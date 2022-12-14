# Daa-assignment-2

<h2>Implementing the solution for N-Queens Problem using Backtracking</h2>

<h3>Introduction:</h3>
In this problem, we are given a chessboard  with N x N dimensions. Our task is to place N queens in each row such that no two queens can attack each other. 
That is, we cannot place any two queens in diagonally opposite positions and neither vertically nor horizontally opposite.<br><br>
For example, lets consider 4 X 4 chessboard where we need to place 4 queens. If we place a queen in grid[1,1], we can see that we will not be able to place any other queen on red crosses.<br><br>

![Untitled design](https://user-images.githubusercontent.com/113958925/203930625-4570af55-9b96-4741-997d-097c822f368e.png)

The rest of the white spaces are safe to occupy.<br>
If we place one more queen on grid [2,3], we can see with the help of green crosses which new places can't be occupied now. <br>
![Untitled design (1)](https://user-images.githubusercontent.com/113958925/203931299-74bfe65e-1f4b-471a-a3df-a546fad07141.png)

Now, there is only one place left to place third queen. <br>

![Untitled design (2)](https://user-images.githubusercontent.com/113958925/203931795-583e5c9b-ecc4-4647-85e8-488229489caf.png)

<br>
We are at dead end. The problem was to place 4 queens but we did only 3.<br>

<h3>Using Backtracking to Solve N Queens:</h3>
We know presently that placing the first queen in grid[1,1] doesn't result into solution. We now backtrack to it and change its position to grid [1,2] and restart from this point again.
<br>

![Untitled design (4)](https://user-images.githubusercontent.com/113958925/203938631-44603fea-7562-431d-b5f6-888933c0b32d.png)

Building ahead on this, we finally reached to the solution whose screenshot is below.<br>

![Untitled design (5)](https://user-images.githubusercontent.com/113958925/203941396-3330c394-a576-4e3d-8f38-7f3494d94196.png)

This is one of the solutions, there can be many others such as this.<br>

![Untitled design (6)](https://user-images.githubusercontent.com/113958925/203941530-b2f8ea51-a745-4dba-b93b-6f6b41e76555.png)


Backtracking helps by taking appropriate steps that would lead us to solution and eliminating those which don't.<br> 

<h3>Implementation in C++:</h3>
Three functions are defined:<br>
1) NQueen <br>
2) place  <br>
3)printSolution <br>

A 2-D array board is declared with integer data type which acts as a chess board. It is filled with either 0s or 1s, where 1 represents a queen.

Function NQueen() places each queen column by column and returns a boolean true if queen is placed in that column. It also make changes to board array by filling 1 to corresponding block.
If it returns false, we backtrack to queens of previous columns and change their row positions and again start from there.



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

Function place() checks if a given block is safe for queen to place.It checks whether the diagonal and horizontal(row) positions are occupied and returns boolean value accordingly.<br>
                      
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
                      
                      
                      
Function printSolution() is simply for interpreting and printing the board array in presentable form in terminal.

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
  

<h3> Three test Cases:</h3>

![6](https://user-images.githubusercontent.com/113958925/203964679-4714c742-ff08-44f1-b8be-4faea1716a95.PNG)

![8](https://user-images.githubusercontent.com/113958925/203964709-6c9d59fb-9797-4876-a75c-18b79c8f2e1b.PNG)

![11](https://user-images.githubusercontent.com/113958925/203964608-45836e76-1115-4e89-a422-798bd66f387b.PNG)
