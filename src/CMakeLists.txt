set(target beerbeat)

set(source_path "${CMAKE_CURRENT_SOURCE_DIR}")
set(source_dir "${CMAKE_CURRENT_SOURCE_DIR}")

set(sources "BeerBeat.cpp")

add_subdirectory(patternEngine)

add_executable(${target}
    ${sources}
)

target_link_directories(${target}
    PRIVATE
    ${GTKMM_LIBRARY_DIRS}
)

target_link_libraries(${target} PRIVATE
    patternengine
    ${GTKMM_LIBRARIES}
)