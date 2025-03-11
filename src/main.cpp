#include <ncurses.h>
#include <unistd.h>
#include "grid.h"
#include "life_simulator.h"

int main() {
    initscr();
    noecho();
    curs_set(0);
    timeout(0);

    LifeSimulator simulator(60, 20);

    while (true) {
        simulator.draw();
        simulator.update();
        usleep(100000);

        int ch = getch();
        if (ch == 'q') break;
    }

    endwin();
    return 0;
}
