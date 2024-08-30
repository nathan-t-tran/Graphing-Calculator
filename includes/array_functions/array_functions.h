#ifndef ARRAY_FUNCTIONS_H
#define ARRAY_FUNCTIONS_H

#include <iostream>
#include <string>
#include <fstream>
#include <ostream>

using namespace std;

const int MINIMUM_CAPACITY = 3;

template<class T>
T* allocate(int capacity = MINIMUM_CAPACITY);

template<class T>
T* reallocate(T* a, int size, int capacity);

template<class T>
void copy_array(T* dest, const T* src, int many_to_copy);

template <class T>
T* copy_array(const T *src, int size);

template<class T>
void print_array(T* a, int size, int capacity = 0, ostream& outs = cout); 

template <class T>
void print(T* a, unsigned int how_many, ostream& outs = cout);

template<class T>
T* search_entry(T* a, int size, const T& find_me);

template <class T>
int search(T* a, int size, const T& find_me); 

template <class T>
void shift_left(T* a, int& size, T* shift_here);

template <class T>
void shift_left(T* a, int& size, int shift_here);

template <class T>
void shift_right(T* a, int &size, T* shift_here);

template <class T>
void shift_right(T *a, int &size, int shift_here);

template <class T>
string array_string(const T *a, int size);

template <class T>
void array_init(T *a, int size, T value);

template <typename T>
void append(T* a, int& size, T add_me);

template<class T>
T* allocate(int capacity)
{
    T* arrpointer = new T [capacity];
    return arrpointer;
}

template<class T>
T* reallocate(T* a, int size, int capacity)
{
    T* new_array = new T [capacity];
    copy_array(new_array,a, size);
    delete[] a;
    return new_array;
}

template<class T>
void copy_array(T* dest, const T* src, int many_to_copy)
{
    for (int i = 0; i < many_to_copy; i++)
    {
        *dest = *src;
        dest++;
        src++;
    }
}

template <class T>
T* copy_array(const T* src, int size)
{
    T* arr_dest = allocate<T>(size);
    copy_array(arr_dest, src, size);

    return arr_dest;
}

//Prints (size/capacity) along with array.
template<class T>
void print_array(T* a, int size, int capacity, ostream& outs)
{
    if (size >= 10)
    {
        outs << "(" << size;
    }
    else if (size < 10)
    {
        outs << "( " << size;
    }

    if(capacity == 0)
    {
        outs << ") ";
    }
    else if(capacity >= 10)
    {
        outs << "/" << capacity << ") ";
    }
    else if(capacity < 10)
    {
        outs << "/ " <<capacity << ") ";
    }

    print(a, size);

    outs << endl;
}

//Prints out array.
/*template <class T>
void print(T* a, unsigned int how_many, ostream& outs)
{
    cout << "[ ";
    for (int i = 0; i < how_many; i++)
    {
        cout << *a << " | ";

        a++;
    }
    cout << "]";
}*/

//Finds the address of a given value in an array.
template<class T>
T* search_entry(T* a, int size, const T& find_me)
{
    T* found = NULL; //Outputs a null value if no value is found.
    for (int i = 0; i < size; i++)
    {
        if (*a == find_me)//Checks if *a is equal to find_me.
        {
            found = a; //Sets found to a.
            break;
        }
        a++; //Increments a.
    }
    return found;
}

//Finds the index of a given value in an array.
template <class T>
int search(T* a, int size, const T& find_me)
{
    int found = -1; //Outputs -1 if no value is found.
    
    for (int i = 0; i < size; i++)
    {
        if(*a == find_me) //checks if *a is equal to find_me
        {
            found = i; //Sets found to i;
            break;
        }
        a++;
    }
    return found;
}

//Function shifts array to the left.
template <class T>
void shift_left(T* a, int& size, T* shift_here)
{
    T* shift_val = search_entry(a, size, *shift_here); //Gets address of shift_here value in array.
    int spaces_taken = 0;

    for(int i = 0; i < size; i++)
    {
        if (*a == *shift_here)
        {
            break;
        }
        a++;
        spaces_taken++; //Finds how many spaces are taken.
    }

    int spaces_left = size - spaces_taken; //Gets how many times needed to loop.
    for (int i = 0; i < (spaces_left-1); i++)
    {
        T* temp_val = shift_val;
        shift_val++;
        *temp_val = *shift_val;
    }
    size--; //Decreases size by 1.
}

//Takes index of shift_here and calls on shift_left function.
template <class T>
void shift_left(T* a, int& size, int shift_here)
{
    T* shift_address = (a + shift_here);
    shift_left(a, size, shift_address);
}

template <class T>
void shift_right(T* a, int &size, T* shift_here)
{
    int spaces_taken = 0;

    for(int i = 0; i < size; i++)
    {
        if (*a == *shift_here)
        {
            break;
        }
        a++;
        spaces_taken++; //Finds how many spaces are taken.
    }

    int spaces_left = size - spaces_taken; //Gets how many times needed to loop.

    T* final_element = a + (size - 1);
    T* temp_val;
    size++; //Increases size by 1.

    for (int i = 0; i < size; i++)
    {
        temp_val = final_element;
        temp_val++;
        *temp_val = *final_element;
        final_element--;

        if(final_element == shift_here - 1)
        {
            break;
        }
    }
}

template <class T>
void shift_right(T *a, int &size, int shift_here)
{
    T* shift_address = (a + shift_here);
    shift_right(a, size, shift_address);
}


template <class T>
string array_string(const T* a, int size)
{
    string dest = "[  ";
    for (int i = 0; i < size; i++)
    {
        dest += to_string(*a) + "  ";
        a++;
    }
    dest += "  ]";
    return dest;
    
}

template <class T>
void array_init(T *a, int size, T value)
{
    for (int i = 0; i < size; i++)
    {
        *a = value;
        a++;
    }
}

template <typename T>
void append(T* a, int& size, T new_value)
{
    a += size;
    *a = new_value;
    size++;
}

#endif //ARRAY_FUNCTIONS_H