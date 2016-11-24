
#include "pong_service.hpp"

#define POINT_COLLIDES_WITH_RECT(X, Y, RECT) ((X) >= (RECT).x && (X) < (RECT).x + (RECT).w &&\
        (Y) >= (RECT).y && (Y) < (RECT).y + (RECT).h)

pong_service::pong_service()
: tris::subscription_service_entity<block>("pong_service"), player_paddle(new paddle(100, 320)), pong_ball(new ball(400, 320, 3))
{}

void pong_service::update(tris::engine* eng)
{
    const uint8_t* keys = SDL_GetKeyboardState(nullptr);
    if (keys[SDL_SCANCODE_W])
        this->player_paddle->sy -= 0.5;
    if (keys[SDL_SCANCODE_S])
        this->player_paddle->sy += 0.5;

    if (POINT_COLLIDES_WITH_RECT(this->pong_ball->x, this->pong_ball->y, this->player_paddle->sprite.rect)
//    this->pong_ball->x >= this->player_paddle->sprite.rect.x &&
//        this->pong_ball->x < this->player_paddle->sprite.rect.x + this->player_paddle->sprite.rect.w &&
//        this->pong_ball->y >= this->player_paddle->sprite.rect.y &&
//        this->pong_ball->y < this->player_paddle->sprite.rect.y + this->player_paddle->sprite.rect.h
        )
    {
        for (int i = 0; i < 15; i++)
            eng->update_ctx.add_entity(new particle(this->pong_ball->x, this->pong_ball->y, 3 + rand() % 8, tris::color(255, 255, 255, 255)));

        this->pong_ball->sx *= 1.01;
        this->pong_ball->sy *= 0.75;
        this->pong_ball->sa = -4 * this->player_paddle->sy;
        this->pong_ball->x += 2 * (this->player_paddle->sprite.rect.x + this->player_paddle->sprite.rect.w - this->pong_ball->x);
        this->pong_ball->sx = -this->pong_ball->sx;
    }


    if (this->pong_ball->x < 0)
    {
        for (int i = 0; i < 50; i++)
            eng->update_ctx.add_entity(new particle(this->pong_ball->x, this->pong_ball->y, 5 + rand() % 16, tris::color(255, 255, 255, 255)));

        this->pong_ball->x = eng->graphics.window_width / 2;
        this->pong_ball->y = eng->graphics.window_height / 2;
        this->pong_ball->sx = 3;
        this->pong_ball->sy = 0;
        this->pong_ball->sa = 0;
        this->pong_ball->sprite.angle = 0;
    }
    else
    {
        for (auto it = this->subscribed_entities.begin(), it_end = this->subscribed_entities.end(); it != it_end; it++)
        {
            if (POINT_COLLIDES_WITH_RECT(this->pong_ball->x, this->pong_ball->y, (*it)->sprite.rect))
            {
            for (int i = 0; i < 50; i++)
                eng->update_ctx.add_entity(new particle((*it)->sprite.rect.x + (*it)->sprite.rect.w / 2, (*it)->sprite.rect.y + (*it)->sprite.rect.w / 2,
                        4 + rand() % (*it)->sprite.rect.w / 2, (*it)->sprite.rgba));
                eng->update_ctx.remove_entity(*it);
            }
        }
    }

}


