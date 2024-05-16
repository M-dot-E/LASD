
#ifndef STACKLST_HPP
#define STACKLST_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackLst : virtual public Stack<Data>, virtual protected List<Data>{
  // Must extend Stack<Data>,
  //             List<Data>

private:

  // ...

protected:

  // using List<Data>::???;
  using List<Data>::size;

  // ...

public:

  // Default constructor
  inline StackLst() = default;
  // StackLst() specifier;

  /* ************************************************************************ */

  // Specific constructor
  // StackLst(argument) specifiers; // A stack obtained from a TraversableContainer
  StackLst(const TraversableContainer<Data> & con ) : List<Data>(con){};
  // StackLst(argument) specifiers; // A stack obtained from a MappableContainer
  StackLst(MappableContainer<Data> && con ) : List<Data>(std::move(con)){};

  /* ************************************************************************ */

  // Copy constructor
  inline StackLst<Data>(const StackLst<Data> & stk) : List<Data>(stk){};
  // StackLst(argument);

  // Move constructor
  inline StackLst<Data>(StackLst<Data> && stk) : List<Data>(std::move(stk)){};
  // StackLst(argument);

  /* ************************************************************************ */

  // Destructor
  virtual ~StackLst() = default;
  // ~StackLst() specifier;

  /* ************************************************************************ */

  // Copy assignment
  inline StackLst & operator=(const StackLst<Data> &);
  // type operator=(argument);

  // Move assignment
  inline StackLst & operator=(StackLst<Data> &&) noexcept;
  // type operator=(argument);

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  inline bool operator==(const StackLst &) const noexcept;
  // type operator!=(argument) specifiers;
  inline bool operator!=(const StackLst &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)

  // type Top() specifiers; // Override Stack member (non-mutable version; must throw std::length_error when empty)
  inline const Data& Top() const override;
  // type Top() specifiers; // Override Stack member (non-mutable version; must throw std::length_error when empty)
  inline Data& Top() override;
  // type Pop() specifiers; // Override Stack member (must throw std::length_error when empty)
  inline void Pop() override;
  // type TopNPop() specifiers; // Override Stack member (must throw std::length_error when empty)
  inline Data TopNPop() override;
  // type Push(argument) specifiers; // Override Stack member (copy of the value)
  inline void Push(const Data&) override;
  // type Push(argument) specifiers; // Override Stack member (move of the value)
  inline void Push(Data &&) override;
  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // using List<Data>::Clear;
  using List<Data>::Clear;

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "stacklst.cpp"

#endif