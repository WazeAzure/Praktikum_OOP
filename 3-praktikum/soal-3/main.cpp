#include "Restaurant.hpp"

int main(){
    Restaurant r;

    r.Push(1);
    r.Push(2);
    r.Push(3);

    cout << r << endl;
    
    r.Push(1);
    r.Push(2);
    r.Push(3);

    r.AddMenu(3, 2);

    cout << r << endl;

    r.Reorder(100);
    cout << r << endl;
    cout << r << endl;

    Restaurant q;
    cout << q << endl;
    return 0;
}