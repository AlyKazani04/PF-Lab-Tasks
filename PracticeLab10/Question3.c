#include <stdio.h>
typedef struct Book{
		char title[50];
		char author[50];
		int isbn;
		int publication_year;
		int status;
}Book;
void addBook(Book book[], int *num, int addcount){
	for(int i = *num; i < *num + addcount ; i++){
		printf("Enter Book %d Title : ", i+1);
		scanf("%s", book[i].title);
		printf("Enter Book %d Author : ", i+1);
		scanf("%s", book[i].author);
		printf("Enter Book %d isbn : ", i+1);
		scanf("%s", &book[i].isbn);
		printf("Enter Book %d publication year : ", i+1);
		scanf("%d", &book[i].publication_year);
		while(1){
			printf("Enter Book %d Availability(1 for Available, 0 for Not Available): ", i+1);
			scanf("%d", &book[i].status);
			if(book[i].status==0 || book.status==1){
				break;
			}
			else{
				printf("Invalid Availability, try again.\n");
			}
		}
	}
	*num += addcount;
	printf("_________________________\n\n");
}

void searchBookTitle(Book book[], char arr[], int num){
	int found = 0;
	for(int i = 0; i<num ; i++){
		if(strcmp(book[i].title, arr)==0){
			printf("Book %d Title= %s\n", i+1, book[i].title);
			printf("Book %d Author = %s\n", i+1, book[i].author);
			printf("Book %d ISBN = %d\n", i+1, book[i].isbn);
			printf("Book %d Publication Year = %d\n", i+1, book[i].publication_year);
			if(book[i].status==1){
				printf("Availability: Available\n");
			}
			else{
				printf("Availability: Not Available\n");
			}
			printf("\n");
			found = 1;
		}
	}
	if(!found){
		printf("Did Not Find %s\n", arr);
	}
	printf("_________________________\n\n");
	return;
}

void searchBookAuthor(books book[], char arr[], int num){
	int found = 0;
	for(int i = 0; i<num ; i++){
		if(strcmp(book[i].author, arr)==0){
			printf("Book %d Title = %s\n", i+1, book[i].title);
			printf("Book %d Author = %s\n", i+1, book[i].author);
			printf("Book %d ISBN = %d\n", i+1, book[i].isbn);
			printf("Book %d Publication Year = %d\n", i+1, book[i].publication_year);
			if(book[i].status==1){
				printf("Availability: Available\n");
			}
			else{
				printf("Availability: Not Available\n");
			}
			printf("\n");
			found = 1;
		}
	}
	if(!found){
		printf("Did Not Find %s\n", arr);
	}
	printf("_________________________\n\n");
	return;
}

int main(){
	Book book[100];
	int num=0, n, addcount;
	char arr[100];
	while(1){
		printf("Enter 1 to Add Book, 2 to Search for a book or 0 to End : ");
		scanf("%d", &n);
		switch(n){
			case 1:
				printf("Enter the number of Books you would like to add : ");
				scanf("%d", &addcount);
				addBook(book, &num, addcount);
				break;
			case 2:
				printf("Search by Title(Enter 1) or Author(Enter 2) or Enter 0 to Cancel :");
				scanf("%d", &search);
				if(search==0){
					break;
				}
				if(search==1){
					printf("Enter Title:");
					scanf("%s", &arr);
					searchBookTitle(book, arr, num);
					break;
				}
				else if(search==2){
					printf("Enter Author:");
					scanf("%s", &arr);
					searchBookAuthor(book, arr, num);
					break;
				}
			case 0:
				printf("Operation Ended.\n");
				return 0;
			default:
				printf("Invalid Entry Try Again\n");
		}
	}
	return 0;
}