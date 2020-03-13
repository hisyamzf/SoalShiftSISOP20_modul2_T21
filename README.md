# SoalShiftSISOP20_modul2_T21


Soal Shift Sistem Operasi 2020


Hisyam Zulkarnain F             05311840000019\
Bayu Trianayasa                 05311840000038
## #2 &ndash; Kiwa
> Source code: [soal2.c](https://github.com/hisyamzf/SoalShiftSISOP20_modul2_T21/blob/master/soal2.c)

---


```
code
```


## #3 &ndash; MultiProcess
> Source code: [soal3.c](https://github.com/hisyamzf/SoalShiftSISOP20_modul2_T21/blob/master/soal3.c)

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
