
#pragma once

#include "../tris/tris.hpp"

class ball : public tris::entity
{
public:
    tris::box sprite;

    float sx, sy = 0, sa = -1;
    float x, y;

    ball(int x, int y, int direction=1);

    void update(tris::engine* eng);

    void on_added(tris::engine* eng);
    void on_removed(tris::engine* eng);


};

