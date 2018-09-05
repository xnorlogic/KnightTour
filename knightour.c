#include "knightour.h"

int NEW_X (int x, int moveNumber){
	switch (moveNumber){
			case 1:x = x + 2;//Perform Move1
			break;
			
			case 2:x = x + 2;//Perform Move2
			break;
			
			case 3:x = x + 1;//Perform Move3
			break;
			
			case 4:x = x + 1;//Perform Move4
			break;
			
			case 5:x = x - 2;//Perform Move5
			break;
			
			case 6:x = x - 2;//Perform Move6
			break;
			
			case 7:x = x - 1;//Perform Move7
			break;
			
			case 8:x = x - 1;//Perform Move8
			break;
			
			default: x = x;
		} 
	return x;
}

int NEW_Y (int y, int moveNumber){
	switch (moveNumber){
				case 1:y = y + 1;//Perform Move1
				break;
				
				case 2:y = y - 1;//Perform Move2
				break;
				
				case 3:y = y + 2;//Perform Move3
				break;
				
				case 4:y = y - 2;//Perform Move4
				break;
				
				case 5:y = y + 1;//Perform Move5
				break;
				
				case 6:y = y - 1;//Perform Move6
				break;
				
				case 7:y = y + 2;//Perform Move7
				break;
				
				case 8:y = y - 2;//Perform Move8
				break;
				
				default : y = y;
			} 
	return y;
}

int SelectData_INDEX(int Array[]){

	int TMP = Array[0];
	int Index = 0;
	int T;
	
	for(T=1;T<8;T++){
		if(Array[T]<TMP && Array[T] !=0)
		{
			TMP = Array[T];
			Index = T;
		}
	}
	
	return Index;
}

bool MOVE1_OK(int x, int y, int MoveAvailable){
	if(IS_MOVE1_LEGAL && MoveAvailable == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool MOVE2_OK(int x, int y, int MoveAvailable){
	if(IS_MOVE2_LEGAL && MoveAvailable == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool MOVE3_OK(int x, int y, int MoveAvailable){
	if(IS_MOVE3_LEGAL && MoveAvailable == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool MOVE4_OK(int x, int y, int MoveAvailable){
	if(IS_MOVE4_LEGAL && MoveAvailable == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool MOVE5_OK(int x, int y, int MoveAvailable){
	if(IS_MOVE5_LEGAL && MoveAvailable == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool MOVE6_OK(int x, int y, int MoveAvailable){
	if(IS_MOVE6_LEGAL && MoveAvailable == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool MOVE7_OK(int x, int y, int MoveAvailable){
	if(IS_MOVE7_LEGAL && MoveAvailable == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool MOVE8_OK(int x, int y, int MoveAvailable){
	if(IS_MOVE8_LEGAL && MoveAvailable == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Returns the value at a given location
int BoardValue_XY(int x, int y, int moveNumber, int Board[ROW][COL]){
    /*
	Posible moves for the knight
	Board[x + 2][y + 1]
	Board[x + 2][y - 1]
	Board[x + 1][y + 2]
	Board[x + 1][y - 2]
	Board[x - 2][y + 1]
	Board[x - 2][y - 1]
	Board[x - 1][y + 2]
	Board[x - 1][y - 2]
	*/
	int BoardValue = 0;
	switch (moveNumber){
			case 1:BoardValue = Board[x + 2][y + 1];
			break;
			
			case 2:BoardValue = Board[x + 2][y - 1];
			break;
			
			case 3:BoardValue = Board[x + 1][y + 2];
			break;
			
			case 4:BoardValue = Board[x + 1][y - 2];
			break;
			
			case 5:BoardValue = Board[x - 2][y + 1];
			break;
			
			case 6:BoardValue = Board[x - 2][y - 1];
			break;
			
			case 7:BoardValue = Board[x - 1][y + 2];
			break;
			
			case 8:BoardValue = Board[x - 1][y - 2];
			break;
			
			default: BoardValue = BoardValue;
		} 
	return BoardValue;
}

//returns how many moves for the Knight are available at a given location in the board
int DetermineMoves(int x, int y,int Board[ROW][COL]){

	int possibleMoves = 0;
	
	if(MOVE1_OK(x,y,BoardValue_XY(x,y,Move1,Board)))
	{
		possibleMoves++;
	}
	else
	{
		possibleMoves=possibleMoves;
	}
		
	if(MOVE2_OK(x,y,BoardValue_XY(x,y,Move2,Board)))
	{
		possibleMoves++;
	}
	else
	{
		possibleMoves=possibleMoves;
	}
		
	if(MOVE3_OK(x,y,BoardValue_XY(x,y,Move3,Board)))
	{
		possibleMoves++;
	}
	else
	{
		possibleMoves=possibleMoves;
	}
		
	if(MOVE4_OK(x,y,BoardValue_XY(x,y,Move4,Board)))
	{
		possibleMoves++;
	}
	else
	{
		possibleMoves=possibleMoves;
	}
		
	if(MOVE5_OK(x,y,BoardValue_XY(x,y,Move5,Board)))
	{
		possibleMoves++;
	}
	else
	{
		possibleMoves=possibleMoves;
	}
		
	if(MOVE6_OK(x,y,BoardValue_XY(x,y,Move6,Board)))
	{
		possibleMoves++;
	}
	else
	{
		possibleMoves=possibleMoves;
	}
	
	if(MOVE7_OK(x,y,BoardValue_XY(x,y,Move7,Board)))
	{
		possibleMoves++;
	}
	else
	{
		possibleMoves=possibleMoves;
	}
		
	if(MOVE8_OK(x,y,BoardValue_XY(x,y,Move8,Board)))
	{
		possibleMoves++;
	}
	else
	{
		possibleMoves=possibleMoves;
	}
	
	return possibleMoves;
}

//Display the board in the console
void DispBoard (int Board[ROW][COL]){
	printf(" \n ");
	for (int R = 0; R<ROW; R++){
		for (int C =0; C<COL; C++){
			printf(" %2d ", Board [R][C]);
		}
		printf(" \n ");
	}
}

//Write the board to a txt file
void WriteToFile (int Board[ROW][COL], char Location[]){
	FILE *fp;
    fp = fopen(Location, "a");
	
	fprintf(fp," \n ");
	for (int R = 0; R<ROW; R++){
		for (int C =0; C<COL; C++){
			fprintf(fp, " %2d ", Board [R][C]);
		}
		fprintf(fp," \n ");
	}
	
	fclose(fp);
}

//Genereates initial empty board with zeros
void ClearBoard (int Board[ROW][COL]){
	for (int R = 0; R<ROW; R++){
		for (int C =0; C<COL; C++){
			Board [R][C] = 0;
		}
	}
}

//This is a prototype to generate all moves available at the initial stage of the board. 
//(No necessary for the solution)
void CreateMoves (int Board[ROW][COL]){
	for (int R = 0; R<ROW; R++)
	{
		for (int C =0; C<COL; C++)
		{
			Board [R][C] = DetermineMoves(R,C,Board);
		}
	}
}

//--------------------------------------------------------------------------------------------
//Logic for the KnightTour solution-----------------------------------------------------------
//returns next move based on how many moves for the knight are available at a given position
int NextMove(int x,int y, int Board[ROW][COL]){

	int MOVES [8] = {0,0,0,0,0,0,0,0};
	int Location [8] = {0,0,0,0,0,0,0,0};
	int Jumps = 0;
	
	if (MOVE1_OK(x,y,BoardValue_XY(x,y,Move1,Board))){
		MOVES[Jumps] = DetermineMoves(x+2,y+1,Board);
		Location[Jumps] = Move1;
		Jumps++;
	}
	else{Jumps=Jumps;}
	
	if (MOVE2_OK(x,y,BoardValue_XY(x,y,Move2,Board))){
		MOVES[Jumps] = DetermineMoves(x+2,y-1,Board);
		Location[Jumps] = Move2;
		Jumps++;
	}
	else{Jumps=Jumps;}
	
	if (MOVE3_OK(x,y,BoardValue_XY(x,y,Move3,Board))){
		MOVES[Jumps] = DetermineMoves(x+1,y+2,Board);
		Location[Jumps] = Move3;
		Jumps++;
	}
	else{Jumps=Jumps;}
	
	if (MOVE4_OK(x,y,BoardValue_XY(x,y,Move4,Board))){
		MOVES[Jumps] = DetermineMoves(x+1,y-2,Board);
		Location[Jumps] = Move4;
		Jumps++;
	}
	else{Jumps=Jumps;}
	
	if (MOVE5_OK(x,y,BoardValue_XY(x,y,Move5,Board))){
		MOVES[Jumps] = DetermineMoves(x-2,y+1,Board);
		Location[Jumps] = Move5;
		Jumps++;
	}
	else{Jumps=Jumps;}
	
	if (MOVE6_OK(x,y,BoardValue_XY(x,y,Move6,Board))){
		MOVES[Jumps] = DetermineMoves(x-2,y-1,Board);
		Location[Jumps] = Move6;
		Jumps++;
	}
	else{Jumps=Jumps;}
	
	if (MOVE7_OK(x,y,BoardValue_XY(x,y,Move7,Board))){
		MOVES[Jumps] = DetermineMoves(x-1,y+2,Board);
		Location[Jumps] = Move7;
		Jumps++;
	}
	else{Jumps=Jumps;}
	
	if (MOVE8_OK(x,y,BoardValue_XY(x,y,Move8,Board))){
		MOVES[Jumps] = DetermineMoves(x-1,y-2,Board);
		Location[Jumps] = Move8;
		Jumps++;
	}
	else{Jumps=Jumps;}
	
	return Location[SelectData_INDEX(MOVES)];
}

//PerformMove(<int x>, <int y>, <int MOVE ID: 1,2,3,4,5,6,7,8>, <int Marker>, <int BOARD[][]>)
void PerformMove(int x, int y, int moveNumber, int marker, int Board[ROW][COL]){

	x = NEW_X(x,moveNumber);
	y = NEW_Y(y,moveNumber);

	Board[x][y] = marker;
	
}
//--------------------------------------------------------------------------------------------
