#include<iostream>
using namespace std;
template <class t>
class node
{
    private:
        t data;
        node<t> *next;
        template <class x> friend class cll;
};
template <class t>
class cll
{
    private:
        node<t> *cursor;
        public:
            cll();
           // ~cll();
            bool isEmpty();
            void menu();
            void display();
            void addAtFront(t);
            void addAfter(t,t);
            void addBefore(t);
            void concatenate(cll l2);
            t remove(t);
            t deleteBefore();
            t deleteAfter();
            node<t> *search(t);
};
template <class t>
cll<t>::cll()
{
    cursor=NULL;
}
template <class t>
bool cll<t>::isEmpty()
{
    if(cursor==NULL)
    return true;
    else
    return false;
}
template <class t>
void cll<t>::display()
{
    cout<<"your list is : ";
    if(!isEmpty())
    {
        node<t> *temp=cursor;
        cout<<temp->data<<" ";
        temp=temp->next;
        while(temp!= cursor)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
    else
    cout<<"empty list\n";
}
template <class t>
void cll<t>::addAtFront(t val)
{
    node<t> *temp=new node<t>();
    temp->data=val;
    temp->next=NULL;
    if(isEmpty())
    {
        cursor=temp;
        cursor->next=cursor;
    }
    else
    {
    temp->next=cursor->next;
    cursor->next=temp;
    }
}
template <class t>
void cll<t>::addAfter(t val,t insval)
{
    node<t> *temp=new node<t>();
    temp->data=insval;
    temp->next=NULL;
    node<t> *point=cursor;
    if(!isEmpty())
    {
        if(point->data==val)
            addAtFront(insval);
        else{
            point=point->next;
            while(point->data!=val && point!=cursor)
                point=point->next;
        if(point->data==val)
        {
            temp->next=point->next;
            point->next=temp;
        }
        else 
        {
            cout<<"Unable to insert as list is empty\n";
        }
        }
    }
    else
        cout<<"list is empty.\n";
}
template <class t>
void cll<t>::addBefore(t val)
{
    node<t> *temp=new node<t>();
    temp->data=val;
    temp->next=NULL;
    if(!isEmpty())
    {
        node<t> *prev=cursor;
        while(prev->next!=cursor)
        prev=prev->next;
        prev->next=temp;
        temp->next=cursor;
    }
    else
    addAtFront(val);
}
template <class t>
t cll<t>::remove(t val)
{
    if(!isEmpty())
    {
        node<t> *curr=cursor;
        node<t> *prev=cursor;
        while(curr->data!=val && prev->next!=cursor)
        {
            prev=curr;
            curr=curr->next;
        }
        if(curr->data==val && curr!=cursor)
        {
            prev->next=curr->next;
            curr->next=NULL;
            t y=curr->data;
            delete curr;
            cout<<"value deleted.\n";
            return y;
        }
        else if(curr==cursor && prev==cursor && cursor->data==val)
        {
            if(curr->next==cursor)
            {
                cursor=NULL;
                delete curr;
            }
            else
            {   
                while(prev->next!=cursor)
                    prev=prev->next;
                prev->next=cursor->next;
                delete curr;
                cursor=prev;
                cout<<"deleted successfully \n";
            }
        }
        else
            cout<<"element is not present in linklist\n";
    }
    else
        cout<<"list is empty.\n";
}
template <class t>
t cll<t>::deleteBefore()
{
    if(!isEmpty())
    {
        node<t> *temp=cursor;
        node<t> *del=NULL;
        if(cursor->next!=cursor)
        {
            while(temp->next->next!=cursor)
                temp=temp->next->next;
            del=temp->next;
            temp->next=cursor;
            del->next=NULL;
            t data=del->data;
            delete del;
            return data;
        }
        else
        {
            t x=cursor->data;
            cursor=NULL;
            delete temp;
            return x;
        }
    }
}
template <class t>
t cll<t>::deleteAfter()
{
    if(!isEmpty())
    {
        node<t> *temp=cursor;
        node<t> *point=cursor;
        if(cursor->next!=cursor)
        {
            temp=temp->next;
            point->next=temp->next;
            temp->next=NULL;
            t x=temp->data;
            delete temp;
            return x;
        }
        else
        {
            t x=cursor->data;
            cursor=NULL;
            delete temp;
            return x;
        }
    }
}
template <class t>
node<t>* cll<t>::search(t value)
{
    if(isEmpty())
    cout<<"list is empty,No element found.\n";
    else
    {
        node<t> *temp=cursor;
        if(temp->data==value)
        return cursor;
        else{
            temp=temp->next;
            while(temp!=cursor)
            {
                if(temp->data==value)
                {
                cout<<"Element found at address ";
                return temp;
                }
                else
                temp=temp->next;
            }
            if(temp==cursor)
            {
                cout<<"\nelement not found \n";
            }
        }
    }
    return NULL;
}
template <class t>
void cll<t>::concatenate(cll l2)
{
    if(!isEmpty())
    {
        node<t> *temp=cursor;
        node<t> *newtemp=l2.cursor;
        while(temp->next!=cursor)
            temp=temp->next;
        while(newtemp->next!=l2.cursor)
            newtemp=newtemp->next;
        temp->next=l2.cursor;
        newtemp->next=cursor;
        l2.cursor=NULL;
    }
    else
    {
        cursor=l2.cursor;
        l2.cursor=NULL;
    }
}
template <class t>
void cll<t>::menu()
{
    cll<t> l2;
    char c;
    int ask,index;
    t value,insvalue;
    do
    {
     cout<<"*****CIRCULAR LINKLIST*****\n Choose the desired operation to perform : \n1)add after cursor.\n2)add before cursor.\n3)add after value.\n4)remove by value.\n5)delete before cursor.\n6)delete after cursor.\n7)concatenation.\n8)searching\n9)display \n";
     cin>>ask;
     switch(ask)
     {
         case 1:
         {
             cout<<"enter data you want to insert.\n";
             cin>>value;
             addAtFront(value);
             break;
         }
         case 2:
         {
             cout<<"enter data you want to insert.\n";
             cin>>value;
             addBefore(value);
             break;
         }
         case 3:
         {
            
             cout<<"enter data you want to insert.\n";
             cin>>insvalue;
             cout<<"enter the data after which you want to insert.\n";
             cin>>value;
             addAfter(value,insvalue);
             break;
         }
         case 4:
         {
            cout<<"enter data you want to delete.\n";
            cin>>value;
            remove(value);
            break;
         }
         case 5:
         {
             deleteBefore();
             break;
         }
         case 6:
         {
            deleteAfter();
            break;
         }
         case 7:
         {
            l2.menu();
            concatenate(l2);
            break;
         }
         case 8:
         {
             cout<<"enter data you want to search.\n";
             cin>>value;
             cout<<search(value)<<endl;
             break;
            }
         case 9:
         {
             display();
             break;
         }           
     }
     cout<<"do you want to continue?(y/n)\n";
     cin>>c;
    }while(c=='y' || c=='Y');
}
void menu_type()
{
    int datatype;
    cout<<"enter the data type of circular linklist.\n1)int.\n2)float.\n3)char.\n";
    cin>>datatype;
    switch(datatype)
    {
        case 1:
        {
            cll<int> obj;
            obj.menu();
            break;
        }
        case 2:
        {
            cll<float> obj;
            obj.menu();
            break;
        }
        case 3:
        {
            cll<char> obj;
            obj.menu();
            break;
        }
    }
}
int main()
{
    menu_type();
    return 0;
}
