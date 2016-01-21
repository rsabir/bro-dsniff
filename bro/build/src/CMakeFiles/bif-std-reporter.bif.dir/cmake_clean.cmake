FILE(REMOVE_RECURSE
  "../scripts/base/bif"
  "CMakeFiles/bif-std-reporter.bif"
  "reporter.bif.func_def"
  "reporter.bif.func_h"
  "reporter.bif.func_init"
  "reporter.bif.netvar_def"
  "reporter.bif.netvar_h"
  "reporter.bif.netvar_init"
  "../scripts/base/bif/reporter.bif.bro"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/bif-std-reporter.bif.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
