#ifndef CONFIG_H
#define CONFIG_H

	const int WinX = 500; const int WinY = 300;
        
	/* Player */
		int PaddleLX = 5;	/* Base X position */
		int PaddleLY = WinY/2;	/* Base Y position */
        	int PaddleLW = 10;	/* Base width */
		int PaddleLH = 40;	/* Base height */

	/* Opponent */
        	int PaddleRX = WinX-15;	/* Base X position */
		int PaddleRY = WinY/2;	/* Base Y position */
        	int PaddleRW = 10;	/* Width */
		int PaddleRH = 40;	/* Height */

	/* Ball */
        	int BallX = WinX/2;	/* Base Y position */
		int BallY = WinY/2;	/* Base X position */
        	int BallW = 20;		/* Width */
		int BallH = 20; 	/* Height */
		int BallXS = 7; 	/* X Speed */
		int BallYS = 7; 	/* Y Speed */
	
	/* Game */
	int Quit = 0;			/* Signal */
        int Score = 0;			/* Base score */

        /* Rects */
	SDL_Rect PaddleL;		/* Player paddle */
	SDL_Rect PaddleR;		/* Opponent paddle */
	SDL_Rect Ball;			/* The ball */

	/* SDL */
        SDL_Event Event;		/* SDL Event */

#endif
