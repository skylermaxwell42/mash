#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include "command.h"

struct Command* createCommand(char* user_input) {
  struct Command* command = malloc(sizeof(struct Command));
  if (command == NULL) {
    fprintf(stderr, "Could not allocate space for Process struct\n");
  }
  initCommand(command);
  
  strcpy(command->string_rep, strtok(user_input, "\n"));
  int num_procs = 1;
  command->num_processes = num_procs;
  command->async_status = 0;
  command->p_links = 0;
  
  // Initializing individual
  for (int i = 0; i < command->num_processes; i++) {
    command->processes[i] = *createProcess(command->string_rep);
  }
  
  return command;
}

struct Process* createProcess(char* process_string) {
  struct Process* process = malloc(sizeof(struct Process));
  if (process == NULL) {
    fprintf(stderr, "Could not allocate space for Process struct\n");
  }
  initProcess(process);
  
  parseInputToProcesses(process->args, process_string);
  printf("%s_%s_%s\n", process->args[0], process->args[1], process->args[2]);
  enum IORedirect io_redirect = nil;
  process->io_redirect = io_redirect;
  strcpy(process->string_rep, process_string);
  return process;
}

void initCommand(struct Command* command) { //}, char* input) {
  // Allocating space for dynamically allocated properties
  command->string_rep = malloc(sizeof(char)*(MAX_CMD_LENGTH));
  command->processes = malloc(sizeof(struct Process)*MAX_PROCESS_NUMS);
  
  if ((command->string_rep == NULL)  || (command->processes == NULL)) {
    fprintf(stderr, "Could not allocate space for Command struct properties\n");
  }
  return;
}

void freeCommand(struct Command* command) {
  // Unallocating Command struct properties
  free(command->string_rep);
  for (int i = 0; i < command->num_processes; i++) {
    freeProcess(&command->processes[i]);
  }
  
  // Unallocating Command struct itself
  free(command);
}

void initProcess(struct Process* process) {
  //process = malloc(sizeof(struct Process));
  // Allocating space for dynamically allocated properties
  process->string_rep = malloc(sizeof(char)*(MAX_CMD_LENGTH/MAX_PROCESS_NUMS));
  process->args = malloc(sizeof(process->string_rep));
  
  if ((process->args == NULL) || (process->string_rep == NULL)) {
    fprintf(stderr, "Could not allocate space for Process struct properties\n");
  }
  return;
}

void freeProcess(struct Process* process) {
  // Unallocating Process struct properties
  free(process->string_rep);
  free(process->args);
  
  // Unallocating Process struct itself
  free(process);
  
  //if ((process != NULL) || (process->string_rep != NULL) || (process->args != NULL)) {
  //  fprintf(stderr, "Could not unallocate Process struct\n");
  //}
}

void parseInputToProcesses(char* args[NUM_PROC_ARGS], char* input) {

  const char delim[2] = " ";
  char* new_input = malloc(sizeof(input));
  strcpy(new_input, input);
  char* token = strtok(new_input, delim);
  for(int i = 0; i < NUM_PROC_ARGS; i++) {
    args[i] = token;
    printf("Token: %s\n", args[i]);
    token = strtok(NULL, delim);
  }
  //free(new_input);
  return;
}

void removeNewLine(char* string) {
  printf("Removing NL: %s", string);
  int idx = 0;
  while (string[idx] != '\n') {
    idx++;
  }
  string[idx] = 0;
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

int runCommand(struct Command* command) {
  for (int i = 0; i < command->num_processes; i++) {
    runProcess(&command->processes[i]);
  }
  return 1;
}

int runProcess(struct Process* process) {

  pid_t pid;
  pid = fork();
  if (pid == 0) {         // Child
    printf("%s %s %s\n", process->args[0], process->args[1], process->args[2]);
    execvp(process->args[0], process->args);
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
