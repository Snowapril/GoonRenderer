# Target name
set(target GoonMath)

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/gm/details/type_vec3.inl
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/gm/property/vec_property.inl
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/gm/transform/vec_transform.inl
)

set(INCLUDES
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/gm/details/type_vec3.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/gm/details/type_vec4.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/gm/details/type_vec_base.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/gm/property/vec_property.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/gm/transform/vec_transform.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/gm/type_specialization/vec3_bool.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/gm/type_specialization/vec3_double.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/gm/type_specialization/vec3_float.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/gm/type_specialization/vec3_int.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/gm/type_specialization/vec3_uint.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/gm/vec3.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/gm/vec4.h
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