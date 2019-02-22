#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "command.h"
#include "shell.h"

ShellState shell_state;

int main(int argc, char* argv[]) {

  initShellState(&shell_state, MAX_CMD_LENGTH);



  while(1){
    struct Command command;

    /* Grabs input from command line and initializes a Command struct */
    char* user_input = NULL;
    size_t size = 20;
    char c = getline(&user_input, &shell_state.max_cmd_len, stdin);
    initCommand(&command, user_input);

    system("clear");

    // BEGIN BEGIN
    putCommand(command);
    printf("{%s} {%s} {%s}\n", command.processes[0].args[0], command.processes[0].args[1], command.processes[0].args[2]);
    // DEBUG END

    /* Running Command */
    runCommand(command);
    pushHistoryQ(&shell_state.historyQ, command.string_rep);
  }
  return 0;
}
