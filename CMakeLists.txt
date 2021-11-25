cmake_minimum_required(VERSION 3.13)
project(List C)

set(CMAKE_C_STANDARD 11)

add_library(
    list
    src/list.c
)

add_library(List::List ALIAS list)

target_include_directories(
    list
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    #    PUBLIC include
)

include(GNUInstallDirs)

install(
    TARGETS list
    EXPORT ListTargets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(
    FILES
    include/list.h
    TYPE INCLUDE
    COMPONENT
    Devel
)

install(
    EXPORT ListTargets
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/List
    NAMESPACE List::
    FILE ListTargets.cmake
)

include(CMakePackageConfigHelpers)
configure_package_config_file(
    "cmake/Config.cmake.in"
    "cmake/ListConfig.cmake"
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/List
    PATH_VARS
    CMAKE_INSTALL_LIBDIR
)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/cmake/ListConfigVersion.cmake
    VERSION 0.2.1
    COMPATIBILITY SameMajorVersion
)

install(
    FILES
    "${CMAKE_CURRENT_BINARY_DIR}/cmake/ListConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake/ListConfigVersion.cmake"
    DESTINATION
    "${CMAKE_INSTALL_LIBDIR}/cmake/List"
)