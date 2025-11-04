cmake_minimum_required(VERSION 3.31)

project(Lavendel LANGUAGES CXX)

# === GLOBAL SETTINGS ===
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

# === CONFIGURATIONS ===
set(CMAKE_CONFIGURATION_TYPES "Debug;Release;Dist" CACHE STRING "" FORCE)

# === OUTPUT DIRECTORIES ===
if(WIN32)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
else()
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
endif()

# === PLATFORM MACROS ===
if(WIN32)
    add_compile_definitions(LV_PLATFORM_WINDOWS)
elseif(APPLE)
    add_compile_definitions(LV_PLATFORM_OSX)
elseif(UNIX)
    add_compile_definitions(LV_PLATFORM_LINUX)
endif()

# === CONFIGURATION MACROS ===
# Diese Defines h�ngen vom Build-Typ ab (Debug / Release / Dist)
add_compile_definitions(
    $<$<CONFIG:Debug>:LM_DEBUG>
    $<$<CONFIG:Release>:LM_RELEASE>
    $<$<CONFIG:Dist>:LM_DIST>
)

# === COMPILER WARNINGS & FLAGS ===
add_compile_options(/UTF-8)

# === SUBDIRECTORIES ===
add_subdirectory(Lavendel)
add_subdirectory(Sandbox)

target_compile_definitions(Lavendel PRIVATE LV_BUILD_DLL)

# Set the working directory for debugging in Visual Studio
set_target_properties(Sandbox PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/bin/$<CONFIG>"
)

# Copy shaders to output directory
add_custom_command(TARGET Sandbox POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/shaders
    $<TARGET_FILE_DIR:Sandbox>/shaders
    COMMENT "Copying shaders to output directory"
)
