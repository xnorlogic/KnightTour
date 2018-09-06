#include "knightour.h"

U_Int8 NEW_X (U_Int8 x, U_Int8 moveNumber){
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

U_Int8 NEW_Y (U_Int8 y, U_Int8 moveNumber){
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

U_Int8 Sort_Array(U_Int8 Array[8]){

	U_Int8 TMP = 0;
	U_Int8 T;
	U_Int8 swap_flag = 0;
	U_Int8 move_array[8] = {1,2,3,4,5,6,7,8};
	
	do{	
		swap_flag = 0;
		for(T=0;T<7;T++){
			if(Array[T]>Array[T+1]){
				/*swap the array move element to sort the lowest possible move to the start of the array*/
				TMP = Array[T];
				Array[T] = Array[T+1];
				Array[T+1];
				/*swap  the moves array as a mirror in order to have the best next move*/
				TMP = move_array[T];
				move_array[T]  = move_array[T+1];
				move_array[T+1] = TMP;
				/*swap happened*/
				swap_flag = 1;				
			}
			else{
				/*no change*/
			}
		}
	}while(swap_flag);
	
	return move_array[0];
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
U_Int8 BoardValue_XY(U_Int8 x, U_Int8 y, U_Int8 moveNumber){
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
	U_Int8 BoardValue = 0;
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
U_Int8 DetermineMoves(U_Int8 x, U_Int8 y){
	
	U_Int8 possibleMoves = 0;
	
	U_Int8 M1 = IS_MOVE1_LEGAL;
	U_Int8 M2 = IS_MOVE2_LEGAL;
	U_Int8 M3 = IS_MOVE3_LEGAL;
	U_Int8 M4 = IS_MOVE4_LEGAL;
	U_Int8 M5 = IS_MOVE5_LEGAL;
	U_Int8 M6 = IS_MOVE6_LEGAL;
	U_Int8 M7 = IS_MOVE7_LEGAL;
	U_Int8 M8 = IS_MOVE8_LEGAL;
	
	possibleMoves = M1 + M2 + M3 + M4 + M5 + M6 + M7 + M8;
	
	return possibleMoves;
}

//Display the board in the console
void DispBoard (void){
	printf(" \n ");
	for (int R = 0; R<ROW; R++){
		for (int C =0; C<COL; C++){
			printf(" %2d ", Board [R][C]);
		}
		printf(" \n ");
	}
}

//Write the board to a txt file
void WriteToFile (char Location[]){
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
void ClearBoard (void){
	for (int R = 0; R<ROW; R++){
		for (int C =0; C<COL; C++){
			Board [R][C] = 0;
		}
	}
}

//This is a prototype to generate all moves available at the initial stage of the board. 
//(No necessary for the solution)
void CreateMoves (void){
	for (int R = 0; R<ROW; R++)
	{
		for (int C =0; C<COL; C++)
		{
			Board [R][C] = DetermineMoves(R,C);
		}
	}
}

//--------------------------------------------------------------------------------------------
//Logic for the KnightTour solution-----------------------------------------------------------
//returns next move based on how many moves for the knight are available at a given position
U_Int8 NextMove(U_Int8 x,U_Int8 y){

    U_Int8 ghost_x;
	U_Int8 ghost_y;
	U_Int8 moveNumber = 1;
	U_Int8 moves[8] = {255,255,255,255,255,255,255,255};
	
	for (moveNumber = 1;moveNumber<=8;moveNumber++){
		
		switch (moveNumber){
					case 1:
					ghost_x = X_PLUS_2;
					ghost_y = Y_PLUS_1;
					break;
					
					case 2:
					ghost_x = X_PLUS_2;
					ghost_y = Y_MINUS_1;
					break;
					
					case 3:
					ghost_x = X_PLUS_1;
					ghost_y = Y_PLUS_2;
					break;
					
					case 4:
					ghost_x = X_PLUS_1;
					ghost_y = Y_MINUS_2;
					break;
					
					case 5:
					ghost_x = X_MINUS_2;
					ghost_y = Y_PLUS_1;
					break;
					
					case 6:
					ghost_x = X_MINUS_2;
					ghost_y = Y_MINUS_1;
					break;
					
					case 7:
					ghost_x = X_MINUS_1;
					ghost_y = Y_PLUS_2;
					break;
					
					case 8:
					ghost_x = X_MINUS_1;
					ghost_y = Y_MINUS_2;
					break;
					
					default : 
					ghost_x = x + 0;
					ghost_y = y + 0;
					break;
				} 
		
		if ((((ghost_x) >= 0) && ((ghost_x) <= 7)) && (((ghost_y) >= 0) && ((ghost_y) <= 7))){
			if(BoardValue_XY(ghost_x,ghost_y,moveNumber) == 0){
				moves[moveNumber] = DetermineMoves(ghost_x,ghost_y);
			}
			else{
				/*move not valid... move has been allready taken*/
			}
		}
		else{
			/*move not valid... out of bounce!*/
		}
		
	}
	
	return Sort_Array(moves);
}

//PerformMove(<int x>, <int y>, <int MOVE ID: 1,2,3,4,5,6,7,8>, <int Marker>, <int BOARD[][]>)
void PerformMove(U_Int8 x, U_Int8 y, U_Int8 moveNumber, U_Int8 marker){

	x = NEW_X(x,moveNumber);
	y = NEW_Y(y,moveNumber);

	Board[x][y] = marker;
	
}
//--------------------------------------------------------------------------------------------
