#ifndef COMMAND_H
#define COMMAND_H

  #define MAX_CMD_LENGTH    1024

  typedef struct {
    char* prog;
    char* opts;
    char* args;
  } Command;

  void init_command(Command* command, char* input);
  void split_string(char* command_split[3], char* string);
  
#endif
