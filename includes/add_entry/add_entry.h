#ifndef ADD_ENTRY_H
#define ADD_ENTRY_H

#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include "../../includes/array_functions/array_functions.h"

using namespace std;



template<class T>
T* add_entry(T* list, const T& new_entry, int& size, int& capacity = 3);

template<class T>
T* remove_entry(T* list, const T& delete_me, int& size, int& capacity);

template <class T>
T *remove_last_entry(T *list, T &popped, int &size, int &capacity);

template <class T>
T *insert_entry(T *list, const T &insert_this, int insert_here, int &size, int &capacity);

template <class T>
T *erase_entry(T *list, int index, int &size, int &capacity);

template<class T>
T* add_entry(T* list, const T& new_entry, int& size, int& capacity) //Adds entry given element value.
{
    const bool debug = false; //For debugging purposes.
    T* array = list; //Sets new pointer = to list.
    if (size == capacity) //Checks if size is equal to capacity.
    {
        if (debug)
        {
            cout << "DEBUG: Capacity BEFORE: " << capacity << endl;
        }
        capacity = capacity * 2; //Doubles the capacity.

        if (debug)
        {
            cout << "DEBUG: Capacity AFTER: " << capacity << endl;
        }
        array = reallocate (list, size, capacity);
    }

    if (debug)
        {
            cout << "DEBUG: Size: " << size << ", Capacity: " << capacity << endl;
        }
        
    append(array, size, new_entry); //Adds new element and increases size by 1.

    return array;
}

template<class T>
T* remove_entry(T* list, const T& delete_me, int& size, int& capacity) //Removes entry given the element.
{
    const bool debug = false; //For debugging purposes.

    T* array = list; //Sets new array pointer = list.

    int delete_index = search (array, size, delete_me); //Finds the index of delete_me 

    if (delete_index == -1) //If delete_me is not in array.
    {
        return array; //Returns array unaltered.
    }

    if (debug)
    {
        cout << "DEBUG: Size: " << size << ", Capacity: " << capacity << endl;
    }

    shift_left (array, size, delete_index); //Removes delete_me and decrements size.

    if ((size * 4) <= capacity) //Checks if size is less than 1/4 of capacity.
    {
        if (debug)
        {
            cout << "DEBUG: Capacity BEFORE: " << capacity << endl;
        }

        capacity = capacity/2 ; //Sets capacity of half of itself.

        if (debug)
        {
            cout << "DEBUG: Capacity AFTER: " << capacity << endl;
        }

        array = reallocate (list, size, capacity); //Reallocates with new capacity.
    }

    return array;
}

template <class T>
T *remove_last_entry(T *list, T &popped, int &size, int &capacity) //Removes the last entry of an array.
{
    const bool debug = false; //For debugging purposes.
    T* array = list; //Sets new array pointer = to list.
    T* last_element = array + (size - 1); //Finds the last element in the array.

    if (debug)
    {
        cout << "DEBUG: Last element: " << *last_element << endl;
    }

    popped = *last_element;
    array = remove_entry (array, *last_element, size, capacity); //Removes the last entry from array.

    return array;
}

template <class T>
T *insert_entry(T *list, const T &insert_this, int insert_here, int &size, int &capacity) //Inserts entry given new element and location in array.
{
    const bool debug = false;

    T* array = list; //Sets array pointer = to list.

    if (debug)
    {
        cout << "DEBUG: insert_this: " << insert_this << ", insert_here: " << insert_here << endl;
        cout << "DEBUG: Size: " << size << ", Capacity: " << capacity << endl;
    }

    if (size == capacity) //Checks if size is equal to capacity.
    {
        if (debug)
        {
            cout << "DEBUG: Capacity BEFORE: " << capacity << endl;
        }
        capacity = capacity * 2; //Doubles the capacity.

        if (debug)
        {
            cout << "DEBUG: Capacity AFTER: " << capacity << endl;
        }

        array = reallocate (list, size, capacity); //Reallocates a new array pointer with new capacity.
    }

    if (debug)
    {
        cout << "DEBUG: BEFORE SHIFT: insert_this: " << insert_this << ", insert_here: " << insert_here << endl;
    }

    shift_right (array, size, insert_here); //Shifts the array one more to the right.

    if (debug)
    {
        cout << "DEBUG: AFTER SHIFT: insert_this: " << insert_this << ", insert_here: " << insert_here << endl;
    }


    T* new_element = array + insert_here; //Finds the location of where to insert.
    
    if (debug)
    {
        cout << "DEBUG: New element before alteration: " << *new_element << endl;
        cout << "DEBUG: New element location before alteration: " << search(array, size, insert_this) << endl;
    }

    *new_element = insert_this; //Sets location to insert_this.

    if (debug)
    {
        cout << "DEBUG: New element after alteration: " << *new_element << endl;
        cout << "DEBUG: New element location after alteration: " << search(array, size, insert_this) << endl;
    }

    return array;

}

template <class T>
T* erase_entry(T *list, int index, int &size, int &capacity) //Erases entry given the element's index.
{
    const bool debug = false; //For debugging purposes.
    T* array = list; //Uses array pointer to hold list.

    if (index < 0 || index > size) //Checks if index given is in the array.
    {
        return array; //Leaves array alone if index is not inside array.
    }

    T* new_element = array + index; //Gets element at given index.

    if (debug)
    {
        cout << "DEBUG: Index: " << index << ", New Element: " << *new_element << endl;
        print_array(array, size, capacity);
    }

    array = remove_entry(array, *new_element, size, capacity); //Removes entry at given index.

    return array;

}

#endif