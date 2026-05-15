#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<unistd.h>
#include<cstdlib>
#include<ctime>
using namespace std;
fstream file,file2;
void main_page_actions(){
	cout<<"\n\n";
	cout<<"\t\t\t\t\t\t\t\t\t\t\t====================================\n";
	cout<<"\t\t\t\t\t\t\t\t\t\t\t:                                  :\n";
	cout<<"\t\t\t\t\t\t\t\t\t\t\t:        1. Admin                  :\n";
	cout<<"\t\t\t\t\t\t\t\t\t\t\t:        2. ATM                    :\n";
	cout<<"\t\t\t\t\t\t\t\t\t\t\t:        0. Exit                   :\n";
	cout<<"\t\t\t\t\t\t\t\t\t\t\t:                                  :\n";
	cout<<"\t\t\t\t\t\t\t\t\t\t\t====================================\n";
}

void admin_actions(){
	cout<<"\n\n";
	cout<<"\t\t\t\t\t\t\t\t\t\t\t====================================\n";
	cout<<"\t\t\t\t\t\t\t\t\t\t\t:                                  :\n";
	cout<<"\t\t\t\t\t\t\t\t\t\t\t:        1. Open Account           :\n";
	cout<<"\t\t\t\t\t\t\t\t\t\t\t:        2. View All Accounts      :\n";
	cout<<"\t\t\t\t\t\t\t\t\t\t\t:        3. Account Details        :\n";
	cout<<"\t\t\t\t\t\t\t\t\t\t\t:        4. Account Logs           :\n";
	cout<<"\t\t\t\t\t\t\t\t\t\t\t:        5. Delete Account         :\n";
	cout<<"\t\t\t\t\t\t\t\t\t\t\t:        0. Exit                   :\n";
	cout<<"\t\t\t\t\t\t\t\t\t\t\t:                                  :\n";
	cout<<"\t\t\t\t\t\t\t\t\t\t\t====================================\n";
}

void display_title(){
	cout<<"\n";
  	cout<<"\t\t\t                   ____              _      __  __                                                   _      _____           _                  "<<endl;
  	cout<<"\t\t\t                  |  _ \\            | |    |  \\/  |                                                 | |    / ____|         | |                 "<<endl;
  	cout<<"\t\t\t                  | |_) | __ _ _ __ | | __ | \\  / | __ _ _ __   __ _  __ _  ___ _ __ ___   ___ _ __ | |_  | (___  _   _ ___| |_ ___ _ __ ___   "<<endl;
  	cout<<"\t\t\t                  |  _ < / _` | '_ \\| |/ / | |\\/| |/ _` | '_ \\ / _` |/ _` |/ _ \\ '_ ` _ \\ / _ \\ '_ \\| __|  \\___ \\| | | / __| __/ _ \\ '_ ` _ \\  "<<endl;
  	cout<<"\t\t\t                  | |_) | (_| | | | |   <  | |  | | (_| | | | | (_| | (_| |  __/ | | | | |  __/ | | | |_   ____) | |_| \\__ \\ ||  __/ | | | | | "<<endl;
  	cout<<"\t\t\t                  |____/ \\__,_|_| |_|_|\\_\\ |_|  |_|\\__,_|_| |_|\\__,_|\\__, |\\___|_| |_| |_|\\___|_| |_|\\__| |_____/ \\__, |___/\\__\\___|_| |_| |_| "<<endl;
  	cout<<"\t\t\t                                                                      __/ |                                        __/ |                       "<<endl;
  	cout<<"\t\t\t                                                                     |___/                                        |___/                        "<<endl;
  	cout<<"\t\t\t                                                                                                                                               "<<endl;

}

char take_choice(){
	char a;
	cout<<"\n\n";
	cout<<"\t\t\t\t\t\t\t\t\t\t\t      Enter Choice : ";
	cin>>a;
	return a;
}

bool login(string role){
	string u,p;
	if(role=="admin")
	{
		u="admin 123";
		p="admin 123";
	}
	
	bool stat=0;
	int tries=3;
	string username,password;
	cin.ignore();
				
				//Attempting login till tries is not equal to zero
				
	while(tries!=0)
	{
						
		cout<<"\n\t\t\t\t\t\t\t\t\t\t\tEnter your username : ";     //Asking Username 
		getline(cin,username);
		
		cout<<"\t\t\t\t\t\t\t\t\t\t\tEnter your password : ";     //Asking Password
		getline(cin,password);
		
						//Validating The Username And Passowrd
		if(username==""||password=="")
			cout<<"\t\t\t\t\t\t\t\t\t\t\tYou can't leave any input blank.\n";
			
		else if(username==u&&password==p)
		{
				//If Username and Password are Correct Then Transfering For OTP Verification

			int otp,random,tre=5;
			
							//OTP has also  5 tries
			while(tre!=0)
			{	
				srand(time(0));
				random=rand();
				cout<<"\n\t\t\t\t\t\t\t\t\t\t\tOTP : "<<random<<endl;
				cout<<"\t\t\t\t\t\t\t\t\t\t\tEnter the above OTP Code : ";
				cin>>otp;
				
							//Validating the OTP Entered By user
				
				if(otp==random)
				{
					stat=1;  //If OTP is correct then aliving his status
					break;
				}
				else{
					tre--;	//On false OTP Decreasing tries and generating error
					cout<<"\n\t\t\t\t\t\t\t\t\t\t\tTry Again!\n";
					cout<<"\t\t\t\t\t\t\t\t\t\t\t"<<tre<<" OTP's left.\n";
				}	
			}
						//Failing In OTP Returning To Main Function
			if(tre==0)
			return false;
			
			break;
			
		}
						//If username and password are not matched then decreasing his tries and generating error
		else
		{
			tries--;
			cout<<"\n\t\t\t\t\t\t\t\t\t\t\tEntered Credentials is Incorrect.";
			cout<<"\n\t\t\t\t\t\t\t\t\t\t\tYou have left "<<tries<<" attemps.\n";
		}
	}
		
					//If Admin status is alive Then Proceeding To Admin Panel
	
	if(stat==1)
	{
		return true;
	}
					//If all tries are lost returning to main function
	else
	{
		system("cls");
		display_title();
		cout<<"\n\n";
		cout<<"\t\t\t\t\t\t\t\t\t\t\t    Sorry! Try another time. ";
		return false;
	}
}

void Start(){
	int bal,pin,acc;
	string name,cnic,space,date,mthd;
	fstream file,file2;
	file.open("Data/accounts_data.txt");
	file2.open("Data/accounts_logs_data.txt");
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
		bank.insert(acc,bal,name,cnic,pin,date);
		
	}file.close();
	
	while(file2>>acc){
		file2>>bal;
		file2.ignore();
		getline(file2,mthd);
		getline(file2,date);
		getline(file2,space);
		Node *n=bank.search(acc);
		if(n){
			n->log.insert_log(bal,mthd,date);
		}
	}
	file2.close();

}
void Write(Node *n){
	if(n){
		Write(n->left);
		
		file<<n->account_no<<endl;
		file<<n->account_holder_name<<endl;
		file<<n->cnic<<endl;
		file<<n->pin<<endl;
		file<<n->date_created;
		file<<n->balance<<endl<<endl;
		listnode *lg= n->log.head;
		
		while(lg){
			file2<<n->account_no<<endl;
			file2<<lg->amount<<endl;
			file2<<lg->method<<endl;
			file2<<lg->date<<endl;
			lg=lg->next;
		}
		
		Write(n->right);
	}
}
void Update_File(){
	file.open("Data/accounts_data.txt",ios::out);
	file2.open("Data/accounts_logs_data.txt",ios::out);
	Write(bank.root);
	file.close();
	file2.close();
}

