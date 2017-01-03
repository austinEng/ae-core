
add_executable(simd_types simd_types.cc)
target_link_libraries(simd_types ae_core)
add_test(simd_types simd_types)