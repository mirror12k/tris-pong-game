
#pragma once

#include "../tris/tris.hpp"

class block : public tris::entity
{
public:
    tris::box sprite;

    block(int x, int y, int w, tris::color rgba);

    void on_added(tris::engine* eng);
    void on_removed(tris::engine* eng);
};



