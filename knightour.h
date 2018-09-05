#ifndef KNIGHTOUR_H
#define KNIGHTOUR_H

#include <stdio.h>

typedef unsigned char bool;

#define true 1
#define false 1

//Board Size
#define ROW 8
#define COL 8

//Move Restriction conditions
#define IS_MOVE1_LEGAL (x + 2) <= 7 && (y + 1) <= 7
#define IS_MOVE2_LEGAL (x + 2) <= 7 && (y - 1) >= 0
#define IS_MOVE3_LEGAL (x + 1) <= 7 && (y + 2) <= 7
#define IS_MOVE4_LEGAL (x + 1) <= 7 && (y - 2) >= 0
#define IS_MOVE5_LEGAL (x - 2) >= 0 && (y + 1) <= 7
#define IS_MOVE6_LEGAL (x - 2) >= 0 && (y - 1) >= 0
#define IS_MOVE7_LEGAL (x - 1) >= 0 && (y + 2) <= 7
#define IS_MOVE8_LEGAL (x - 1) >= 0 && (y - 2) >= 0

//Enumerator for the knight moves
enum Knight_Moves {NULLmove, Move1, Move2, Move3, Move4, Move5, Move6, Move7, Move8};

typedef struct Chess_Piece_Location{
	int x;
	int y;
}Chess_Piece_Location;

int X (int x, int moveNumber);

int Y (int y, int moveNumber);

int SelectData_INDEX(int Array[]);

bool MOVE1_OK(int x, int y, int MoveAvailable);

bool MOVE2_OK(int x, int y, int MoveAvailable);

bool MOVE3_OK(int x, int y, int MoveAvailable);

bool MOVE4_OK(int x, int y, int MoveAvailable);

bool MOVE5_OK(int x, int y, int MoveAvailable);

bool MOVE6_OK(int x, int y, int MoveAvailable);

bool MOVE7_OK(int x, int y, int MoveAvailable);

bool MOVE8_OK(int x, int y, int MoveAvailable);

//Returns the value at a given location
int BoardValue_XY(int x, int y, int moveNumber, int Board[ROW][COL]);

//returns how many moves for the Knight are available at a given location in the board
int DetermineMoves(int x, int y,int Board[ROW][COL]);

//Display the board in the console
void DispBoard (int Board[ROW][COL]);

//Write the board to a txt file
void WriteToFile (int Board[ROW][COL], char Location[]);

//Genereates initial empty board with zeros
void ClearBoard (int Board[ROW][COL]);

//This is a prototype to generate all moves available at the initial stage of the board. 
//(No necessary for the solution)
void CreateMoves (int Board[ROW][COL]);

//--------------------------------------------------------------------------------------------
//Logic for the KnightTour solution-----------------------------------------------------------
//returns next move based on how many moves for the knight are available at a given position
int NextMove(int x,int y, int Board[ROW][COL]);

//PerformMove(<int x>, <int y>, <int MOVE ID: 1,2,3,4,5,6,7,8>, <int Marker>, <int BOARD[][]>)
void PerformMove(int x, int y, int moveNumber, int marker, int Board[ROW][COL]);
//--------------------------------------------------------------------------------------------

#endif /* */