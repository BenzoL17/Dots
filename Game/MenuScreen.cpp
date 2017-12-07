#include "MenuScreen.h"
#include "ScreenManager.h"



MenuScreen::MenuScreen()
{
}


MenuScreen::~MenuScreen()
{
}

void MenuScreen::Init()
{
	menuUpdater = new MenuUpdater();
	menuUpdater->init(screeType);

}

void MenuScreen::Unload()
{
	menuUpdater->unload();
	delete menuUpdater;
}

void MenuScreen::Update(sf::RenderWindow &window, sf::Event ev)
{
	if (input.update(ev)) {
		if (ev.type == sf::Event::MouseMoved) {
			menuUpdater->update(ev.mouseMove.x, ev.mouseMove.y, screeType);
		}
		if (input.MouseKeyReleased(sf::Mouse::Left)) {
			menuUpdater->goToScreen(window);
		}
		if (input.KeyReleased(sf::Keyboard::A)) { // test
			ScreenManager::getInstance()->setScreen(END);
		}
		if (screeType == screenType::PAUSE_MENU) {
			if (input.KeyReleased(sf::Keyboard::Escape)) {
				ScreenManager::getInstance()->setScreen(screenType::GAME);
			}
		}
	}
}

void MenuScreen::Draw(sf::RenderWindow &window)
{
	window.draw(menuUpdater->getBackground());
	if (screeType == PAUSE_MENU) {
		window.draw(menuUpdater->getText(textType::GAME_CONTINUE));

	}
	window.draw(menuUpdater->getText(textType::GAME_NEW));
	window.draw(menuUpdater->getText(textType::GAME_EXIT));
	//window.draw(menuUpdater->getTextBox());
}
