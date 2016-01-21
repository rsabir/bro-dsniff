FILE(REMOVE_RECURSE
  "../scripts/base/bif"
  "CMakeFiles/bif-std-types.bif"
  "types.bif.func_def"
  "types.bif.func_h"
  "types.bif.func_init"
  "types.bif.netvar_def"
  "types.bif.netvar_h"
  "types.bif.netvar_init"
  "../scripts/base/bif/types.bif.bro"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/bif-std-types.bif.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
