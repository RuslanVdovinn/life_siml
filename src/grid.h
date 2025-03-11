#ifndef GRID_H
#define GRID_H

#include <vector>

class Grid {
public:
    Grid(int width, int height);

    void randomize();
    void update();
    bool getCell(int x, int y) const;
    void setCell(int x, int y, bool state);
    int getWidth() const;
    int getHeight() const;

private:
    int width, height;
    std::vector<std::vector<bool>> cells;

    int countNeighbors(int x, int y) const;
};

#endif
