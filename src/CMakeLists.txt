
file(GLOB ae_core_headers
  memory/*.h
  pp/*.h
  simd/*.h
)

file(GLOB ae_core_source
  memory/*.cc
  pp/*.cc
  simd/*.cc
)

configure_file("config.inl" "${CMAKE_CURRENT_BINARY_DIR}/config_impl.h")
add_library(ae_core ${ae_core_headers} ${ae_core_source})
set_target_properties(ae_core PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(ae_core PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}> # for headers when building
  $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}> # for config_impl.hpp when building
  $<INSTALL_INTERFACE:${INCLUDE_DEST}> # for client in install mode
  $<INSTALL_INTERFACE:${LIB_DEST}> # for config_impl.hpp in install mode)
)

install(TARGETS ae_core EXPORT ae_core DESTINATION "${LIB_DEST}")
install(FILES ae_core-config.cmake DESTINATION ${LIB_DEST})
install(EXPORT ae_core DESTINATION "${LIB_DEST}")
install(FILES ${ae_core_headers} DESTINATION "${INCLUDE_DEST}")
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/config_impl.h DESTINATION "${LIB_DEST}")