#include<iostream>
#include<iomanip>
#include "BST.h"
Tree bank;
#include "functions.h"
#include "admin.h"
#include "atm.h"
using namespace std;
int main(){
	Start();
	display_title();
	while(true){
		main_page_actions();
		char choice = take_choice();
		if(choice == '0')
			break;
		else if(choice =='1')
			admin();
		else if(choice =='2')
			atm();
		else{
			system("cls");
			display_title();
			cout<<"\n\t\t\t\t\t\t\t\t\t\t\t        Invalid Choice! ";
		}
	}
}

