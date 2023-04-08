#ifndef DLLIST_H
#define DLLIST_H

#include <iostream>
namespace hlp2 {
	template <typename T>
	class dllist
	{
	public:
		template <typename U>
		struct node
		{
			node* prev;
			U value;  // data portion
			node* next;
		};
        
		dllist();
        
        // Copy ctor
        dllist(dllist<T> const&);
        
		~dllist();
        
        // Copy assignment operator
        dllist<T>& operator=(dllist<T> const&);

		// Return the count of elements 
		size_t size() const;

		// Add a new value to the beginning 
		void push_front(T value);

        // Remove the front node
		void pop_front();
        
		// Add a new value to the end
    	void push_back(T value);

		// Print the contents 
    	void print() const;

		// Find first occurrence 
    	node<T>* find(T value) const;

	
		void insert(T value, size_t position);

		// Remove the first element in list with value
    	void remove_first(T value);

	private:
		node<T>* head;
		node<T>* tail;
	};
	
    template<typename T>
	dllist<T>::dllist() :
		head(nullptr),
		tail(nullptr) {}

	template<typename T>
	dllist<T>::~dllist()
	{
		node<T>* cur = head;
		while (cur){
			node<T>* next = cur->next;
			delete cur;
			cur = next;
		}
	}

    template<typename T>
	dllist<T>& dllist<T>::operator=(dllist<T> const& rhs)
	{
		// Check for self-assignment
		if (this == &rhs)
			return *this;

		// Deallocate memory of this list
		while (head)
		{
			node<T>* temp = head;
			head = head->next;
			delete temp;
		}

		// If other list is empty, return empty list
		if (!rhs.head)
		{
			head = tail = nullptr;
			return *this;
		}

		// Allocate memory for head
		head = new node<T>{ nullptr, rhs.head->value, nullptr };
		node<T>* curr = head;

		// Copy elements from other list to this list
		for (node<T>* temp = rhs.head->next; temp; temp = temp->next)
		{
			curr->next = new node<T>{ curr, temp->value, nullptr };
			curr = curr->next;
		}
		tail = curr;

		return *this;
	}

	template <typename T>
	dllist<T>::dllist(dllist<T> const& other): head(nullptr), tail(nullptr)
	{
		// If other list is empty, return empty list
		if (!other.head)
		{
			head = tail = nullptr;
			return;
		}

		// Allocate memory for head
		head = new node<T>{ nullptr, other.head->value, nullptr };
		node<T>* curr = head;

		// Copy elements from other list to this list
		for (node<T>* temp = other.head->next; temp; temp = temp->next)
		{
			curr->next = new node<T>{ curr, temp->value, nullptr };
			curr = curr->next;
		}
		tail = curr;
	}

	template <typename T>
	size_t dllist<T>::size() const
	{
		size_t count = 0;
		node<T>* cur = head;
		while (cur) {
			++count;
			cur = cur->next;
		}
		return count;
	}

	template <typename T>
	void dllist<T>::print() const
	{
		node<T> const* l_pCur = head;
		while (l_pCur) {
			std::cout << l_pCur->value << "    ";
			l_pCur = l_pCur->next;
		}
		std::cout << "\n";
	}

	template <typename T>
	void dllist<T>::push_front(T value)
	{	
		node<T>* newNode = new node<T>();
		newNode->value = value;
		newNode->prev = nullptr;
		newNode->next = head;
		if (head)
			head->prev = newNode;
		else
			tail = newNode;
		head = newNode;
	}

	template <typename T>
	void dllist<T>::pop_front()
	{
		if (head) {
			node<T>* next = head->next;
			delete head;
			head = next;
			if (head)
				head->prev = nullptr;
			else
				tail = nullptr;
		}
	}

	template <typename T>
	void dllist<T>::push_back(T value)
	{
		node<T>* newNode = new node<T>();
		newNode->value = value;
		newNode->next = nullptr;
		newNode->prev = tail;
		if (tail)
			tail->next = newNode;
		else
			head = newNode;
		tail = newNode;
	}

	template <typename T>
	dllist<T>::node<T>* dllist<T>::find(T value) const
	{
		node<T>* cur = head;
		while (cur && cur->value != value)
			cur = cur->next;
		return cur;
	}

	template <typename T>
	void dllist<T>::insert(T value, size_t position)
	{
		if (position >= size())
			push_back(value);
		else {
			node<T>* cur = head;
			for (size_t i = 0; i < position; ++i)
				cur = cur->next;
			node<T>* newNode = new node<T>();
			newNode->value = value;
			newNode->prev = cur->prev;
			newNode->next = cur;
			cur->prev = newNode;
			if (newNode->prev)
				newNode->prev->next = newNode;
			else
				head = newNode;
		}
	}

	template <typename T>
	void dllist<T>::remove_first(T value)
	{
		if (head == nullptr) return;
			if (head->value == value) {
				node<T>* temp = head;
				head = head->next;
				delete temp;
				return;
  		  	}
		node<T>* current = head;
		while (current->next != nullptr && current->next->value != value) {
			current = current->next;
		}
		if (current->next != nullptr) {
			node<T>* temp = current->next;
			current->next = temp->next;
			delete temp;
		}
	}

	
} 

#endif