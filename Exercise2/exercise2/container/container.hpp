
#ifndef CONTAINER_HPP
#define CONTAINER_HPP

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

class Container {

private:

  // ...

protected:

  // ...
  unsigned long size= 0;
  
  /* ************************************************************************ */

  // Default constructor
  Container() = default;
  // Container() specifiers;

public:

  // Destructor
  // ~Container() specifiers
  virtual ~Container() = default;

  /* ************************************************************************ */

  // Copy assignment
  Container& operator=(const Container&) = delete;
  // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  Container& operator=(Container&&) noexcept = delete;
  // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator==(const Container&) const noexcept = delete;
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator!=(const Container&) const noexcept = delete;
  /* ************************************************************************ */
 
  // Specific member functions

  // type Empty() specifiers; // (concrete function should not throw exceptions)
  virtual bool Empty() const noexcept{
    return size == 0;
  }

  // type Size() specifiers; // (concrete function should not throw exceptions)
  virtual  unsigned long Size() const noexcept{
    return size;
  }

};

/* ************************************************************************** */

class ClearableContainer : virtual public Container{
  // Must extend Container

private:

  // ...

protected:

  // ...

public:

  // Destructor
  ~ClearableContainer() = default;
  // ~ClearableContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  ClearableContainer& operator=(const ClearableContainer&) = delete;
  // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  ClearableContainer& operator=(ClearableContainer&&) noexcept = delete;
  // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator==(const ClearableContainer&) const noexcept= delete;
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator!=(const ClearableContainer&) const noexcept= delete;

  /* ************************************************************************ */

  // Specific member functions

  // type Clear() specifiers;
  inline virtual void Clear() {
    size = 0;
  }

};

/* ************************************************************************** */

class ResizableContainer :  virtual public ClearableContainer{
  // Must extend ClearableContainer

private:

  // ...

protected:

  // ...

public:

  // Destructor
  ~ResizableContainer()  = default;
  // ~ResizableContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  ResizableContainer& operator=(const ResizableContainer&) = delete;
  // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  ResizableContainer& operator=( ResizableContainer&&) noexcept = delete;
  // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const ResizableContainer&) const noexcept = delete;
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator!=(const ResizableContainer&) const noexcept = delete;
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member functions

  // type Resize(argument) specifiers;
  inline virtual void Resize(unsigned long n){
    size = n;
  }

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member
  inline virtual void Clear() override{
    Resize(0);
  }
};

/* ************************************************************************** */

}

#endif