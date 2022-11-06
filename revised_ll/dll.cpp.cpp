#include<iostream>
#include"rads4.h"
using namespace std;
template<class T>
bool DLL<T>::isEmpty()
		{
			if(head==NULL)
			return true;
			
			else
			return false;
	    }
template<class T>void DLL<T>::display()
{
   Node <T>*temp;
   if(isEmpty())
   {
    cout<<"\nEMPTY LIST!"<<endl;
   }
   else
   {
    Node <T>*temp=head;
     cout<<"\nLinked List will be : ";
	 while(temp!=NULL)
	  {
	  	if(temp==head)
	    cout<<temp->data;
	    else
	    cout<<"<-->"<<temp->data;
	    temp=temp->next;
      }	
   }
   cout<<endl;
}
template<class T>void DLL<T>::InsertAtHead(T n)
{
	           Node <T>*New=new Node<T>();
	           New->data=n;
	           New->next=NULL;
	           New->prev=NULL;
	           if(isEmpty())
	           {
		        New->next=NULL;
		        New->prev=NULL;
	    	  	head=tail=New;	
	    	   }
	          else
    	       {
		       New->next=head;
		       head->prev=New;
		       head=New;
			   cout<<"\nNode sucessfully inserted at head."<<endl;
	           }
}
template<class T>T DLL<T>::Count()
{
	int count=0;
	Node<T> *temp=head;
	while(temp!=NULL)
	{
		temp=temp->next;
		++count;
	}
	return count;
}
template<class T>void DLL<T>::InsertAtI(T n,int i)
{
   int c=1;
   Node <T>*New=new Node<T>();
   New->data=n;
   New->next=NULL;
   New->prev=NULL;
   if(isEmpty())
   {
    New->next=head;
    head=New;
   }
   else
   {
          if(i>(Count()+1)||i<1)
          cout<<"Invalid position!!"<<endl;
	       if(i==1)
	       {
		     InsertAtHead(n);
	       }
	       else 
	       {
	         Node <T>*temp=head;
	         while(c!=i-1 && temp!=NULL)
		     {
			   c=c+1;
		       temp=temp->next;
		     }
			 if(temp==tail)
    	     {
    	     	InsertAtTail(n);
    	     }
    	     else
    	     {
		      New->next=temp->next;
	    	  New->prev=temp;
	    	  temp->next->prev=New;
	    	  temp->next=New; 
	    	 cout<<"Node insert successfully at "<<i<<" position."<<endl;
	         }
	       }
	       
}
}
template<class T>void DLL<T>::InsertAtTail(T n)
{
			Node <T>*New=new Node<T>();	
	        New->data=n;
           	New->next=NULL;
            New->prev=NULL;
	        if(isEmpty())
	        {
     		head=tail=NULL;
	        }
	        else
	        {
	       	if(head->next==NULL)
	       	{
	       		head->next=New;
	       		New->prev=head;
	       		tail=New;
	       	}
	       	else
	       	{
	       		tail->next=New;
	       		New->prev=tail;
	       		tail=New;
	        }
	        }
		  cout<<"Node successfully inserted at end "<<endl;	      
}
template<class T>
T DLL<T>::DeleteFromTail()
{
	Node<T> *temp=NULL;
	if(!isEmpty())
	{
		if(head==tail)
		{
			delete tail;
			head=NULL;
		}
		else
		{
			temp=tail->prev;
			delete temp->next;
			temp->next=NULL;
			tail=temp;
		}
		cout<<" Node Deleted from tail!!"<<endl;
	}
}
template<class T>T DLL<T>::DeleteFromHead()
{
	Node<T> *temp=NULL;
	if(!isEmpty())
	{
		if(head==tail)
		{
			delete tail;
			head=NULL;
			
		}
		else
		{
			temp=head;
			head=head->next;
			head->prev=NULL;
			delete temp;
		}
		cout<<"Node Deleted at head !!"<<endl;
	}
}
template<class T>T DLL<T>::DeleteFromI(int i)
{
	int c=1;
	Node<T> *temp=NULL;
	Node<T> *p=head;
	if(isEmpty())
	{
		cout<<"List is Empty! "<<endl;
	}
	else
	{
		if(i==1)
		DeleteFromHead();
		else
	    {
		while(c!=i && p->next!=NULL)
		{
			p=p->next;
			c++;
		}
		if(c==i)
		{
			p->prev->next=p->next;
			p->next->prev=p->prev;
			cout<<"Entered Node deleted sucessfully at " <<i<<" position "<<endl;
			delete p;
  		}
		else
		{
			cout<<"Value of i is out of scope! "<<endl;
	    }
	    }
	}
}
template<class T>void DLL<T>::Search()
{
		Node <T>*temp=head;
	    T val;
     	int c=1;
	    cout<<"Enter the element you want to search in Linklist : ";
	    cin>>val;
		while(temp!=NULL)
		{
			if(temp->data==val)
			{
				cout<<"Element found at address "<<temp<<" And at position "<<c<<endl;
				break;
			}
			else
			{
			temp=temp->next;
			c++;
			}
		}if(temp==NULL)
	cout<<"OOPS!Element not Found in linklist!"<<endl;

}
template<class T>void DLL<T>::Concat(DLL l2)
{
	if(isEmpty())
	{
		cout<<"List1 is empty"<<endl;
		l2.display();
	}
	else if(l2.isEmpty())
	{
		cout<<"List2 is empty"<<endl;
		display();
	}
	else
	{
		Node<T>*temp=tail;
		temp->next=l2.head;
		l2.head->prev=temp;
		display();
	}
}
template<class T>void DLL<T>::Reverse()
{
	if(!isEmpty())
	{
		if(head==tail)
		cout<<"Reversal not needed !"<<endl;
		else
		{
			Node<T> *curr=head;
			Node<T> *p=head->next;
			while(curr!=NULL)
			{
				p=curr->next;
				curr->next=curr->prev;
				curr->prev=p;
				curr=p;
			}
			curr=head;
			head=tail;
			tail=curr;
		}
	}
}
template<class T>void DLL<T>::menu()
{
	DLL<T> l2;
	int choice,i;
	char ch;
	do
		{
			cout<<"\n------------- Doubly Linked List -------------"<<endl;
            cout<<"\n1.Insert node at beginning.\n2.Insert node at ith position\n3.Remove node at beginning.\n4.Remove node at ith position.\n5.Search for element in the list.\n6.To display list\n 7.for Reverse the list."<<endl;
            cout<<"8.Insert at tail\n9.Delete from tail\n10.Concat list\n";
			cout<<"\nEnter your choice :";
            cin>>choice;
			switch(choice)
				   {
				   	case 1:
				   		cout<<"Enter data to insert : ";
				   		cin>>data;
				   		InsertAtHead(data);
				   	break;
				   		
				   	case 2:
				   		cout<<"Enter data to insert : ";
				   		cin>>data;
				   		cout<<"Enter position : ";
				   		cin>>i;
				   		InsertAtI(data,i);
				   		break;
				   	case 3:
				   		DeleteFromHead();
				   		break;
				   	case 4:
				   		cout<<"Enter the position you want to delete : ";
				   		cin>>i;
				   		DeleteFromI(i);
				   		break;
				   	case 5:
				   		Search();
				   		break;
				   	case 6:
				   		display();
				   		break;
				  case 7:
				  	cout<<"Original list : ";
				  	display();
				  	cout<<"List After reversing : ";
				   	Reverse();
				   	display();
				   	break;
				   	case 8:
						cout<<"Enter the data:";
						cin>>data;
				   		InsertAtTail(data);
				   		break;
				   	case 9:
						DeleteFromTail();
						break;
				   	case 10:
				   		l2.menu();
				   		Concat(l2);
				   		break;	
				   }
			cout<<"Press y to continue : ";
			cin>>ch;
        }while(ch=='y');
}
template<class T>void DLL<T>::menu_type()
{
    int datatype;
    cout<<"enter the data type of circular linklist.\n1)int.\n2)float.\n3)char.\n";
    cin>>datatype;
    switch(datatype)
    {
        case 1:
        {
            DLL<int> obj;
            obj.menu();
            break;
        }
        case 2:
        {
            DLL<float> obj;
            obj.menu();
            break;
        }
        case 3:
        {
            DLL<char> obj;
            obj.menu();
            break;
        }
    }
}
int main()
{
	DLL<int>ob;
	ob.menu_type();
	return 0;
}
