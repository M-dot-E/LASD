
#ifndef QUEUEVEC_HPP
#define QUEUEVEC_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueVec : virtual public Queue<Data> , virtual protected Vector<Data>{
  // Must extend Queue<Data>,
  //             Vector<Data>

private:

  // ...

protected:

  // using Vector<Data>::???;
  using Vector<Data>::size;
  using Vector<Data>::elements;
  unsigned long head = 0;
  unsigned long tail = 0;

  // ...

public:

  // Default constructor
  QueueVec() : Vector<Data>(2){}
  // QueueVec() specifier;

  /* ************************************************************************ */

  // Specific constructor
  // QueueVec(argument) specifiers; // A stack obtained from a TraversableContainer
  QueueVec(const TraversableContainer<Data>& );
  // QueueVec(argument) specifiers; // A stack obtained from a MappableContainer
  QueueVec(MappableContainer<Data>&& );


  /* ************************************************************************ */

  // Copy constructor
  QueueVec(const QueueVec<Data>&);
  // QueueVec(argument);

  // Move constructor
  QueueVec(QueueVec<Data>&&) noexcept;
  // QueueVec(argument);

  /* ************************************************************************ */

  // Destructor
  virtual ~QueueVec() = default;
  // ~QueueVec() specifier;

  /* ************************************************************************ */

  // Copy assignment
  QueueVec& operator=(const QueueVec&);
  // type operator=(argument);

  // Move assignment
  QueueVec& operator=(QueueVec&&) noexcept;
  // type operator=(argument);

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const QueueVec&) const noexcept;
  // type operator!=(argument) specifiers;
  inline bool operator!=(const QueueVec&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

  // type Head() specifiers; // Override Queue member (non-mutable version; must throw std::length_error when empty)
  const Data& Head() const override;
  // type Head() specifiers; // Override Queue member (mutable version; must throw std::length_error when empty)
  Data& Head() override;
  // type Dequeue() specifiers; // Override Queue member (must throw std::length_error when empty)
  void Dequeue() override;
  // type HeadNDequeue() specifiers; // Override Queue member (must throw std::length_error when empty)
  Data HeadNDequeue() override;
  // type Enqueue(argument) specifiers; // Override Queue member (copy of the value)
  void Enqueue(const Data&) override;
  // type Enqueue(argument) specifiers; // Override Queue member (move of the value)
  void Enqueue(Data&& dat) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  // type Empty() specifiers; // Override Container member
  bool Empty() const noexcept override;

  // type Size() specifiers; // Override Container member
  unsigned long Size() const noexcept override;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member
  void Clear() override;

protected:

  // Auxiliary functions, if necessary!
  void Expand();

  void Reduce();

  void Resize(unsigned long newsize, unsigned long num);

};

/* ************************************************************************** */

}

#include "queuevec.cpp"

#endif