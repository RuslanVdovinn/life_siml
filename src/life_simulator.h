#ifndef LIFE_SIMULATOR_H
#define LIFE_SIMULATOR_H

#include "grid.h"
#include <ncurses.h>

class LifeSimulator {
public:
    LifeSimulator(int width, int height);

    void update();
    void draw() const;

private:
    Grid grid;
};

#endif
