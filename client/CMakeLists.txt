cmake_minimum_required(VERSION 3.16)

project(untitled VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools network WebEngineWidgets Qt6WebSockets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools WebEngineWidgets WebSockets)

set(TS_FILES untitled_zh_CN.ts)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        ${TS_FILES}
)

#add include dir 子目录，子目录中需要有cmake文件
include_directories(protobuf/src)
include_directories(pb)

set(MINGW_PB_DIR ${PROJECT_SOURCE_DIR}/protobuf/build)
link_directories(${MINGW_PB_DIR} ${PROJECT_SOURCE_DIR})
link_libraries(protobuf)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(untitled
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        clipboad.h clipboad.cpp
        textitem.h textitem.cpp
        pb/logic.pb.cc pb/logic.pb.h pb/struct.pb.cc pb/struct.pb.h
        protobuf/.bazelignore protobuf/.git protobuf/.gitignore protobuf/.gitmodules protobuf/.readthedocs.yml protobuf/appveyor.bat protobuf/appveyor.yml protobuf/autogen.sh protobuf/BUILD.bazel protobuf/build_files_updated_unittest.sh protobuf/CHANGES.txt protobuf/CMakeLists.txt protobuf/configure.ac protobuf/CONTRIBUTING.md protobuf/CONTRIBUTORS.txt protobuf/fix_permissions.sh protobuf/generate_changelog.py protobuf/generate_descriptor_proto.sh protobuf/global.json protobuf/LICENSE protobuf/Makefile.am protobuf/maven_install.json protobuf/post_process_dist.sh protobuf/protobuf.bzl protobuf/protobuf.pc.in protobuf/Protobuf.podspec protobuf/protobuf_deps.bzl protobuf/protobuf_release.bzl protobuf/protobuf_version.bzl protobuf/Protobuf-C++.podspec protobuf/protobuf-lite.pc.in protobuf/README.md protobuf/SECURITY.md protobuf/tests.sh protobuf/update_compatibility_version.py protobuf/update_file_lists.sh protobuf/update_version.py protobuf/version.json protobuf/WORKSPACE
        network.cpp
        network.h
        wxlogin.h
        logmanager.h logmanager.cpp
        maintab.h maintab.cpp
        loginwindow.h loginwindow.cpp
        config.h config.cpp
        encode.h encode.cpp
        packet.h packet.cpp




    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET untitled APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(untitled SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(untitled
            ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_link_libraries(untitled PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::WebEngineWidgets Qt${QT_VERSION_MAJOR}::WebSockets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.untitled)
endif()
set_target_properties(untitled PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS untitled
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(untitled)
endif()
