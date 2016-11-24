
#include "particle.hpp"


particle::particle(int x, int y, int w, tris::color rgba)
: sprite(w, w, x - w/2, y - w/2, rgba), x(x), y(y)
{
    this->sx = (-50 + rand() % 101) / 10.0;
    this->sy = (-50 + rand() % 101) / 10.0;
    this->sa = (-50 + rand() % 101) / 10.0;
    this->sprite.angle = rand() % 360;
}

void particle::update(tris::engine* eng)
{
    this->x += this->sx;
    this->y += this->sy;
    this->sprite.rect.x = -this->sprite.rect.w/2 + this->x;
    this->sprite.rect.y = -this->sprite.rect.w/2 + this->y;
    this->sprite.angle += this->sa;

    this->sprite.rgba.a *= 0.95;
    this->sprite.changed = true;
    if (this->sprite.rgba.a == 0)
        eng->update_ctx.remove_entity(this);
}

void particle::on_added(tris::engine* eng)
{
    eng->graphics.add_box(&this->sprite);
}
void particle::on_removed(tris::engine* eng)
{
    eng->graphics.remove_box(&this->sprite);
    tris::entity::on_removed(eng);
}

