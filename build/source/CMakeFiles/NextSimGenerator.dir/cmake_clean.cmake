file(REMOVE_RECURSE
  "libNextSimGenerator.a"
  "libNextSimGenerator.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/NextSimGenerator.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
