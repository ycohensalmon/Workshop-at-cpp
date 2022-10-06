#pragma once
class Employee
{
private:
	int id;
	char name[21];
	float salaire;
	int hours;
	float amount;
	float sum_salaire(float salaire_, int hours_);
public:
	int getId();
	char* getName();
	float getSalaire();
	int getHours();
	float getAmount();
	void setId(int id_);
	void setName(char name_[]);
	void setSalaire(float salaire_);
	void setHours(int hours_);
	void setAmount(float amount);
	float salaire_with_bonus();

};

