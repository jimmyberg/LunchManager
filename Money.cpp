
#include "Money.h"

std::istream& operator>>(std::istream& is, Money& money){
	int amount;
	is >> amount;
	int cents = 0;
	if(is.peek() == '.'){
		is.get();
		do{
			is >> cents;
		}while(cents >= 100 || cents < 0);
		if(amount < 0){
			cents *= -1;
		}
	}
	money += Money(amount, cents);
	return is;
}

std::ostream& operator<<(std::ostream& os, Money& money){
	os << money.getWholes() << '.';
	int cents = money.getCents();
	if(cents < 0){
		cents *= -1;
	}
	os << cents;
	return os;
}
