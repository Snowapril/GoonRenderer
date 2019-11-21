# Target name
set(target GoonMath)

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/main.cpp
)

set(INCLUDES
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/gm/vector.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/gm/util.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/gm/internal/simd.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/gm/internal/type_specialization.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/gm/internal/vector3.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/gm/internal/vector3_simd.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/gm/internal/vector4.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/gm/internal/vector4_simd.h
)

add_executable(GoonMath ${SOURCES} ${INCLUDES})

target_include_directories(GoonMath
PUBLIC
PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes
)

target_link_libraries(GoonMath
PUBLIC
PRIVATE
)

