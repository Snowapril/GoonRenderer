# Target name
set(target GoonMath)

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/main.cpp
)

set(INCLUDES
   
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