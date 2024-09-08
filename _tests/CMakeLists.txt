include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(test_Generator Generator.test.cpp ../generator.cpp)

target_link_libraries(test_Generator gtest gtest_main)

enable_testing()

add_test(NAME GeneratorTests COMMAND test_Generator)
