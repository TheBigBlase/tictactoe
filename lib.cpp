#include <iostream>
#include "./lib.hpp"

Board::Board(){
	for(char i {0} ; i < 3; i++){
		for(char j {0} ; j < 3; j++){
			mState[i][j][0] = false;
			mState[i][j][1] = false;
		}
	}
}

bool Board::isMoveValid(char x, char y, bool player){
	if(!mState[y][x][1]){
		mState[y][x][0] = player;
		mState[y][x][1] = true;
		return true;
	}
	std::cout<<"This is not a valid move"<<std::endl;
	return false;
}

char Board::boolToSymbol(std::array<bool,2> &x){
	if(x[1] == false){
		return ' ';
	}
	if(x[0] == true){
		return 'X';
	}
	return 'O';
}

void Board::renderFrame(){
	std::cout<<std::endl;
	std::cout<< boolToSymbol(mState[0][0]) << "|" << boolToSymbol(mState[0][1]) 
		<< "|" << boolToSymbol(mState[0][2]) << std::endl;
	std::cout<<"-----" << std::endl;
	std::cout<<boolToSymbol(mState[1][0]) << "|" << boolToSymbol(mState[1][1])
		<< "|" << boolToSymbol(mState[1][2]) << std::endl;
	std::cout<<"-----" << std::endl;
	std::cout<<boolToSymbol(mState[2][0]) << "|" << boolToSymbol(mState[2][1])
		<< "|" << boolToSymbol(mState[2][2]) << std::endl;
}

bool Board::isGameOver(){

	for(auto k {0}; k < 3 ;k++){ //for cols
		if(mState[k][0][1] == true and mState[k][1][1] == true and mState[k][2][1] == true){
			if(mState[k][0][0] == mState[k][1][0] 
					and mState[k][1][0] == mState[k][2][0]){
				std::cout<<"reached there";
				return true;
			}
		}
	}

	for(auto l {0}; l < 3 ;l++){ //for lines
		if(mState[0][l][1] == true and mState[1][l][1] == true and mState[2][l][1] == true){
			if(mState[0][l][0] == mState[1][l][0] 
					and mState[1][l][0] == mState[2][l][0]){
				std::cout<<"reached there 2";
				return true;
			}
		}
	}

	bool shouldContinue = true;//for diago 
	for(auto k {0} ; k < 3 ; k++){
		if(mState[k][k][1] == false){
			shouldContinue = false;
			break;
		}
	}
	if(shouldContinue){
		bool player = mState[0][0][0]; // first diago
		if(player ^ (!mState[1][1][0]) && player ^ (!mState[2][2][0])){
			return true;
		}
	}
	shouldContinue = true;

	for(auto k {0} ; k < 3 ; k++){
		if(mState[k][2-k][1] == false){
			shouldContinue = false;
			break;
		}
	}
	if(shouldContinue){
		bool player = mState[0][2][0]; // second diago
		if(player ^ (!mState[1][1][0]) && player ^ (!mState[2][0][0])){
			return true;
		}
	}
	for(auto k {0} ; k < 3 ; k++){ //no draw
		for(auto l {0} ; l < 3 ; l++){
			if(!mState[l][k][1]){
				return false;
			}
		}
	}
	isDraw = true;
	return true;
}

void Board::turn(bool player){
	bool validMove = false;
	while(not validMove){
		renderFrame();
		std::cin>>mMove;
		if (mMove.size() > 1){
			std::cout<<"wait, thats's illegal"<<std::endl;
		}
		char move = mMove[0];
		switch(move){
			case 'a':
				validMove = isMoveValid(0,0,player);
				break;
			case 'z':
				validMove = isMoveValid(1,0,player);
				break;
			case 'e':
				validMove = isMoveValid(2,0,player);
				break;
			case 'q':
				validMove = isMoveValid(0,1,player);
				break;
			case 's':
				validMove = isMoveValid(1,1,player);
				break;
			case 'd':
				validMove = isMoveValid(2,1,player);
				break;
			case 'w':
				validMove = isMoveValid(0,2,player);
				break;
			case 'x':
				validMove = isMoveValid(1,2,player);
				break;
			case 'c':
				validMove = isMoveValid(2,2,player);
				break;
			case 'p':
				clean();
				break;
			default :
				std::cout<<"non ! " <<std::endl;
				break;
		}
	}
	if(isGameOver()){
		renderFrame();
		if(!isDraw){
			char winner {'O'};
			if(player){ winner = 'X';}
			std::cout<< winner << " won ! EZ Clap"<< std::endl;
			std::exit(0);
		}
		std::cout<<"its a draw ! GG" <<std::endl;
		std::exit(0);
	}
}

void Board::clean(){
	for(char i {0} ; i < 3; i++){
		for(char j {0} ; j < 3; j++){
			mState[i][j][0] = false;
			mState[i][j][1] = false;
		}
	}
	std::cout<<"\n\n\n\n\n\n\n\n\n"<< std::endl;
}
