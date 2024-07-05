#include "raylib.h"

const int screenWidth = 800;
const int screenHeight = 450;

class Ball {
public:
	Vector2 position;
	Vector2 velocity;
};

Ball ball;

void InitGame();
void DrawGame();
void DrawBall(int size, Color color);
void MoveBall(int speed);

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
	ball.velocity = Vector2{ 1, 1 };
}

void DrawGame()
{
	ClearBackground(RAYWHITE);
	DrawBall(20, LIGHTGRAY);
}

void DrawBall(int size, Color color)
{
	DrawCircle(ball.position.x, ball.position.y, size, color);
	MoveBall(2);
}

void MoveBall(int speed)
{
	ball.position.x += ball.velocity.x * speed;
	ball.position.y += ball.velocity.y * speed;
}

