#include <stdio.h>
#include <raylib.h>
#include "config.h"

// ---------------------------------[ ~ CONFIG ~ ]---------------------------------
/*
	Config has moved to file: config.h

	Refrain from using the Makefile made by me, use CMake instead

	Hope y'all understand!
*/

char *sound = "";

void PlaySoundBell() {
	if(sounds){
        	sound = "\a";
	} else { 
		printf("No sounds enabled.\n");
        	sound = "";
	}

	printf("%s", sound);
	fflush(stdout);
}

struct Ball {
	float x, y, speedx, speedy, radius;
	Color clr;
};
struct Paddle {
	float x, y, width, height;
	Color clr;
};

int main(void) {
	
	InitWindow(window_width, window_height, "Pong - C (RayLib)");
	SetTargetFPS(window_max_fps);

	struct Ball b={ 400,250,200,-200,ball_radius,ball_color };
	struct Paddle p1={ 10,170,paddle_width,paddle_height,paddle_color };
	struct Paddle pa={ GetScreenWidth()-10-paddle_width,170,paddle_width,paddle_height,paddle_color };
	p1s = 0;
	p2s = 0;

	while(!WindowShouldClose()) {
	BeginDrawing();
	float delta = GetFrameTime();	

	if(CheckCollisionCircleRec((Vector2){b.x,b.y},b.radius,(Rectangle){p1.x,p1.y,p1.width,p1.height})){ b.speedx *= -1; PlaySoundBell(); b.speedy += 0.1;}
	if(CheckCollisionCircleRec((Vector2){b.x,b.y},b.radius,(Rectangle){pa.x,pa.y,pa.width,pa.height})){ b.speedx *= -1; PlaySoundBell(); b.speedx += 0.1; }
	
	b.x += b.speedx * delta;
	b.y += b.speedy * delta;

	if(p1.y >= GetScreenHeight()-p1.height) p1.y = GetScreenHeight()-p1.height;
	if(pa.y >= GetScreenHeight()-pa.height) pa.y = GetScreenHeight()-pa.height;
	if(p1.y <= 1) p1.y = 1;
	if(pa.y <= 1) pa.y = 1;

	
	if(IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) p1.y += paddles_speed * delta;
	if(IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) p1.y -= paddles_speed * delta;

	if(b.y > pa.y) pa.y += ((paddles_speed - 30) * delta);
	if(b.y < pa.y) pa.y -= ((paddles_speed - 30) * delta);
	// Borked. DO NOT make this mistake smh.
	//if(b.y > pa.y) pa.y += paddles_speed;
	//else { pa.y -= paddles_speed-60 * delta; }
	
	ClearBackground(BLACK);

	DrawRectangle(p1.x,p1.y,p1.width,p1.height,p1.clr);
	DrawRectangle(pa.x,pa.y,pa.width,pa.height,pa.clr);
	DrawCircle(b.x, b.y, b.radius, b.clr);
	if(line_visible) DrawLine(GetScreenWidth()/2, 0, GetScreenWidth()/2, GetScreenHeight(), line_color);
	DrawText(TextFormat("Plr1: %d\nPlr2: %d", p1s, p2s), 10, GetScreenHeight()-30, GetScreenHeight()/50, text_color); // txt font is 1/10th of screen's height.
	
	if(b.y - b.radius <= 1 || b.y >= GetScreenHeight()-b.radius) b.speedy *= -1;
	//printf("%f\n", b.y);
	
	if(b.x <= 10 + paddle_width/2) { b.speedx *= -1;
		b.x = GetScreenWidth()/2-b.radius; b.y = GetScreenHeight()/2-b.radius;
		p2s += scr; 
		b.speedx = 200; b.speedy = -200; }
	
	if(b.x >= GetScreenWidth()-10-paddle_width)  { b.speedx *= -1;
		b.x = GetScreenWidth()/2-b.radius; b.y = GetScreenHeight()/2-b.radius;
		p1s += scr;
		b.speedx = 200; b.speedy = -200; }
	
	EndDrawing();	
	}

PlaySoundBell();
CloseWindow();
return 0;
}
