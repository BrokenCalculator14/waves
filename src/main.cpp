#include <raylib.h>

int main()
{
    InitWindow(800, 600, "Waves");
    SetTargetFPS(60);

    int sizeInc = 0;
    const int frequency = 50;
    const int speed = 2;
    const int thickness = 3;
    Color mainColor = (Color){255, 0, 0, 255};
    Color bgColor = (Color){0, 0, 0, 255};
    float hue = 0;
    const float hueSpeed = 0.5f;

    while (!WindowShouldClose())
    {
        sizeInc += speed;
        sizeInc %= frequency;

        hue += hueSpeed;
        if (hue >= 360)
        {
            hue = 0;
        }

        mainColor = ColorFromHSV(hue, 1.0f, 1.0f);
        bgColor = ColorFromHSV(hue, 1.0f, 0.15f);

        BeginDrawing();

        ClearBackground(bgColor);
        for (int i = 0; i < frequency * 10; i += frequency)
        {
            for (int j = 0; j < thickness; j++)
            {
                DrawCircleLines(400, 300, (i + sizeInc) + j, mainColor);
            }
        }

        EndDrawing();
    }
    CloseWindow();

    return 0;
}