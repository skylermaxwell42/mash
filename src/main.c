#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "command_handler.h"
#include "command.h"
#include "shell.h"

ShellState shell_state;

int main(int argc, char* argv[]) {

  initShellState(&shell_state);

  char user_input[MAX_CMD_LENGTH];

  while (strcmp(user_input, "quit\n") != 0) {
    /* Grabs input from command line and initializes a Command struct */
    makeCommandPrompt(shell_state.command_prompt);
    printf("%s", shell_state.command_prompt);

    fgets(user_input, MAX_CMD_LENGTH, stdin);
    char* cmd_input = strtok(user_input, "\n");
    struct Command command = createCommand(cmd_input);
    if (processCommand(command)) {
      addCommandToHistory(&shell_state.historyQ, command);
    }

    fflush(stdout);
  }
  return 0;
}
