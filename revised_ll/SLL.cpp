#include<iostream>
#include"SLL.h"
using namespace std;
template<class T>
SLL<T>::SLL(Node <T>*temp)
{
	head=temp;
}
template<class T>bool SLL<T>::isEmpty()
		{
			if(head==NULL)
			return true;
			
			else
			return false;
	    }
template<class T>void SLL<T>::display()
{
   Node <T>*temp;
   if(isEmpty())
   {
    cout<<"\nEMPTY LIST!!"<<endl;
   }
   else
   {
    Node <T>*temp=head;
     cout<<"\nLinked List : ";
	 while(temp!=NULL)
	  {
	   cout<<temp->data<<"-->";
	  temp=temp->next;
      }	
   }
   cout<<endl;
}
template<class T>void SLL<T>::InsertAtHead(T n)
{
	           Node <T>*New_n=new Node<T>();
	           New_n->data=n;
	           New_n->next=NULL;
	          if(isEmpty())
	          {
		        New_n->next=NULL;
		        
	    	    head=New_n;
	    	    cout<<"\nNode inserted sucessfully at head "<<endl; 
	    	    return;			
			  }
	          else
    	      {
		       New_n->next=head;
		       head=New_n;
			   cout<<"\nNode inserted sucessfully at head "<<endl;
	           }
}
template<class T>void SLL<T>::InsertAtI(T n,int i)
{
   int c=1;
   Node <T>*New_n=new Node<T>();
   New_n->data=n;
   New_n->next=NULL;
   if(isEmpty())
   {
    New_n->next=head;
    head=New_n;
   }
   	if(i==1)
	{
		InsertAtHead(n);
	}
	else
	{
		int c=1;
		Node<T>*temp=head;
		while(c!=i-1)
		{
			c=c+1;
			temp=temp->next;
		}
		Node<T>*p=temp->next;
		temp->next=New_n;
		New_n->next=p;
	if(c==i-1)
	{
		cout<<"Element inserted successfully at position "<<i<<endl;
	}
	else
	{
		cout<<"Invalid position "<<endl;
	}
      }
}
template<class T>void SLL<T>::InsertAtTail(T n)
{
			Node <T>*New=new Node<T>();	
	        New->data=n;
           	New->next=NULL;

	       if(isEmpty())
	       {
     		head=New;
	       }
	       else
	       {
	       	  Node <T>*temp=head;
		        while(temp->next!=NULL)
	        	{
			       temp=temp->next;
		     	}temp->next=New;
		    }
		  cout<<"Node inserted successfully at end "<<endl;
		      
}
template<class T>T SLL<T>::RemoveFromHead()
{
	Node <T>*temp=head;
	if(isEmpty())
	{
		cout<<"Empty list"<<endl;
	}
    else
    {
    	Node <T>*temp=head;
    	head=head->next;
    	if(temp->next!=NULL)
    	temp->next=NULL;
    	T x=temp->data;
    	delete temp;
    	return x;
    	cout<<"Node deleted sucessfully at head"<<endl;
	}
}
template<class T>T SLL<T>::RemoveFromI(int i)
{
	if(isEmpty())
	{
		cout<<"The list is empty.\n";
	}
	else
	{
	if(i==1)
	{
		RemoveFromHead();
	}
	else
	{
		Node <T>*prev=NULL;
		Node <T>*curr=head;
		int c=1;
		while(c!=i && curr->next!=NULL)
		{
			prev=curr;
			curr=curr->next;
			c++;
		}
		if(c==i)
		{
			T x=curr->data;
			prev->next=curr->next;
			curr->next=NULL;
			delete curr;
			cout<<"Entered Node deleted sucessfully at " <<i<<" position "<<endl;
			return x;			
		}
		else
		cout<<"Index out of bound!"<<endl;
	}
	}	
}
template<class T>void SLL<T>::concat(SLL l2)
{
	if(isEmpty())
	{
		cout<<"List1 is empty! "<<endl;
		l2.display();
	}
	else if(l2.isEmpty())
	{
		cout<<"List2 is empty! "<<endl;
		display();
	}
	else
	{
		Node<T>*temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=l2.head;
		l2.head=NULL;
		display();
	}
}
template<class T>void SLL<T>::Reverse()
{
	if(isEmpty())
	{
		cout<<"Empty List"<<endl;
	}
	else
	{
		Node<T>*temp=NULL;
		Node <T>*prev=NULL;
		Node <T>*curr=head;
		
       while(curr!=NULL)
	   {
		 temp=curr->next;
		 curr->next=prev;
		 prev=curr;
		 curr=temp;
	   }	
	   head=prev;
   }
   display();
}
template<class T>void SLL<T>::Search()
{
	Node <T>*temp=head;
	T ele;
	int c=1;
	cout<<"Input element you want to search in linklist : ";
	cin>>ele;
		while(temp!=NULL)
		{
			if(temp->data==ele)
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
	cout<<"Element not Found."<<endl;

}

template<class T>void SLL<T>::menu()
{
	SLL<T>l2;
	int i;
	int choice;
	char ch;
	int data,ele;
	do{				
        cout<<"\n     **** Singly Linked List *****"<<endl;
        cout<<"\n1. To Insert node at beginning.\n2.To Insert node at ith position\n3.To Remove node at beginning.\n4.To Remove node at ith position.\n5.To Search for element in the list.\n6.To display the linklist\n 7.To reverse the list.\n 8.To Insert at tail\n";
		cout<<"9.To concatenate\n";
		cout<<"\nEnter your choice :";
        cin>>choice;
			switch(choice)
			{
				   	case 1:
				   		cout<<"Enter data you want to  insert : ";
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
				   		RemoveFromHead();
				   		break;
				   	case 4:
				   		cout<<"Enter the position you want to delete : ";
				   		cin>>i;
				   		RemoveFromI(i);
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
				   	    break;
				   	case 8:
						cout<<"Enter the data:";
						cin>>data;
				   		InsertAtTail(data);
				   		break;
				   	case 9:
				   		l2.menu();
					    concat(l2);
						break;	
				   	default:
		            cout<<"Invalid input entered "<<endl;
		            break; 
		    }
				   cout<<"Press (y/Y) to continue and (n/N)for exit ";
				   cin>>ch;
       }
                while(ch=='y'|| ch=='Y');
}
template<class T>void SLL<T>::menu_type()
{
	int datatype;
    cout<<"enter the data type of circular linklist.\n1)int.\n2)float.\n3)char.\n";
    cin>>datatype;
    switch(datatype)
    {
        case 1:
        {
            SLL<int> obj;
            obj.menu();
            break;
        }
        case 2:
        {
            SLL<float> obj;
            obj.menu();
            break;
        }
        case 3:
        {
            SLL<char> obj;
            obj.menu();
            break;
        }
    }
}
int main()
{
	SLL<int>ob;
	ob.menu_type();
	return 0;
}
