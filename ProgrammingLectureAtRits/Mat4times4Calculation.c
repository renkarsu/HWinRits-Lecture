/*
I wrote this code after I have learn programming for a month.
Owing to that, this code may not be good.
*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void in_mat1(double mat1[4][4]);
void in_mat2(double mat2[4][4]);
void mat_add(double a[4][4], double b[4][4], double c[4][4]);
void mat_sub(double a[4][4], double b[4][4], double c[4][4]);
void mat_mul(double a[4][4], double b[4][4], double c[4][4]);
void mat_out(double c[4][4]);
void fdet(double x[4][4]);
void inverse(double x[4][4]);

int main(void){

  double mat1[4][4] = {0};
  double mat2[4][4] = {0};
  double mat3[4][4] = {0};
  double inv_x[4][4] = {0};

  printf("2つの4行4列の行列を入力。\n");
  in_mat1(mat1);
  in_mat2(mat2);

  printf("4行4列の行列と4行4列の行列の和は\n");
  mat_add(mat1, mat2, mat3);
  mat_out(mat3);

  printf("4行4列の行列と4行4列の行列の差は\n");
  mat_sub(mat1, mat2, mat3);
  mat_out(mat3);

  printf("4行4列の行列と4行4列の行列の積は\n");
  mat_mul(mat1, mat2, mat3);
  mat_out(mat3);

  printf("初めの行列式は");
  fdet(mat1);

  printf("次の行列式は");
  fdet(mat2);


  printf("初めの行列に対する逆行列は\n");
  inverse(mat1);

  printf("次の行列に対する逆行列は\n");
  inverse(mat2);

  return 0;
} 


void in_mat1(double mat1[4][4]){

  int i = 0;

  printf("まず、1つ目の4行4列の行列を入力して下さい。\n"
	 "（要素と要素の間は半角スペースを打ってください。）\n"
	 "(4桁まででお願いします。)\n");

  printf("例えば   5 5 5 5　のように打ってエンター\n");

  for (i = 0; i < 4; i++){
    scanf("%lf %lf %lf %lf",
	  &mat1[i][0], &mat1[i][1],
	  &mat1[i][2], &mat1[i][3], &mat1[1][4]);
  }
}


void in_mat2(double mat2[4][4]){

  int i = 0;

  printf("最後に、2つ目の4行4列の行列を入力して下さい。\n");

  for (i = 0; i < 4; i++){
    scanf("%lf %lf %lf %lf",
	  &mat2[i][0], &mat2[i][1],
	  &mat2[i][2], &mat2[i][3], &mat2[1][4]);
  }
}


void mat_add(double a[4][4], double b[4][4], double c[4][4]){

  int i, j;

  for(i = 0; i < 4; i++){
    for(j = 0; j < 4; j++){
      c[i][j] = a[i][j] + b[i][j];
    }
  }
}



void mat_sub(double a[4][4], double b[4][4], double c[4][4]){

  int i, j;

  for(i = 0; i < 4; i++){
    for(j = 0; j < 4; j++){
      c[i][j] = a[i][j] - b[i][j];
    }
  }
}


void mat_mul(double a[4][4], double b[4][4], double c[4][4]){
 
  int i, j, k;
  double item;

  for(i = 0; i < 4; i++){
    for(j = 0; j < 4; j++){
      c[i][j] = a[i][j] * b[i][j];
 
      //要素の計算
      for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
          item = 0;
          for(k = 0; k < 4; k++)
            item = item + a[i][k]*b[k][j];
          c[i][j] = item;
        }
      }

    }
  }
}

void mat_out(double c[4][4]){

  int i, j;
  for (i = 0; i < 4; i++){
    for (j = 0; j < 4; j++)
      printf("%5.2lf", c[i][j]);

    printf("\n");
  }
}


//fdet = function det
void fdet(double x[4][4]){

  double det = 1;
  int i, j, k;
  double temp;
  double matcpy[4][4];

  for(i = 0; i < 4; i++){
    for(j = 0; j < 4; j++)
      matcpy[i][j] = x[i][j];
  }
//上三角行列を求める
    for(i = 0; i < 4; i++){

       for(j = 0; j < 4; j++){
          if(i < j){
           temp = matcpy[j][i] / matcpy[i][i];
           for(k = 0; k < 4; k++)
              matcpy[j][k] -= matcpy[i][k] * temp;
    
          }
       }
    }

  //対角部分の積を求める
  for(i = 0; i < 4; i++)
    det *= matcpy[i][i];

  printf("%5.2lfです。\n", det);
}



void inverse(double x[4][4]){

  int i, j, k;
  double temp;
  double inv_x[4][4];


  //単位行列を作る
  for(i = 0; i < 4; i++){

    for(j = 0; j < 4; j++){
      inv_x[i][j]=(i==j)?1:0;
    }

  }




  //掃き出し法(ガウスの消去法notJohldan)
  for(i = 0; i < 4; i++){

    temp = 1 / x[i][i];

     for(j = 0; j < 4; j++){
        x[i][j] *= temp;
        inv_x[i][j] *= temp;
     }

     for(j = 0; j < 4; j++){
        if(i != j){
	      temp = x[j][i];

	      for(k = 0; k < 4; k++){
	         x[j][k] -= x[i][k] * temp;
	         inv_x[j][k] -= inv_x[i][k] * temp;
	      }
        }
     }
  }



  //逆行列を出力
  for(i = 0; i < 4; i++){
    for(j = 0; j < 4; j++){
      printf(" %5.2lf",inv_x[i][j]);
    }
    printf("\n");
  }

}
