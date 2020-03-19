#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <wait.h>
#include <string.h>
#define SIZE 1000



     int main() {
  pid_t child;
  time_t rawtime;
  int status;
  struct tm *timeinfo;
  char file[SIZE];
  char aa[SIZE];
  char place[SIZE];
    rawtime = time(NULL);
  timeinfo = localtime ( &rawtime ); 
  strcpy (file, "/home/osboxes/modul2/");
  strftime (aa, SIZE, "%Y-%m-%d_%H:%M:%S", timeinfo);
  strcat (file, aa);
     child = fork();
   if (child == 0) {
     sleep(30);
     char *argv[] = {"mkdir","-p",file,NULL};
     execv("/bin/mkdir", argv);
   } 
}



