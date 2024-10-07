file(REMOVE_RECURSE
  "libNextSimEvent.a"
  "libNextSimEvent.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/NextSimEvent.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
