#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "history.h"
#include "command.h"

#define MAX_LEN_HISTORYQ        1

void pushHistoryQ(HistoryQ* qNode, char* command_string) {
  printf("Pushing Q: %s\n", command_string);
  if (isFull(qNode)) {
    printf("Q FUll\n");
    popHistoryQ(qNode);
  }
  
  HistoryQ new_node = createHistoryQ(command_string);
  printf("Pushed q\n");
  new_node.next = qNode;
  qNode = &new_node;
  
  return;
}

void popHistoryQ(HistoryQ* qNode) {
  printf("Popping Q\n");
  HistoryQ* curr_node = qNode;
  while (curr_node->next != NULL) {
    curr_node = curr_node->next;
  }
  freeNode(curr_node);
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
  return count-1;
}

HistoryQ createHistoryQ(char* command_string) {
  HistoryQ qNode;
  initHistoryQ(&qNode);
  
  strcpy(qNode.command, command_string);
  qNode.next = NULL;
  
  return qNode;
}

void initHistoryQ(HistoryQ* qNode) {
  qNode->command = malloc(sizeof(char)*MAX_CMD_LENGTH);
  if (qNode == NULL) {
    fprintf(stderr, "Couldnt allocate space for history entry\n");
  }
}

void freeNode(HistoryQ* node) {
  free(node->command);
}
