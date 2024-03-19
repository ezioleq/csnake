#ifndef CSNAKE_GAME_H
#define CSNAKE_GAME_H

#include <stdbool.h>
#include <SDL2/SDL.h>
#include "snake.h"
#include "food.h"

typedef struct game_t {
    bool is_running;
    snake_t snake;
    food_t food;

    SDL_Event event;
    SDL_Window *window;
    SDL_Renderer *renderer;
} game_t;

void game_run(game_t *game);

void game_init(game_t *game);

void game_handle_events(game_t *game);

void game_update(game_t *game);

void game_draw(game_t *game);

void game_clean(game_t *game);

#endif
