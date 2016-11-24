
#include "block.hpp"

#include "pong_service.hpp"

block::block(int x, int y, int w, tris::color rgba)
: sprite(w, w, x - w/2, y - w/2, rgba)
{}

void block::on_added(tris::engine* eng)
{
    eng->graphics.add_box(&this->sprite);
    pong_service* srv = eng->update_ctx.get_service<pong_service>("pong_service");
    srv->subscribe(this);
}
void block::on_removed(tris::engine* eng)
{
    eng->graphics.remove_box(&this->sprite);
    pong_service* srv = eng->update_ctx.get_service<pong_service>("pong_service");
    srv->unsubscribe(this);
}

