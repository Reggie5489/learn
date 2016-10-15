// Author: Reginald M. Jefferson
// Version: October 14, 2016
// Class: CS 107
// Section: 11:00 AM
// Description: Project 2

#include <stdio.h>
#include <stdlib.h>

int main()
{
int userValueEntered;   // variable for user values entered
int multiplier;   // used as multiplier value from user
int row = 20,   // max row size intialized to 20
int col = 20;   // max col size initialized to 20
int mat[20][20];   // array
int choice;   // user input menu choice
  
for(int i = 0;i < row;++i)   // matrix is initially zero by zero
{
  for(int j = 0;j < col;++j)
  {
    mat[i][j] = 0;
  }
}

while(1)   // program will continue unless user enters 5
{
 
  printf("Main Menu"); // Main Menu is printed
  printf("1) Enter Matrix\n");
  printf("2) Manipulate Rows\n");
  printf("3) Manipulate Columns\n");
  printf("4) Print Matrix\n");
  printf("5) Exit\n");
 
  printf("Please enter your choice:\n");
  scanf("%d",&choice);   // Your Choice

  switch(choice)
  {
  case 1:
    printf("Please enter the number of rows in the matrix:\n");
    scanf("%d",&row);
    printf("Please enter the number of columns in the matrix:\n");
    scanf("%d", &col);

    for(int i = 0;i < row;++i)   // Row Input Data
    {
      printf("Please enter the data for row %d:\n",i + 1);
      for(int j = 0;j < col;++j)
      {
        scanf("%d",&mat[i][j]);
      }
    }
    break;
    
    case 2: // Row Manipulation
    printf("Manipulate the Rows of the Matrix\n");
    printf("1) add two rows and replace second row\n");
    printf("2) multiply row by constant\n");
    printf("3) return to main menu\n");
    printf("Please enter your choice:\n");
    scanf("%d",&userValueEntered);
      
    switch(userValueEntered)
    {
      case 1:
        printf("Please enter the two rows you want to add separated by space\n");
        int a;   // Row 1 of operation
        int b;   // Row 2 of operation 
        scanf("%d%d",&a,&b);
        --a;--b;
        
        if(a >= row || a < 0 || b >= row || b < 0)
        {
           printf("Invalid input\nReturn to Main Menu\n");   // error if invalid or return to main menu
           break;
        }
        
        for(int j = 0;j < col;++j)
        {
           mat[a][j] += mat[b][j];
        }
        
        for(int i = b + 1;i < row;++i)   // Row Replacement 
        {
           for(int j = 0;j < col;++j)
           {
              mat[i - 1][j] = mat[i][j];
           }
        }
              --row;
           break;
      case 2:
        printf("Which row would you like to multiply, followed by the constant you would like to use:\n");
        int r;   // row user picks for multiplication
        scanf("%d%d",&r,&multiplier);
        --r;
        if(r >= row || r < 0)
        {
          printf("Invalid input\nReturn to Main Menu\n");
          break;
        }
        
        for(int j = 0;j < col;++j)
        {
           mat[r][j] *= multiplier;   // multiplication of constant and row
        }
           break;
           default:
           break;
        }
      
      break;
      
      case 3:   // to manipulate the columns
        printf("Manipulate the Columns of the Matrix\n");
        printf("1) add two Columns and replace second Column\n");
        printf("2) multiply Column by constant\n");
        printf("3) return to main menu\n");
        printf("Please enter your choice:\n");
        scanf("%d",&multiplier);

        switch(userValueEntered)
        {
          case 1:
            printf("Please enter the two columns you want to add, separate by a space\n");
            int a;   // column 1
            int b;   // column 2
            scanf("%d%d",&a,&b);
            --a;--b;
            if(a >= col || a < 0 || b >= col || b < 0)
            {
               printf("Invalid input\n");
               printf("Return to Main Menu\n");
            break;
            }
            
            for(int j = 0;j < row;++j)
            {
               mat[j][a] += mat[j][b];
            }
           
            for(int i = b + 1;i < col;++i)   // Column Shifting
            {
               for(int j = 0;j < row;++j)
               {
                  mat[j][i - 1] = mat[j][i - 1];
               }
            }
               --col;
            break;
          case 2:
            printf("Which Column would you like to multiply and by what constant value you would like to multiply it by:\n");
            int c;
            scanf("%d%d",&c,&multiplier);
            --c;
            if(c >= col || c < 0)
            {
            printf("Invalid input\n");
            printf("Return to Main Menu\n");
            break;
            }
            
            for(int j = 0;j < row;++j)   // multiply each value of the column by the constant
            {
               mat[j][c] *= multiplier;
            }
            break;
            default:
            break;
            }
            break;
          case 4:
          printf("Current Matrix is -\n");
          if(row == 0 || col == 0)
          {
             printf("No Matrix\n");
          }
          for(int i = 0;i < row;++i)
          {
             for(int j = 0;j < col;++j)
             {
                printf("%d ", mat[i][j]);
             }
          printf("\n");
          }
          break;
          default:
          printf("Good Bye, Thanks for using the Matrix Manipulator\n");
          return 0;
    }
  }
      return 0;
}

