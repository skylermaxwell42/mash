#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
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
    
    fgets(user_input, MAX_CMD_LENGTH, stdin);
    char* cmd_input = strtok(user_input, "\n");
    
    if (strcmp(cmd_input, "!!") == 0) {
      char pathbuf[100];
      chdir("..");
      getcwd(pathbuf, 100);
      printf("Changing dir to: %s\n", pathbuf);
      continue;
    }
    
    struct Command command = createCommand(cmd_input);
    system("clear");
    
    /* Running Command */
    if (runCommand(&command)) {
      //printf("QQQQ Size: %d\n", getHistoryQLength(&shell_state.historyQ));
      //pushHistoryQ(&shell_state.historyQ, command.string_rep);
      //printf("QQQQ Size: %d\n", getHistoryQLength(&shell_state.historyQ));
    }
    freeCommand(&command);
    
    fflush(stdout);
  }
  return 0;
}
