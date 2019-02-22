#ifndef COMMAND_H
#define COMMAND_H
  #include "history.h"

  #define MAX_CMD_LENGTH    512
  #define NUM_PROC_ARGS     3
  #define MAX_PROCESS_NUMS  4

  enum Program {ls};

  enum IORedirect {nil, redirect_input, redirect_output, pipe_in, pip_out};

  struct Process {
    char string_rep[MAX_CMD_LENGTH/MAX_PROCESS_NUMS];
    char* args[NUM_PROC_ARGS];
    enum IORedirect io_redirect;
  };

  struct Command {
    char string_rep[MAX_CMD_LENGTH];
    struct Process* processes;
    int num_processes;
    int p_links;
    int async_status;
  };

  void initCommand(struct Command* command, char* input);
  void initProcess(struct Process* process, char* proc_string);
  void parseInputToProcesses(char* command_split[3], char* string);
  void putCommand(struct Command command);
  void removeNewLine(char* string);
  int runCommand(struct Command command);
  int runProcess(struct Process process);

#endif
