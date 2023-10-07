/***********************************************************************
 * Header File:
 *    Possible Moves Test : Unit tests for getPossibleMoves
 * Author:
 *    Spencer Sorenson
 * Summary:
 *    The unit tests for getPossibleMoves
 ************************************************************************/

#pragma once
#include <set>

#include "piece.h"


/***************************************************
  * POSSIBLE MOVES TEST
  * Test the getPossibleMoves class
  ***************************************************/
class PossibleMovesTest
{
public:
    bool result;
    Piece piece;
    bool areEqual;
    bool areSetsEqual(const std::set<int>& a, const std::set<int>& b) {
        return a == b;
    }
    void run()
    {
        // get possible
        pawn_start();
        pawn_conversion();
        pawn_enpassant();
        pawn_capture();
        pawn_no_moves();
        knight_normal();
        knight_capture();
        knight_no_moves();
        king_normal();
        king_capture();
        king_no_moves();
        king_castle();
        queen_normal();
        queen_capture();
        queen_no_moves();
        rook_normal();
        rook_capture();
        rook_no_moves();
        bishop_normal();
        bishop_capture();
        bishop_no_moves();


        // get bool
        isNotWhite_true();
        isNotWhite_false();
        isNotBlack_true();
        isNotBlack_false();
        isWhite_true();
        isWhite_false();
        isBlack_true();
        isBlack_false();
    }



private:
    void pawn_start();
    void pawn_conversion();
    void pawn_enpassant();
    void pawn_capture();
    void pawn_no_moves();
    void knight_normal();
    void knight_capture();
    void knight_no_moves();
    void king_normal();
    void king_capture();
    void king_no_moves();
    void king_castle();
    void queen_normal();
    void queen_capture();
    void queen_no_moves();
    void rook_normal();
    void rook_capture();
    void rook_no_moves();
    void bishop_normal();
    void bishop_capture();
    void bishop_no_moves();

    void isNotWhite_true();
    void isNotWhite_false();
    void isNotBlack_true();
    void isNotBlack_false();
    void isWhite_true();
    void isWhite_false();
    void isBlack_true();
    void isBlack_false();

};

