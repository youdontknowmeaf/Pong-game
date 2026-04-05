import com.raylib.Raylib;

public class Ball {
    public int Width;
    public int Height;
    public int xPos;
    public int yPos;
    public int speedX;
    public int speedY;
    public float Radius;
    public Raylib.Vector2 Center = new Raylib.Vector2().x(xPos).y(yPos);

    void Update() {
        if(yPos >= Settings.ScreenHeight-Radius || yPos <= Radius) {
            speedY *= -1;
        }
        if(xPos <= 2+Radius || xPos >= Settings.ScreenWidth-2-Radius) {
            xPos = Settings.ScreenWidth/2;
            yPos = Settings.ScreenHeight/2;
        }
        xPos += speedX;
        yPos += speedY;

        Center.x(xPos).y(yPos);
    }

    public Ball() {
        speedY = 8;
        Radius = 10;
        speedX = 8;
        yPos = Settings.ScreenHeight/2;
        xPos = Settings.ScreenWidth/2;
        Height = 60;
        Width = 20;
    }
}