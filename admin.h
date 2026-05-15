#include<iostream>
#include "admin_functions.h"
using namespace std;
void admin_panel(){
	system("cls");
	display_title();
	while(true){
		cout<<"\n\n";
		cout<<"\t\t\t\t\t\t\t\t\t\t\t          Admin Panel ";
		admin_actions();
		char choice = take_choice();
		if(choice=='0')
		break;
		else if(choice=='1')
		open_account();
		else if(choice=='2')
		all_account_details();
		else if(choice=='3')
		account_details();
		else if(choice=='4')
		account_logs();
		else if(choice=='5')
		delete_account();
		else{
			system("cls");
			display_title();
		}
	}
	
	system("cls");
	display_title();
}

void admin(){
	system("cls");
	display_title();
	cout<<"\n\n";
	bool login_status = login("admin");
	if(login_status)
		admin_panel();	
	
}


