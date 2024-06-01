class A {
    protected:
        int i;
    public:
        A(int x){
            this->i = x;
        }

        virtual int getI(){
            return this->i;
        }
};

class B: public A {
    private:
        int j;
    public:
        B(int x, int y): A(x){
            this->j = y;
        }

        int getI(){
            return this->j*100;
        }

        int getj(){
            return this->j;
        }
};