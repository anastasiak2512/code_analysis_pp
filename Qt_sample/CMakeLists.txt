
set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)
set(CMAKE_AUTOUIC ON)

add_executable(qt_sample main.cpp Confirmation.h)

if (NOT CMAKE_PREFIX_PATH)
    if (WIN32 OR APPLE)
        message(FATAL_ERROR "CMAKE_PREFIX_PATH is not defined, set -DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\"")
    else ()
        message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it (e.g. -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt5/ on Ubuntu)")
    endif ()
endif ()

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(qt_sample ${REQUIRED_LIBS_QUALIFIED})

if (WIN32)
    set(DEBUG_SUFFIX)
    if (CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    add_custom_command(TARGET qt_sample POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E make_directory
            $<TARGET_FILE_DIR:qt_sample>/plugins/platforms/)
    add_custom_command(TARGET qt_sample POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_PREFIX_PATH}/../../plugins/platforms/qwindows${DEBUG_SUFFIX}.dll
            $<TARGET_FILE_DIR:qt_sample>/plugins/platforms/)
    foreach (QT_LIB ${REQUIRED_LIBS})
        add_custom_command(TARGET qt_sample POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_PREFIX_PATH}/../../bin/Qt${QT_VERSION}${QT_LIB}${DEBUG_SUFFIX}.dll
                $<TARGET_FILE_DIR:qt_sample>)
    endforeach (QT_LIB)
endif ()

