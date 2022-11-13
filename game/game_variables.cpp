#include "singleton.h"
#include "game_variables.h"

std::unique_ptr<GameVariables> Singleton<GameVariables>::single;