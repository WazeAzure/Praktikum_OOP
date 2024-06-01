#include <iostream>

using namespace std;

class Hewan {
    public:
        Hewan(){
            // cout << "Hewan Constructor" << endl;
        }

        Hewan(string name){
            this->name = name;
            // cout << "Hewan Constructor Param" << endl;
        }

        virtual void print(){
            cout << "Hewan ini namanya " << this->name << endl;
        }

        ~Hewan(){
            cout << "Hewan mati " << this->name << "\n";
        }

    protected:
        string name;
};

class Kucing : public Hewan {
    public:
        Kucing(): Hewan(){
            cout << "Kucing Constructor" << endl;
        }

        Kucing(string name): Hewan(name){
            
        }
        
        virtual ~Kucing(){
            cout << "Kucing mati " << this->name << "\n";
        }
};

class Anjing : public Hewan {
    public:
        Anjing(string name): Hewan(name){
        
        }
        
        void print(){
            cout << "Anjing ini namanya " << this->name << endl;
        }

        ~Anjing(){
            cout << "Anjing mati " << this->name << "\n";
        }
};

class KucingAnggora : public Kucing {
    public:
        KucingAnggora(string name, string owner): Kucing(name) {
            this->owner = owner;
        }

        void print(){
            cout << "Kucing anggora ini namanya " << this->name << ". Pemiliknya adalah " << this->owner << "\n";
        }

        ~KucingAnggora(){
            cout << "Kucing anggora mati " << this->name << "\n";
        }

    private:
        string owner;
};

class AnjingBulldog : public Anjing {
    public:
        AnjingBulldog(string name, string owner): Anjing(name) {
            this->owner = owner;
        }

        void print(){
            cout << "Anjing bulldog ini namanya " << this->name << ". Pemiliknya adalah " << this->owner << "\n";
        }

        ~AnjingBulldog(){
            cout << "Anjing bulldog mati " << this->name << "\n";
        }
    private:
        string owner;
};
