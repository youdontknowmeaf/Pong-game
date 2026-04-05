// package com.JavaPong;
import static com.raylib.Raylib.*;
import static com.raylib.Colors.*;


public class Main {
    public static void main(String[] args) {
        InitWindow(Settings.ScreenWidth, Settings.ScreenHeight, Settings.NAME);
        SetTargetFPS(Settings.MaxFPS);

        Ball ball = new Ball();
        PaddlePlayer player = new PaddlePlayer();
        PaddleAI bot = new PaddleAI();

        while(!WindowShouldClose()) {
            if (ball.xPos <= ball.Radius) {
                bot.Score++;
            }
            if (ball.xPos >= Settings.ScreenWidth - ball.Radius) {
                player.Score++;
            }
            ball.Update();
            player.Update();
            bot.Update(ball.yPos);

            if(CheckCollisionCircleRec(ball.Center, ball.Radius, player.Paddle)) ball.speedX *= -1;
            if(CheckCollisionCircleRec(ball.Center, ball.Radius, bot.Paddle)) ball.speedX *= -1;

            /*-------------------------*/
            BeginDrawing();
            ClearBackground(BLACK);
            //drawing
            /*-------------------------*/
            DrawCircle(ball.xPos, ball.yPos, ball.Radius, Settings.mainColor);
            player.Draw();
            bot.Draw();

            DrawText(Settings.NAME, 30, 30, 20, Settings.textColor);
            DrawText("Score 1: " + player.Score, 10, GetScreenHeight()-40, 10, Settings.textColor);
            DrawText("Score 2: " + bot.Score, 10, GetScreenHeight()-20, 10, Settings.textColor);

            /*-------------------------*/
            EndDrawing();
        }

        CloseWindow();
    }
}