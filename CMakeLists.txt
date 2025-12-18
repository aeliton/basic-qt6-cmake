cmake_minimum_required(VERSION 3.28)

project(hello VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS OFF)

if (CMAKE_COMPILE_WARNING_AS_ERROR)
  if (MSVC)
    add_compile_options(/W4 /WX)
  else()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
  endif()
endif()

find_package(spdlog REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt6_wrap_cpp(MOC_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/include/mainwindow.h
)

add_executable(main
  ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/mainwindow.cpp
  ${MOC_SOURCES}
)
target_include_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(main PRIVATE
  spdlog::spdlog
  Qt6::Widgets
)

include(CTest)

find_package(GTest CONFIG REQUIRED COMPONENTS GTest GMock)

enable_testing()
add_executable(tests
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_hello.cpp
)

target_include_directories(tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_libraries (tests
  GTest::gmock
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)
