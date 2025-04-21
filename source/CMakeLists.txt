file(GLOB_RECURSE SOURCE_FILES "./*.cpp")
file(GLOB_RECURSE HEADER_FILES "./*.h")

add_executable(${TARGET_NAME})
target_sources(${TARGET_NAME} PRIVATE ${SOURCE_FILES} ${HEADER_FILES})
target_precompile_headers(${TARGET_NAME} PRIVATE "./pch.h")
target_include_directories(${TARGET_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR})

find_package(Eigen3 CONFIG REQUIRED)
find_package(SDL3 CONFIG REQUIRED)
target_link_libraries(${TARGET_NAME} PRIVATE Eigen3::Eigen SDL3::SDL3)