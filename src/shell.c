#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "shell.h"

void initShellState(ShellState* shell_state) {
  printf("Initializing Shell State\n");
  shell_state->canonical_state = canonical_mode;
  shell_state->historyQ = createHistoryQ("HEAD");
  printf("QQQQ Size: %d\n", getHistoryQLength(&shell_state->historyQ));
  return;
}

void makeCommandPrompt(char* command_prompt) {
  time_t curtime = time(NULL);
  char hostname[100];
  char pathbuf[100];
  struct tm *loctime;

  gethostname(hostname, 100);
  getcwd(pathbuf, 100);
  loctime = localtime(&curtime);
  sprintf(command_prompt, "user@%s in %s\n$ ", hostname, pathbuf);
}
