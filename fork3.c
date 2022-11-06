#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int main(){
	int fd[2] ,statu ,i ,j;
	pid_t pid;
	char ch1[150]; 
	char* ch[] = {"管道文件的测试程序开始","管道文件测试正在进行","管道通信测试结束"};	
	if(statu = pipe(fd)){
		perror("pipe error");
		exit(-2);
	}
	switch (pid = fork()){
		case -1 :
			perror("fork error");
			break;
		case 0 :
			close(fd[0]);
			printf("子进程pid：%d\n",getpid());
			for(i = 0 ;i < 3 ;i++){
				fflush(stdout);
				if(! write(fd[1] ,ch[i] ,strlen(ch[i])))
					printf("cant write");
				sleep(1);
			}
			break;
		default :
			printf("主进程pid：%d\n",getpid());
			close(fd[1]);
			for (i = 0 ;i < 3 ;i++){
				read(fd[0] ,ch1 ,150);
				fflush(stdout);
				printf("%s\n",ch1);
				for(j = 0 ;ch1[j] ; j++)
					ch1[j] = '\0';
				sleep(1);
			}
	}
}
