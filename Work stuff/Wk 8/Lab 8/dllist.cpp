/*!*************************************************************************
****
\file dllist.cpp
\author Kaushik Thirumavalavan
\par DP email: 2200927\@sit.singaporetech.edu.sg
\par Course: RSE1202
\par Section: 2201986
\par Assignment 6
\date 28-02-2023
\brief
 This file uses interface-implementation separation to complete a doubly linked list ADT that has a number of overloaded operators

 The function include:
- dllist
This function creates a linked list and initalise head and tail to zero.
- ~dllist
This function deletes the created linked list.
- size
This function return the count of elements in linked list.
- print
This function print each element of linked list from front to back.
- dllist(dllist const& other)
This function is a copy constructor that creates a new dllist object with the same value as another dllist object
- operator=
This function overloads the "=" operator for a doubly linked list
- bool operator==
This function overloads the "==" operator for a doubly linked list
- operator+
This function overloads the "+" operator for a doubly linked list
- operator+=
This function overloads the "+=" operator for a doubly linked list
- operator-
This function overloads the "-" operator for a doubly linked list
- operator--
This function overloads the "--" operator for a doubly linked list
- operator--(int)
This function overloads the "--" operator for a doubly linked list
- operator[]
This function overloads the "[]" operator for a doubly linked list
- operator[](size_t index)
This function overloads the "[]" operator for a doubly linked list
- operator<<
This function overloads the "<<" operator for a doubly linked list
- push_front
This function add element to the front of linked list.
- pop_front
This function removes the first node of a doubly linked list, updates the "head" pointer if necessary, and ensures that the "prev"
- push_back
This function add element to the back of linked list.
- find
This function find first element in linked list with value specified by 2nd parameter.
- insert
This function insert element with value in 2nd parameter in linked list at index specified by position.
- remove_first
This function remove first element in linked list with value specified in 2nd parameter.
- operator!=
This function returns false if data of the dllists is different in terms of value, sequence, or number of items
****************************************************************************
***/

#include <iostream>
#include <iomanip>
#include "dllist.h"
#include "except.h"
namespace hlp2 {

/*!*************************************************************************
****
\brief
This function creates a linked list and initalise head and tail to zero.
\return void
****************************************************************************
***/
	dllist::dllist() :
		head(nullptr),

		tail(nullptr)
	{}

/*!*************************************************************************
****
\brief
This function deletes the created linked list.
\return void
****************************************************************************
***/
	dllist::~dllist()
	{

		node* current = head;

		while (current != nullptr) {

			node* next = current->next;

			delete current;

			current = next;
		}

		head = nullptr;
		tail = nullptr;

	}

/*!*************************************************************************
****
\brief
This function return the count of elements in linked list.
\return sz
The total count of elements in the linked list.
****************************************************************************
***/
	size_t dllist::size() const
	{

		size_t count = 0;

		node* current = head;

		while (current != nullptr) {

			count++;

			current = current->next;
		}

		return count;
	}

/*!*************************************************************************
****
\brief
This function print each element of linked list from front to back.
\return void
****************************************************************************
***/
	void dllist::print() const
	{
		node const* l_pCur = head;
		while (l_pCur) {
			std::cout << l_pCur->value << "    ";
			l_pCur = l_pCur->next;
		}
		std::cout << "\n";
	}

/*!*************************************************************************
****
\brief
This function is a copy constructor that creates a new dllist object with the same value as another dllist object
\param other
First data of the linked list
\return void
****************************************************************************
***/
	dllist::dllist(dllist const& other) :
		head(nullptr),
		tail(nullptr)
	{

		if (other.head == nullptr) {
			return;
		}


		node const* current = other.head;

		while (current != nullptr) {

			push_back(current->value);

			current = current->next;
		}
	}

/*!*************************************************************************
****
\brief
This function overloads the "=" operator for a doubly linked list
\param other
First data of the linked list
\return *this
Returns a reference to the modified calling object to allow chaining of the "=" operator.
****************************************************************************
***/
	dllist& dllist::operator=(dllist const& other)
	{

		if (this != &other) {

			node* curr = head;

			while (curr != nullptr) {

				node* temp = curr;

				curr = curr->next;

				delete temp;
			}

			head = tail = nullptr;


			node* other_curr = other.head;

			while (other_curr != nullptr) {

				push_back(other_curr->value);

				other_curr = other_curr->next;
			}
		}

		return *this;
	}

/*!*************************************************************************
****
\brief
This function overloads the "==" operator for a doubly linked list
\param lhs
First data of the linked list
\param rhs
Second data of the linked list
\return bool
true / false
****************************************************************************
***/
	bool operator==(dllist const& lhs, dllist const& rhs) {

		if (&lhs == &rhs) {
			return true;
		}


		if (lhs.size() != rhs.size()) {
			return false;
		}


		dllist::node const* currentLhs = lhs.head;

		dllist::node const* currentRhs = rhs.head;

		while (currentLhs != nullptr) {

			if (currentLhs->value != currentRhs->value) {
				return false;
			}

			currentLhs = currentLhs->next;
			currentRhs = currentRhs->next;
		}

		return true;
	}

/*!*************************************************************************
****
\brief
This function overloads the "+" operator for a doubly linked list
\param lhs
a constant reference to an object
\param rhs
a constant reference to another object
\return result
Returns all the node objects.
****************************************************************************
***/
	dllist operator+(dllist const& lhs, dllist const& rhs) {

		dllist result = lhs;

		dllist::node const* current = rhs.head;

		while (current != nullptr) {

			result.push_back(current->value);

			current = current->next;
		}

		return result;
	}

/*!*************************************************************************
****
\brief
This function overloads the "+=" operator for a doubly linked list
\param rhs
a constant reference to another object
\return *this
Returns a reference to the modified calling object to allow chaining of the "+=" operator.
****************************************************************************
***/
	dllist& dllist::operator+=(dllist const& rhs)
	{

		if (&rhs == this) {

			dllist copy = rhs;

			return *this += copy;
		}

		if (rhs.head == nullptr) {

			return *this;
		}

		if (head == nullptr) {

			head = new node{ nullptr, rhs.head->value, nullptr };
			tail = head;

			node* rhs_curr = rhs.head->next;

			while (rhs_curr != nullptr) {

				node* new_node = new node{ tail, rhs_curr->value, nullptr };

				tail->next = new_node;

				tail = new_node;

				rhs_curr = rhs_curr->next;
			}

			return *this;
		}

		node* curr = tail;

		node* rhs_curr = rhs.head;

		while (rhs_curr != nullptr) {

			node* new_node = new node{ curr, rhs_curr->value, nullptr };

			curr->next = new_node;

			curr = new_node;

			rhs_curr = rhs_curr->next;
		}

		tail = curr;

		return *this;
	}

/*!*************************************************************************
****
\brief
This function overloads the "-" operator for a doubly linked list
\param -
\return result
A constant reference to the modified list
****************************************************************************
***/
	dllist const dllist::operator-() const {

		dllist result = *this;

		node* current = result.head;

		while (current != nullptr) {

			current->value = -current->value;

			current = current->next;
		}

		return result;

	}


/*!*************************************************************************
****
\brief
This function overloads the "--" operator for a doubly linked list
\param -
\return *this
A reference to the modified list
****************************************************************************
***/
	dllist& dllist::operator--() {

		if(size() == 0){
			throw("No tail");
		}
		if (head == nullptr) {
			return *this;
			throw("No tail");
		}

		if (head == tail) {

			delete head;

			head = nullptr;
			tail = nullptr;

			return *this;
		}

		node* current = head;

		while (current->next != tail) {

			current = current->next;
		}

		delete tail;

		tail = current;

		tail->next = nullptr;

		return *this;
	}

/*!*************************************************************************
****
\brief
This function overloads the "--" operator for a doubly linked list
\param int
An integer parameter that is not used in the implementation of the function.
\return result
The copy of the original list that was created at the beginning of the function.
****************************************************************************
***/
	dllist const dllist::operator--(int) {

		if(size() == 0){
			throw("No tail");
		}
		dllist result = *this;
		//empty list
		if (head == nullptr) {
			return result;
		}
		//if 1 element
		if (head == tail) {

			delete head;

			head = nullptr;
			tail = nullptr;

			return result;
		}

		node* current = head;

		while (current->next != tail) {

			current = current->next;
		}

		delete tail;

		tail = current;

		tail->next = nullptr;

		return result;
	}

/*!*************************************************************************
****
\brief
This function overloads the "[]" operator for a doubly linked list.
\param index
The index of the element to be accessed
\return current
a constant reference to the value stored in the node pointed to by the current pointer
****************************************************************************
***/
	int& dllist::operator[](size_t index)
	{

		if (index >= size()) {

			//throw std::out_of_range("Index out of bounds");
			throw(SubscriptErr((int)index));
		}


		node* current = head;

		for (size_t i = 0; i < index; ++i) {

			current = current->next;
		}


		return current->value;
	}
/*!*************************************************************************
****
\brief
This function overloads the "[]" operator for a doubly linked list.
\param index
The index of the element to be accessed
\return current
a constant reference to the value stored in the node pointed to by the current pointer
****************************************************************************
***/
	int const& dllist::operator[](size_t index) const
	{

		if (index >= size()) {

			//throw std::out_of_range("Index out of bounds");
			throw(SubscriptErr((int)index));
		}


		node* current = head;

		for (size_t i = 0; i < index; ++i) {

			current = current->next;
		}


		return current->value;
	}

/*!*************************************************************************
****
\brief
This function overloads the "<<" operator for a doubly linked list.
\param os
Output stream
\param list
Constant doubly linked list object
\return os
****************************************************************************
***/
	std::ostream& operator<<(std::ostream& os, dllist const& list) {

		list.print();

		return os;
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

	void hlp2::dllist::push_front(int value) {

		node* newNode = new node{ nullptr, value, nullptr };

		if (!head) {
			head = tail = newNode;
		}
		else {

			head->prev = newNode;

			newNode->next = head;

			head = newNode;
		}
	}

/*!*************************************************************************
****
\brief
This function removes the first node of a doubly linked list, updates the "head" pointer if necessary, and ensures that the "prev" pointer of the new head node
\param -
\return void
****************************************************************************
***/
	void dllist::pop_front() {

		if (head == nullptr) {
			throw(NoNdErr());
			return;
		}

		else if (head == tail) {

			delete head;

			head = nullptr;
			tail = nullptr;
		}
		else {

			node* new_head = head->next;

			delete head;

			head = new_head;

			head->prev = nullptr;
		}
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
	void hlp2::dllist::push_back(int value) {

		node* new_node = new node{ tail, value, nullptr };

		if (tail != nullptr) {

			tail->next = new_node;
		}
		else {

			head = new_node;
		}

		tail = new_node;
	}

/*!*************************************************************************
****
\brief
This function find first element in linked list with value specified by 2nd parameter.
\param value
Integer value to be located.
\return current
Pointer to the node with a specific value.
****************************************************************************
***/
	hlp2::dllist::node* hlp2::dllist::find(int value) const {

		node* current = head;

		while (current != nullptr) {

			if (current->value == value) {
				return current;
			}

			current = current->next;
		}

		return nullptr;
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
	void dllist::insert(int value, size_t position) {

		if (head == nullptr) {
			push_front(value);

			return;
		}

		else if (position == 0) {
			push_front(value);

			return;
		}

		node* current = head;

		for (size_t i = 0; i < position - 1; i++) {

			if (current->next == nullptr) {
				push_back(value);
				// return
				return;
			}

			current = current->next;
		}

		node* newNode = new node{ current, value, current->next };

		current->next = newNode;

		if (newNode->next != nullptr) {

			newNode->next->prev = newNode;
		}
		else {

			tail = newNode;
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
	void dllist::remove_first(int value) {

		if (head == nullptr) {
			return;
		}


		if (head->value == value) {

			pop_front();

			return;
		}

		node* current = head;

		while (current->next != nullptr) {

			if (current->next->value == value) {

				node* temp = current->next;

				current->next = current->next->next;

				if (current->next != nullptr) {

					current->next->prev = current;
				}
				else {

					tail = current;
				}

				delete temp;

				return;
			}

			current = current->next;
		}
	}

/*!*************************************************************************
****
\brief
This function returns false if data of the dllists is different in terms of value, sequence, or number of items
\param lhs
First data of the linked list
\param rhs
Second data of the linked list
\return bool, false
****************************************************************************
***/
	bool operator!=(dllist const& lhs, dllist const& rhs)
	{

		return !(lhs == rhs);
	}
}