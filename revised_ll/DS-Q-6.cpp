#include<iostream>
using namespace std;
template<class T>
class Stack
{
	public:
		int size;
		T *Arr,top;
		Stack()
		{
//			cout<<"Enter the size of the array : ";
//			cin>>size;
			Arr=new T[size];
			top=-1;
		}
		~Stack()
		{
			while(!isEmpty())
			Pop();
			delete [] Arr;	
		}
		bool isEmpty();
		bool isFull();
		void input();
		void Push(T);
		T Pop();
		T PeekTop();
		void display();
		void menu();
		void menu_type();
};
template<class T>bool Stack<T>::isEmpty()
{
	if(top==-1)
	return true;
	else
	return false;
}
template<class T>bool Stack<T>::isFull()
{
	if(top==size-1)
	return true;
	else
	return false;
}
template<class T>void Stack<T>::input()
{
	cout<<"Enter the size of array : ";
	cin>>size;
}
template<class T>void Stack<T>::Push(T item)
{
	if(isFull())
	{
	cout<<"Stack Overflow"<<endl;
	}
	
	else
	{
		top++;
		Arr[top]=item;
		cout<<"Number pushed in stack!"<<endl;
	}
	
}
template<class T>T Stack<T>::Pop()
{
	if(isEmpty())
	{
	cout<<"Stack Underflow!"<<endl;
	return -1;
	}	
	else
	{
		T item;
		T x=Arr[top];
		top--;
		return x;
		cout<<"Number popped out"<<endl;	
	}
}
template<class T>T Stack<T>::PeekTop()
{
	if(!isEmpty())
	{
		
	return Arr[top];	
	}
	
	else
	{
		cout<<"Empty Stack"<<endl;
	}
}
template<class T>void Stack<T>::display()
{
	if(isEmpty())
	{
	 cout<<"Empty Stack"<<endl;	
	}
	
	else
	{
		cout<<"Stack is : ";
	for(int i=top;i>=0;i--)
	{
		cout<<Arr[i]<<"-->";
	}	
	}
}
template<class T>void Stack<T>::menu()
{
	char ch;
	int c;
	do{
        cout<<"Choose the desired option to perform:"<<endl;
        cout<<"1.Input"<<endl;
        cout<<"2.for push"<<endl;
        cout<<"3.for pop"<<endl;
        cout<<"4.for top item"<<endl;
        cout<<"5.for display Stack"<<endl;
        cout<<"Select your Option : ";
        cin>>c;
        switch(c){
        	case 1:
        		input();
        		break;
            case 2:    
                T num;
                cout<<"Enter value to push : ";
                cin>>num;
                Push(num);	
           //     cout<<"Number pushed in stack!"<<endl;
                break;
            case 3:
               cout<< Pop();
            //   cout<<"Number popped out"<<endl;
                break;
            case 4:
               cout<<"Top Item in Stack : "<<PeekTop();
                break;
            case 5:
               display();
		        break;
            default:
                cout<<"invalid selection !"<<endl;
                break;
        }
        cout<<endl<<"Do you want to continue?(y/n) ";
        cin>>ch;

    }while(ch=='y'||ch=='y');
}
template <class T> void Stack<T>::menu_type()
{
	int datatype;
    cout<<"enter the data type of circular linklist.\n1)int.\n2)char.\n";
    cin>>datatype;
    switch(datatype)
    {
        case 1:
        {
            Stack<int> obj;
            obj.menu();
            break;
        }
        case 2:
        {
            Stack<char> obj;
            obj.menu();
            break;
        }
    }
}
int main()
{
	Stack<int> obj;
	obj.menu_type();  
    return 0;

}
