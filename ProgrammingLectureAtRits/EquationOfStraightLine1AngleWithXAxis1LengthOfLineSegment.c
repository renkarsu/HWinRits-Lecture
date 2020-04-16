/*
I wrote this code after I have learn programming for a month.
Owing to that, this code may not be good.
*/

#include<stdio.h>
#include<math.h>

void input(int*, int*, int*, int*);

void elinear(int, int, int ,int, int, int, int, int, int, int,
             int*, int*, int*, int*);

void olinear(int, int, int, int);

int main(void){

  int x1=0, y1 = 0, x2 = 0, y2 = 0;
  int i = 0, j = 0, k = 0, l = 0;
  int r = 0, tmp = 0;
  int di = 0, dj = 0, dk = 0, dl = 0;

  double rad = 0,line = 0;

  // 座標の入力
  input(&x1, &y1, &x2, &y2);

  // 直線の方程式を求める(evaluate)
  elinear(x1, y1, x2, y2, r, tmp, di, dj, dk, dl, &i, &j, &k, &l);

  //直線の方程式の出力(output)
  olinear(i, j, k, l);

  rad = (double)atan2(i, j);
  printf("\nx軸となす角度は%fです。", rad);

  line = (double)sqrt(j*j + i*i);
  printf("\n線分の長さは%fです。", line);

  puts("");

  return 0;
}
 
void input(int *px1, int *py1, int *px2, int *py2){

  printf("二つの座標を整数で入力してください。\n"
	 "２点を通る直線の方程式を出力します。\n");

  printf("X1:");
  scanf("%d", px1);

  printf("Y1:");
  scanf("%d", py1);

  printf("X2:");
  scanf("%d", px2);

  printf("Y2:");
  scanf("%d", py2);
}

void elinear(int x1, int y1, int x2, int y2, int r, int tmp,
	     int di, int dj, int dk, int dl,
             int *pi, int *pj, int *pk, int *pl){

  *pi = y2 - y1;
  *pj = x2 - x1;
  *pk = x2*y1-x1*y2;
  *pl = x2 - x1;

  //y = ax+bのaの最大公約数を求めてそれでaを約分する

  if(*pi > 0)
    di = *pi;
  if(*pi < 0)
    di = -(*pi);

  if(*pj > 0)
    dj = *pj;
  if(*pj < 0)
    dj = -(*pj);

  if(di != 1 && dj != 1 && di != 0 && dj != 0){

    if(di < dj){
      tmp = di;
      di = dj;
      dj = tmp;
    }

    r = di % dj;

    while(r != 0){

      di = dj;
      dj = r;
      r = di % dj;
    }

    *pi /= dj;
    *pj /= dj;

  }

  //y = ax+bのbの最大公約数を求めてそれでbを約分する

  if(*pk > 0)
    dk = *pk;
  if(*pk < 0)
    dk = -(*pk);

  if(*pl > 0)
    dl = *pl;
  if(*pl < 0)
    dl = -(*pl);

  if(dk != 1 && dl != 1 && dk != 0 && dl != 0){

    if(dk < dl){
      tmp = dk;
      dk = dl;
      dl = tmp;
    }
 
    r = dk % dl;

    while(r!=0){
      dk = dl;
      dl = r;
      r = dk % dl;
    }    

    *pk /= dl;
    *pl /= dl;        
  }

}

void olinear(int i, int j, int k, int l){

  //aに関する処理
  if(i == 0 || j == 0)
    printf("y = ");

  else if(i != 0 && j != 0){

    if(j != 1 && j != -1){

      if(i > 0 && j > 0)
        printf("y = %d/%dx ", i, j);

      if(i < 0 && j < 0)
        printf("y = %d/%dx ", -i, -j);

      if(i > 0 && j < 0)
        printf("y = -(%d/%d)x ", i, -j);

      if(i < 0 && j > 0)
        printf("y = -(%d/%d)x ", -i, j);
    }

    if(j == 1 && i != 1 && i != -1)
      printf("y = %dx ", i);

    if(j == 1 && i == 1)
      printf("y = x ");

    if(j == 1 && i == -1)
      printf("y = -x ");


    if(j == -1 && i != 1 && i != -1)
      printf("y = %dx ", -i);

    if(j == -1 && i == 1)
      printf("y = -x ");

    if(j == -1 && i == -1)
      printf("y = x "); 
  }


  //bに関する処理
  if((k == 0 || l == 0) && i != 0 && j != 0)
    printf("");

  if((k == 0 || l == 0) && (i == 0 || j == 0))
    printf("0");

  else if(k != 0 && l != 0){

    if(l != 1 && l != -1){

      if(k > 0 && l > 0)
	printf("+ %d/%d", k, l);

      if(k < 0 && l < 0)
	printf("+ %d/%d", -k, -l);

      if(k > 0 && l < 0)
	printf("- (%d/%d)", k, -l);

      if(k < 0 && l > 0)
	printf("- (%d/%d)", -k, l);

    }


    if(l == 1){

      if(k > 0)
	printf("+ %d", k);
 
      if(k < 0)
	printf("- %d", -k);
    }

    if(l == -1){
      if(k > 0)
	printf("- %d", k);

      if(k < 0)
	printf("+ %d", -k);
    }

  }

}
