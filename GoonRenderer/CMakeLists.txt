# Target name
set(target GoonRenderer)

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/Colorbuffer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/DataType.cpp
)

set(INCLUDES
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/DataType.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/Colorbuffer.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/RenderingPipeline.h
)

add_executable(GoonRenderer ${SOURCES} ${INCLUDES})

target_include_directories(GoonRenderer
PUBLIC
    ${extension_dir}/GoonBMP/Includes
PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes
)

target_link_libraries(GoonRenderer
PUBLIC
PRIVATE
)