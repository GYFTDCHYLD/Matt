#include <stdio.h>
#include <stdlib.h>
//Mathew Reid

typedef struct{
    int Id;
    char Name[20];
    char Status;
    char Location;	
}Book;
Book Books[50];// array to store 50 items											

void Menu();
void Select(int choice);
void addBook();
void loanBook();
void viewBooks();
int index,i;
int id = 1;

int main(){
	index = 0;
	for(i = 0; i < 20; i++){
		Books[i].Id = 0;
	}
	Menu();	
	return 0;
}


void Menu(){ // this function return an int for the option selected to be utilized by the select function  
	
	int option;

    printf("________________________\n");
    printf("|         Menu         |\n");
    printf("|  1. Add Book         |\n");
    printf("|  2. Loan Book        |\n");
    printf("|  3. View Books       |\n");
    printf("|  4. Exit             |\n");
    printf("|______________________|\n");
    printf(" Choice: ");
	
	scanf("%d", &option);
    
    Select(option);
}



void Select(int choice){// this function use the value returned by the main function 

	switch (choice) {
    case 1: addBook();
			break;
			
    case 2: loanBook();
			break;
			
    case 3: viewBooks();
			break;
	case 4: system("exit");
			break;
			
	default:
	    	printf("\n  Invalid Option*");
	}
} 
	

void addBook(){
	if(index == 49){// handle the error if user tries to enter item when list has reach the limit
		printf("The shelf is full");
	}else{	
		printf("\n Your Book ID is %d: ",id);
		Books[index].Id = id;
		Books[index].Status = 'A';
		printf("\n Please enter name of book:");
		scanf("%s", Books[index].Name);//sstore the data in the correct index of the list
		
		printf("\n Please enter location to store book, Shelf:");
		scanf("%s", &Books[index].Location);	
	}
	index ++;
	fflush(stdin);
	Menu();
}

void loanBook(){
	int index = 0;
	int key;
	int flag = 0;
	printf("\n Please Id# of book wish to loan: ");
	scanf("%d", &key);
	while(Books[index].Id > 0){
	    if(Books[index].Id == key && Books[index].Status == 'A'){
	        Books[index].Status = 'L';
	        flag = 1;
	    }
		index ++;
	}
	if(flag == 1){
	   printf("\n Book was Loaned successfully: "); 
	}else{
	     printf("\n Book was not found: "); 
	}
	fflush(stdin);
	Menu();
}

void viewBooks(){
	int index = 0;
	printf(" Id \t Name \t Location \t  Status\n");
	for(index = 0; index < 50; index++){
	    if(Books[index].Id != 0){
    		printf("%d ",Books[index].Id);
    		printf("%s \t",Books[index].Name);
    		printf("%c \t",Books[index].Location);
    		printf("%c \n",Books[index].Status);
	    }
		index++;
	}
	fflush(stdin);
	Menu();		
}
