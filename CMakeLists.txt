cmake_minimum_required(VERSION 4.0)
project(fuckass)

set(CMAKE_CXX_STANDARD 20)

add_compile_options(-march=native -O3 -ffast-math)

# had to yoink this from danil LMAO
set(RAYLIB_VERSION 5.5)
cmake_policy(SET CMP0169 OLD)
find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
    include(FetchContent)
    FetchContent_Declare(
            raylib
            DOWNLOAD_EXTRACT_TIMESTAMP OFF
            URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif()
endif()

include_directories(.)

add_executable(${PROJECT_NAME}
        Logging.h
        FuckAss.cpp
        FuckAss.h
        obj/objects/DebugView.h
        obj/objects/DebugView.cpp
        obj/objects/BouncyText.h
        obj/objects/BouncyText.cpp
        obj/Object.h
        obj/Text.h
        )

target_link_libraries(${PROJECT_NAME} raylib)

# Web Configurations
if (${PLATFORM} STREQUAL "Web")
    # Tell Emscripten to build an example.html file.
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html")
endif()

# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()