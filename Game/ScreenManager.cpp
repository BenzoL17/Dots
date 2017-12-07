#include "ScreenManager.h"
#include "EndScreen.h"
#include "GameScreen.h"
#include "MenuScreen.h"


IScreenState *screenState;
IScreenState *gameState = new GameScreen();


ScreenManager::ScreenManager()
{
}

ScreenManager::~ScreenManager()
{
}

//ScreenManager & ScreenManager::operator=(const ScreenManager & scr)
//{
//	this->Instance = scr;
//}


ScreenManager* ScreenManager::getInstance()
{
	static ScreenManager *Instance;
	if (Instance == nullptr)
		Instance = new ScreenManager();
	return Instance;
}

void ScreenManager::Init()
{
	screenState->Init();
}

void ScreenManager::Update(sf::RenderWindow &window, sf::Event ev)
{	
	screenState->Update(window, ev);
}

void ScreenManager::Draw(sf::RenderWindow &window)
{
	screenState->Draw(window);
}

void ScreenManager::setScreen(int screenType)
{
	if (screenState) {
		if (screenState->screeType != GAME) {
			screenState->Unload();
			delete screenState;
		}
		else
			gameState = screenState;
	}
	switch (screenType)
	{
	case END:
		screenState = new EndScreen();
		screenState->Init();
		break;
	case MENU:
		screenState = new MenuScreen();
		screenState->screeType = MENU;
		screenState->Init();
		break;
	case PAUSE_MENU:
		screenState = new MenuScreen();
		screenState->screeType = PAUSE_MENU;
		screenState->Init();
		break;
	case GAME:
		screenState = gameState;
		break;
	case NEW_GAME:
		screenState = new GameScreen();
		screenState->Init();
		break;
	};
}


