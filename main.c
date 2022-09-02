#include <stdio.h>
#include <stdlib.h>
typedef struct
{
int data;
struct Node*next;
struct Node*prev;
} Node;

typedef struct
{
Node*head;
Node*tail;
} LinkedList;
LinkedList* init()
{

LinkedList*l=malloc(sizeof(LinkedList));
l->head=NULL;
l->tail=NULL;
return l;
}
Node* newNode(int x)
{
Node * n =malloc(sizeof(Node));
n->data=x;
n->next=NULL;
n->prev=NULL;
return n;
}

//Complexity O(1)
void insertBegining(LinkedList*list,int
x)
{
Node* n =newNode(x);
if(list->head==NULL)//list is empty
{
list->head=n;
list->tail=n;
}
else
{
n->next=list->head;
list->head->prev=n;
list->head=n;
}
}

//Complexity O(1)
void insertEnd(LinkedList*list,int x)
{
Node* n =newNode(x);
if(list->head==NULL)//list is empty
{
list->head=n;
list->tail=n;
}
else
{
list->tail->next=n;
n->prev=list->tail;
list->tail=n;
}
}

//Complexity O(1)
int isEmpty(LinkedList*list)
{
if (list->head==NULL)
return 1;
else
return 0 ;
}
void deleteBegining(LinkedList*list)
{
if(list->head==NULL)
return ;

Node*temp=list->head;

// when list only have 1 node and deleted
//if(list->head==NULL)
//ist->tail=NULL;
//else // head is not null
//{
Node*p=(list->head->next);
p->prev=NULL;
list->head=p;
free(temp);

//}

}
/*void deleteLastNode(LinkedList*list)
{
if(!list->head) // list is empty
return ;
else if(list->head->next==NULL)
//only one node
{
free(list->head);
list->head=NULL;
list->tail=NULL;
}
else
{
Node*temp=list->head;
//get node before Tail
Node*prev=NULL;
while(temp->next!=NULL)
{
prev=temp;
temp=temp->next;
}
prev->next=NULL;
list->tail=prev;
free(temp);
}/*
}//
Can be done in O(1) we can get prev to
//tail without loop
//Complexity O(1)
void deleteLastNode(LinkedList*list)
{
if(!list->head) // list is empty
return ;
else if(list->head->next==NULL)
//only one node
{
free(list->head);
list->head=NULL;
list->tail=NULL;
}
else
{
Node*temp=list->tail;
//get node before Tail
Node*prev=list->tail->prev;
prev->next=NULL;
list->tail=prev;
free(temp);
}
}
//Complexity O(n)
void display(LinkedList*list)
{
Node* temp=list->head;
while(temp!=NULL)
{
printf("%d ",temp->data);
temp=temp->next;
}
}
void displayReversed(LinkedList*list)
{
Node* temp=list->tail;
while(temp!=NULL)
{
printf("%d ",temp->data);
temp=temp->prev;
}
}*/
//Complexity O(n)
void display(LinkedList*list)
{
Node* temp=list->head;
while(temp!=NULL)
{
printf("%d ",temp->data);
temp=temp->next;
}
}
void displayReversed(LinkedList*list)
{
Node* temp=list->tail;
while(temp!=NULL)
{
printf("%d ",temp->data);
temp=temp->prev;
}
}
void deleteLastNode(LinkedList*list)
{
if(!list->head) // list is empty
return ;
else if(list->head->next==NULL)
//only one node
{
free(list->head);
list->head=NULL;
list->tail=NULL;
}
else
{
Node*temp=list->tail;
//get node before Tail
//Node*prev=list->tail->prev;
//prev->next=NULL;
list->tail=list->tail->prev;
list->tail->next=NULL;
free(temp);
}
}


int main()
{
LinkedList*list =init();
insertBegining(list,5);
insertBegining(list,7);
insertBegining(list,8);
insertEnd(list,4);
insertEnd(list,3);
insertEnd(list,1);
display(list);
printf("\n");
//displayReversed(list);
//printf("\n");
deleteBegining(list);
display(list);printf("\n");

deleteLastNode(list);
display(list);
printf("\n");
//displayReversed(list);

return 0;
}
