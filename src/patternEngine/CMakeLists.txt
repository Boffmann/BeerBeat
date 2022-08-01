set(target patternengine)

set(source_path "${CMAKE_CURRENT_SOURCE_DIR}")

set(include_path
    "${source_path}"
    "${source_path}/visualization"
    "${source_path}/visualization/gui"
)

set(public_headers
    ${source_path}/PatternEngine.h
)

set(sources
    ${source_path}/visualization/visualization.cpp
    ${source_path}/visualization/gui/DebugApplication.cpp
    ${source_path}/visualization/gui/DebugGui.cpp
    ${source_path}/visualization/gui/LEDArea.cpp
    ${source_path}/Pattern.cpp
    ${source_path}/PatternEngine.cpp
)

add_library(${target} STATIC
    ${sources}
)

set_target_properties(${target} PROPERTIES PUBLIC_HEADER "${public_headers}")

target_link_directories(${target}
    PRIVATE
    ${GTKMM_LIBRARY_DIRS}
)

target_include_directories(${target}
    PUBLIC
    ${GTKMM_INCLUDE_DIRS}
    ${include_path}
)

target_link_libraries(${target}
    ${GTKMM_LIBRARIES}
)
