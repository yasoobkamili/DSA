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
    printf("enter the value and position respectively for insertion:\n");
    scanf("%d%d",&val,&x);
    insert(val,x);
    display();

    return 0;
}

void insert(int value, int k){
    
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));   // declaring the node i want to insert
    temp->data = value;
    if (k == 1){       // insert at the head
        temp->next = head;
        head = temp;
        return;
    }

    else{

        struct Node* temp_1 = head;         // storing head for travering
        int i;
        for(i=2; i<k; i++){
            temp_1 = temp_1->next;   // travering to the kth position
            if(temp_1 == NULL){
                printf("Invalid position.\n");
                return;
            }
        }
        temp->next = temp_1->next;
        temp_1->next = temp;
    }
}

void display(){
    printf("List is: [ ");
    struct Node* current = head;
	while(current != NULL){
	    printf("%d",current->data);
            if(current->next!=NULL)
	    printf(", ");
	    current = current->next;
        
    }
    printf(" ]\n");
}

