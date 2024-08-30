#ifndef VECTOR_CLASS_H
#define VECTOR_CLASS_H
#include <iostream>
#include <cassert>
#include <assert.h>
#include <iomanip>

#include "../../includes/add_entry/add_entry.h"
#include "../../includes/array_functions/array_functions.h"

using namespace std;

template <class T>
class Vector{
public:

    Vector(int size = 100){
        _s = allocate<T>(size);
        _size = 0;
        _capacity = size;
    }
    Vector(T *arr, int size){
        _s = allocate<T>(size);
        copy_array(_s, arr, size);
        _size = size;
        _capacity = _size;
    }
    // big three:
    ~Vector(){   //destructor
        delete [] _s;
    }
    Vector(const Vector& other){ //copy constructor
        _size = other._size;
        _capacity = other._capacity;
        _s = allocate<T>(_capacity);
        copy_array(_s, other._s, _size);
    }
    Vector& operator =(const Vector& RHS){
        if (this==&RHS){
            return *this;
        }
        delete [] _s;
        _size = RHS._size;
        _capacity = RHS._capacity;
        _s = allocate<T>(_capacity);
        copy_array(_s,RHS._s, _size);
        return *this;
    }
    //member access functions:
    T& operator [](int index){
        assert(index<_size&&index>-1);
        return at(index);
    }
    const T& operator [](int index) const{
        assert(index<_size&&index>-1);
        return at(index);
    }

    T& at(int index){             //return reference to item at position index
        assert(index<_size&&index>-1); //edge case 
        T* walker = _s;
        walker += index;
        return *walker;
    }
    const T& at(int index) const{  //return a const item at position index
        assert(index<_size&&index>-1);
        return at(index);
    }

    T& front(){                         //return item at position 0.
        return at(0);
    }
    T& back(){                         //return item at the last position
        return at(_size-1);
    }


    //Push and Pop functions:
    Vector& operator +=(const T& item){
        push_back(item);
        return *this;
    } //push_back
    void push_back(const T& item){      //append to the end
        _s = add_entry(_s, item, _size, _capacity);
    }
    T pop_back(){                       //remove last item and return it
        T popped;
        _s = remove_last_entry(_s, popped, _size, _capacity);
        return popped;
    }


    //Insert and Erase:
    void insert(int insert_here, const T& insert_this){ //insert at pos
        assert(insert_here<_size&&insert_here>-1);
        _s = insert_entry(_s, insert_this, insert_here, _size, _capacity);
    }
    void erase(int erase_this_index){        //erase item at position
        assert(erase_this_index<_size&&erase_this_index>-1);
        _s = erase_entry(_s, erase_this_index, _size, _capacity);
    }
    int index_of(const T& item){             //search for item. retur index.
        int index = search(_s, _size, item);
        return index;
    }

    //size and capacity:
    void set_size(int size){              //enlarge the vector to this size
        if (size>_capacity){
            _s = reallocate(_s, _size, size);
            _capacity = size;
            _size = size;
        }
        _size = size;

    }
    void set_capacity(int capacity){      //allocate this space
        _capacity = capacity;
        _s = reallocate(_s, _size, _capacity);
    }
    int size() const {return _size;}  //return _size
    int capacity() const {return _capacity;} //return _capacity

    bool empty() const{return (_size==0);}                    //return true if vector is empty

    //OUTPUT:
    template <class U>
    friend ostream& operator <<(ostream& outs, const Vector<U>& _a);

private:
    T* _s;
    int _size;
    int _capacity;
};

#endif