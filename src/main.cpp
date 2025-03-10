#include <ncurses.h>
#include <vector>
#include <unistd.h>

const int WIDTH = 20;
const int HEIGHT = 10;

void drawGrid(const std::vector<std::vector<int>>& grid) {
    clear();
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            mvprintw(y, x * 2, grid[y][x] ? "O" : ".");
        }
    }
    refresh();
}

int main() {
    initscr();
    noecho();
    curs_set(0);

    std::vector<std::vector<int>> grid(HEIGHT, std::vector<int>(WIDTH, 0));

    grid[4][5] = grid[4][6] = grid[4][7] = 1;

    while (true) {
        drawGrid(grid);
        usleep(200000);
    }

    endwin();
    return 0;
}