#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct string {
   char *str;
   int len;
   int size;
}string;

void push_back(string *input, char in)
{
   if (input->len >= input->size - 1)
   {
      input->str = realloc(input->str, input->size + 5);
   }
   input->size += 5;
   input->str[input->len++] = in;
   
}

void string_cp(string *des, string *src)
{
   if (des->str != NULL)
      free(des->str);
   des->str = malloc(src->size);
   strncpy(des->str, src->str, src->len);
   des->len = src->len;
   des->size = src->size;
}

typedef struct queue {
   int first;
   string cmds;
}Queue;

int n, m;
int front = 0, rear = 0;
int visited[10001];

int D(int x) {
   if (x * 2 > 9999) {
      return (x * 2) % 10000;
   }
   else {
      return x * 2;
   }
}
int S(int x) {
   if (x - 1 == -1) {
      return 9999;
   }
   else {
      return x - 1;
   }
}
int L(int x) {
   return (x * 10) % 10000 + x / 1000;
}
int R(int x) {
   return x / 10 + (x % 10) * 1000;
}

void bfs() {
   Queue* q = (Queue*)calloc(sizeof(Queue), 40000);
   front = rear = 0;
   visited[n] = 1;
   q[++rear].first = n;
   q[rear].cmds.len = 0;
   q[rear].cmds.str = malloc(1);
   q[rear].cmds.str[0] = 0;
   q[rear].cmds.size = 1;
   
   while (front <= rear) {
      //printf("[front = %d, rear = %d]\n", front, rear);
      int num = q[++front].first;
      if (num == m) {
         q[front].cmds.str[q[front].cmds.len] = 0;
         printf("%s\n", q[front].cmds.str);
         for (int i = 0 ; i < 40000 ; ++i)
             if (q[i].cmds.str)
                 free(q[i].cmds.str);
         free(q);
         return;
      }

      int d = D(num);
      if (visited[d] == 0) {
         visited[d] = 1;
         rear++;
         q[rear].first = d;
         string_cp(&q[rear].cmds, &q[front].cmds);
         push_back(&q[rear].cmds, 'D');
      }

      int s = S(num);
      if (visited[s] == 0) {
         visited[s] = 1;
         q[++rear].first = s;
         string_cp(&q[rear].cmds, &q[front].cmds);
         push_back(&q[rear].cmds, 'S');
      }

      int l = L(num);
      if (visited[l] == 0) {
         visited[l] = 1;
         q[++rear].first = l;
         string_cp(&q[rear].cmds, &q[front].cmds);
         push_back(&q[rear].cmds, 'L');
      }

      int r = R(num);
      if (visited[r] == 0) {
         visited[r] = 1;
         q[++rear].first = r;
         string_cp(&q[rear].cmds, &q[front].cmds);
         push_back(&q[rear].cmds, 'R');
      }
   }
}

int main() {
   int t;
   scanf("%d", &t);
   for (int i = 0; i < t; i++) {
      scanf("%d %d", &n, &m);
      bfs();
      memset(visited, 0, sizeof(visited));
   }

   return 0;
}