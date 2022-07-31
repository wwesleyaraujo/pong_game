#include "raylib.h"

struct Ball {

	float x,y;
	float radius;
	float speedX, speedY;
};

struct Paddle {
	float x,y;
        int width, height;
};

int main(void)
{
    InitWindow(800, 450, "raylib-pong");
    SetWindowState(FLAG_VSYNC_HINT);  
    
    Ball ball;
    ball.x = GetScreenWidth()/ 2.0f;
    ball.y = GetScreenHeight() / 2.0f;
    ball.radius = 5.0;
    ball.speedX = 300.0;
    ball.speedY= 300.0;

    Paddle p1, p2;

    p1.x = GetScreenWidth()*0.015;
    p1.y = GetScreenHeight()/2- GetScreenWidth()*0.15/2;
    p1.height = GetScreenHeight()*0.015;
    p1.width  = GetScreenWidth()*0.15;

    p2.x = 800-GetScreenWidth()*0.015;
    p2.y = GetScreenHeight()/2- GetScreenWidth()*0.15/2;
    p2.height = GetScreenHeight()*0.015;
    p2.width  = GetScreenWidth()*0.15;

    while (!WindowShouldClose())
    {

	ball.x += ball.speedX * GetFrameTime();
        ball.y += ball.speedY * GetFrameTime();	
         
	if (ball.y > GetScreenHeight()){
		ball.speedY = -ball.speedY;
	}else if(ball.y < 0){
		ball.speedY = -ball.speedY;
	}

	if (ball.x > GetScreenWidth()){
		ball.speedX = -ball.speedX;
	}else if(ball.x < 0){
		ball.speedX = -ball.speedX;
	}
	

	BeginDrawing();
        	ClearBackground(BLACK);
	        
  		DrawCircle( (int) ball.x, (int) ball.y,(int) ball.radius, WHITE);
		DrawRectangle( (int) p1.x,(int) p1.y,(int) p1.height,(int) p1.width, WHITE);
		DrawRectangle((int) p2.x,(int) p2.y,(int) p2.height,(int) p2.width, RED);

	   	DrawFPS(10,10);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
