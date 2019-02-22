#ifndef HISTORY_H
#define HISTORY_H

  typedef struct HistoryQ {
    char* command;
    struct HistoryQ* next;
    struct HistoryQ* prev;
  } HistoryQ;

  void putHistoryQ(HistoryQ* qNode);
  void pushHistoryQ(HistoryQ* qNode, char* command_string);
  void popHistoryQ(HistoryQ* qNode);

#endif
