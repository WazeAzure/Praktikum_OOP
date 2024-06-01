#ifndef PRIO_QUEUE_HPP
#define PRIO_QUEUE_HPP

#include <iostream>
#include <vector>
using namespace std;

template<class T>
class PriorityQueue {
    private:
        int size;
        std::vector<T> content;
    public:
    /*
        Default constructor, size = 0
    */
    PriorityQueue(){
        this->size = 0;
    }
    /*
        Destructor
    */
    ~PriorityQueue(){} 
    /*
        Menambahkan nilai T ke dalam content
    */   
    void Enqueue(T value){
        if(this->size == 0){
            this->content.push_back(value);
        } else {
            int i = 0;
            while (i < this->size && this->content[i] > value) {
                i++;
            }

            if (i == this->size){
                this->content.push_back(value);
            } else {
                this->content.push_back(this->content[this->size-1]);
                for(int j=this->size-1; j > i; j--){
                    this->content[j] = this->content[j-1];
                }
                this->content[i] = value;
            }
        }
        this->size++;
    }


    /*
        Mengembalikan nilai pada posisi paling depan dari queue dan menghapus nilai tersebut
        Dijamin PrioriryQueue tidak kosong
    */
    T Dequeue(){
        T temp = this->content[0];

        for(int i=0; i<this->size; i++){
            this->content[i] = this->content[i+1];
        }
        this->content.pop_back();
        this->size--;
        
        return temp;
    }

    /*
        Mengembalikan nilai pada posisi paling depan dari queue
        Dijamin PriorityQueue tidak kosong
    */
    T Front(){
        return this->content[0];
    }

    /*
        Menambahkan elemen pada priority queue pq ke dalam content
    */
    void MergeQueue(const PriorityQueue<T> pq){
        for(int i=0; i<pq.size; i++){
            this->Enqueue(pq.content[i]);
        }
    }

    /*
        Mengembalikan banyak data dari priority queue ini
    */
    int GetSize(){
        return this->size;
    }

    /*
        Operator overloading untuk mencetak isi priority queue
        Contoh: (3, 2, 1)
        Apabila kosong, tampilkan ()
    */
    friend ostream& operator<<(ostream& os, PriorityQueue<T> pq){
        os << "(";
        int i;
        for(i=0; i<pq.GetSize(); i++){
            os << pq.content[i];
            if(i < pq.GetSize()-1){
                os << ", ";
            }
        }
        os << ")\n";
        return os;
    }


};



#endif
