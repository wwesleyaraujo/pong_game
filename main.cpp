#include "raylib.h"

struct Ball {

	float x,y;
	float radius;
	float speedX, speedY;
	void Draw() {
		x += speedX*GetFrameTime();
		y += speedY*GetFrameTime();
		DrawCircle((int)x, (int)y, 5, WHITE);
	}
};

struct Paddle {
	float x,y;
        int width, height;
	int speed;

	Rectangle GetRect(){
		return Rectangle{x -width/2, y - height/2, 10, 100};
	}

	void Draw (){
		DrawRectangleRec(GetRect(), WHITE);
	}
};

int main(void)
{
	InitWindow(800, 450, "raylib-pong");
	SetWindowState(FLAG_VSYNC_HINT);  
	
	Ball ball;
	ball.x = GetScreenWidth()/ 2.0f;
	ball.y = GetScreenHeight() / 2.0f;
	ball.radius = 5.0;
	ball.speedX = 30.0;
	ball.speedY= 30.0;
	
	Paddle p1, p2;
	
	p1.x = 50;
	p1.y = GetScreenHeight()/2;
	p1.height =100;
	p1.width  = 10;
	p1.speed = 500;

	p2.x = GetScreenWidth() -50;
	p2.y = GetScreenHeight()/2;
	p2.height =100;
	p2.width  = 10;
	p2.speed = 500;
          
	const char* winnerText = nullptr;

       	while (!WindowShouldClose())
	{
	    if (ball.y > GetScreenHeight()){
	    	ball.speedY = -ball.speedY;
	    }
	    if(ball.y < 0){
	    	ball.speedY = -ball.speedY;
	    }
	    

	    if (IsKeyDown(KEY_W)){
	    	p1.y -= p1.speed*GetFrameTime();
	    }
	    if (IsKeyDown(KEY_S)){
	    	p1.y += p1.speed*GetFrameTime();
	    }
	    if (IsKeyDown(KEY_O)){
	    	p2.y -= p2.speed*GetFrameTime();
	    }
	    if (IsKeyDown(KEY_L)){
	    	p2.y += p2.speed*GetFrameTime();
	    }

            if(CheckCollisionCircleRec(Vector2{ball.x,ball.y},ball.radius,p1.GetRect()))
	    {
		if(ball.speedX < 0) {
			ball.speedX*= -1.1f;
			ball.speedY = (ball.y - p1.y)/ (p1.height/2)*ball.speedX;
		}
	    }
    	    if(CheckCollisionCircleRec(Vector2{ball.x,ball.y},ball.radius,p2.GetRect()))
	    {
		if (ball.speedX > 0 ){
	    		ball.speedX*= -1.1f;
                        ball.speedY = (ball.y - p2.y)/ (p2.height/2)*ball.speedX;
		}
	    }	   
	    if (ball.x < 0 ) {
	    	winnerText = "Right Player Wins";
	    }

	    if (ball.x >= GetScreenWidth() ) {
	    	winnerText = "Left Player Wins";
	    }
	    if( winnerText) {
	    	DrawText(winnerText, 200, GetScreenWidth()/2 -30 , 60, YELLOW);
	    } 
	    BeginDrawing();
	    	ClearBackground(BLACK);
	            
		ball.Draw();
	    	p1.Draw();
	    	p2.Draw() ; 
	
	       	DrawFPS(10,10);
	    EndDrawing();
}

CloseWindow();

return 0;
}
