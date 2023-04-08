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
	
template <typename T>class vector {
public:
  // @todo: using declarations required!!!
  // types to declare: size_type, value_type,
  // reference, const_reference, pointer, const_pointer
  using size_type = size_t;
  using value_type = T;
  using pointer = value_type*;
  using const_pointer = value_type const*;
  using reference = value_type&;
  using const_reference = value_type const&;

public:
  public:
  vector(){sz=0; space = 0; allocs = 0; data = nullptr;} // default ctor
  explicit vector(size_type n); // non-default ctor

  vector(std::initializer_list<T> rhs); // non-default ctor
  vector(vector const& rhs); // copy ctor
  ~vector(){if(this->data) delete[] this->data;}
  vector& operator=(vector const&);
  vector& operator=(std::initializer_list<T> rhs);
  reference operator[](size_type index);
  const_reference operator[](size_type index) const;
  /*!*****************************************************************************
	\brief
	  function that will be used by both clients and other functions to add memory for new elements.
	\param n
	  n is the size of memory to be added.
	\return
	  void
	*******************************************************************************/
  void reserve(size_type n);
  /*!*****************************************************************************
	\brief
	  resizes the container so that it contains n elements.
	\param n
	  n is the elements to resize container.
	\return
	  void
	*******************************************************************************/
  void resize(size_type n);
  /*!*****************************************************************************
	\brief
	  pushes back memory block.
	\param val
	  values to be pushed back.
	\return
	  void
	*******************************************************************************/
  void push_back(value_type val);
  /*!*****************************************************************************
	\brief
	  check if container is empty.
	\return
	  bool
	*******************************************************************************/
  bool empty() const; // is container empty?
  /*!*****************************************************************************
	\brief
	  returns space.
	\return
	  size_type
	*******************************************************************************/
  size_type size() const; // what is sz?
  /*!*****************************************************************************
	\brief
	  returns space.
	\return
	  size_type
	*******************************************************************************/
  size_type capacity() const; // what is space?
  /*!*****************************************************************************
	\brief
	  returns allocs.
	\return
	  size_type
	*******************************************************************************/
  size_type allocations() const; // how many allocations or "growths"?
  // iterators ...
  pointer begin(); // pointer to first element
  pointer end(); // pointer to one past last element
  const_pointer begin() const;
  const_pointer end() const;
  const_pointer cbegin() const;
  const_pointer cend() const;

  // @todo: declare iterators [described in spec]
void swap(vector& rhs);
private:
  size_type sz;     // the number of elements in the array
  size_type space;  // the allocated size (in terms of elements) of the array
  size_type allocs; // number of times space has been updated
  pointer   data;   // the dynamically allocated array
};

} // namespace hlp2

#endif // VECTOR_HPP
