//Linked list : Inserting a node at the beginning
#include<stdio.h>
#include<stdlib.h>
void insert(int x);
void print();
struct Node{
        int data;
        struct Node* next;
    };
struct Node* head;
void insert(int x)
{
    struct Node* temp = (Node* )malloc(sizeof(struct Node));   //creating a node
    (*temp).data = x;    // alternate syntax: temp->data = x;
    (*temp).next = NULL;
    if(head != NULL) temp->next = head;
    head = temp ;
}
void print()
{
    struct Node* temp = head;
    while(temp != NULL)
    {
        printf("%d",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main(){
    head = NULL;
    printf("How many numbers?\n");
    int n,i,x;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the number\n");
        scanf("%d",&x);
        insert(x);
        print();
    }
   


}
