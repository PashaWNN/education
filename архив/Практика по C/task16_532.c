#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int value;
    struct Node *next;
} Node;


int pop(Node **head) {
    Node* prev = NULL;
    int val;
    if (head == NULL) {
        exit(-1);
    }
    prev = (*head);
    val = prev->value;
    (*head) = (*head)->next;
    free(prev);
    return val;
}


Node* get(Node* head, int n) {
    int counter = 0;
    while (counter < n && head) {
        head = head->next;
        counter++;
    }
    return head;
}


Node* getLast(Node *head) {
    if (head == NULL) {
        return NULL;
    }
    while (head->next) {
        head = head->next;
    }
    return head;
}


void printLinkedList(const Node *head) {
    while (head) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

void push(Node **head, int data) {
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp->value = data;
    tmp->next = (*head);
    (*head) = tmp;
}

void pushBack(Node *head, int data) {
    Node *last = getLast(head);
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp->value = data;
    tmp->next = NULL;
    last->next = tmp;
}

int main() {
  Node *head = NULL;
  int n = 0;
  printf("Введите n: ");
  scanf("%d", &n);
  int m;
  for (int i = 0; i<n; i++) {    
    printf("Введите %d эл-т списка: ", i);
    scanf("%d", &m);
    if (!(head)) {
      push(&head, m);
    } else {
      pushBack(head, m);
    }
  }
  m = get(head, 0)->value;
  int flag = 0;
  for (int i = 1; i<n; i++) {
    if (get(head, i)->value<m) {
      flag = 1;
      break;
    } else {
      m = get(head, i)->value;
    }
  }
  if (flag) {
    for (int i = n-1; i>=0; i--) {
      printf("%d ", get(head, i)->value);
    }
    printf("\n");
  } else {
    printLinkedList(head);
  }
  return 0;
}



