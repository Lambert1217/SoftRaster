# SDL3
set(SDL_TEST OFF)
set(BUILD_SHARED_LIBS OFF)
add_subdirectory(SDL-release-3.2.10)

add_library(vendor INTERFACE)
target_link_libraries(vendor INTERFACE SDL3::SDL3)
