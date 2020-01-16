#include <stdio.h>

struct Node{
	int data;
	Node* next;
};

struct Stack{
	Node* head=NULL;

	void print()
	{
		Node* p;
		p=head;
		if(p==NULL) printf("Empty List\n");
		for(p=head;p!=NULL;p=p->next)
		{
			printf("%d ",p->data);
		}
		printf("\n");
	}

	void insert_first(int data)
	{
		Node* temp=new Node;
		temp->data=data;
		temp->next=head;
		head=temp;

	}

	void insert_Last(int data)
	{
		Node* temp=new Node;
		Node* p=head;
		Node* q;
		temp->data=data;
		while(p!=NULL)
		{
			q=p;
			p=p->next;
		}
		q->next=temp;

	}
	void delete_first()
	{
		head=head->next;
	}

	void delete_last()
	{
		Node* p;
		while(head->next!=NULL)
		{
			p=head;
			head=head->next;
		}
		p=NULL;
	}
	Node* srs_max()
	{
		int p=head->data;
		Node* h=head;
		while(head!=NULL)
		{
			head=head->next;
			if(p<head->data){
				p=head->data;
				h=head;
			}
		}
		printf("%d\n",h->data);
		return h;
	}

};

int main()
{
	struct Stack a;
	int x,n;
	printf("1. to push data from first.\n2. to push data from first.\n3. to print data.\n4. to delete data from first.\n5. to delete data from last.\n6. to show max\n0. to exit\n");
	while(1)
	{
		scanf("%d",&x);
		if(x==1){
			scanf("%d",&n);
			a.insert_first(n);
		}
		else if(x==2){
			scanf("%d",&n);
			a.insert_Last(n);
		}
		else if(x==3){
			a.print();
		}
		else if(x==4){
			a.delete_first();
		}
		else if(x==5){
			a.delete_last();
		}
		else if(x==6){
			a.srs_max();
		}
		else if(x==0) return 0;

	}
	return 0;
}
