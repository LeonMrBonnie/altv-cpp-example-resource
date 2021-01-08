#include "Player.h"

void Player::SpawnPersonalVehicle(const char* model, alt::Vector3f pos)
{
    auto veh = alt::ICore::Instance().CreateVehicle(alt::ICore::Instance().Hash(model), pos, {0, 0, 0});
    veh->SetNumberplateText("CPP");
    veh->SetPrimaryColorRGB({255, 255, 255, 255});
    personalVehicle = veh;
}

void Player::RemovePersonalVehicle()
{
    alt::ICore::Instance().DestroyBaseObject(personalVehicle);
}
