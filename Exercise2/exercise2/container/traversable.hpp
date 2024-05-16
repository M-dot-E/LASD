
#ifndef TRAVERSABLE_HPP
#define TRAVERSABLE_HPP

/* ************************************************************************** */

#include <functional>

/* ************************************************************************** */

#include "testable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class TraversableContainer : virtual public TestableContainer<Data> {
  // Must extend TestableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~TraversableContainer() specifiers
  virtual ~TraversableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  TraversableContainer& operator=(const TraversableContainer&) = delete;
  // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  TraversableContainer& operator=(TraversableContainer&&) noexcept = delete;
  // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might be possible.
  bool operator==(const TraversableContainer &) const noexcept = delete;
  // type operator!=(argument) specifiers; // Comparison of abstract types might be possible.
  bool operator!=(const TraversableContainer &) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  // using TraverseFun = std::function<void(const Data &)>;
  using TraverseFun = std::function<void(const Data&)>;

  // type Traverse(arguments) specifiers;
  virtual void Traverse(TraverseFun) const = 0;

  // template <typename Accumulator>
  template <typename Accumulator>
  // using FoldFun = std::function<Accumulator(const Data &, const Accumulator &)>;
  using FoldFun = std::function<Accumulator(const Data&, const Accumulator &)>;

  // template <typename Accumulator>
  template <typename Accumulator>
  // type Fold(arguments) specifiers;
  Accumulator Fold(FoldFun<Accumulator>, const Accumulator) const;

  /* ************************************************************************ */

  // Specific member function (inherited from TestableContainer)

  // type Exists(argument) specifiers; // Override TestableContainer member
  inline bool Exists(const Data&) const noexcept override;

};

/* ************************************************************************** */

template <typename Data>
class PreOrderTraversableContainer : virtual public TraversableContainer<Data>{
  // Must extend TraversableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~PreOrderTraversableContainer() specifiers
  virtual ~PreOrderTraversableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  PreOrderTraversableContainer& operator=(const PreOrderTraversableContainer&) = delete;
  // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  PreOrderTraversableContainer& operator=(PreOrderTraversableContainer&&) noexcept = delete;
  // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might be possible.
  bool operator==(const PreOrderTraversableContainer&) const noexcept = delete;
  // type operator!=(argument) specifiers; // Comparison of abstract types might be possible.
  bool operator!=(const PreOrderTraversableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  // using typename TraversableContainer<Data>::TraverseFun;
  using typename TraversableContainer<Data>::TraverseFun;

  // type PreOrderTraverse(arguments) specifiers;
  inline virtual void PreOrderTraverse(TraverseFun) const = 0;

  // template <typename Accumulator>
  template <typename Accumulator>
  // using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;
  using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

  // template <typename Accumulator>
  template <typename Accumulator>
  // type PreOrderFold(arguments) specifiers;
  Accumulator PreOrderFold(FoldFun<Accumulator> , Accumulator) const;

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  // type Traverse(arguments) specifiers; // Override TraversableContainer member
  inline void Traverse(TraverseFun) const override;

};

/* ************************************************************************** */

template <typename Data>
class PostOrderTraversableContainer : virtual public TraversableContainer<Data>{
  // Must extend TraversableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~PostOrderTraversableContainer() specifiers
  virtual ~PostOrderTraversableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  PostOrderTraversableContainer& operator=(const PostOrderTraversableContainer&) = delete;
  // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  PostOrderTraversableContainer& operator=(PostOrderTraversableContainer&&) noexcept = delete;
  // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might be possible.
  bool operator==(const PostOrderTraversableContainer&) const noexcept = delete;
  // type operator!=(argument) specifiers; // Comparison of abstract types might be possible.
  bool operator!=(const PostOrderTraversableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  // using typename TraversableContainer<Data>::TraverseFun;
  using typename TraversableContainer<Data>::TraverseFun;

  // type PostOrderTraverse(arguments) specifiers;
  virtual void PostOrderTraverse(TraverseFun) const = 0;

  // template <typename Accumulator>
  // using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;
  template<typename Accumulator>
  using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

  // template <typename Accumulator>
  // type PostOrderFold(arguments) specifiers;
  template<typename Accumulator>
  Accumulator PostOrderFold(FoldFun<Accumulator> , Accumulator) const;

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  // type Traverse(arguments) specifiers; // Override TraversableContainer member
  inline void Traverse(TraverseFun) const override;

};

/* ************************************************************************** */

template <typename Data>
class InOrderTraversableContainer : virtual public TraversableContainer<Data>{
  // Must extend TraversableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~InOrderTraversableContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  InOrderTraversableContainer& operator=(const InOrderTraversableContainer&) = delete;
  // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  InOrderTraversableContainer& operator=(InOrderTraversableContainer&&) noexcept = delete;
  // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might be possible.
  bool operator==(const InOrderTraversableContainer&) const noexcept = delete;
  // type operator!=(argument) specifiers; // Comparison of abstract types might be possible.
  bool operator!=(const InOrderTraversableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  // using typename TraversableContainer<Data>::TraverseFun;
   using typename TraversableContainer<Data>::TraverseFun;

  // type InOrderTraverse(arguments) specifiers;
  virtual void InOrderTraverse(TraverseFun) const = 0;

  // template <typename Accumulator>
  template<typename Accumulator>
  // using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;
  using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

  // template <typename Accumulator>
  // type InOrderFold(arguments) specifiers;
  template<typename Accumulator>
  Accumulator InOrderFold(FoldFun<Accumulator> , Accumulator) const;
  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  // type Traverse(arguments) specifiers; // Override TraversableContainer member
  inline void Traverse(TraverseFun) const override;

};

/* ************************************************************************** */

template <typename Data>
class BreadthTraversableContainer : virtual public TraversableContainer<Data>{
  // Must extend TraversableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~BreadthTraversableContainer() = default;
  // ~BreadthTraversableContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  BreadthTraversableContainer& operator=(const BreadthTraversableContainer&) = delete;
  // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  BreadthTraversableContainer& operator=(BreadthTraversableContainer&&) noexcept = delete;
  // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might be possible.
  bool operator==(const BreadthTraversableContainer&) const noexcept = delete;
  // type operator!=(argument) specifiers; // Comparison of abstract types might be possible.
  bool operator!=(const BreadthTraversableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  // using typename TraversableContainer<Data>::TraverseFun;
  using typename TraversableContainer<Data>::TraverseFun;
  // type BreadthTraverse(arguments) specifiers;
  inline virtual void BreadthTraverse(TraverseFun) const = 0;

  // template <typename Accumulator>
  // using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;
  template<typename Accumulator>
  using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

  // template <typename Accumulator>
  // type BreadthFold(arguments) specifiers;
  template<typename Accumulator>
  Accumulator BreadthFold(FoldFun<Accumulator> , Accumulator) const;

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  // type Traverse(arguments) specifiers; // Override TraversableContainer member
  inline void Traverse(TraverseFun) const override;

};

/* ************************************************************************** */

}

#include "traversable.cpp"

#endif