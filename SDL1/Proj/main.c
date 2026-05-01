/*
TODO:
- Make the Left Paddle move. [x]
- Make the Right Paddle and make it move. [x]
- Make the ball and make it move. [x]
- Make the ball bounce off the walls and attach it's Y to Right Paddle's update function. [x]
- Check for collisions Ball-PaddleR. [x]
- Check for collisions Ball-PaddleL. [x]
- Add scoring when paddle collides with ball or when ball falls off the screen.
- Make the ball reset position when it falls off the screen. [x]
- Make these window properties changeable from config on the very top of the file:
Window X, Window Y, Window's Background Colour, Window's Title.
- Make the loop independent off FPS using Delta Time.
- Make a proper Makefile. [x]
- Make a port to MS-DOS.
- Make the code compile with 1989 compiler [x]
*/
#include <stdio.h>
#include <SDL/SDL.h>

	int PaddleLX = 5; int PaddleLY = 300;
        int PaddleLW = 10; int PaddleLH = 40;
        int PaddleRX = 800-15; int PaddleRY = 300;
        int PaddleRW = 10; int PaddleRH = 40;
        int BallX = 400; int BallY = 300;
        int BallW = 20; int BallH = 20; int BallXS = 7; int BallYS = 7;
        int Quit = 0;
        int Score = 0;
        SDL_Rect PaddleL; SDL_Rect PaddleR; SDL_Rect Ball;
	SDL_Event Event;


int CheckCollisionRect(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2) {
	if (x1 + w1 <= x2 || x1 >= x2 + w2 || y1 + h1 <= y2 || y1 >= y2 + h2) {
        		return 0; }
		printf("Collides. \n");
			return 1;
	}

void UpdatePaddleL(SDL_Rect *PdlL) {
        PdlL->x = PaddleLX; PdlL->y = PaddleLY;
        PdlL->w = PaddleLW; PdlL->h = PaddleLH;
                                if((int)PaddleLY > 600-PaddleLH) {
                                        PaddleLY = 600-PaddleLH;
                                } if((int)PaddleLY < 0) {
                                        PaddleLY = 0;
                                }
        }

void UpdatePaddleR(SDL_Rect *PdlR) {
        PdlR->x = PaddleRX; PdlR->y = PaddleRY;
        PdlR->w = PaddleRW; PdlR->h = PaddleRH;
                                if((int)PaddleRY > 600-PaddleRH) {
                                        PaddleRY = 600-PaddleRH;
                                } if((int)PaddleRY < 0) {
                                        PaddleRY = 0;
                                }
        }

void UpdateBall(SDL_Rect *Ball) {
            BallX += BallXS; BallY += BallYS;
            Ball->x = BallX; Ball->y = BallY;
            Ball->w = BallW; Ball->h = BallH;
                if((int)BallY > 600-BallH) {
                    BallYS *= -1; } if((int)BallY < 0) {
                    BallYS *= -1; }
                if(CheckCollisionRect(BallX, BallY, BallW, BallH, PaddleRX, PaddleRY, PaddleRW, PaddleRH) != 0) {
                        BallXS *= -1;
                } if(CheckCollisionRect(BallX, BallY, BallW, BallH, PaddleLX, PaddleLY, PaddleLW, PaddleLH) != 0) {
                        BallXS *= -1;
                }
                if(BallX <= 0) { BallX = 400; BallY = 300; }
                if(BallX >= 800-BallW) { BallY= 300; BallX = 400; Score++; printf("Score: %d\n", Score); }
           }

void PaddleRAILogic(int yPos) {
                if(PaddleRY < yPos) {
                        PaddleRY += 7;
                } else {
                        PaddleRY -= 7;
                        }
        }


int main(int argc, char *argv[]) {

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
	
	while(Quit != 1) {
		/*Event handling*/
		while(SDL_PollEvent(&Event)) {
			if(Event.type == SDL_QUIT) {
				Quit = 1;
			}
		if(Event.type == SDL_KEYDOWN) {
			if(Event.key.keysym.sym == SDLK_UP) PaddleLY -= 20;
			if(Event.key.keysym.sym == SDLK_DOWN) PaddleLY += 20;
		}
		}
		
		/*Drawing*/

		SDL_FillRect(Screen, NULL, SDL_MapRGB(Screen->format, 0, 0, 0));
		SDL_FillRect(Screen, &PaddleL, SDL_MapRGB(Screen->format, 255, 0, 0));
		SDL_FillRect(Screen, &PaddleR, SDL_MapRGB(Screen->format, 255, 0, 0));
		SDL_FillRect(Screen, &Ball, SDL_MapRGB(Screen->format, 255, 0, 0));
				/* ^ Window update */
		SDL_Flip(Screen);
                SDL_Delay(33);				
				/*Update*/
                
                UpdatePaddleL(&PaddleL);
                UpdatePaddleR(&PaddleR);
                PaddleRAILogic(BallY);
                UpdateBall(&Ball);

	}

				SDL_Quit();
				return 0;
				}
