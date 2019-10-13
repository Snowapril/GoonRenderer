# Target name
set(target GoonVideo)

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/main.cpp
)

set(INCLUDES
)

add_executable(GoonVideo ${SOURCES} ${INCLUDES})

target_include_directories(GoonVideo
PUBLIC
PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes
)

target_link_libraries(GoonVideo
PUBLIC
PRIVATE
)