#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
		int data;
		struct node *next;
	   };
	   struct node *front=NULL,*rear=NULL;

void traverse(struct node *ptr);
void insert_at_begin();
void insert_at_end();
void insert_at_loc();
void del_at_begin();
void del_at_end();
void del_at_loc();

void main()
{
  int ch;
  char choice;
  do{
	clrscr();
	printf("\n\t\t 1. Insert at beginning");
	printf("\n\t\t 2. Insert at end");
	printf("\n\t\t 3. Insert at specified location");
	printf("\n\t\t 4. delete from beginning");
	printf("\n\t\t 5. delete from end");
	printf("\n\t\t 6. delete from specified location");
	printf("\n\t\t 7. Traverse");
	printf("\n\t\t Enter a choice: ");
	scanf("%d",&ch);
	switch(ch)
	{
	    case 1:
		 insert_at_begin();
		 break;
	    case 2:
		 insert_at_end();
		 break;
	    case 3:
		 insert_at_loc();
		 break;
	    case 4:
		 del_at_begin();
		 break;
	    case 5:
		 del_at_end();
		 break;
	    case 6:
		 del_at_loc();
		 break;
	    case 7:
		 traverse(front);
		 break;
	    default:
	 printf("\n Invalid choice");
	}
	printf("\n Do you want to continue..? for yes press Y or y: ");
	fflush(stdin);
	scanf("%c",&choice);
	}while(choice=='Y' || choice=='y');
getch();
}

void insert_at_begin()
{
    struct node *new1;
    //read an item
    int item;
    printf("\n Enter the value of item: ");
    scanf("%d",&item);

    new1=(struct node *)malloc(sizeof(struct node));
    new1->data=item;

    if(front==NULL)    //Check if list is empty
    {
	new1->next=new1;
	front=rear=new1;
    }
    else    //list is not empty so then add item at beginning
    {
	new1->next=front;
	rear->next=new1;
	front=new1;
    }
}


void insert_at_end()
{
    struct node *new1;

    //Insert Item
    int item;
    printf("\n Enter the value of item: ");
    scanf("%d",&item);

    new1=(struct node *)malloc(sizeof(struct node));
    new1->data=item;

    if(front==NULL)  //check if list is empty
    {
	new1->next=new1;
	front=rear=new1;
    }

    else  //if list exists
    {
	new1->next=front;
	rear->next=new1;
	rear=new1;
    }
}

void insert_at_loc()
{
    struct node *new1,*ptr,*tmp;
    int item,i=1,loc;

    //enter item in list
    printf("\n Enter the location of item: ");
    scanf("%d",&loc);
    printf("\n Enter the value of item: ");
    scanf("%d",&item);

    new1=(struct node *)malloc(sizeof(struct node));
    new1->data=item;

    if(front==NULL)
    {
	printf("!!List is Empty!!");
    }

    else   //if list exists
    {
	ptr=front;
	while(i<loc)
	{       tmp=ptr;
		ptr=ptr->next;
		i+=1;
	}
	new1->next=ptr;
	tmp->next=new1;
    }
}

void del_at_begin()
{
    struct node *ptr;

    if(front==NULL)  //check if list is empty
    {
	printf("List is Empty");
    }

    else if(front==rear) //for single node
    {
	ptr=front;
	printf("Deleted item is=%d",ptr->data);
	front=rear=NULL;
	free(ptr);
    }

    else    //for more than one node
    {
	ptr=front;
	front=rear->next=ptr->next;
	printf("Deleted item is=%d",ptr->data);
	free(ptr);
    }
}

void del_at_end()
{
   struct node *ptr,*tmp;

    if(front==NULL) //check if list is empty
	printf("List is Empty");

    else if(front==rear) //if only one node found
    {
	ptr=front;
	front=rear=NULL;
	printf("Deleted item is=%d",ptr->data);
	free(ptr);
    }
    else //if more than one node exist
    {
	ptr=front;
	while(ptr->next!=front)
	{
	    tmp=ptr;
	    ptr=ptr->next;
	}
	tmp->next=ptr->next;
	rear=tmp;
	printf("Deleted item is=%d",ptr->data);
	free(ptr);
    }
}
void del_at_loc()
{
    struct node *ptr,*tmp;
    int i=1,loc;

    if(front==NULL) //check if list is empty
	printf("\nList is Empty");

    else if(front==rear) //if only one node found
    {
	printf("\nDeletion not Possible..!");
    }
    else //if more than one node exist
    {   printf("\n Enter the location of item: ");
	scanf("%d",&loc);
	ptr=front;
	while(i<loc)
	{
	    tmp=ptr;
	    ptr=ptr->next;
	    i+=1;
	}
	tmp->next=ptr->next;
	printf("Deleted item is=%d",ptr->data);
	free(ptr);
    }
}

void traverse(struct node *ptr)
{
    ptr=front;
    if(front==NULL)
    {
      printf("List is empty");
    }
    else
    {
       do
       {
	printf("%d\n",ptr->data);
	ptr=ptr->next;
       }while(ptr!=front);
    }
}