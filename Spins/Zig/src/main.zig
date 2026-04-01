const rl = @import("raylib");

const screenWidth = 800;
const screenHeight = 600;
const maxFPS = 30;
var defColor: rl.Color = .red;

pub const Paddle = struct {
    xpos: i32,
    ypos: i32,
    width: i32,
    height: i32,
    speed: i32,

    pub fn init(xpos: i32, ypos: i32, width: i32, height: i32, speed: i32) Paddle {
        return Paddle {
            .xpos = xpos,
            .ypos = ypos,
            .width = width,
            .height = height,
            .speed = speed,
        };
    }

    pub fn move(self: *Paddle) void {
        if(self.ypos <= 0) { self.ypos = 0; }
        if(self.ypos >= screenHeight - self.height) { self.ypos = screenHeight - self.height; }
        if(rl.isKeyDown(.up)) {
            self.ypos -= self.speed;
        }
        if(rl.isKeyDown(.down)) {
            self.ypos += self.speed;
        }
    }
    pub fn aiMove(self: *Paddle, bYpos: i32) void {
        if(self.ypos <= 0) { self.ypos = 0; }
        if(self.ypos >= screenHeight - self.height) { self.ypos = screenHeight - self.height; }
        if(self.ypos <= bYpos) {
            self.ypos += self.speed;
        } else {
            self.ypos -= self.speed;
        }
    }


};

pub const Ball = struct {
    xpos: i32,
    ypos: i32,
    radius: f32,
    speedx: i32,
    speedy: i32,

    pub fn init(xpos: i32, ypos: i32, radius: f32, speedx: i32, speedy: i32) Ball {
        return Ball {
            .xpos = xpos,
            .ypos = ypos,
            .radius = radius,
            .xpeedx = speedx,
            .speedy = speedy,
        };
    }

    pub fn move(self: *Ball) void {
        self.xpos += self.speedx;
        self.ypos += self.speedy;
        if((self.ypos <= 0) or (self.ypos >= screenHeight-5)) {
            self.speedy *= -1; }
        if((self.xpos <= 5) or (self.xpos >= screenWidth)){
            //self.speedx *= -1;
            self.xpos = @divTrunc(screenWidth, 2);
        }
    }
};

var player: Paddle = Paddle {
    .xpos = 5,
    .ypos = screenHeight/2,
    .speed = 10,
    .width = 10,
    .height = 50,
};
var enemy: Paddle = Paddle {
    .xpos = screenWidth-15,
    .ypos = screenHeight/2,
    .speed = 8,
    .width = 10,
    .height = 50,
};
var ball: Ball = Ball {
    .xpos = screenWidth/2,
    .ypos = screenHeight/2,
    .speedy = 8,
    .speedx = 8,
    .radius = 10.0,
};

pub fn main() !void {
    rl.initWindow(screenWidth, screenHeight, "ZigPong");
    defer rl.closeWindow();
    rl.setTargetFPS(maxFPS);

    while(!rl.windowShouldClose()) {
        player.move();
        enemy.aiMove(ball.ypos);

        if(rl.checkCollisionCircleRec(
        rl.Vector2{ .x = @floatFromInt(ball.xpos), .y = @floatFromInt(ball.ypos) },
        ball.radius,
        rl.Rectangle{
        .x = @floatFromInt(player.xpos),
        .y = @floatFromInt(player.ypos),
        .width = @floatFromInt(player.width),
        .height = @floatFromInt(player.height)})) {
            ball.speedx *= -1;
        }
        if(rl.checkCollisionCircleRec(
        rl.Vector2{ .x = @floatFromInt(ball.xpos), .y = @floatFromInt(ball.ypos) },
        ball.radius,
        rl.Rectangle{
        .x = @floatFromInt(enemy.xpos),
        .y = @floatFromInt(enemy.ypos),
        .width = @floatFromInt(enemy.width),
        .height = @floatFromInt(enemy.height)})) {
            ball.speedx *= -1;
        }

        ball.move();


        rl.beginDrawing();
        defer rl.endDrawing();

        rl.clearBackground(.black);
        
        rl.drawRectangle(player.xpos, player.ypos, player.width, player.height, defColor);
        rl.drawRectangle(enemy.xpos, enemy.ypos, enemy.width, enemy.height, defColor);
        rl.drawCircle(ball.xpos, ball.ypos, ball.radius, defColor);

        rl.drawText("Got brain damage with this lang...", 10, 10, 20, .red);
    }
}
