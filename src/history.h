#ifndef HISTORY_H
#define HISTORY_H

  typedef struct HistoryQ {
    char* command;
    struct HistoryQ* next;
  } HistoryQ;

  void pushHistoryQ(HistoryQ** qNode, char* command_string);
  void popHistoryQ(HistoryQ* qNode);
  int getHistoryQLength(HistoryQ* qNode);
  void initHistoryQ(HistoryQ* qNode, char* command_string);
  int isFull(HistoryQ* qNode);

#endif
