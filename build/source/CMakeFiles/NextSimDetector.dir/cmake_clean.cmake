file(REMOVE_RECURSE
  "libNextSimDetector.a"
  "libNextSimDetector.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/NextSimDetector.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
