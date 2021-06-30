cmake_minimum_required(VERSION 3.20)
project(code_analysis_pp)

set(CMAKE_CXX_STANDARD 20)

if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
#    add_compile_options(-Wall -Wextra -Werror)
    add_compile_options(-Wsign-compare -Wsizeof-pointer-memaccess -Wmisleading-indentation)
endif()

add_subdirectory(Qt_sample)

add_executable(lifetimes lifetime_safety_samples.cpp)
add_executable(dfa dfa_samples.cpp)
add_executable(clang-tidy-checks clang-tidy_cppcoreguidelines.cpp clang-tidy_modernize.cpp)
add_executable(compiler_check compiler_checks.cpp)
add_executable(misra misra_checks.cpp)
add_executable(namis naming_rules.cpp)
add_executable(code_analysis_pp main.cpp)
