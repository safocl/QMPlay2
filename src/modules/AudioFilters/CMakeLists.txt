project(AudioFilters)
cmake_minimum_required(VERSION 3.0.2)
FIND_PACKAGE(PkgConfig REQUIRED)

set(AudioFilters_HDR
    AudioFilters.hpp
    Equalizer.hpp
    EqualizerGUI.hpp
    VoiceRemoval.hpp
    PhaseReverse.hpp
    Echo.hpp
)

set(AudioFilters_SRC
    AudioFilters.cpp
    Equalizer.cpp
    EqualizerGUI.cpp
    VoiceRemoval.cpp
    PhaseReverse.cpp
    Echo.cpp
)

set(AudioFilters_RESOURCES
    icons.qrc
)

add_definitions(-D__STDC_CONSTANT_MACROS)

PKG_CHECK_MODULES(LIBAVCODEC libavcodec REQUIRED)
PKG_CHECK_MODULES(LIBAVUTIL libavutil REQUIRED)
link_directories(${LIBAVCODEC_LIBRARY_DIRS} ${LIBAVUTIL_LIBRARY_DIRS})

if(USE_QT5)
    qt5_add_resources(AudioFilters_RESOURCES_RCC ${AudioFilters_RESOURCES})
else()
    qt4_add_resources(AudioFilters_RESOURCES_RCC ${AudioFilters_RESOURCES})
endif()

include_directories(../../qmplay2/headers ${LIBAVCODEC_INCLUDE_DIRS} ${LIBAVUTIL_INCLUDE_DIRS})

add_library(${PROJECT_NAME} MODULE
    ${AudioFilters_HDR}
    ${AudioFilters_SRC}
    ${AudioFilters_RESOURCES_RCC}
)

if(USE_QT5)
    qt5_use_modules(${PROJECT_NAME} Gui Widgets)
else()
    target_link_libraries(${PROJECT_NAME} Qt4::QtGui Qt4::QtCore)
endif()

add_dependencies(${PROJECT_NAME} qmplay2)
target_link_libraries(${PROJECT_NAME}
    ${LIBAVCODEC_LIBRARIES}
    ${LIBAVUTIL_LIBRARIES}
    $<TARGET_FILE:qmplay2>
)

install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION "${MODULES_INSTALL_PATH}")