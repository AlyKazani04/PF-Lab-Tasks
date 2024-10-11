#include <stdio.h>
int main(){
	int num;
	printf("Provide a number of rows: \n");
	scanf(" %d", &num);
	int i=0, j=num, spaces=num;
	while(i!=num+1){
		while(j>=0){
			while(spaces>=0){
				printf(" ");
			}
			spaces-=2;
			printf("*");
			j-=2;
		}
		printf("\n");
		i++;
	}
}