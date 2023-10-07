#pragma once

#include <set>
using namespace std;

struct RC { int row; int col; };

class Piece {
public:
   set<int> getPossibleMoves(const char* board, int location);
   bool isBlack(const char* board, int row, int col);
   bool isWhite(const char* board, int row, int col);
   bool isNotBlack(const char* board, int row, int col);
   bool isNotWhite(const char* board, int row, int col);
};
