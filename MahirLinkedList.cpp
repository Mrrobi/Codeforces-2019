#include<bits/stdc++.h>
using namespace std;


struct node{
	int data;
	node *next;
};

node *head = NULL;
node *last = NULL;

node* create(int data){
	node *nw = new node();
	nw->data = data;
	nw->next = NULL;
	return nw;
}

void finsert(int data){
	if(head==NULL){
		head = create(data);
		last = head;
	}else{
		node *temp = create(data);
		temp->next = head;
		head = temp;
	}
}

void minsert(int data){
	if(head==NULL){
		head = create(data);
		last = head;
	}else if(data<head->data){
		node *temp = create(data);
		temp->next = head;
		head = temp;
	}else{
		node *temp = head;
		while(temp->next!=NULL&&temp->next->data>data){
			temp = temp->next;
		}
		node *nw = create(data);
		nw->next = temp->next;
		temp->next=nw;
	}
}

void linsert(int data){
	if(head==NULL){
		head = create(data);
		last = head;
	}else{
		node *nw = create(data);
		last->next = nw;
		last = nw;
	}
}

void show(){
	node *temp = head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp = temp->next;
	}
	cout<<endl;
}

//eta hocchilo na baki gulo thik ase
//void pop(){
//	node *temp = head;
//	while(temp!=NULL&&temp->next!=NULL){
//		temp = temp->next;
//	}
//	if(temp==head){
//		head = NULL;
//	}else{
//		temp = NULL;
//	}
//}

int main(){
	
	int ch;
	while(1){
		cout<<"1.First Insert"<<endl;
		cout<<"2.Middle Insert"<<endl;
		cout<<"3.Last Insert"<<endl;
		cout<<"4.Show"<<endl;
		cout<<"5.Push"<<endl;
		//cout<<"6.Pop"<<endl;
		cin>>ch;
		switch(ch){
			case 1:
				int temp;
				printf("Enter a data: ");
				scanf("%d",&temp);
				finsert(temp);
				break;
			case 2:
				printf("Enter a data: ");
				scanf("%d",&temp);
				minsert(temp);
				break;
			case 3:
				printf("Enter a data: ");
				scanf("%d",&temp);
				linsert(temp);
				break;
			case 4:
				show();
				break;
			case 5:
				printf("Enter a data: ");
				scanf("%d",&temp);
				finsert(temp);
				break;
			//case 6:
				//pop();
				//break;
		}
	}
}

