/*
# -------------------- #
# (C)2022 madoodia.com #
# -------------------- #
*/

// Standard Libraries
#include <iostream>

// Third Party Libraries
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// Application Libraries

void frameBufferSizeCallback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

// Settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

float RED = 0.0f;
float GREEN = 0.0f;
float BLUE = 0.0f;

// Main Function
int main()
{
    // glfw initialization
    glfwInit();
    // Creating OpenGL context (Configuring glfw)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);                 // OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);                 // OpenGL 3.3
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // Core profile
    // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);        // For Mac OS
    // glfwWindowHint(GLFW_RESIZABLE, GL_FALSE); // Not resizable window

    // glfw window creatiion
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Learning OpenGL", nullptr, nullptr);
    if (window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, frameBufferSizeCallback);

    // glew initialization
    if (glewInit() != GLEW_OK)
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    // render loop
    while (!glfwWindowShouldClose(window))
    {
        // Input
        processInput(window);

        glClearColor(RED, GREEN, BLUE, 1.0f); // This is a state-setting function
        glClear(GL_COLOR_BUFFER_BIT);         // This is a state-using function

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}

void processInput(GLFWwindow* window)
{
    // Close Window
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }

    // Color Control
    if (glfwGetKey(window, GLFW_KEY_KP_4) == GLFW_PRESS)
    {
        RED += 0.01f;
    }
    if (glfwGetKey(window, GLFW_KEY_KP_1) == GLFW_PRESS)
    {
        RED -= 0.01f;
    }
    if (glfwGetKey(window, GLFW_KEY_KP_5) == GLFW_PRESS)
    {
        GREEN += 0.01f;
    }
    if (glfwGetKey(window, GLFW_KEY_KP_2) == GLFW_PRESS)
    {
        GREEN -= 0.01f;
    }
    if (glfwGetKey(window, GLFW_KEY_KP_6) == GLFW_PRESS)
    {
        BLUE += 0.01f;
    }
    if (glfwGetKey(window, GLFW_KEY_KP_3) == GLFW_PRESS)
    {
        BLUE -= 0.01f;
    }
}

void frameBufferSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}