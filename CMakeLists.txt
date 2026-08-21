cmake_minimum_required(VERSION 3.16)

project(
  glibme
  VERSION 0.1.0
  DESCRIPTION "A small libc-style learning library"
  LANGUAGES C
)

option(GLIBME_BUILD_TESTS "Build glibme tests" ON)
option(GLIBME_BUILD_SHARED "Build a shared glibme library" ON)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

include(GNUInstallDirs)

set(GLIBME_SOURCES
  src/ctype.c
  src/string.c
)

add_library(glibme_static STATIC ${GLIBME_SOURCES})
add_library(glibme::static ALIAS glibme_static)
set_target_properties(glibme_static PROPERTIES
  OUTPUT_NAME glibme
  EXPORT_NAME static
)

target_include_directories(glibme_static
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_compile_options(glibme_static
  PRIVATE
    $<$<C_COMPILER_ID:AppleClang,Clang,GNU>:-Wall -Wextra -Wpedantic>
)

if(GLIBME_BUILD_SHARED)
  add_library(glibme_shared SHARED ${GLIBME_SOURCES})
  add_library(glibme::shared ALIAS glibme_shared)
  set_target_properties(glibme_shared PROPERTIES
    OUTPUT_NAME glibme
    EXPORT_NAME shared
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
  )

  target_include_directories(glibme_shared
    PUBLIC
      $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
      $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
  )

  target_compile_options(glibme_shared
    PRIVATE
      $<$<C_COMPILER_ID:AppleClang,Clang,GNU>:-Wall -Wextra -Wpedantic>
  )
endif()

if(GLIBME_BUILD_TESTS)
  enable_testing()
  add_executable(glibme_tests tests/test_glibme.c)
  target_link_libraries(glibme_tests PRIVATE glibme::static)
  add_test(NAME glibme_tests COMMAND glibme_tests)
endif()

install(
  DIRECTORY include/
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(
  TARGETS glibme_static
  EXPORT glibmeTargets
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(GLIBME_BUILD_SHARED)
  install(
    TARGETS glibme_shared
    EXPORT glibmeTargets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  )
endif()

install(
  EXPORT glibmeTargets
  NAMESPACE glibme::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/glibme
)
