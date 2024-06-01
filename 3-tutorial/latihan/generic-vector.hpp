#ifndef __GENERIC_VECTOR__
#define __GENERIC_VECTOR__

#include <iostream>
#include "errors.h"

template <class T, int N>
class Vector{
    private:
        T* elements;
    
    public:
        Vector() {
            this->elements = new T[N];
        }

        Vector(const Vector<T, N>& s){
            std::cout << "called copy const\n";
            this->elements = new T[N];
            for(int i=0; i<N; i++){
                this->elements[i] = s.elements[i];
            }
        }

        Vector<T, N> operator=(const Vector<T, N>& vec){
            std::cout << "operator assignment\n";
            Vector<T, N> c;
            c.elements = new T[N];
            for(int i=0; i<N; i++){
                c.elements[i] = vec.elements[i];
            }
            return c;
        }

        ~Vector() {
            delete [] this->elements;
        }

        T& operator[](int idx){
            if(idx < 0 || idx >= N){
                myOwnError moe;
                throw moe;
            }
            return this->elements[idx];
        }

        Vector<T, N> operator+(const Vector<T, N>& other){
            Vector<T, N> c;
            for(int i=0; i<N; i++){
                c.elements[i] = this->elements[i] + other.elements[i];
            }
            return c;
        }

        friend std::ostream& operator<<(std::ostream& os, const Vector<T, N>& vec){
            os << "<";
            for(int i=0; i<N; i++){
                os << vec.elements[i];
                if(i != N-1){
                    os << ", ";
                }
            }
            os << ">";
            return os;
        }

        friend std::istream& operator>>(std::istream& is, const Vector<T, N>& vec){
            for(int i=0; i<N; i++){
                is >> vec.elements[i];
            }
            return is;
        }
};

#endif