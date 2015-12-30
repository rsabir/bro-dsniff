/*
       B R O C C O L I  --  The Bro Client Communications Library

Copyright (C) 2004-2008 Christian Kreibich <christian (at) icir.org>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to
deal in the Software without restriction, including without limitation the
rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies of the Software and its documentation and acknowledgment shall be
given in the documentation and software packages that this Software was
used.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/
#if HAVE_CONFIG_H
# include <config.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#ifdef __EMX__
#include <strings.h>
#endif

#include <bro_types.h>
#include <bro_io.h>
#include <bro_debug.h>
#include <bro_val.h>
#include <bro_vector.h>


BroVector *
__bro_vector_new(void)
	{
	BroVector *rec;

	if (! (rec = calloc(1, sizeof(BroVector))))
		return NULL;

	return rec;
	}


void
__bro_vector_free(BroVector *vec)
	{
	int i;

	if ( ! vec )
		return;

	for ( i = 0; i < vec->length; ++i )
		__bro_sobject_release((BroSObject*) vec->vector[i]);

	free(vec->vector);
	free(vec);
	}


int
__bro_vector_get_length(BroVector *vec)
	{
	D_ENTER;

	if ( ! vec )
		D_RETURN_(0);

	D_RETURN_(vec->length);
	}


BroVector     *
__bro_vector_copy(BroVector *vec)
	{
	int i;
	BroVector *copy;
	BroVal *val_copy;

	D_ENTER;

	if ( ! vec )
		D_RETURN_(NULL);

	if ( ! (copy = __bro_vector_new()) )
		D_RETURN_(NULL);

	if ( ! (copy->vector = calloc(vec->length, sizeof(BroVal*))) )
		{
		__bro_vector_free(copy);
		D_RETURN_(NULL);
		}

	copy->length = vec->length;

	for ( i = 0; i < vec->length; ++i )
		{
		val_copy = (BroVal*) __bro_sobject_copy((BroSObject*) vec->vector[i]);

		if ( ! val_copy )
			{
			__bro_vector_free(copy);
			D_RETURN_(NULL);
			}

		copy->vector[i] = val_copy;
		}

	D_RETURN_(copy);
	}


int
__bro_vector_add_val(BroVector *vec, BroVal *val)
	{
	D_ENTER;

	if ( ! vec || ! val )
		D_RETURN_(FALSE);

	vec->vector = realloc(vec->vector, (vec->length + 1) * sizeof(BroVal*));

	if ( ! vec->vector )
		{
		D(("Realloc'ing vector failed.\n"));
		D_RETURN_(FALSE);
		}

	vec->vector[vec->length] = val;
	vec->length++;
	D_RETURN_(TRUE);
	}

BroVal *
__bro_vector_get_nth_val(BroVector *vec, int num)
	{
	if ( ! vec || num < 0 || num >= vec->length )
		return NULL;

	return vec->vector[num];
	}


int
__bro_vector_set_nth_val(BroVector *vec, int num, BroVal *v)
	{
	BroVal *val;

	if ( ! vec || num < 0 || num >= vec->length || ! v )
		return FALSE;

	__bro_sobject_release((BroSObject*) vec->vector[num]);
	vec->vector[num] = v;
	return TRUE;
	}


uint32
__bro_vector_hash(BroVector *vec)
	{
	int i;
	uint32 result;

	D_ENTER;

	if ( ! vec )
		D_RETURN_(0);

	result = vec->length;

	for ( i = 0; i < vec->length; ++i )
		result ^= __bro_sobject_hash((BroSObject*) vec->vector[i]);

	D_RETURN_(result);
	}


int
__bro_vector_cmp(BroVector *vec1, BroVector *vec2)
	{
	int i;

	if ( ! vec1 || ! vec2 )
		D_RETURN_(FALSE);

	if ( vec1->length != vec2->length )
		D_RETURN_(FALSE);

	for ( i = 0; i < vec1->length; ++i )
		if ( ! __bro_sobject_cmp((BroSObject*) vec1->vector[i],
		                         (BroSObject*) vec2->vector[i]) )
			D_RETURN_(FALSE);

	D_RETURN_(TRUE);
	}
