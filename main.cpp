#include <iostream>
#include <cstdlib>
#include "LunchManager.h"
using namespace std;

LunchManager lunchManager;

string getCommand(){
	string ret;
	cin >> ret;
	cin.ignore(256, '\n');
	return ret;
}

int main(int argc, char** argv){
	lunchManager.load();
	while(1){
		cout << "-> " << flush;
		string command = getCommand();
		if(command == "lunch"){
			cout << "Specify name of buyer:" << endl;
			string user;
			cin >> user;
			cout << "Specify cost of total meal" << endl;
			Money costMeal;
			cin >> costMeal;
			if(lunchManager.Lunch(user, costMeal) == false){
				cout << "Failed to pay for lunch. Is the user spelled correctly?" << endl;
			}
			lunchManager.printUserCredit();
		}
		else if(command == "exit" || command == "q"){
			cout << "Good bye!" << endl;
			break;
		}
		else if(command == "clear"){
			if(system("clear") == -1){
				cerr << "clear returned error." << endl;
			}
		}
		else if(command == "ls"){
			lunchManager.printUserCredit();
		}
		else if(command == "addcredit"){
			cout << "Specify name:" << endl;
			string user;
			cin >> user;
			cout << "Specify amount of credit the user will get. Negative credit is also allowed:" << endl;
			Money credit;
			cin >> credit;
			if(lunchManager.addCreditUser(user, credit)){
				cout << "Added " << credit << " to " << user << "'s account." << endl;
			}
			else{
				cout << "Failed to add credit." << endl;
			}
		}
		else if(command == "transfercredit"){
			cout << "Specify name to transfer from:" << endl;
			string userFrom;
			cin >> userFrom;
			cout << "Specify name to transfer to:" << endl;
			string userTo;
			cin >> userTo;
			cout << "Specify amount of credit." << endl;
			Money credit;
			cin >> credit;
			if(lunchManager.transferCredit(userFrom, userTo, credit)){
				cout << "Added " << credit << " from " << userFrom << "'s' to " << userTo << "'s account." << endl;
			}
			else{
				cout << "Failed to transfer credit." << endl;
			}
		}
		else if(command == "adduser"){
			cout << "Specify name:" << endl;
			string newUser;
			cin >> newUser;
			if(lunchManager.AddUser(newUser)){
				cout << "User " << newUser << " successfully added." << endl;
			}
			else{
				cout << "Could not add user." << endl;
			}
		}
		else if(command == "deluser"){
			cout << "Specify name:" << endl;
			string delUser;
			cin >> delUser;
			if(lunchManager.deleteUser(delUser)){
				cout << "User " << delUser << " successfully deleted." << endl;
			}
			else{
				cout << "Could not delete user. Either he does not exist or has some credit/debit left." << endl;
			}
		}
		else if(command == "help"){
			cout << "The following commands are available:" << endl
			<< "help           - displays this help message.\n"
			<< "lunch          - execute lunch protocol.\n"
			<< "exit           - exit program.\n"
			<< "clear          - clears screen.\n"
			<< "ls             - list every user with their credit.\n"
			<< "transfercredit - transfer credit from one user to another.\n"
			<< "addcredit      - add credit to user. Acquired when putting money in the cash register.\n"
			<< "adduser        - add a user to the system.\n"
			<< "deluser        - remove a user from the system if he has no credit/debit left.\n"
			<< flush;
		}
		else{
			cout << "Unknown command: " << command << '\n';
			cout << "Enter \"help\" for available commands." << endl;
		}
		lunchManager.save();
	}
	return 0;
}
