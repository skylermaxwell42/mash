#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include "command.h"

struct Command createCommand(char* user_input) {
  struct Command command ;
  initCommand(&command);
  
  strcpy(command.string_rep, user_input);
  command.num_processes = 1;
  command.async_status = 0;
  command.p_links = 0;
  
  // Initializing individual
  for (int i = 0; i < command.num_processes; i++) {
    command.processes[i] = createProcess(command.string_rep);
  }
  
  return command;
}

void initCommand(struct Command* command) {
  // Allocating space for dynamically allocated properties
  command->string_rep = malloc(sizeof(char)*MAX_CMD_LENGTH);
  
  if (command->string_rep == NULL) {
    fprintf(stderr, "Could not allocate space for Command struct properties\n");
  }
  return;
}

void freeCommand(struct Command* command) {
  // Unallocating Command struct properties
  free(command->string_rep);
  freeProcess(command->processes);
}

struct Process createProcess(char* process_string) {
  struct Process process;
  initProcess(&process);
  
  parseInputToProcesses(process.args, process_string);
  //printf("%s_%s_%s\n", process.args[0], process.args[1], process.args[2]);
  process.io_redirect = nil;
  strcpy(process.string_rep, process_string);
  
  return process;
}

void putCommand(struct Command command) {
  printf("Command: %s\n", command.string_rep);
  return;
}

void addCommandToHistory(HistoryQ* historyQ, struct Command* command){
  printf("Adding Command to History\n");
  return;
}

int runCommand(struct Command* command) {
  printf("Processes to run: %d\n", command->num_processes);
  for (int i = 0; i < command->num_processes; i++) {
    runProcess(&command->processes[i]);
  }
  return 1;
}

void initProcess(struct Process* process) {
  // Allocating space for dynamically allocated properties
  process->string_rep = malloc(sizeof(char)*(MAX_CMD_LENGTH));
  for (int i = 0; i < NUM_PROC_ARGS; i++) {
    process->args[i] = malloc(sizeof(char)*MAX_CMD_LENGTH);
  }
  
  printf("Size of strs: %lu\n", sizeof(process->string_rep));
  
  if (process->string_rep == NULL) {
    fprintf(stderr, "Could not allocate space for Process struct properties\n");
  }
  return;
}

void freeProcess(struct Process* process) {
  // Unallocating Process struct properties
  free(process->string_rep);
  for (int i = 0; i < NUM_PROC_ARGS; i++) {
    free(process->args[i]);
  }
}

void parseInputToProcesses(char* args[3], char* input) {
  const char delim[2] = " ";
  char* new_input = malloc(sizeof(input));
  strcpy(new_input, input);
  char* token = strtok(new_input, delim);
  for(int i = 0; i < NUM_PROC_ARGS; i++) {
    if (token != NULL) {
      strcpy(args[i], token);
      printf("Token: %s\n", args[i]);
      token = strtok(NULL, delim);
    }
    else {
      args[i] = NULL;
    }
  }
  free(new_input);
  return;
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
