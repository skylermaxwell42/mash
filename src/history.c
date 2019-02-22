#include <stdio.h>
#include <stdlib.h>
#include "history.h"

#define MAX_LEN_HISTORYQ        1

void pushHistoryQ(HistoryQ** qNode, char* command_string) {
  printf("Pushing Q: %s\n", command_string);
  if (*qNode == NULL) {
    initHistoryQ(*qNode, command_string);
  }
  if (isFull(*qNode)) {
    printf("Q FUll\n");
    popHistoryQ(*qNode);
  }

  HistoryQ* new_node = NULL;
  initHistoryQ(new_node, command_string);
  printf("Pushed q\n");
  new_node->next = *qNode;
  *qNode = new_node;

  return;
}

void popHistoryQ(HistoryQ* qNode) {
  printf("Popping Q\n");
  HistoryQ* curr_node = qNode;
  while (curr_node->next != NULL) {
    curr_node = curr_node->next;
  }
  free(curr_node);
  curr_node = NULL;
  return;
}

int isFull(HistoryQ* qNode) {
  int len = getHistoryQLength(qNode);
  printf("Checking if full: %d\n", len);
  if (len >= MAX_LEN_HISTORYQ) {
    return 1;
  }
  return 0;
}

int getHistoryQLength(HistoryQ* qNode) {
  if (qNode == NULL) {
    return 0;
  }
  HistoryQ* curr_node = qNode;
  int count = 1;
  while (qNode->next != NULL) {
    printf("%d\n", count);
    curr_node = curr_node->next;
    count++;
  }
  return count;
}

void initHistoryQ(HistoryQ* qNode, char* command_string) {
  if (qNode == NULL) {
    printf("allocating space for node\n");
    qNode = malloc(sizeof(HistoryQ));
    qNode->command = command_string;
    qNode->next = NULL;

  }
  else {
    fprintf(stderr, "HistoryQ Could not be initialized... node is allocated here \n");
  }
}
