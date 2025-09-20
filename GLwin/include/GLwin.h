#pragma once
#include <windows.h>
#include <string>
#include "GLwinDefs.h"

#define WIN32_LEAN_AND_MEAN  // Exclude rarely-used stuff from Windows headers

#ifdef __cplusplus
extern "C" {
#endif

    // My Window library functions for messages at startup
    void GLwinHello(void);

    // Opaque window structure
    typedef struct GLWIN_window GLWIN_window;

    // Window creation & destruction
    GLWIN_window* GLwin_CreateWindow(int width, int height, const wchar_t* title);
    void GLwin_DestroyWindow(GLWIN_window* window);

    // Window/context management
    void GLwinMakeContextCurrent(GLWIN_window* window);
    void GLwinSwapBuffers(GLWIN_window* window);
    void GLwinPollEvents(void);
    int  GLwinWindowShouldClose(GLWIN_window* window);

    // Framebuffer size and window state
    void GLwinGetFramebufferSize(GLWIN_window* window, int* width, int* height);
    int  GLwinGetWidth(GLWIN_window* window);
    int  GLwinGetHeight(GLWIN_window* window);

    // Window icon and maximize
    void GLwinSetWindowIcon(GLWIN_window* window, const wchar_t* iconPath);
    // bool GLwinSetScreenMaximized(GLWIN_window* window, bool maximize);

     // Window hints (stub, for API compatibility)
    void GLwinWindowHint(int hint, int value);

    // Keyboard input API
    int GLwinGetKey(GLWIN_window* window, int keycode);


    // Mouse input API
    int GLwinGetMouseButton(GLWIN_window* window, int button);
    void GLwinGetCursorPos(GLWIN_window* window, double* xpos, double* ypos);

    // Optional: callback for resize
    typedef void(*GLwinResizeCallback)(int width, int height);

    // Terminate and cleanup library (optional, for symmetry with GLFW)
    void GLwinTerminate(void);

#ifdef __cplusplus
}
#endif
