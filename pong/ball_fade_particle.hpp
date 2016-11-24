
#pragma once

#include "../tris/tris.hpp"

class ball_fade_particle : public tris::entity
{
public:
    tris::box sprite;

    ball_fade_particle(int x, int y, float a);

    void update(tris::engine* eng);

    void on_added(tris::engine* eng);
    void on_removed(tris::engine* eng);
};


