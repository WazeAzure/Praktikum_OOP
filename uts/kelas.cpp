#include <iostream>
using namespace std;

class B1 {
	protected:
	int x = 100;
	public:
	virtual void getInfo() = 0;
};

class D1: public B1{
	public:
	void getInfo(){
		cout << x << " dari D1" << endl;
	}	
};

class D2: public B1{
};

class E: public D1, public D2 {};

int main(){
	E e;
	e.getInfo();
	return 0;
}
