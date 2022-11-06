#include <error.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#define ture 1
int main(int argc ,char *argv[] ,char* envp[]){
	pid_t pid;
	int i,j;
	char ch1[10]; 
	char ch3[10][200];
	char* ch[10] ;
	
	fflush(stdin);

	printf("请输入命令字符\n");
	scanf("%s",ch1);
	ch[0] = ch1;
	i=1;
	while(getchar() == ' '){
		scanf("%s",ch3[i-1]);
		ch[i] = ch3[i-1];
		i++;
	}
	ch[++i] == NULL;	
	
	pid = fork();
	if (pid < 0){
		printf("创建进程失败\n");
		exit(-1);
	}else if (pid == 0){
		execvp(ch[0] ,ch);
	}else {
		wait(pid);
		printf("\n子进程运行结束\n");
	}

}
