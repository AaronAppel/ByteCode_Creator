#include "SetupLibraries.h"

GLFWwindow* Setup(const char* windowTitle, int winWidth, int winHeight)
{
    /* glfw */
    GLFWwindow* window;

    if (!glfwInit())
        return nullptr; // glfw crashed

    window = glfwCreateWindow(winWidth, winHeight, windowTitle, NULL, NULL);
    if (!window)
        return nullptr; // glfw crashed

    glfwMakeContextCurrent(window);

    /* glew */
    if (glewInit() != GLEW_OK)
        return nullptr; // glew crashed    

    /* opengl */
    glViewport(0, 0, winWidth, winHeight);

    /* imgui */
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui_ImplGlfwGL3_Init(window, true);

    return window; // pass window back to main thread
}

void TearDown(GLFWwindow* window)
{
    glfwDestroyWindow(window); // destroy window
    ImGui_ImplGlfwGL3_Shutdown(); // shutdown imgui
    ImGui::DestroyContext(); // destroy imgui
    glfwTerminate(); // shutdown glfw
}