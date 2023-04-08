/*!************************

\file dllist.cpp
\author Kaushik Thirumavalavan
\par DP email: 2200927@sit.singaporetech.edu.sg
\par Course: RSE 1202 
\par Programming Lab #5
\date 4-02-2023
\brief
This program defines member functions of class dllist in order 
to access and edit the linked list

- dllist
This function constructs a linked list and initalise head and tail to zero

- ~dllist
This function deletes the linked list created 

-size
This function returns the total number of elements in the linked list 

- print
This function prints each element of linked list from front to back

- push_front
This function adds a new node with a specified value at the beginning 
of the linked list

- push_back
This function adds a new node with a specified value at the end  
of the linked list

- find
This function locates a node with the value  specified in the parameter 

- insert
This function adds a node with a value to the index, both specified in the parameter

- remove_first 
This function  deletes the first element that contains the specified value 
**************************
*/
#include <iostream>
#include <iomanip>
#include "dllist.h"




namespace hlp2 {

/*!************************

\brief
This function constructs a doubly linked list and initialise
the head and tail to null
\return
void
**************************
*/
	dllist::dllist() : head(nullptr), tail(nullptr) {
		/*
		head = new node;
		tail = new node;
		head->next = tail;
		head->prev = nullptr;
		tail->next = nullptr;
		tail->prev = head;
		*/
	}

/*!************************

\brief
This function deletes the linked list created 
\return
void
**************************
*/
	dllist::~dllist(){
		if(head!=nullptr){
			node* temp;
			for(node* head2 = head;head2 != tail;head2 = temp){
			temp = head2->next;
			delete head2;
			}
			delete tail;
		}
		
		
	}

/*!************************
  
\brief
This function returns the total count of elements in the linked list 
\return 
total number of elements in the linked list 
**************************
*/
	size_t dllist::size() const{
		
		 size_t number = 0;
   		 node* temp;
   		 for(node* head2 = head;head2;head2 = temp){
			number++;
			temp = head2->next;
		}
    return number;
		/*
		size_t number = 0;
		node* temp;
		for(node* head2 = head;head2!=tail;head2 = temp){
			number++;
			temp = head2->next;
		}
		if(head == nullptr && tail == nullptr){
			return 0;
		}
		return ++number;
		*/
	}

  /*!************************
  
  \brief
  This function prints each element of linked list from front to back
  **************************
  */
	void dllist::print() const
	{
		node const* l_pCur = head;
		while (l_pCur) {
			std::cout << l_pCur->value << "    ";
			l_pCur = l_pCur->next;
		}
		std::cout << "\n";
	}
/*!************************

\brief
This function adds a new node with a specified value at the beginning 
of the linked list
\param value
integer value of the new node to be added 
\return
void
**************************
*/  
	void dllist::push_front(int value){
		node* newNode = new node;
		newNode->value = value;
		if(head == nullptr) {
			newNode->next = nullptr;
			newNode->prev = nullptr;
        head = newNode;
		
      	}else{
		newNode->next = head;
		newNode->prev = nullptr;
		head->prev = newNode;

		head = newNode;
		}
	}
/*!************************

\brief
This function adds a new node with a specified value at the end of 
the linked list
\param value
integer value of the new node to be added 
\return
void
**************************
*/
	void dllist::push_back(int value){
		node* newNode = new node;
		newNode->value = value;
		newNode->next = nullptr;
		if(tail == nullptr){
		newNode->prev = nullptr;
		head = tail = newNode;
		tail->next = nullptr;
		}else{
			newNode->prev = tail;
			tail->next = newNode;

			tail = newNode;
			tail->next = nullptr;
		}
	}
/*!************************

\brief
This function locates a node with the value  specified in the parameter 
\param value
integer value to be located 
\return
pointer to node with the specified value
**************************
*/
	dllist::node* dllist::find(int value) const{
		
		if(head == nullptr){
			return nullptr;
		}

		for(node* start = head; start != tail; start = start->next){
			if(start->value == value){
				return start;
			} 
		}	
			if(tail->value == value){
				return tail;
			}
		
		return nullptr;
	}	
/*!************************

\brief
This function adds a node with a value to the index, both specified in 
the parameter
\param value
Integer value to of new node to be added 
\param position 
Index where new value will be added 
\return
void
**************************
*/
	void dllist::insert(int value, size_t position)
	{
		if (position == 0)
		{
			push_front(value);
			return;
		}
		node* temp = head;
		for (size_t i = 1; i < position && temp != nullptr; i++)
		{
			temp = temp->next;
		}
		if (temp == nullptr)
		{
			push_back(value);
			return;
		}
		node* newNode = new node;
		newNode->value = value;
		newNode->prev = temp;
		newNode->next = temp->next;
		temp->next = newNode;
		if (newNode->next != nullptr)
		{
			newNode->next->prev = newNode;
		}
		if (tail == temp)
		{
			tail = newNode;
		}
	}

/*!************************

\brief
This function  deletes the first element that contains the specified value 
\param value
The integer value to be located and removed
\return
void
**************************
*/
	void dllist::remove_first(int value){
		if(head == nullptr){
			return;
		}

		if(head->value == value){
			node* current = head;
			head = head->next;
			if(head != nullptr){
			head->prev = nullptr;
			}else{
				tail = nullptr;
			}
			delete current;
			return;
  		}
		for(node* start = head;start;start = start->next){
			if(start->value == value){
				if(start == tail){
					tail = start->prev;
					if(tail){tail->next = nullptr;}
					delete start;
					break;
				}else{
				start->prev->next = start->next;
				start->next->prev = start->prev;
				delete start;
				break;
				}
			}
			if(start == tail){
				break;
			}
		}
	}
	//TODO: Rest of the member functions

} // end namespace hlp2