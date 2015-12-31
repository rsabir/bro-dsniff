FILE(REMOVE_RECURSE
  "CMakeFiles/docclean"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/docclean.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
