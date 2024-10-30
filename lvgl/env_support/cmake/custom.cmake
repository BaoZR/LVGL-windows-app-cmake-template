include("${CMAKE_CURRENT_LIST_DIR}/version.cmake")

# Option to define LV_LVGL_H_INCLUDE_SIMPLE, default: ON
option(LV_LVGL_H_INCLUDE_SIMPLE
       "Use #include \"lvgl.h\" instead of #include \"../../lvgl.h\"" ON)

# Option to define LV_CONF_INCLUDE_SIMPLE, default: ON
option(LV_CONF_INCLUDE_SIMPLE
       "Use #include \"lv_conf.h\" instead of #include \"../../lv_conf.h\"" ON)

# Option LV_CONF_PATH, which should be the path for lv_conf.h
# If set parent path LV_CONF_DIR is added to includes
if( LV_CONF_PATH )
    get_filename_component(LV_CONF_DIR ${LV_CONF_PATH} DIRECTORY)
endif( LV_CONF_PATH )

# Option to build shared libraries (as opposed to static), default: OFF
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

# Set sources used for LVGL components
file(GLOB_RECURSE SOURCES ${LVGL_ROOT_DIR}/src/*.c ${LVGL_ROOT_DIR}/src/*.S ${LVGL_ROOT_DIR}/*.h)
# file(GLOB_RECURSE EXAMPLE_SOURCES ${LVGL_ROOT_DIR}/examples/*.c)
# file(GLOB_RECURSE DEMO_SOURCES ${LVGL_ROOT_DIR}/demos/*.c)
file(GLOB_RECURSE THORVG_SOURCES ${LVGL_ROOT_DIR}/src/libs/thorvg/*.cpp ${LVGL_ROOT_DIR}/src/others/vg_lite_tvg/*.cpp)

# Build LVGL library
add_library(lvgl ${SOURCES})
add_library(lvgl::lvgl ALIAS lvgl)

target_compile_definitions(
  lvgl PUBLIC $<$<BOOL:${LV_LVGL_H_INCLUDE_SIMPLE}>:LV_LVGL_H_INCLUDE_SIMPLE>
              $<$<BOOL:${LV_CONF_INCLUDE_SIMPLE}>:LV_CONF_INCLUDE_SIMPLE>)

# Add definition of LV_CONF_PATH only if needed
if(LV_CONF_PATH)
  target_compile_definitions(lvgl PUBLIC LV_CONF_PATH=${LV_CONF_PATH})
endif()

# Add definition of LV_CONF_SKIP only if needed
if(LV_CONF_SKIP)
  target_compile_definitions(lvgl PUBLIC LV_CONF_SKIP=1)
endif()

# Include root and optional parent path of LV_CONF_PATH
target_include_directories(lvgl SYSTEM PUBLIC ${LVGL_ROOT_DIR} ${LV_CONF_DIR} ${CMAKE_CURRENT_BINARY_DIR})


if(NOT LV_CONF_BUILD_DISABLE_THORVG_INTERNAL)
    add_library(lvgl_thorvg ${THORVG_SOURCES})
    add_library(lvgl::thorvg ALIAS lvgl_thorvg)
    target_include_directories(lvgl_thorvg SYSTEM PUBLIC ${LVGL_ROOT_DIR}/src/libs/thorvg)
    target_link_libraries(lvgl_thorvg PUBLIC lvgl)
endif()

if(NOT (CMAKE_C_COMPILER_ID STREQUAL "MSVC"))
  set_source_files_properties(${LVGL_ROOT_DIR}/src/others/vg_lite_tvg/vg_lite_tvg.cpp PROPERTIES COMPILE_FLAGS -Wunused-parameter)
endif()

# Library and headers can be installed to system using make install
file(GLOB LVGL_PUBLIC_HEADERS
    "${LVGL_ROOT_DIR}/lvgl.h"
    "${LVGL_ROOT_DIR}/lv_version.h"
    "${LVGL_ROOT_DIR}/lv_conf.h")

if(NOT LV_CONF_SKIP)
  if (LV_CONF_PATH)
    list(APPEND LVGL_PUBLIC_HEADERS
    ${LV_CONF_PATH})
  else()
    list(APPEND LVGL_PUBLIC_HEADERS
    "${CMAKE_SOURCE_DIR}/lv_conf.h")
  endif()
endif()

if("${LIB_INSTALL_DIR}" STREQUAL "")
  set(LIB_INSTALL_DIR "lib")
endif()
if("${RUNTIME_INSTALL_DIR}" STREQUAL "")
  set(RUNTIME_INSTALL_DIR "bin")
endif()
if("${INC_INSTALL_DIR}" STREQUAL "")
  set(INC_INSTALL_DIR "include/lvgl")
endif()

set(CMAKE_INSTALL_PREFIX .)


configure_file("${LVGL_ROOT_DIR}/lvgl.pc.in" ${CMAKE_BINARY_DIR}/lvgl.pc @ONLY)
configure_file("${LVGL_ROOT_DIR}/lv_version.h.in" ${CMAKE_BINARY_DIR}/lv_version.h @ONLY)

install(
  FILES "${CMAKE_CURRENT_BINARY_DIR}/lvgl.pc"
  DESTINATION "${LIB_INSTALL_DIR}/pkgconfig/")
