from pyray import *
from random import randint

# Configs - Window
window_width = 800
window_height = 600
max_fps = 30
text = True # "Python sucks" text
# Configs - Paddles
paddle_width = 10
paddle_height = 50
paddle_speed = 10
paddle_color = RED
# Configs - Ball
ball_speed = 10
ball_color = RED
ball_radius = 10

class Paddle:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.width = paddle_width
        self.height = paddle_height
        self.color = paddle_color
        self.speed = paddle_speed
    def draw(self):
        draw_rectangle(self.x, self.y, self.width, self.height, self.color)
    def move_plr(self):
        if is_key_down(KEY_UP):
            self.y -= self.speed
        if is_key_down(KEY_DOWN):
            self.y += self.speed
    def move_ai(self, bally):
        if bally >= self.y:
            self.y += self.speed
        else:
            self.y -= self.speed
    def prevent_leaving(self):
        if self.y <= 0:
            self.y = 0
        if self.y + self.height >= window_height:
            self.y = window_height - self.height

class Ball:
    def __init__(self):
        self.x = window_height//2
        self.y = window_width//2
        self.color = ball_color
        self.speedx = ball_speed
        self.speedy = ball_speed
        self.radius = ball_radius
    def draw(self):
        draw_circle(self.x, self.y, self.radius, self.color)
    def move(self):
        self.x += self.speedx
        self.y += self.speedy

    def prevent_leaving(self):
        if self.y - self.radius <= 0:
            self.y = self.radius
            self.speedy = self.speedy * -1 + randint(1, 3)
        if self.y + self.radius >= window_height:
            self.y = window_height - self.radius
            self.speedy = self.speedy * -1 + randint(1, 3)
        if self.x <= 0 or self.x >= window_width:
            self.y = window_height//2
            self.x = window_width//2



init_window(window_width, window_height, 'PyPong')
set_target_fps(max_fps)

player = Paddle(10, 0)
enemy = Paddle(window_width - 20, window_height)
ball = Ball()

while not window_should_close():
    if check_collision_circle_rec(Vector2(ball.x, ball.y), ball.radius, Rectangle(player.x, player.y, player.width, player.height)):
        ball.speedx = ball.speedx * -1
    if check_collision_circle_rec(Vector2(ball.x, ball.y), ball.radius, Rectangle(enemy.x, enemy.y, enemy.width, enemy.height)):
        ball.speedx = ball.speedx * -1
    begin_drawing()
    clear_background(BLACK)
    #--------------------------------------------------------------------
    if text == True:
        draw_text('Python sucks', 50, 50, 20, RED)

    ball.draw()
    player.draw()
    enemy.draw()
    ball.move()
    enemy.move_ai(ball.y)
    player.move_plr()
    ball.prevent_leaving()
    enemy.prevent_leaving()
    player.prevent_leaving()


    #--------------------------------------------------------------------
    end_drawing()
close_window()
