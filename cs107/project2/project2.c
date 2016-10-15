#include <stdio.h>
#include <stdlib.h>

int main()
{

int manipulate, constant; // variable which will be used later in the function
int row = 20, col = 20; // row and col variable is defining current matrix size in row x col
int mat[20][20];

// initialize matrix to zero
for(int i = 0;i < row;++i)
{
  for(int j = 0;j < col;++j)
  {
    mat[i][j] = 0;
  }
}

// infinite Loop until user press 5(Exit)
while(1)
{
  // Display Main Menu
  printf("Main Menu\n1) Enter Matrix\n2) Manipulate Rows\n3) Manipulate Columns\n4) Print Matrix\n5) Exit\n");
  int choice;
  printf("Please enter your choice:\n");
  scanf("%d",&choice); // Enter your choice

  // Switch case to choose the menu depending on the user input
  // We could use if else too but switch looks more elegant
  // and easy in this scenario
  switch(choice){
  case 1:
    printf("Please enter the number of rows in the matrix:\n");
    scanf("%d",&row);
    printf("Please enter the number of columns in the matrix:\n");
    scanf("%d", &col);

    //now new row and col is changed

    //Take the input of each row
    for(int i = 0;i < row;++i) {
      printf("Please enter the data for row %d:\n",i + 1);
      for(int j = 0;j < col;++j){
        scanf("%d",&mat[i][j]);
      }
    }
    break;
    case 2:
    // to manipulate the rows
    printf("Manipulate the Rows of the Matrix\n1) add two rows and replace second row\n2) multiply row by constant\n3) return to main menu\n");
    printf("Please enter your choice:\n");
    scanf("%d",&manipulate);

    // Another switch case to decide what operation we should perform
    switch(manipulate){
      case 1:
        printf("Please enter the two row you want to add separated by space\n");
        int a,b;
        scanf("%d%d",&a,&b);
        --a;--b;// making it 0 based
        // add the value of row b to row a
        //check if a and b is between 0 and row
        if(a >= row || a < 0 || b >= row || b < 0){
        printf("Invalid input\nReturn to Main Menu\n");
        break;
        }
        for(int j = 0;j < col;++j){
        mat[a][j] += mat[b][j];
        }
        //To delete the row b, we need to shift up all the row below b and decrement row size
        for(int i = b + 1;i < row;++i){
        for(int j = 0;j < col;++j){
        mat[i - 1][j] = mat[i][j];
        }
        }
        --row;
        break;
      case 2:
        printf("Which row would you like to multiply, followed by the constant you would like to use:\n");
        int r;
        scanf("%d%d",&r,&constant);
        // check if r is valid or not
        --r;
        if(r >= row || r < 0){
          printf("Invalid input\nReturn to Main Menu\n");
          break;
        }

        // multiply each value of row r with that constant
        for(int j = 0;j < col;++j){
        mat[r][j] *= constant;
        }
        break;
        default:
        break;
      }
      break;
      case 3:
        // to manipulate the columbns
        printf("Manipulate the Columns of the Matrix\n1) add two Columns and replace second Column\n2) multiply Column by constant\n3) return to main menu\n");
        printf("Please enter your choice:\n");
        scanf("%d",&manipulate);

        // Another switch case to decide what operation we should perform
        switch(manipulate){
          case 1:
            printf("Please enter the two Columns you want to add separated by space\n");
            int a,b;
            scanf("%d%d",&a,&b);
            --a;--b;// making it 0 based
            // add the value of Column b to Column a
            //check if a and b is between 0 and col
            if(a >= col || a < 0 || b >= col || b < 0){
            printf("Invalid input\nReturn to Main Menu\n");
            break;
            }
            for(int j = 0;j < row;++j){
            mat[j][a] += mat[j][b];
            }
            //To delete the Column b, we need to shift left all the Columns right of b and decrement Column size
            for(int i = b + 1;i < col;++i){
            for(int j = 0;j < row;++j){
            mat[j][i - 1] = mat[j][i - 1];
            }
            }
            --col;
            break;
          case 2:
            printf("Which Column would you like to multiply, followed by the constant you would like to use:\n");
            int c;
            scanf("%d%d",&c,&constant);
            --c;
            // check if r is valid or not
            if(c >= col || c < 0){
            printf("Invalid input\nReturn to Main Menu\n");
            break;
            }

            // multiply each value of Column c with that constant
            for(int j = 0;j < row;++j){
            mat[j][c] *= constant;
            }
            break;
            default:
            break;
            }
            break;
          case 4:
          printf("Current Matrix is -\n");
          if(row == 0 || col == 0){
          printf("Matrix is empty\n");
          }
          for(int i = 0;i < row;++i){
          for(int j = 0;j < col;++j){
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

