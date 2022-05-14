#include <stdio.h>

int pid_array [4701];
int last;


#define MAX_PID 5000
#define MIN_PID 300

int allocate_map(void) {
  int i;
  for (i = 0; i <=(MAX_PID - MIN_PID); i++) {
    pid_array[i] = 0;
  }
  last = 0;
  if (pid_array[4700] == 0) {
    return 1;           
  } else {
    return -1;          
  }
}


int allocate_pid(void) {
    int i = 0;        
    int next;         
    if (last == MAX_PID) {
      next = MIN_PID;
    } else {
      next = last + 1;
    }
    while ((i <= (MAX_PID - MIN_PID)) && (pid_array[next] == 1)) {
      ++i;
      ++next;
      if (next > MAX_PID) {
        next = MIN_PID;
      }
    }
    if (i == (MAX_PID - MIN_PID) + 1) {
        return -1;      // return — 1 if unable to allocate a pid
    }
    pid_array[next] = 1;
    last = next;
    return last + 300;
}

void release_pid(int pid) {
    pid_array[pid - 300] = 0;
}



int main(){
int pid, pid2;
printf("Allocating map: %d\n\n", allocate_map());
pid = allocate_pid();
    printf("Allocating PID: %d\n", pid);
    release_pid(pid);
    printf("Releasing PID: %d\n", pid);

   
}