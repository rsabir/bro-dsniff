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
#ifndef broccoli_vector_h
#define broccoli_vector_h

#include <broccoli.h>
#include <bro_types.h>

/* Typedef is in broccoli.h because the users need to know it -- we keep
 * it opaque for them though by defining it here.
 */
struct bro_vector
{
  BroVal                     **vector;
  int                          length;
};

BroVector     *__bro_vector_new(void);
void           __bro_vector_free(BroVector *rec);
BroVector     *__bro_vector_copy(BroVector *rec);
int            __bro_vector_get_length(BroVector *rec);

/* Appends the given val at the end of the vector and adopts ownership,
 * i.e, the value is not duplicated internally.
 */
int            __bro_vector_add_val(BroVector *vec, BroVal *val);

BroVal        *__bro_vector_get_nth_val(BroVector *rec, int num);

int            __bro_vector_set_nth_val(BroVector *rec, int num, BroVal *val);

uint32         __bro_vector_hash(BroVector *rec);
int            __bro_vector_cmp(BroVector *rec1, BroVector *rec2);

#endif
