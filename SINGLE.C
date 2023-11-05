#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
		int data;
		struct node *next;
	   };
	   struct node *start=NULL;
	   int item;
  void traverse(struct node *ptr);
   void insert_at_beg();
   void insert_at_end();
   void insert_at_loc();
   void del_at_beg();
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
	printf("\n\t\t Enter a choice");
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
	printf("\n Do you want to continue..");
	fflush(stdin);
	scanf("%c",&choice);
	}while(choice=='Y' || choice=='y');
 }

 void insert_at_beg()
 {
   struct node *new1;

   printf("\n Enter the value of item");
   scanf("%d",&item);
   new1=(struct node *)malloc(sizeof(struct node));
   new1->data=item;
   if(start==NULL)
   {
     new1->next=NULL;
     start=new1;
    }
    else{
	 new1->next=start;
	 start=new1;
	 }
  }

  void insert_at_end()
  {

  }

  void insert_at_loc()
  {

  }

  void del_at_beg()
  {
  }
  void del_at_end()
  {

  }
  void del_at_loc()
  {

  }

  void traverse(struct node *ptr)
  {
    ptr=start;
    if(start==NULL)
    {
      printf("\n%d",ptr->data);
      return;
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

