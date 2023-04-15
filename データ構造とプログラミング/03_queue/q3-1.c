#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 5
// メモ : リングバッファとは
// リングバッファは、配列の先頭と末尾をつなげたような構造で、末尾の次は先頭に戻るようにしている。
// これにより、配列の先頭と末尾を使い回すことができる。
typedef struct
{
  int *buf;
  int head;
  int tail;
  int size;
} Queue;

void init_queue(Queue *q)
{
  q->buf = (int *)malloc(sizeof(int) * QUEUE_SIZE);
  q->head = q->tail = q->size = 0;
}

void enqueue(Queue *q, int data)
{
  if (q->size == QUEUE_SIZE)
  {
    printf("queue is full");
    return;
  }
  q->buf[q->tail] = data;
  q->tail = (q->tail + 1) % QUEUE_SIZE;
  q->size++;
}

int dequeue(Queue *q)
{
  if (q->size == 0)
  {
    printf("queue is empty");
    return -1;
  }
  int data = q->buf[q->head];
  q->head = (q->head + 1) % QUEUE_SIZE;
  q->size--;
  return data;
}

int main()
{
  Queue q;
  init_queue(&q);

  enqueue(&q, 100);
  enqueue(&q, 200);
  enqueue(&q, 300);

  printf("%d\n", dequeue(&q));

  dequeue(&q);

  enqueue(&q, 400);
  while (q.size > 0)
  {
    printf("%d ", dequeue(&q));
  }
  printf("\n");

  free(q.buf);

  return 0;
}
