#include "Restaurant.hpp"

Restaurant::Restaurant(){}

Restaurant::~Restaurant(){}

void Restaurant::Push(int val){
    this->order.push(val);
}

void Restaurant::Pop(int val){
    if(val > this->order.size()){
        cout << "Proses tidak valid\n";
    } else {
        int i;
        for(i=0; i<val; i++){
            this->order.pop();
        }
    }
}

void Restaurant::AddMenu(int k, int val){
    stack<int> temp;

    if(k > this->order.size()){
        k = this->order.size();
    }

    while(this->order.size() > k){
        int temp2 = this->order.top();
        this->order.pop();

        temp.push(temp2);
    }

    while(!this->order.empty()){
        int temp2 = this->order.top() + val;
        this->order.pop();
        temp.push(temp2);
    }

    while(!temp.empty()){
        int temp2 = temp.top();
        temp.pop();
        this->order.push(temp2);
    }
}

void Restaurant::Reorder(int k){
    stack<int> s;

    if(k > this->order.size()){
        k = this->order.size();
    }

    while(this->order.size() > k){
        int temp = this->order.top();
        this->order.pop();

        s.push(temp);
    }

    stack<int> final;

    while(!this->order.empty()){
        int temp = this->order.top();
        this->order.pop();

        final.push(temp);
    }

    while(!s.empty()){
        int temp = s.top();
        s.pop();

        final.push(temp);
    }

    this->order = final;
}

ostream& operator<<(ostream& os, Restaurant r){
    stack<int> s;

    int size = r.order.size();

    os << "(";
    for(int i=0; i<size; i++){
        os << r.order.top();

        int temp = r.order.top();
        r.order.pop();
        s.push(temp);

        if(i < size-1){
            os << ", ";
        }
    }
    os << ")\n";

    while(!s.empty()){
        int temp = s.top();
        s.pop();
        r.order.push(temp);
    }
    return os;
}