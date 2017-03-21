cmake_minimum_required(VERSION 2.8)
project(KandyClient)

find_package(CURL REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(JSONCPP jsoncpp)

link_libraries(${JSONCPP_LIBRARIES})

include_directories(${CURL_INCLUDE_DIRS})

add_executable(KandyClient httpClient.cpp kandyClient.cpp main.cpp)

target_link_libraries(KandyClient ${CURL_LIBRARIES})
target_link_libraries(KandyClient ${JSONCPP_LIBRARIES})


