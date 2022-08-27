CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  if(DEFINED ENV{VITASDK})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VITASDK}/share/vita.toolchain.cmake" CACHE PATH "toolchain file")
  else()
    message(FATAL_ERROR "Please define VITASDK to point to your SDK path!")
  endif()
endif()

PROJECT(ZeldaPicross CXX)

# This line adds Vita helper macros, must go after project definition in order
# to build Vita specific artifacts (self/vpk).
include("${VITASDK}/share/vita.cmake" REQUIRED)
set(VITA_APP_NAME "The Legend of Zelda: Picross")
set(VITA_TITLEID  "ZELDAPIC1")

## Flags and includes for building
# Note that we make sure not to overwrite previous flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -flto -g -Wl,-q -O2 -D_PSP2_NPDRMPACKAGE_H_ -DHAVE_LIBSPEEXDSP -DWANT_FMMIDI=1 -DUSE_AUDIO_RESAMPLER -DHAVE_OGGVORBIS -Wall -fdiagnostics-color=always")
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -fno-rtti -fno-exceptions -std=gnu++11 -fpermissive")

FILE(GLOB SOURCES ${CMAKE_SOURCE_DIR}/src/vita/*.cpp ${CMAKE_SOURCE_DIR}/src/*.cpp ${CMAKE_SOURCE_DIR}/src/*.c)

include_directories(${CMAKE_SOURCE_DIR}/src/vita)

add_executable(ZeldaPicross 
  ${SOURCES}
)

target_link_libraries(${PROJECT_NAME} SDL_gfx SDL_image SDL freetype png png16 bz2 jpeg z mikmod mpg123 FLAC vorbisfile vorbis ogg opus opusfile modplug webp pthread stdc++)
# find_package(SDL2 REQUIRED)
# target_link_libraries($PROJECT_NAME} SDL2_ttf SDL2_mixer SDL2_image SDL2)
target_link_libraries(${PROJECT_NAME}
  SceDisplay_stub
  SceCtrl_stub
  SceAudio_stub
  SceAudioIn_stub
  SceSysmodule_stub
  SceGxm_stub
  SceCommonDialog_stub
  SceAppMgr_stub
  SceTouch_stub
  SceMotion_stub
  SceHid_stub
  SceIme_stub
  m
)
#include_directories("${VITASDK}/arm-vita-eabi/include;${VITASDK}/arm-vita-eabi/include/SDL2;")

vita_create_self(${PROJECT_NAME}.self ${PROJECT_NAME})
vita_create_vpk(${PROJECT_NAME}.vpk ${VITA_TITLEID} ${PROJECT_NAME}.self
  VERSION ${VITA_VERSION}
  NAME ${VITA_APP_NAME}
)