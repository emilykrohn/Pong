#include "raylib.h"
#include "raymath.h"
#include <cmath>

const int screenWidth = 800;
const int screenHeight = 450;

class Ball {
public:
	Vector2 position;
	Vector2 velocity;
	float angle;
	int radius;
};

Ball ball;

void InitGame();
void DrawGame();
void DrawBall(int size, Color color);
void MoveBall(int speed);
void BallCollision();

int main()
{
	InitWindow(screenWidth, screenHeight, "Pong");

	InitGame();

	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		BeginDrawing();

			DrawGame();

		EndDrawing();
	}

	CloseWindow();

	return 0;
}

void InitGame()
{
	ball.position = Vector2{ screenWidth / 2, screenHeight / 2 };
	ball.velocity = Vector2{ 0.5, 0.5 };
	ball.radius = 20;
}

void DrawGame()
{
	ClearBackground(RAYWHITE);
	DrawBall(20, LIGHTGRAY);
}

void DrawBall(int size, Color color)
{
	DrawCircle(ball.position.x, ball.position.y, size, color);
	BallCollision();
	MoveBall(500);
}

void MoveBall(int speed)
{
	ball.position.x += ball.velocity.x * speed * GetFrameTime();
	ball.position.y += ball.velocity.y * speed * GetFrameTime();
}

void BallCollision()
{
	if (ball.position.x + (ball.radius / 2) >= screenWidth ||
		ball.position.x - (ball.radius / 2) <= 0)
	{
		ball.angle = Vector2Angle(ball.velocity, Vector2{ 1, 0 });
		ball.velocity.x = -cos(ball.angle);
		ball.velocity.y = -sin(ball.angle);
	}
	else if (ball.position.y + (ball.radius / 2) >= screenHeight ||
			 ball.position.y - (ball.radius / 2) <= 0)
	{
		ball.angle = Vector2Angle(ball.velocity, Vector2{ 0, 1 });
		ball.velocity.x = cos(ball.angle);
		ball.velocity.y = -sin(ball.angle);
	}
}

