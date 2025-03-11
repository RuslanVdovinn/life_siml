#include "grid.h"
#include <cstdlib>
#include <ctime>
#include <exception>

Grid::Grid(int width, int height) : width(width), height(height), cells(height, std::vector<bool>(width, false)) {
    std::srand(std::time(nullptr));
}

void Grid::randomize() {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            cells[y][x] = std::rand() % 2;
        }
    }
}

void Grid::update() {
    std::vector<std::vector<bool>> newCells = cells;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int neighbors = countNeighbors(x, y);

            if (cells[y][x] && (neighbors == 2 || neighbors == 3))
                if (x != width) {
                    newCells[y][x + 1] = true;
                } else {
                    newCells[y][x] = true;
                }
            else if (!cells[y][x] && neighbors == 3)
                newCells[y][x] = true;
            else
                newCells[y][x] = false;
        }
    }
    if (cells == newCells) {
        // throw std::__throw_runtime_error; // todo
    }
    cells = newCells;
}

int Grid::countNeighbors(int x, int y) const {
    int count = 0;
    for (int dy = -1; dy <= 1; ++dy) {
        for (int dx = -1; dx <= 1; ++dx) {
            if (dx == 0 && dy == 0) continue;
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < width && ny >= 0 && ny < height)
                count += cells[ny][nx];
        }
    }
    return count;
}

bool Grid::getCell(int x, int y) const {
    return cells[y][x];
}

void Grid::setCell(int x, int y, bool state) {
    cells[y][x] = state;
}

int Grid::getWidth() const { return width; }
int Grid::getHeight() const { return height; }
