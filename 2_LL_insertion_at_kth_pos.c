//insertion at kth position of linked list
// CSE-23-46
#include<stdio.h>
#include<stdlib.h>

void insert(int , int);
void display();
struct Node{
    int data;
    struct Node* next;
};
struct Node* head;  // declaration of head node which will point to first element

int main(){
    head = NULL;
    int n,i;
    printf("How many values do you want to insert?\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        int value;
        printf("Enter the value to insert:\n");
        scanf("%d",&value);
        insert(value,i+1);
    }
    display();
    // call for insertion at position x
    int val,x;
    printf("enter the value and position respectively:\n");
    scanf("%d%d",&val,&x);
    insert(val,x);
    display();

    return 0;
}

void insert(int value, int k){
    int i = 2;
    struct Node* temp_1 = head;         // storing head to be safge
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));   // declaring the node i want to insert
    temp->data = value;
    if (k == 1) {       // insert at the head
        temp->next = head;
        head = temp;
        return;
    }
    struct Node* previous = temp_1;         // here previous is in 1st node 
    struct Node* current = temp_1->next;    // here present is in 2nd node
    while(i<k && current!=NULL){ 
        // in this loop we will shift prev and curr forward until current is pointing to kth element 
        previous = current; 
        current = current->next;
        i++;
    }
    if(i==k){
        previous->next = temp;  //updating link of previous to point to temp
        temp->next = current;   //updating link of temp to point to current
    }
    else{
        printf("Invalid Position");
    }
}

void display(){
    printf("List is: ");
    struct Node* current = head;
	while(current != NULL){
		printf("%d ",current->data);
		current = current->next;
    }
    printf("\n");
}

