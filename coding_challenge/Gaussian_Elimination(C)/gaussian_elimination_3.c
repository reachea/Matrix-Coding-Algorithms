#include <stdio.h>

int main() {

  // Column and Row Variable
  int row, col, cnt;


  // Specify Row
  printf("Input value for row and col: ");
  scanf("%d", &row);


  // Specify Column
  col = row + 1;


  // Variable Usage
  float a[row][col];
  float factor;
  float cofactor;


  // Getting input
  for (int i=0; i < row; i++) {
    for (int j=0; j < col; j++) {
      printf("Input value for row %d and col %d: ", i+1, j+1);
      scanf("%f", &a[i][j]);
    }
  }


  //Calculating
  cnt = 0;
  for (int i=0; i < row; i++) {

    for (int j=0; j < row; j++) {
      // Getting value other than fixed dependency to 0 Logic
      for (int k=0; k < col; k++) {
        if (j > cnt) {
          if (k == 0) {
            cofactor = a[j][cnt] / a[cnt][cnt];
          }
          a[j][k] = a[j][k] - (cofactor * a[cnt][k]);
        }
      }
    }

    cnt = cnt + 1;
  }


  // Divide
  for (int i=(row - 1); i >= 0; i--) {

    for (int j=0; j < row; j++) {
      // Getting fixed dependency to 1 Logic
      for (int k = 0; k < col; k++) {
        if (j == i) {
          if (k == 0) {
            factor = a[i][i];
          }
          a[i][k] = a[i][k] / factor;
        }
      }
    }
  }


  //Multiply
  for (int i=(row - 1); i >= 0; i--) {
    //Getting Result Logic
    for (int j=0; j < row; j++) {
      if (j > i && j < row) {
        a[i][j] = a[i][j] * a[j][col-1];
        a[i][col-1] = a[i][col-1] - a[i][j];
      }
    }
  }


  //Result

  //Output Matrix:
  for (int i=0; i < row; i++) {
    for (int j=0; j < col; j++) {
      if (j > i && j < row) {
        a[i][j] = 0;
      }
      printf("%.2f  ", a[i][j]);
    }
    printf("\n");
  }

  printf("The inverse of matrix above is: \n");

  // Answer
  for (int i=(row-1); i >= 0; i--) {
    printf("x_%d = %.2f\n", i+1, a[i][col-1]);
  }


  return 0;
}
