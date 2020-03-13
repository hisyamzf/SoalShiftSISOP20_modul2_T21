# SoalShiftSISOP20_modul2_T21


Soal Shift Sistem Operasi 2020


Hisyam Zulkarnain F             05311840000019\
Bayu Trianayasa                 05311840000038
## #2 &ndash; Kiwa
> Source code: [soal2.c](https://github.com/hisyamzf/SoalShiftSISOP20_modul2_T21/blob/master/soal2.c)

---


```
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
  strcpy (file, "/home/osboxes/sisop20/");
  strftime (aa, SIZE, "%Y-%m-%d_%H:%M:%S", timeinfo);
  strcat (file, aa);
     child = fork();
   if (child == 0) {
     sleep(30);
     char *argv[] = {"mkdir","-p",file,NULL};
     execv("/bin/mkdir", argv);
   } 
}

```


## #3 &ndash; MultiProcess
> Source code: [soal3.c](https://github.com/hisyamzf/SoalShiftSISOP20_modul2_T21/blob/master/soal3.c)

---

```
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>
#include <wait.h>

int main(){
  pid_t child, child1, child2, child3, child4, child5, child6;
  int status;
  child = fork();
  if (child == 0) {
    char *argv[] = {"mkdir","-p","/home/osboxes/sisop20/indomie",NULL};
    execv("/bin/mkdir", argv);
  }
        while((waitpid(child,&status,0))>0);
  child1 = fork();
  if (child1 == 0) {
    sleep(5);
    char *argv[] = {"mkdir","-p","/home/osboxes/sisop20/sedaap",NULL};
    execv("/bin/mkdir", argv);
  }
        while((waitpid(child1,&status,0))>0);
  child2 = fork();
  if (child2 == 0) { 
    char *argv[] = {"unzip","/home/osboxes/sisop20/jpg.zip","-d","/home/vaniameith/modul2",NULL};
    execv("/usr/bin/unzip", argv);
  }
        while((waitpid(child2,&status,0))>0);
  child3 = fork();
  if (child3 == 0){
    char *argv[] = {"find","/home/osboxes/sisop20/jpg",
                    "-mindepth","1","-type","f","-exec","mv",
                    "{}","/home/osboxes/sisop20/sedaap",
                    ";",NULL};
    execv("/usr/bin/find", argv);
  }

        while((waitpid(child3,&status,0))>0);
  child4 = fork();
  if (child4 == 0){
    char *argv[] = {"find","/home/osboxes/sisop20/jpg",
                    "-mindepth","1","-type","d","-exec","mv",
                    "{}","/home/osboxes/sisop20/indomie",
                    ";",NULL};
    execv("/usr/bin/find", argv);
  }
        while((waitpid(child4,&status,0))>0);
  child5 = fork();
  if (child5 == 0){
    char *argv[] = {"find","/home/osboxes/sisop20/indomie","-mindepth","1","-type","d","-exec","touch","{}/coba1.txt","'\'",";",NULL};
    execv("/usr/bin/find", argv);
  }
        while((waitpid(child5,&status,0))>0);
  child6 = fork();
  if (child6 == 0) {
    sleep(3);
    char *argv[] = {"find","/home/osboxes/sisop20/indomie","-mindepth","1","-type","d","-exec","touch","{}/coba2.txt","'\'",";",NULL};
    execv("/usr/bin/find", argv);
  }  
}
```
