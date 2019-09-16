# Target name
set(target GoonBMP)

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/main.cpp
)

set(INCLUDES
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/gbmp/bmp_image.h
)

add_executable(GoonBMP ${SOURCES} ${INCLUDES})

target_include_directories(GoonBMP
PUBLIC
PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes
)

target_link_libraries(GoonBMP
PUBLIC
PRIVATE
)