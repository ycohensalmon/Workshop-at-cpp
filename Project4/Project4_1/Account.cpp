/*
Yossef Cohen-Salmon T.Z. 317805588
Workshop in c ++
Exercise 4 Question 1
*/
#include "Account.h"
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

float Account::sumWithdraw = 0;

float Account::sumDeposit = 0;

void Account::withdraw(float nis)
{
	if (balance - nis < -6000)    // If he is minus NIS 6,000 at the bank
		throw "ERROR: cannot have less than - 6000 NIS!";
	else if (nis > 2500)          // It is forbidden to withdraw more than NIS 2,500
		throw "ERROR: cannot withdraw more than 2500 NIS!";
	else
		balance -= nis;           // Updates the amount of withdrawn from the bank

	sumWithdraw += nis;           // Updates the amount of all funds withdrawn from the bank
}

void Account::deposit(float nis)
{
	if (nis > 10000)     // It is forbidden to deposit a check over 10,000 shekels
		throw "ERROR: cannot deposit more than 10000 NIS!";
	else
		balance += nis; // Updates the amount of deposit from the bank

	sumDeposit += nis;  // Updates the amount of all funds deposit from the bank
}

float  Account::getSumWithdraw()            { return sumWithdraw; }

float  Account::getSumDeposit()             { return sumDeposit; }

const int Account::getCode() const          { return code; }

const int Account::getAccountNumber() const { return accountNumber; }

const float Account::getBalance() const     { return balance; }

const string Account::getMail() const       { return mail; }

void Account::setCode(const int myCode)             { code = myCode; }

void Account::setAccountNumber(const int myAccount) { accountNumber = myAccount; }

void Account::setBalance(const float myBalance)     { balance = myBalance; }

void Account::setMail(const string myMail)          { mail = myMail; }

Account::Account()
{
	accountNumber =0;
	code =0;
	balance =0;
	mail ='\0';
}

Account::Account(const int myAccount = 0, const int myCode = 0, const float myBalance = 0, string myMail = '\0')
{
	if (myAccount <= 0)                  // If the account number is less than or equal to 0
		throw "ERROR: wrong code!";
	else
		setAccountNumber(myAccount);

	if (myCode < 1000 || myCode > 9999)  // If the code does not contain 4 digits
		throw "ERROR: code must be of 4 digits!";
	else
		setCode(myCode);

	setBalance(myBalance);

	int p = myMail.find('@');
	if (p == -1)                                // If there is no @ in the email address
		throw "ERROR: email must contain @!";
		
	if (myMail.find('@',p+1) != -1)             // If there are 2 @ in the email address
		throw "ERROR: email must contain @!";


	                                    // If the suffix of the email is incorrect
	if (myMail.find(".com") == -1 && myMail.find(".co.il") == -1)
		throw "ERROR: email must end at .com or .co.il!";
	else
		setMail(myMail);
}

Account::Account(const Account& temp) // copy-constractor
{
	accountNumber = temp.accountNumber;
	code = temp.code;
	balance = temp.balance;
	mail = temp.mail;
}

istream& operator>>(istream& is, Account& p)
{
	is >> p.accountNumber >> p.code >> p.mail;

	Account a(p.accountNumber, p.code, 0, p.mail); // Sends the values for testing in a constructor

	return is;
}
