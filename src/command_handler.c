#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "command_handler.h"
#include "command.h"

int processCommand(struct Command command) {
  /* Running Command */
  if (runMashCommand(&command)) {
    return 1;
  }
  else if (runCommand(&command)) {
    return 1;
  }
  else {
    printf("Command or Keyword not found: <%s>\n", command.string_rep);
    return 0;
  }
  freeCommand(&command);
}
