#pragma once
#include <windows.h>
#include <string>
#include "GLwinDefs.h"

// The new code is on GitHub : https://github.com/Spidex3d/GLwin
// It's a window library API to make it easy to open a window and set up modern opengl like GLFW _ SLD_Raylib
// Road map get the window open, have a GUI, have minimal 2d and 3d objects, have a minimal Shader, have a.obj model loader

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
     // Window hints (stub, for API compatibility)
    void GLwinWindowHint(int hint, int value);
	// Set window position
	// set window opacity
	// set window focus
	// get window refresh rate

    // Framebuffer size and window state
    void GLwinGetFramebufferSize(GLWIN_window* window, int* width, int* height);
    int  GLwinGetWidth(GLWIN_window* window);
    int  GLwinGetHeight(GLWIN_window* window);
    // Optional: callback for resize
    typedef void(*GLwinResizeCallback)(int width, int height);

    // Window icon and maximize
    void GLwinSetWindowIcon(GLWIN_window* window, const wchar_t* iconPath);

    // Keyboard input API
    int GLwinGetKey(GLWIN_window* window, int keycode);

    // Mouse input API
    int GLwinGetMouseButton(GLWIN_window* window, int button);
    void GLwinGetCursorPos(GLWIN_window* window, double* xpos, double* ypos);

	// GLwinUI: Simple GUI message box
	// GLwinUI_MessageBox(const wchar_t* title, const wchar_t* message);

    

    // Terminate and cleanup library (optional, for symmetry with GLFW)
    void GLwinTerminate(void);

#ifdef __cplusplus
}
#endif
