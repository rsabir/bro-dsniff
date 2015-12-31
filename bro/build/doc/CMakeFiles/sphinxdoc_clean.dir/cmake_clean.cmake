FILE(REMOVE_RECURSE
  "CMakeFiles/sphinxdoc_clean"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/sphinxdoc_clean.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
