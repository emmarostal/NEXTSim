file(REMOVE_RECURSE
  "libNextSimCore.a"
  "libNextSimCore.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/NextSimCore.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
