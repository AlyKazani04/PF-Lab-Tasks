#include <stdio.h>
#include <stdlib.h>
int main(){
	int stdnum, grdnum[stdnum];
	printf("Enter number of students : ");
	scanf(" %d", &stdnum);
	int **students = (int **)malloc(stdnum*sizeof(int*));
	if(students == NULL){
		printf("didnt not alloc");
	}
	for(int i=0; i<stdnum;i++){
		students[i] = (int *)malloc(grdnum[i]*sizeof(int));
		if(students[i] == NULL){
			printf("didnt not alloc");
		}
	}
	int var;
	for(int i=0; i<stdnum;i++){
		printf("Enter number of grades for Student %d : ", i+1);
		scanf("%d", &grdnum[i]);
		printf("Enter grades for Student %d : \n", i+1);
		for(int j=0; j<grdnum[i];j++){
			printf("\tGrade %d: ", j+1);
			scanf(" %d", &var);
			students[i][j] = var;
			var = 0;
		}
	}
	printf("Grades: \n\n");
	for(int i=0; i<stdnum;i++){
		printf("Student %d : \n", i+1);
		printf("\tStudent %d Grade : ", i+1);
		for(int j=0; j<grdnum[i];j++){
			printf(" %d ", students[i][j]);
		}
		printf("\n");
	}
	for(int i=0; i<stdnum;i++){
		for(int j=0; j<grdnum[i];j++){
			free((students+j));
		}
	}
	free(students);
	return 0;
}