/*
TODO:
- Make the Left Paddle move. [x]
- Make the Right Paddle and make it move. [x]
- Make the ball and make it move.
- Make the ball bounce off the walls and attach it's Y to Right Paddle's update function.
- Check for collisions Ball-PaddleR.
- Check for collisions Ball-PaddleL.
- Add scoring when paddle collides with ball or when ball falls off the screen.
- Make the ball reset position when it falls off the screen.
- Make these window properties changeable from config on the very top of the file:
Window X, Window Y, Window's Background Colour, Window's Title.
- Make the loop independent off FPS using Delta Time.
- Make a proper Makefile.
- Make a port to MS-DOS.
*/
#include <stdio.h>
#include <SDL/SDL.h>

int main(void) {
	int PaddleLX = 5; int PaddleLY = 300;
	int PaddleLW = 10; int PaddleLH = 40;
	int PaddleRX = 800-15; int PaddleRY = 300;
	int PaddleRW = 10; int PaddleRH = 40;
	int Quit = 0;
	SDL_Surface* Screen = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL Failed to initialize.\n");
		return 1;
	}

	if(!Screen) {
		printf("Window could not be created. SDL_Error @ stage 2\n");
		return 1;
	}

	SDL_WM_SetCaption("SDL Pong", NULL);

	SDL_Rect PaddleL;
	void UpdatePaddleL() {
	PaddleL.x = PaddleLX; PaddleL.y = PaddleLY;
	PaddleL.w = PaddleLW; PaddleL.h = PaddleLH;
	
	
				if((int)PaddleLY > 600-PaddleLH) {
					PaddleLY = 600-PaddleLH;
				} if((int)PaddleLY < 0) {
					PaddleLY = 0;
				}
	}
	
	SDL_Rect PaddleR;
	void UpdatePaddleR() {
	PaddleR.x = PaddleRX; PaddleR.y = PaddleRY;
	PaddleR.w = PaddleRW; PaddleR.h = PaddleRH;
	
	
				if((int)PaddleRY > 600-PaddleRH) {
					PaddleRY = 600-PaddleRH;
				} if((int)PaddleRY < 0) {
					PaddleRY = 0;
				}
	}
	
	void PaddleRAILogic(int yPos) {
	        if(PaddleRY < yPos) {
	                PaddleRY += 10;
	        } else {
	                PaddleRY -= 10;
	                }
	}


	SDL_Event Event;

	while(Quit != 1) {
		/*Event handling*/
		while(SDL_PollEvent(&Event)) {
			if(Event.type == SDL_QUIT) {
				Quit = 1;
			}
		if(Event.type == SDL_KEYDOWN) {
			if(Event.key.keysym.sym == SDLK_UP) PaddleLY -= 10;
			if(Event.key.keysym.sym == SDLK_DOWN) PaddleLY += 10;
		}
		}
		
		/*Drawing*/

		SDL_FillRect(Screen, NULL, SDL_MapRGB(Screen->format, 0, 0, 0));
		SDL_FillRect(Screen, &PaddleL, SDL_MapRGB(Screen->format, 255, 0, 0));
		SDL_FillRect(Screen, &PaddleR, SDL_MapRGB(Screen->format, 255, 0, 0));
				/* ^ Window update */
				SDL_Flip(Screen);
				
				/*Update*/
                
                UpdatePaddleL();
                UpdatePaddleR();
                PaddleRAILogic(PaddleLY);


	}

				SDL_Quit();
				return 0;
				}
