#include <stdio.h>
int main(){
	int num;
	printf("Provide a number of rows: \n");
	scanf(" %d", &num);
	int i=0, j=0;
	while(i != num+1){
		while(j != num+1){
			printf("*");
			j++;
		}
		printf("\n");
		i++;
		j=i;
	}
}