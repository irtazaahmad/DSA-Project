#include<iostream>
#include "atm_functions.h"
using namespace std;
void atm_panel(Node *n){
	system("cls");
	display_title();
	while(true){
		cout<<"\n\n";
		cout<<"\t\t\t\t\t\t\t\t\t\t\t               ATM ";
		cout<<"\n\n";
		cout<<"\t\t\t\t\t\t\t\t\t\t\t         Balance : "<<n->balance<<"\n\n"; 
		cout<<"\t\t\t\t\t\t\t\t\t\t\t====================================\n";
		cout<<"\t\t\t\t\t\t\t\t\t\t\t:                                  :\n";
		cout<<"\t\t\t\t\t\t\t\t\t\t\t:        1. Withdraw Balance       :\n";       
		cout<<"\t\t\t\t\t\t\t\t\t\t\t:        2. Deposit Balance        :\n";       
		cout<<"\t\t\t\t\t\t\t\t\t\t\t:        0. Exit                   :\n";
		cout<<"\t\t\t\t\t\t\t\t\t\t\t:                                  :\n";
		cout<<"\t\t\t\t\t\t\t\t\t\t\t====================================\n";
		char choice = take_choice();
		if(choice=='0')
		break;
		else if(choice=='1')
		withdraw(n);
		else if(choice=='2')
		deposit(n);
		else{
			system("cls");
			display_title();
		}
		
	}
	
	system("cls");
	display_title();
}

void atm(){
	system("cls");
	display_title();
	cout<<"\n\n";
	Node *n;
	bool login_status = atm_login(n);
	if(login_status)
		atm_panel(n);	
	
}


