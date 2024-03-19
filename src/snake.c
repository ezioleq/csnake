#include "snake.h"
#include "constants.h"

void snake_init(snake_t *snake) {
    snake->pos_x = GAME_LOGICAL_SIZE / 2;
    snake->pos_y = GAME_LOGICAL_SIZE / 2;
    snake->length = 1;
    snake->direction = DIRECTION_RIGHT;
}

void snake_handle_events(SDL_Event *event, snake_t *snake) {
    switch (event->key.keysym.sym) {
        case SDLK_UP:
            snake->direction = DIRECTION_UP;
            break;
        case SDLK_DOWN:
            snake->direction = DIRECTION_DOWN;
            break;
        case SDLK_RIGHT:
            snake->direction = DIRECTION_RIGHT;
            break;
        case SDLK_LEFT:
            snake->direction = DIRECTION_LEFT;
            break;
    }
}

void snake_update(snake_t *snake) {
    switch (snake->direction) {
        case DIRECTION_UP:
            snake->pos_y -= 1;
            break;
        case DIRECTION_DOWN:
            snake->pos_y += 1;
            break;
        case DIRECTION_RIGHT:
            snake->pos_x += 1;
            break;
        case DIRECTION_LEFT:
            snake->pos_x -= 1;
            break;
    }

    if (snake->pos_y >= GAME_LOGICAL_SIZE)
        snake->pos_y = 0;

    if (snake->pos_y < 0)
        snake->pos_y = GAME_LOGICAL_SIZE - 1;

    if (snake->pos_x >= GAME_LOGICAL_SIZE)
        snake->pos_x = 0;

    if (snake->pos_x < 0)
        snake->pos_x = GAME_LOGICAL_SIZE - 1;
}

void snake_append_tail(snake_t *snake) {
    snake->length++;
}

void snake_draw(SDL_Renderer *renderer, snake_t *snake) {
    SDL_Rect body = {
        .x = snake->pos_x,
        .y = snake->pos_y,
        .w = 1,
        .h = 1,
    };

    SDL_SetRenderDrawColor(renderer, 127, 127, 127, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, &body);
}
