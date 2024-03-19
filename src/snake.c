#include "snake.h"
#include "constants.h"

void snake_init(snake_t *snake) {
    snake->head = malloc(sizeof(snake_body_t));
    snake->head->prev = NULL;
    snake->head->next = NULL;
    snake->head->pos_x = GAME_LOGICAL_SIZE / 2;
    snake->head->pos_y = GAME_LOGICAL_SIZE / 2;

    snake->tail = snake->head;

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
    int32_t pos_x = snake->head->pos_x;
    int32_t pos_y = snake->head->pos_y;

    switch (snake->direction) {
        case DIRECTION_UP:
            pos_y -= 1;
            break;
        case DIRECTION_DOWN:
            pos_y += 1;
            break;
        case DIRECTION_RIGHT:
            pos_x += 1;
            break;
        case DIRECTION_LEFT:
            pos_x -= 1;
            break;
    }

    if (snake->head->pos_y >= GAME_LOGICAL_SIZE)
        pos_y = 0;

    if (snake->head->pos_y < 0)
        pos_y = GAME_LOGICAL_SIZE - 1;

    if (snake->head->pos_x >= GAME_LOGICAL_SIZE)
        pos_x = 0;

    if (snake->head->pos_x < 0)
        pos_x = GAME_LOGICAL_SIZE - 1;

    snake_body_t *body_part = snake->tail;

    while (body_part != snake->head) {
        if (snake->head->pos_x == body_part->pos_x && snake->head->pos_y == body_part->pos_y) {
            snake_reset(snake);
            return;
        }

        body_part->pos_x = body_part->prev->pos_x;
        body_part->pos_y = body_part->prev->pos_y;
        body_part = body_part->prev;
    }

    snake->head->pos_x = pos_x;
    snake->head->pos_y = pos_y;
}

void snake_append_tail(snake_t *snake) {
    snake_body_t *new_body = malloc(sizeof(snake_body_t));
    new_body->next = NULL;
    new_body->prev = snake->tail;
    
    snake->tail->next = new_body;
    snake->tail = new_body;
    
    snake->length++;

    switch (snake->direction) {
        case DIRECTION_UP:
            new_body->pos_x = snake->tail->pos_x;
            new_body->pos_y = snake->tail->pos_y + 1;
            break;
        case DIRECTION_DOWN:
            new_body->pos_x = snake->tail->pos_x;
            new_body->pos_y = snake->tail->pos_y - 1;
            break;
        case DIRECTION_RIGHT:
            new_body->pos_x = snake->tail->pos_x - 1;
            new_body->pos_y = snake->tail->pos_y;
            break;
        case DIRECTION_LEFT:
            new_body->pos_x = snake->tail->pos_x + 1;
            new_body->pos_y = snake->tail->pos_y;
            break;
    }
}

void snake_reset(snake_t *snake) {
    snake_free(snake);
    snake_init(snake);
}

void snake_draw(SDL_Renderer *renderer, snake_t *snake) {
    SDL_SetRenderDrawColor(renderer, 127, 127, 127, SDL_ALPHA_OPAQUE);
    snake_body_t *body_part = snake->head;

    while (body_part != NULL) {
        SDL_Rect body = {
            .x = body_part->pos_x,
            .y = body_part->pos_y,
            .w = 1,
            .h = 1,
        };

        SDL_RenderFillRect(renderer, &body);
        body_part = body_part->next;
    }
}

void snake_free(snake_t *snake) {
    snake_body_t *temp_body;

    while (snake->tail != NULL) {
        temp_body = snake->tail;
        snake->tail = snake->tail->next;
        free(temp_body);
    }
}
