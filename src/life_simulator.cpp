#include "life_simulator.h"

LifeSimulator::LifeSimulator(int width, int height) : grid(width, height) {
    grid.randomize();
}

void LifeSimulator::update() {
    try {
        grid.update();
    } catch (...) {
        
    }
    
}

void LifeSimulator::draw() const {
    clear();
    for (int y = 0; y < grid.getHeight(); ++y) {
        for (int x = 0; x < grid.getWidth(); ++x) {
            mvaddch(y, x, grid.getCell(x, y) ? 'O' : ' ');
        }
    }
    refresh();
}
