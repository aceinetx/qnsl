#include "Renderer.h"

#include <curses.h>

qn::Renderer::Renderer() {
#ifdef LINUX_SDL2
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		exit(1);

	atexit(SDL_Quit);

	pdc_window = SDL_CreateWindow(APP_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
	pdc_screen = SDL_GetWindowSurface(pdc_window);
	pdc_yoffset = 416;

	int i, j;
	for (i = 640, j = 416; j; i -= 2, j -= 2) {
		SDL_Rect dest;

		dest.x = (640 - i) / 2;
		dest.y = (416 - j) / 2;
		dest.w = i;
		dest.h = j;

		SDL_FillRect(pdc_screen, &dest, SDL_MapRGB(pdc_screen->format, rand() % 256, rand() % 256, rand() % 256));
	}
	SDL_UpdateWindowSurface(pdc_window);
#endif

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

qn::Renderer* qn::Renderer::getInstance() {
	static Renderer instance;
	return &instance;
}

void qn::Renderer::render() {
	auto director = qn::Director::getInstance();

	Scene* runningScene = director->getRunningScene();
	assert(runningScene != nullptr);

	runningScene->visit();
	refresh();

#ifdef LINUX_SDL2
	SDL_UpdateWindowSurface(pdc_window);
#endif
}
