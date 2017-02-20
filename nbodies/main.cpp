
#include <SDL.h>

int main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_EVERYTHING);
	
	auto window = SDL_CreateWindow("n-bodies", 200, 200, 600, 600, SDL_WINDOW_ALLOW_HIGHDPI);
	auto renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

	SDL_ShowWindow(window);

	auto start_time = SDL_GetTicks();

	bool running = true;
	while (running) {
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) running = false;
		}

		auto t = (SDL_GetTicks() - start_time) / 1000.f;

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);

		for (float x = -1.f; x < 1.f; x += 0.03f) {
			for (float y = -1.f; y < 1.f; y += 0.03f) {
				SDL_SetRenderDrawColor(renderer, (x+1.f)*127.f, 127, (y+1.f)*127.f, 255);
				SDL_RenderDrawPoint(renderer, 300+sin(x*t + y*20)*200, 300+cos(y*t + x*20)*200);
			}
		}

		SDL_RenderPresent(renderer);
	}

	SDL_Quit();
	return 0;
}