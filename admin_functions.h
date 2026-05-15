#include<iostream>
#include<iomanip>
#include<conio.h>
using namespace std;

void display_account(Node*);
void display_header();
void in_order_display(Node*);
bool validate_name(string);
bool validate_cnic(string);
void open_account(){
	string name,cnic;
	int balance,pin,account_no;
	system("cls");
	display_title();
	cout<<"\n\n";
	cout<<"\t\t\t\t\t\t\t\t\t\t\t          Open Account ";
	cout<<"\n\n\n";
	cout<<"\t\t\t\t\t\t\t\t\t\t\tEnter Account Holder Name : ";
	cin.ignore();
	getline(cin,name);
	while(validate_name(name)==false)
	{
		cout<<"\t\t\t\t\t\t\t\t\t\t\tEnter name again :";
		getline(cin,name);
		validate_name(name);
	}
	while(true){
		cout<<"\t\t\t\t\t\t\t\t\t\t\tEnter CNIC (xxxxxxxxxxxxx) : ";
		getline(cin,cnic);
		while(validate_cnic(cnic)==false)
		{
			cout<<"\t\t\t\t\t\t\t\t\t\t\tEnter Valid CNIC (xxxxxxxxxxxxx) : ";
			getline(cin,cnic);
			validate_cnic(cnic);
		}
		if(bank.cnic_existance(cnic)){
			cout<<"\t\t\t\t\t\t\t\t\t\t\tThis CNIC is already used ! \n";
		}else{
			break;
		}
	}
	
	do{
		cout<<"\t\t\t\t\t\t\t\t\t\t\t    Balance (Minimum - 2000PKR) : ";	
		cin>>balance;
	}while(balance<2000);
	string cnfrm;cin.ignore();
	cout<<"\t\t\t\t\t\t\t\t\t\t\t     Press 1 for confirm : ";
	getline(cin,cnfrm);
	if(cnfrm=="1"){
		srand(time(0));
		account_no=rand();
		while(bank.existance(account_no)){
			account_no=rand();
		}
	
		pin=(rand() % (9999 - 1000 + 1)) + 1000;
		bank.insert(account_no,balance,name,cnic,pin);
		Update_File();
		system("cls");
		display_title();
		cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t Account Opened Successfuly!";
		cout<<"\n\t\t\t\t\t\t\t\t\t\t\t Account No. : "<<account_no;
		cout<<"\n\t\t\t\t\t\t\t\t\t\t\t Pin : "<<pin;
		char a;
		cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t Press any key to go Back  ";
		a=getch();
		system("cls");
		display_title();
		
		return;
	}
	system("cls");
	display_title();
}

void account_details(){
	system("cls");
	display_title();
	int num;
	cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t     See Account Details ";
	cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t    Enter Account Number : ";
	cin>>num;
	
	Node* ref = bank.search(num);
	
	if(ref){
		system("cls");
		display_title();
		cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t       Account Details \n\n";
		display_header();
		display_account(ref);	
	}
	else{
		system("cls");
		display_title();
		cout<<"\t\t\t\t\t\t\t\t\t\t\t       Account Not Found! ";
		return;
	}
	
	char a;
	cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t      Press any key to go Back  ";
	a=getch();
	system("cls");
	display_title();
	
}

void all_account_details(){
	system("cls");
	display_title();
	if(!bank.root){
		cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t        No Accounts are Created";
		return ;
	}
	cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t        All Account Details \n\n";
	display_header();
	in_order_display(bank.root);
	char a;
	cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t        Press any key to go Back  ";
	a=getch();
	system("cls");
	display_title();
}

void delete_account(){
	system("cls");
	display_title();
	int num;
	cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t     Delete Account ";
	cout<<"\n\n\t\t\t\t\t\t\t\t\t\t  Enter Account Number For Deletion : ";
	cin>>num;
	
	Node* ref = bank.search(num);
	
	if(ref){
		int a;
		cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t      Account Found! ";
		cout<<"\n\n\t\t\t\t\t\t\t\t\t\t  Press 1 for Deletion 0 for back : ";
		cin>>a;
		if(a==1){
			ref->log.~List();
			bank.root=bank.deleteNode(bank.root,num);
			system("cls");
			display_title();
			Update_File();
			cout<<"\t\t\t\t\t\t\t\t\t\t\t    Account Deleted Successfuly! ";
		}else{
			system("cls");
			display_title();
		}
			
	}
	else{
		system("cls");
		display_title();
		cout<<"\t\t\t\t\t\t\t\t\t\t\t        Account Not Found For Deletion! ";
		return;
	}
	
}

void account_logs(){
	system("cls");
	display_title();
	int num;
	cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t       Account Logs ";
	cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t   Enter Account Number : ";
	cin>>num;
	
	Node* ref = bank.search(num);
	
	if(ref){
		system("cls");
		display_title();
		cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t          Account Logs \n\n";
		cout<<"\t\t\t\t\t\t\t\t\t\t\t      Account Number : "<<num<<" \n\n";
		cout<<"\t\t\t\t\t\t\t\t\t\t\t      Current Balance : "<<ref->balance<<" \n\n";
		ref->log.display();			
	}
	else{
		system("cls");
		display_title();
		cout<<"\t\t\t\t\t\t\t\t\t\t\t        Account Not Found! ";
		return;
	}
	
	char a;
	cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t        Press any key to go Back  ";
	a=getch();
	system("cls");
	display_title();
	
}

void in_order_display(Node *n){
	if(n){
		in_order_display(n->left);
		display_account(n);
		in_order_display(n->right);
	}
}

void display_header(){
	cout<<"\t\t------------------------------------------------------------------------------";
	cout<<"--------------------------------------------------------------------------"<<endl;
	cout<<left;
	cout<<"\t\t"<<setw(5)<<""<<setw(20)<<"Account No."<<setw(5)<<"|"<<setw(30)<<"Account Holder's Name"<<setw(5)<<"|"<<setw(22)<<"CNIC";
	cout<<setw(5)<<"|"<<setw(15)<<"Balance"<<setw(5)<<"|"<<setw(30)<<"Date Created"<<setw(5)<<"\n";
	cout<<"\t\t-----------------------------------------------------------------------------";
	cout<<"--------------------------------------------------------------------------"<<endl;
}

void display_account(Node*n){
	
	cout<<"\t\t"<<setw(5)<<""<<setw(20)<<n->account_no<<setw(5)<<"|"<<setw(30)<<n->account_holder_name<<setw(5)<<"|"<<setw(22)<<n->cnic<<setw(5)<<"|";
	cout<<setw(15)<<n->balance<<setw(5)<<"|"<<setw(30)<<n->date_created<<setw(5)<<"\n";
	cout<<"\t\t-----------------------------------------------------------------------------";
	cout<<"--------------------------------------------------------------------------"<<endl;
	

}

bool validate_name(string name){
	int i=0;
	while(name[i]!='\0')
	{
	if ( !(( name[i] >= 'a' && name[i] <= 'z') || ( name[i] >= 'A' && name[i] <= 'Z') || name[i] == ' '))
                {
                    return false;
                }
		i++;
	}
	return true;
}

bool validate_cnic(string cnic){
	int counter=0;
	for(int i=0;i<cnic.length();i++){	
	
		if(cnic[i]<48 || cnic[i]>57){
			return false;
		}
		counter++;
	}
	if(counter==13)
	return true;
	else
	return 
	false;
}
