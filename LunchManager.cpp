
#include "LunchManager.h"
#include <list>
#include <fstream>
#include "config.h"

using namespace std;

bool LunchManager::AddUser(const string& name){
	if(findUser(name) == nullptr){
		users.emplace_back(name);
		return true;
	}
	else
		return false;
}
bool LunchManager::transferCredit(const std::string& from, const std::string& to, const Money& money){
	if(from == to)
		return false;
	User* userFrom = findUser(from);
	User* userTo = findUser(to);
	if(userFrom == nullptr || userTo == nullptr)
		return false;
	userTo->eurosCredit += money;
	userFrom->eurosCredit -= money;
	return true;
}
bool LunchManager::addCreditUser(const string& name, const Money& credit){
	User* user = findUser(name);
	if(user == nullptr)
		return false;
	user->eurosCredit += credit;
	return true;
}
bool LunchManager::deleteUser(const string& name){
	for (vector<User>::const_iterator it = users.begin(); it != users.end(); ++it)
	{
		if(it->getName() == name){
			if(it->eurosCredit != Money(0, 0)){
				return false;
			}
			users.erase(it);
			return true;
		}
	}
	return false;
}
bool LunchManager::Lunch(const string& userPaid, const Money& costMeal){
	User* paidUser = findUser(userPaid);
	if(paidUser != nullptr){
		paidUser->eurosCredit += costMeal;
		list<User*> usersThatHadLunch;
		cin.ignore(256, '\n');
		for(auto& user : users){
			if(user.getName() == userPaid)
				usersThatHadLunch.push_back(&user);
			else{
				cout << "Does " << user.getName() << " eat lunch?" << endl;
				if(cin.get() == 'y'){
					usersThatHadLunch.push_back(&user);
				}
				cin.ignore(256, '\n');
			}
		}
		Money sharedBurden = costMeal / usersThatHadLunch.size();
		if((costMeal % usersThatHadLunch.size()).getCents()){
			sharedBurden += Money(0, 1);
		}
		for(auto* user : usersThatHadLunch){
			user->eurosCredit -= sharedBurden;
		}
		const Money leftCredit = costMeal - (sharedBurden * usersThatHadLunch.size());
		paidUser->eurosCredit -= leftCredit;
		return true;
	}
	return false;
}
void LunchManager::printUserCredit(){
	Money cashRegister;
	for(auto& user : users){
		cout.width(16);
		cout << left << user.getName();
		cout << ": " << user.eurosCredit << endl;
		cashRegister += user.eurosCredit;
	}
	cout << "\n";
	cout.width(16);
	cout << "Cash register";
	cout << ": " << cashRegister << endl;
}

void LunchManager::save(){
	ofstream oFile(SAVE_LOCATION".lunch_manager");
	if(oFile.is_open()){
		oFile << users.size() << endl;
		for(auto& user: users){
			oFile << user.getName() << '\t' << user.eurosCredit << endl;
		}
	}
}

void LunchManager::load(){
	ifstream iFile(SAVE_LOCATION".lunch_manager");
	if(iFile.is_open() && !iFile.eof()){
		unsigned int usersSize;
		iFile >> usersSize;
		users.clear();
		for (unsigned int i = 0; i < usersSize; ++i){
			string name;
			iFile >> name;
			Money credit;
			iFile >> credit;
			users.emplace_back(name, credit);
		}
	}
}
