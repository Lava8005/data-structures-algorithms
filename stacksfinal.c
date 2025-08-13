// we are making a text editor which can undo and redo the characters typed in 
// For this we will have to create 2 stacks , the first one will store the current words typed and the second one will store the charactes which were popped so that we can restore them 
// we will use the array based stacks and fix the size to 100 words and for each word to have 25 characters 
// we will add Enter String , Undo , Redo , View Current Text and exit 
// the flow will be first the user will be asked to enter a word of max 49 chars + null char , then it will be pushed onto the Undo stack which will be the main stack
// second they will be given the menu from which they can choose one of the actions
// first we will make the undo redo stacks , then push and pop , after which peek and view current and then main
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
char undo[MAX][50];
char redo[MAX][50];
int topUndo = -1;
int topRedo = -1;
// Now we will create push , for which we need to look at 2 scenarios first if the space in stack is over then to give a warning message and if not then to store
void push(char sentence[]){
    if (topUndo == MAX - 1){
        printf("Stack Overflow !!!");
        return ; 
    }
    strcpy(undo[++topUndo], sentence) ; // here we store the value in the stack
}
// Now for the pop function we will remove the value at the top of the undo stack and store it in the redo stack so for this we need to create 2 pop functions 
void popUndotoRedo(){
    if(topUndo == -1){ 
        printf("Stack Underflow !!!");
        return;
    } // We have to copy strings now so we use strcpy(destination,source) 
    strcpy(redo[++topRedo],undo[topUndo--]);//this will increase space in redo stack by 1 copy string from the undo stack and remove the string from undo stack
}
void popRedotoUndo(){
    if (topRedo == -1){
        printf("Stack Underflow !!!");
        return;
    }
    strcpy(undo[++topUndo],redo[topRedo--]);
}
// To view the current stack we will use the loop and print function
void Display(){
    if(topUndo == -1){
        printf("The Editor is EMPTY .\n");
        return ; 
    }
    printf("Editor-: \n");
    for(int i=0;i<=topUndo;i++){
        printf("%s ",undo[i]);
    }
    printf("\nTHE END.\n");
}
// Now we print the menu and take in the text write the main
int main(){
    int choice;
    char text[50];
    printf("\n TEXT EDITOR \n");
    while (1){
    printf("If you wish to \n 1) Type in a sentance ENTER 1. \n 2) Undo your actions ENTER 2. \n 3) Redo your actions ENTER 3. \n 4) Display the current editor ENTER 4. \n 5) EXIT ENTER 5. \n ENTER YOUR CHOICE : ");
    scanf("%d",&choice);
    getchar(); //this will clear the additional newline created
    // Using the switch case 
    switch (choice) {
        case 1: 
            printf("Enter Sentance: ");
            fgets(text,sizeof(text),stdin);
            text[strcspn(text, "\n")] = 0; //this will remove the new line and fgets keeps the sentance from overflowing
            push(text);
            topRedo = -1;
            break;
        case 2:
            popUndotoRedo();
            break;
        case 3:
            popRedotoUndo();
            break;
        case 4:
            Display();
            break;
        case 5:
            printf(" EXIT \n");
            exit(0);
        default:
            printf("Invalid Choice !!!");

    }
  }
  return 0;

}
