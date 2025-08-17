#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int top=-1;
void push(int arr[],int *top,int value){
    arr[++(*top)] = value;
}
int pop(int arr[],int *top){
    if (*top == -1){
        return -1;
    }
    return arr[(*top)--];
}
void display(int arr[],int top){
    for(int i=0;i<=top;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int checker(int arr[], int top) {
    for(int i = 0; i < top; i++) {
        if(arr[i] < arr[i+1]) { 
            return 0; // bigger disc on smaller one
        }
    }
    return 1;
}
// this function will check if the discs are in a decending order or not
int wincondition(int arrx[], int arry[], int arrz[], int n, int top1, int top2, int top3){
    int countx = top1 + 1;
    int county = top2 + 1;
    int countz = top3 + 1;

    if(countx==n && county==0 && countz==0){
        return checker(arrx, top1);
    }
    if(county==n && countz==0 && countx==0){
        return checker(arry, top2);
    }
    if(countz==n && countx==0 && county==0){
        return checker(arrz, top3);
    }
    return 0;
}
// this will check that if all the discs are in any of the discs then if they are in correct order 
int move(int from,int to,int arr1[],int arr2[],int arr3[],int *top1,int *top2,int *top3){
    int disk;
    if(from ==1){
        if(*top1==-1){
            return 0;
        }
        disk = pop(arr1, top1);
    }
    else if(from==2){
        if (*top2==-1){
            return 0;
        }
        disk = pop(arr2,top2);
    }
    else if (from==3){
        if(*top3==-1){
            return 0;
        }
        disk = pop(arr3, top3);
    }
    // all of these will pop now for push
    if(to==1){
        push(arr1,top1,disk);
    }
    else if (to==2){
        push(arr2,top2,disk);
    }
    else if (to==3){
        push(arr3,top3,disk);
    }
    return 1;
}
// now we will need the input from the user 
int main(){
    int n,destirod,sourcerod,x;
    printf("\n########## TOWER OF HANOI ##########\n");
    n=3;
    int arr1[n],arr2[n],arr3[n];
    int from = 0;
    int to = 0;
    printf("Enter the Source Rod: ");
    scanf("%d",&from);
    printf("Enter destination rod: ");
    scanf("%d",&to);
    int top1=-1,top2=-1,top3=-1;
    // here we have collected all the data from user now for the game to start , we will now build the source rod 
    printf("# ## ### GAME STARTS # ## ###\n");
    switch(from){
        case 1:{
            for(int i=n;i>=1;i--){
                push(arr1,&top1,i);
            }
            break;
        }
        case 2: {
            for(int i=n;i>=1;i--){
                push(arr2,&top2,i);
            }
            break;
        }
        case 3: {
            for(int i=n;i>=1;i--){
                push(arr3,&top3,i);
            }
            break;
        }
    }
    // this will build the source array now for the display and moves 
    while(1){
        printf("Rod 1: "); display(arr1, top1);
        printf("Rod 2: "); display(arr2, top2);
        printf("Rod 3: "); display(arr3, top3);
        printf("Enter the Source Rod: ");
        scanf("%d",&from);
        printf("Enter destination rod: ");
        scanf("%d",&to);
        if(!move(from,to,arr1,arr2,arr3, &top1, &top2, &top3)) {
            printf("Invalid move !!!");
        }
        if(wincondition(arr1,arr2,arr3,n,top1, top2, top3)){
            printf("########## THE TOWER OF HANOI IS SOLVED ##########");
            break;
        }
    }
}

    

