project(plasma-closer)
 
find_package(KDE4 REQUIRED)
include(KDE4Defaults)
 
add_definitions (${QT_DEFINITIONS} ${KDE4_DEFINITIONS})
include_directories(
   ${CMAKE_SOURCE_DIR}
   ${CMAKE_BINARY_DIR}
   ${KDE4_INCLUDES}
   )
 
set(closer_SRCS closer.cpp)
 
kde4_add_plugin(plasma_applet_closer ${closer_SRCS})
target_link_libraries(plasma_applet_closer 
                      ${KDE4_PLASMA_LIBS} ${KDE4_KDEUI_LIBS} taskmanager)
 
install(TARGETS plasma_applet_closer
        DESTINATION ${PLUGIN_INSTALL_DIR})
 
install(FILES plasma-applet-closer.desktop
        DESTINATION ${SERVICES_INSTALL_DIR})
        
kde4_install_icons(${ICON_INSTALL_DIR})

