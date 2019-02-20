#include "command.h"

void init_command(Command* command, char* input) {
  char* cmd_split[3];
  split_string(cmd_split, input);
  command->prog = cmd_split[0];
  command->opts = cmd_split[1];
  command->args = cmd_split[2];
  return;
}

void split_string(char* command_split[3], char* string) {
  char* str0 = "ls";
  char* str1 = "-l";
  char* str2 = "";
  command_split[0] = str0;
  command_split[1] = str1;
  command_split[2] = str2;
  return;
}
