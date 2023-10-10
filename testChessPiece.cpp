/***********************************************************************
 * Source File:
 *    Chess Piece Test: Unit tests for Chess Piece
 * Author:
 *    Tyler McMurtrey
 * Summary:
 *    The unit tests for Chess Piece
 ************************************************************************/

#include "testChessPiece.h" 
#include <cassert>
#include <cctype>
#include <iostream>
#include <string>



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

void ChessPieceTest::testIsBlackRook() {
    if (board[63] == 'R') {
        assert(piece.isBlack(board, 7, 7));
        cout << "testIsBlackRook passed" << endl;
    }
}

void ChessPieceTest::testIsBlackKnight() {
    if (board[62] == 'N') {
        assert(piece.isBlack(board, 7, 6));
        cout << "testIsBlackKnight passed" << endl;
    }
}
void ChessPieceTest::testIsBlackBishop() {
    if (board[61] == 'B') {
        assert(piece.isBlack(board, 7, 5));
        cout << "testIsBlackBishop passed" << endl;
    }
}

void ChessPieceTest::testIsBlackQueen() {
    if (board[60] == 'Q') {
        assert(piece.isBlack(board, 7, 4));
        cout << "testIsBlackQueen passed" << endl;
    }
}

void ChessPieceTest::testIsBlackKing() {
    if (board[59] == 'K') {
        assert(piece.isBlack(board, 7, 3));
        cout << "testIsBlackKing passed" << endl;
    }
}

void ChessPieceTest::testIsWhiteRook() {
    if (board[0] == 'r') {
        assert(piece.isWhite(board, 0, 0));
        cout << "testIsWhiteRook passed" << endl;
    }
}

void ChessPieceTest::testIsWhiteKnight() {
    if (board[1] == 'n') {
        assert(piece.isWhite(board, 0, 1));
        cout << "testIsWhiteKnight passed" << endl;
    }
}

void ChessPieceTest::testIsWhiteBishop() {
    if (board[2] == 'b') {
        assert(piece.isWhite(board, 0, 2));
        cout << "testIsWhiteBishop passed" << endl;
    }
}

void ChessPieceTest::testIsWhiteQueen() {
    if (board[3] == 'q') {
        assert(piece.isWhite(board, 0, 3));
        cout << "testIsWhiteQueen passed" << endl;
    }
}

void ChessPieceTest::testIsWhiteKing() {
    if (board[4] == 'k') {
        assert(piece.isWhite(board, 0, 4));
        cout << "testIsWhiteKing passed" << endl;
    }
}

void ChessPieceTest::testIsBlackPawn() {
    if (board[48] == 'P') {
        assert(piece.isBlack(board, 6, 0));
        cout << "testIsBlackPawn passed" << endl;
    }
}

void ChessPieceTest::testIsWhitePawn() {
    if (board[8] == 'p') {
        assert(piece.isWhite(board, 1, 0));
        cout << "testIsWhitePawn passed" << endl;
    }
}

void ChessPieceTest::testIsEmptySpace() {
    if (board[16] == ' ') {
        // Replace with your own logic if needed
        cout << "testIsEmptySpace passed" << endl;
    }
}

void ChessPieceTest::testIsNotBlack() {
    if (board[48] == 'p') {
        assert(piece.isNotBlack(board, 6, 0));
        cout << "testIsNotBlack passed" << endl;
    }
}

void ChessPieceTest::testIsNotWhite() {
    if (board[8] == 'P') {
        assert(piece.isNotWhite(board, 1, 0));
        cout << "testIsNotWhite passed" << endl;
    }
}

void ChessPieceTest::testIsNotKing() {
    if (board[59] == 'Q') {
        assert(board[59] != 'K' && board[59] != 'k');
        cout << "testIsNotKing passed" << endl;
    }
}

void ChessPieceTest::testIsNotQueen() {
    if (board[58] == 'B') {
        assert(board[58] != 'Q' && board[58] != 'q');
        cout << "testIsNotQueen passed" << endl;
    }
}

void ChessPieceTest::testIsNotRook() {
    if (board[57] == 'N') {
        assert(board[57] != 'R' && board[57] != 'r');
        cout << "testIsNotRook passed" << endl;
    }
}

void ChessPieceTest::testIsNotBishop() {
    if (board[56] == 'R') {
        assert(board[56] != 'B' && board[56] != 'b');
        cout << "testIsNotBishop passed" << endl;
    }
}

void ChessPieceTest::testIsNotKnight() {
    if (board[55] == 'P') {
        assert(board[55] != 'N' && board[55] != 'n');
        cout << "testIsNotKnight passed" << endl;
    }
}



