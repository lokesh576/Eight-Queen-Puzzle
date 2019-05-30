# Eight-Queen-Puzzle
Eight Queen puzzle in C language


## INRODUCTION TO THE PROJECT:

  The objective of this project is to create a small challenge -eight queens puzzle     
The eight queens puzzle is the problem of placing eight chess queens on an 8×8 chessboard so that no two queens threaten each other; thus, a solution requires that no two queens share the same row, column, or diagonal.   
 

## CONTENT OF THE PROJECT :

 This project contains a challenge, where the user has to place n number of queens in an nxn square box such that any of the queen should not attack another queen.
 
Once the user selects the dimensions of the box he wants to play with, he has to give the row and column number of the square where he wants to place his queen.

This repeats n number of times. After he places n queens in n different squares, he will be notified whether he has won or lost the challenge.

## DESIGN

### CREATING THE BOX:

Taking the dimension of the square box from the user, we create a square box using the characters ‘-’ and ‘|’.
We print the box with centre of every box to be a character space.
After the user enters the row and column number, the character ‘ ’ is converted to ‘Q’ in the centre of that particular box right after the screen is refreshed.
