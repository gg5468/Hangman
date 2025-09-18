#include "Player.h"
#include "Figure.h"
#include <string>
#include <vector>

namespace Hangman {
	class Game {
	public:
		void Run();

		std::string GetWord(std::string filename) const;
	private:
		Player player;
		Figure figure;
		
		
		std::vector<std::string> getLines(std::ifstream& file) const;
	};
}


