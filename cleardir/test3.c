#include <stdio.h>

struct node_derevo{
  char path[30];
  struct node_derevo *previos;
  struct node_derevo *next[3];
}

  typedef struct node_derevo Node;

   Node* start = NULL;//корень дерева


//получаем полный путь
char* full_path(Node* element);


//добавление нового элемента
void add_by_path(char* full_path, Node* root) {

  /* code */
  return 0;
}





int main(int argc, char const *argv[]) {
  Node a = {"/usr/bin", NULL, {NULL,NULL,NULL}};
  start = &a; //указатель на a

  Node b = {"/usr/bin", start, {NULL,NULL,NULL}};
  start->next[0] = &b; //в массив записываем указатель на b

  return 0;
}
