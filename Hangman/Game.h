#include "Player.h"
#include "Figure.h"
#include <string>
#include <vector>

namespace Hangman {
	class Game {
	public:
		Game();
		void Run();

		std::string GetWord(std::string filename);
		std::ifstream OpenFile(const std::string& filename);
	private:
		Player player = Player();
		Figure figure = Figure();
		
		
		std::vector<std::string> getLines(std::ifstream& file);
	};
}


