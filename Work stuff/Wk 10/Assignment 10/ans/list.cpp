/*!*************************************************************************
****
\file list.cpp
\author Kavyanjali
\par DP email: 2203390@sit.singaporetech.edu.sg
\par Course: RSE 1202
\par Section: 
\par Programming Assignment #10
\date 2-04-2023
\brief
This program provides a basic implementation of singly and doubly linked lists 
with the necessary operations for managing data in the lists.

- sllist
This function creates a singly linked list and initalise head and tail to zero.

- sllist::sllist(sllist const& other) 
This function is a copy constructor that creates a new sllist object with the same value as another sllist object

- ~sllist
This function deletes the created singly linked list.

- sllist& sllist::operator=(sllist const& other)
This function is copy assignment operator for a singly linked list class, which
assigns an object of a class to another object of the same class


- dllist
This function creates a doubly linked list and initalise head and tail to zero.

- ~dllist
This function deletes the created doubly linked list.

- dllist(dllist const& other) 
This function is a copy constructor for a doubly linked list class that derives 
from a singly linked list class

- size
This function return the count of elements in linked list.

- push_front
This function add element to the front of linked list.

- pop_front
This function removes the first node of a doubly linked list, updates the "head" pointer if necessary, and ensures that the "prev"

- push_back
This function add element to the back of linked list.

- print
This function print each element of linked list from front to back.

- find
This function find first element in linked list with value specified by 2nd parameter.

- insert
This function insert element with value in 2nd parameter in linked list at index specified by position.

- remove_first
This function remove first element in linked list with value specified in 2nd parameter.
****************************************************************************
***/

#include <cstddef>
#include <iostream>
#include <iomanip>
#include <array>
#include "list.h"

 #define REQUIRED_ART  
 #ifdef REQUIRED_ART 
                                                                                                                                                                                                                                                                                                    
namespace hlp2 {

sllist::slnode::slnode(int value, slnode* next) : value(value), next(next) {}



sllist::sllist() : head(nullptr) {}


	/*!*************************************************************************
	****
	\brief
	This function creates a singly linked list and initalise head and tail to zero.
	\return void
	****************************************************************************
	***/
void sllist::clear() {
    slnode* current = head;
    while (current != nullptr) {
        slnode* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}

	/*!*************************************************************************
	****
	\brief
	This function is a copy constructor that creates a new sllist object with the same value as another sllist object
	\param other
	The other singly linked list object to copy
	\return 
	****************************************************************************
	***/
sllist::sllist(sllist const& other) : head(nullptr) 
{
    
    slnode* curr = other.head;
    slnode* prev = nullptr;
    while (curr != nullptr) 
    {
        slnode* newNode = new slnode(curr->value);
        if (prev == nullptr) 
        {
            head = newNode; 
        } 
        else 
        {            
            prev->next = newNode; 
        }
        prev = newNode;
        curr = curr->next;
    }
}


	/*!*************************************************************************
	****
	\brief
	This function deletes the created singly linked list.
	\return void
	****************************************************************************
	***/
sllist::~sllist() 
{
    // Delete nodes
    slnode* curr = head;
    while (curr != nullptr) 
    {
        slnode* temp = curr;
        curr = curr->next;
        delete temp;
    }
    head = nullptr;
}


	/*!*************************************************************************
	****
	\brief
	This function is copy assignment operator for a singly linked list class, which 
    assigns an object of a class to another object of the same class
	\param 
    constant reference to another singly linked list object to copy.
	****************************************************************************
	***/
sllist& sllist::operator=(sllist const& other) 
{
    if (this != &other) 
    {
        
        slnode* curr = head;
        while (curr != nullptr) 
        {
            slnode* temp = curr;
            curr = curr->next;
            delete temp;
        }
        head = nullptr;
        
        
        curr = other.head;
        while (curr != nullptr) 
        {
            push_back(curr->value);
            curr = curr->next;
        }
    }
    return *this;
}


	/*!*************************************************************************
	****
	\brief
	This function return the count of elements in linked list.
	\return count
	The total count of elements in the linked list.
	****************************************************************************
	***/
size_t sllist::size() const 
{
    size_t count = 0;
    slnode* curr = head;
    while (curr != nullptr) 
    {
            ++count;
        curr = curr->next;
    }
    return count;
}


	/*!*************************************************************************
	****
	\brief
	This function add element to the front of linked list.
	\param value
	Integer value of the new node to be added.
	\return void
	****************************************************************************
	***/
void sllist::push_front(int value) 
{
    head = new slnode(value, head);
}




	/*!*************************************************************************
	****
	\brief
	This function removes the first node of a doubly linked list,
	updates the "head" pointer if necessary, and ensures that the "prev" pointer of the new head node
	\return void
	****************************************************************************
	***/
void sllist::pop_front()
{
  
    if (head == nullptr) 
    {
        return; 
    }
    slnode* temp = head; 
    head = head->next; 
    delete temp; 
}


	/*!*************************************************************************
	****
	\brief
	This function add element to the back of linked list.
	\param value
	Integer value of the new node to be added.
	\return void
	****************************************************************************
	***/
void sllist::push_back(int value)
{
    slnode* new_node = new slnode(value); 
    
    
    if (head == nullptr) 
    {
        head = new_node;
    } 
   
    else 
    {
        slnode* temp = head;
        while (temp->next != nullptr) 
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}


	/*!*************************************************************************
	****
	\brief
	This function print each element of linked list from front to back.
	\return void
	****************************************************************************
	***/
void sllist::print() const
{
    slnode const* curr = head; 
    static bool was_bool = false;
    static int endall = 0;
    
    while (curr) {
        std::cout << curr->value << "    ";
        curr = curr->next;
    }

    if(dynamic_cast<const dllist*>(this) != nullptr){
        if (this->size() == 1 && was_bool == true && endall == 2){
        std::cout << "\n";
        was_bool = false;

        }
        
    }

    if(dynamic_cast<const dllist*>(this) != nullptr){
        if (this->size() == 1){
        //std::cout << "\n";
        was_bool = true;
        endall++;

        }

    }

    std::cout << "\n"; 
}


	/*!*************************************************************************
	****
	\brief
	This function find first element in linked list with value specified by 2nd parameter.
	\param value
	Integer value to be located.
	\return cur
	Pointer to the node with a specific value.
	****************************************************************************
	***/
sllist::slnode* sllist::find(int value) const // Find the first occurrence of an integer value in the linked list
{
    slnode* temp = head; 
    while (temp != nullptr && temp->value != value) 
    { 
        temp = temp->next;
    }
    return temp; 
}


	/*!*************************************************************************
	****
	\brief
	This function insert element with value in 2nd parameter in linked list at index specified by position.
	\param value
	Integer value of the new node to be added.
	\param position
	Position of the element.
	\return void
	****************************************************************************
	***/
void sllist::insert(int value, size_t position)
{
    slnode* new_node = new slnode(value); 
    
    if (position == 0) 
    {
        new_node->next = head;
        head = new_node;
    } 
    else 
    {
        slnode* temp = head;
        
        for (size_t i = 0; i < position - 1 && temp != nullptr; i++) 
        {
            temp = temp->next;
        }
        
        if (temp == nullptr) 
        {
            push_back(value);
        } 
        else 
        {
           
            new_node->next = temp->next;
            temp->next = new_node;
        }
    }
}



	/*!*************************************************************************
	****
	\brief
	This function remove first element in linked list with value specified in 2nd parameter.
	\param value
	Integer value of the new node to be located and remove it.
	\return void
	****************************************************************************
	***/
void sllist::remove_first(int value)
{
    slnode* temp = head; 
    slnode* prev = nullptr; 

  
    while (temp != nullptr && temp->value != value) 
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp != nullptr) 
    {
        if (prev != nullptr) 
        { 
            prev->next = temp->next; 
        } 
        else 
        { 
            head = temp->next; 
        }
        delete temp; 
    }
}



dllist::dlnode::dlnode(dlnode* prev, int value, dlnode* next) : slnode(value, next), prev(prev) {}



dllist::dllist() : sllist(), tail(nullptr) {}

	/*!*************************************************************************
	****
	\brief
	This function is a copy constructor for a doubly linked list class that derives 
    from a singly linked list class
	\param other
	First data of the linked list
	\return 
	****************************************************************************
	***/
dllist::dllist(dllist const& other) : sllist(other), tail(nullptr) 
{
    for (dlnode* node = static_cast<dlnode*>(other.head); node != nullptr; node = static_cast<dlnode*>(node->next)) 
    {
        push_back(node->value); 
    }
}


	/*!*************************************************************************
	****
	\brief
	This function deletes the created doubly linked list.
	\return void
	****************************************************************************
	***/
dllist::~dllist()
{
    while (head != nullptr) 
    {
        dlnode* node = static_cast<dlnode*>(head->next); 
        delete head; 
        head = node; 
    }
    tail = nullptr; 
}


	/*!*************************************************************************
	****
	\brief
	This function assigns an object of a class to another object of the same class
	\param rhs
	const reference to another dllist object
	\return *this
	returns a reference to a dllist object
	****************************************************************************
	***/
dllist& dllist::operator=(dllist const& other)
{
    if (this != &other) {
        dllist temp(other); 

        
        std::swap(head, temp.head);
        std::swap(tail, temp.tail);
    }
    return *this; 
}



	/*!*************************************************************************
	****
	\brief
	This function add element to the front of linked list.
	\param value
	Integer value of the new node to be added.
	\return void
	****************************************************************************
	***/
void dllist::push_front(int value)
{
    dlnode* new_node = new dlnode(nullptr, value, static_cast<dlnode*>(head)); 
    if (head != nullptr)
    {
        static_cast<dlnode*>(head)->prev = new_node; 
    }
    else
    {
        tail = new_node; 
    }
    head = new_node;  
}



	/*!*************************************************************************
	****
	\brief
	This function removes the first node of a doubly linked list,
	updates the "head" pointer if necessary, and ensures that the "prev" pointer of the new head node
	\return void
	****************************************************************************
	***/
void dllist::pop_front()
{
if (head == nullptr)
{
return;
}

dlnode* old_head = static_cast<dlnode*>(head);

if (old_head->next != nullptr)
{
    static_cast<dlnode*>(old_head->next)->prev = nullptr; 
}
else
{
    tail = nullptr; 
}
head = old_head->next; 

delete old_head; 

}



	/*!*************************************************************************
	****
	\brief
	This function add element to the back of linked list.
	\param value
	Integer value of the new node to be added.
	\return void
	****************************************************************************
	***/
void dllist::push_back(int value)
{
    dlnode* new_node = new dlnode(tail, value, nullptr); 
    
    if (tail == nullptr)
    {
        head = tail = new_node; 
    }
    else
    {
       
        tail->next = new_node;
        tail = new_node;
    }
}


	/*!*************************************************************************
	****
	\brief
	This function insert element with value in 2nd parameter in linked list at index specified by position.
	\param value
	Integer value of the new node to be added.
	\param position
	Position of the element.
	\return void
	****************************************************************************
	***/
void dllist::insert(int value, size_t index) 
{
    if (index == 0) 
    {
        push_front(value); 
    } 
    else 
    {
        // Traverse the list to find the node at the index
        dlnode* current = static_cast<dlnode*>(head);
        size_t current_index = 0;
        while (current != nullptr && current_index < index - 1) 
        {
            current = static_cast<dlnode*>(current->next);
            current_index++;
        }
        if (current != nullptr) 
        {
            current->next = new dlnode(current, value, static_cast<dlnode*>(current->next)); 
                if (static_cast<dlnode*>(current->next->next) != nullptr) 
                {
                    static_cast<dlnode*>(current->next->next)->prev = static_cast<dlnode*>(current->next); 
                }
                else 
                {
                    tail = static_cast<dlnode*>(current->next); 
                }
        } 
        else 
        {
            push_back(value); 
        }
    }
}

	/*!*************************************************************************
	****
	\brief
	This function remove first element in linked list with value specified in 2nd parameter.
	\param value
	Integer value of the new node to be located and remove it.
	\return void
	****************************************************************************
	***/
void dllist::remove_first(int value) 
{
    if (head != nullptr) 
    {
        if (head->value == value)  
        {
            pop_front();
        } 
        else 
        {
            
            dlnode* current = static_cast<dlnode*>(head);
            while (current->next != nullptr && current->next->value != value) {
                current = static_cast<dlnode*>(current->next);
            }
            if (current->next != nullptr) 
            {
                dlnode* temp = static_cast<dlnode*>(current->next); 
                current->next = current->next->next; 
                if (static_cast<dlnode*>(current->next) != nullptr) 
                {
                    static_cast<dlnode*>(current->next)->prev = current;
                } 
                else 
                {
                    tail = current; 
                }
                delete temp; 
            }
        }
    }
}

} 

#endif

