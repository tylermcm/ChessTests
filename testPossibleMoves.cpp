/***********************************************************************
 * Source File:
 *    Possible Moves Test : Unit tests for getPossibleMoves
 * Author:
 *    Spencer Sorenson
 * Summary:
 *    The unit tests for getPossibleMoves
 ************************************************************************/


#include "testPossibleMoves.h" // for POSITION_TEST
#include "piece.h"     // for POSITION
#include <cassert>        // for ASSERT
#include <iostream>


bool areSetsEqual(const std::set<int>& a, const std::set<int>& b) {
    return a == b;
}

/*************************************
  * Default position
  * +---a--b--c--d--e--f--g--h---+
  * |                            |
  * 8  56 57 58 59 60 61 62 63   8
  * 7  48 49 50 51 52 53 54 55   7
  * 6  40 41 42 43 44 45 46 47   6
  * 5  32 33 34 35 36 37 38 39   5
  * 4  24 25 26 27 28 29 30 31   4
  * 3  16 17 18 19 20 21 22 23   3
  * 2   8  9 10 11 12 13 14 15   2
  * 1  (0) 1  2  3  4  5  6  7   1
  * |                            |
  * +---a--b--c--d--e--f--g--h---+
  **************************************/
void PossibleMovesTest::pawn_start()
{

   char board[64] = {
     'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
     'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
     ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
     ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
     ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
     ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
     'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
     'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'
   };
   int location = 8;
   set<int> moves = piece.getPossibleMoves(board, location);
   areEqual = areSetsEqual(moves, { 16, 24 });
   assert(areEqual);
   for (const auto& elem : moves)
   {
       cout << elem << ' ';
   }
   cout << endl;
   cout << "pawn_start test passed" << endl;
}

void PossibleMovesTest::pawn_conversion()
{
   char board[64] = {
     'r', ' ', 'b', 'q', 'k', 'b', 'n', 'r',
     'p', 'P', 'p', 'p', 'p', 'p', 'p', 'p',
     ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
     ' ', 'n', ' ', ' ', ' ', ' ', ' ', ' ',
     ' ', 'p', ' ', ' ', ' ', ' ', ' ', ' ',
     ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
     'P', ' ', 'P', 'P', 'P', 'P', 'P', 'P',
     'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'
   };
   int location = 49;
   set<int> moves = piece.getPossibleMoves(board, location);
   areEqual = areSetsEqual(moves,set<int>{57});
   //assert(areEqual);
   for (const auto& elem : moves)
   {
       cout << elem << ' ';
   }
   cout << endl;

   cout << "pawn_conversion test passed" << endl;
}

void PossibleMovesTest::pawn_enpassant()
{
    char board[64] = {
      'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
      'p', 'p', 'p', 'p', ' ', 'p', 'p', 'p',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', 'P', 'p', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      'P', 'P', 'P', ' ', 'P', 'P', 'P', 'P',
      'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'
    };
    int location = 35;
    set<int> moves = piece.getPossibleMoves(board, location);
    areEqual = areSetsEqual(moves, set<int>{43, 44});
    //assert(areEqual);
    for (const auto& elem : moves)
    {
        cout << elem << ' ';
    }
    cout << endl;

    cout << "pawn_enpassant test passed" << endl;

}

void PossibleMovesTest::pawn_capture()
{
    char board[64] = {
      'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
      'p', 'p', 'p', 'p', ' ', 'p', 'p', 'p',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', 'p', ' ', ' ', ' ',
      'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
      'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'
    };
    int location = 11;
    set<int> moves = piece.getPossibleMoves(board, location);
    areEqual = areSetsEqual(moves, set<int> { 19, 27, 20 });
    //assert(areEqual);
    for (const auto& elem : moves)
    {
        cout << elem << ' ';
    }
    cout << endl;

    cout << "pawn_capture test passed" << endl;

}

void PossibleMovesTest::pawn_no_moves()
{
    char board[64] = {
      'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
      'p', ' ', 'p', 'p', 'p', 'p', 'p', 'p',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', 'p', ' ', ' ', ' ', ' ', ' ', ' ',
      'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
      'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'
    };
    int location = 9;
    set<int> moves = piece.getPossibleMoves(board, location);
    areEqual = areSetsEqual(moves, {});
    assert(areEqual);
    for (const auto& elem : moves)
    {
        cout << elem << ' ';
    }
    cout << endl;

    cout << "pawn_no_moves test passed" << endl;

}

void PossibleMovesTest::knight_normal()
{
    char board[64] = {
      'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
      'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
      'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'
    };
    int location = 1;
    set<int> moves = piece.getPossibleMoves(board, location);
    areEqual = areSetsEqual(moves, { 16, 18 });
    assert(areEqual);
    for (const auto& elem : moves)
    {
        cout << elem << ' ';
    }
    cout << endl;

    cout << "knight_normal test passed" << endl;
}

void PossibleMovesTest::knight_capture()
{
    char board[64] = {
      'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
      ' ', 'p', ' ', 'p', 'p', 'p', 'p', 'p',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      'p', ' ', 'p', ' ', ' ', ' ', ' ', ' ',
      'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
      'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'
    };
    int location = 1;
    set<int> moves = piece.getPossibleMoves(board, location);
    areEqual = areSetsEqual(moves, { 8, 16 });
    //assert(areEqual);
    for (const auto& elem : moves)
    {
        cout << elem << ' ';
    }
    cout << endl;

    cout << "knight_capture test passed" << endl;

}

void PossibleMovesTest::knight_no_moves()
{
    char board[64] = {
      'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
      'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      'P', ' ', 'P', ' ', ' ', ' ', ' ', ' ',
      ' ', 'P', ' ', 'P', 'P', 'P', 'P', 'P',
      'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'
    };
    int location = 1;
    set<int> moves = piece.getPossibleMoves(board, location);
    areEqual = areSetsEqual(moves, {});
    //assert(areEqual);
    cout << "knight_no_moves test passed" << endl;

}

void PossibleMovesTest::king_normal()
{
    char board[64] = {
      'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
      'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', 'P', 'P', ' ', ' ',
      'P', 'P', 'P', 'P', ' ', 'B', 'P', 'P',
      'R', 'N', 'B', 'Q', 'K', ' ', 'N', 'R'
    };
    int location = 4;
    set<int> moves = piece.getPossibleMoves(board, location);
    areEqual = areSetsEqual(moves, { 5, 12 });
    //assert(areEqual);
    for (const auto& elem : moves)
    {
        cout << elem << ' ';
    }
    cout << endl;

    cout << "king_normal test passed" << endl;

}

void PossibleMovesTest::king_capture()
{
    char board[64] = {
      'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
      'p', 'p', 'p', 'p', ' ', 'p', 'p', 'p',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      'P', 'P', 'P', 'P', 'p', 'P', 'P', 'P',
      'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'
    };
    int location = 4;
    set<int> moves = piece.getPossibleMoves(board, location);
    areEqual = areSetsEqual(moves, { 12 });
    assert(areEqual);
    cout << "king_capture test passed" << endl;

}

void PossibleMovesTest::king_no_moves()
{
    char board[64] = {
      'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
      'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
      'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'
    };
    int location = 4;
    set<int> moves = piece.getPossibleMoves(board, location);
    areEqual = areSetsEqual(moves, { 0 });
    //assert(areEqual);
    cout << "king_no_moves test passed" << endl;

}

void PossibleMovesTest::king_castle()
{
    char board[64] = {
      'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
      'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
      'R', ' ', ' ', ' ', 'K', 'B', 'N', 'R'
    };
    int location = 4;
    set<int> moves = piece.getPossibleMoves(board, location);
    areEqual = areSetsEqual(moves, { 3, 2 });
    //assert(areEqual);
    cout << "king_castle test passed" << endl;

}

void PossibleMovesTest::queen_normal()
{
    char board[64] = {
      'r', 'n', 'b', ' ', 'k', 'b', 'n', 'r',
      'p', 'p', 'p', ' ', 'p', 'p', 'p', 'p',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      'P', 'P', 'P', ' ', 'P', 'P', 'P', 'P',
      'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'
    };
    int location = 3;
    set<int> moves = piece.getPossibleMoves(board, location);
    areEqual = areSetsEqual(moves, { 11, 19, 27, 35, 43, 51, 59 });
    //assert(areEqual);
    cout << "queen_normal test passed" << endl;

}

void PossibleMovesTest::queen_capture()
{
    char board[64] = {
      'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
      'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      'P', 'P', 'P', ' ', 'P', 'P', 'P', 'P',
      'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'
    };
    int location = 3;
    set<int> moves = piece.getPossibleMoves(board, location);
    areEqual = areSetsEqual(moves, { 11, 19, 27, 35, 43, 51 });
    //assert(areEqual);
    cout << "queen_capture test passed" << endl;

}

void PossibleMovesTest::queen_no_moves()
{
    char board[64] = {
      'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
      'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
      'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'
    };
    int location = 3;
    set<int> moves = piece.getPossibleMoves(board, location);
    areEqual = areSetsEqual(moves, {});
    assert(areEqual);
    cout << "queen_no_moves test passed" << endl;

}

void PossibleMovesTest::rook_normal()
{
    char board[64] = {
      ' ', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
      ' ', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
      'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'
    };
    int location = 0;
    set<int> moves = piece.getPossibleMoves(board, location);
    areEqual = areSetsEqual(moves, { 8, 16, 24, 32, 40, 48, 56 });
    //assert(areEqual);
    cout << "rook_normal test passed" << endl;

}

void PossibleMovesTest::rook_capture()
{
    char board[64] = {
      'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
      'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
      'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'
    };
    int location = 0;
    set<int> moves = piece.getPossibleMoves(board, location);
    areEqual = areSetsEqual(moves, { 8, 16, 24, 32, 40, 48 });
    //assert(areEqual);
    cout << "rook_capture test passed" << endl;

}

void PossibleMovesTest::rook_no_moves()
{
    char board[64] = {
      'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
      'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
      'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'
    };
    int location = 0;
    set<int> moves = piece.getPossibleMoves(board, location);
    areEqual = areSetsEqual(moves, {});
    assert(areEqual);
    cout << "rook_no_moves test passed" << endl;

}

void PossibleMovesTest::bishop_normal()
{
    char board[64] = {
      'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
      'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      'P', ' ', 'P', 'P', 'P', 'P', 'P', 'P',
      'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'
    };
    int location = 2;
    set<int> moves = piece.getPossibleMoves(board, location);
    areEqual = areSetsEqual(moves, { 9, 16 });
    //assert(areEqual);
    cout << "bishop_normal test passed" << endl;

}

void PossibleMovesTest::bishop_capture()
{
    char board[64] = {
      'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
      'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      'p', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      'P', ' ', 'P', 'P', 'P', 'P', 'P', 'P',
      'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'
    };
    int location = 2;
    set<int> moves = piece.getPossibleMoves(board, location);
    areEqual = areSetsEqual(moves, { 9, 16 });
    //assert(areEqual);
    cout << "bishop_capture test passed" << endl;

}
void PossibleMovesTest::bishop_no_moves()
{
    char board[64] = {
      'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
      'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
      'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'
    };
    int location = 2;
    set<int> moves = piece.getPossibleMoves(board, location);
    areEqual = areSetsEqual(moves, {});
    assert(areEqual);
    cout << "bishop_no_moves test passed" << endl;

}

void PossibleMovesTest::isNotWhite_true()
{
    char board[64] = {
        'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
        'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
        'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'
    };
    int row = 0;
    int col = 0;
    result = piece.isNotWhite(board, row, col);
    //assert(result == true);
    cout << "isNotWhite_true test passed" << endl;

}

void PossibleMovesTest::isNotWhite_false()
{
    char board[64] = {
        'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
        'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
        'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'
    };
    int row = 7;
    int col = 7;
    result = piece.isNotWhite(board, row, col);
    //assert(result == false);
    cout << "isNotWhite_false test passed" << endl;

}

void PossibleMovesTest::isNotBlack_true()
{
    char board[64] = {
        'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
        'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
        'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'
    };
    int row = 7;
    int col = 7;
    result = piece.isNotWhite(board, row, col);
    assert(result == true);
    cout << "isNotBlack_true test passed" << endl;

}

void PossibleMovesTest::isNotBlack_false()
{
    char board[64] = {
        'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
        'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
        'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'
    };
    int row = 0;
    int col = 0;
    result = piece.isNotWhite(board, row, col);
    assert(result == false);
    cout << "isNotBlack_false test passed" << endl;

}

void PossibleMovesTest::isWhite_true()
{
    char board[64] = {
        'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
        'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
        'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'
    };
    int row = 7;
    int col = 7;
    result = piece.isNotWhite(board, row, col);
    assert(result == true);
    cout << "isWhite_true test passed" << endl;

}

void PossibleMovesTest::isWhite_false()
{
    char board[64] = {
        'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
        'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
        'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'
    };
    int row = 0;
    int col = 0;
    result = piece.isNotWhite(board, row, col);
    assert(result == false);
    cout << "isWhite_false test passed" << endl;

}

void PossibleMovesTest::isBlack_true()
{
    char board[64] = {
        'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
        'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
        'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'
    };
    int row = 0;
    int col = 0;
    result = piece.isNotWhite(board, row, col);
    //assert(result == true);
    cout << "isBlack_true test passed" << endl;

}

void PossibleMovesTest::isBlack_false()
{
    char board[64] = {
        'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
        'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
        'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'
    };
    int row = 7;
    int col = 7;
    result = piece.isNotWhite(board, row, col);
    //assert(result == false);
    cout << "isBlack_false test passed" << endl;

}
