#include<iostream>
#include<ctime>
#include<iomanip>
using namespace std;
class listnode{
	public:
	int amount;
	string method;
	char *date;
	listnode *next;
};
class List{
	listnode *last;
	public:
		listnode *head;
		List(){ head=NULL; }
		void insert_log(int amnt,string mthd,string date="NULL"){
			
			if(head==NULL){
				head=new listnode;
				head->amount=amnt;
				head->method=mthd;
				if(date=="NULL"){
					time_t now = time(0);
					head->date = ctime(&now);
				}else{
					char *arr =new char[date.length()+1];
					strcpy(arr, date.c_str());
					head->date=arr;
				}
				head->next=NULL;
				last=head;
			}else{
				listnode *newnode=new listnode;
				newnode->amount=amnt;
				newnode->method=mthd;
				if(date=="NULL"){
					time_t now = time(0);
					newnode->date = ctime(&now);
				}else{
					char *arr =new char[date.length()+1];
					strcpy(arr, date.c_str());
					newnode->date=arr;
				}
				newnode->next=NULL;
				last->next=newnode;
				last=newnode;
			}
		}
		void display(){
			listnode* temp=head;
			int i=1;
			cout<<"\t\t\t\t\t\t\t\t------------------------------------------------------------------------------"<<endl;
			cout<<left;
			cout<<"\t\t\t\t\t\t\t\t"<<setw(3)<<""<<setw(10)<<"S.No"<<setw(5)<<"|"<<setw(15)<<"Amount"<<setw(5)<<"|"<<setw(10)<<"Method"<<setw(5)<<"|"<<setw(30)<<"Date"<<endl;
			cout<<"\t\t\t\t\t\t\t\t------------------------------------------------------------------------------"<<endl;
			while(temp){
				cout<<"\t\t\t\t\t\t\t\t"<<setw(3)<<""<<setw(10)<<i<<setw(5)<<"|"<<setw(15)<<temp->amount<<setw(5)<<"|"<<setw(10)<<temp->method<<setw(5)<<"|"<<setw(30)<<temp->date<<endl;
				cout<<"\t\t\t\t\t\t\t\t------------------------------------------------------------------------------"<<endl;
				temp=temp->next;
				i++;
			}
			
		}
		~List(){
			listnode* currNode = head, *nextNode = NULL;
			while (currNode != NULL)
			{
			nextNode = currNode->next;
			// destroy the current node
			delete currNode;
			currNode = nextNode;
			
			}
		}
};
