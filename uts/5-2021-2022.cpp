#include <iostream>
using namespace std;

class Kendaraan {
	public:
	virtual void info(){
		cout << "ini adalah kendaraan.\n";
	}
};

class Mobil: virtual public Kendaraan {
	public:
	void info(){
		cout << "Ini adalah kendaraan mobil.\n";
	}
};

class Motor: virtual public Kendaraan {
	public:
	void info(){
		cout << "Ini adalah kendaraan motor.\n";
	}
};

class Batmobile: public Mobil, public Motor {
	public:
	void info(){
		cout << "Ini adalah kendaraan mobil motor Batmobile.\n";
	}
};

int main(){
	Kendaraan kendaraan;
	Mobil mobil;
	Motor motor;
	Batmobile batmobile;

	Kendaraan* obj1 = &kendaraan;
	obj1->info();
	obj1 = &mobil;
	obj1->info();
	obj1 = &motor;
	obj1->info();
	obj1 = &batmobile;
	obj1->info();

	Kendaraan obj2 = kendaraan;
	obj2.info();
	obj2 = mobil;
	obj2.info();
	obj2 = motor;
	obj2.info();
	obj2 = batmobile;
	obj2.info();

	return 0;
}
