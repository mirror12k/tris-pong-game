
#pragma once

#include "../tris/tris.hpp"

#include "paddle.hpp"

class pong_service : public tris::service_entity
{
public:
    paddle* player_paddle;
    pong_service();

    void update(tris::engine* eng);

    void on_added(tris::engine* eng);
    void on_removed(tris::engine* eng);
};
