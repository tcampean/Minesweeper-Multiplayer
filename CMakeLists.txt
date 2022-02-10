cmake_minimum_required(VERSION 3.17)
project(e3_912_Campean_Tudor_Alexandru)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "D:\\Qt\\6.0.3\\mingw81_64")


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(QT_VERSION 6)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt6::Core Qt6::Gui Qt6::Widgets)

include_directories(.)

add_executable(e3_912_Campean_Tudor_Alexandru
        Player.cpp
        Player.h Repository.cpp Repository.h Service.cpp Service.h Observer.cpp Observer.h main.cpp GUI.cpp GUI.h TableModel.cpp TableModel.h)


target_link_libraries(e3_912_Campean_Tudor_Alexandru Qt6::Core Qt6::Gui Qt6::Widgets )
find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)
