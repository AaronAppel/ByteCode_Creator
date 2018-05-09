#include "Creator.h"

void DrawItemWindow();
void DrawCharacterWindow();

Compiler g_Comp; // TODO: No globals!

static char itemName[100];
static char charName[100];

int main()
{    
    memcpy(itemName, "Axe", 3); // TODO: Init string better
    memcpy(charName, "Terry", 5);

    GLFWwindow* window = Setup("Creator", 300, 600);

    while (!glfwWindowShouldClose(window))
    {
        /* input */
        glfwPollEvents();
        ImGui_ImplGlfwGL3_NewFrame();

        /* logic */


        /* render */
        glClear(GL_COLOR_BUFFER_BIT);
        
        DrawItemWindow();
        DrawCharacterWindow();

        ImGui::Render();
        ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);
    }

    return 0;
}

void DrawItemWindow()
{
    // persistent data
    static bool itemCreator = 1;
    static int cost = 0;

    // draw fields
    ImGui::Begin("Item Creator", &itemCreator, 0);
    ImGui::Text("Create Item");
    ImGui::InputText("Name", itemName, 100);
    ImGui::InputInt("Cost", &cost);

    if (ImGui::Button("Create!"))
    {
        Item testItem;
        testItem.SetName(itemName);
        testItem.SetCost(cost);
        g_Comp.GenerateItem(&testItem);
    }
    ImGui::End();
}

void DrawCharacterWindow()
{
    // persistent data
    static bool charCreator = 1;
    static int energy = 0;

    // draw fields
    ImGui::Begin("Character Creator", &charCreator, 0);
    ImGui::Text("Create Character");
    ImGui::InputText("Name", charName, 100);
    ImGui::InputInt("MaxEnergy", &energy);
    if (ImGui::Button("Create!"))
    {
        Character testChar;
        testChar.SetName(charName);
        testChar.SetMaxEnergy(energy);
        g_Comp.GenerateCharacter(&testChar);
    }
    ImGui::End();
}