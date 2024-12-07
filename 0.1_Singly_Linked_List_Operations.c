// implementation of some operations on singly linked list using functions

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head ;

void traverse(struct Node* head){
    //function okay
    struct Node* current = head ;
    while(current != NULL){
        printf("%d ",current->data);
        current = current->next;
        if(current != NULL)
            printf("-> ");
        
    }
    printf("\n");

}

void insert_at_end(int value){          //function okay tested
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL) { // Check if memory allocation is successful
        printf("Memory allocation failed!\n");
        return;
    }
    temp->data = value;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
    }
    else{
        struct Node* current = head;
        while(current->next!=NULL){
            current = current->next;
        }
        current->next = temp;
    }
    
}

void insert_at_beg(int value){     //function okay tested
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    if(head==NULL){
        head = temp;
    }
    else{
        temp->next = head;
        head = temp; 
    }
}

void insert_at_k(){    //funtion okay tested
    
    int value, pos, i = 1;
    printf("enter value and position respectively for insertion: ");
    scanf("%d%d",&value,&pos);
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    if(pos==1){
        temp->next = head;
        head = temp;
    }
    else{
        struct Node* current = head;
        while(current->next!= NULL){
            current = current->next;
            i++;
            if(i==pos-1){
                temp->next = current->next;
                current->next = temp;
                return;
            }
        } 
    }
}

void delete_at_end(){    //function okay
    struct Node* prev = head;
    struct Node* pres = head->next;
    while(pres->next!=NULL){
        pres = pres->next;
        prev = prev->next;
    }
    prev->next = NULL;
    free(pres);
}

void delete_at_beg(){    //function okay
    head = head->next;
 }
struct Node* new_node(int value){    //function okay
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void search(){    //function okay ig
    int n, i=1, flag = 0;
    struct Node* current = head;
    printf("Enter the number you are looking for: ");
    scanf("%d",&n);
    while(current->next != NULL)
    {
        if(current->data == n ){
            printf("Caught at Position %d.\n",i);
            flag = 1;
        }
        
        current = current->next;
        i++;    
    }
    if(flag == 0){
        printf("Sorry! Not found\n");
    }
}

void length(){    //function okay 
    struct Node* current = head;
    int length = 0;
    while(current->next != NULL){
        length++;
        current = current->next;
    }
    printf("Length of your linked list is : %d\n",length);
}

int middle(){ //funtion okay tested
    // print the middle of a given linked list
/*
    Given a singly linked list, the task is to find the middle of the linked list. If the number of nodes are even, then there would be two middle nodes, so return the second middle node.

*/
    int count = 0;
    struct Node* current = head;
    while(current != NULL){
        count++;
        current = current->next;
    } 
    printf("count is : %d\n",count);
    current = head;
    for(int i=1; i<=(count/2); i++){
        current = current->next;
    }
    if(count%2==0){
        printf("Middle element for even list length is : %d\n",current->data);

    }
    else
        printf("Middle element for odd list length is: %d\n",current->data);

}


int main(){
    head = NULL;

    // now i'm calling the functions which i just wrote ~~~~~~~~~~~~~~~
   
    for(int i = 1; i<=14; i++){
        insert_at_end(i);
    }
    traverse(head);
    length();
    middle();

    return 0;
}





    // ignore this   |
    //               |
    //             \   /
    //              \ /
    //               *
    // struct Node* first = new_node(1);
    // struct Node* second = new_node(2);
    // struct Node* third = new_node(3);
    // struct Node* fourth = new_node(3);
    // struct Node* fifth = new_node(3);
    // head = first;
    // first->next = second;
    // second->next = third;
    // third->next = fourth;
    // fourth->next = fifth;
    // fifth->next = NULL;
    // insert_at_beg(10);
    // insert_at_end(39);
    // delete_at_end();
    // delete_at_end();
    // delete_at_beg();
    // search();
    // insert_at_k();
    // traverse(head);

    // printf("data is : %d , next is: %d\n",first->data,first->next);
    // printf("data is : %d , next is: %d\n",second->data,second->next);
    // printf("data is : %d , next is: %d\n",third->data,third->next);
    
    //              ^
    //             /|\
    // Ignore this  |   
    
    

