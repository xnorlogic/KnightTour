#ifndef KNIGHTOUR_H
#define KNIGHTOUR_H

#include <stdio.h>

typedef unsigned char bool;
typedef unsigned char U_Int8;

/*Board Size*/
#define ROW 8
#define COL 8

/*Chess board*/
U_Int8 Board[ROW][COL];

/*knight xy move combination*/
#define X_PLUS_2  x + 2
#define X_PLUS_1  x + 1
#define X_MINUS_2 x - 2
#define X_MINUS_1 x - 1
#define Y_PLUS_2  y + 2
#define Y_PLUS_1  y + 1
#define Y_MINUS_2 y - 2
#define Y_MINUS_1 y - 1

/*Move Restriction conditions knight*/
#define IS_MOVE1_LEGAL (((X_PLUS_2)  <= 7) && ((X_PLUS_2)  >= 0)) && (((Y_PLUS_1)  <= 7) && ((Y_PLUS_1)  >= 0)) 
#define IS_MOVE2_LEGAL (((X_PLUS_2)  <= 7) && ((X_PLUS_2)  >= 0)) && (((Y_MINUS_1) >= 0) && ((Y_MINUS_1) <= 7))
#define IS_MOVE3_LEGAL (((X_PLUS_1)  <= 7) && ((X_PLUS_1)  >= 0)) && (((Y_PLUS_2)  <= 7) && ((Y_PLUS_2)  >= 0))
#define IS_MOVE4_LEGAL (((X_PLUS_1)  <= 7) && ((X_PLUS_1)  >= 0)) && (((Y_MINUS_2) >= 0) && ((Y_MINUS_2) <= 7))
#define IS_MOVE5_LEGAL (((X_MINUS_2) >= 0) && ((X_MINUS_2) <= 7)) && (((Y_PLUS_1)  <= 7) && ((Y_PLUS_1)  >= 0))
#define IS_MOVE6_LEGAL (((X_MINUS_2) >= 0) && ((X_MINUS_2) <= 7)) && (((Y_MINUS_1) >= 0) && ((Y_MINUS_1) <= 7))
#define IS_MOVE7_LEGAL (((X_MINUS_1) >= 0) && ((X_MINUS_1) <= 7)) && (((Y_PLUS_2)  <= 7) && ((Y_PLUS_2)  >= 0))
#define IS_MOVE8_LEGAL (((X_MINUS_1) >= 0) && ((X_MINUS_1) <= 7)) && (((Y_MINUS_2) >= 0) && ((Y_MINUS_2) <= 7))

typedef struct Chess_Piece_Location{
	U_Int8 x;
	U_Int8 y;
}Chess_Piece_Location;

/*Structure to hold location of particular piece on the board...*/
Chess_Piece_Location White_Knight_1_Location;

U_Int8 NEW_X (U_Int8 x, U_Int8 moveNumber);

U_Int8 NEW_Y (U_Int8 y, U_Int8 moveNumber);

U_Int8 Sort_Array(U_Int8 Array[8]);

/*Returns the value at a given offset location*/
U_Int8 BoardValue_XY_offset(U_Int8 x, U_Int8 y, U_Int8 moveNumber);

/*Returns the value at a given location*/
U_Int8 BoardValue_XY(U_Int8 x, U_Int8);

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
