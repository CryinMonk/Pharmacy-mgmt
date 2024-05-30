#include <iostream>
#include <string>
#include <windows.h>
#include "Account.h"
using namespace std;


bool Account::login(){
	while(true){
	cout<<"\n\n\n\n ";	
	cout<<"\t\t\t\tEnter Username ";
	cin>>username;
	cout<<"\t\t\t\tEnter Password ";
	cin>>password;
	if((username!="abc")||(password!="1234"))
	{
	cout<<"\t\t\t\tInvalid user"<<endl;
	Sleep(500);
	system("CLS");
	return 0;}
	else{
	cout<<"\t\t\t\tValid user"<<endl;
	Sleep(850);
	system("CLS");
	return 1;
	}
	}
}
		
void Account::registration(){
	cout<<"Enter Username: ";
	cin>>new_username;
	cout<<"Enter Password: ";
	cin>>password;
	cout<<"Confirm Password: ";
	cin>>confirm_password;
	if(password!=confirm_password)
	cout<<"Wrong password"<<endl;
	else if(new_username==username)
	cout<<"Username alrady in use."<<endl;
	else
	cout<<"New account created!"<<endl;
	}
