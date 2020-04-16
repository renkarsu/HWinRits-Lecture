#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//noc == number of characters
#define noc 100

int replace_string(char *strS, const char *chPrevious, const char *chNext,
                   int *ploop);

int main(void){

  char *strS;
  strS = malloc(sizeof(char) * noc);

  if(strS == NULL)
    return 0;

  const char chPrevious[noc];
  const char chNext[noc];
  int loop = 0;
  int cnt = 1;

  printf("文字列を入力してください。ただし、半角なら100文字まで全角なら50文字までです。\n");
  scanf("%s", strS);
  puts("");

  printf("置換したい文字列は?ただし、2~5文字まで\n");
  scanf("%s", chPrevious);
  puts("");

  printf("置換後の文字列は?ただし、2~5文字まで\n");
  scanf("%s", chNext);
  puts("");

  replace_string(strS, chPrevious, chNext, &loop);
  printf("%s\n", strS);

  do{
      printf("置換を繰り返しますか?   ...1 / 0\n");
      scanf("%d", &loop);
      puts("");

      if(loop == 1){
        replace_string(strS, chPrevious, chNext, &loop);

	//置換先がないときにインクリメントしないためのif
	if(loop != 0)
	cnt++;

        printf("%s\n", strS);
      }
  }while(loop == 1);

  printf("修正箇所の個数は%d個です。\n", cnt);

  return 0;
}


int replace_string(char *strS, const char *chPrevious, const char *chNext,
                   int *ploop){
  char *locator;

  //error-handling
  if(NULL == strS || NULL == chPrevious || NULL == chNext)
    return 0;

  //locator = strstr. Then, NULL-check
  if((locator = strstr(strS, chPrevious)) == NULL){

    printf("置換先がありません。\n");
    *ploop = 0;
    return 0;
  }

  //error-handling
  if(NULL == locator)
    return 0;

  /*if str not replaced smaller than str replaced, buffer is extended.
    Then, cpy */
  if(strlen(chPrevious) < strlen(chNext)){

    strS = realloc(strS,
		   strlen(strS) + strlen(chNext) + 1 - strlen(chPrevious));
    memmove(locator + strlen(chNext), locator + strlen(chPrevious),
	    strlen(strS) - strlen(chPrevious) - (locator - strS) + 1);
    memcpy(locator, chNext, strlen(chNext));

  }

  /*In else, not replacedlen == replacedlen || notrep > rep, firstly, cpy.
    Then, if notrep > rep, buffer is resized.*/
  else {
    memcpy(locator, chNext, strlen(chNext));

    if(strlen(chPrevious) > strlen(chNext)){
      memmove(locator + strlen(chNext), locator + strlen(chPrevious),
	      strlen(strS) - strlen(chPrevious) - (locator - strS) + 1);
    }

  }
  return 1;
}
