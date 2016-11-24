
#include "paddle.hpp"


paddle::paddle(int x, int y)
: sprite(16, 128, x - 8, y - 64, tris::color(200, 200, 200, 255)), x(x - 8), y(y - 64)
{}

void paddle::update(tris::engine* eng)
{
    this->x += this->sx *= 0.80;
    this->y += this->sy *= 0.80;

    if (this->x + 8 < 0)
        this->x = -8;
    else if (this->x + 8 >= eng->graphics.window_width)
        this->x = eng->graphics.window_width - 9;

    if (this->y + 64 < 0)
        this->y = -64;
    else if (this->y + 64 >= eng->graphics.window_height)
        this->y = eng->graphics.window_height - 65;

    this->sprite.rect.x = this->x;
    this->sprite.rect.y = this->y;

}


void paddle::on_added(tris::engine* eng)
{
    eng->graphics.add_box(&this->sprite);
}
void paddle::on_removed(tris::engine* eng)
{
    eng->graphics.remove_box(&this->sprite);
}

