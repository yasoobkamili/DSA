//deletion of node at kth position of linked list
// CSE-23-46
#include<stdio.h>
#include<stdlib.h>

void insert(int, int);
void delete(int, int);
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
    //call for deletion
    int v ,t;
    printf("enter the value and position to delete respectively:\n");
    scanf("%d%d",&v,&t);
    delete(v,t);
    display();

    return 0;
}

void delete(int value , int k){
    if(head==NULL){
        printf("You are trying to delete from empty list !!!\n");
        return;
    }
    struct Node* temp = head;  // storing head for safety
    if(k==1){
        head = head->next;
    }
    else{

        int i=2;
        struct Node* prev = temp;  // prev is pointing to first node
        struct Node* pres = temp->next;  // pres is pointing to 2nd node
        while(i<k && pres!=NULL){
        prev = pres;
        pres = pres->next;
        i++;
        }
        if(i==k && (pres->data) == value){
            prev->next = pres->next;
            free(pres);
        }
        else{
            printf("Wrong combination entered.\n");
        }
    }
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
            temp_1 = temp_1->next;
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
    printf("List is: ");
    struct Node* current = head;
	while(current != NULL){
		printf("%d ",current->data);
		current = current->next;
    }
    printf("\n");
}
