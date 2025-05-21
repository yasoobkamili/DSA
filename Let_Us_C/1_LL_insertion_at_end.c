// multiple insertions at the end of the linked list
// CSE-23-46
#include<stdio.h>
#include<stdlib.h>
void insert_node(int value);  // functioni to insert nodes at the end
struct Node{
    int data;
    struct Node* next;
};
struct Node* A = NULL ;

int main(){
    int num,i,value;
    printf("How many values?\n");
    scanf("%d",&num);
    for(i=0;i<num;i++){
        printf("Enter value %d\n",i+1);
        scanf("%d",&value);
        insert_node(value);
    }
    //printing linked list nodes one by one
    struct Node* current = A;
    while(current != NULL){
        printf("Data is %d\nNext is %p\n",current->data,current->next);
	current = current->next;
    }
	return 0;
}

void insert_node(int value){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;

    if(A == NULL){
        A = temp;
    }
    else{
    struct Node* current = A;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = temp;        
    }
}
