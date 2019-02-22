#include <stdio.h>
#include "shell.h"
#include "command.h"

typedef struct CommandPrompt {
  size_t placeholder;
} CommandPrompt;

void initShellState(ShellState* shell_state, int max_cmd_len) {
  printf("Initializing Shell State\n");
  shell_state->max_cmd_len = max_cmd_len;
  shell_state->canonical_state = canonical_mode;
  shell_state->historyQ = NULL;
  return;
}
