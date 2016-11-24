
#include "ball.hpp"


ball::ball(int x, int y, int direction)
: sprite(16, 16, x - 8, y - 8, tris::color(255, 255, 255, 255)), sx(1 * direction), x(x - 8), y(y - 8)
{}

void ball::update(tris::engine* eng)
{
    this->sx *= 1.001;
    this->sy *= 1.001;
    this->sy += this->sa / 720.0;
    this->sprite.angle += this->sa;
    this->sprite.rect.x = this->x += this->sx;
    this->sprite.rect.y = this->y += this->sy;

    if (this->y + 8 < 0)
    {
        this->y += -(this->y + 8);
        this->sy = -this->sy;
    }
    else if (this->y + 8 >= eng->graphics.window_height)
    {
        this->y += eng->graphics.window_height - (this->y + 8);
        this->sy = -this->sy;
    }
}

void ball::on_added(tris::engine* eng)
{
    eng->graphics.add_box(&this->sprite);
}
void ball::on_removed(tris::engine* eng)
{
    eng->graphics.remove_box(&this->sprite);
}
