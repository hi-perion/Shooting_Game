cmake_minimum_required(VERSION 3.12)
project(Shooting_Game)

set(CMAKE_CXX_STANDARD 14)

include_directories(./dxlib)
link_directories(./dxlib)

add_executable(Shooting_Game main.cpp character.cpp character.h player.cpp player.h define.h bullet.cpp bullet.h game.cpp game.h enemy.cpp enemy.h boss.cpp boss.h)

target_link_libraries(
        Shooting_Game
        DxLib
        DxUseCLib
        DxDrawFunc
        jpeg
        png
        zlib
        tiff
        theora_static
        vorbis_static
        vorbisfile_static
        ogg_static
        bulletdynamics
        bulletcollision
        bulletmath
        opusfile
        opus
        silk_common
        celt
)