/*
I wrote this code after I have learn programming for a month.
Owing to that, this code may not be good.
*/

#include<stdio.h>
#include<math.h>

  int a, b, c;
  int D;
  double result1, result2;
  double real, img;

void Bnot0Cnot0(int, int, int);
void Cnot0(int, int, int);
void Bnot0(int, int, int);
void BandC0(int, int, int);

int main(void){

  printf("二次方程式ax^2+bx+cの解の種類を判別式Dにより判別します。\n"
         "さらに、解も出します。\n"
         "a,b,cの値を入力してください。ただしa ≠  0で、a,b,cは整数です。\n");

  printf("整数a:");
  scanf("%d", &a);

  if(a == 0){
    do{
      printf("aに0を入力しないでください。\n");

      printf("整数a:");
      scanf("%d", &a);

    }while(a == 0);
  }

  printf("整数b:");
  scanf("%d", &b);

  printf("整数c:");
  scanf("%d", &c);

  D = b*b-4*a*c;





  if(D > 0){
    printf("判定結果:実数解を2つ持ちます。\n");

    result1 = (double)( -b + sqrt(D) )/2*a;
    result2 = (double)( -b - sqrt(D) )/2*a;

    Bnot0Cnot0(a, b, c);

    Cnot0(a, b, c);

    Bnot0(a, b, c);

    BandC0(a, b, c);

    printf("x = %g,%g\n", result1, result2);
  }





  else if(D == 0){
    printf("判定結果:重解を持ちます。\n");

    result1 = (double)( -b - sqrt(D) )/2*a;

    Bnot0Cnot0(a, b, c);

    Cnot0(a, b, c);

    Bnot0(a, b, c);

    BandC0(a, b, c);

    printf("x = %g \n", result1);
  }





  else{
    printf("判定結果:虚数解を持ちます。\n");

    real = -b/2*a;
    img = sqrt(-D)/2*a;

    Bnot0Cnot0(a, b, c);

    Cnot0(a, b, c);

    Bnot0(a, b, c);

    BandC0(a, b, c);

    if(real != 0)
      printf("x = (%g+%g)i, (%g-%g)i \n", real, img, real, img);
    
    if(real == 0)
      printf("x = (%g)i, (-%g)i \n", img, img);
  }

  return 0;
}

void Bnot0Cnot0(int a, int b, int c){

    if(b != 0 && c != 0){
      if(b > 0 && c > 0){

	if(a == 1)
	  printf("x^2+%dx+%dの解は\n", b, c);

	if(a != 1)
	  printf("%dx^2+%dx+%dの解は\n", a, b, c);
      }

      if(b > 0 && c < 0){

	if(a == 1)
	  printf("x^2+%dx%dの解は\n", b, c);

	if(a != 1)
	  printf("%dx^2+%dx%dの解は\n", a, b, c);
      }

      if(b < 0 && c > 0){

	if(a == 1)
	  printf("x^2%dx+%dの解は\n", b, c);

	if(a != 1)
	  printf("%dx^2%dx+%dの解は\n", a, b, c);
      }

      if(b < 0 && c < 0){

	if(a == 1)
	  printf("x^2%dx%dの解は\n", b, c);

	if(a != 1)
	  printf("%dx^2%dx%dの解は\n", a, b, c);
      }
    }
}

void Cnot0(int a, int b, int c){

    if(b == 0 && c != 0){

      if(c > 0){

	if(a == 1)
	  printf("x^2+%dの解は\n", c);

	if(a != 1)
	  printf("%dx^2+%dの解は\n", a, c);
      }

      if(c < 0){

	if(a == 1)
	  printf("x^2%dの解は\n", c);

	if(a != 1)
	  printf("%dx^2%dの解は\n", a, c);
      }
    }
}

void Bnot0(int a, int b, int c){

    if(b != 0 && c == 0){

      if(b > 0){

	if(a == 1)
	  printf("x^2+%dxの解は\n", b);

	if(a != 1)
	  printf("%dx^2+%dxの解は\n", a, b);
      }

      if(b < 0){

	if(a == 1)
	  printf("x^2%dxの解は\n", b);

	if(a != 1)
	  printf("%dx^2%dxの解は\n", a, b);
      }   
    }
}

void BandC0(int a, int b, int c){

    if(b == 0 && c == 0){

      if(a == 1)
	printf("x^2の解は\n");

      if(a != 1)
        printf("%dx^2の解は", a);
   
    }
}
