#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "command.h"
#include "shell.h"

ShellState shell_state;

int main(int argc, char* argv[]) {

  init_shell_state(&shell_state, MAX_CMD_LENGTH);

  while(1){

    Command command;
    /* Grabs input from command line and initializes a Command struct */
    char* input = NULL;
    size_t size;
    char c = getline(&input, &size, stdin);
    init_command(&command, input);
    free(input);

    printf("mash> %s %s %s", command.prog, command.opts, command.args);

  }
  return 0;
}
