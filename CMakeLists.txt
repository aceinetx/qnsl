cmake_minimum_required(VERSION 3.20)
project(QnslTest)
set(APP_NAME "QnslTest")

set(LINUX_NO_NCURSES YES)
set(LINUX_BACKEND "SDL2")

include("qnsl/qnsl.cmake")
