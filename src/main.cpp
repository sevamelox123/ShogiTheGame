// #include <ncurses.h>
#include <dlfcn.h>
#include <cstdio>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include "desk.h"
#include "shoga.h"
// #include "raylib.h"
#include "raylib_dlsym_types.h"

const int screenWidth = 800;
const int screenHeight = 450;

int main(int argc, char *argv[])
{
  char *program_location_folder = new char[strlen(argv[0])];
  strcpy(program_location_folder, argv[0]);
  for (int i = strlen(program_location_folder) - 1; i >= 0; i--)
  {
    if (program_location_folder[i] == '/')
    {
      program_location_folder[i] = '\0';
      break;
    }
  }

  void *ray_handle = dlopen(strcat(program_location_folder, "/libraylib.so"), RTLD_LAZY);

  LOAD_FUNC_FROM_DLL(RL_InitWindow_t, InitWindow, ray_handle);
  LOAD_FUNC_FROM_DLL(RL_CloseWindow_t, CloseWindow, ray_handle);
  LOAD_FUNC_FROM_DLL(RL_SetTargetFPS_t, SetTargetFPS, ray_handle);
  LOAD_FUNC_FROM_DLL(RL_WindowShouldClose_t, WindowShouldClose, ray_handle);
  LOAD_FUNC_FROM_DLL(RL_BeginDrawing_t, BeginDrawing, ray_handle);
  LOAD_FUNC_FROM_DLL(RL_EndDrawing_t, EndDrawing, ray_handle);
  LOAD_FUNC_FROM_DLL(RL_ClearBackground_t, ClearBackground, ray_handle);
  LOAD_FUNC_FROM_DLL(RL_GetMousePosition_t, GetMousePosition, ray_handle);
  LOAD_FUNC_FROM_DLL(RL_CheckCollisionPointRec_t, CheckCollisionPointRec, ray_handle);
  LOAD_FUNC_FROM_DLL(RL_DrawRectangleRec_t, DrawRectangleRec, ray_handle);
  LOAD_FUNC_FROM_DLL(RL_GetScreenHeight_t, GetScreenHeight, ray_handle);
  LOAD_FUNC_FROM_DLL(RL_GetScreenWidth_t, GetScreenWidth, ray_handle);
  LOAD_FUNC_FROM_DLL(RL_GetTime_t, GetTime, ray_handle);
  LOAD_FUNC_FROM_DLL(RL_GetFPS_t, GetFPS, ray_handle);
  LOAD_FUNC_FROM_DLL(RL_GetFrameTime_t, GetFrameTime, ray_handle);
  LOAD_FUNC_FROM_DLL(RL_DrawText_t, DrawText, ray_handle);
  LOAD_FUNC_FROM_DLL(RL_IsMouseButtonDown_t, IsMouseButtonDown, ray_handle);
  LOAD_FUNC_FROM_DLL(RL_LoadFont_t, LoadFont, ray_handle);
  LOAD_FUNC_FROM_DLL(RL_MeasureTextEx_t, MeasureTextEx, ray_handle);
  LOAD_FUNC_FROM_DLL(RL_GetFontDefault_t, GetFontDefault, ray_handle);
  LOAD_FUNC_FROM_DLL(RL_DrawTextPro_t, DrawTextPro, ray_handle);
  LOAD_FUNC_FROM_DLL(RL_ToggleFullscreen_t, ToggleFullscreen, ray_handle);
  LOAD_FUNC_FROM_DLL(RL_BeginMode3D_t, BeginMode3D, ray_handle);
  if (ray_handle == nullptr)
  {
    printf("No raylib shared library found!\n");

    return 1;
  }

  InitWindow(screenWidth, screenHeight, "ShogiGame");

  SetTargetFPS(60);

  Vector2 mousePoint = {0.0f, 0.0f};
  int state = 0;
  while (!WindowShouldClose())
  {
    Rectangle btnBounds = {GetScreenWidth() / 4.0f, GetScreenHeight() / 4.0f, GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};

    BeginDrawing();

    mousePoint = GetMousePosition();

    if (state == 0) {
      if (CheckCollisionPointRec(mousePoint, btnBounds))
      {
        DrawRectangleRec(btnBounds, RED);
        Font font = GetFontDefault();
        Vector2 text_size = MeasureTextEx(font, "Play Shog", 50, 5);
        DrawTextPro(font, "Play Shog", Vector2{GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f}, Vector2{text_size.x / 2.0f, text_size.y / 2.0f}, 0, 50, 5, BLACK);
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
          state = 1;
        }
      }
      else
      {
        DrawRectangleRec(btnBounds, ORANGE);
        Font font = GetFontDefault();
        Vector2 text_size = MeasureTextEx(font, "Play Shog", 50, 5);
        DrawTextPro(font, "Play Shog", Vector2{GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f}, Vector2{text_size.x / 2.0f, text_size.y / 2.0f}, 0, 50, 5, BLACK);
      }

      ClearBackground(RAYWHITE);
    }
    else if (state == 1) {
      ClearBackground(RAYWHITE);
      Rectangle _desk = {GetScreenWidth() / 4.0f, GetScreenHeight() / 4.0f, GetScreenWidth() / 2.0f, GetScreenHeight() / 1.5f};
      DrawRectangleRec(_desk,ORANGE);
    }

    EndDrawing();
  }

  CloseWindow();

  return 0;
}