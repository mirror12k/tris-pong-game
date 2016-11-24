
#pragma once

#include "../tris/tris.hpp"

#include "particle.hpp"
#include "paddle.hpp"
#include "ball.hpp"

#include "block.hpp"

class pong_service : public tris::subscription_service_entity<block>
{
public:
    paddle* player_paddle;
    ball* pong_ball;

    pong_service();

    void update(tris::engine* eng);
};
