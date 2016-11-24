
#pragma once

#include "../tris/tris.hpp"

class paddle : public tris::entity
{
public:
    tris::box sprite;

    float sx = 0, sy = 0;
    float x, y;

    paddle(int x, int y);

    void update(tris::engine* eng);

    void on_added(tris::engine* eng);
    void on_removed(tris::engine* eng);


};

