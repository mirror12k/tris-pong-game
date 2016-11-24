
#include "pong_service.hpp"


pong_service::pong_service()
: tris::service_entity("pong_service"), player_paddle(new paddle(100, 200)), pong_ball(new ball(100, 100, 3))
{}

void pong_service::update(tris::engine* eng)
{
    const uint8_t* keys = SDL_GetKeyboardState(nullptr);
    if (keys[SDL_SCANCODE_W])
        this->player_paddle->sy -= 1.5;
    if (keys[SDL_SCANCODE_S])
        this->player_paddle->sy += 1.5;

    if (this->pong_ball->x >= this->player_paddle->sprite.rect.x &&
        this->pong_ball->x < this->player_paddle->sprite.rect.x + this->player_paddle->sprite.rect.w &&
        this->pong_ball->y >= this->player_paddle->sprite.rect.y &&
        this->pong_ball->y < this->player_paddle->sprite.rect.y + this->player_paddle->sprite.rect.h)
    {
        this->pong_ball->sx *= 1.01;
        this->pong_ball->sy *= 0.95;
        this->pong_ball->sa = this->player_paddle->sy;
        this->pong_ball->x += 2 * (this->player_paddle->sprite.rect.x + this->player_paddle->sprite.rect.w - this->pong_ball->x);
        this->pong_ball->sx = -this->pong_ball->sx;
    }


    if (this->pong_ball->x < 0)
    {
        this->pong_ball->x = eng->graphics.window_width / 2;
        this->pong_ball->y = eng->graphics.window_height / 2;
        this->pong_ball->sx = 1;
        this->pong_ball->sy = 0;
        this->pong_ball->sa = 0;
        this->pong_ball->sprite.angle = 0;
    }

}

void pong_service::on_added(tris::engine* eng)
{
}
void pong_service::on_removed(tris::engine* eng)
{
}


