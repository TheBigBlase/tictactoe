#include <array>
#include <string>

class Board  {
	public:
		Board();
		void turn(bool);
		void clean();
		void renderFrame();
	private:
		std::string mMove;
		std::array<std::array<std::array<bool, 2>, 3>, 3>  mState;
		char boolToSymbol(std::array<bool, 2> &);
		bool isMoveValid(char x, char y, bool player);
		bool isGameOver();
		bool isDraw {false};
};

