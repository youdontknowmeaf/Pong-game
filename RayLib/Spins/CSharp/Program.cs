using System;
using Raylib_cs;

namespace PongGame;

internal static class Settings {
	public static int ScreenWidth = 800;
	public static int ScreenHeight = 600;
	public static int MaxFPS = 30;	
}

internal class Paddle {
	public Color clr = Color.Red;
	public int height = 80; public int width = 20;
	public int xpos = 0; public int ypos = 0;
	public int score = 0;	public int speed = 15;
	
	public void Init() {
		xpos = 0 + 10;
		ypos = Settings.ScreenHeight/2-height/2;
	}

	public void Draw() {
		Raylib.DrawRectangle(xpos, ypos, width, height, clr);
	}

	public void Update() {
		if(Raylib.IsKeyDown(KeyboardKey.Up) || Raylib.IsKeyDown(KeyboardKey.W)) {
			ypos -= speed;
		}
	        if(Raylib.IsKeyDown(KeyboardKey.Down) || Raylib.IsKeyDown(KeyboardKey.S)) {
			ypos += speed;
		}
	}

	public void PreventLeaving() {
		if(ypos <= 0) ypos = 0;
		if(ypos >= Settings.ScreenHeight-height) ypos = Settings.ScreenHeight-height;
	}
}
	
internal class PaddleAI : Paddle {
	public void Init() {
		xpos = Settings.ScreenWidth-10-width;
                ypos = Settings.ScreenHeight/2-height/2;
	}
}

internal class Ball {
	public int xpos = 0; public int ypos = 0; public int speedx = 15; public int speedy = 15;
	public int radius; public Color clr = Color.Red;
	
	public void Init() {
		radius = Settings.ScreenHeight/100;
		xpos = Settings.ScreenWidth/2-radius/2;
		ypos = Settings.ScreenHeight/2-radius/2;
	}
	
	public void Draw() {
		Raylib.DrawCircle(xpos, ypos, radius, clr);
	}

	public void Update() {
		xpos += speedx;
		ypos += speedy;
	}
	
	public void PreventLeaving() {
		if(ypos <= 0 || ypos >= Settings.ScreenHeight-radius) speedy *= -1;
	}

	public void Reset() {
		xpos = Settings.ScreenWidth/2-radius/2;
                ypos = Settings.ScreenHeight/2-radius/2;
	}

}

internal static class Program {
	public static void Main() {
		Paddle Paddlel = new Paddle();
		PaddleAI Paddler = new PaddleAI();
		Ball FooBall = new Ball(); // Get it? Foo-Ball?? Eh? Eh? Football? FOO-BALL? Hehehe

		Raylib.InitWindow(Settings.ScreenWidth, Settings.ScreenHeight, "Pong C# - Linux x86_64");
		Raylib.SetTargetFPS(Settings.MaxFPS);

		Paddlel.Init(); Paddler.Init(); FooBall.Init();

		while(!Raylib.WindowShouldClose()) {

			Raylib.BeginDrawing();
			Raylib.ClearBackground(Color.Black);
			
			Paddlel.Update(); FooBall.Update();
			Paddlel.Draw(); Paddler.Draw(); FooBall.Draw();
			Paddlel.PreventLeaving(); Paddler.PreventLeaving(); FooBall.PreventLeaving();

			Raylib.DrawLine(Raylib.GetScreenWidth()/2, 0, Raylib.GetScreenWidth()/2, Raylib.GetScreenHeight(), Color.Red);
			Raylib.DrawText($"Score:\nLeft - {Paddlel.score}\nRight - {Paddler.score}", 20, Raylib.GetScreenHeight()-70, 20, Color.White);

			if(Raylib.CheckCollisionCircleRec(new System.Numerics.Vector2(FooBall.xpos, FooBall.ypos),
					FooBall.radius,
					new Rectangle(Paddler.xpos, Paddler.ypos,
					Paddler.width, Paddler.height))){
				FooBall.speedx *= -1; Console.Beep();   }
			if(Raylib.CheckCollisionCircleRec(new System.Numerics.Vector2(FooBall.xpos, FooBall.ypos),
                                        FooBall.radius,
                                        new Rectangle(Paddlel.xpos, Paddlel.ypos,
                                        Paddlel.width, Paddlel.height))){
                                FooBall.speedx *= -1; Console.Beep();   }


			if(FooBall.xpos <= 0 + 10) {
				FooBall.Reset(); Paddler.score++;
			}
			if(FooBall.xpos >= Raylib.GetScreenWidth()-10) {
				FooBall.Reset(); Paddlel.score++;
			}
			if(Paddler.ypos < FooBall.ypos) { Paddler.ypos += Paddler.speed;
			} else { Paddler.ypos -= Paddler.speed; }

			Raylib.EndDrawing();
		}

		Raylib.CloseWindow();

	}
}
