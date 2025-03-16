#include "Renderer.h"
#include <curses.h>


qn::Renderer::Renderer() {
	initscr();
	noecho();
	nodelay(stdscr, true);
	curs_set(0);
#ifdef BUTTON1_MOVED
	mousemask(BUTTON1_PRESSED | BUTTON1_RELEASED | BUTTON1_MOVED, NULL);
#else
	mousemask(BUTTON1_PRESSED | BUTTON1_RELEASED, NULL);
#endif
}

qn::Renderer::~Renderer() {
	endwin();
}

void qn::Renderer::plotPixel(Vec2 coords, char pixel) {
	mvaddch(coords.y, coords.x, pixel);
}

qn::Renderer *qn::Renderer::getInstance() {
	static Renderer instance;
	return &instance;
}

void qn::Renderer::render() {
	auto director = qn::Director::getInstance();

	Scene *runningScene = director->getRunningScene();
	assert(runningScene != nullptr);

	runningScene->visit();
}
