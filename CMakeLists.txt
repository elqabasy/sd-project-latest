cmake_minimum_required(VERSION 3.27)
project(ds_project_latest)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Define source directories
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(UI_DIR ${CMAKE_SOURCE_DIR}/ui)

# Find Qt6 (Ensure Qt6 is installed and properly configured)
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

# Automatically gather all .cpp, .h, and .ui files
file(GLOB_RECURSE SRC_FILES "${SRC_DIR}/*.cpp")
file(GLOB_RECURSE HEADER_FILES "${SRC_DIR}/*.h")
file(GLOB_RECURSE UI_FILES "${UI_DIR}/*.ui")




# Add the executable
add_executable(${PROJECT_NAME} ${SRC_FILES} ${HEADER_FILES} ${UI_FILES})

# Link Qt libraries
target_link_libraries(${PROJECT_NAME}
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

# Include source directories
target_include_directories(${PROJECT_NAME} PRIVATE ${SRC_DIR} ${UI_DIR})




# Windows-specific setup
if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
