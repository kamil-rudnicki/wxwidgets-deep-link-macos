cmake_minimum_required(VERSION 3.0)
project(DeepLinkTest)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

set(SOURCES
    main.cpp
    MainFrame.cpp
    URLHandler.mm
)

add_executable(DeepLinkTest MACOSX_BUNDLE ${SOURCES})

target_link_libraries(DeepLinkTest ${wxWidgets_LIBRARIES})

if(APPLE)
    set_target_properties(DeepLinkTest PROPERTIES
        MACOSX_BUNDLE_GUI_IDENTIFIER "com.timecamp.TimeCamp"
        MACOSX_BUNDLE_BUNDLE_NAME "DeepLinkTest"
        MACOSX_BUNDLE_BUNDLE_VERSION "1.0"
        MACOSX_BUNDLE_SHORT_VERSION_STRING "1.0"
    )
    
    set(MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/Info.plist)
    set_target_properties(DeepLinkTest PROPERTIES
        MACOSX_BUNDLE_INFO_PLIST ${MACOSX_BUNDLE_INFO_PLIST}
    )

    target_link_libraries(DeepLinkTest "-framework Cocoa")
endif()