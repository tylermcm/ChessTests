#include "piece.h"
set<int> Piece::getPossibleMoves(const char* board, int location) {
   set <int> possible;

   // return the empty set if there simply are no possible moves
   if (location < 0 || location >= 64 || board[location] == ' ')
      return possible;
   int row = location / 8;  // current location row
   int col = location % 8;  // current location column
   int r;                   // the row we are checking
   int c;                   // the column we are checking
   bool amBlack = isBlack(board, row, col);

   //
   // PAWN
   //
   if (board[location] == 'P')
   {
      c = col;
      r = row - 2;
      if (row == 6 && board[r * 8 + c] == ' ' && board[(r + 1) * 8 + c] == ' ')
         possible.insert(r * 8 + c);  // forward two blank spaces
      r = row - 1;
      if (r >= 0 && board[r * 8 + c] == ' ')
         possible.insert(r * 8 + c);  // forward one black space
      c = col - 1;
      if (isWhite(board, r, c))
         possible.insert(r * 8 + c);    // attack left
      c = col + 1;
      if (isWhite(board, r, c))
         possible.insert(r * 8 + c);    // attack right
      r = row;
      if (isWhite(board, r, c) && board[(r + 1) * 8 + c] == ' ')
          possible.insert((r - 1) * 8 + c); //enpassant right
      c = col - 1;
      if (isWhite(board, r, c) && board[(r + 1) * 8 + c] == ' ')
          possible.insert((r - 1) * 8 + c); //enpassant left
      // what about en-passant and pawn promotion
   }
   if (board[location] == 'p')
   {
      c = col;
      r = row + 2;
      if (row == 1 && board[r * 8 + c] == ' ' && board[(r - 1) * 8 + c] == ' ')
         possible.insert(r * 8 + c);  // forward two blank spaces
      r = row + 1;
      if (r < 8 && board[r * 8 + c] == ' ')
         possible.insert(r * 8 + c);    // forward one blank space
      c = col - 1;
      if (isBlack(board, r, c))
         possible.insert(r * 8 + c);      // attack left
      c = col + 1;
      if (isBlack(board, r, c))
         possible.insert(r * 8 + c);      // attack right
      r = row;
      if (isBlack(board, r, c) && board[(r + 1) * 8 + c] == ' ')
          possible.insert((r + 1) * 8 + c); //enpassant right
      c = col - 1;
      if (isBlack(board, r, c) && board[(r + 1) * 8 + c] == ' ')
          possible.insert((r + 1) * 8 + c); //enpassant left
      // what about en-passant and pawn promotion
   }

   //
   // KNIGHT
   //
   if (board[location] == 'N' || board[location] == 'n')
   {
      RC moves[8] =
      {
               {-1,  2}, { 1,  2},
      {-2,  1},                    { 2,  1},
      {-2, -1},                    { 2, -1},
               {-1, -2}, { 1, -2}
      };
      for (int i = 0; i < 8; i++)
      {
         r = row + moves[i].row;
         c = col + moves[i].col;
         if (amBlack && isNotBlack(board, r, c))
            possible.insert(r * 8 + c);
         if (!amBlack && isNotWhite(board, r, c))
            possible.insert(r * 8 + c);
      }
   }

   //
   // KING
   //
   if (board[location] == 'K' || board[location] == 'k')
   {
      RC moves[10] =
      {
         {-1,  1}, {0,  1}, {1,  1},
         {-1,  0},          {1,  0},
         {-1, -1}, {0, -1}, {1, -1}
      };
      for (int i = 0; i < 8; i++)
      {
         r = row + moves[i].row;
         c = col + moves[i].col;
         //while (location == 4 || location = 60)
         if (amBlack && isNotBlack(board, r, c))
            possible.insert(r * 8 + c);
         if (!amBlack && isNotWhite(board, r, c))
            possible.insert(r * 8 + c);
      }
      
      if (location == 4)
      {
          if (board[0] == 'r')
          {
              while (col > 2 && board[row * 8 + col - 1] == ' ')
              {
                  col -= 1;
              }
              if (col == 2)
                  possible.insert(row * 8 + col);
          }
          else if (board[7] == 'r')
          {
              while (col < 6 && board[row * 8 + col] == ' ')
              {
                  col += 1;
              }
              if (col == 6)
                  possible.insert(row * 8 + col);
          }
      }
      else if (location == 60)
      {
          if (board[56] == 'R')
          {
              while (col > 58 && board[row * 8 + col] == ' ')
              {
                  col -= 1;
              }
              if (col == 58)
                  possible.insert(row * 8 + col);
          }
          else if (board[63] == 'R')
          {
              while (col < 62 && board[row * 8 + col] == ' ')
              {
                  col += 1;
              }
              if (col == 62)
                  possible.insert(row * 8 + col);
          }
      }
      // what about castling?
   }

   //
   // QUEEN
   //
   if (board[location] == 'Q' || board[location] == 'q')
   {
      RC moves[8] =
      {
         {-1,  1}, {0,  1}, {1,  1},
         {-1,  0},          {1,  0},
         {-1, -1}, {0, -1}, {1, -1}
      };
      for (int i = 0; i < 8; i++)
      {
         r = row + moves[i].row;
         c = col + moves[i].col;
         while (r >= 0 && r < 8 && c >= 0 && c < 8 &&
            board[r * 8 + c] == ' ')
         {
            possible.insert(r * 8 + c);
            r += moves[i].row;
            c += moves[i].col;
         }
         if (amBlack && isNotBlack(board, r, c))
            possible.insert(r * 8 + c);
         if (!amBlack && isNotWhite(board, r, c))
            possible.insert(r * 8 + c);
      }
   }

   //
   // ROOK
   //
   if (board[location] == 'R' || board[location] == 'r')
   {
      RC moves[4] =
      {
                  {0,  1},
         {-1, 0},         {1, 0},
                  {0, -1}
      };
      for (int i = 0; i < 4; i++)
      {
         r = row + moves[i].row;
         c = col + moves[i].col;
         while (r >= 0 && r < 8 && c >= 0 && c < 8 &&
            board[r * 8 + c] == ' ')
         {
            possible.insert(r * 8 + c);
            r += moves[i].row;
            c += moves[i].col;
         }
         if (amBlack && isNotBlack(board, r, c))
            possible.insert(r * 8 + c);
         if (!amBlack && isNotWhite(board, r, c))
            possible.insert(r * 8 + c);
      }
   }

   //
   // BISHOP
   //
   if (board[location] == 'B' || board[location] == 'b')
   {
      RC moves[4] =
      {
         {-1,  1}, {1,  1},
         {-1, -1}, {1, -1}
      };
      for (int i = 0; i < 4; i++)
      {
         r = row + moves[i].row;
         c = col + moves[i].col;
         while (r >= 0 && r < 8 && c >= 0 && c < 8 &&
            board[r * 8 + c] == ' ')
         {
            possible.insert(r * 8 + c);
            r += moves[i].row;
            c += moves[i].col;
         }
         if (amBlack && isNotBlack(board, r, c))
            possible.insert(r * 8 + c);
         if (!amBlack && isNotWhite(board, r, c))
            possible.insert(r * 8 + c);
      }
   }

   return possible;
}

bool Piece::isBlack(const char* board, int row, int col) {
   if (row < 0 || row >= 8 || col < 0 || col >= 8)
      return false;
   char piece = board[row * 8 + col];

   return (piece >= 'A' && piece <= 'Z');

}

bool Piece::isWhite(const char* board, int row, int col) {
   if (row < 0 || row >= 8 || col < 0 || col >= 8)
      return false;
   char piece = board[row * 8 + col];

   return (piece >= 'a' && piece <= 'z');
}

bool Piece::isNotBlack(const char* board, int row, int col) {
   if (row < 0 || row >= 8 || col < 0 || col >= 8)
      return false;
   char piece = board[row * 8 + col];

   return piece == ' ' || (piece >= 'a' && piece <= 'z');
}

bool Piece::isNotWhite(const char* board, int row, int col) {
   if (row < 0 || row >= 8 || col < 0 || col >= 8)
      return false;
   char piece = board[row * 8 + col];

   return piece == ' ' || (piece >= 'A' && piece <= 'Z');
}