#include "chessboardlib.h"
/*TBD... Create more chess pieces!*/

void Make_Move(Chess_Set *Local_Chess_Set,U_Int8 PieceType,U_Int8 move,U_Int8 marker){
	U_Int8 X_Local;
	U_Int8 Y_Local;
	/*To Do: create the moves and rules for the other chess pieces*/
	switch(PieceType){
		case PAWN:
		break;

		case KNIGHT:
			Local_Chess_Set->Chess_White.Knight_1.x = NEW_X_Knight(Local_Chess_Set->Chess_White.Knight_1.x,move);
			Local_Chess_Set->Chess_White.Knight_1.y = NEW_Y_Knight(Local_Chess_Set->Chess_White.Knight_1.y,move);
			X_Local = Local_Chess_Set->Chess_White.Knight_1.x;
			Y_Local = Local_Chess_Set->Chess_White.Knight_1.y;
		break;

		case BISHOP:
		break;

		case ROOK:
		break;

		case QUEEN:
		break;

		case KING:
		break;
	}
	Board[X_Local][Y_Local] = marker;
}

/*
Possible moves for the knight
Board[x + 2][y + 1] move 1
Board[x + 2][y - 1] move 2
Board[x + 1][y + 2] move 3
Board[x + 1][y - 2] move 4
Board[x - 2][y + 1] move 5
Board[x - 2][y - 1] move 6
Board[x - 1][y + 2] move 7
Board[x - 1][y - 2] move 8
*/

/*x,y move combination for the knight------------*/
U_Int8 NEW_X_Knight (U_Int8 x, U_Int8 moveNumber){
	switch (moveNumber){
			case 1:x = x + 2;
			break;

			case 2:x = x + 2;
			break;

			case 3:x = x + 1;
			break;

			case 4:x = x + 1;
			break;

			case 5:x = x - 2;
			break;

			case 6:x = x - 2;
			break;

			case 7:x = x - 1;
			break;

			case 8:x = x - 1;
			break;

			default: x = x + 0;
		}
	return x;
}
U_Int8 NEW_Y_Knight (U_Int8 y, U_Int8 moveNumber){
	switch (moveNumber){
				case 1:y = y + 1;
				break;

				case 2:y = y - 1;
				break;

				case 3:y = y + 2;
				break;

				case 4:y = y - 2;
				break;

				case 5:y = y + 1;
				break;

				case 6:y = y - 1;
				break;

				case 7:y = y + 2;
				break;

				case 8:y = y - 2;
				break;

				default : y = y + 0;
			}
	return y;
}
/*-----------------------------------------------*/

/*Returns the value at a given location*/
U_Int8 BoardValue_XY(U_Int8 x, U_Int8 y){
	return Board[x][y];
}

/*Display the board in the console*/
void DispBoard (void){
	U_Int8 R = 0;
	U_Int8 C = 0;
	printf(" \n ");
	for (R = 0; R<ROW; R++){
		for (C = 0; C<COL; C++){
			printf(" %3d ", Board [R][C]);
		}
		printf(" \n ");
	}
}

/*Write the board to a txt file*/
void WriteToFile (char Location[]){
	U_Int8 R = 0;
	U_Int8 C = 0;
	FILE *fp;
    fp = fopen(Location, "a");
	
	fprintf(fp," \n ");
	for (R = 0; R<ROW; R++){
		for (C =0; C<COL; C++){
			fprintf(fp, " %3d ", Board [R][C]);
		}
		fprintf(fp," \n ");
	}
	
	fclose(fp);
}

/*Generates initial empty board with zeros*/
void ClearBoard (void){
	U_Int8 R = 0;
	U_Int8 C = 0;
	for (R = 0; R<ROW; R++){
		for (C =0; C<COL; C++){
			Board [R][C] = 0;
		}
	}
}
