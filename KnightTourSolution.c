/*
	Solves the Knight Tour Problem from the 64 start location possibilities.
	by AndyR.
*/

#include "knightour.h"

/*file outputs*/
char Location_Solution[] = "KnightTourOutput.txt";

int main(void){
	U_Int8 LOOPx = 0U;
	U_Int8 LOOPy = 0U;
	
	for (LOOPx=0U;LOOPx<8U;LOOPx++){
		for (LOOPy=0U;LOOPy<8U;LOOPy++){
			/*Clear the board (Clean zero no moves on the board)*/
			ClearBoard();
			/*print on screen the start position*/
			printf("\n solution from starting position : (%d,%d) ",LOOPx , LOOPy);
			/*solve the knight tour from the given position with no intermediate display... no detail on the solution*/
			Solve_KnightTour(LOOPx,LOOPy,0U);
			/*display the board for giggles*/
			DispBoard();
			/*Write the final board to the file*/
			WriteToFile(Location_Solution);
		}
	}

	printf("\n Solutions Completed \n ");
	
	/*solve the knight tour from the start location 0,2 with some display*/
	Solve_KnightTour(0U,2U,1U);

	U_Int8 Test_A[8]={255, 255, 255, 255, 1, 1, 255, 255};

	printf("\n %d \n ",Sort_Array(Test_A));

	return 0;
}
