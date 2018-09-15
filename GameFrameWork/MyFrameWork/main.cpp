#include "Game.h"

SDL_Event g_Event;

int main(int argc, char* args[])
{
	if (Game::GetInst()->init("Chapter 1", 100, 100, 1024, 720, false))
	{
		Game::GetInst()->Run();
	}
	Game::DeleteSingle();
	return 0;
}
