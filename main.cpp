#include "raylib.h"

int main(void)
{
    InitWindow(800, 450, "raylib-pong");
    SetWindowState(FLAG_VSYNC_HINT);  
    while (!WindowShouldClose())
    {
	BeginDrawing();
        	ClearBackground(BLACK);
	        
  		DrawCircle(GetScreenWidth()/2,GetScreenHeight()/2,5, WHITE);
		DrawRectangle(GetScreenWidth()*0.015,GetScreenHeight()/2- GetScreenWidth()*0.15/2,GetScreenHeight()*0.015,GetScreenWidth()*0.15, WHITE);
		DrawRectangle(800-GetScreenWidth()*0.015,GetScreenHeight()/2- GetScreenWidth()*0.15/2,GetScreenHeight()*0.015,GetScreenWidth()*0.15, RED);

	   	DrawFPS(10,10);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
