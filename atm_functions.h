#include<iostream>
#include<unistd.h>
using namespace std;
void receipt(Node *,int,string);
int validate_amount(int);
bool atm_login(Node *&n){
	
	bool stat=0;
	int tries=3;
	int acc_num,pass;
	cin.ignore();
				
				//Attempting login till tries is not equal to zero
				
	while(tries!=0)
	{
						
		cout<<"\n\t\t\t\t\t\t\t\t\t\t\tAccount No : ";     //Asking Username 
		cin>>acc_num;
		if(!bank.existance(acc_num)){
			cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\tInvalid Account! ";
			sleep(3);
			system("cls");
			display_title();
			return false;
		}
		Node* ref = bank.search(acc_num);
		while(tries>0){
			cout<<"\n\t\t\t\t\t\t\t\t\t\t\tPIN : ";     //Asking Password
			cin>>pass;
			if(pass==ref->pin){
				system("cls");
				display_title();
				cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t  Account Logged In Successfuly! ";
				sleep(1.5);
				n=ref;
				system("cls");
				display_title();
				return true;
			}
			system("cls");
			display_title();
			tries--;
			cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t     Wrong PIN! \n";
			cout<<"\n\t\t\t\t\t\t\t\t\t\t\t  "<<tries<<" Tries Left! ";
			sleep(3);
			system("cls");
			display_title();
			cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\tAccount No : "<<acc_num<<endl;
			
		}
		return false;
	}
}

void withdraw(Node *n){
	system("cls");
	display_title();
	while(true){
		cout<<"\n\n";
		cout<<"\t\t\t\t\t\t\t\t\t\t\t               ATM ";
		cout<<"\n\n";
		cout<<"\t\t\t\t\t\t\t\t\t\t\t            Withdrawl \n\n";
		cout<<"\t\t\t\t\t\t\t\t\t\t   Account : "<<n->account_no<<"\t\tBalance : "<<n->balance<<"\n\n";
		cout<<"\t\t\t\t\t\t\t\t\t\t\t====================================\n\n";
		int amnt;
		cout<<"\t\t\t\t\t\t\t\t\t\t\t           (-1 for Back) \n";
		cout<<"\t\t\t\t\t\t\t\t\t\t\t        Amount : ";
		cin>>amnt;
		if(amnt==-1){
			system("cls");
			display_title();
			break;
		}
		else if(amnt<0){
			system("cls");
			display_title();
			cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t    Invalid Amount! \n\n";
			sleep(2);
		}
		else if(amnt>n->balance)
		{
			system("cls");
			display_title();
			cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t    Not Much Balance in Account! \n\n";
			sleep(2);
			system("cls");
			display_title();
		}
		else{
			int a;
			cout<<"\n\n\t\t\t\t\t\t\t\t\t\t  Press 1 for Confirmation 0 for back : ";
			cin>>a;
			if(a==1){
				n->balance-=amnt;
				n->log.insert_log(amnt,"Withdraw");
				Update_File();
				receipt(n,amnt,"Withdraw");
				break;
			}
			else{
				system("cls");
				display_title();
				break;
			}
			
		}
	}
	
}

void deposit(Node *n){
	system("cls");
	display_title();
	while(true){
		cout<<"\n\n";
		cout<<"\t\t\t\t\t\t\t\t\t\t\t               ATM ";
		cout<<"\n\n";
		cout<<"\t\t\t\t\t\t\t\t\t\t\t            Deposit \n\n";
		cout<<"\t\t\t\t\t\t\t\t\t\t   Account : "<<n->account_no<<"\t\tBalance : "<<n->balance<<"\n\n";
		cout<<"\t\t\t\t\t\t\t\t\t\t\t====================================\n\n";
		int amnt;
		cout<<"\t\t\t\t\t\t\t\t\t\t\t           (-1 for Back) \n";
		cout<<"\t\t\t\t\t\t\t\t\t\t\t        Amount : ";
		cin>>amnt;
		while(validate_amount(amnt)==0)
		{
			cout<<"\t\t\t\t\t\t\t\tYou cannot enter negative amount. Enter again: ";
			cin>>amnt;
			validate_amount(amnt);
		}
		if(validate_amount(amnt)==-1)
		{
			system("cls");
			display_title();
			break;
		}
		
		int a;
		cout<<"\n\n\t\t\t\t\t\t\t\t\t\t  Press 1 for Confirmation 0 for back : ";
		cin>>a;
		if(a==1){
			n->balance+=amnt;
			n->log.insert_log(amnt,"Deposit");
			Update_File();
			receipt(n,amnt,"Deposit");
			break;
		}
		else{
			system("cls");
			display_title();
			break;
		}
			
	}
	
}

void receipt(Node *n,int amnt,string mthd){
			system("cls");
			display_title();
			cout<<endl<<endl<<left;
			
			cout<<"\t\t\t\t\t\t\t\t\t         ------------------------------------------------\n";
			cout<<setw(3)<<"\t\t\t\t\t\t\t\t\t         |"<<setw(40)<<"\t           Bank Name    "<<" |";
			cout<<"\n\t\t\t\t\t\t\t\t\t         ------------------------------------------------\n"; 
			cout<<setw(3)<<"\t\t\t\t\t\t\t\t\t         |"<<setw(33)<<"\t\t      ATM Slip"<<" |";
			cout<<"\n\t\t\t\t\t\t\t\t\t         ------------------------------------------------\n";
			cout<<right;
			cout<<"\t\t\t\t\t\t\t\t\t         |"<<setw(15)<<"Account # :"<<setw(28)<<n->account_no<<setw(4)<<"|";
			cout<<"\n\t\t\t\t\t\t\t\t\t         ------------------------------------------------\n";
			if(mthd=="Withdraw"){
				cout<<"\t\t\t\t\t\t\t\t\t         |"<<setw(18)<<"Amount Withdrwan :"<<setw(25)<<amnt<<setw(4)<<"|";
				cout<<"\n\t\t\t\t\t\t\t\t\t         ------------------------------------------------\n";
				cout<<"\t\t\t\t\t\t\t\t\t         |"<<setw(19)<<"Remaining Balance :"<<setw(24)<<n->balance<<setw(4)<<"|";
			}else{
				cout<<"\t\t\t\t\t\t\t\t\t         |"<<setw(18)<<"Amount Deposit :"<<setw(25)<<amnt<<setw(4)<<"|";
				cout<<"\n\t\t\t\t\t\t\t\t\t         ------------------------------------------------\n";
				cout<<"\t\t\t\t\t\t\t\t\t         |"<<setw(19)<<"New Balance :"<<setw(24)<<n->balance<<setw(4)<<"|";
			}
			cout<<"\n\t\t\t\t\t\t\t\t\t         ------------------------------------------------\n";
			cout<<left;
			cout<<setw(3)<<"\t\t\t\t\t\t\t\t\t         |"<<setw(33)<<"\t\tThanks"<<" |";
			cout<<"\n\t\t\t\t\t\t\t\t\t         ------------------------------------------------\n";
			char a;
			cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t Press any key to go Back  ";
			a=getch();
			
			system("cls");
			display_title();
}

int validate_amount(int amount){
		while(amount<=0 && amount!=-1)
	{
		return 0;
	}
	if(amount==-1)
	{
		return -1;
	}
	else
	{
		return 1;
	}
	
}
