#ifndef SHELL_H
#define SHELL_H

  enum CanonicalState {non_canonical_mode, canonical_mode};

  typedef struct {
    enum CanonicalState canonical_state;
    int max_cmd_len;
  } ShellState;
  
  void init_shell_state(ShellState* shell_state, int max_cmd_len);

#endif
