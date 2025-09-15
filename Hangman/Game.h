#include "Player.h"
#include "Figure.h"
#include <string>
#include <vector>

namespace Hangman {
	class Game {
	public:
		Game() {};
		void const Run();

		std::string const GetWord(std::string filename);
	private:
		Player player;
		Figure figure;
		
		
		std::vector<std::string> const getLines(std::ifstream& file);
	};
}


