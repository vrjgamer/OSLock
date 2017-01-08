#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
	
	char ct[100];
		
	printf("Lock.c started\n");
        while(1){
        	scanf("%s",ct);
		//memmove(c,c+44,strlen(c));
        	printf("input %s",ct);
		if(ct[0] == 'S'){
		    printf("Unlocked!!\n");
		}else if(ct[0]=='F'){
		    printf("locked!!\n");   
		}	
 }
	return 0;		

}
