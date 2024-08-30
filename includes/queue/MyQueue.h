#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <iostream>
#include <iomanip>
#include "../../includes/node/node.h"
#include "../../includes/linked_list_functions/linked_list_functions.h"

template <typename T>
class Queue
{
public:
    class Iterator{
    public:
        friend class Queue;          //give access to list to access _ptr
        Iterator(){_ptr = NULL;}                  //default ctor
        Iterator(node<T>* p){_ptr = p;}        //Point Iterator to where
        //...                        //  p is pointing to
        T& operator *()                        //dereference operator
        {
            return _ptr->_item;
        }
        T* operator ->()                       //member access operator
        {
            return &(_ptr->_item);
        }

        bool is_null()                                 //true if _ptr is NULL
        {
            return (_ptr == nullptr);
        }

        friend bool operator !=(const Iterator& left,
                                const Iterator& right) //true if left != right
        {
            return (left._ptr != right._ptr);
        }

        friend bool operator ==(const Iterator& left,
                                const Iterator& right) //true if left == right
        {
            return (left._ptr == right._ptr);
        }

        Iterator& operator++()                         //member operator: ++it; or ++it = new_value
        {
            _ptr = _ptr->_next;
            return *this;
        }

        friend Iterator operator++(Iterator& it,
                                   int unused)         //friend operator: it++
        {
            Iterator temp(it._ptr);
            it._ptr = it._ptr->_next;
            return temp;
        }
 
    private:
        node<T>* _ptr;               //pointer being encapsulated
    };

    Queue()
    {
        _front = nullptr;
        _rear = _front;
        _size = 0;
    }

    Queue(const Queue<T>& copyMe)
    {
        _front = nullptr;
        _front = _copy_list(copyMe._front);
        _rear = copyMe._rear;
        _size = copyMe._size;
    }
    ~Queue()
    {
        _clear_list(_front);
    }
    Queue& operator=(const Queue<T>& RHS)
    {
        _front = nullptr;
        _front = _copy_list(RHS._front);
        _rear = RHS._rear;
        _size = RHS._size;
        return *this;
    }

    bool empty()
    {
        return (_front == nullptr);
    }
    T front()
    {
        return _front->_item;
    }
    T back()
    {
        return _rear->_item;
    }

    void push(T item)
    {
        _rear = _insert_after (_front, _rear, item);
    }

    T pop()
    {
        T item_popped = _delete_node (_front, _front);
        return item_popped;
    }

    Iterator begin() const            //Iterator to the head node
    {
        return Iterator(_front);
    }
    Iterator end() const              //Iterator to NULL
    {
        return Iterator();
    }
    void print_pointers();
    int size() const { return _size; }
    template<typename TT>
    friend ostream& operator << (ostream& outs, const Queue<TT>& printMe);
private:
    node<T>* _front;
    node<T>* _rear;
    int _size;
};

template<typename TT>
ostream& operator << (ostream& outs, const Queue<TT>& printMe)
{
    cout << "Queue:Head->";
    _print_list (printMe._front);
    return outs;
}

#endif