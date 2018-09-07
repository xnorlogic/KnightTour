/*
	Solves the Knight Tour Problem from the 64 start location possibilities.
	by AndyR.
*/

#include "knightour.h"

/*file outputs*/
char Location_Solution[] = "KnightTourOutput.txt";

int main(void){
	
	for (U_Int8 LOOPx=0;LOOPx<8;LOOPx++){	
		for (U_Int8 LOOPy=0;LOOPy<8;LOOPy++){
			/*Clear the board (Clean zero no moves on the board)*/
			ClearBoard();
			/*print on screen the start position*/
			printf("\n solution from starting position : (%d,%d) ",LOOPx , LOOPy);
			/*solve the knight tour from the given position with no intermediate display... no detail on the solution*/
			Solve_KnightTour(LOOPx,LOOPy,0);
			/*display the board for giggles*/
			DispBoard();
			/*Write the final board to the file*/
			WriteToFile(Location_Solution);
		}
	}

	printf("\n Solutions Completed \n ");
	
	/*solve the knight tour from the start location 5,1 with some display*/
	Solve_KnightTour(0,2,1);

	return 0;
}
