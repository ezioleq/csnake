#include "game.h"

int main() {
    game_t *game = malloc(sizeof(game_t));
    game_run(game);

    free(game);
    return 0;
}
