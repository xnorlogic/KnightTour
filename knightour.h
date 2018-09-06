#ifndef KNIGHTOUR_H
#define KNIGHTOUR_H

#include <stdio.h>

typedef unsigned char bool;
typedef unsigned char U_Int8;

#define true 1
#define false 1

//Board Size
#define ROW 8
#define COL 8

/*Chess board*/
int Board[ROW][COL];

/*knight xy move combination*/
#define X_PLUS_2 x + 2
#define X_PLUS_1 x + 1
#define X_MINUS_2 x - 2
#define X_MINUS_1 x - 1
#define Y_PLUS_2 y + 2
#define Y_PLUS_1 y + 1
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
 
//Enumerator for the knight moves
enum Knight_Moves {NULLmove, Move1, Move2, Move3, Move4, Move5, Move6, Move7, Move8};

typedef struct Chess_Piece_Location{
	int x;
	int y;
}Chess_Piece_Location;

U_Int8 NEW_X (U_Int8 x, U_Int8 moveNumber);

U_Int8 NEW_Y (U_Int8 y, U_Int8 moveNumber);

U_Int8 Sort_Array(U_Int8 Array[8]);

bool MOVE1_OK(int x, int y, int MoveAvailable);

bool MOVE2_OK(int x, int y, int MoveAvailable);

bool MOVE3_OK(int x, int y, int MoveAvailable);

bool MOVE4_OK(int x, int y, int MoveAvailable);

bool MOVE5_OK(int x, int y, int MoveAvailable);

bool MOVE6_OK(int x, int y, int MoveAvailable);

bool MOVE7_OK(int x, int y, int MoveAvailable);

bool MOVE8_OK(int x, int y, int MoveAvailable);

//Returns the value at a given location
int BoardValue_XY(int x, int y, int moveNumber);

//returns how many moves for the Knight are available at a given location in the board
U_Int8 DetermineMoves(U_Int8 x, U_Int8 y);

//Display the board in the console
void DispBoard (void);

//Write the board to a txt file
void WriteToFile (char Location[]);

//Genereates initial empty board with zeros
void ClearBoard (void);

//This is a prototype to generate all moves available at the initial stage of the board. 
//(No necessary for the solution)
void CreateMoves (void);

//--------------------------------------------------------------------------------------------
//Logic for the KnightTour solution-----------------------------------------------------------
//returns next move based on how many moves for the knight are available at a given position
U_Int8 NextMove(U_Int8 x,U_Int8 y);

//PerformMove(<int x>, <int y>, <int MOVE ID: 1,2,3,4,5,6,7,8>, <int Marker>, <int BOARD[][]>)
void PerformMove(int x, int y, int moveNumber, int marker);
//--------------------------------------------------------------------------------------------

#endif /* */