#ifndef CHESSBOARDLIB_H
#define CHESSBOARDLIB_H

#include <stdio.h>

typedef unsigned char U_Int8;

/*Board Size*/
#define SeedBoardSize 8U /*standard 8x8 chess board*/
#define BoardSize SeedBoardSize*SeedBoardSize
#define ROW SeedBoardSize
#define COL SeedBoardSize

/*structure for the chess piece location*/
typedef struct Chess_Piece_Location{
	U_Int8 x;
	U_Int8 y;
}Chess_Piece_Location;

typedef struct Pieces{
	Chess_Piece_Location Pawn_1;
	Chess_Piece_Location Pawn_2;
	Chess_Piece_Location Pawn_3;
	Chess_Piece_Location Pawn_4;
	Chess_Piece_Location Pawn_5;
	Chess_Piece_Location Pawn_6;
	Chess_Piece_Location Pawn_7;
	Chess_Piece_Location Pawn_8;
	Chess_Piece_Location Knight_1;
	Chess_Piece_Location Knight_2;
	Chess_Piece_Location Bishop_1;
    Chess_Piece_Location Bishop_2;
	Chess_Piece_Location Rook_1;
    Chess_Piece_Location Rook_2;
	Chess_Piece_Location Queen;
    Chess_Piece_Location King;
}Pieces;

typedef struct Chess_Set{
	Pieces Chess_White;
	Pieces Chess_Black;
}Chess_Set;

/*Structure to hold the location of the pieces of a chess set*/
Chess_Set My_Chess_Set;

/*chess pieces from least important to most important*/
enum ChessPieces {NoPiece,PAWN,KNIGHT,BISHOP,ROOK,QUEEN,KING};

/*Chess board*/
U_Int8 Board[ROW][COL];

/*new x for knight move*/
U_Int8 NEW_X_Knight (U_Int8 x, U_Int8 moveNumber);
/*new y for knight move*/
U_Int8 NEW_Y_Knight (U_Int8 y, U_Int8 moveNumber);
/*move a chess piece*/
void Make_Move(Chess_Set *My_Chess_Set,U_Int8 PieceType,U_Int8 move,U_Int8 marker);
/*Returns the value at a given location*/
U_Int8 BoardValue_XY(U_Int8 x, U_Int8 y);
/*Display the board in the console*/
void DispBoard (void);
/*Write the board to a txt file*/
void WriteToFile (char Location[]);
/*Generates initial empty board with zeros*/
void ClearBoard (void);

#endif /* */
