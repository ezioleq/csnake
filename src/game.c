#include "game.h"
#include "constants.h"

void game_run(game_t *game) {
    game->is_running = true;

    game_init(game);

    while (game->is_running) {
        while (SDL_PollEvent(&game->event)) {
            game_handle_events(game);
        }

        game_update(game);
        game_draw(game);
    }

    game_clean(game);
}

void game_init(game_t *game) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        fprintf(stderr, "Failed to initialize SDL! %s\n", SDL_GetError());
        exit(1);
    }

    uint32_t window_flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;
    game->window = SDL_CreateWindow(
            "snake",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            640,
            640,
            window_flags
    );

    if (game->window == NULL) {
        fprintf(stderr, "Failed to create window! %s\n", SDL_GetError());
        exit(1);
    }

    uint32_t renderer_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    game->renderer = SDL_CreateRenderer(game->window, -1, renderer_flags);

    if (game->renderer == NULL) {
        fprintf(stderr, "Failed to create renderer! %s\n", SDL_GetError());
        exit(1);
    }

    SDL_RenderSetLogicalSize(game->renderer, GAME_LOGICAL_SIZE, GAME_LOGICAL_SIZE);

    snake_init(&game->snake);
}

void game_handle_events(game_t *game) {
    if (game->event.type == SDL_QUIT)
        game->is_running = false;

    snake_handle_events(&game->event, &game->snake);
}

void game_update(game_t *game) {
    snake_update(&game->snake);
}

void game_draw(game_t *game) {
    SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(game->renderer);

    snake_draw(game->renderer, &game->snake);
    SDL_Delay(100);

    SDL_RenderPresent(game->renderer);
}

void game_clean(game_t *game) {
    snake_free(&game->snake);

    SDL_DestroyRenderer(game->renderer);
    SDL_DestroyWindow(game->window);
    SDL_Quit();
}
