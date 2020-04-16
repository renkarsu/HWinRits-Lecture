/*
I wrote this code after I have learn programming for two month.
Owing to that, this code may not be good.
*/

#include<stdio.h>
#include<stdlib.h>

//stack

typedef struct{

  int smax;
  int ptr;
  int *stk;
}istack;

int sinitialize(istack *s, int smax);

int spush(istack *s, int x);

int spop(istack *s, int *x);

int speek(const istack *s, int *x);

void sprint(const istack *s);

void sterminate(istack *s);

int scapasity(const istack *s);

int ssize(const istack *s);

int stack(void);



//queue

typedef struct{
  int max;
  int num;
  int front;
  int rear;
  int *que;
}iqueue;

int initialize(iqueue *q, int max);

int enque(iqueue *q, int x);

int deque(iqueue *q, int *x);

int peek(const iqueue *q, int *x);

int capasity(const iqueue *q);

int size(const iqueue *q);

void print(const iqueue *q);

void terminate(iqueue *q);

int queue(void);

//main

int main(void){

  int which = 0;

  printf("スタックをご利用なら1を、キューをご利用なら0をご入力ください。\n");
  scanf("%d", &which);

  if(which == 1)
    stack();

  if(which == 0)
    queue();

  return 0;
}

//stack

int sinitialize(istack *s, int smax){

  s->ptr = 0;
  if((s->stk = calloc(smax, sizeof(int))) == NULL){

    s->smax = 0;
    return -1;
  }
  s->smax = smax;
  return 0;
}

int spush(istack *s, int x){
  if(s->ptr >= s->smax)
    return -1;
  s->stk[s->ptr++] = x;
  return 0;
}

int spop(istack *s, int *x){

  if(s->ptr <= 0)
    return -1;
  *x = s->stk[--s->ptr];
  return 0;
}

int speek(const istack *s, int *x){

  if(s->ptr <= 0)
    return -1;
  *x = s->stk[s->ptr - 1];
  return 0;
}

void sprint(const istack *s){

  int i;

  for(i = 0; i < s->ptr; i++)
    printf("%d ", s->stk[i]);
  putchar('\n');
}

void sterminate(istack *s){

  if(s->stk != NULL)
    free(s->stk);
  s->smax = s->ptr = 0;
}

int scapasity(const istack *s){

  return s->smax;
}

int ssize(const istack *s){

  return s->ptr;
}



int stack(void){

  istack s;
  int i;

  if(sinitialize(&s, 4) == -1){
    puts("スタックの生成に失敗しました。");
    return 1;
  }

  while(1){
    int menu, x;

    printf("現在のデータ数:%d / %d\n", ssize(&s), scapasity(&s));
    printf("(1)プッシュ (2)ポップ (3)ピーク (4)表示 (0)終了:");
    scanf("%d", &menu);

    if(menu == 0) break;

    switch(menu){
    case 1: /*---spush---*/
      printf("データ:");
      scanf("%d", &x);
      if(spush(&s, x) == -1)
	puts("エラー:プッシュに失敗しました。");
      break;

    case 2:/*---spop---*/
      if(spop(&s, &x) == -1)
	puts("エラー:ポップに失敗しました。");
      else
	printf("ポップしたデータは%dです。\n", x);
      break;

    case 3:/*---speek---*/
      if(speek(&s, &x) == -1)
	puts("エラー:ピークに失敗しました。");
      else
	printf("ピークしたデータは%dです。\n", x);
      break;

    case 4:/*---sprint---*/
      sprint(&s);
      break;
    }
  }

  sterminate(&s);

  return 0;
}


//queue

int initialize(iqueue *q, int max){

  q->num = q->front = q->rear = 0;
  if((q->que = calloc(max, sizeof(int))) == NULL){
    q->max = 0;
    return -1;
  }
  q->max = max;
  return 0;
}

int enque(iqueue *q, int x){

  if(q->num >= q->max)
    return -1;
  else{
    q->num++;
    q->que[q->rear++] = x;
    if(q->rear == q->max)
      q->rear = 0;
  }
}

int deque(iqueue *q, int *x){

  if(q->num <= 0)
    return -1;
  else{
    q->num--;
    *x = q->que[q->front++];
    if(q->front == q->max)
      q->front = 0;
    return 0;
  }
}

int peek(const iqueue *q, int *x){

  if(q->num <= 0)
    return -1;
  *x = q->que[q->front];
  return 0;
}

int capasity(const iqueue *q){

  return q->max;
}

int size(const iqueue *q){

  return q->num;
}

void print(const iqueue *q){

  int i;

  for(i = 0; i < q->num; i++)
    printf("%d ", q->que[(i + q->front) % q->max]);
  putchar('\n');
}

void terminate(iqueue *q){

  if(q->que != NULL)
    free(q->que);
  q->max = q->num = q->front = q->rear = 0;
}

int queue(void){

  iqueue que;

  if(initialize(&que, 4) == -1){
    puts("キューの生成に失敗しました。");
    return 1;
  }

  while(1){
    int m, x;

    printf("現在のデータ数:%d / %d\n", size(&que), capasity(&que));
    printf("(1)エンキュー (2)デキュー (3)ピーク (4)表示 (0)終了:");
    scanf("%d", &m);

    if(m == 0)
      break;

    switch(m){
    case 1:/*---enque---*/
      printf("データ:");
      scanf("%d", &x);
      if(enque(&que, x) == -1)
	puts("エラー:エンキューに失敗しました。");
      break;

    case 2:/*---deque---*/
      if(deque(&que, &x) == -1)
	puts("エラー:デキューに失敗しました。");
      else
	printf("デキューしたデータは%dです。\n", x);
      break;

    case 3:/*---peek---*/
      if(peek(&que, &x) == -1)
	puts("エラー:ピークに失敗しました。");
      else
	printf("ピークしたデータは%dです。\n", x);
      break;

    case 4:/*---print---*/
      print(&que);
      break;
    }
  }
  terminate(&que);

  return 0;
}#include<stdio.h>
#include<stdlib.h>

//stack

typedef struct{

  int smax;
  int ptr;
  int *stk;
}istack;

int sinitialize(istack *s, int smax);

int spush(istack *s, int x);

int spop(istack *s, int *x);

int speek(const istack *s, int *x);

void sprint(const istack *s);

void sterminate(istack *s);

int scapasity(const istack *s);

int ssize(const istack *s);

int stack(void);



//queue

typedef struct{
  int max;
  int num;
  int front;
  int rear;
  int *que;
}iqueue;

int initialize(iqueue *q, int max);

int enque(iqueue *q, int x);

int deque(iqueue *q, int *x);

int peek(const iqueue *q, int *x);

int capasity(const iqueue *q);

int size(const iqueue *q);

void print(const iqueue *q);

void terminate(iqueue *q);

int queue(void);

//main

int main(void){

  int which = 0;

  printf("スタックをご利用なら1を、キューをご利用なら0をご入力ください。\n");
  scanf("%d", &which);

  if(which == 1)
    stack();

  if(which == 0)
    queue();

  return 0;
}

//stack

int sinitialize(istack *s, int smax){

  s->ptr = 0;
  if((s->stk = calloc(smax, sizeof(int))) == NULL){

    s->smax = 0;
    return -1;
  }
  s->smax = smax;
  return 0;
}

int spush(istack *s, int x){
  if(s->ptr >= s->smax)
    return -1;
  s->stk[s->ptr++] = x;
  return 0;
}

int spop(istack *s, int *x){

  if(s->ptr <= 0)
    return -1;
  *x = s->stk[--s->ptr];
  return 0;
}

int speek(const istack *s, int *x){

  if(s->ptr <= 0)
    return -1;
  *x = s->stk[s->ptr - 1];
  return 0;
}

void sprint(const istack *s){

  int i;

  for(i = 0; i < s->ptr; i++)
    printf("%d ", s->stk[i]);
  putchar('\n');
}

void sterminate(istack *s){

  if(s->stk != NULL)
    free(s->stk);
  s->smax = s->ptr = 0;
}

int scapasity(const istack *s){

  return s->smax;
}

int ssize(const istack *s){

  return s->ptr;
}



int stack(void){

  istack s;
  int i;

  if(sinitialize(&s, 4) == -1){
    puts("スタックの生成に失敗しました。");
    return 1;
  }

  while(1){
    int menu, x;

    printf("現在のデータ数:%d / %d\n", ssize(&s), scapasity(&s));
    printf("(1)プッシュ (2)ポップ (3)ピーク (4)表示 (0)終了:");
    scanf("%d", &menu);

    if(menu == 0) break;

    switch(menu){
    case 1: /*---spush---*/
      printf("データ:");
      scanf("%d", &x);
      if(spush(&s, x) == -1)
	puts("エラー:プッシュに失敗しました。");
      break;

    case 2:/*---spop---*/
      if(spop(&s, &x) == -1)
	puts("エラー:ポップに失敗しました。");
      else
	printf("ポップしたデータは%dです。\n", x);
      break;

    case 3:/*---speek---*/
      if(speek(&s, &x) == -1)
	puts("エラー:ピークに失敗しました。");
      else
	printf("ピークしたデータは%dです。\n", x);
      break;

    case 4:/*---sprint---*/
      sprint(&s);
      break;
    }
  }

  sterminate(&s);

  return 0;
}


//queue

int initialize(iqueue *q, int max){

  q->num = q->front = q->rear = 0;
  if((q->que = calloc(max, sizeof(int))) == NULL){
    q->max = 0;
    return -1;
  }
  q->max = max;
  return 0;
}

int enque(iqueue *q, int x){

  if(q->num >= q->max)
    return -1;
  else{
    q->num++;
    q->que[q->rear++] = x;
    if(q->rear == q->max)
      q->rear = 0;
  }
}

int deque(iqueue *q, int *x){

  if(q->num <= 0)
    return -1;
  else{
    q->num--;
    *x = q->que[q->front++];
    if(q->front == q->max)
      q->front = 0;
    return 0;
  }
}

int peek(const iqueue *q, int *x){

  if(q->num <= 0)
    return -1;
  *x = q->que[q->front];
  return 0;
}

int capasity(const iqueue *q){

  return q->max;
}

int size(const iqueue *q){

  return q->num;
}

void print(const iqueue *q){

  int i;

  for(i = 0; i < q->num; i++)
    printf("%d ", q->que[(i + q->front) % q->max]);
  putchar('\n');
}

void terminate(iqueue *q){

  if(q->que != NULL)
    free(q->que);
  q->max = q->num = q->front = q->rear = 0;
}

int queue(void){

  iqueue que;

  if(initialize(&que, 4) == -1){
    puts("キューの生成に失敗しました。");
    return 1;
  }

  while(1){
    int m, x;

    printf("現在のデータ数:%d / %d\n", size(&que), capasity(&que));
    printf("(1)エンキュー (2)デキュー (3)ピーク (4)表示 (0)終了:");
    scanf("%d", &m);

    if(m == 0)
      break;

    switch(m){
    case 1:/*---enque---*/
      printf("データ:");
      scanf("%d", &x);
      if(enque(&que, x) == -1)
	puts("エラー:エンキューに失敗しました。");
      break;

    case 2:/*---deque---*/
      if(deque(&que, &x) == -1)
	puts("エラー:デキューに失敗しました。");
      else
	printf("デキューしたデータは%dです。\n", x);
      break;

    case 3:/*---peek---*/
      if(peek(&que, &x) == -1)
	puts("エラー:ピークに失敗しました。");
      else
	printf("ピークしたデータは%dです。\n", x);
      break;

    case 4:/*---print---*/
      print(&que);
      break;
    }
  }
  terminate(&que);

  return 0;
}
