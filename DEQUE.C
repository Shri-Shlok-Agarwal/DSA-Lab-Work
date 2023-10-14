#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
# define MAXSIZE 10

void dqinsert_front();
void dqinsert_rear();
int dqdel_front();
int dqdel_rear();
void traverse();

int dq[MAXSIZE],i,item,front=-1,rear=-1;

void main(){
   int ch; char choice; clrscr();

   do{
      printf("\n\t1-Insertion from front");
      printf("\n\t2-Insertion from rear");
      printf("\n\t3-Deletion from front");
      printf("\n\t4-Deletion from front");
      printf("\n\t5-Traverse");
      printf("\nInsert Your Choice: ");
      scanf("%d",&ch);

      switch(ch){
	 case 1:
	    dqinsert_front();
	    break;

	 case 2:
	    dqinsert_rear();
	    break;

	 case 3:
	    i=dqdel_front();
	    printf("\nDeleted Value is=%d",i);
	    break;

	 case 4:
	    i=dqdel_rear();
	    printf("\nDeleted Value is=%d",i);
	    break;

	 case 5:
	    traverse();
	    break;

	 default:
	    printf("\n!!Invalid Input!!");

      } //End of Switch Block
      printf("\nDo you want to continue");
      fflush(stdin);
      printf("\nfor yes press Y or y");
      scanf("%c",&choice);

   }while(choice=='Y' || choice=='y');  //End of do-while block
}//End of main program

//dqinsert_front Function
void dqinsert_front(){
   if (front==0 && rear==MAXSIZE-1){
      printf("\ndq is full");
      getch();
      exit(0);
   }
   else{
      printf("\nEnter a value");
      scanf("%d",&item);

      if (front==-1){
	 front=rear=0;
	 dq[front]=item;
      }
      else if(front ==0 && rear!=MAXSIZE-1){
	 for(i=rear;i>=front;i--){
	    dq[i+1]=dq[i];
	 }
	 dq[front]=item;
	 rear = rear+1;
      }
      else if (front>0){
	 front=front-1;
	 dq[front]=item;
      }
   }
}

//dqinsert_rear Function
void dqinsert_rear(){
   if (front==0 && rear==MAXSIZE-1){
      printf("\ndq is full");
      getch();
      exit(0);
   }
   else{
      printf("\nEnter a value");
      scanf("%d",&item);

      if (front==-1){
	 front=rear=0;
	 dq[rear]=item;
      }
      else if(front>0 && rear==MAXSIZE-1){
	 for(i=front;i>=rear;i++){
	    dq[i-1]=dq[i];
	 }
	 dq[rear]=item;
	 front = front-1;
      }
      else if (rear!=MAXSIZE-1){
	 rear=rear+1;
	 dq[rear]=item;
      }
   }
}

//dqdel_front Function
int dqdel_front(){
   if (front==-1){
      printf("\ndq is empty");
      getch();
      exit(0);
   }
   else{
      item=dq[front];
      if (front==rear){
	 front=rear-1;
      }
      else
	 front=front+1;
   }
   return(item);
}

//dqdel_rear Function
int dqdel_rear(){
   if (front==-1){
      printf("\ndq is empty");
      getch();
      exit(0);
   }
   else{
      item=dq[rear];
      if (front==rear){
	 front=rear-1;
      }

      else{
	 rear=rear-1;
      }
   }
   return(item);
}

//Traverse Function
void traverse(){
   if (front==-1){
      printf("\ndq is empty");
      getch();
      exit(0);
   }
   else{
      for (i=front;i<=rear;i++){
	 printf("\n%d",dq[i]);
      }
   }
}