# Automatically enable catch2 to generate ctest targets
if (CONAN_CATCH2_ROOT_DEBUG)
    include(${CONAN_CATCH2_ROOT_DEBUG}/lib/cmake/Catch2/Catch.cmake)
else ()
    include(${CONAN_CATCH2_ROOT}/lib/cmake/Catch2/Catch.cmake)
endif ()

add_subdirectory(catch_main)
add_subdirectory(check_bypass)
add_subdirectory(comparisons)
add_subdirectory(constexpr)
add_subdirectory(heartbleed)
add_subdirectory(signed_addition_overflow)
add_subdirectory(string_length)
