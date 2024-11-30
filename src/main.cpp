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

int main(int argc,char *argv[])
{
  char* program_location_folder = new char[strlen(argv[0])];
  strcpy(program_location_folder, argv[0]);
  for (int i = strlen(program_location_folder) - 1;i >= 0;i--) {
    if (program_location_folder[i] == '/') {
      program_location_folder[i] = '\0';
      break;
    }
  }

  void* ray_handle = dlopen(strcat(program_location_folder, "/libraylib.so"), RTLD_LAZY);

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

  if (ray_handle == nullptr) {
    printf("No raylib shared library found!\n");

    return 1;
  }

  InitWindow(screenWidth, screenHeight, "ShogiGame");
  
  SetTargetFPS(60);

  Vector2 mousePoint = {0.0f, 0.0f};

  while (!WindowShouldClose()) {
    Rectangle btnBounds = { GetScreenWidth()/2.0f - GetScreenWidth()/4.0f - GetScreenWidth() / 4.0f * static_cast<float>(sin(GetTime() * -5)), GetScreenHeight()/2.0f - GetScreenHeight()/4.0f - GetScreenHeight()/4.0f *  static_cast<float>(cos(GetTime() * 5)), GetScreenWidth()/2.0f, GetScreenHeight()/2.0f};

    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawRectangleRec(btnBounds, ORANGE);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}