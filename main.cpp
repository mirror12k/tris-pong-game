
#include "tris/tris.hpp"


#include "pong/pong_service.hpp"


int main ()
{
    srand(time(nullptr));
    tris::engine game("Tris Pong", 800, 640, 60);

    pong_service* srv = new pong_service();
    game.update_ctx.add_entity(new tris::util::fps_ticker_entity());

    game.update_ctx.add_entity(srv->player_paddle);
    game.update_ctx.add_entity(srv->pong_ball);
    game.update_ctx.add_entity(srv);
    for (int y = 48; y < 640 - 48; y += 48)
        game.update_ctx.add_entity(new block(700, y, 32, tris::color(255,64,64,255)));
    for (int y = 48; y < 640 - 48; y += 48)
        game.update_ctx.add_entity(new block(700 - 48, y, 32, tris::color(64,255,64,255)));
    for (int y = 48; y < 640 - 48; y += 48)
        game.update_ctx.add_entity(new block(700 - 48 * 2, y, 32, tris::color(64,64,255,255)));
    game.run();

    return 0;
}

