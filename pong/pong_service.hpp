
#pragma once

#include "../tris/tris.hpp"

#include "particle.hpp"
#include "paddle.hpp"
#include "ball.hpp"

class pong_service : public tris::service_entity
{
public:
    paddle* player_paddle;
    ball* pong_ball;

    pong_service();

    void update(tris::engine* eng);

    void on_added(tris::engine* eng);
    void on_removed(tris::engine* eng);
};
