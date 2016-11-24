
#pragma once

#include "../tris/tris.hpp"

class particle : public tris::entity
{
public:
    tris::box sprite;

    float sx, sy, sa;
    float x, y;

    particle(int x, int y, int w, tris::color rgba);

    void update(tris::engine* eng);

    void on_added(tris::engine* eng);
    void on_removed(tris::engine* eng);
};


