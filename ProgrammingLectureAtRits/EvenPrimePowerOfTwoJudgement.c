/*
I wrote this code after I have learn programming for a month.
Owing to that, this code may not be good.
*/

#include<stdio.h>
#include<math.h>
#include<stdbool.h>

void isevenORodd(int);
bool isprime(int);
void ispower(int);

int main(void){

  int x = 0;

  do{
  puts("正の整数を入力してください。(0 < x < 32768)");
  printf("x:", x);
  scanf("%d", &x);
  }while(x > 32768 && x < 0);

  isevenORodd(x);

  if(isprime(x) == 1)
    puts("素数です。");

  if(isprime(x) != 1)
    puts("素数ではありません。"); 

  ispower(x);


  return 0;
}


void isevenORodd(int x){

  if(x % 2 == 0)
    puts("偶数です。");

  if(x % 2 != 0)
    puts("奇数です。");
}


bool isprime(int x)
{
  int i;

    if (x < 2) return false;
    else if (x == 2) return true;
    //2以外の偶数を省く
    else if (x % 2 == 0) return false;

    //ある数nが素数かどうか判定するには√n以下の素数で割り切れるかどうかを確認すればよい。
    double sqrtX = sqrt(x);
    for (i = 3; i <= sqrtX; i += 2)
    {
        if (x % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}


void ispower(int x){

  /*(i) 整数nが2のべき乗数の場合
    nを2進数で表すと 1000...00 となり、最上位ビットのみが1であるので、n-1 は、 111...111      となる。よって、両者のビット論理積をとれば、必ず0になる。
  */
  if(  !(x & (x-1))  )
    puts("2のべき乗である。");

  else
    puts("2のべき乗ではない。");
}
