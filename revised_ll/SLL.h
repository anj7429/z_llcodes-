#include<iostream>
using namespace std;
template<typename T>class Node
{
    private:
        T data;
        Node<T>* next;
        template<typename U>friend class SLL;
};
template <typename T>
class SLL
{
	public:
		 Node <T>* head;
		 SLL()
		 {
			head=NULL;
		 }
		 SLL(Node <T>*temp);
		bool isEmpty();
		void InsertAtHead(T);
		void InsertAtTail(T);
		void InsertAtI(T ,int );
		 T Count();
		void concat(SLL);
	    T RemoveFromHead();
	    T RemoveFromTail();
	    T RemoveFromI(int);
	    void display();
	    void menu();
	    void Reverse();
	    void Search();
	    void menu_type();
};
