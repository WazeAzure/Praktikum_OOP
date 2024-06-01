#include "PriorityQueue.hpp"

void printPQ(PriorityQueue<int> pq, int i){
    cout << "pq" << i << ": " << pq << endl;
}

int main(){
    PriorityQueue<int> pq;
    PriorityQueue<int> pq2;
    PriorityQueue<int> pq3;

    printPQ(pq3, 3);

    for(int i=0; i<6; i++){
        if(i%2 == 0){
            pq.Enqueue(i);
            printPQ(pq, 1);
        } else {
            pq2.Enqueue(i);
            printPQ(pq2, 2);
        }
    }

    pq.Enqueue(-1);
    // cout << "pq el " << pq.content.size() << endl;

    cout << pq.Front() << endl;
    cout << pq.Dequeue() << endl;
    printPQ(pq, 1);
    pq.MergeQueue(pq2);
    printPQ(pq, 1);
    cout << pq.GetSize() << endl;


    return 0;
}