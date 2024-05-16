
#ifndef STACK_HPP
#define STACK_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Stack : virtual public ClearableContainer{
  // Must extend ClearableContainer

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~Stack() specifiers
  virtual ~Stack() = default;

  /* ************************************************************************ */

  // Copy assignment
  Stack& operator=(const Stack&) = delete;
  // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  Stack& operator=(Stack&&) noexcept = delete;
  // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator==(const Stack&) const noexcept = delete;
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator!=(const Stack&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  // type Top() specifiers; // (non-mutable version; concrete function must throw std::length_error when empty)
  virtual const Data& Top() const = 0;
  // type Top() specifiers; // (mutable version; concrete function must throw std::length_error when empty)
  virtual Data& Top() = 0;
  // type Pop() specifiers; // (concrete function must throw std::length_error when empty)
  virtual void Pop() = 0;
  // type TopNPop() specifiers; // (concrete function must throw std::length_error when empty)
  virtual Data TopNPop() = 0;
  // type Push(argument) specifiers; // Copy of the value
  virtual void Push(const Data&) = 0;
  // type Push(argument) specifiers; // Move of the value
  virtual void Push(Data&&) = 0;

};

/* ************************************************************************** */

}

#endif