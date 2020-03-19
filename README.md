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

```
##### Penjelasan soal 2a
```
  rawtime = time(NULL);
  timeinfo = localtime ( &rawtime ); 
  strcpy (file, "/home/osboxes/modul2/");
  strftime (lalaland, SIZE, "%Y-%m-%d_%H:%M:%S", timeinfo);
  strcat (file, lalaland);

    child = fork();
   if (child == 0) {
     sleep(30);
     char *argv[] = {"mkdir","-p",file,NULL};
     execv("/bin/mkdir", argv);
   } 
 ```
 - `rawtime = time(NULL);`, untuk mengambil local time pada linux.
 - `timeinfo = localtime ( &rawtime ); `, membuat variabel `timeinfo` untuk menyimpan local waktu yang telah diperoleh.
 - `strcpy (file, "/home/osboxes/modul2/");`. `strcpy` untuk meng-copy `"/home/osboxes/modul2/"` ke variabel string file.
 - `strftime (lalaland, SIZE, "%Y-%m-%d_%H:%M:%S", timeinfo);`. `strftime` fungsi untuk format tanggal dan waktu dan diambil dari variable string timeinfo tersebut.
 - `strcat (file, lalaland);`, untuk menggabungkan isi dalam `file` dan `lalaland`.
 - ` sleep(30);`, memberikan jeda waktu 30 detik antara pembuatan file/direktori pertama dengan direktori selanjutnya.
 - `char *argv[] = {"mkdir","-p",file,NULL};`, untuk membuat direktori baru dengan nama format dari `file` berupa timestamp dan isi dari direktori tersebut kosong.



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
    char *argv[] = {"mkdir","-p","/home/osboxes/modul2/indomie",NULL};
    execv("/bin/mkdir", argv);
  }
        while((waitpid(child,&status,0))>0);
  child1 = fork();
  if (child1 == 0) {
    sleep(5);
    char *argv[] = {"mkdir","-p","/home/osboxes/modul2/sedaap",NULL};
    execv("/bin/mkdir", argv);
  }
        while((waitpid(child1,&status,0))>0);
  child2 = fork();
  if (child2 == 0) { 
    char *argv[] = {"unzip","/home/osboxes/modul2/jpg.zip","-d","/home/osboxes/modul2",NULL};
    execv("/usr/bin/unzip", argv);
  }
        while((waitpid(child2,&status,0))>0);
  child3 = fork();
  if (child3 == 0){
    char *argv[] = {"find","/home/osboxes/modul2/jpg",
                    "-mindepth","1","-type","f","-exec","mv",
                    "{}","/home/osboxes/modul2/sedaap",
                    ";",NULL};
    execv("/usr/bin/find", argv);
  }

        while((waitpid(child3,&status,0))>0);
  child4 = fork();
  if (child4 == 0){
    char *argv[] = {"find","/home/osboxes/modul2/jpg",
                    "-mindepth","1","-type","d","-exec","mv",
                    "{}","/home/osboxes/modul2/indomie",
                    ";",NULL};
    execv("/usr/bin/find", argv);
  }
        while((waitpid(child4,&status,0))>0);
  child5 = fork();
  if (child5 == 0){
    char *argv[] = {"find","/home/osboxes/modul2/indomie","-mindepth","1","-type","d","-exec","touch","{}/coba1.txt","'\'",";",NULL};
    execv("/usr/bin/find", argv);
  }
        while((waitpid(child5,&status,0))>0);
  child6 = fork();
  if (child6 == 0) {
    sleep(3);
    char *argv[] = {"find","/home/osboxes/modul2/indomie","-mindepth","1","-type","d","-exec","touch","{}/coba2.txt","'\'",";",NULL};
    execv("/usr/bin/find", argv);
  }  
}
```

##### Penjelasan soal 3a
```
child = fork();
  if (child == 0) {
    char *argv[] = {"mkdir","-p","/home/osboxes/modul2/indomie",NULL};
    execv("/bin/mkdir", argv);
  }
  ```
  - `child = fork()`, untuk membuat proses baru (child) dengan menduplikasi proses utama.
  - `child == 0`, bernilai sama dengan 0 untuk menandakan bahwa proses tersebut sukses.
  - `char *argv[]`, mendeklarasikan sebuah penyimpanan hasil dari proses/perintah di dalamnya.
  - `"mkdir","-p","/home/osboxes/modul2/indomie",NULL`. `mkdir` untuk membuat sebuah direktori/folder baru. `-p` yang berarti parent atau path yang berarti membuat semua direktori yang ada mengarah ke direktori baru/yang belum ada sebelumnya. `/home/osboxes/modul2/indomie` adalah untuk mengarah tempat pembuatan direktori baru di dalam folder modul2 dengan nama indomie.
  - `execv("/bin/mkdir", argv);`, mengeksekusi argv.
  
  ```
  while((waitpid(child,&status,0))>0);
  child1 = fork();
  if (child1 == 0) {
    sleep(5);
    char *argv[] = {"mkdir","-p","/home/osboxes/modul2/sedaap",NULL};
    execv("/bin/mkdir", argv);
  }
  ```
  - `while((waitpid(child,&status,0))>0)`, untuk menunggu child proses untuk berhenti 
  - `sleep(5)`, untuk memberikan jeda 5 detik dalam pembuatan antara output satu dengan output selanjutnya. Di soal ini, memberikan jeda pembuatan direktori indomie dengan direktori sedaap.
  - `/home/osboxes/modul2/sedaap`, membuat direktori baru di dalam modul2 dengan nama sedaap.
  
 ##### Penjelasan soal 3b
 ```
  child2 = fork();
  if (child2 == 0) { 
    char *argv[] = {"unzip","/home/osboxes/modul2/jpg.zip","-d","/home/osboxes/modul2",NULL};
    execv("/usr/bin/unzip", argv);
  }
  ```
  - `unzip -d`, untuk meng-unzip sebuah folder/file 
  - `"/home/osboxes/modul2/jpg.zip","-d","/home/osboxes/modul2"`. `/home/osboxes/modul2/jpg.zip` untuk menunjukkan letak dari file/folder yang akan di unzip. `/home/osboxes/modul2` menentukan tempat untuk unzip dari folder tersebut.
  
##### Penjelasan soal 3c
```
if (child3 == 0){
    char *argv[] = {"find","/home/osboxes/modul2/jpg",
                    "-mindepth","1","-type","f","-exec","mv",
                    "{}","/home/osboxes/modul2/sedaap",
                    ";",NULL};
    execv("/usr/bin/find", argv);
  }
  ```
  - `"find","/home/osboxes/modul2/jpg"`, berfungsi untuk menemukan isi/file/direktori yang sedang dicari dalam direktori/folder jpg.
  - `"-mindepth","1"`, fungsi yang menandakan bahwa proses masuk ke dalam direktori tujuan sejumlah satu kali saja. Fungsi ini masih berhubungan dengan fungsi `find`. Fungsi ini mengecek semua isi dalam direktori tujuan tersebut.
  - `"-type","f"`, fungsi ini juga masih berhubungan dengan find dimana menjelaskan kepada proses bahwa untuk mencari isi di dalam direktori tujuan dengan tipe data file.
  - `"mv",{}","/home/osboxes/modul2/sedaap"`, untuk memindahkan suatu file yang telah ditemukan tersebut ke direktori/folder sedaap.

```
child4 = fork();
  if (child4 == 0){
    char *argv[] = {"find","/home/osboxes/modul2/jpg",
                    "-mindepth","1","-type","d","-exec","mv",
                    "{}","/home/osboxes/modul2/indomie",
                    ";",NULL};
    execv("/usr/bin/find", argv);
  }
  ```
  Program diatas sama halnya dengan program diatas, perbedaannya adalah menemukan isi dengan tipe data directory/folder dan memindahkannya ke directory/folder indomie.
  
##### Penjelasan soal 3d
```
 child5 = fork();
  if (child5 == 0){
    char *argv[] = {"find","/home/osboxes/modul2/indomie","-mindepth","1","-type","d","-exec","touch","{}/coba1.txt","'\'",";",NULL};
    execv("/usr/bin/find", argv);
  }
```
- `touch`, command ini berfungsi untuk membuat sebuah file/direktori tanpa isi apapun didalamnya. Dalam soal ini, program diatas membuat file `coba1.txt` ke dalam direktori indomie.

```
child6 = fork();
  if (child6 == 0) {
    sleep(3);
    char *argv[] = {"find","/home/osboxes/modul2/indomie","-mindepth","1","-type","d","-exec","touch","{}/coba2.txt","'\'",";",NULL};
    execv("/usr/bin/find", argv);
 }
 ```
 - program diatas untuk membuat file `coba2.txt` ke dalam direktori indomie.
