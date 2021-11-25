#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "LinkedList::linkedList" for configuration "Debug"
set_property(TARGET LinkedList::linkedList APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(LinkedList::linkedList PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "C"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib64/liblinkedList.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS LinkedList::linkedList )
list(APPEND _IMPORT_CHECK_FILES_FOR_LinkedList::linkedList "${_IMPORT_PREFIX}/lib64/liblinkedList.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
