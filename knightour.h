#ifndef KNIGHTOUR_H
#define KNIGHTOUR_H

#include "chessboardlib.h"

/*sort the array for best move*/
U_Int8 Sort_Array(U_Int8 Array[8U]);
/*Returns the value at a given offset location*/
U_Int8 BoardValue_XY_offset(U_Int8 x, U_Int8 y, U_Int8 moveNumber);
/*returns how many moves for the Knight are available at a given location in the board*/
U_Int8 DetermineMoves(U_Int8 x, U_Int8 y);
/*solve the knight tour*/
void Solve_KnightTour (U_Int8 x, U_Int8 y, U_Int8 Display_flag);
/*returns next move based on how many moves for the knight are available at a given position*/
U_Int8 NextMove(U_Int8 x,U_Int8 y);

#endif /* */
