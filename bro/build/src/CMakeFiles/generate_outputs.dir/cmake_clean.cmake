FILE(REMOVE_RECURSE
  "../scripts/base/bif"
  "CMakeFiles/generate_outputs"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/generate_outputs.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
