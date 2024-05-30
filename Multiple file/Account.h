#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

using namespace std;

class Account{
	private:
		string password;
		string username;
		string new_username;
		string confirm_password;
	public:
		
		bool login();
		void registration();	
};

#endif
