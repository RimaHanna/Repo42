#include <SDL.h>

void handle_event(SDL_Event event) {
    switch (event.type) {
        case SDL_MOUSEBUTTONDOWN:
            if (event.button.button == SDL_BUTTON_LEFT) {
                printf("Left mouse button clicked at (%d, %d)\n", event.button.x, event.button.y);
                // Handle left-click event
            } else if (event.button.button == SDL_BUTTON_RIGHT) {
                printf("Right mouse button clicked at (%d, %d)\n", event.button.x, event.button.y);
                // Handle right-click event
            }
            break;
        case SDL_MOUSEWHEEL:
            if (event.wheel.y > 0) {
                printf("Mouse wheel scrolled up\n");
                // Handle scroll up (zoom in) event
            } else if (event.wheel.y < 0) {
                printf("Mouse wheel scrolled down\n");
                // Handle scroll down (zoom out) event
            }
            break;
        default:
            break;
    }
}

int main(int argc, char *argv[]) {
    // SDL initialization code here
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        handle_event(event);
    }
    // SDL cleanup code here
    return 0;
}

