#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int val;
	struct Node *next,*prev;
}node;

node* head=NULL;
node* tail=NULL;

void delete(node * del)
{
	if(head==NULL)
	{
		return;
	}
	if(head==tail)
	{
		if(head==del)
		{
			head=tail=NULL;
			free(del);
		}
		return;
	}
	if(del==head)
	{
		head=del->next;
		head->prev=NULL;
		free(del);
		return;
	}
	if(del==tail)
	{
		tail=tail->prev;
		tail->next=NULL;
		free(del);
		return;
	}

	del->prev->next=del->next;
	del->next->prev=del->prev;
	free(del);
	return ;
}

void insert(int value)
{
	node * temp= (node *)malloc(sizeof(node));
	temp->val=value;
	if(head==NULL)
	{
		temp->next=NULL,temp->prev=NULL;
		head=tail=temp;
		return;
	}

	tail->next=temp;
	temp->prev=tail;
	temp->next=NULL;
	tail=temp;
	return ;
}

void print()
{
	node * cur = head;
	while(cur!=NULL)
	{
		printf("%d ",cur->val);
		cur = cur -> next;
	}
}
int main()
{
	int n,i,x,count=0;
	scanf("%d",&n);
	int size=n,ans=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		insert(x);
	}
	//    print();
	node * cur,*temp;
	int flag=1;
	while(count<n)
	{
		if(flag==1)
		{
			cur=head;
			while(cur!=NULL)
			{
				if(count>=cur->val)
				{
					count+=1;
					temp=cur->next;
					delete(cur);
					cur=temp;
				}
				else 
					cur=cur->next;

				if(cur==NULL && flag==1)
					flag=-1,ans+=1;
			}
		}
		else if(flag==-1)
		{
			cur=tail;
			while(cur!=NULL)
			{
				if(count>=cur->val)
				{
					count+=1;
					temp=cur->prev;
					delete(cur);
					cur=temp;
				}
				else 
					cur=cur->prev;

				if(cur==NULL && flag==-1)
					flag=1,ans+=1;
			}
		}

	}

	printf("%d\n",ans-1);

	return 0;
}