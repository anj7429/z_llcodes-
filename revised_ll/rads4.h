#include<iostream>
using namespace std;
template <typename T>
class Node
{
	private:
		T data;
        Node<T>* next;
        Node<T>* prev;
        template<typename U>friend class DLL;
};
template <typename T>
class DLL
{
	public:
		 T val,data;
		 Node <T>* head;
		 Node <T>* tail;
		 DLL()
		 {
			head=NULL;
			tail=NULL;
		 }
		DLL(Node <T>*temp)
		{
			head=temp;
		}
		bool isEmpty();
		void InsertAtHead(T);
		void InsertAtTail(T);
	    void display();
	    T Count();
	    void Search();
	    void Reverse();
	    void Concat(DLL);
	    void menu();
	    void InsertAtI(T,int);
	    T DeleteFromHead();
	    T DeleteFromTail();
	    T DeleteFromI(int);
	    void menu_type();
};
