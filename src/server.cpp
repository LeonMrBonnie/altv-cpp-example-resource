#include "server.h"

Server::Server()
{
    Log::Info << "Started server" << Log::Endl;
}

void Server::OnPlayerConnect(alt::Ref<alt::IPlayer> _player)
{
    auto player = new Player(_player);
    players.emplace_back(player);

    player->SpawnPersonalVehicle("t20", {5, 5, 71});

    _player->SetModel(Core->Hash("mp_m_freemode_01"));
    _player->Spawn({0, 0, 71}, 0);

    Log::Colored << "~y~" << _player->GetName().CStr() << " ~w~has ~g~connected" << Log::Endl;
}

void Server::OnPlayerDisconnect(alt::Ref<alt::IPlayer> _player)
{
    auto player = FindPlayer(_player);
    player->RemovePersonalVehicle();
    RemovePlayer(player);

    Log::Colored << "~y~" << _player->GetName().CStr() << " ~w~has ~r~disconnected" << Log::Endl;
}