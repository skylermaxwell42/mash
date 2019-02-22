#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include "command.h"

void initCommand(struct Command* command, char* input) {

  /* Preprocessing user input */
  removeNewLine(input);

  int num_procs = 1;
  strcpy(command->string_rep, input);
  command->processes = malloc(sizeof(struct Process)*num_procs);
  command->num_processes = num_procs;
  initProcess(&command->processes[0], input);
  // Initialize the command
  // - determine redirect, async, pipe
  return;
}

void initProcess(struct Process* process, char* proc_string) {
  enum IORedirect io_redirect = nil;      // Temp
  strcpy(process->string_rep, proc_string);
  parseInputToProcesses(process->args, proc_string);
  process->io_redirect = io_redirect;
  return;
}

void parseInputToProcesses(char* args[NUM_PROC_ARGS], char* input) {

  const char delim[2] = " ";
  char* token = strtok(input, delim);
  for(int i = 0; i < NUM_PROC_ARGS; i++) {
    args[i] = token;
    //printf("Token: %s\n", args[i]);
    token = strtok(NULL, delim);
  }
  return;
}

void removeNewLine(char* string) {
  int idx = 0;
  while (string[idx] != '\n') {
    idx++;
  }
  string[idx] = '\0';
  //printf("%d\n", idx);
}

void putCommand(struct Command command) {
  printf("Command: %s\n", command.string_rep);
  return;
}

void addCommandToHistory(HistoryQ* historyQ, struct Command* command){
  printf("Adding Command to History\n");

  // pop History Q
  // push History Q
  return;
}

int runCommand(struct Command command) {
  for (int i = 0; i < command.num_processes; i++) {
    runProcess(command.processes[i]);
  }
  return 1;
}

int runProcess(struct Process process) {

  pid_t pid;
  pid = fork();
  if (pid == 0) {         // Child
    printf("%s %s %s\n", process.args[0], process.args[1], process.args[2]);
    execvp(process.args[0], process.args);
    printf("FAILED excecuting command\n");
    return 0;
  }
  else if (pid > 0) {     // Parent
    wait(NULL);
    printf("Back from parent\n");
    return 1;
  }
  return 0;
}
