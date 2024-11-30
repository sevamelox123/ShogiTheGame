#include <unistd.h>
#include <string.h>
#include <dlfcn.h>

#include "raylib.h"

#define LOAD_FUNC_FROM_DLL(type, name, handle) type name = reinterpret_cast<type>(dlsym(handle, #name))

typedef decltype(InitWindow)* RL_InitWindow_t;
typedef decltype(CloseWindow)* RL_CloseWindow_t;
typedef decltype(SetTargetFPS)* RL_SetTargetFPS_t;
typedef decltype(WindowShouldClose)* RL_WindowShouldClose_t;
typedef decltype(BeginDrawing)* RL_BeginDrawing_t;
typedef decltype(EndDrawing)* RL_EndDrawing_t;
typedef decltype(ClearBackground)* RL_ClearBackground_t;
typedef decltype(GetMousePosition)* RL_GetMousePosition_t;
typedef decltype(CheckCollisionPointRec)* RL_CheckCollisionPointRec_t;
typedef decltype(DrawRectangleRec)* RL_DrawRectangleRec_t;
typedef decltype(GetScreenHeight)* RL_GetScreenHeight_t;
typedef decltype(GetScreenWidth)* RL_GetScreenWidth_t;
typedef decltype(GetTime)* RL_GetTime_t;
typedef decltype(GetFPS)* RL_GetFPS_t;
typedef decltype(GetFrameTime)* RL_GetFrameTime_t;
typedef decltype(DrawText)* RL_DrawText_t;
typedef decltype(IsMouseButtonDown)* RL_IsMouseButtonDown_t;