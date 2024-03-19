#ifndef CSNAKE_FOOD_H
#define CSNAKE_FOOD_H

#include <SDL2/SDL.h>
#include <stdint.h>
#include "snake.h"

typedef struct food_t {
    int32_t pos_x;
    int32_t pos_y;
} food_t;

void food_init(food_t *food);

void food_randomize_position(food_t *food);

void food_update(food_t *food, snake_t *snake);

void food_draw(SDL_Renderer *renderer, food_t *food);

#endif
