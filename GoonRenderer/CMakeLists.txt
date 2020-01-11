# Target name
set(target GoonRenderer)

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/Buffer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/RenderingPipeline.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/ObjReader.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/LineRenderer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/Window.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/Context.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/Renderer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/SwapChain.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/MeshRenderer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/Texture/TextureGeneration.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/Texture/Texture.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/Texture/Texture2D.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/Texture/TextureCompression.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/Texture/TextureManager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/Resource/MemoryManager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/Pipeline/FragmentShader.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/Pipeline/VertexShader.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/Pipeline/InputAssembler.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/Pipeline/Rasterizer.cpp
)

set(INCLUDES
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/HeaderPrerequistes.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/DataType.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/Singleton.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/Buffer.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/RenderingPipeline.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/ObjReader.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/LineRenderer.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/Window.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/Context.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/Renderer.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/SwapChain.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/MeshRenderer.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/Util.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/Texture/Texture.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/Texture/Texture2D.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/Texture/TextureCompression.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/Texture/TextureGeneration.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/Texture/TextureManager.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/Resource/MemoryManager.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/Resource/Resource.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/Pipeline/FragmentShader.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/Pipeline/VertexShader.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/Pipeline/InputAssembler.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/Pipeline/Rasterizer.h
)

add_executable(GoonRenderer ${SOURCES} ${INCLUDES})

target_include_directories(GoonRenderer
PUBLIC
    ${extension_dir}/GoonBMP/Includes
    ${extension_dir}/GoonMath/Includes
PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes
)

target_link_libraries(GoonRenderer
PUBLIC
PRIVATE
)