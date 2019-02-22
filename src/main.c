#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "command.h"
#include "shell.h"

ShellState shell_state;

int main(int argc, char* argv[]) {

  initShellState(&shell_state, MAX_CMD_LENGTH);


  char user_input[MAX_CMD_LENGTH];
  
  while (strcmp(user_input, "quit\n") != 0) {
    printf("--------------\nNew Command\n");
    

    /* Grabs input from command line and initializes a Command struct */
    //char* user_input = NULL;//malloc(sizeof(command.string_rep));
    //size_t size = 0;
    printf("mash > ");
    //char c = getline(&user_input, &size, stdin);
    fgets(user_input, MAX_CMD_LENGTH, stdin);
    
    struct Command* command = NULL;
    command = createCommand(user_input);
    system("clear");

    // BEGIN BEGIN
    putCommand(command);
    printf("{%s} {%s} {%s}\n", command->processes[0].args[0], command->processes[0].args[1], command->processes[0].args[2]);
    // DEBUG END

    /* Running Command */
    runCommand(command);
    //free(user_input);
    //freeCommand(command);
    fflush(stdout);
  }
  return 0;
}
