file(REMOVE_RECURSE
  "libNextSimOutput.a"
  "libNextSimOutput.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/NextSimOutput.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
