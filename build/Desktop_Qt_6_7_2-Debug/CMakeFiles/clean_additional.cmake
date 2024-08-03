# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/CustomEmitConnect_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/CustomEmitConnect_autogen.dir/ParseCache.txt"
  "CustomEmitConnect_autogen"
  )
endif()
