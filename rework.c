/*
<rant>
        I want to fully rework the thing in C so it runs a little pittle better.
        This is part of the rework. I will reuse the code from lightweigh version.
        Unstable, untested, likely doesn't work. I will have to rewrite make file,
        fuck this shit.
		FUCK RUST I REWRITE MY CODE IN FUCKIDY C LIKE A REAL PROGRAMMER.
		Do I want to include time header? I dunno, maybe. I don't know if I really
		care about random ball movements? I feel like it's only unnecesary extra
		math for like nothing. I want to make this as compatible as RayLib is so
		giving extra math to process for a shitty commodore processor is a bad idea.
		Or I am just lazy, both are good. For refference to new kidz:
		Commodore is a old ass computer. I don't even know if raylib supports this but
		anything supporting OpenGL should work so 90s stuff like i486 intel should
		be compatible too. In theory. I mean not many distros even support this architecture
		so I dunno what kind of system you would even use on it... NetBSD maybe? PLD (Polish
		Linux Distribution)? MAYBE some Mandrake? I dunno, I don't judge. Or I am just thinking
		outside of the box now and you can just use something like Windows 98... both is
		good. End of rant.
</rant>
*/

#include <stdio.h>
#include <raylib.h>


// ---------------------------------[ ~ CONFIG ~ ]---------------------------------
/*
                Colors table | Tabela kolorów: | [place for other languages]
                RED          | Czerwony        |
                BLACK        | Czarny          |
                WHITE        | Biały           |
                RAYWHITE     | Ciemny biały    |
                BLUE         | Niebieski       |
                GREEN        | Zielony         |
*/
// ---------------------------------[ Window cnf. ]---------------------------------

        int window_width = 500;
        int window_height = 500;
        int window_max_fps = 30;
	Color text_color = WHITE; 

// ---------------------------------[ Paddles cnf ]---------------------------------

        float paddle_width = 25;
        float paddle_height = 80;
        Color paddle_color = RED;
	int paddles_speed = 200;
	int p1s = 0;
	int p2s = 0;

// ---------------------------------[ Ball conf. ]---------------------------------

        float ball_radius = 20;
        Color ball_color = RED;

// ---------------------------------[ END CONFIG ]---------------------------------

struct Ball {
	float x, y, speedx, speedy, radius;
	Color clr;
};
struct Paddle {
	float x, y, width, height;
	Color clr;
};

int main(void) {
	
	InitWindow(window_width, window_height, "Lightweigh Pong");
	SetTargetFPS(window_max_fps);

	struct Ball b={ 400,250,200,-200,ball_radius,ball_color };
	struct Paddle p1={ 10,170,paddle_width,paddle_height,paddle_color };
	struct Paddle pa={ GetScreenWidth()-10-paddle_width,170,paddle_width,paddle_height,paddle_color };
	p1s = 0;
	p2s = 0;

	while(!WindowShouldClose()) {
	BeginDrawing();
	float delta = GetFrameTime();	

	if(CheckCollisionCircleRec((Vector2){b.x,b.y},b.radius,(Rectangle){p1.x,p1.y,p1.width,p1.height})) b.speedx *= -1;
	if(CheckCollisionCircleRec((Vector2){b.x,b.y},b.radius,(Rectangle){pa.x,pa.y,pa.width,pa.height})) b.speedx *= -1;
	
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
	DrawLine(GetScreenWidth()/2, 0, GetScreenWidth()/2, GetScreenHeight(), RED);
	DrawText(TextFormat("Plr1: %d\nPlr2: %d", p1s, p2s), 10, GetScreenHeight()-30, GetScreenHeight()/50, text_color); // txt font is 1/10th of screen's height.
	
	if(b.y - b.radius <= 1 || b.y >= GetScreenHeight()-b.radius) b.speedy *= -1;
	printf("%f\n", b.y);
	
	if(b.x <= 10 + paddle_width/2) { b.speedx *= -1;
		b.x = GetScreenWidth()/2-b.radius; b.y = GetScreenHeight()/2-b.radius;
		p2s++; }
	
	if(b.x >= GetScreenWidth()-10-paddle_width)  { b.speedx *= -1;
		b.x = GetScreenWidth()/2-b.radius; b.y = GetScreenHeight()/2-b.radius;
		p1s++; }
	
	EndDrawing();	
	}

CloseWindow();
return 0;
}
