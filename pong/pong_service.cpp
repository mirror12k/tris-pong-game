
#include "pong_service.hpp"


pong_service::pong_service()
: tris::service_entity("pong_service"), player_paddle(new paddle(100, 200))
{}

void pong_service::update(tris::engine* eng)
{
    const uint8_t* keys = SDL_GetKeyboardState(nullptr);
    if (keys[SDL_SCANCODE_W])
        this->player_paddle->sy -= 1.5;
    if (keys[SDL_SCANCODE_S])
        this->player_paddle->sy += 1.5;
}

void pong_service::on_added(tris::engine* eng)
{
}
void pong_service::on_removed(tris::engine* eng)
{
}


