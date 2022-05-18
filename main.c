#include <libtcod.h>
#include <SDL.h>
#include "roguelike.h"
#include "event.h"

int main(int argc, char *argv[])
{
    player_x = CONSOLE_WIDTH / 2;
    player_y = CONSOLE_HEIGHT / 2;

    TCOD_Console *console = TCOD_console_new(CONSOLE_WIDTH, CONSOLE_HEIGHT);
    /* TCOD_Tileset *tileset; <<TODO: Add tileset>> */

    TCOD_ContextParams context_params = {
        .tcod_version = TCOD_COMPILEDVERSION,
        .console = console,
        .window_title = "Roguelike",
        .sdl_window_flags = SDL_WINDOW_RESIZABLE,
        .vsync = true,
        .argc = argc,
        .argv = (const char *const *)argv /* Do not reuse const char in non-const location
                                            which will modify it at the same time the const
                                            characters are accessed */
    };

    TCOD_Context *context;
    TCOD_context_new(&context_params, &context);

    while (true) {
        TCOD_console_clear(console);

        TCOD_console_put_char(console, player_x, player_y, '@', TCOD_BKGND_NONE);

        TCOD_context_present(context, console, NULL);

        handle_events(context);
    }

    return 0;
}
