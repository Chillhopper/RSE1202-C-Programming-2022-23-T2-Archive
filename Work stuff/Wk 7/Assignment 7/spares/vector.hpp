// make sure to have a file-level Doxygen documentation block AND
// function-level documentation block for each function that your
// client will be using!!!
/*!*****************************************************************************
\file       vector.hpp
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
////////////////////////////////////////////////////////////////////////////////
#ifndef VECTOR_HPP
#define VECTOR_HPP
////////////////////////////////////////////////////////////////////////////////
#include <cstddef>          // need this for size_t
#include <initializer_list> // need this for std::initializer_list<int>
 
namespace hlp2 {
	
class vector {
public:
  // @todo: using declarations required!!!
  // types to declare: size_type, value_type,
  // reference, const_reference, pointer, const_pointer
  using size_type = size_t;
  using value_type = int;
  using pointer = value_type*;
  using const_pointer = value_type const*;
  using reference = value_type&;
  using const_reference = value_type const&;

public:
  public:
  vector(){sz=0; space = 0; allocs = 0; data = nullptr;} // default ctor

// non-default ctor
  explicit vector(size_type n){
    sz=n; 
        space = n; 
        allocs = 1; 
        data = new vector::value_type[n];
  } 
// non-default ctor
  vector(std::initializer_list<int> rhs){
    int i = 0;
        for(int value : rhs)
            data[i++] = value; 
  } 
  // copy ctor
vector(vector const& rhs): sz{rhs.sz}, space{rhs.sz}, allocs{1}, data{new int[space]{}}{      
        for(size_type i{0}; i < sz; ++i)
            data[i] = rhs[i];
    }

  ~vector(){if(this->data) delete[] this->data;}

  vector& operator=(vector const& rhs){
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

  vector& operator=(std::initializer_list<int> rhs){
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

  reference operator[](size_type index){
    return this->data[index];
  }

  const_reference operator[](size_type index) const{
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
  void reserve(size_type n){
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
  void resize(size_type n){
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
  void push_back(value_type val){
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
  bool empty() const{
      if(!this->data) return false;
        return true;
  } // is container empty?
  /*!*****************************************************************************
	\brief
	  returns space.
	\return
	  size_type
	*******************************************************************************/
  size_type size() const{
    return this->sz;
  } // what is sz?
  /*!*****************************************************************************
	\brief
	  returns space.
	\return
	  size_type
	*******************************************************************************/
  size_type capacity() const{
    return this->space;
  } // what is space?
  /*!*****************************************************************************
	\brief
	  returns allocs.
	\return
	  size_type
	*******************************************************************************/
  size_type allocations() const{
    return this->allocs;
  } // how many allocations or "growths"?
  // iterators ...
  pointer begin(){
    return this->data;
  } // pointer to first element
  pointer end(){
    return this->data+this->sz;
  } // pointer to one past last element
  const_pointer begin() const{
    return (const_pointer)this->data;
  }
  const_pointer end() const{
    return this->data+this->sz;
  }
  const_pointer cbegin() const{
    return (const_pointer)this->data;
  }
  const_pointer cend() const{
    return (const_pointer)this->data+this->sz;
  }

  // @todo: declare iterators [described in spec]
  void swap(vector& rhs);

private:
  size_type sz;     // the number of elements in the array
  size_type space;  // the allocated size (in terms of elements) of the array
  size_type allocs; // number of times space has been updated
  pointer   data;   // the dynamically allocated array
};

}
#endif // VECTOR_HPP
