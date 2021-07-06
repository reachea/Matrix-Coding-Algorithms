#include <stdio.h>

int main() {

  // Define array for row and column of expression

  int row, col;

  printf("Specify number of expression: ");
  scanf("%d", &row);

  col = row + 1;

  float a[row][col];


  // Getting Input
  for (int i=0; i<row; i++) {
    for (int j=0; j<col; j++) {
      printf("Enter the value of expression %d, variable %d: ", i+1, j+1);
      scanf("%f", &a[i][j]);
    }
  }

  // Global variable

  float ans[row], subAns[row];
  float factor;

  // Calculation
  // Divide all element with its factor

  for (int i=0; i<row; i++) {

    factor = a[i][i];

    for (int j=0; j<col; j++) {
      a[i][j] = a[i][j] / factor;
    }
  }


  // init default value
  float rowArray[row][row];

  for (int i=0; i<row; i++) {
    ans[i] = 0;
    for (int j=0; j<col; j++) {
      if (j != i && j != col-1) {
        rowArray[i][j] = a[i][j];
      }
    }
  }


  //Answer Logic

  printf("\n\n");

  float cofactor;
  cofactor = 0;

  for (int loop=0; loop<10; loop++) {
    for (int i=0; i<row; i++) {
      for (int j=0; j<row; j++) {
        if (j != i) {
          cofactor = cofactor + (rowArray[i][j] * ans[j]);
        }
      }

      for (int j=0; j<row; j++) {
        if (j == i) {
          subAns[i] = a[i][col-1] - cofactor;
        }
      }
      cofactor = 0;
    }

    for (int i=0; i<row; i++) {
      ans[i] = subAns[i];
      printf("%.2f ", ans[i]);
    }
    printf("\n");
  }


  printf("\n\n\n");

  // Output the expression

  //Getting the output answer logic
  char letter[26] = {'x','y','z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w'};
  printf("Therefore, the answer of the expression is: \n");
  for (int i=0; i<row; i++) {
    printf("%c = %.2f\n", letter[i], ans[i]);
  }


  return 0;
}
