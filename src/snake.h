#ifndef CSNAKE_SNAKE_H
#define CSNAKE_SNAKE_H

#include <SDL2/SDL.h>
#include <stdlib.h>
#include "direction.h"

typedef struct snake_body_t {
    int32_t pos_x;
    int32_t pos_y;
    struct snake_body_t *prev;
    struct snake_body_t *next;
} snake_body_t;

typedef struct snake_t {
    snake_body_t *head;
    snake_body_t *tail;
    int32_t length;
    direction_t direction;
} snake_t;

void snake_init(snake_t *snake);

void snake_handle_events(SDL_Event *event, snake_t *snake);

void snake_update(snake_t *snake);

void snake_append_tail(snake_t *snake);

void snake_draw(SDL_Renderer *renderer, snake_t *snake);

void snake_free(snake_t *snake);

#endif
