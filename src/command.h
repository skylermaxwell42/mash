#ifndef COMMAND_H
#define COMMAND_H
  #include <stdlib.h>
  #include "history.h"

  #define MAX_CMD_LENGTH    512
  #define NUM_PROC_ARGS     3
  #define MAX_PROCESS_NUMS  4

  enum IORedirect {nil, redirect_input, redirect_output, pipe_in, pip_out};

  struct Process {
    char* string_rep;//MAX_CMD_LENGTH/MAX_PROCESS_NUMS
    char* args[3];
    enum IORedirect io_redirect;
  };
  struct Command {
    char* string_rep;
    struct Process processes[2];
    int num_processes;
    int p_links;
    int async_status;
  };

  struct Process createProcess(char* process_string);
  void  initProcess(struct Process* process);
  void freeProcess(struct Process* process);
  void parseInputToProcesses(char* command_split[3], char* string);
  int runProcess(struct Process* process);


  struct Command createCommand(char* user_input);
  void initCommand(struct Command* command);
  void freeCommand(struct Command* command);
  void putCommand(struct Command command);
  void addCommandToHistory(HistoryQ* historyQ, struct Command command);
  void removeNewLine(char* string);
  int runCommand(struct Command* command);
  int runMashCommand(struct Command* command);


#endif
