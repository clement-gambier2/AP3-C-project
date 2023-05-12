#include <SDL2/SDL.h>

int main(int argc, char *argv[]) {
    // Initialize SDL2
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Failed to initialize SDL2: %s\n", SDL_GetError());
        return 1;
    }

    // Create a window
    SDL_Window* window = SDL_CreateWindow("AP3-C-Project",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          640, 480,
                                          SDL_WINDOW_SHOWN);

    // Create a renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    // Set the drawing color to black
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    // Clear the screen to black
    SDL_RenderClear(renderer);

    // Set the drawing color to red
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    // Draw a red square in the center of the screen
    SDL_Rect rect = { (640 - 50) / 2, (480 - 50) / 2, 50, 50 };
    SDL_RenderFillRect(renderer, &rect);

    // Present the renderer to the screen
    SDL_RenderPresent(renderer);

    // Wait for events
    SDL_Event event;
    int running = 1;
    while (running) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = 0;
                    break;
                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_q) {
                        running = 0;
                    }
                    break;
            }
        }
        SDL_Delay(10);
    }

    // Cleanup SDL2
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
