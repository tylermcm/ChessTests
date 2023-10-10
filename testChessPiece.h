
/***********************************************************************
 * Header File:
 *    Chess Piece Test: Unit tests for Chess Piece
 * Author:
 *    Tyler McMurtrey
 * Summary:
 *    The unit tests for Chess Piece
 ************************************************************************/

#pragma once
#include "piece.h"

/***************************************************
 * CHESS PIECE TEST
 * Test the Chess Piece class
 ***************************************************/
class ChessPieceTest
{
public:
    Piece piece;
    void run()
	{
        testIsBlackRook();
        testIsBlackKnight();
        testIsBlackBishop();
        testIsBlackQueen();
        testIsBlackKing();
        testIsWhiteRook();
        testIsWhiteKnight();
        testIsWhiteBishop();
        testIsWhiteQueen();
        testIsWhiteKing();
        testIsBlackPawn();
        testIsWhitePawn();
        testIsEmptySpace();
        testIsNotBlack();
        testIsNotWhite();
        testIsNotKing();
        testIsNotQueen();
        testIsNotRook();
        testIsNotBishop();
        testIsNotKnight();
    }

private:
    void testIsBlackRook();
    void testIsBlackKnight();
    void testIsBlackBishop();
    void testIsBlackQueen();
    void testIsBlackKing();
    void testIsWhiteRook();
    void testIsWhiteKnight();
    void testIsWhiteBishop();
    void testIsWhiteQueen();
    void testIsWhiteKing();
    void testIsBlackPawn();
    void testIsWhitePawn();
    void testIsEmptySpace();
    void testIsNotBlack();
    void testIsNotWhite();
    void testIsNotKing();
    void testIsNotQueen();
    void testIsNotRook();
    void testIsNotBishop();
    void testIsNotKnight();


};


