#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
		int data;
		struct node *next;
	   };
	   struct node *start=NULL;
 
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
         insert_at_beg();
         break;
	    case 2:
		 insert_at_end();
		 break;
	    case 3:
		 insert_at_loc();
		 break;
	    case 4:
		 del_at_beg();
		 break;
	    case 5:
		 del_at_end();
		 break;
	    case 6:
		 del_at_loc();
		 break;
	    case 7:
		 traverse(start);
		 break;
	    default:
         printf("\n Invalid choice");
	}
	printf("\n Do you want to continue..? for yes press Y or y: ");
	fflush(stdin);
	scanf("%c",&choice);
	}while(choice=='Y' || choice=='y');
}

void insert_at_begin()
{
    struct node *new1;
    int item;
    printf("\n Enter the value of item: ")
    scanf("%d",&item);
    
    new1=(struct node *)malloc(sizeof(struct node));
    new1->data=item;

    if(start==NULL)
    {
        new1->next=NULL;
        start=new1;
    }
    else
    {
        new1->next=start;
        start=new1;
	}
}


void insert_at_end()
{
    struct node *new1,*ptr;
    int item;
    printf("\n Enter the value of item: ")
    scanf("%d",&item);
    
    new1=(struct node *)malloc(sizeof(struct node));
    new1->data=item;
    new1->next=NULL;

    if(start==NULL)
    {
        start=new1;
    }
    else
    {
	    ptr=start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=new1;
    }   
}

void insert_at_loc()
{
    struct node *new1,*ptr;
    int item,i=1,loc;
    printf("\n Enter the value of item and location of item: ")
    scanf("%d",&item);
    
    new1=(struct node *)malloc(sizeof(struct node));
    new1->data=item;

    if(start==NULL)
    {
        printf("!!List is Empty!!");
    }
    else if(start->next==NULL)
    {
        printf("Insertion not Possible");
    }
    else
    {
	 ptr=start;
     while(i<loc)
     {
        ptr=ptr->next;
        i+=1;
     }
     new1->next=ptr->next;
     ptr->next=new1;
    }
}

void del_at_begin()
{
    struct node *ptr;

    if(start==NULL)
        printf("List is Empty");
    
    else
    {
        ptr=start;
        start=ptr->next;
        printf("Deleted item is=%d",ptr->data);
        free(ptr);
    }
}

void del_at_end()
{
   struct node *ptr,*tmp;

    if(start==NULL) //check if list is empty
        printf("List is Empty");
    
    else if(start->next==NULL) //if only one node found
    {
        ptr=start;
        start=NULL;
        printf("Deleted item is=%d",ptr->data);
        free(ptr);
    }
    else //if more than one node exist
    {
        ptr=start;
        while(ptr->next!=NULL)
        {
            tmp=ptr;
            ptr=ptr->next;
        }
        temp->next=NULL;
        printf("Deleted item is=%d",ptr->data);
        free(ptr);
    }
}
void del_at_loc()
{
    struct node *ptr,*tmp;
    int i=1,loc;

    if(start==NULL) //check if list is empty
        printf("List is Empty");
    
    else if(start->next==NULL) //if only one node found
    {
        printf("Deletion not Possible..!")
    }
    else //if more than one node exist
    {
        ptr=start;
        while(i<loc)
        {
            tmp=ptr;
            ptr=ptr->next;
            i+=1;
        }
        temp->next=ptr->next;
        printf("Deleted item is=%d",ptr->data);
        free(ptr);
    }  
}

void traverse(struct node *ptr)
{
    ptr=start;
    if(start==NULL)
    {
      printf("List is empty");
    }
    else
    {
       while(ptr!=NULL)
       {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
       }
    }
}
