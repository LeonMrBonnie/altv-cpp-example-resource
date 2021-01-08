#pragma once
#include "cpp-sdk/SDK.h"

class Player
{
    alt::Ref<alt::IVehicle> personalVehicle;
    alt::Ref<alt::IPlayer> player;

public:
    Player(alt::Ref<alt::IPlayer> _player) : player(_player) {};
    ~Player() = default;

    void SpawnPersonalVehicle(const char* model, alt::Vector3f pos);
    void RemovePersonalVehicle();
    alt::Ref<alt::IVehicle> GetPersonalVehicle()
    {
        return personalVehicle;
    }

    alt::Ref<alt::IPlayer> GetPlayer()
    {
        return player;
    }
};
