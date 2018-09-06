#include <SDL.h>

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;

SDL_Event g_event;

int main(int argc, char* args[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		g_pWindow = SDL_CreateWindow("PP01.HelloSDL",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			640, 480, SDL_WINDOW_SHOWN);

		if (g_pWindow != 0)
		{
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
		}
		else
		{
			return 1;
		}


		int rectPosX = 0;
		int rectPosY = 0;

		while (1)
		{
			SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);
			SDL_RenderClear(g_pRenderer);
			if (SDL_PollEvent(&g_event))
			{
				if (g_event.key.keysym.sym == SDLK_UP)
				{
					rectPosY -= 3;
				}
				if (g_event.key.keysym.sym == SDLK_DOWN)
				{
					rectPosY += 3;
				}
				if (g_event.key.keysym.sym == SDLK_LEFT)
				{
					rectPosX -= 3;
				}
				if (g_event.key.keysym.sym == SDLK_RIGHT)
				{
					rectPosX += 3;
				}
				if (g_event.key.keysym.sym == SDLK_ESCAPE)
				{
					SDL_Quit();
				}
			}

			SDL_SetRenderDrawColor(g_pRenderer, 255, 255, 255, 255);
			SDL_Rect rect = { rectPosX,rectPosY,50,50 };
			SDL_RenderDrawRect(g_pRenderer, &rect);


			SDL_RenderPresent(g_pRenderer);
		}
		
		SDL_Delay(1000);
		SDL_Quit();

		return 0;
	}
}