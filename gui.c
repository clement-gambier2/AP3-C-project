#include <SDL2/SDL.h>

int main(int argc, char *argv[]) {
    // Initialize SDL2
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Failed to initialize SDL2: %s\n", SDL_GetError());
        return 1;
    }

    //We start by creating a window
    SDL_Window* window = SDL_CreateWindow("AP3-C-Project",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          640, 480,
                                          SDL_WINDOW_SHOWN);

    //Then we need to render
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    // Create a black background
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Draw a red square in the center of the screen
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_Rect rect = { (640 - 30) / 2, (480 - 30) / 2, 30, 30 };
    SDL_RenderFillRect(renderer, &rect);

    // We print the render to the window
    SDL_RenderPresent(renderer);

    // Here we are waiting for events
    SDL_Event event;
    int running = 1;
    while (running) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = 0;
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_q:
                            running = 0;
                            break;
                        case SDLK_UP:
                            rect.y -= 10;
                            break;
                        case SDLK_DOWN:
                            rect.y += 10;
                            break;
                        case SDLK_LEFT:
                            rect.x -= 10;
                            break;
                        case SDLK_RIGHT:
                            rect.x += 10;
                            break;
                    }
                    break;
            }
        }


        // We create a grid
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        // Draw vertical lines
        for (int x = 0; x <= 640; x += 30) {
            SDL_RenderDrawLine(renderer, x, 0, x, 480);
        }
        // Draw horizontal lines
        for (int y = 0; y <= 480; y += 30) {
            SDL_RenderDrawLine(renderer, 0, y, 640, y);
        }

        // Draw a red square
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &rect);

        // Present the renderer to the screen
        SDL_RenderPresent(renderer);

        SDL_Delay(10);
    }

    // Cleanup SDL2
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
