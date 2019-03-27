#include<stdlib.h>
#include<stdio.h>

int front=-1,rear=-1;

FILE*fs,*fp;
int B[100];



typedef struct node
{
	int data;
	char colour;
	struct node* par;
	struct node* next;
}node;

node*A[100];
int dequeue(int B[]);
void insert(node** A,int v1,int v2);
void bfs(node** A,int s);
void dfs(node** A,int s);
void enqueue(int B[],int k);

int main()
{
	node*temp=NULL;
	int i,j,v1,v2,k,v,s,e;
	char ch;

	fs=fopen("input.txt","r");
	fp=fopen("output.txt","w");

	fscanf(fs,"%d",&v);
	fscanf(fs,"%d",&e);

	for(i=0;i<v;i++)
	{
	temp=(node*)malloc(sizeof(node));
	temp->data=i;
	temp->next=NULL;
	temp->colour='w';
	temp->par=NULL;
	A[i]=temp;
	}
		
	for(i=0;i<e;i++)
	{
		fscanf(fs,"%d",&v1);
		fscanf(fs,"%d",&v2);

		insert(A,v1,v2);

		//node* u=A[v1]->next;
	}
	fscanf(fs,"%d",&s);
	bfs(A,s);

	for(i=0;i<v;i++)
	{
	A[i]->colour='w';
	}
	fprintf(fp,"\n");
	dfs(A,s);
}
//=========================================================
void insert(node** A,int v1,int v2)
{
	node*head=A[v1];
	node*p=head;

	node* newnode=(node*)malloc(sizeof(node));
	newnode->data=v2;
	newnode->next=NULL;
	newnode->colour='w';

	while(head->next!=NULL)
		{head=head->next;}
	head->next=newnode;

}
//======================================================

void bfs(node** A,int s)
{
	int k;

	node*temp3;
	node*temp4;
	node*temp2=A[s];
	temp2->colour='g';
	temp2->par=NULL;

	enqueue(B,temp2->data);

	while(front <=rear)
	{
	//printf("suhas\n");
		k=dequeue(B);
		temp3=A[k];
		temp4=temp3->next;
		while(temp4!=NULL)
		{
		    if(A[temp4->data]->colour=='w')
			{
				A[temp4->data]->colour='g';
				//temp4->par=temp3;
				enqueue(B,temp4->data);
			}
		temp4=temp4->next;
		}
	temp3->colour='b';
	fprintf(fp,"%d ",temp3->data);
	}
}	
//=========================================
void dfs(node** A,int s)
{
	int k;
	node*temp3;
	node*temp4;
	node*temp2=A[s];
	temp2->colour='g';
	temp4=temp2->next;

	fprintf(fp,"%d ",temp2->data);

	while(temp4!=NULL)
	{
		if(A[temp4->data]->colour=='w')
		{
		A[temp4->data]->colour=='g';
		dfs(A,temp4->data);
		}
		A[temp4->data]->colour=='g';
	temp4=temp4->next;
	}
	return;
}
//=============================================

void enqueue(int B[],int k)
{
if(front==-1)
	front=0;
//rear++;
B[++rear]=k;

//return 0;
}
//=========================================
int dequeue(int B[])
{
	int item;
	item=B[front];
	front++;

	/*if(front > rear)
	{
		rear=-1;
	front=-1;
	}*/
	return item;
}
//==================================================
