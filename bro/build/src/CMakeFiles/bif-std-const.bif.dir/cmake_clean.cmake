FILE(REMOVE_RECURSE
  "../scripts/base/bif"
  "CMakeFiles/bif-std-const.bif"
  "const.bif.func_def"
  "const.bif.func_h"
  "const.bif.func_init"
  "const.bif.netvar_def"
  "const.bif.netvar_h"
  "const.bif.netvar_init"
  "../scripts/base/bif/const.bif.bro"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/bif-std-const.bif.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
