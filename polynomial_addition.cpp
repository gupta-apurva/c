#include<stdio.h>
#include<stdlib.h>
struct poly
{
	float coeff;
	int expo;
	struct poly*next;
};
void poly_create(struct poly**,int);
void poly_add(struct poly*,struct poly*,struct poly**);
struct poly*insert(struct poly*,float,int);
void traverse(struct poly*);
int main()
{
		struct poly*head1=NULL;
		struct poly*head2=NULL;
		struct poly*head3=NULL;
		int n,ch;
		while(1)
		{
			printf("\n1.create\n\n2.add\n\n3.traverse\n\n4.resultant\n\n0.exit\n\nchoice...:");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:printf("\n enter the no of exponent of 1st poly");
				scanf("%d",&n);
				poly_create(&head1,n);
				printf("\nenter the no of exponent of 2nd poly");
				scanf("%d",&n);
				poly_create(&head2,n);
				break;
				case 2:
				poly_add(head1,head2,&head3);
				printf("\n 1st poly\n:");
				traverse(head1);
				printf("\n 2nd poly\n:");
				traverse(head2);
				break;
			}
		}
}
void poly_create(struct poly**head,int n)
{
	int i,e;
	float c;
	struct poly*newnode,*temp;
	if(*head!=NULL)
		return;
	for(i=1;i<=n;i++)
	{
		newnode=(struct poly*)malloc(sizeof(struct poly));
		printf("\nenter the co-effiencent");
		scanf("%f",&c);
		printf("\n enter the exponent");
		scanf("%d",&e);
		newnode->coeff=c;
		newnode->expo=e;
		newnode->next=NULL;
		if(*head==NULL)
			*head=newnode;
		else
			temp->next=newnode;
			temp=newnode;
	}
	return;
}
void poly_add(struct poly*head1,struct poly*head2,struct poly**head3)
{
	struct poly*loc1,*loc2;
	float s=0;
	loc1=head1;
	loc2=head2;
	while(loc1!=NULL && loc2!=NULL)
	{
		if(loc1->expo==loc2->expo)
		{
			s=loc1->coeff+loc2->expo;
			if(s!=0)
			{
				*head3=insert(*head3,s,loc1->expo);
				loc1=loc1->next;
				loc2=loc2->next;
			}
			else if(loc1->expo>loc2->expo)
			{
				*head3=insert(*head3,loc2->coeff,loc1->expo);
				loc1=loc1->next;
			}
			else
			{
				*head3=insert(*head3,loc2->coeff,loc2->expo);
				loc2=loc2->next;
			}
			
		}
		while(loc1!=NULL)
		{
			*head3=insert(*head3,loc1->coeff,loc1->expo);
			loc1=loc1->next;
		}
		while(loc2!=NULL)
		{
			*head3=insert(*head3,loc2->coeff,loc2->expo);
			loc2=loc2->next;
		}
		return;
	}
}
	struct poly*insert(struct poly*head,float c,int e)
	{
		struct poly*newnode,*loc;
		newnode=(struct poly*)malloc(sizeof(struct poly));
		newnode->coeff=c;
		newnode->expo=e;
		newnode->next=NULL;
		loc=head;
		if(loc==NULL)
			head=newnode;
		else
		{
			while(loc->next!=NULL)
			{
				loc=loc->next;
			}
			loc->next=newnode;
		}
		return head;
		
	}
	void traverse(struct poly*head)
	{
		struct poly*loc;
		loc=head;
		while(loc!=NULL)
		{
			printf("\n%gx^%d+",loc->coeff,loc->expo);
			loc=loc->next;
		}
	}
