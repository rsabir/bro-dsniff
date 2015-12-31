FILE(REMOVE_RECURSE
  "../scripts/base/bif"
  "CMakeFiles/pac-binpac-lib.pac"
  "binpac-lib_pac.h"
  "binpac-lib_pac.cc"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/pac-binpac-lib.pac.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
