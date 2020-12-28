cmake_minimum_required(VERSION 3.14)

project(rttg
        VERSION 0.0.1
        DESCRIPTION "Provides run-time tuple element access"
        HOMEPAGE_URL "https://github.com/AlexKiryushkin/rttg"
        LANGUAGES CXX)

# ---- Warning guard ----

# Protect dependents from this project's warnings if the guard isn't disabled
set(rttg_warning_guard SYSTEM)
if(rttg_INCLUDE_WITHOUT_SYSTEM)
  set(rttg_warning_guard "")
endif()

# ---- Declare library ----

add_library(rttg INTERFACE)
add_library(rttg::rttg ALIAS rttg)

target_include_directories(rttg
        ${rttg_warning_guard}
        INTERFACE
        "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>")

target_compile_features(rttg INTERFACE cxx_std_17)

# ---- Install ----

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

set(rttg_directory "rttg-${PROJECT_VERSION}")
set(rttg_include_directory
        "${CMAKE_INSTALL_INCLUDEDIR}/${rttg_directory}")

install(DIRECTORY "${PROJECT_SOURCE_DIR}/include/"
        DESTINATION "${rttg_include_directory}")

install(TARGETS rttg
        EXPORT rttgTargets
        INCLUDES DESTINATION "${rttg_include_directory}")

write_basic_package_version_file(
        rttg-config-version.cmake
        COMPATIBILITY SameMajorVersion
        ARCH_INDEPENDENT)

set(rttg_install_cmakedir
        "${CMAKE_INSTALL_LIBDIR}/cmake/${rttg_directory}")

install(FILES "${PROJECT_BINARY_DIR}/rttg-config-version.cmake"
        DESTINATION "${rttg_install_cmakedir}")

install(EXPORT rttgTargets
        FILE rttg-config.cmake
        NAMESPACE rttg::
        DESTINATION "${rttg_install_cmakedir}")
