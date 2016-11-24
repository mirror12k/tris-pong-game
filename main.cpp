
#include "tris/tris.hpp"


#include "pong/ball.hpp"


int main ()
{
    tris::engine game("Tris Pong", 800, 640, 60);

    game.update_ctx.add_entity(new ball(100, 100, 1));
    game.run();

    return 0;
}

