#pragma once
#include "main.h"
#include "entities/Player.h"

#include <algorithm>

class Server
{
    std::vector<Player*> players;

public:
    Server();
    ~Server() = default;

    Player* FindPlayer(alt::Ref<alt::IPlayer> player)
    {
        for(auto ply : players)
        {
            if(ply->GetPlayer() == player) return ply;
        }
        return nullptr;
    }
    void RemovePlayer(Player* player)
    {
        players.erase(std::remove(players.begin(), players.end(), player), players.end());
        delete player;
    }

    // Events
    void OnPlayerConnect(alt::Ref<alt::IPlayer> player);
    void OnPlayerDisconnect(alt::Ref<alt::IPlayer> player);
};
