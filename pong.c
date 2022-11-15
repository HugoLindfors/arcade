#include "raylib.h"

// cc pong.c `pkg-config --libs --cflags raylib` -o pong

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");

    Vector2 ballPosition = { (float)screenWidth/2, (float)screenHeight/2 };
    Vector2 ballVelocity = { 2.0f, 1.0f };

    Vector2 racket1Position = { 80, (float)screenHeight/2 };
    Vector2 racket1Velocity = { 0.0f, 2.0f };

    Vector2 racket2Position = { 720, (float)screenHeight/2 };
    Vector2 racket2Velocity = { 0.0f, 2.0f };

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        ballPosition.x += ballVelocity.x;
        ballPosition.y += ballVelocity.y;

        if (IsKeyDown(KEY_S)) racket1Position.y += racket1Velocity.y;
        if (IsKeyDown(KEY_DOWN)) racket2Position.y += racket2Velocity.y;

        if (IsKeyDown(KEY_W)) racket1Position.y -= racket1Velocity.y;
        if (IsKeyDown(KEY_UP)) racket2Position.y -= racket2Velocity.y;

        if (ballPosition.x >= racket1Position.x - 5) 
        {
            if (ballPosition.y >= racket1Position.y)
            {
                ballVelocity.x = -(ballVelocity.x);
                ballVelocity.y = -(ballVelocity.y);   
            }
        }

        if (ballPosition.x <= racket2Position.x + 5)
        {
            if (ballPosition.y <= racket2Position.y)
            {
                ballVelocity.x = -(ballVelocity.x);
                ballVelocity.y = -(ballVelocity.y);
            }
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(BLACK);

            DrawRectangle(racket1Position.x - 5, racket1Position.y - 100, 10, 200, RED);

            DrawRectangle(racket2Position.x + 5, racket2Position.y - 100, 10, 200, WHITE);

            DrawRectangle(ballPosition.x - 10, ballPosition.y - 10, 20, 20, WHITE);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
