#source files
set(SOURCE_FILES
        coord.cpp
        entity.cpp
        game.cpp
        main.cpp
        map.cpp
        mapobject.cpp
        monster.cpp
        player.cpp
        playscreen.cpp
        properties.cpp
        tile.cpp
        tui.cpp
        utility.cpp
        world.cpp
)

#find libtcod library
find_package(LIBTCODXX REQUIRED)
include_directories(${LIBTCODXX_INCLUDE_DIRS})

#build and link
add_executable(Xoria ${SOURCE_FILES})
target_link_libraries(Xoria ${LIBTCODXX_LIBRARIES})
