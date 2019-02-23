#ifndef SHELL_H
#define SHELL_H
  #include <stdlib.h>
  #include "history.h"

  enum CanonicalState {non_canonical_mode, canonical_mode};

  typedef struct ShellState {
    enum CanonicalState canonical_state;
    HistoryQ historyQ;
    size_t max_cmd_len;
  } ShellState;

  void initShellState(ShellState* shell_state);

#endif
