#include <iostream>
#include <SDL.h>
#include <emscripten.h>

SDL_Window* g_window = nullptr;
SDL_Renderer* g_renderer = nullptr;
bool g_quit = false;

void mainLoop() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            g_quit = true;
        }
    }

    SDL_SetRenderDrawColor(g_renderer, 0, 0, 0, 255);
    SDL_RenderClear(g_renderer);

    SDL_SetRenderDrawColor(g_renderer, 255, 0, 0, 255);
    SDL_Rect rect = { 100, 100, 50, 50 };
    SDL_RenderFillRect(g_renderer, &rect);

    SDL_RenderPresent(g_renderer);
}

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
        return 1;
    }
    g_window = SDL_CreateWindow("Incogine Editor - Video Editor",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        1280, 720, SDL_WINDOW_OPENGL);

    if (!g_window) {
        std::cerr << "SDL window creation failed: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    g_renderer = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);

    if (!g_renderer) {
        std::cerr << "SDL renderer creation failed: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(g_window);
        SDL_Quit();
        return 1;
    }

    emscripten_set_main_loop(mainLoop, 0, 1);

    return 0;
}
