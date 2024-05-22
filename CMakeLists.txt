cmake_minimum_required(VERSION 3.14)

project(TcpDataTransmitter LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Network REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Network REQUIRED)

set(PROJECT_SOURCES
    include/ProtocolFormatSrings.h
    include/TcpDataTransmitter.h
    src/ProtocolFormatSrings.cpp
    src/TcpDataTransmitter.cpp
)

add_library(TcpDataTransmitter STATIC
    ${PROJECT_SOURCES}
)

target_include_directories(TcpDataTransmitter PUBLIC include/)
target_link_libraries(TcpDataTransmitter PRIVATE Qt${QT_VERSION_MAJOR}::Core PRIVATE Qt${QT_VERSION_MAJOR}::Network)

#target_compile_definitions(TcpDataTransmitter PRIVATE TCPDATATRANSMITTER_LIBRARY)
