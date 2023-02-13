#include "raylib.h"
#include <stdlib.h>
#include <string.h>
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

void OptionMenu(float* MusicVol, int* ScreenSelector) {
    char MusicText[30];
    ClearBackground(RAYWHITE);

    GuiSetStyle(DEFAULT, TEXT_SIZE, 25);
    //GuiSlider((Rectangle){GetScreenWidth() / 10, GetScreenHeight() / 20, 200, 50}, "Muisc", "", *MusicVol, 0, 100);
    int MusicInt = (int)*MusicVol;
    sprintf(MusicText, "%d", MusicInt);
    strcat(MusicText, "%");
    *MusicVol = GuiSliderBar((Rectangle){GetScreenWidth() / 5, GetScreenHeight() / 20, 200, 50}, "Muisc", MusicText, *MusicVol, 0, 100);
    if (GuiButton((Rectangle){GetScreenWidth() / 2 - 35, (GetScreenHeight() / 10) * 9, 150, 40}, "Main Menu")) {
        *ScreenSelector = 0;
    }
}

void MainMenu(bool* GameRunning, int* ScreenSelector) {
    ClearBackground(RAYWHITE);

    DrawText("GAME TITLE", GetScreenWidth() / 2 - (MeasureText("Game Title", 30) / 2), GetScreenHeight() / 2 - 20, 30, BLACK);
    GuiSetStyle(DEFAULT, TEXT_SIZE, 20);
    if (GuiButton((Rectangle){(GetScreenWidth() / 2) - 12.5, (GetScreenHeight() / 2) + 20, 75, 40}, "Play")) {
        *ScreenSelector = 1;
    }
    if (GuiButton((Rectangle){(GetScreenWidth() / 2) - 12.5, (GetScreenHeight() / 2) + 80, 75, 40}, "Options")) {
        *ScreenSelector = 2;
    }
    if (GuiButton((Rectangle){(GetScreenWidth() / 2) - 12.5, (GetScreenHeight() / 2) + 140, 75, 40}, "Exit")) {
        *GameRunning = false;
    }
}

int main(void) {
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(1000, 800, "Game");

    SetExitKey(KEY_NULL);

    int ScreenSelector = 0;

    float MusicVolume;

    bool GameRunning = true;
    while (GameRunning) {
        int SCREEN_WIDTH = GetScreenWidth();
        int SCREEN_HEIGHT = GetScreenHeight();
        BeginDrawing();

        if (ScreenSelector == 0) { MainMenu(&GameRunning, &ScreenSelector); } 
        if (ScreenSelector == 2) { OptionMenu(&MusicVolume, &ScreenSelector); }

        EndDrawing();
        if (WindowShouldClose()) GameRunning = false;
    }

    CloseWindow();

    return 0;
}
