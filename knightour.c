#include "knightour.h"

/*knight xy move combination*/
#define X_PLUS_2  x + 2U
#define X_PLUS_1  x + 1U
#define X_MINUS_2 x - 2U
#define X_MINUS_1 x - 1U
#define Y_PLUS_2  y + 2U
#define Y_PLUS_1  y + 1U
#define Y_MINUS_2 y - 2U
#define Y_MINUS_1 y - 1U

/*Move Restriction conditions knight*/
#define IS_MOVE1_LEGAL (((X_PLUS_2)  <= (SeedBoardSize-1)) && ((X_PLUS_2)  >= 0U)) && (((Y_PLUS_1)  <= (SeedBoardSize-1)) && ((Y_PLUS_1)  >= 0U))
#define IS_MOVE2_LEGAL (((X_PLUS_2)  <= (SeedBoardSize-1)) && ((X_PLUS_2)  >= 0U)) && (((Y_MINUS_1) >= 0U) && ((Y_MINUS_1) <= (SeedBoardSize-1)))
#define IS_MOVE3_LEGAL (((X_PLUS_1)  <= (SeedBoardSize-1)) && ((X_PLUS_1)  >= 0U)) && (((Y_PLUS_2)  <= (SeedBoardSize-1)) && ((Y_PLUS_2)  >= 0U))
#define IS_MOVE4_LEGAL (((X_PLUS_1)  <= (SeedBoardSize-1)) && ((X_PLUS_1)  >= 0U)) && (((Y_MINUS_2) >= 0U) && ((Y_MINUS_2) <= (SeedBoardSize-1)))
#define IS_MOVE5_LEGAL (((X_MINUS_2) >= 0U) && ((X_MINUS_2) <= (SeedBoardSize-1))) && (((Y_PLUS_1)  <= (SeedBoardSize-1)) && ((Y_PLUS_1)  >= 0U))
#define IS_MOVE6_LEGAL (((X_MINUS_2) >= 0U) && ((X_MINUS_2) <= (SeedBoardSize-1))) && (((Y_MINUS_1) >= 0U) && ((Y_MINUS_1) <= (SeedBoardSize-1)))
#define IS_MOVE7_LEGAL (((X_MINUS_1) >= 0U) && ((X_MINUS_1) <= (SeedBoardSize-1))) && (((Y_PLUS_2)  <= (SeedBoardSize-1)) && ((Y_PLUS_2)  >= 0U))
#define IS_MOVE8_LEGAL (((X_MINUS_1) >= 0U) && ((X_MINUS_1) <= (SeedBoardSize-1))) && (((Y_MINUS_2) >= 0U) && ((Y_MINUS_2) <= (SeedBoardSize-1)))

U_Int8 Sort_Array(U_Int8 Array[8U]){
	U_Int8 TMP = 0U;
	U_Int8 Index = 0U;
	U_Int8 swap_flag = 0U;
	U_Int8 move_array[8U] = {1U,2U,3U,4U,5U,6U,7U,8U};
	/*sort the array*/
	do{	
		swap_flag = 0U;
		for(Index=0U;Index<7U;Index++){
			if(Array[Index]>Array[Index+1U]){
				/*swap the array move element to sort the lowest possible move to the start of the array*/
				TMP = Array[Index];
				Array[Index] = Array[Index+1U];
				Array[Index+1U] = TMP;
				/*swap  the moves array as a mirror in order to have the best next move*/
				TMP = move_array[Index];
				move_array[Index]  = move_array[Index+1U];
				move_array[Index+1U] = TMP;
				/*swap happened*/
				swap_flag = 1U;
			}
			else{
				/*no change, persist the no change flag*/
			}
		}
	}while(swap_flag);
	/*return the corresponding move based on the sort*/
	return move_array[0U];
}

/*Returns the value at a given offset location location with*/
U_Int8 BoardValue_XY_offset(U_Int8 x, U_Int8 y, U_Int8 moveNumber){
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

			default: BoardValue = BoardValue + 0;
		}
	return BoardValue;
}

/*returns how many moves for the Knight are available at a given location in the board*/
U_Int8 DetermineMoves(U_Int8 x, U_Int8 y){
	U_Int8 possibleMoves = 0;
	U_Int8 M1 = IS_MOVE1_LEGAL && (BoardValue_XY_offset(x,y,1) == 0);
	U_Int8 M2 = IS_MOVE2_LEGAL && (BoardValue_XY_offset(x,y,2) == 0);
	U_Int8 M3 = IS_MOVE3_LEGAL && (BoardValue_XY_offset(x,y,3) == 0);
	U_Int8 M4 = IS_MOVE4_LEGAL && (BoardValue_XY_offset(x,y,4) == 0);
	U_Int8 M5 = IS_MOVE5_LEGAL && (BoardValue_XY_offset(x,y,5) == 0);
	U_Int8 M6 = IS_MOVE6_LEGAL && (BoardValue_XY_offset(x,y,6) == 0);
	U_Int8 M7 = IS_MOVE7_LEGAL && (BoardValue_XY_offset(x,y,7) == 0);
	U_Int8 M8 = IS_MOVE8_LEGAL && (BoardValue_XY_offset(x,y,8) == 0);
	possibleMoves = M1 + M2 + M3 + M4 + M5 + M6 + M7 + M8;
	return possibleMoves;
}

/*solve the knight tour*/
void Solve_KnightTour (U_Int8 x, U_Int8 y, U_Int8 Display_flag){
	U_Int8 CNT = 1;
	/*set the best next move to zero for the first pass*/
	U_Int8 BestNextMove = 0;
	/*set the board size for the loop... we want to make +1 in order to start the board from 1 not from 0*/
	U_Int8 My_Board_Size = BoardSize + 1;
	/*initial position*/
	White_Knight_1_Location.x=x;
	White_Knight_1_Location.y=y;
	/*clear the board*/
	ClearBoard();
	/*loop through the chess board*/
	for (CNT=1;CNT<My_Board_Size;CNT++){
		/*move the knight*/
		Make_Move(&White_Knight_1_Location,KNIGHT,BestNextMove,CNT);
		/*find the best next move for the knight*/
		BestNextMove = NextMove(White_Knight_1_Location.x, White_Knight_1_Location.y);
		if(Display_flag == 1){
			/*print some data of the steps*/
			printf("\n loop: %d \n ",CNT);
			printf("# of move: %d \n ",DetermineMoves(White_Knight_1_Location.x,White_Knight_1_Location.y));
			printf("next move ID: %d \n ",BestNextMove);
			DispBoard ();
		}
		else{
			/*no print*/
		}
	}
}

/*returns next move based on how many moves for the knight are available at a given position*/
U_Int8 NextMove(U_Int8 x,U_Int8 y){
    U_Int8 ghost_x;
	U_Int8 ghost_y;
	U_Int8 moveNumber = 0;
	U_Int8 moves[8] = {255,255,255,255,255,255,255,255};
	
	for (moveNumber = 0;moveNumber<8;moveNumber++){
		
		switch (moveNumber + 1){
					case 1:
					ghost_x = x + 2;
					ghost_y = y + 1;
					break;
					
					case 2:
					ghost_x = x + 2;
					ghost_y = y - 1;
					break;
					
					case 3:
					ghost_x = x + 1;
					ghost_y = y + 2;
					break;
					
					case 4:
					ghost_x = x + 1;
					ghost_y = y - 2;
					break;
					
					case 5:
					ghost_x = x - 2;
					ghost_y = y + 1;
					break;
					
					case 6:
					ghost_x = x - 2;
					ghost_y = y - 1;
					break;
					
					case 7:
					ghost_x = x - 1;
					ghost_y = y + 2;
					break;
					
					case 8:
					ghost_x = x - 1;
					ghost_y = y - 2;
					break;
					
					default : 
					ghost_x = x + 0;
					ghost_y = y + 0;
					break;
		}

		/*check if inbounds and a non occupied move*/
		if ((((ghost_x) >= 0) && ((ghost_x) <= (SeedBoardSize-1))) && (((ghost_y) >= 0) && ((ghost_y) <= (SeedBoardSize-1))) && BoardValue_XY(ghost_x,ghost_y) == 0){
			moves[moveNumber] = DetermineMoves(ghost_x,ghost_y);
		}
		else{
			/*move not valid... out of bounce!*/
			/*move not valid... move has been already taken*/
		}
	}
	/*return the best next move*/
	return Sort_Array(moves);
}
