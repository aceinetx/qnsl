#pragma once
#include "Director.h"
#include "Vec2.h"
#ifdef LINUX_SDL2
#include <SDL2/SDL.h>
#endif
#include <curses.h>

namespace qn {
class Renderer {
private:
#ifdef LINUX_SDL2
	SDL_Window* pdc_window;
	SDL_Surface* pdc_screen;
	int pdc_yoffset;
#endif
public:
	static Renderer* getInstance();
	~Renderer();

	void plotPixel(Vec2 coords, char pixel);
	void render();

private:
	Renderer();
};
} // namespace qn
