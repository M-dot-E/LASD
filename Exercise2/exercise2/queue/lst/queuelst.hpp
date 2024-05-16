
#ifndef QUEUELST_HPP
#define QUEUELST_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueLst : virtual public Queue<Data> , virtual protected List<Data>{
  // Must extend Queue<Data>,
  //             List<Data>

private:

  // ...

protected:

  // using List<Data>::???;
  using List<Data>::size;

  // ...

public:

  // Default constructor
  QueueLst() = default;
  // QueueLst() specifier;

  /* ************************************************************************ */

  // Specific constructor
  // QueueLst(argument) specifiers; // A stack obtained from a TraversableContainer
  QueueLst(const TraversableContainer<Data>& );
  // QueueLst(argument) specifiers; // A stack obtained from a MappableContainer
  QueueLst(MappableContainer<Data>&& );

  /* ************************************************************************ */

  // Copy constructor
  QueueLst(const QueueLst<Data>&);
  // QueueVec(argument);

  // Move constructor
  QueueLst(QueueLst<Data>&&) noexcept;
  // QueueVec(argument);

  /* ************************************************************************ */

  // Destructor
  virtual ~QueueLst() = default;
  // ~QueueLst() specifier;

  /* ************************************************************************ */

  // Copy assignment
  inline QueueLst& operator=(const QueueLst&);
  // type operator=(argument);

  // Move assignment
  inline QueueLst& operator=(QueueLst&&) noexcept;
  // type operator=(argument);

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  inline bool operator==(const QueueLst&) const noexcept;
  // type operator!=(argument) specifiers;
  inline bool operator!=(const QueueLst&) const noexcept;
  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

  // type Head() specifiers; // Override Queue member (non-mutable version; must throw std::length_error when empty)
  inline const Data& Head() const override;
  // type Head() specifiers; // Override Queue member (mutable version; must throw std::length_error when empty)
  inline Data& Head() override;
  // type Dequeue() specifiers; // Override Queue member (must throw std::length_error when empty)
  inline void Dequeue() override;
  // type HeadNDequeue() specifiers; // Override Queue member (must throw std::length_error when empty)
  inline Data HeadNDequeue() override;
  // type Enqueue(argument) specifiers; // Override Queue member (copy of the value)
  inline void Enqueue(const Data&) override;
  // type Enqueue(argument) specifiers; // Override Queue member (move of the value)
  inline void Enqueue(Data&&) override;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // using List<Data>::Clear;
  using List<Data>::Clear;

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "queuelst.cpp"

#endif