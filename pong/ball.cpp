
#include "ball.hpp"


#include "particle.hpp"

ball::ball(int x, int y, int direction)
: sprite(16, 16, x - 8, y - 8, tris::color(255, 255, 255, 255)), sx(1 * direction), x(x), y(y)
{}

void ball::update(tris::engine* eng)
{
//    this->sx *= 1.001;
//    this->sy *= 1.001;
    this->sy += this->sa / 720.0;
    this->sprite.angle += this->sa;
    this->x += this->sx;
    this->y += this->sy;

    if (this->y < 0)
    {
        for (int i = 0; i < 10; i++)
            eng->update_ctx.add_entity(new particle(this->x, this->y, 3 + rand() % 5, tris::color(255, 255, 255, 255)));
        this->y += -(this->y);
        this->sy = -this->sy;
    }
    else if (this->y >= eng->graphics.window_height)
    {
        for (int i = 0; i < 10; i++)
            eng->update_ctx.add_entity(new particle(this->x, this->y, 3 + rand() % 5, tris::color(255, 255, 255, 255)));
        this->y += eng->graphics.window_height - (this->y);
        this->sy = -this->sy;
    }

    if (this->x >= eng->graphics.window_width)
    {
        for (int i = 0; i < 10; i++)
            eng->update_ctx.add_entity(new particle(this->x, this->y, 3 + rand() % 5, tris::color(255, 255, 255, 255)));
        this->x += eng->graphics.window_width - (this->x);
        this->sx = -this->sx;
    }

    this->sprite.rect.x = -8 + this->x;
    this->sprite.rect.y = -8 + this->y;
}

void ball::on_added(tris::engine* eng)
{
    eng->graphics.add_box(&this->sprite);
}
void ball::on_removed(tris::engine* eng)
{
    eng->graphics.remove_box(&this->sprite);
}
