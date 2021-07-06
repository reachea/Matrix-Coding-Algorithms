#include <stdio.h>

// QaussianElimination for 2 and 3 equation
int main() {
  int row,col,cnt,ver;
  float x,y,z;
  float factor;

  printf("Enter number of equation row: ");
  scanf("%d", &row);

  col = row + 1;
  cnt = row - 2;
  ver = 1;

  float a[row][col];
  float aCpy[row][col];
  float cofactor[row];

  // getMatrixInput
  for (int i=0; i<row; i++) {
    for (int j=0; j<col; j++) {
      printf("Enter input for row %d, column %d: ", i+1, j+1);
      scanf("%f", &a[i][j]);
    }
  }

  // Clone Matrix A
  for (int i=0; i<row; i++) {
    for (int j=0; j<col; j++) {
      aCpy[i][j] = a[i][j];
    }
  }

  // Calculate
  for (int i=0; i<row; i++){
    for (int j=0; j<col; j++) {
      if (i > 0) {
        aCpy[i][j] = a[i][j] - (( a[0][j] * a[i][0] )/a[0][0]);
        if (i > 1) {
          for (int k=1; k< i; k++ ) {
            if (j==ver) {
              factor = aCpy[i][ver] / aCpy[ver][ver];
            }
            aCpy[i][j] = aCpy[i][j] - (aCpy[i-1][j] * factor);
          }
        }
      }
    }
    ver = 1;
  }


  // Finding x,y or even z then OUTPUT!
  if(row == 2) {
    y = aCpy[1][2] / aCpy[1][1];
    x = (aCpy[0][2] - (aCpy[0][1] * y)) / aCpy[0][0];


    for (int i=0; i<row; i++) {
      for (int j=0; j<col; j++) {
        printf("%.2f  ", aCpy[i][j]);
      }
      printf("\n");
    }

    printf("Therefore, x = %.2f, y = %.2f", x, y);
  }
  else if (row == 3) {
    z = aCpy[2][3] / aCpy[2][2];
    y = (aCpy[1][3] - (aCpy[1][2] * z)) / aCpy[1][1];
    x = (aCpy[0][3] - (aCpy[0][2] * z) - (aCpy[0][1] * y)) / aCpy[0][0];


    for (int i=0; i<row; i++) {
      for (int j=0; j<col; j++) {
        printf("%.2f  ", aCpy[i][j]);
      }
      printf("\n");
    }

    printf("Therefore, x = %.2f, y = %.2f, z = %.2f", x, y, z);
  } else {
    for (int i=0; i<row; i++) {
      for (int j=0; j<col; j++) {
        printf("%.2f  ", aCpy[i][j]);
      }
      printf("\n");
    }
  }

  return 0;
}
