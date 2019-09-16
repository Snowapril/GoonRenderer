# Target name
set(target GoonRenderer)

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/main.cpp
)

set(INCLUDES
)

add_executable(GoonRenderer ${SOURCES} ${INCLUDES})

target_include_directories(GoonRenderer
PUBLIC
PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes
)

target_link_libraries(GoonRenderer
PUBLIC
PRIVATE
)