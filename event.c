#include "event.h"

void handle_keys(SDL_Event *event) {
    switch (event->type) {
    case SDL_KEYDOWN:
        switch (event->key.keysym.sym) {
        case SDLK_LEFT:
            // Set left
            break;
        case SDLK_RIGHT:
            // Set right
            break;
        case SDLK_UP:
            // Set up
            break;
        case SDLK_DOWN:
            // Set down
            break;
        default:
            break;
        }
    case SDL_KEYUP:
        switch (event->key.keysym.sym) {
        case SDLK_LEFT:
            // Reset left
            break;
        case SDLK_RIGHT:
            // Reset right
            break;
        case SDLK_UP:
            // Reset up
            break;
        case SDLK_DOWN:
            // Reset down
            break;
        default:
            break;
        }
    case SDL_QUIT:
        // Quit
        break;
    default:
        break;
    }
}

void handle_events(TCOD_Context *context) {
    SDL_Event *event;

    SDL_WaitEvent(NULL);

    while (SDL_PollEvent(event)) {
        TCOD_context_convert_event_coordinates(context, event);
    }
}
