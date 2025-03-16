cmake_minimum_required(VERSION 3.20)
include_directories("qnsl/include")
include_directories("Source")

if(NOT DEFINED APP_NAME)
	message(SEND_ERROR "APP_NAME is not defined")
endif()

file(GLOB_RECURSE QNSL_SOURCES CONFIGURE_DEPENDS "qnsl/src/*.cpp")
file(GLOB_RECURSE APP_SOURCES CONFIGURE_DEPENDS "Source/*.cpp")

if(WIN32)
	file(GLOB_RECURSE PDCURSES_PLATFORM_SOURCES CONFIGURE_DEPENDS "qnsl/PDCurses/wincon/*.c")
	file(GLOB_RECURSE PDCURSES_SOURCES "qnsl/PDCurses/pdcurses/*.c")
	include_directories("qnsl/PDCurses")

	file(GLOB_RECURSE PROJ_SOURCES CONFIGURE_DEPENDS "proj.win32/*.cpp")
	include_directories("proj.win32")

	add_executable(${APP_NAME} ${PDCURSES_SOURCES} ${PDCURSES_PLATFORM_SOURCES} ${PROJ_SOURCES} ${QNSL_SOURCES} ${APP_SOURCES})
else()
	file(GLOB_RECURSE PROJ_SOURCES CONFIGURE_DEPENDS "proj.linux/*.cpp")
	include_directories("proj.linux")

	find_package(Curses REQUIRED QUIET)

	if(Curses_FOUND)
		message(STATUS "NCurses found. Linking against NCurses.")
		add_executable(${APP_NAME} ${PROJ_SOURCES} ${QNSL_SOURCES} ${APP_SOURCES})
		target_link_libraries(${APP_NAME} ${CURSES_LIBRARIES})
	else()
		message(STATUS "NCurses not found. Using PDCurses.")
		file(GLOB_RECURSE PDCURSES_PLATFORM_SOURCES CONFIGURE_DEPENDS "qnsl/PDCurses/x11/*.c")
		file(GLOB_RECURSE PDCURSES_SOURCES "qnsl/PDCurses/common/*.c" "qnsl/PDCurses/pdcurses/*.c")
		include_directories("qnsl/PDCurses")

		add_executable(${APP_NAME} ${PROJ_SOURCES} ${QNSL_SOURCES} ${APP_SOURCES} ${PDCURSES_SOURCES} ${PDCURSES_PLATFORM_SOURCES})
		target_link_libraries(${APP_NAME} "X11" "Xt" "Xaw" "Xmu" "Xpm")
	endif()
endif()
