cmake_minimum_required(VERSION 2.8)
project(KendyClient)

find_package(CURL REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(JSONCPP jsoncpp)

link_libraries(${JSONCPP_LIBRARIES})

include_directories(${CURL_INCLUDE_DIRS})

add_executable(KendyClient httpClient.cpp kendyClient.cpp main.cpp)

target_link_libraries(KendyClient ${CURL_LIBRARIES})
target_link_libraries(KendyClient ${JSONCPP_LIBRARIES})


