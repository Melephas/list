#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "List::list" for configuration "Debug"
set_property(TARGET List::list APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(List::list PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "C"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib64/liblist.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS List::list )
list(APPEND _IMPORT_CHECK_FILES_FOR_List::list "${_IMPORT_PREFIX}/lib64/liblist.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
