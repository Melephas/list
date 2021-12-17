cmake_minimum_required(VERSION 3.13)
project(List C)

set(CMAKE_C_STANDARD 11)

set(PROJECT_VERSION 0.3.1)

set(SOURCES src/list.c)

add_compile_options(
    -g
)

add_library(
    list SHARED
    ${SOURCES}
)

add_library(
    listStatic STATIC
    ${SOURCES}
)

set_target_properties(listStatic PROPERTIES OUTPUT_NAME list)

add_library(List::List ALIAS list)
add_library(List::List::Static ALIAS listStatic)

target_include_directories(
    list
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    #    PUBLIC include
)

target_include_directories(
    listStatic
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

include(GNUInstallDirs)

install(
    TARGETS list listStatic
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
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

install(
    FILES
    "${CMAKE_CURRENT_BINARY_DIR}/cmake/ListConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake/ListConfigVersion.cmake"
    DESTINATION
    "${CMAKE_INSTALL_LIBDIR}/cmake/List"
)
