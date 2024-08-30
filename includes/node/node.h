#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <iomanip>

template <typename ITEM_TYPE>
struct node
{
    public:

        node(const ITEM_TYPE& item = ITEM_TYPE(), node* next = nullptr)
        {
            _item = item;
            _next = next;
        }

        template <typename T>
        friend std::ostream& operator <<(std::ostream& outs, const node<T> &printMe);

        ITEM_TYPE _item;
        node* _next;

};

template <typename T>
std::ostream& operator <<(std::ostream& outs, const node<T> &printMe)
{
    outs << printMe._item;
    return outs;
}

#endif