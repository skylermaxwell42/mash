#ifndef SHELL_H
#define SHELL_H
  #include <stdlib.h>
  #include "history.h"

  #define CMD_PROMPT_BUFF_SIZE   1024

  enum CanonicalState {non_canonical_mode, canonical_mode};

  typedef struct ShellState {
    enum CanonicalState canonical_state;
    HistoryQ historyQ;
    size_t max_cmd_len;
    char command_prompt[CMD_PROMPT_BUFF_SIZE];
  } ShellState;

  void initShellState(ShellState* shell_state);
  void makeCommandPrompt(char* command_prompt);

#endif
