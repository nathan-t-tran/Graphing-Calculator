#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>
#include <iomanip>
#include "../../includes/node/node.h"
#include "../../includes/linked_list_functions/linked_list_functions.h"

template <typename T>
class Stack{
public:
    class Iterator{
    public:
        friend class Stack;                     //give access to list to access _ptr
        Iterator(){_ptr = NULL;}                //default ctor
        Iterator(node<T>* p){_ptr =p;}          //Point Iterator to where
                                                //  p is pointing to

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
        node<T>* _ptr;                          //pointer being encapsulated
    };

    Stack() //Initializes node.
    {
        _top = nullptr;
        _size = 0;
    }

    Stack(const Stack<T>& copyMe) //Copy CTOR
    {
        
        delete _top;
        _size = copyMe._size; //Copies size.
        _top = _copy_list(copyMe._top); //Copies node list.
    }

    ~Stack() //DESTRUCTOR
    {
        _clear_list (_top);
    }

    Stack<T>& operator=(const Stack<T>& RHS) //Assignment OP 
    {
        delete _top;
        _size = RHS._size; //Copies size
        _top = _copy_list(RHS._top); //Copies node list.
        return *this;
    }

    T top() //Returns the item of top node.
    {
        return _top->_item; //Returns top item.
    }

    bool empty(){return _top == nullptr;}

    void push(T item)
    {
        _insert_head (_top, item);
        _size++;
    }

    T pop()
    {
        assert (_top != nullptr && "_top was expected to not be nullptr.");
        T item_removed = _delete_node (_top, _top);
        _size--;
        return item_removed;
    }
    template<typename TT>
    friend ostream& operator<<(ostream& outs,  const Stack<TT>& printMe);
                                       
    Iterator begin() const              //Iterator to the head node
    {
        return Iterator(_top);
    }

    Iterator end() const               //Iterator to NULL
    {
        return Iterator();
    }
    int size() const { return _size; }

private:
    node<T>* _top;
    int _size;
};

template<typename TT>
ostream& operator<<(ostream& outs, const Stack<TT>& printMe)
{
    cout << "Stack:Head->";
    _print_list(printMe._top);
    return outs;
}

#endif