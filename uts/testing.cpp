#include <iostream>
using namespace std;

class Awe {
	private:
	int umur;
	char goldar;

	public:
	Awe(): umur(2), goldar('C') {}

	Awe(int u, char g): umur(u), goldar(g) {}

	void getAllInfo(){
		cout << this->umur << " " << this->goldar << endl;
	}
};

int main(){
	Awe aw;
	aw.getAllInfo();

	Awe aw2(100, 'Z');
	aw2.getAllInfo();
	return 0;
}
