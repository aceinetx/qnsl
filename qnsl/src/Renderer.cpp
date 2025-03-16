#include "Renderer.h"

qn::Renderer::Renderer()
{
	initscr();
	noecho();
	nodelay(stdscr, true);
	curs_set(0);
	mousemask(BUTTON1_PRESSED | BUTTON1_RELEASED | BUTTON1_MOVED, NULL);
}

qn::Renderer::~Renderer()
{
	endwin();
}

void qn::Renderer::plotPixel(Vec2 coords, char pixel) {
	mvaddch(coords.x, coords.y, pixel);
}

qn::Renderer* qn::Renderer::getInstance()
{
	static Renderer instance;
	return &instance;
}

void qn::Renderer::render() {
	auto director = qn::Director::getInstance();

	Scene* runningScene = director->getRunningScene();
	assert(runningScene != nullptr);

	runningScene->visit();
}