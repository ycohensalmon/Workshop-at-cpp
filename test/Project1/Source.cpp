#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//class Animal
//{
//protected:
//	double weight;
//public:
//	Animal(int w) : weight(w) {
//		cout << "Animal CTOR\n";
//	}
//	~Animal() {
//		cout << "Animal DTOR.\n";
//	}
//	void virtual show() = 0;
//};
//class Cow : public Animal
//{
//private:
//	int milk;
//public:
//	Cow(double w = 2000, int m = 200) : Animal(w), milk(m) {
//		cout << "Cow CTOR\n";
//	}
//	~Cow() { cout << "Cow DTOR.\n"; }
//	void show() {
//		cout << "Weight=" << weight << ",\nMilk ="  << milk << endl; 
//	}
//};
//int main()
//{
//	Animal* myCow = new Cow(1000);
//	myCow->show();
//	delete myCow;
//	return 0;
//}

//class A
//{
//	int x, y;
//public:
//	A(int X = 0, int Y = 0);
//	A(A& a);
//	A operator+(A a);
//	A& operator=(A& a);
//	friend ostream& operator<<(ostream& os, A a);
//};
//A::A(int X, int Y) :x(X), y(Y)
//{ }
//A::A(A& a) : x(a.y), y(a.x)
//{ }
//A A::operator+(A a)
//{
//	A temp(x + a.x, y + a.y);
//	return temp;
//}
//A& A::operator=(A& a)
//{
//	x = a.x;
//	y = a.y;
//	return *this;
//}
//ostream& operator<<(ostream& os, A a)
//{
//	os << "x=" << a.x << ' ';
//	os << "y=" << a.y << ' ';
//	return os;
//}
//
//int main()
//{
//	A a(2, 4), b(6, 8), c;
//	c = a + b;
//	cout << c;
//	return 0;
//}

class C {
	static int counter;
public:
	C() { counter++; }
	C(int size) {
		counter++;
	}
	C(C& other) {
		cout << ++counter << ' ';
	}
	~C() {
		counter--;
	}
	C operator+(C c) {
		C tmp;
		return tmp;
	}
	bool operator==(C c) {
		return true;
	}
};
int C::counter = 0;
int main() {
	C c1(4);
	C c2;
	C c3(c1);
	if (c1 == c2)
		c1 = c1 + c2;
}