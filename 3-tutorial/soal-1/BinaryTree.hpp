#ifndef __BINARY_TREE
#define __BINARY_TREE

#include <iostream>
#include <vector>
using namespace std;

template<class T>
class BinaryTree {
    private:
        T value;
        std::vector<BinaryTree<T>> children;
        int numChildren;

    public:
        // Default constructor, set numChildren = 0
        BinaryTree() {
            this->numChildren = 0;
        }

        // Copy constructor
        BinaryTree(const BinaryTree<T>& bintree) {
            this->numChildren = bintree.numChildren;
            this->children = bintree.children;
            this->value = bintree.value;
        }

        // Destruktor
        ~BinaryTree() {}

        // Setter untuk value
        void setValue(const T& val) {
            this->value = val;
        }

        /*
        Menambahkan anak binary tree dengan value tertentu.
        Fungsi ini membuat sebuah BinaryTree baru dan menambahkannya ke list of children.
        BinaryTree yang baru dibuat kemudian dikembalikan sebagai return value dari fungsi ini.
        Jika jumlah children sudah lebih dari dua, lemparkan exception "Tidak bisa memiliki lebih dari dua children\n".
        */
        BinaryTree<T>& addChild(T child) {
            if (numChildren < 2) {
                BinaryTree<T> newTree;
                newTree.setValue(child);
                this->children.push_back(newTree);
                numChildren++;
                return this->children[this->numChildren-1];                
            } else {
                throw "Tidak bisa memiliki lebih dari dua children\n";
            }  
        }

        /*
        Operator overloading untuk mencetak isi tree ke ostream.
        Format : <value>(<binary_tree_1>)(<binary_tree_2>)
        Tidak perlu ada newline di akhir.
        Berbagai contoh pencetakan binary tree :
        - Binary tree of integer tanpa children : 5()()
        - Binary tree of integer dengan satu children : 5(7()())()
        - Binary tree of integer dengan dua children : 5(7()())(6()())
        */
        friend ostream& operator<<(ostream& os, BinaryTree<T> bintree) {
            os << bintree.value;
            for (int i = 0; i < 2; i++) {
                os << "(";
                if (i < bintree.children.size()) {
                    os << bintree.children[i];
                }
                os << ")";
            }
            return os;
        }
};

#endif