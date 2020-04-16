/*
I wrote this code after I have learn programming for a month.
Owing to that, this code may not be good.
*/

#include <stdio.h>
#include <math.h>
 
int main() {
 
  /* 三角形の辺 */
  int a, b, c;
  float S, s;
 
  /* 辺の長さを入力 */
  printf("三角形の辺a, b, cの長さを整数で入力してください。\n");
  printf("辺 a = ");
  scanf("%d", &a);
  printf("辺 b = ");
  scanf("%d", &b);
  printf("辺 c = ");
  scanf("%d", &c);
 
  /* 三角形の種類を判別・出力 */
  if ((a + b > c && a + c > b && b + c > a)
      && (a > 0 && b > 0 && c > 0)) {


    if (a == b && b  == c)
      printf("正三角形");
    else if (a == b || b == c || a == b)
      printf("二等辺三角形");
    else
      printf("全ての辺が等しくない三角形");

    if(c*c == b*b + a*a)
      printf("で直角三角形でもある。\n");
    else if(c*c > b*b + a*a)
      printf("で鈍角三角形でもある。\n");
    else
      printf("で鋭角三角形でもある。\n");


    /* 三角形の面積を計算・出力 */
    s = (double)(a + b + c) / 2.0;
    S  = (double)sqrt(s*(s-a)*(s-b)*(s-c));

    printf("三角形の面積は:%.2f\n", S);

  } 

  else {
    printf("その3辺では三角形をつくれません。\n");
  }
 
   return 0;
}
