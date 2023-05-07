#include "State.h"
#include "Player.h"
#include "PauseMenu.h"
class GameState : public State
{
private:
	//Pause Menu
	PauseMenu* pmenu;
	//Player
	Player* player;
	//World
	Sprite WorldBackground;
	//font
	Font font;
	//Functions
	void initfont();
	void initPlayer();
	void initkeybinds();
	void initTextures();
	void initWorldBackground();
public:

	GameState(RenderWindow* window, map <string, int>* supportedkeys, stack<State*>* states);
	virtual ~GameState();

	//Functions
	void updateinput(const float& dt);
	void updatePausedInput();
	void update(const float& dt, RenderTarget* target = nullptr);
	void render(RenderTarget* target = nullptr);

};