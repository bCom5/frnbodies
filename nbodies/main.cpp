
#include <SDL.h>
#include "vec.h"

struct app {
	SDL_Window* window; SDL_Renderer* renderer;
	Uint32 start_time;
	Uint32 last_time;

	app() {
		window = SDL_CreateWindow("n-bodies", 200, 200, 600, 600, SDL_WINDOW_ALLOW_HIGHDPI);
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

		SDL_ShowWindow(window);

		start_time = SDL_GetTicks();
	}

	void update(float t, float dt) {}
	
	void render(float t, float dt) {
		for (float x = -1.f; x < 1.f; x += 0.03f) {
			for (float y = -1.f; y < 1.f; y += 0.03f) {
				SDL_SetRenderDrawColor(renderer, (x + 1.f)*127.f, 127, (y + 1.f)*127.f, 255);
				SDL_RenderDrawPoint(renderer, 300 + sin(x*t + y * 20) * 200, 300 + cos(y*t + x * 20) * 200);
			}
		}
	}

	void run() {
		bool running = true;
		while (running) {
			SDL_Event e;
			while (SDL_PollEvent(&e)) {
				if (e.type == SDL_QUIT) running = false;
			}

			auto ticks = SDL_GetTicks();
			auto t = (ticks - start_time) / 1000.f;
			auto dt = (ticks - last_time) / 1000.f;
			last_time = ticks;

			update(t, dt);

			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
			SDL_RenderClear(renderer);
			render(t, dt);
			SDL_RenderPresent(renderer);
		}
	}
};

int main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_EVERYTHING);
	
	app a;
	a.run();

	SDL_Quit();
	return 0;
}