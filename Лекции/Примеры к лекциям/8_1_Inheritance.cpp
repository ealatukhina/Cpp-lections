#include <iostream>
using namespace std;

class figure{
protected: 
	double x, y;
public:
	figure(double a=0, double b=0){x=a; y=b;}
	virtual double area() {return 0;}
};

class rectangle: public figure{
public:	
	rectangle(double a, double b): figure(a, b){};
	double area(){return x*y;}
};

class circle: public figure{
public:
	circle(double a): figure(a){};
	double area(){return 3.1416*x*x;}
};

int main() {
	figure A(2, 3);
	cout << "S(A) = "<< A.area() << endl;
	rectangle B(2, 3);
	cout << "S(B) = "<< B.area() << endl;	
	circle C(3);
	cout << "S(C) = "<< C.area() << endl;
	
	figure *X, *Y;
	X = &B;
	Y = &C;
	cout << "S(X) = " << X->area() << endl;
	cout << "S(Y) = "<< Y->area() << endl;
	
	return 0;
}