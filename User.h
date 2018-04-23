
#ifndef _USER_H_
#define _USER_H_

#include <string>
#include "Money.h"

class User
{
public:
	User(const std::string& name):name(name){}
	User(const std::string& name, const Money& eurosCredit):eurosCredit(eurosCredit), name(name){}
	Money eurosCredit;
	const std::string& getName() const{return name;}
private:
	std::string name;
};

#endif
