#ifndef LINKED_LIST_FUNCTIONS_H
#define LINKED_LIST_FUNCTIONS_H

#include <iostream>
#include <iomanip>
#include "../../includes/node/node.h"
#include <assert.h>

using namespace std;

//Linked List General Functions:
template <typename ITEM_TYPE>
void _print_list(node<ITEM_TYPE>* head);

//recursive fun! :)
template <typename ITEM_TYPE>
void _print_list_backwards(node<ITEM_TYPE> *head);

//return ptr to key or NULL
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _search_list(node<ITEM_TYPE>* head,
                            ITEM_TYPE key);


template <typename ITEM_TYPE>
node<ITEM_TYPE>* _insert_head(node<ITEM_TYPE> *&head,
                            ITEM_TYPE insert_this);

//insert after ptr
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _insert_after(node<ITEM_TYPE>*& head,
                            node<ITEM_TYPE> *after_this,
                            ITEM_TYPE insert_this);

//insert before ptr
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _insert_before(node<ITEM_TYPE>*& head,
                            node<ITEM_TYPE>* before_this,
                            ITEM_TYPE insert_this);

//ptr to previous node
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _previous_node(node<ITEM_TYPE>* head,
                            node<ITEM_TYPE>* prev_to_this);

//delete, return item
template <typename ITEM_TYPE>
ITEM_TYPE _delete_node(node<ITEM_TYPE>*&head,
                    node<ITEM_TYPE>* delete_this);

//duplicate the list...
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _copy_list(node<ITEM_TYPE>* head);

//duplicate list and return the last node of the copy
template <typename T>
node<T> *_copy_list(node<T>* &dest, node<T> *src);


//delete all the nodes
template <typename ITEM_TYPE>
void _clear_list(node<ITEM_TYPE>*& head);

//_item at this position
template <typename ITEM_TYPE>
ITEM_TYPE& _at(node<ITEM_TYPE>* head, int pos);

//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
//      Sorted List Routines. order: 0: ascending, order: other: descending
//                              Assume a Sorted List
//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _insert_sorted(node<ITEM_TYPE>* &head,       //insert
                            ITEM_TYPE item,
                            bool ascending=true);

//insert or add if a dup
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _insert_sorted_and_add(node<ITEM_TYPE>* &head,
                                    ITEM_TYPE item,
                                    bool ascending=true);
//node after which this item goes order: 0 ascending
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _where_this_goes(node<ITEM_TYPE>* head,
                            ITEM_TYPE item,
                            bool ascending=true);
//Last Node in the list
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _last_node(node<ITEM_TYPE>* head);            //never use this function.

//----------------------------FUNCTION DEFINITIONS--------------------------------------------

//Linked List General Functions:
template <typename ITEM_TYPE>
void _print_list(node<ITEM_TYPE>* head) //TESTED!
{
    node<ITEM_TYPE>* walker(head); //Gets walker node that starts at head node.


    while (walker) //Checks for end node
    {
        cout << "[" << *walker->_item << "]-> "; //Prints each item
        walker = walker ->_next; //Moves onto next item on list.
    }
    cout << "|||" << endl;
}
 
//recursive fun! :)
template <typename ITEM_TYPE>
void _print_list_backwards(node<ITEM_TYPE> *head) //TESTED!
{
    node<ITEM_TYPE>* for_walker = head; //Creates a walker that goes forward.
    node<ITEM_TYPE>* back_walker = new node<ITEM_TYPE>(); //Creates empty walker for backwards.

    while (for_walker) //Checks for last node
    {
        if (for_walker->_next == nullptr) //When the last node is found.
        {
            back_walker = for_walker; //Sets the back_walker to last node.
        }
        for_walker = for_walker->_next; //Moves onto next node.
    }

    cout << "[ ";
    do
    {
        cout << back_walker->_item << " | "; //Prints node.
        back_walker = _previous_node(head, back_walker); //Finds the node behind current node.
    } while (back_walker); //Checks for the beginning node.
    cout << " ]" << endl;
}

//return ptr to key or NULL
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _search_list(node<ITEM_TYPE>* head, ITEM_TYPE key) 
{
    //assert (head);
    if (!head) return nullptr;

    node<ITEM_TYPE>* walker = head; //Gets walker node that starts at head node;

    while (walker != nullptr) //Checks for last item node.
    {
        if (walker->_item == key) //Checks if walker's item matches key
        {
            return walker; //If so, returns walker.
        }

        walker = walker->_next; //Moves onto next node.
    }

    return nullptr; //returns null when key not found.
}


template <typename ITEM_TYPE>
node<ITEM_TYPE>* _insert_head(node<ITEM_TYPE> *&head, ITEM_TYPE insert_this) //TESTED!!
{
    node<ITEM_TYPE>* temp = new node<ITEM_TYPE>(insert_this,head); //Gets new dynamic node.
    head = temp; //Points head->_next to temp;
    return head; 
}

//insert after ptr
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _insert_after(node<ITEM_TYPE>*& head, node<ITEM_TYPE> *after_this, ITEM_TYPE insert_this) //TESTED!!
{
    if (head == nullptr)
    {
        head = _insert_head(head, insert_this);
        return head;
    }

    node<ITEM_TYPE>* inserted_node = after_this->_next; //Creates node;
    after_this->_next = new node<ITEM_TYPE>(insert_this, inserted_node); //Sets new next.
    return after_this->_next;
}

//insert before ptr
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _insert_before(node<ITEM_TYPE>*& head, node<ITEM_TYPE>* before_this, ITEM_TYPE insert_this)
{
    if (before_this == head || head == nullptr)
    {
        head = _insert_head(head, insert_this);
        return head;
    }

    node<ITEM_TYPE>* prev_node = _previous_node (head, before_this); //Gets previous node;
    return _insert_after(head, prev_node, insert_this);
}

//ptr to previous node
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _previous_node(node<ITEM_TYPE>* head, node<ITEM_TYPE>* prev_to_this)
{
    node<ITEM_TYPE> *walker = head; //Gets walker to points to head.

    while (walker->_next) //Checks for if walker->next is true;
    {
        if (walker->_next == prev_to_this) //Checks if there is a node that has next of prev_to_this.
        {
            return walker; //Returns location of the previous node.
        }
        walker = walker->_next; //Moves onto next node.
    }
    return nullptr; //Returns null if previous node is not found.
}

//delete, return item
template <typename ITEM_TYPE>
ITEM_TYPE _delete_node(node<ITEM_TYPE>*&head, node<ITEM_TYPE>* delete_this) //TEST!!
{
    assert (head != nullptr);

    ITEM_TYPE return_item = delete_this->_item; //Takes item held by node

    if (delete_this != head) //If delete_this is not head.
    {
        node<ITEM_TYPE>* previous_node = _previous_node (head, delete_this); //Gets previous node
        node<ITEM_TYPE>* next_node = delete_this->_next; //Gets the next node from delete_this
        previous_node->_next = next_node; //Sets next node.
    }
    else if (delete_this == head) //If the delete_this is head.
    {
        head = delete_this->_next; //Makes new head.
    }
    delete delete_this; //Deletes node.
    return return_item;
}

//duplicate the list...
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _copy_list(node<ITEM_TYPE>* head) //TEST!!
{
    if (head == nullptr)
    {
        return head;
    }

    node<ITEM_TYPE>* walker = head; //Gets walker.
    node<ITEM_TYPE>* new_list = new node<ITEM_TYPE>(); //Gets new node for list.
    node<ITEM_TYPE>* new_head = new_list; //Creates a headptr
    node<ITEM_TYPE>* temp = new_list; //Creates a temp

    new_head->_item = walker->_item;
    walker = walker->_next;

    while (walker != nullptr)
    {
        new_list = new node<ITEM_TYPE>(); 
        temp->_next = new_list;
        temp = temp->_next;
        new_list->_item = walker->_item;
        walker = walker->_next;   
    }

    return new_head;
}

//duplicate list and return the last node of the copy
template <typename T>
node<T> *_copy_list(node<T>* &dest, node<T> *src) 
{
    dest = _copy_list(src);
    node<T>* walker = dest;
    node<T>* last_node = new node<T>();

    while (walker)
    {
        if (walker->_next == nullptr)
        {
            last_node = walker;
        }
        walker = walker->_next;
    }

    return last_node;
}


//delete all the nodes
template <typename ITEM_TYPE>
void _clear_list(node<ITEM_TYPE>*& head)
{
    const bool debug = false;

    while(head)
    {
        ITEM_TYPE deleted_val = _delete_node (head, head);

        if (debug)
        {
            _print_list(head);
            cout << "DEBUG: " << deleted_val << endl;
            
        }
    }
    
}

//_item at this position
template <typename ITEM_TYPE>
ITEM_TYPE& _at(node<ITEM_TYPE>* head, int pos) //Need to solve for when pos doesn't exist.
{
    node<ITEM_TYPE>* walker = head;
    int count = 0;
    while (walker)
    {
        if (count == pos)
        {
            return walker->_item;
        }
        walker = walker->_next;
        count++;
    }
}

//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
//      Sorted List Routines. order: 0: ascending, order: other: descending
//                              Assume a Sorted List
//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _insert_sorted(node<ITEM_TYPE>* &head, ITEM_TYPE item, bool ascending)   //insert
{
    node<ITEM_TYPE>* follower = head;
    node<ITEM_TYPE>* leader = follower->_next;

    while(ascending == true)
    {
        if (leader->_item > item) //If lead walker is greater than item.
        {
            _insert_after (head, follower, item);
            return head; //returns the node before.
        }

        follower = follower->_next;
    }

    while(ascending == false)
    {
        if (leader->_item < item) //If lead walker is less than item
        {
            _insert_after (head, follower, item);
            return head; //returns the node behind.
        }

        follower = follower->_next;
    }
}

//insert or add if a dup
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _insert_sorted_and_add(node<ITEM_TYPE>* &head, ITEM_TYPE item, bool ascending)
{

}

//node after which this item goes order: 0 ascending
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _where_this_goes(node<ITEM_TYPE>* head, ITEM_TYPE item, bool ascending)
{
    node<ITEM_TYPE>* follower = head;
    node<ITEM_TYPE>* leader = follower->_next;

    while(ascending == true)
    {
        if (leader->_item > item) //If lead walker is greater than item.
        {
            return leader; //returns the node before.
        }

        follower = follower->_next;
    }

    while(ascending == false)
    {
        if (leader->_item < item) //If lead walker is less than item
        {
            return leader; //returns the node behind.
        }

        follower = follower->_next;
    }
}

//Last Node in the list
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _last_node(node<ITEM_TYPE>* head)            //never use this function.
{
    while (head)
    {
        if (head->_next == nullptr)
        {
            return head;
        }
        head = head->_next;
    }
}

#endif