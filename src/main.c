#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "command.h"
#include "command_handler.h"
#include "shell.h"

ShellState shell_state;

int main(int argc, char* argv[]) {

  initShellState(&shell_state);

  char user_input[MAX_CMD_LENGTH];
  
  while (strcmp(user_input, "quit\n") != 0) {
    printf("--------------\nNew Command\n");
    

    /* Grabs input from command line and initializes a Command struct */
    printf("mash > ");
    //inputHandler(strtok(user_input, "\n"));
    
    fgets(user_input, MAX_CMD_LENGTH, stdin);
    
    struct Command command = createCommand(strtok(user_input, "\n"));
    system("clear");
    
    // BEGIN BEGIN
    putCommand(command);
    printf("{%s} {%s} {%s}\n", command.processes[0].args[0], command.processes[0].args[1], command.processes[0].args[2]);
    // DEBUG END
    
    /* Running Command */
    if (runCommand(&command)) {
      //printf("QQQQ Size: %d\n", getHistoryQLength(&shell_state.historyQ));
      //pushHistoryQ(&shell_state.historyQ, command.string_rep);
      //printf("QQQQ Size: %d\n", getHistoryQLength(&shell_state.historyQ));
    }
    //free(user_input);
    freeCommand(&command);
    
    fflush(stdout);
  }
  return 0;
}
