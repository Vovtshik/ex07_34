/*ex07_34.cpp*/

#include <iostream>
using std::cout;
using std::endl;

#include <cstdlib>
using std::rand;
using std::srand;

#include <ctime>
using std::time;

#include <iomanip>
using std::setw;

bool correctness_of_the_course(int [][8], int, int);
void make_move(int [][8], int, int);
void make_m_1(int [][8], int, int, int);
void make_m_2(int [][8], int, int, int);
void make_m_3(int [][8], int, int, int);
void make_m_4(int [][8], int, int, int);
void make_m_5(int [][8], int, int, int);
void make_m_6(int [][8], int, int, int);
void make_m_7(int [][8], int, int, int);
void make_m_8(int [][8], int, int, int);
void show_board(int [][8]);

int main()
{
   srand(time(0));
   int move_r, move_c;
   int number_move = 0;
   int attempt_counter = 0;
   int board[8][8] = {0};  
   move_r = rand() % 8;
   move_c = rand() % 8;

   while(true)
   {
      if(correctness_of_the_course(board, move_r, move_c))
      {
         number_move++;
	     board[move_r][move_c] = number_move;
         make_move(board, move_r, move_c);
         attempt_counter = 0;
      }
      else
      {
	     attempt_counter++;
         if(attempt_counter > 100)
            break;
      }

      move_r = rand() % 8;
      move_c = rand() % 8;
   }

   show_board(board);

   return 0;
}

bool correctness_of_the_course(int B[][8], int current_R, int current_C)
{
   if(B[current_R][current_C] != 0)
      return false;
   else
      return true;
}

void make_move(int B[][8], int current_R, int current_C)
{
   int filler = 10;
   int r_temp = current_R;
   int c_temp = current_C;

   make_m_1(B, r_temp, c_temp, filler);

   r_temp = current_R;
   c_temp = current_C;

   make_m_2(B, r_temp, c_temp, filler);

   r_temp = current_R;
   c_temp = current_C;

   make_m_3(B, r_temp, c_temp, filler);

   r_temp = current_R;
   c_temp = current_C;

   make_m_4(B, r_temp, c_temp, filler);

   r_temp = current_R;
   c_temp = current_C;

   make_m_5(B, r_temp, c_temp, filler);
   
   r_temp = current_R;
   c_temp = current_C;

   make_m_6(B, r_temp, c_temp, filler);
   
   r_temp = current_R;
   c_temp = current_C;

   make_m_7(B, r_temp, c_temp, filler);

   r_temp = current_R;
   c_temp = current_C;

   make_m_8(B, r_temp, c_temp, filler);
}

void make_m_1(int B[][8], int rT, int cT, int fil)
{
   if((cT - 1) < 0)
      return;
   else
   {
      cT--;
      B[rT][cT] = fil;
      make_m_1(B, rT, cT, fil);
   }
}

void make_m_2(int B[][8], int rT, int cT, int fil)
{
    if ((cT + 1) >= 8)
        return;
    else
    {
        cT++;
        B[rT][cT] = fil;
        make_m_2(B, rT, cT, fil);
    }
}

void make_m_3(int B[][8], int rT, int cT, int fil)
{
    if ((rT - 1) < 0)
        return;
    else
    {
        rT--;
        B[rT][cT] = fil;
        make_m_3(B, rT, cT, fil);
    }
}

void make_m_4(int B[][8], int rT, int cT, int fil)
{
    if ((rT + 1) >= 8)
        return;
    else
    {
        rT++;
        B[rT][cT] = fil;
        make_m_4(B, rT, cT, fil);
    }
}

void make_m_5(int B[][8], int rT, int cT, int fil)
{
    if ((rT - 1) < 0 || (cT - 1) < 0)
        return;
    else
    {
        rT--;
        cT--;
        B[rT][cT] = fil;
        make_m_5(B, rT, cT, fil);
    }
}

void make_m_6(int B[][8], int rT, int cT, int fil)
{
    if ((rT + 1) >= 8 || (cT + 1) >= 8)
        return;
    else
    {
        rT++;
        cT++;
        B[rT][cT] = fil;
        make_m_6(B, rT, cT, fil);
    }
}

void make_m_7(int B[][8], int rT, int cT, int fil)
{
    if ((rT + 1) >= 8 || (cT - 1) < 0)
        return;
    else
    {
        rT++;
        cT--;
        B[rT][cT] = fil;
        make_m_7(B, rT, cT, fil);
    }
}

void make_m_8(int B[][8], int rT, int cT, int fil)
{
    if ((rT - 1) < 0 || (cT + 1) >= 8)
        return;
    else
    {
        rT--;
        cT++;
        B[rT][cT] = fil;
        make_m_8(B, rT, cT, fil);
    }
}

void show_board(int B[][8])
{
   cout << "\n      0   1   2   3   4   5   6   7   \n" ;
   cout << "                                   \n";
   for(int i = 0; i < 8; i++)
   {
       cout << "    |---|---|---|---|---|---|---|---|\n";
       cout << i << "   |";
       for (int j = 0; j < 8; j++)
       {
           /*if (i == sCR && j == sCC)
               cout << " 1 " << "|";
           else*/ if (B[i][j] == 0)
               cout << "   |";
           else    
               cout << setw(3) << B[i][j] << "|";
       }
       cout << endl;
   }
   cout << "    |---|---|---|---|---|---|---|---|\n";
}
