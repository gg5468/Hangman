#include "Player.h"
#include "Figure.h"
#include <string>

namespace Hangman {
	class Game {
	public:
		Game();
		void Run();
		std::string GetWord(std::string filename);

	private:
		Player player;
		Figure figure;
	};
}


