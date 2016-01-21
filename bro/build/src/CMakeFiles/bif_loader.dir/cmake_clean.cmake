FILE(REMOVE_RECURSE
  "../scripts/base/bif"
  "CMakeFiles/bif_loader"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/bif_loader.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
