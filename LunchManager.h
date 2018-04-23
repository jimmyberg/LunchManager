#ifndef _LUNCH_MANAGER_H_
#define _LUNCH_MANAGER_H_

#include <vector>
#include <string>
#include "User.h"

class LunchManager
{
public:
	LunchManager(){}
	bool AddUser(const std::string& name);
	bool addCreditUser(const std::string& name, const Money& credit);
	bool deleteUser(const std::string& name);
	bool Lunch(const std::string& userPaid, const Money& costMeal);
	void printUserCredit();
	void save();
	void load();
private:
	User* findUser(const std::string& name){
		for(User& user : users){
			if(name == user.getName()){
				return &user;
			}
		}
		return nullptr;
	}
	std::vector<User> users;
};

#endif
