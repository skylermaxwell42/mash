#include <stdio.h>
#include "shell.h"

typedef struct CommandPrompt {
  size_t placeholder;
} CommandPrompt;

void initShellState(ShellState* shell_state) {
  printf("Initializing Shell State\n");
  shell_state->canonical_state = canonical_mode;
  shell_state->historyQ = createHistoryQ("HEAD");
  return;
}
