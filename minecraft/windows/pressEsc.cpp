#include <iostream>
#include <windows.h>
#include <winable.h>
using namespace std;

void itemCode(char *item);
void amount(char *amount);

/* HWND = "Window Handle" */
HWND GameWindow = FindWindow(0, "Minecraft");

/* This is a function to simplify usage of sending keys */
void GenerateKey(int vk, BOOL bExtended) {

    KEYBDINPUT  kb = {0};
    INPUT       Input = {0};

    /* Generate a "key down" */
    if (bExtended) { kb.dwFlags  = KEYEVENTF_EXTENDEDKEY; } //keep pressed
    kb.wVk  = vk;
    Input.type  = INPUT_KEYBOARD;
    Input.ki  = kb;
    SendInput(1, &Input, sizeof(Input));

    /* Generate a "key up" */
    ZeroMemory(&kb, sizeof(KEYBDINPUT));
    ZeroMemory(&Input, sizeof(INPUT));
    kb.dwFlags  =  KEYEVENTF_KEYUP;
    if (bExtended) { kb.dwFlags |= KEYEVENTF_EXTENDEDKEY; } //keep un-pressed
    kb.wVk = vk;
    Input.type = INPUT_KEYBOARD;
    Input.ki = kb;
    SendInput(1, &Input, sizeof(Input));

    return;
}

int main(int argc, char **argv) {

    SetForegroundWindow(GameWindow);
	
	Sleep(500);
    GenerateKey(0x1B, FALSE); /* esc key, bring down menu */
}