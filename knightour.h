#ifndef KNIGHTOUR_H
#define KNIGHTOUR_H

#include <stdio.h>
#include <math.h>

typedef unsigned char bool;
typedef unsigned char U_Int8;

/*Board Size*/
#define SeedBoardSize 15U
#define BoardSize SeedBoardSize*SeedBoardSize
#define ROW SeedBoardSize
#define COL SeedBoardSize

typedef struct Chess_Piece_Location{
	U_Int8 x;
	U_Int8 y;
}Chess_Piece_Location;

/*Chess board*/
U_Int8 Board[ROW][COL];

U_Int8 NEW_X (U_Int8 x, U_Int8 moveNumber);

U_Int8 NEW_Y (U_Int8 y, U_Int8 moveNumber);

U_Int8 Sort_Array(U_Int8 Array[8U]);

/*Returns the value at a given offset location*/
U_Int8 BoardValue_XY_offset(U_Int8 x, U_Int8 y, U_Int8 moveNumber);

/*Returns the value at a given location*/
U_Int8 BoardValue_XY(U_Int8 x, U_Int8 y);

/*returns how many moves for the Knight are available at a given location in the board*/
U_Int8 DetermineMoves(U_Int8 x, U_Int8 y);

/*Display the board in the console*/
void DispBoard (void);

/*Write the board to a txt file*/
void WriteToFile (char Location[]);

/*Generates initial empty board with zeros*/
void ClearBoard (void);

/*solve the knight tour*/
void Solve_KnightTour (U_Int8 x, U_Int8 y, U_Int8 Display_flag);

/*returns next move based on how many moves for the knight are available at a given position*/
U_Int8 NextMove(U_Int8 x,U_Int8 y);

#endif /* */
