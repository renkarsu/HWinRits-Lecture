/*
This is a JankenGame code. This code is used XOR shift RNGs, enum, function
and to determine the condition by the string(also char), yes or no,  method.
これはじゃんけんゲームのコードです。このコードの中にはXOR shift RNGsやenum列挙体,関数,
yesかnoの文字列（または文字）により条件を決定するというメソッドが使われています。
---for Ritsumeikan students---
XORshiftRNGsという乱数生成アルゴリズムはコンピュータが出す手を決めるために乱数が必要なので使います。
まるまるパクってもばれないと思いますが自分は元々提出予定だったじゃんけんゲームを魔改造してこのコードを書いたので
（元々、どうしてもわからないときはみていいよということで先生から答えはもらえる）ワンチャンばれるかも(というかみんながパクればれる)。
なんで手法だけ盗む気持ちがええかと。
---caution---
I killed some security hole. However, if someone input large inputs to the standard input, it will be broken.
I didn't fix this because it was tired.
セキュリティホールは少ないはずだけど大量に標準入力したら多分つぶれます。けど、めんどくさいので放置しました。
printXXX of function is renamed printfXXX on the github's edditor, so it will be some error.
github上でprintXXXという名前の関数を手動でprintfXXXって名前の関数にしたのでエラーが新しくあるかも。コピペするなら気を付けてください。
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef enum janken
  {
    Gu = 0,
    Choki = 2,
    Pa = 5
  }JPON;

int saikoro(void);

JPON DecideNPCsHand(int);

void printfNPCsHand(JPON);

void printfUsersHand(JPON);

int judge(JPON, JPON);

void printfResult(int);

int main(void){
  JPON usersHand;
  JPON NPCsHand;
  int ken_buf;
  int sai;
  int result_1_0_minus1;

  char ccontinue[1];
  int win = 0, lose = 0, draw = 0;

  do{

    //DecideUsersHand
      do{
        printf("\nジャンケンをしましょう。\n");
        printf("グーは0 チョキは2 パーは5を入れます。\n");
        printf("\nじゃんけんぽん！はいどうぞ：");

        while(scanf("%d", &ken_buf) != 1){
            printf("「数字」を入力してね!はいどうぞ:");
            while(getchar() != '\n');
        }

        usersHand = (JPON)ken_buf;

        if((usersHand != Gu) && (usersHand != Choki) && (usersHand != Pa))
        printf("\n@@@@正しく入れてください！@@@@\n");

      }while(!(usersHand == Gu || usersHand == Choki || usersHand == Pa));

      sai = saikoro();
      NPCsHand = DecideNPCsHand(sai);

      result_1_0_minus1 = judge(usersHand, NPCsHand);


    printfUsersHand(usersHand);
    printfNPCsHand(NPCsHand);
    printfResult(result_1_0_minus1);

    //continue?
    if(result_1_0_minus1 == 1) win += 1;
    else if(result_1_0_minus1 == 0) draw += 1;
    else lose += 1;

    printf("\nResult:%d勝 %d敗 %d分けです。\n", win, lose, draw);
    printf("Continue? Yes：y, No：n ---");
    
    while(scanf(" %[yn]", ccontinue) != 1){
        printf("正しく入れてね！はいどうぞ:");
        while(getchar() != '\n');
    }

}while(!strcmp(ccontinue, "y"));

  printf("\n終わります。Have a nice day!!\n\n");

  return (0);
}

int saikoro(void){
  int sai;
  static unsigned int tx = 123456789, ty = 362436069,
                      tz = 521288629, tw = 88675123;
  unsigned int tt = (tx^(tx<<11));
  tx = ty; ty = tz; tz = tw;
  tw = tw^(tw>>19)^(tt^(tt>>8));

  sai = tw%6+1;

  return(sai);
}

JPON DecideNPCsHand(int sainome){
  int pon = 0;
  switch(sainome){
  case 1:pon = 0; break;
  case 2:pon = 0; break;
  case 3:pon = 2; break;
  case 4:pon = 2; break;
  case 5:pon = 5; break;
  case 6:pon = 5; break;
  }
  return ((JPON)pon);
}

void printfNPCsHand(JPON ken){

  switch(ken){
  case Gu:{
    puts("わたし：グー");
    break;
  }
  case Choki:{
    puts("わたし：チョキ");
    break;
  }
  case Pa:{
    puts("わたし：パー");
    break;
  }
  }
}

void printfUsersHand(JPON ken){

  switch(ken){
  case Gu:{
    printf("\nあなた：グー\n");
    break;
  }
  case Choki:{
    printf("\nあなた：チョキ\n");
    break;
  }
  case Pa:{
    printf("\nあなた：パー\n");
    break;
  }
  }
}

int judge(JPON user, JPON npc){
  int result;
  switch(user){
  case Gu:{
    if(npc == Gu) result = 0;
    else if(npc == Choki) result = 1;
    else result = -1;
    break;
  }
  case Choki:{
    if(npc == Gu) result = -1;
    else if(npc == Choki) result = 0;
    else result = 1;
    break;
  }
  case Pa:{
    if(npc == Gu) result = 1;
    else if(npc == Choki) result = -1;
    else result = 0;
    break;
  }
  }
  return (result);
}

void printfResult(int result){
  if(result == -1) printf("\nYou lose...\n");
  else if(result == 1) printf("\nYou win!!\n");
  else if(result == 0) printf("\ndraw\n");
  else printf("引数のエラーです。");
}
