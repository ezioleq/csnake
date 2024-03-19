#include "food.h"

#include "mathf.h"
#include "constants.h"

void food_init(food_t *food) {
    food_randomize_position(food);
}

void food_randomize_position(food_t *food) {
    food->pos_x = mathf_random_between(0, GAME_LOGICAL_SIZE - 1);
    food->pos_y = mathf_random_between(0, GAME_LOGICAL_SIZE - 1);
}

void food_update(food_t *food, snake_t *snake) {
    if (snake->head->pos_x == food->pos_x && snake->head->pos_y == food->pos_y) {
        food_randomize_position(food);
        snake_append_tail(snake);
    }
}

void food_draw(SDL_Renderer *renderer, food_t *food) {
    SDL_Rect body = {
        .x = food->pos_x,
        .y = food->pos_y,
        .w = 1,
        .h = 1,
    };

    SDL_SetRenderDrawColor(renderer, 255, 64, 64, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, &body);
}
