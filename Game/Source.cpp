#include <windows.h>
#include <stdlib.h> 
#include <string.h> 
#include <tchar.h>  
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "ScreenManager.h"
#include "PlayerManager.h"
#include "Loader.h"


LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	
	sf::RenderWindow window(sf::VideoMode(560,560), "SFML window", sf::Style::Close);
	ScreenManager::getInstance()->setScreen(screenType::MENU);
	PlayerManager::getInstance()->setPlayer(FIRST);
	window.setVerticalSyncEnabled(true);
	window.setKeyRepeatEnabled(false);
	
	if (!Loader::getInstance()->init()) {
		MessageBox(nullptr, "Can't load some files", "Error occured", MB_OK);
		return EXIT_SUCCESS;
	}
	while (window.isOpen())
	{
		sf::Event prevEvent;
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		if (prevEvent.type != event.type || event.type == sf::Event::MouseMoved) {
			prevEvent.type = event.type;
		}
		else {
			event.type = sf::Event::MouseWheelMoved;
		}
		ScreenManager::getInstance()->Update(window, event);
		ScreenManager::getInstance()->Draw(window);
		window.display();
	}
	Loader::getInstance()->unload();
	return EXIT_SUCCESS;

}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	PAINTSTRUCT ps; HDC hdc; TCHAR greeting[] = _T("Hello, World!"); switch (message) {
	case WM_PAINT: hdc = BeginPaint(hWnd, &ps); // Here your application is laid out. // For this introduction, we just print out "Hello, World!" // in the top left corner. 
		TextOut(hdc, 5, 5, greeting, _tcslen(greeting)); // End application-specific layout section. 
		EndPaint(hWnd, &ps); break; case WM_DESTROY: PostQuitMessage(0); 
		break; 
		default: return DefWindowProc(hWnd, message, wParam, lParam); 
			break; 
	} return 0; 
} 