#include <stdio.h>

int main() {

  int row, col, cnt, ver;
  cnt = 0;

  printf("Input value for row and col: ");
  scanf("%d", &row);

  col = row;

  float a[row][col];
  float b[row][col];
  float c[row][col];

  float factor;
  float cofactor;

  // Getting input
  for (int i=0; i < row; i++) {
    for (int j=0; j < col; j++) {
      printf("Input value for row %d and col %d: ", i, j);
      scanf("%f", &a[i][j]);
    }
  }


  //Getting I value of matrix A
  for (int i=0; i < row; i++) {
    for (int j=0; j < col; j++) {
      if (i==cnt && j==cnt) {
        b[cnt][cnt] = 1;
        cnt = cnt + 1;
      } else {
        b[i][j] = 0;
      }
    }
  }
  cnt = 0;


  //Calculating
  for (int i=0; i < row; i++) {
    for (int j=0; j < row; j++) {
      for (int k=0; k < col; k++) {
        if (j == cnt) {
          if (k == cnt) {
            factor = (a[j][k] - 1) / a[j][cnt];
          }
          a[j][k] = a[j][k] - (a[j][k] * factor);
          b[j][k] = b[j][k] - (b[j][k] * factor);
        }
      }
    }


    for (int j=0; j < row; j++) {
      // Finding factor
      for (int k=0; k < col; k++) {
        if (j != cnt) {
          if (k == cnt) {
            cofactor = a[j][cnt];
          }
          a[j][k] = a[j][k] - (cofactor * a[cnt][k]);
          b[j][k] = b[j][k] - (cofactor * b[cnt][k]);
        }
      }
    }
    cnt = cnt + 1;
  }

  //Output Matrix:
  for (int i=0; i < row; i++) {
    for (int j=0; j < col; j++) {
      printf("%.2f  ", a[i][j]);
    }
    printf("\n");
  }


  for (int i=0; i < row; i++) {
    for (int j=0; j < col; j++) {
      printf("%.2f  ", b[i][j]);
    }
    printf("\n");
  }

  return 0;
}
