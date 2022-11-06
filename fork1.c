#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main(){
	int data = 0;
	pid_t pid;
	int choose = 0;
	while ((choose = getchar()) != 'q'){
		switch (choose){
			case '1':
				pid = fork();
				if (pid < 0){
					printf ("Error !\n");
				}
				if (pid == 0){
					data++;
					exit(0);
				}
					wait(pid);
				if (pid > 0){
					printf("data is %d\n",data);
				}
				break;
			case '2':
				pid = vfork();
				if (pid < 0){
					perror("Error!\n");
				}
				if (pid == 0){
					data++;
					exit(0);
				}
				wait(pid);
				if (pid > 0){
					printf("data is %d\n",data);
				}
				break;
			defult:
				break;
		}
	}
}
