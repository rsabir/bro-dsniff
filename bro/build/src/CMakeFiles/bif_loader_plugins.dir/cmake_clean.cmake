FILE(REMOVE_RECURSE
  "../scripts/base/bif"
  "CMakeFiles/bif_loader_plugins"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/bif_loader_plugins.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
