#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* head = NULL;
struct Node* tail = NULL;
int Length(){
    // This function will give the total length of the linked lists and will also put a fail safe if the user enters an incorrect position.
    // To make this we will have to use a loop that will increse the value of an integer l till the variable returns null value 
    struct Node* size = head;
    int count = 0;
    while(size!=NULL){
        count++;
        size = size -> next;
    }
    return count;
}
void Insert(int x,int y){
    int len = Length(); // this will be our fail safe
    if(x<1||x>len+1){
        printf("Invalid Position to insert, the current length of list is %d .\n",len);
        return;
    }
    // here we will ask the user at which point and what value they wish to store.
    struct Node*temp1 = (struct Node*)malloc(sizeof(struct Node));
    temp1 -> data = y;
    temp1 -> next = NULL;
    if(x==1){
        temp1 -> next = head;
        head = temp1 ;
        return ; 
    }
    struct Node*temp2 = head;
    for(int i=0;i<x-2;i++){
        temp2 = temp2->next;
    }
    temp1 -> next = temp2 -> next;
    temp2->next = temp1;
    if(temp1->next == NULL){
        tail = temp1;
    } // this will store the last position in tail if needed later on.
    // here what we do is we first connect the new box of value and pointer to what will come after it and then connect the previous box to the new box since there is only a one way connection.
}
void Delete(int w){
    int len = Length(); //This will again be our fail safe
    if(w<1||w>len ){
        printf("Invalid Position to delete, the current length of list is %d .\n",len);
        return;
    }
    // To delete at a particular node we will have to go there and then free it 
    // now this is a one sided connection , so we will have to go to 2 positions before the node to be deleted then go to the node after the node to be deleted save the position of the n+1 node in the n-1 node and then free the n node
    struct Node* temp3 = head;
    if(w==1){
        head = temp3 -> next ; 
        free(temp3);
     }
    else{
        // if it is not the head node being deleted we need to travese to the n-2 th node 
        for(int i=0;i<w-2;i++){
            temp3 = temp3->next;
        }
        struct Node* temp4 = temp3->next;
        temp3->next = temp4->next;
        free(temp4);
    }
};
void Print(){
// here we will use the loop to traverse the list and print each element.
    struct Node* temp = head;
    printf("The Data Set:  ");
    while (temp != NULL){
        printf(" %d",temp->data);
        temp = temp -> next;
    }
    printf("  END \n");
};
void Reverse(){
    // 1 METHOD IS THAT WE CAN USE ITERATION TO REVERSE THE LIST i.e USE LOOPS 
    struct Node *current,*previous,*upcomming; // we define al 3 states 
    current = head; // say that the starting node will be head
    previous = NULL; // since we wish to reverse the node the head node must be pointing to null
    while(current!=NULL){ // now till the current node is not equal to null loop will work
        upcomming = current -> next; // the next position will be stored in upcomming since after the reverse the connection will break
        current -> next = previous;// the position of the previous node will be stored in the previous variable 
        previous = current;// we say that the value at the previous position is equal to the current possition  
        current  = upcomming; // and that the current value is now equal to the upcomming position 
    }
    head = previous; // we say that at the end the last node is stored in previous so head = previous and since it is a one way connection all the other nodes fall behind thereby reverseing the list
    printf("The List has been Succesfully Reversed ...\n");
}
void PrintReverse(struct Node* temp){ // now in main if we pass head in the parameter i.e temp = head 
    //Now this will only print out the reversed list and will not change the actual value of the list.
    if(temp == NULL) return; // Now here we dont want the loop to run infinitly so here we write if the pointer is void then end the loop
    PrintReverse(temp->next); // we call upon the function itself creating a loop  , and from head it goes to the next node
    printf("%d ",temp->data); // and here we print the data that is at the position 
}; //FIRST THE QUEUE WILL BE STACKED THAT IS IT WILL CALL THE FUCNTION THROUGH RECURSION TILL IT GETS TO THE END OF THE LIST AND THEN IT WILL START PRINTING
// there is also a third way to reverse a ll using recursion this will permanently reverse the list like the iterative method
void ReverseRecurrsion(struct Node*temp){
    if (temp == NULL||temp -> next == NULL){
        head = temp; // therefore the temp var becomes the new head.
        return; // this will help not run the loop infinitely.
    }
    ReverseRecurrsion(temp->next); // Now we go deeper in the list 
    temp -> next -> next = temp; //will go 2 nodes ahead and declare that as the temp var
    temp -> next = NULL; // this breaks the forward link
};
void SetTail(){
    tail = head;
    while(tail&&tail->next ){
         tail = tail->next;
        }
}
int main(){
    int n,o,q,w,c;
    // Ask user how many data values they wish to add 
    // Take those and run a for loop to save those values in the nodes using a head and tail variable for the first keep head and else keep adding to tail use malloc
    //Ask user 1. if they wish to insert , 2. if they wish to delete , 3. if they wish to print the lists, 4. If they wish to reverse the lists , 5. End the program
    // After that use a loop for repetedly asking the user selects anything display that and if not free the ll
    printf("Enter the number of data values to be created :  ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter the %d value: ",(i+1));
        scanf("%d",&newnode->data);
        newnode -> next = NULL;
        if(head == NULL){
            head = newnode;
            tail = newnode;
        }
        else{
            tail->next = newnode;
            tail = newnode;

        } // this wil ask and store the values provided by the user.
    }
    // now we call the print function to print the list once
    Print();
    // Now we ask the user if they wish to do any more operations,we will loop this so that the user can access this we use the do while loop.
    do{
        printf("If you wish to \n 1. Insert Another Data To Set Enter : 1\n 2. Delete Data Enter : 2\n 3.Print The Final List Enter : 3\n 4. Reverse the given list Enter : 4 \n 5. To Find the Length of list Enter: 5\n 6. To Exit the Program Enter : 6");
        scanf("%d",&o);
        if(o==1){
        printf("Enter the Position at which you wish to insert the element : ");
        scanf("%d",&q);
        printf("Enter the value to be entered at %d position : ",q);
        scanf("%d",&w);
        Insert(q,w);
        printf("The Data value has been Inserted Succesfully...");
    }
    else if(o==2){
        printf("Enter the Position of Data to be deleted: ");
        scanf("%d",&q);
        Delete(q);
        printf("The Data value has been deleted Succesfully...");
    }
    else if(o==3){
        Print();
    } 
    else if(o==4){
        Reverse();
        SetTail();//This will save the last position of the linked list for further use if any
    }
    else if(o==5){
        printf("The Length of the list is: %d .",Length());
    }
}
while( o!=6);                

    // here we will free the dynamically allocated data.
    // To do that we need to first count the total number of nodes
    struct Node* temp5 = head;
    while(temp5!=NULL){
        struct Node* temp6 = temp5->next;
        free(temp5);
        temp5 = temp6;
    }
    return 0;

}