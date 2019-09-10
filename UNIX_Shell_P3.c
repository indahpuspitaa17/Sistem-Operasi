/*
Shell
=====
Shell adalah program yang membuat proses child untuk menjalankan string perintah yang diberikan.
Shell berupa infinite looping yang berisi siklus fork--exec--wait.
Lengkapilah kode berikut ini untuk membuat program shell sederhana!
Contoh masukan dan keluaran
---------------------------
    $ date
    Tue Dec  9 13:34:17 WIB 2014
    $ whoami
    auriza
    $ exit
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

// pecah string per kata
void split_words(char *string, char **words)
{
    int i;
    words[0] = strtok(string, " \n");
    for (i = 0; words[i]; i++)
        words[i+1] = strtok(NULL, " \n");
}

int main()
{
    char cmd[80];                           //  string perintah
    char *args[20];                         //  argumen string perintah

    while (1)
    {
        //  cetak prompt "$ "
		printf("$ ");
		
        //  baca string perintah
		fgets(cmd, sizeof cmd, stdin);	
        
        //  pecah string perintah per argumen
		split_words(cmd, args);
		
        //  jika perintah = "exit"
        if (!strcmp(args[0], "exit"))
			break;	//      break
			
        //  jika perintah = "cd"
        if(!strcmp(args[0], "cd")) {
			int balik;
			
			//      ganti direktori
			if (args[1]) {
				char *dir = args[1];
				balik = chdir(dir);
				if (balik == -1) {
					puts("No such file or directory");
				}
			}
			//      continue
			else {
				chdir("/home/student");
			}
			continue;
		}
		
        //      cetak pesan error
		pid_t pid = fork();
		
		int balik;
		
		//  buat proses child:
		if (pid == 0) {
			//      exec string perintah
			balik = execlp(args[0], *args, NULL);
			//      keluar dengan kode -1
			if (balik == -1) {
				puts("command not found");
			}
		}
		//  tunggu child selesai
		else {
			wait(NULL);
		} 
    }

    return 0;
}
