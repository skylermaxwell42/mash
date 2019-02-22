#ifndef COMMAND_H
#define COMMAND_H
  #include "history.h"

  #define MAX_CMD_LENGTH    512
  #define NUM_PROC_ARGS     3
  #define MAX_PROCESS_NUMS  4

  enum Program {ls};

  enum IORedirect {nil, redirect_input, redirect_output, pipe_in, pip_out};

  struct Process {
    char string_rep[512];//MAX_CMD_LENGTH/MAX_PROCESS_NUMS
    char* args[3];
    enum IORedirect io_redirect;
  };

  struct Command {
    char string_rep[512];
    struct Process processes[4];
    int num_processes;
    int p_links;
    int async_status;
  };

  void initCommand(struct Command* command);//, char* input);
  struct Command* createCommand(char* user_input);
  struct Process* createProcess(char* process_string);
  void initProcess(struct Process* process); //char* proc_string);
  void freeProcess(struct Process* process);
  void freeCommand(struct Command* command);
  void parseInputToProcesses(char* command_split[3], char* string);
  void putCommand(struct Command* command);
  void addCommandToHistory(HistoryQ* historyQ, struct Command* command);
  void removeNewLine(char* string);
  int runCommand(struct Command* command);
  int runProcess(struct Process* process);

#endif
