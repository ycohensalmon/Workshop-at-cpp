#pragma once
class MyString
{
private:
	int len;
	char* array;
	void setString(const char*); // inisialize the string
	const int compare(const MyString&);
	
public:
	MyString();                  // default constructor
	MyString(const char*);       // constructor
	MyString(const MyString&);   // copy constructor
	MyString(MyString&&)noexcept;        // move constructor
	~MyString();                 // destructor
	const int getLen()const;     
	const char* getArray()const;

	/* there are no 'const' after the operators fonction,
	to send the '*this' to the fonction 'compare' */
	const bool operator>(const MyString&);
	const bool operator<(const MyString&);
	const bool operator>=(const MyString&);
	const bool operator<=(const MyString&);
	const bool operator==(const MyString&);
	const bool operator!=(const MyString&);
	char& operator[](int const);
	const MyString insert(int index, const char* str);  // insert array to other array
	void print()const;                                  // print the array
};

