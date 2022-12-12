#include <iostream>
#include <typeinfo>
using namespace std;

class Node {
    public:
        string value;
        Node* next;

        Node(string val) {
            this->value = val;
            this->next = NULL; // This is important to do or it will point to some random Node Pointer
        }
};

class LinkedList {
    public:
    
        Node* head;
        Node* tail;
        int length = 0;


        /**
         * @brief Available Methods
         * 
         * * push (O(1))
         * * pop (O(N)) : N is number of nodes in List
         * * shift : (O(1))
         * * unshift : (O(1))
         * * reverse : (O(N))
         * * insert by postion : (O(N))
         * * remove by position : (O(N))
         * * get method : (O(N))
         * * set method : (O(N))
         * * print(optional)
         */


        Node* push(string val) {
            Node* newNode = new Node(val);

            if(!this->length) {
                // cout<<"It's zero brother";

                this->head = newNode;
                this->tail = newNode;
            } else {
                Node* temp = this->tail;
                temp->next = newNode;
                this->tail = newNode;
            }

            this->length++;

            return newNode;
        }

        Node* pop() {
            /**
             * @brief 
             * - Loop until there is next of next, once you reach store curr
             * - and set it's next property to null
             * 
             */

            Node* curr = this->head;

            /**
             * 1->2->3->4
             * 
             * Now once it would reach at 3 then
             * 3->next->next = 0;
             * 
             * that's why loop will end
             */
            int count = 1;
            while(count < this->length-1) {
                curr = curr->next;
                count++;
            }



            this->tail = curr;

            Node* removedNode = curr->next;
            curr->next = 0;

            this->length--;

            return removedNode;
        }

        Node* get(int pos) {
            if(pos >= this->length) {
                return NULL;
            };

            if(pos == 0) return this->head;
            if(pos == this->length - 1) return this->tail;

            int start = 1;

            Node *curr = this->head;

              // 1,2,3,4,5

            while(start <= pos) {
                curr = curr->next;
                start++;
            }

            return curr;
        }

        Node* set(string val, int pos) {
            Node* itemToBeUpdated = this->get(pos);
            itemToBeUpdated->value = val;
            return itemToBeUpdated;
        }


        Node* insert(string val, int pos) {
            // 1-> 2 -> 3-> 4->5
            // store 2 and its next;
            // and then 2->next = newNode->next = oldNext;
          if(pos >= this->length) return NULL;

          // ? Write insert method;
        }


        Node* remove(int pos) {
            // 1-> 2-> 3-> 4-> 5

            if(pos == 0) {
                Node* item = this->shift();
                if (item) {
                    return item;
                } else {
                    return NULL;
                }
            }

            if(pos == this->length - 1) {
                Node* item = this->pop();
                if (item) {
                    return item;
                } else {
                    return NULL;
                }
            } 


            Node* prevItem  = this->get(pos - 1);
            Node* removeItem = prevItem->next;
            prevItem->next = prevItem->next->next;

            removeItem->next = NULL;

            this->length --;

            return removeItem;  
        }


        Node* unshift(string val) {
            Node* newNode = new Node(val);

            if(this->length == 0) {
                this->head = newNode;
                this->tail = newNode;
            } else {
                Node* temp = this->head;

                newNode->next = temp;

                this->head = newNode;
            }

            this->length++;

            return newNode;
        }


        Node* shift() {
            if(this->length == 0) {
                Node* newHead = NULL;
                return newHead;  
            };
            Node* nodeToBeRemoved = this->head; // 2 -> 3-> 4-> 5
            // 1-> 2-> 3-> 4-> 5
            if(this->length == 1) {
                this->head=NULL;
                this->tail=NULL;
                this->length--;
                return nodeToBeRemoved;
            };
            // if(this->length == 2) {
            //     this->head = this->tail;
            //     return this->head;
            // } else {
                Node* temp = nodeToBeRemoved->next; //
                this->head = temp; //
                nodeToBeRemoved->next = NULL;

                this->length--;


                return nodeToBeRemoved;
            // }

            
        }


        Node* reverse() {
            // 1->2->3->4->5

            /**
             * @brief Steps to do
             * define one empty Node* variable called newHead;
             * start with curr = this->head;
             * and store curr.next in temp
             * and then take temp.next and assign it newHead and
             * then reasssing newHead to curr
             * 
             */

            // Node* to define and store class;
            // Node *curr to only store address of class;
            Node* curr;
            Node* newHead = NULL;

            curr = this->head;

            while(curr) {
                Node* temp;
                temp = curr->next; // 2->3->4->5 // 3->4->5
                curr->next = newHead; // 1->next = Empty; // 2->1->empty
                newHead = curr; // 1->empty // 2->1-empty
                curr=temp; // 2->3->4->5 // 3->4->5
            }

            this->head = newHead;
            return this->head;
        }

        void print() {
            Node* item = this->head;

              // Using for loop
            // for(int i = 0; i < this->length; i++) {
            //     cout<< item->value << endl;
            //     item = item->next;
            // }


            Node* item2 = this->head;

             // Using While loops
             while(item2) {
                cout<<item2->value << endl;
                item2 = item2->next;
             }
        }


};

// Class* stores the address of current system
// And if you've stored address instead of instance then you can access its properties using
// -> pointer
int main() {

    /**
     * @brief Node Class Instance Example
     * 
     */
    // // ? Using value
    // Node linked_node_1 = Node("Heroine");
    // cout<<linked_node_1.value << endl;
    // cout<<linked_node_1.next << endl;

    // // ? Storing Pointer;

    // Node* linked_node = new Node("Naruto");
    // cout<<linked_node << endl; // Gives you address of that instance;
    // cout<<linked_node->value << endl; // Gives you value;
    // cout<<linked_node->next << endl;

    /**
     * @brief Linked List Class Instance Examples
     * 
     */


    LinkedList* linked_list = new LinkedList();
    

    linked_list->push("Sasuke");
    linked_list->push("Naruto");
    linked_list->push("Kakashe");
    linked_list->push("Sakura");
    linked_list->push("Hinata");
    linked_list->unshift("Jiraya");
    linked_list->unshift("Tsunade");
    linked_list->unshift("Orochimaru");
    

    // linked_list->reverse();

    // cout << "Removed Item: " << linked_list->pop()->value << endl << endl;
    // cout << "Removed Item: " << linked_list->pop()->value << endl << endl;

    // cout << linked_list->remove(1)->value<< endl << endl;
    // cout << linked_list->remove(0)->value<< endl << endl;


    // cout << linked_list->set("Naruto Uzumaki", 1)->value<< endl << endl;
    cout << linked_list->length;



    linked_list->print();

    /** * Get Method */
    // cout<<linked_list->get(0)->value;
    // cout<<linked_list->get(1)->value;
    // cout<<linked_list->get(2)->value;
    // cout<<linked_list->get(3)->value;
    // cout<<linked_list->get(4)->value << endl;
    // cout<<linked_list->get(5) << endl;
    // cout<<linked_list->unshift("Hello World")->value << endl;
  
};