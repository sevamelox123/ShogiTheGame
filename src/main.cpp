// #include <ncurses.h> 
#include <dlfcn.h>
#include <cstdio>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include "desk.h"
#include "shoga.h"
#include "raylib.h"

const int screenWidth = 800;
const int screenHeight = 450;

int main(int argc,char *argv[])
{
  void (*InitWindow)(int width, int height, const char *title);
  void (*CloseWindow)();
  void (*SetTargetFPS)(int);
  bool (*WindowShouldClose)();
  void (*BeginDrawing)();
  void (*EndDrawing)();
  void (*ClearBackground)(Color color);
  Vector2 (*GetMousePosition)();
  bool (*CheckCollisionPointRec)(Vector2 point, Rectangle rec);
  void (*DrawRectangleRec)(Rectangle, Color);
  int (*GetScreenWidth)();
  int (*GetScreenHeight)();
  double (*GetTime)();
  float (*GetFrameTime)();
  int (*GetFPS)();

  char* program_location_folder = new char[strlen(argv[0])];
  strcpy(program_location_folder, argv[0]);
  for (int i = strlen(program_location_folder) - 1;i >= 0;i--) {
    if (program_location_folder[i] == '/') {
      program_location_folder[i] = '\0';
      break;
    }
  }

  void* ray_handle = dlopen(strcat(program_location_folder, "/libraylib.so"), RTLD_LAZY);

  InitWindow = reinterpret_cast<void(*)(int, int, const char*)>(dlsym(ray_handle, "InitWindow"));
  CloseWindow = reinterpret_cast<void(*)()>(dlsym(ray_handle, "CloseWindow"));
  SetTargetFPS = reinterpret_cast<void(*)(int)>(dlsym(ray_handle, "SetTargetFPS"));
  WindowShouldClose = reinterpret_cast<bool(*)()>(dlsym(ray_handle, "WindowShouldClose"));
  BeginDrawing = reinterpret_cast<void(*)()>(dlsym(ray_handle, "BeginDrawing"));
  EndDrawing = reinterpret_cast<void(*)()>(dlsym(ray_handle, "EndDrawing"));
  ClearBackground = reinterpret_cast<void(*)(Color)>(dlsym(ray_handle, "ClearBackground"));
  GetMousePosition = reinterpret_cast<Vector2(*)()>(dlsym(ray_handle, "GetMousePosition"));
  CheckCollisionPointRec = reinterpret_cast<bool(*)(Vector2, Rectangle)>(dlsym(ray_handle, "CheckCollisionPointRec"));
  DrawRectangleRec = reinterpret_cast<void(*)(Rectangle, Color)>(dlsym(ray_handle, "DrawRectangleRec"));
  GetScreenHeight = reinterpret_cast<int(*)()>(dlsym(ray_handle, "GetScreenHeight"));
  GetScreenWidth = reinterpret_cast<int(*)()>(dlsym(ray_handle, "GetScreenWidth"));
  GetTime = reinterpret_cast<double(*)()>(dlsym(ray_handle, "GetTime"));
  GetFPS = reinterpret_cast<int(*)()>(dlsym(ray_handle, "GetFPS"));
  GetFrameTime = reinterpret_cast<float(*)()>(dlsym(ray_handle, "GetFrameTime"));

  if (ray_handle == nullptr) {
    printf("No raylib shared library found!\n");

    return 1;
  }

  InitWindow(screenWidth, screenHeight, "ShogiGame");
  
  SetTargetFPS(60);

  Vector2 mousePoint = {0.0f, 0.0f};

  while (!WindowShouldClose()) {
    Rectangle btnBounds = { GetScreenWidth()/2.0f - GetScreenWidth()/4.0f - GetScreenWidth() / 4.0f * sin(GetTime() * -5), GetScreenHeight()/2.0f - GetScreenHeight()/4.0f - GetScreenHeight()/4.0f * cos(GetTime() * 5), GetScreenWidth()/2.0f, GetScreenHeight()/2.0f};

    BeginDrawing();

    mousePoint = GetMousePosition();

    if (CheckCollisionPointRec(mousePoint, btnBounds)) {
      printf("Pokakat'\n");
    }

    ClearBackground(RAYWHITE);

    DrawRectangleRec(btnBounds, ORANGE);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}