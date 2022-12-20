/**
 * @file min_binary.cpp
 * @author pkkarn (pk2psp@gmail.com)
 * @brief :
 * 
 * * Min Binary heap is a complete binary tree. where node is always smaller than its child node.
 * 
 * @implmentation: 
 * 
 * * Adding A element
 * - Push a value to the last.
 * - and bubbleUp swap until its parent is greater. stop when parent node is smaaller than its child node.
 * 
 * * Removing A elemnen
 * 
 * - swap first item with last and removed it.
 * - After that sinkDown, which means basically check if element at 0 index is smaller than its child nodes.
 * - Swap with whoever is samller. Stop if both the child nodes are greater
 * @version 0.1
 * @date 2022-12-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


// Just for practive a swap function using pointer
void swap_function(int *a, int *b) {
    int temp = *a; // int variable store value of stored at a pointer inside this
    *a = *b; // now change value of address a to value of address b;
    *b = temp;// and then change value stored at address b from temp;
};



class MinBinaryHeap {
    public: 
        vector<int> values {};

        void swap_bro(int i, int j) {
            // swap_function(&values[i], &values[j]);
            swap(values[i], values[j]);
        }


        vector<int>* push(int val) {
            values.push_back(val);

            sinkUp();
            return &this->values;
        }

        void sinkUp() {
            // take last item from values;
            int n = values.size() - 1;
            int parent_index = (n - 1)/2; // index;
            while(parent_index >= 0 && values[n] < values[parent_index]) {
                    swap(values[n], values[parent_index]);
                    n = parent_index;
                    parent_index = (n - 1)/2; // index;
            }
        }

        vector<int>* remove() {
            /**
             * 1. swap first item with last;
             * 2. then removed one from last;
             * 3. then SinkDown
             * -- start the loop with first node and continute until its in correct position
             * -- at each iteration, swap it with one of its child, whoever is smaller if that child is smaller than
             *    current node
            */
          int n = this->values.size();
          // cout << "Size:- " << this->values.size() << endl;
          if(n <= 0) {
            return  &this->values;
          }
          if(n == 1) {
            this->values.pop_back();
            return  &this->values;
          }
           swap(this->values[0], this->values[this->values.size()- 1]);

           this->values.pop_back();
            
           sinkDown();
           return &this->values;
        }

        void sinkDown() {
            int currIndex = 0;
            while(true) { 
             int n = this->values.size();
              if(currIndex > n) return;
              int child_index_1 = 2*currIndex + 1;
              int child_index_2 = 2*currIndex + 2;
              int minSibiling;

              // cout << child_index_1 << " " << child_index_2 << " " << this->values.size() << endl;
              if(child_index_1 >= n && child_index_2 >= n) {
                return;
              } else if(child_index_2 >= n) {
                minSibiling = child_index_1;
                // cout << "MinSibling Called " <<  ;
              if(this->values[currIndex] > this->values[minSibiling]) {
                swap(this->values[currIndex], this->values[minSibiling]);
              }
                return;
              } else if (child_index_1 >= n) {
                minSibiling = child_index_2;
                if(this->values[currIndex] > this->values[minSibiling]) {   
                  swap(this->values[currIndex], this->values[minSibiling]);
                }
                return;
              } else {
                minSibiling = (this->values[child_index_1] < this->values[child_index_2]) ? child_index_1 : child_index_2;
              }

              if(this->values[currIndex] > this->values[minSibiling]) {
                swap(this->values[currIndex], this->values[minSibiling]);
                currIndex = minSibiling;
              }
                // int minSibling = min()
            }
        }

        void printArray() {
            for(auto i:values)
                cout << i << " -> ";
        }
};

int main() {
    MinBinaryHeap* heap = new MinBinaryHeap();
    // cout << heap->values.at(0) << endl;
    // cout << heap->values.at(1) << endl;

    // // heap->swap_bro(0,1);

    // cout << heap->values.at(0) << endl;
    // cout << heap->values.at(1) << endl;

    heap->push(9);
    heap->push(13);
    heap->push(11);
    heap->push(12);
    heap->push(2);
    heap->push(4);
    // heap->printArray();

    /** Remove Methods */

    heap->remove();
    heap->remove();
    heap->remove();


    heap->printArray();
}
    
