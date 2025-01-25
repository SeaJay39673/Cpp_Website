cmake_minimum_required(VERSION 3.5.0)
project(Cpp_Website VERSION 0.1.0 LANGUAGES C CXX)

add_executable(Cpp_Website src/main.cpp)

set(RESOURCE_PATH "")
if(WIN32)
set(RESOURCE_PATH "$<IF:$<CONFIG:Debug>,Debug,Release>")
endif()

add_custom_target(copy_assets
COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/cpp_website/build ${CMAKE_CURRENT_BINARY_DIR}/${RESOURCE_PATH}/react-build
)
add_dependencies(Cpp_Website copy_assets)

include(./vcpkg/scripts/buildsystems/vcpkg.cmake)

include(CTest)
enable_testing()

find_package(oatpp CONFIG REQUIRED)
target_link_libraries(Cpp_Website PRIVATE oatpp::oatpp oatpp::oatpp-test)