/*
Yossef Cohen-Salmon T.Z. 317805588
Workshop in c ++
Exercise 4 Question 1
*/
#include <iostream>
#include <string>
#include <cstring>
#pragma once
using namespace std;


class Account
{
private:
	int accountNumber;
	int code;
	float balance;
	string mail;
public:
	// The functions of "get"
	const int getCode()const;
	const int getAccountNumber()const;
	const float getBalance()const;
	const string getMail()const;

	// The functions of "set"
	void setCode(const int);
	void setAccountNumber(const int);
	void setBalance(const float);
	void setMail(const string);

	// constractor
	Account();
	Account(const int, const int,const float, string); // constractor/default constractor
	Account(const Account&);                           // copy-constractor

	void withdraw(float); 
	void deposit(float);
	float static sumWithdraw;
	float static sumDeposit;
	float static getSumWithdraw();
	float static getSumDeposit();
	friend istream& operator>>(istream& is, Account& p);
};

