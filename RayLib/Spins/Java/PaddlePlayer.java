import static com.raylib.Raylib.*;

public class PaddlePlayer {
    public int xPos;
    public int yPos;
    public int Width;
    public int Height;
    public int Speed;
    public Rectangle Paddle = new Rectangle().x(xPos).y(yPos).width(Width).height(Height);
    int Score;
    
    void Update() {
        if(IsKeyDown(KEY_DOWN)) yPos += Speed;
        if(IsKeyDown(KEY_UP)) yPos -= Speed;

        if(yPos <= 0) yPos = 0;
        if(yPos >= Settings.ScreenHeight-Height) yPos = Settings.ScreenHeight-Height;

        Paddle.x(xPos).y(yPos).width(Width).height(Height);
    }

    void Draw() {
        DrawRectangle(xPos, yPos, Width, Height, Settings.mainColor);
    }
    
    public PaddlePlayer() {
        xPos = 5;
        yPos = Settings.ScreenHeight/2;
        Width = 20;
        Height = 50;
        Speed = 7;
        Score = 0;
    }
}