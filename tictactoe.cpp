#include "lib.hpp"
#include <iostream>

int main(){
	std::cout<<"";
	Board Board;
	Board.clean();
	bool x = true;
	for(;;){
		Board.turn(x);
		if(x){x = false;}
		else{x = true;}
	}
}
