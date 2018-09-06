/*
	Solves (partialy) the Knight Tour Problem from the 64 start location posibilities.
	by AndyR.
*/

#include "knightour.h"

//Structure to hold location of particular piece on the board... 
//This is the White Knight 1
Chess_Piece_Location White_Knight_1_Location;

int main(){

	char Location_Solution[] = "KnightTourOutput.txt";
	char Location_Moves[] = "MovesStatus.txt";

	U_Int8 NumberOfMoves = 0;
	U_Int8 BestNextMove;
	
	FILE *fp;
    fp = fopen(Location_Moves, "a");
	
	for (U_Int8 LOOPx=0;LOOPx<8;LOOPx++){	
		for (U_Int8 LOOPy=0;LOOPy<8;LOOPy++){
		
			fprintf(fp,"\n ------Loop: %d ------",LOOPy);
			
			//Initialize the next move to 0 (no move at the begining)
			BestNextMove = 0;
			//Clear the board (Clean zero no moves on the board)
			ClearBoard();
			
			//Seed the initial or starting point of the Knight
			White_Knight_1_Location.x = LOOPx;
			White_Knight_1_Location.y = LOOPy;
			
			for (U_Int8 CNT=1;CNT<65;CNT++){	
				
				//Perform a Move
				White_Knight_1_Location.x = NEW_X(White_Knight_1_Location.x,BestNextMove);
				White_Knight_1_Location.y = NEW_Y(White_Knight_1_Location.y,BestNextMove);
				Board[White_Knight_1_Location.x][White_Knight_1_Location.y] = CNT;
				
				//Determine number of moves available from the current location of the Knight
				NumberOfMoves = DetermineMoves(White_Knight_1_Location.x, White_Knight_1_Location.y);
				//Determine the best next move for the Knight
				BestNextMove = NextMove(White_Knight_1_Location.x, White_Knight_1_Location.y);
				
				//Do some print outs to the file
				fprintf(fp,"\n Jump : %d ",CNT);
				fprintf(fp,"\n Knight Location: %d,%d ",White_Knight_1_Location.x,White_Knight_1_Location.y);
				fprintf(fp,"\n Available moves: %d ",NumberOfMoves);
				fprintf(fp,"\n Best Next Move is : %d \n ",BestNextMove);	
				
			}
			
			DispBoard();
			
			//Write the final board to the file
			WriteToFile(Location_Solution);	
		}
		fprintf(fp,"\n --------------------- \n");
	}
	
	fclose(fp);
	printf("\n Solutions Completed \n ");
	
	White_Knight_1_Location.x=0;
	White_Knight_1_Location.y=0;
	
	ClearBoard();
	
	BestNextMove = 0;
	
	for (U_Int8 CNT=1;CNT<65;CNT++){	
	
		White_Knight_1_Location.x = NEW_X(White_Knight_1_Location.x,BestNextMove);
		White_Knight_1_Location.y = NEW_Y(White_Knight_1_Location.y,BestNextMove);
		Board[White_Knight_1_Location.x][White_Knight_1_Location.y] = CNT;
		DispBoard ();
		BestNextMove = NextMove(White_Knight_1_Location.x, White_Knight_1_Location.y);
	
	}
	
	ClearBoard();
	
	White_Knight_1_Location.x=0;
	White_Knight_1_Location.y=0;
	
	White_Knight_1_Location.x = NEW_X(White_Knight_1_Location.x,0);
	White_Knight_1_Location.y = NEW_Y(White_Knight_1_Location.y,0);
	Board[White_Knight_1_Location.x][White_Knight_1_Location.y] = 1;
	DispBoard ();
	
	White_Knight_1_Location.x = NEW_X(White_Knight_1_Location.x,1);
	White_Knight_1_Location.y = NEW_Y(White_Knight_1_Location.y,1);
	Board[White_Knight_1_Location.x][White_Knight_1_Location.y] = 2;
	DispBoard ();
	
	printf("\n %d \n ",DetermineMoves(White_Knight_1_Location.x,White_Knight_1_Location.y));
	printf("\n %d \n ",NextMove(White_Knight_1_Location.x, White_Knight_1_Location.y));
	
	return 0;
}
