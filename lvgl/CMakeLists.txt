cmake_minimum_required(VERSION 3.12.4)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)



set(LVGL_ROOT_DIR ${CMAKE_CURRENT_LIST_DIR})
include(${CMAKE_CURRENT_LIST_DIR}/env_support/cmake/custom.cmake)
include_directories(${LVGL_ROOT_DIR})


#[[
    unfortunately CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS does not work for global data. 
    for global data we still need decl specs.
    Check out the docs to learn more about the limitations of CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS
    https://cmake.org/cmake/help/latest/prop_tgt/WINDOWS_EXPORT_ALL_SYMBOLS.html#prop_tgt:WINDOWS_EXPORT_ALL_SYMBOLS

    For all compiled sources within the library (i.e. basically all lvgl files) we need to use dllexport.
    For all compiled sources from outside the library (i.e. files which include lvgl headers) we need to use dllimport.
    We can do this by using CMakes INTERFACE and PRIVATE keyword.
  ]]
if (MSVC)
  target_compile_definitions(lvgl
    INTERFACE LV_ATTRIBUTE_EXTERN_DATA=__declspec\(dllimport\)
    PRIVATE LV_ATTRIBUTE_EXTERN_DATA=__declspec\(dllexport\)
  )
endif()