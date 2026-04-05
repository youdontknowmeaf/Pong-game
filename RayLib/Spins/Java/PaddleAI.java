import static com.raylib.Raylib.*;

public class PaddleAI {
    public int xPos;
    public int yPos;
    public int Width;
    public int Height;
    public int Speed;
    public Rectangle Paddle = new Rectangle().x(xPos).y(yPos).width(Width).height(Height);
    public int Score;

    void Update(int BallY) {
        if(yPos <= BallY) yPos += Speed;
        if(yPos >= BallY) yPos -= Speed;

        if(yPos <= 0) yPos = 0;
        if(yPos >= Settings.ScreenHeight-Height) yPos = Settings.ScreenHeight-Height;

        Paddle.x(xPos).y(yPos).width(Width).height(Height);
    }

    void Draw() {
        DrawRectangle(xPos, yPos, Width, Height, Settings.mainColor);
    }

    public PaddleAI() {
        Width = 20;
        xPos = Settings.ScreenWidth-(Width+5);
        yPos = Settings.ScreenHeight/2;
        Height = 50;
        Speed = 7;
        Score = 0;
    }
}