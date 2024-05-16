
#ifndef STACKVEC_HPP
#define STACKVEC_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackVec : virtual public Stack<Data> , virtual protected Vector<Data>{
  // Must extend Stack<Data>,
  //             Vector<Data>

private:

  // ...

protected:
  unsigned long index = 0;
  // using Vector<Data>::???;
  using Vector<Data>::size;
  using Vector<Data>::elements;

  // ...

public:

  // Default constructor
  // StackVec() specifier;
  StackVec() : Vector<Data>(1) {};

  /* ************************************************************************ */

  // Specific constructor
  // StackVec(argument) specifiers; // A stack obtained from a TraversableContainer
  StackVec(const TraversableContainer<Data> & con) : Vector<Data>(con){ index = con.Size();}
  // StackVec(argument) specifiers; // A stack obtained from a MappableContainer
  StackVec(MappableContainer<Data> && con) : Vector<Data>(std::move(con)){ index = std::move(con.Size());}

  /* ************************************************************************ */

  // Copy constructor
  StackVec(const StackVec&);
  // StackVec(argument);

  // Move constructor
  StackVec(StackVec&&) noexcept ;
  // StackVec(argument);

  /* ************************************************************************ */

  // Destructor
  virtual ~StackVec() = default;
  // ~StackVec() specifier;

  /* ************************************************************************ */

  // Copy assignment
  StackVec& operator=(const StackVec&);
  // type operator=(argument);

  // Move assignment
   StackVec& operator=(StackVec&&) noexcept;
  // type operator=(argument);

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const StackVec&) const noexcept;
  // type operator!=(argument) specifiers;
  inline bool operator!=(const StackVec&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)

  // type Top() specifiers; // Override Stack member (non-mutable version; must throw std::length_error when empty)
  const Data& Top() const override;
  // type Top() specifiers; // Override Stack member (non-mutable version; must throw std::length_error when empty)
  Data& Top() override;
  // type Pop() specifiers; // Override Stack member (must throw std::length_error when empty)
  void Pop() override;
  // type TopNPop() specifiers; // Override Stack member (must throw std::length_error when empty)
  Data TopNPop() override;
  // type Push(argument) specifiers; // Override Stack member (copy of the value)
  void Push(const Data&) override;
  // type Push(argument) specifiers; // Override Stack member (move of the value)
  void Push(Data&&) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  // type Empty() specifiers; // Override Container member
  inline bool Empty() const noexcept override;

  // type Size() specifiers; // Override Container member
  inline unsigned long Size() const noexcept override;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member
  void Clear() override;

protected:

  // Auxiliary functions, if necessary!
  void Expand();
  void Reduce();

};

/* ************************************************************************** */

}

#include "stackvec.cpp"

#endif