/*
Yossef Cohen-Salmon T.Z. 317805588
Workshop in c ++
Exercise 4 Question 1
The function works like an ATM, there is an option to withdraw money and deposit money
and also see the amount of money withdrawn from all accounts
or the amount of money deposited in total in all accounts
*/
#include <iostream>
#include <string>
#include <cstring>
#include "Clock.h"
#include "Account.h"

using namespace std;

enum action
{
	stop,
	balance,
	deposit,
	withdraw,
	sumDeposit,
	sumWithdraw
};

action menu()
{
	cout << "enter 1 to get account balance" << endl;
	cout << "enter 2 to deposit money" << endl;
	cout << "enter 3 to withdraw money" << endl;
	cout << "enter 4 to see the sum of all withdraws" << endl;
	cout << "enter 5 to see the sum of all Deposits" << endl;
	cout << "enter 0 to stop\n" << endl;
	int x;
	cin >> x;
	return (action)x;
}

/*******The function searches for an account number and code and returns the index*******/
int findAccount(Account* bank, int size)
{
	int number, code;
	bool flag = false;
	cout << "please enter account number:\n";
	cin >> number;
	int i = 0;
	for (i = 0; i < size; i++)
		if (bank[i].getAccountNumber() == number) // Finds the index of the account number
		{
			flag = true;                          // If we found then a feather from the loop
			break;
		}

	if (flag == false)                            // If the account number does not exist
		throw "ERROR: no such account number!";

	cout << "please enter the code:\n";           // Entering an account code
	cin >> code;

	if (code < 1000 || code > 9999)               // If the code does not have the appropriate digit number
		throw "ERROR: code must be of 4 digits!";

	if (bank[i].getCode() == code)                // If the code is correct
		return i;
	else
		throw "ERROR: wrong code!";               // If the code is incorrect
}

/********** The function prints all the operations I do at the ATM ********/
void printTransaction(Account a, action ac, Clock& c)
{
	cout << c << "\t";
	;
	switch (ac)
	{
	case balance: cout << "account #: " << a.getAccountNumber() << "\t";       // Prints the balance of the account
		cout << "balance: " << a.getBalance() << endl;
		break;
	case deposit:
	case withdraw: cout << "account #: " << a.getAccountNumber() << "\t";      // Prints the new account balance
		cout << "new balance: " << a.getBalance() << endl;
		break;
	case sumDeposit:
		cout << "sum of all deposits: " << Account::getSumDeposit() << endl;   // Prints all deposits from the bank
		break;
	case sumWithdraw:
		cout << "sum of all withdraws: " << Account::getSumWithdraw() << endl; // Prints all withdrawals from the bank
		break;
	}
}

/*****The function gives the balance in the bank****/
void getBalance(Account* bank, int size, Clock& c)
{
	int i = findAccount(bank, size);       // Finds the account number
	c += 20;
	printTransaction(bank[i], balance, c); // Prints the balance
}

/*********The function deposits as money in the bank*******/
void cashDeposit(Account* bank, int size, Clock& c)
{
	int i = findAccount(bank, size);              // Finds the account number
	float amount;
	cout << "enter the amount of the check:\n";
	cin >> amount;
	bank[i].deposit(amount);                      // Deposits the money in the bank
	c += 30;
	printTransaction(bank[i], deposit, c);
}

/******The function withdraw money from the bank******/
void cashWithdraw(Account* bank, int size, Clock& c)
{
	int i = findAccount(bank, size);
	float amount;
	cout << "enter the amount of money to withdraw:\n";
	cin >> amount;
	bank[i].withdraw(amount); // Pulls money from the bank
	c += 50;
	printTransaction(bank[i], withdraw, c);
}

int main()
{
	Clock c(8,0,0);    // Initializes the time
	Account bank[10];
	cout << "enter account number, code and email for 10 accounts:\n";
	for (int i = 0; i < 10; i++)
	{
		try {
			cin >> bank[i];
			for (int j = 0; j < i; j++)
				if (bank[i].getAccountNumber() == bank[j].getAccountNumber())  // Checks that there are no 2 matching accounts
					throw "ERROR: account number must be unique!";
		}
		catch (const char* msg)                                                // Gets all the shots of the exceptions
		{
			cout << c << '\t' << msg << '\n';
			i--;
		}
	}
	action ac = menu();
	while (ac)
	{
		try
		{
			switch (ac)
			{
			case balance: getBalance(bank, 10, c);        // The balance in the account
				break;
			case withdraw:cashWithdraw(bank, 10, c);      // The balance in the account
				break;
			case deposit: cashDeposit(bank, 10, c);       // Bank account deposit
				break;
			case sumDeposit:c += 60;
				printTransaction(bank[0], sumDeposit, c); // The sum of all withdrawals from the bank
				break;
			case sumWithdraw:c += 60;
				printTransaction(bank[0], sumWithdraw, c); // The sum of all deposits in the bank

			}
		}
		catch (const char* msg)                            // Gets all the shots of the exceptions
		{
			cout << c << '\t' << msg << '\n';
		}
		
		ac = menu();
	}
	return 0;
}
/*
          ////Running example////

enter account number, code and email for 10 accounts:
1 1111 aaa@gmail.com
2 2222 bbb@gmail.com
3 3333 ccc@gmail.com
4 4444 ddd@gmail.com
5 5555 eee@gmail.co.il
6 6666 zzz
08:00:00        ERROR: email must contain @!
6 6666 fff@gmail.com
7 7777 ggg@gmail.com
8 8888 hhh@gmail.com
9 9999 iii@gmail.com
10 101 zzz@gmail.com
08:00:00        ERROR: code must be of 4 digits!
10 1010 zzz@gmailcom
08:00:00        ERROR: email must end at .com or .co.il!
10 1010 zzz@gmail.com
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop

2
please enter account number:
4
please enter the code:
4444
enter the amount of the check:
2500
08:00:30        account #: 4    new balance: 2500
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop

2
please enter account number:
1
please enter the code:
1111
enter the amount of the check:
3000
08:01:00        account #: 1    new balance: 3000
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop

3
please enter account number:
2
please enter the code:
2222
enter the amount of money to withdraw:
2000
08:01:50        account #: 2    new balance: -2000
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop

4
08:02:50        sum of all deposits: 5500
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop

5
08:03:50        sum of all withdraws: 2000
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop

0

*/