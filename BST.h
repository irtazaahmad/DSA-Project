#include <bits/stdc++.h> 
#include<iostream>
#include "List.h"
#include<stdlib.h>
#include<ctime>
using namespace std;
class Node{
	public:
	string account_holder_name,cnic;
	int balance,account_no,pin;
	char  *date_created;
	Node *right,*left;
	List log;
};
class Tree{
	public:
		Node* root;
		
		Tree(){ root=NULL; }
		
		void insert(int a,int c,string d,string e,int f,string date="NULL"){
			Node* nodeptr;
			Node* newnode = new Node;
			newnode->account_no = a;
			newnode->balance = c;
			newnode->account_holder_name=d;
			newnode->cnic=e;
			newnode->pin=f;
			if(date=="NULL"){
				newnode->log.insert_log(c,"Deposit");
				time_t now = time(0);
				newnode->date_created = ctime(&now);
			}else{
				char *arr =new char[date.length()+1];
				strcpy(arr, date.c_str());
				newnode->date_created=arr;
			}
			
			newnode->left=newnode->right=NULL;
			
			if(!root)
				root=newnode;
			else{
				nodeptr=root;
				while(nodeptr){
					if(a>nodeptr->account_no){
						if(nodeptr->right)
						nodeptr=nodeptr->right;
						else{
							nodeptr->right=newnode;
							break;
						}
					}
					else if(a<nodeptr->account_no){
						if(nodeptr->left)
						nodeptr=nodeptr->left;
						else{
							nodeptr->left=newnode;
							break;
						}
					}
					else{
						delete newnode;
						break;
					}
				}
			}
		}
		
		bool cnic_existance(string a){
			int bal,pin,acc;
			string name,cnic,space,date;
			fstream file;
			bool found = false;
			file.open("Data/accounts_data.txt");
			while(file>>acc){
				file.ignore();
				getline(file,name);
				getline(file,cnic);
				file>>pin;
				file.ignore();
				getline(file,date);
				file>>bal;
				file.ignore();
				getline(file,space);
				if(cnic==a){
					found = true;
					break;
				}
				
			}file.close();
			
			return found;
		}
		
		bool existance(int a){
			bool status = false;
			Node* temp=root;
			
			while(temp){
				if(temp->account_no==a){
					status = true;
					break;
				}
				else if(a>temp->account_no)
					temp=temp->right;
				else
					temp=temp->left;
			}
			return status;
		}
		
		Node* search(int a){
			Node* temp=root;
			
			while(temp){
				if(temp->account_no==a){
					break;
				}
				else if(a>temp->account_no)
					temp=temp->right;
				else
					temp=temp->left;
			}
			return temp;
		}
		
		Node * minValueNode(Node* node){
		   Node* current = node;
		   while (current && current->left != NULL)
		      current = current->left;
		   return current;
		}

		Node* deleteNode(Node* n, int x){
		   if (n == NULL) return n;
		      if (x < n->account_no)
		         n->left = deleteNode(n->left, x);
		      else if (x > n->account_no)
		         n->right = deleteNode(n->right, x);
		   else{
		      if (n->left == NULL){
		         Node *temp = n->right;
		         free(n);
		         return temp;
		      }
		      else if (n->right == NULL){
		         Node *temp = n->left;
		         free(n);
		         return temp;
		      }
		      Node* temp = minValueNode(n->right);
		      n->account_no = temp->account_no;
		      n->right = deleteNode(n->right, temp->account_no);
		   }
		   return n;
		}

};
