cmake_minimum_required(VERSION 3.20)
include_directories("qnsl/include")
include_directories("Source")

if(NOT DEFINED APP_NAME)
	message(SEND_ERROR "APP_NAME is not defined")
endif()

file(GLOB_RECURSE QNSL_SOURCES CONFIGURE_DEPENDS "qnsl/src/*.cpp")
file(GLOB_RECURSE APP_SOURCES CONFIGURE_DEPENDS "Source/*.cpp")

if(WIN32)
	file(GLOB_RECURSE PDCURSES_PLATFORM_SOURCES CONFIGURE_DEPENDS "qnsl/curses.win32/wincon/*.c")
	file(GLOB_RECURSE PDCURSES_SOURCES "qnsl/curses.win32/pdcurses/*.c")
	include_directories("qnsl/curses.win32")

	file(GLOB_RECURSE PROJ_SOURCES CONFIGURE_DEPENDS "proj.win32/*.cpp")
	include_directories("proj.win32")

	add_executable(${APP_NAME} ${PDCURSES_SOURCES} ${PDCURSES_PLATFORM_SOURCES} ${PROJ_SOURCES} ${QNSL_SOURCES} ${APP_SOURCES})
endif()

if(ANDROID)
	file(GLOB_RECURSE PROJ_SOURCES CONFIGURE_DEPENDS "proj.android/*.cpp")
	include_directories("proj.android")
	
	file(GLOB_RECURSE CURSES_SOURCES "qnsl/curses.linux/c++/*.cpp" "qnsl/curses.linux/form/*.c" "qnsl/curses.linux/ncurses/*.c" "qnsl/curses.linux/ncurses/base/*.c" "qnsl/curses.linux/ncurses/tinfo/*.c" "qnsl/curses.linux/ncurses/trace/*.c" "qnsl/curses.linux/ncurses/tty/*.c" "qnsl/curses.linux/ncurses/widechar/*.c" "qnsl/curses.linux/ncurses/*.c" "qnsl/curses.linux/panel/*.c" "qnsl/curses.linux/progs/*.c")
  include_directories("qnsl/curses.linux/ncurses")

	add_executable(${APP_NAME} ${PROJ_SOURCES} ${QNSL_SOURCES} ${APP_SOURCES} ${CURSES_SOURCES})
	target_link_libraries(${APP_NAME})
endif()
