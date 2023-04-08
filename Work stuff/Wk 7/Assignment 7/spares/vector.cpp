// make sure to have a file-level Doxygen documentation block!!!
/*!*****************************************************************************
\file       vector.cpp
\author     
\par        
\par        Course: HLP2
\par        Section: student - A
\par        Assignment 6
\date       
\brief
  build my own version of std::vector. Functions are:
 - reserve
	   function that will be used by both clients and other functions to add memory for new elements.
 - resize
	   resizes the container so that it contains n elements. 
 - push_back
     pushes back memory block.
 - empty
     check if container is empty.
 - size
     returns sz.
 - capacity
     returns space.
 - allocations
     returns allocs.
*******************************************************************************/
#include "vector.hpp"
#include <iostream>

namespace hlp2{
    vector::vector(size_type n){
        sz=n; 
        space = n; 
        allocs = 1; 
        data = new vector::value_type[n];
        }
    vector::vector(std::initializer_list<int> rhs) : sz{rhs.size()}, space{rhs.size()}, allocs{1}, data{new int[space]{}}     
    {        
        int i = 0;
        for(int value : rhs)
            data[i++] = value; 
    }

    vector::vector(vector const& rhs): sz{rhs.sz}, space{rhs.sz}, allocs{1}, data{new int[space]{}}
    {      
        for(size_type i{0}; i < sz; ++i)
            data[i] = rhs[i];
    }

    vector& vector::operator=(vector const& rhs){
        pointer tmp;
        tmp = new vector::value_type[rhs.space];
        for(size_type i{0}; i < rhs.sz; ++i)
            tmp[i] = rhs.data[i];

        this->sz = rhs.sz;
        this->space = rhs.sz;
        if(this->data) delete[] data;
        this->data = tmp;
        this->allocs++;
        return *this;
    }

    vector& vector::operator=(std::initializer_list<int> rhs){
        pointer tmp;
        tmp = new vector::value_type[rhs.size()];
        for(size_type i{0}; i < rhs.size(); ++i)
            tmp[i] = *(rhs.begin() + i);

        this->sz = rhs.size();
        this->space = rhs.size();
        if(this->data) delete[] data;
        this->data = tmp;
        this->allocs++;
        return *this;
    }

    vector::reference vector::operator[](size_type index){
        return this->data[index];
    }

    vector::const_reference vector::operator[](size_type index) const{
        return this->data[index];
    }
    /*!*****************************************************************************
	\brief
	  function that will be used by both clients and other functions to add memory for new elements.
	\param n
	  n is the size of memory to be added.
	\return
	  void
	*******************************************************************************/
    void vector::reserve(size_type n){
        if(this->space >= n) return;

        pointer Arr = new value_type[n];
        if(this->data)
        {
            for(size_type i = 0; i < this->sz; ++i)
                Arr[i] = this->data[i];
            delete[] this->data;
        }

        this->data = Arr;
        this->space = n;
        this->allocs++;
    }
    /*!*****************************************************************************
	\brief
	  resizes the container so that it contains n elements.
	\param n
	  n is the elements to resize container.
	\return
	  void
	*******************************************************************************/
    void vector::resize(size_type n){
        if(n == this->sz) return;
        if(n < this->space) this->sz = n;
        if(n > space) reserve(n*2);
    }
    /*!*****************************************************************************
	\brief
	  pushes back memory block.
	\param val
	  values to be pushed back.
	\return
	  void
	*******************************************************************************/
    void vector::push_back(value_type val){
        if(this->space == 0) reserve(1);
        else if(this->sz == this->space) reserve(this->space*2);        
        this->data[this->sz++] = val;
    }
    /*!*****************************************************************************
	\brief
	  check if container is empty.
	\return
	  bool
	*******************************************************************************/
    bool vector::empty() const{
        if(!this->data) return false;
        return true;
    }
    /*!*****************************************************************************
	\brief
	  returns space.
	\return
	  size_type
	*******************************************************************************/
    vector::size_type vector::size() const{
        return this->sz;
    }
    /*!*****************************************************************************
	\brief
	  returns space.
	\return
	  size_type
	*******************************************************************************/
    vector::size_type vector::capacity() const{
        return this->space;
    }
    /*!*****************************************************************************
	\brief
	  returns allocs.
	\return
	  size_type
	*******************************************************************************/
    vector::size_type vector::allocations() const{
        return this->allocs;
    }
    vector::pointer vector::begin(){
        return this->data;
    }
    vector::pointer vector::end(){
        return this->data+this->sz;
    }
    vector::const_pointer vector::begin() const{
        return (const_pointer)this->data;
    }
    vector::const_pointer vector::end() const{
        return (const_pointer)this->data+this->sz;
    }
    vector::const_pointer vector::cbegin() const{
        return (const_pointer)this->data;
    }
    vector::const_pointer vector::cend() const{
        return (const_pointer)this->data+this->sz;
    }
}