cmake_minimum_required(VERSION 3.20)
include_directories("qnsl/include")
include_directories("Source")

if(NOT DEFINED APP_NAME)
	message(SEND_ERROR "APP_NAME is not defined")
endif()

add_compile_definitions(-DAPP_NAME="\\"${APP_NAME}\\"")

file(GLOB QNSL_SOURCES CONFIGURE_DEPENDS "qnsl/src/*.cpp")
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

	if(Curses_FOUND AND NOT LINUX_NO_NCURSES)
		message(STATUS "NCurses found. Linking against NCurses.")
		add_executable(${APP_NAME} ${PROJ_SOURCES} ${QNSL_SOURCES} ${APP_SOURCES})
		target_link_libraries(${APP_NAME} ${CURSES_LIBRARIES})
	else()
		message(STATUS "NCurses not found.")

		if(LINUX_BACKEND STREQUAL "X11")
			message(STATUS "Using X11.")
			file(GLOB_RECURSE PDCURSES_PLATFORM_SOURCES CONFIGURE_DEPENDS "qnsl/PDCurses/x11/*.c")
			set(LINUX_PLATFORM_LIBS "X11" "Xt" "Xaw" "Xmu" "Xpm")
		elseif(LINUX_BACKEND STREQUAL "SDL2")
			find_package(SDL2 REQUIRED)

			add_compile_definitions(LINUX_SDL2 SDL_MAIN_HANDLED)
			if(SDL2_FOUND)
				message(STATUS "Using SDL2.")
				file(GLOB_RECURSE PDCURSES_ALL_PLATFORM_SOURCES CONFIGURE_DEPENDS "qnsl/PDCurses/sdl2/*.c")

				set(PDCURSES_PLATFORM_SOURCES)
				foreach(FILE ${PDCURSES_ALL_PLATFORM_SOURCES})
					get_filename_component(FILENAME ${FILE} NAME)
					if(NOT FILENAME STREQUAL "sdltest.c")
						list(APPEND PDCURSES_PLATFORM_SOURCES ${FILE})
					endif()
				endforeach()

				set(LINUX_PLATFORM_LIBS "SDL2")
				include_directories(${SDL2_INCLUDE_DIRS})
			else()
				message(SEND_ERROR "SDL2 not found")
			endif()
		else()
			message(SEND_ERROR "unknown LINUX_BACKEND")
		endif()

		file(GLOB_RECURSE PDCURSES_SOURCES "qnsl/PDCurses/common/*.c" "qnsl/PDCurses/pdcurses/*.c")
		include_directories("qnsl/PDCurses")

		add_executable(${APP_NAME} ${PROJ_SOURCES} ${QNSL_SOURCES} ${APP_SOURCES} ${PDCURSES_SOURCES} ${PDCURSES_PLATFORM_SOURCES})
		target_link_libraries(${APP_NAME} ${LINUX_PLATFORM_LIBS})
	endif()
endif()
