/*\file sllist.hpp
\author Tan Choon Yi
\par DP email: 2201766@sit.singaporetech.edu.sg
\par Course: C++ Programming
\par Section: student - provide your section here
\par Programming Lab 8
\date 11-03-2023
\brief
implementation of 9 operator overloading to use in a doubly linked list in addition with throw keyword
****************************************************************************
***/
#include <iostream>
#include <iomanip>
#include "dllist.h"
#include "except.h"
using namespace std;

namespace hlp2 {

	
	
	dllist::dllist():
		head(nullptr),
		tail(nullptr)
		{}

	dllist::~dllist()
	{
		node* cur = head;
		while (cur){
			node* next = cur->next;
			delete cur;
			cur = next;
		}
	}
	dllist :: dllist(dllist const& other)
	{
		// If other list is empty, return empty list
		if (!other.head)
		{
			head = tail = nullptr;
			return;
		}

		// Allocate memory for head
		head = new node{ nullptr, other.head->value, nullptr };
		node* curr = head;

		// Copy elements from other list to this list
		for (node* temp = other.head->next; temp; temp = temp->next)
		{
			curr->next = new node{ curr, temp->value, nullptr };
			curr = curr->next;
		}
		tail = curr;
	}

	dllist& dllist::operator=(dllist const& other)
	{
		// Check for self-assignment
		if (this == &other)
			return *this;

		// Deallocate memory of this list
		while (head)
		{
			node* temp = head;
			head = head->next;
			delete temp;
		}

		// If other list is empty, return empty list
		if (!other.head)
		{
			head = tail = nullptr;
			return *this;
		}

		// Allocate memory for head
		head = new node{ nullptr, other.head->value, nullptr };
		node* curr = head;

		// Copy elements from other list to this list
		for (node* temp = other.head->next; temp; temp = temp->next)
		{
			curr->next = new node{ curr, temp->value, nullptr };
			curr = curr->next;
		}
		tail = curr;

		return *this;
	}
//@brief compare 2 linked list size and value of each node 
	bool operator==(dllist const& dataA, dllist const&  dataB)
	{
		auto A = dataA.head;
		 auto B = dataB.head;
		if((dataA.size())==(dataB.size()))
		{
			while(!(A == nullptr)&&!(B== nullptr))
			{
				if((A->value)==(B->value))
				{
					A = A->next;
					B = B->next;
				}
				else
				{
					return false;
				}
			}	
			return true;
			
		} 
		else
		{
			return false;
		}
		 
		
	}

//@brief concatenate 2 linked list togather using for loop the adapt to different size lists and push_back function to make code shorter 
	dllist operator+(dllist const& dataA, dllist const& dataB)
	{
		dllist left = dataA;
		auto B = dataB.head;
		int count = dataB.size();
	
		for(int i =0;i<count;i++)
		{
			left.push_back(B->value);
			B = B->next;
		}
		return left;
		
	}
	
//@brief concatenate linked list using chaining to continuously update the the linked list used as parameter
	dllist& dllist::operator+=(dllist const& data)
	{
		auto B = data.head;
		int count = data.size();
	
		for(int i =0;i<count;i++)
		{
			
			push_back(B->value);
			B = B->next;
		}
		return *this;
	}

//@brief negate the values in each node using for loop to adapt to list of different size and manually using 0 to deduct the value in each node
	dllist const dllist:: operator-() const
	{
		dllist holder = *this;
		node* number = holder.head;
		int count = holder.size();
		for(int i =0;i<count;i++)
		{
			int neg = number->value;
			neg = 0-neg;
			number->value = neg;
			number = number->next;
		}
		return holder;
	}
//@brief pop_back the last value of the linked list, use chaining to continuously pop_back on the same referenced linked list till empty
	dllist& dllist::operator--(){						
		if(head!=tail){ //if number of element is greater than 1
			tail = tail->prev;	
			tail->next=nullptr;
		}	
		else if(this->size()==1){		 //if only one element				
			dllist::node* temp = tail;
			head = head->next;
			tail=tail->next;
			delete temp;				
		}
		else{ //if list is empty
			throw("No tail");
		}	
			
		return *this;     
	}

//@brief pop_back the last value of the linked list adapted from previously implemented pop_front() function to start from the back instead and return the updated linked list
	dllist const dllist::operator--(int){
		dllist copy=*this;
		--*this;	
		return copy;
	}
//@brief a limited for loop to continuosly update the newnode, result with a fixed end point obtaining required node location
	int& dllist::operator[](size_t x){
			node* value=head;			
		    for(size_t i=0;value && i<x;i++){
				value=value->next;
			}
			if(!value){
				
				throw SubscriptErr(x);
			}
			
			return value->value;
		}
//@brief a limited for loop to continuosly update the newnode, result with a fixed end point obtaining required node location
	int const& dllist::operator[](size_t x) const{
			
		    node* value=head;			
		    for(size_t i=0;value && i<x;i++){
				value=value->next;
			}
			if(!value){
				
				throw SubscriptErr(x);
			}
			
			return value->value;
		}
		
	bool operator!=(dllist const& lhs, dllist const& rhs){
		return !(lhs==rhs);
	}
	
std::ostream& operator<<(std::ostream& os, dllist const& out){
		dllist::node* v=out.head;
		while(v){
			os<< v->value << "    ";
			v=v->next;
		}
		return os<<"\n";		
	}
size_t dllist::size() const
{
	size_t count = 0;
	node* temp = head;
	while (temp != nullptr)
	{
		count++;
		temp = temp->next;
	}
	return count;
}


void dllist::print() const
{
	node const* l_pCur = head;
	while (l_pCur) 
	{
		std::cout << l_pCur->value << "    ";
		l_pCur = l_pCur->next;
	}
	std::cout << "\n";
}

	void dllist::push_front(int value)
	{
		node* newNode = new node();
		newNode->value = value;
		newNode->prev = nullptr;
		newNode->next = head;
		if (head)
			head->prev = newNode;
		else
			tail = newNode;
		head = newNode;
	}

		// Remove the front node
		void dllist::pop_front()
		{
			if(head) 
			{
				node* next = head->next;
				delete head;
				head = next;
				if (head)
					head->prev = nullptr;
				else
					tail = nullptr;
                    
			}
            else
            {
                throw NoNdErr();
            }
		}
		
		// Add a new value to the end
		void dllist::push_back(int value)
		{
			node* newNode = new node();
			newNode->value = value;
			newNode->next = nullptr;
			newNode->prev = tail;
			if (tail)
				tail->next = newNode;
			else
				head = newNode;
			tail = newNode;
           
		}


		// Find first occurrence 
		dllist::node* dllist::find(int value) const
		{
			node *temp = head;
			while(temp != nullptr)
			{
				if(temp->value == value)
				{
					return temp;
				}
				temp = temp->next; 
			}
			return nullptr;

		}

		void dllist::insert(int value, size_t position)
		{
			if(position ==0)
			{
				push_front(value);
				return;
			}
			node *temp = head;
			for(size_t i = 1; (i<position && temp!=nullptr);i++)
			{
				temp = temp->next;
			}
			if(temp == nullptr)
			{
				push_back(value);
				tail = temp;
				return;
			}
			node *newnode = new node();
			newnode->value = value;
			newnode->prev = temp;
			newnode->next = temp->next;
			if(newnode->next != nullptr)
			{
				newnode->next->prev = newnode;
			}
		}


		// Remove the first element in list with value
		 void dllist::remove_first(int value)
	{
		node* current = this->head;
		node* previous = nullptr;

		while (current != nullptr) {
			if (current->value == value) {
				if (previous == nullptr) { //first element
					this->head = current->next;
				} else {
					previous->next = current->next;
					if (current->next != nullptr) {
   						 current->next->prev = previous;
						}
				}

				delete current;
				break;
			}

			previous = current;
			current = current->next;
		}
	}

	//TODO: Rest of the member functions

} // end namespace hlp2