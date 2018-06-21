#include "Link_List.h"

template <typename T>
Link_List<T>::Link_List()
{
    head = NULL;
    tail = NULL;
    size = 0;
}

template <typename T>
Link_List<T>::Link_List(const Link_List<T> &ll)
{
    this->size = ll.size;
	if(ll.head == NULL)
        head = NULL;
    else
    {
        head = new Int_Node<T>;
        head->value = ll.head->value;

        Int_Node<T> *newnode = head;
        newnode->next = NULL;
        newnode->pre = NULL;

        for(Int_Node<T> *s = ll.head;s != NULL;s = s->next)
        {
            newnode->next = new Int_Node<T>;
            newnode->next->pre = newnode;
            newnode = newnode->next;
            newnode->value = s->value;
        }
        tail = newnode;
        newnode->next = NULL;
    }
    if(size>0)
        delete_node(0);
    size = ll.size;
}

template <typename T>
Link_List<T>::~Link_List()
{
	clear();
}

template <typename T>
int Link_List<T>::getSize() const
{
    return size;
}

template <typename T>
const Link_List<T> &Link_List<T>:: operator =(const Link_List<T> &ll)
{
    this->clear();
    Int_Node<T> *node = new Int_Node<T>;
    node = ll.head->next;

    while(node != NULL)
    {
    	this->insert_node(node->value);
    	node = node->next;
	}
	//delete_node(0);
	//this->size = ll.size;
	return *this;
}

template <typename T>
bool Link_List<T>:: operator ==(const Link_List<T> &right) const
{
    if(right.size != size)
        return false;
    else
    {
        for(int i=0;i<size;i++)
        {
            if(right[i] != (*this)[i])
                return false;
        }
        return true;
    }
}

template <typename T>
bool Link_List<T>:: operator !=(const Link_List<T> &right) const		// inequality operator
{
    return !(*this == right);
}

template <typename T>
T &Link_List<T>:: operator [](int index)
{
    Int_Node<T> *ptr = head;

    for(int i=0;i<index;i++)
    {
        ptr = ptr->next;
    }

    return ptr->value;
}

template <typename T>
T Link_List<T>:: operator [](int index) const
{
    Int_Node<T> *ptr = head;

    for(int i=0;i<index;i++)
    {
        ptr = ptr->next;
    }

    return ptr->value;
}

template <typename T>
bool Link_List<T>::insert_node(T v)
{
    bool t = false;
	Int_Node<T> *newnode = new Int_Node<T>;
	newnode->value = v;

    if(size != 0)
    {
        newnode->pre = tail;
        newnode->next = NULL;

        tail->next = newnode;
        tail = newnode;
        t=true;
    }
    else
    {
    	newnode->pre = NULL;
    	newnode->next = NULL;

        head = newnode;
        tail = newnode;
        t=true;
    }
    ++size;
    return t;
}

template <typename T>
bool Link_List<T>::insert_node(int index, T v)
{
    bool t = false;

	if(size == 0)
    {
        insert_node(v);
        t = true;
    }
    else
    {
        Int_Node<T> *node = head;

        for(int i=0;i<index;i++)
            node = node->next;

        Int_Node<T> *newnode = new Int_Node<T>;
        newnode->value = v;
        newnode->next = node;
        newnode->pre = node->pre;

        if(node->pre != NULL)
            node->pre->next = newnode;
        node->pre = newnode;

        if(index == 0)
            head = newnode;
        if(index == size-1)
            tail = newnode->next;
        ++size;
        t = true;
    }
    return t;
}

template <typename T>
bool Link_List<T>::delete_node()
{
    if(head == tail && size == 1)
    {
        delete head;
        head = NULL;
        tail = NULL;
    }
    else
    {
        tail = tail->pre;
        delete tail->next;
        tail->next = NULL;
    }
    size--;
    return true;
}

template <typename T>
bool Link_List<T>::delete_node(int index)
{
    Int_Node<T> *node = head;

    for(int i=0;i<index;++i)
        node = node->next;

    if(node->pre != NULL)
        node->pre->next = node->next;

    if(node->next !=NULL)
        node->next->pre = node->pre;

    if(tail == node && node->pre != NULL)
        tail = node->pre;

    if(head == node && node->next != NULL)
        head = node->next;

    if(head == tail && tail == node)
        head = tail = NULL;

    node->next = node->pre = NULL;
    --size;

    return true;
}

template <typename T>
void Link_List<T>::clear()
{
    while(this->size > 0)
    {
        this->delete_node();
    }
    head = NULL;
    tail = NULL;
    size = 0;
}

template <typename U>
ostream & operator <<(ostream &out, const Link_List<U> &ll)
{
    Int_Node<U> *node = ll.head;
    while(node != NULL)
    {
        out << node->value << " ";
        node = node->next;
    }
    return out;
}

template <typename U>
istream & operator >>(istream &in, Link_List<U> &ll)
{
    Int_Node<U> *node = ll.head;
    for(int i=0;i<ll.size;i++)
        node = node->next;

    U v;
    in >> v;
    ll.insert_node(v);
    return in;
}

template class Link_List<int>;
template ostream & operator <<(ostream &, const Link_List<int> &);
template istream & operator >>(istream &, Link_List<int> &);
