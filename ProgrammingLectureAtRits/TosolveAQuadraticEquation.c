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

  printf("�񎟕�����ax^2+bx+c�̉��̎�ނ𔻕ʎ�D�ɂ�蔻�ʂ��܂��B\n"
         "����ɁA�����o���܂��B\n"
         "a,b,c�̒l����͂��Ă��������B������a ��  0�ŁAa,b,c�͐����ł��B\n");

  printf("����a:");
  scanf("%d", &a);

  if(a == 0){
    do{
      printf("a��0����͂��Ȃ��ł��������B\n");

      printf("����a:");
      scanf("%d", &a);

    }while(a == 0);
  }

  printf("����b:");
  scanf("%d", &b);

  printf("����c:");
  scanf("%d", &c);

  D = b*b-4*a*c;





  if(D > 0){
    printf("���茋��:��������2�����܂��B\n");

    result1 = (double)( -b + sqrt(D) )/2*a;
    result2 = (double)( -b - sqrt(D) )/2*a;

    Bnot0Cnot0(a, b, c);

    Cnot0(a, b, c);

    Bnot0(a, b, c);

    BandC0(a, b, c);

    printf("x = %g,%g\n", result1, result2);
  }





  else if(D == 0){
    printf("���茋��:�d���������܂��B\n");

    result1 = (double)( -b - sqrt(D) )/2*a;

    Bnot0Cnot0(a, b, c);

    Cnot0(a, b, c);

    Bnot0(a, b, c);

    BandC0(a, b, c);

    printf("x = %g \n", result1);
  }





  else{
    printf("���茋��:�������������܂��B\n");

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
	  printf("x^2+%dx+%d�̉���\n", b, c);

	if(a != 1)
	  printf("%dx^2+%dx+%d�̉���\n", a, b, c);
      }

      if(b > 0 && c < 0){

	if(a == 1)
	  printf("x^2+%dx%d�̉���\n", b, c);

	if(a != 1)
	  printf("%dx^2+%dx%d�̉���\n", a, b, c);
      }

      if(b < 0 && c > 0){

	if(a == 1)
	  printf("x^2%dx+%d�̉���\n", b, c);

	if(a != 1)
	  printf("%dx^2%dx+%d�̉���\n", a, b, c);
      }

      if(b < 0 && c < 0){

	if(a == 1)
	  printf("x^2%dx%d�̉���\n", b, c);

	if(a != 1)
	  printf("%dx^2%dx%d�̉���\n", a, b, c);
      }
    }
}

void Cnot0(int a, int b, int c){

    if(b == 0 && c != 0){

      if(c > 0){

	if(a == 1)
	  printf("x^2+%d�̉���\n", c);

	if(a != 1)
	  printf("%dx^2+%d�̉���\n", a, c);
      }

      if(c < 0){

	if(a == 1)
	  printf("x^2%d�̉���\n", c);

	if(a != 1)
	  printf("%dx^2%d�̉���\n", a, c);
      }
    }
}

void Bnot0(int a, int b, int c){

    if(b != 0 && c == 0){

      if(b > 0){

	if(a == 1)
	  printf("x^2+%dx�̉���\n", b);

	if(a != 1)
	  printf("%dx^2+%dx�̉���\n", a, b);
      }

      if(b < 0){

	if(a == 1)
	  printf("x^2%dx�̉���\n", b);

	if(a != 1)
	  printf("%dx^2%dx�̉���\n", a, b);
      }   
    }
}

void BandC0(int a, int b, int c){

    if(b == 0 && c == 0){

      if(a == 1)
	printf("x^2�̉���\n");

      if(a != 1)
        printf("%dx^2�̉���", a);
   
    }
}
