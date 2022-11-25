#define N 11
#include <stdbool.h> 
#include <iostream>
using namespace std;

void printSolution(int board[N][N]) 
{ 
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < N; j++){ 
           if(board[i][j]==1)
           cout<<" Q ";
           else
           cout<<" . ";
        }
         cout<<endl;
    } 
} 

bool place(int board[N][N], int row, int col) 
{ 
    int i, j; 
    for (i = 0; i < col; i++) 
        if (board[row][i]) 
            return false; 

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) 
        if (board[i][j]) 
            return false; 
    for (i = row, j = col; j >= 0 && i < N; i++, j--) 
        if (board[i][j]) 
            return false; 
  
    return true; 
} 

bool NQueen(int board[N][N], int col) 
{ 
    if (col == N) 
        return true; 
   
    for (int i = 0; i < N; i++) { 
        if (place(board, i, col)) { 
         
            board[i][col] = 1; 
         
            if (NQueen(board, col + 1)) 
                return true; 
    
             //backtrack if next queen can't be placed
             //choose next row 
            board[i][col] = 0;  
        } 
    } 
    return false; 
} 

int main() 
{ 
     int board[N][N] = {0};
    cout<<"N Queen board for "<<N<<" queens."<<endl<<endl;
    if (NQueen(board, 0) == false) { 
        printf("Solution does not exist"); 
        return 0; 
    } 
  
    printSolution(board); 
    return true; 
    return 0; 
} 
