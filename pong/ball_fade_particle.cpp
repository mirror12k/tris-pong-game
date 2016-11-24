
#include "ball_fade_particle.hpp"


ball_fade_particle::ball_fade_particle(int x, int y, float a)
: sprite(16, 16, x - 8, y - 8, tris::color(255, 255, 255, 240))
{
    this->sprite.angle = a;
}

void ball_fade_particle::update(tris::engine* eng)
{
    this->sprite.rgba.a -= 16;
    this->sprite.changed = true;
    if (this->sprite.rgba.a == 0)
    {
        eng->update_ctx.remove_entity(this);
    }
}

void ball_fade_particle::on_added(tris::engine* eng)
{
    eng->graphics.add_box(&this->sprite);
}
void ball_fade_particle::on_removed(tris::engine* eng)
{
    eng->graphics.remove_box(&this->sprite);
}

