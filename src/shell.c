#include <stdio.h>
#include "shell.h"

void init_shell_state(ShellState* shell_state, int max_cmd_len) {
  printf("Initializing Shell State\n");
  shell_state->max_cmd_len = max_cmd_len;
  shell_state->canonical_state = canonical_mode;
  return;
}
