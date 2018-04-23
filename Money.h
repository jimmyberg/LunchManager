#ifndef _MONEY_H_
#define _MONEY_H_

#include <iostream>

class Money
{
public:
	Money():cents(0){}
	Money(int wholes, int cents):cents(wholes * 100 + cents){}
	int getCents(){return cents % 100;}
	int getWholes(){return cents / 100;}
	Money operator+(const Money& right) const{
		return Money(0, cents + right.cents);
	}
	Money operator-(const Money& right) const{
		return Money(0, cents - right.cents);
	}
	Money operator*(int right)const{
		return Money(0, cents * right);
	}
	Money operator/(int right)const{
		return Money(0, cents / right);
	}
	Money operator%(int right)const{
		return Money(0, cents % right);
	}
	Money& operator+=(const Money& right){
		cents += right.cents;
		return *this;
	}
	Money& operator-=(const Money& right){
		cents -= right.cents;
		return *this;
	}
	Money& operator*=(int right){
		cents *= right;
		return *this;
	}
	Money& operator/=(int right){
		cents /= right;
		return *this;
	}
	bool operator==(const Money& right) const{
		return cents == right.cents;
	}
	bool operator!=(const Money& right) const{
		return cents != right.cents;
	}
private:
	int cents = 0;
};

std::istream& operator>>(std::istream& is, Money& money);

std::ostream& operator<<(std::ostream& os, Money& money);

#endif
