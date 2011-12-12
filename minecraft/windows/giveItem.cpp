#include <iostream>
#include <windows.h>
#include <winable.h>
#include <stdio.h>
#include <string.h>
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
	GenerateKey(0x54, FALSE); //OPEN CHAT (if bound to t)
	
	Sleep(100);
	GenerateKey(111, FALSE); // a '/'
	Sleep(10);
	GenerateKey(71, FALSE); //g
	Sleep(10);
	GenerateKey(73, FALSE); //i
	Sleep(10);
	GenerateKey(86, FALSE); //v
	Sleep(10);
	GenerateKey(69, FALSE); //e
	Sleep(10);
	GenerateKey(32, FALSE); //space
	Sleep(10);
	GenerateKey('U', FALSE);
	Sleep(10);
	GenerateKey('S', FALSE);
	Sleep(10);
	GenerateKey('E', FALSE);
	Sleep(10);
	GenerateKey('R', FALSE);
	Sleep(10);
	GenerateKey('N', FALSE);
	Sleep(10);
	GenerateKey('A', FALSE);
	Sleep(10);
	GenerateKey('M', FALSE);
	Sleep(10);
	GenerateKey('E', FALSE);
	Sleep(10);
	GenerateKey(32, FALSE); //space
	itemCode(argv[1]);
	Sleep(10);
	GenerateKey(32, FALSE); //space
	amount(argv[2]);
	
	Sleep(10);
	GenerateKey(0x0D, FALSE); /* enter key */

    return 0;
}

//code of max 3 chars length
void itemCode(char *item)
{	
	int i = strlen(item);
	//printf("%d", i); //DEBUG
	for(int a=0; a<i; ++a){
		Sleep(10);
		GenerateKey((48 + *(item + a)), FALSE);
	}
}

//code of max 2 chars length (64 is max)
void amount(char *amount)
{
	int i = strlen(amount);
	for(int a=0; a<i; ++a){
		Sleep(10);
		GenerateKey((48 + *(amount + a)), FALSE);
	}
}

// some info...
//GenerateKey(VK_CAPITAL, TRUE); //caps
//10 = 0 - zero
//10 = caps
//111 = /