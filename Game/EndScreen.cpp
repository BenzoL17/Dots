#include "EndScreen.h"



EndScreen::EndScreen()
{
}


EndScreen::~EndScreen()
{
}

void EndScreen::Init()
{
	screeType = END;
	endSceneUpdater = new EndSceneupdater();
	endSceneUpdater->init();
}

void EndScreen::Unload()
{
	endSceneUpdater->unload();
	delete endSceneUpdater;
}

void EndScreen::Update(sf::RenderWindow &window, sf::Event ev)
{
	input.update(ev);
	if (ev.type == sf::Event::MouseMoved) {
		endSceneUpdater->update(ev.mouseMove.x, ev.mouseMove.y);
	}
	if (input.MouseKeyReleased(sf::Mouse::Left)) {
		endSceneUpdater->boxClicked(ev.mouseButton.x, ev.mouseButton.y);
	}
	if (input.KeyReleased(sf::Keyboard::Escape)) {
		ScreenManager::getInstance()->setScreen(screenType::MENU);
	}
}

void EndScreen::Draw(sf::RenderWindow &window)
{
	window.draw(endSceneUpdater->getBackToMenuBox());
	window.draw(endSceneUpdater->getPlayerBox());
	window.draw(endSceneUpdater->getBackground());
	if (endSceneUpdater->getScore(0) != nullptr) {
		window.draw(*endSceneUpdater->getScore(0));
		window.draw(*endSceneUpdater->getScore(1));
		window.draw(*endSceneUpdater->getScore(2));
	}
}
