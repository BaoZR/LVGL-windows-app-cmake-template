cmake_minimum_required(VERSION 3.12.4)

project(lvglDesktopApplication LANGUAGES C CXX)

add_subdirectory(lvgl)
add_executable(${PROJECT_NAME}
  lvglWindowsDesktopApplication.cpp
)

target_include_directories(${PROJECT_NAME} 
PUBLIC 
  ${CMAKE_CURRENT_SOURCE_DIR}/lvgl 
  ${CMAKE_CURRENT_SOURCE_DIR}/LvglWindowsIconResource)
target_link_libraries(${PROJECT_NAME} lvgl)
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE "/utf-8")
    target_compile_definitions(${PROJECT_NAME} PRIVATE "_UNICODE" "UNICODE")
endif()