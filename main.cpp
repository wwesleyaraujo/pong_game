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

	   	DrawFPS(10,10);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
