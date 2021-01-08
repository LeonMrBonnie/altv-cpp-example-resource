#include "main.h"
#include "cpp-sdk/events/CPlayerConnectEvent.h"
#include "cpp-sdk/events/CPlayerDisconnectEvent.h"

alt::ICore* Core;
static Server* server;

EXPORT void Start(alt::ICore* _core)
{
    alt::ICore::SetInstance(_core);
    Core = _core;
    server = new Server();
}

EXPORT void Stop()
{
    delete server;
}

EXPORT bool OnEvent(const alt::CEvent* ev)
{
    using namespace alt;
    switch(ev->GetType())
    {
        case CEvent::Type::PLAYER_CONNECT:
        {
            auto e = static_cast<const CPlayerConnectEvent*>(ev);
            server->OnPlayerConnect(e->GetTarget());
            break;
        }
        case CEvent::Type::PLAYER_DISCONNECT:
        {
            auto e = static_cast<const CPlayerDisconnectEvent*>(ev);
            server->OnPlayerDisconnect(e->GetTarget());
            break;
        }
    }
    return true;
}
