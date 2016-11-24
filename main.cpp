
#include "tris/tris.hpp"


#include "pong/ball.hpp"
#include "pong/pong_service.hpp"


int main ()
{
    tris::engine game("Tris Pong", 800, 640, 60);

    game.update_ctx.add_entity(new ball(100, 100, 1));
    pong_service* srv = new pong_service();
    game.update_ctx.add_entity(srv->player_paddle);
    game.update_ctx.add_entity(srv);
    game.update_ctx.add_entity(new tris::util::fps_ticker_entity());
    game.run();

    return 0;
}

