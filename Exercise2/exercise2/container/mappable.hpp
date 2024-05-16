
#ifndef MAPPABLE_HPP
#define MAPPABLE_HPP

/* ************************************************************************** */

#include <functional>

/* ************************************************************************** */

#include "traversable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class MappableContainer : virtual public TraversableContainer<Data>{
  // Must extend TraversableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~MappableContainer() = default;
  // ~MappableContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  MappableContainer& operator=(const MappableContainer&) = delete;
  // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  MappableContainer& operator=(MappableContainer&&) noexcept = delete;
  // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const MappableContainer&) const noexcept = delete;
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator!=(const MappableContainer&) const noexcept = delete;
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member function
  
  // using MapFun = std::function<void(Data &)>;
  using MapFun = std::function<void(Data &)>;

  // type Map(argument) specifiers;
  virtual void Map(MapFun) = 0;
  

};

/* ************************************************************************** */

template <typename Data>
class PreOrderMappableContainer : virtual public MappableContainer<Data> , virtual public PreOrderTraversableContainer<Data>{
  // Must extend MappableContainer<Data>,
  //             PreOrderTraversableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~PreOrderMappableContainer() specifiers
  virtual ~PreOrderMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  PreOrderMappableContainer& operator=(const PreOrderMappableContainer&) = delete;
  // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  PreOrderMappableContainer& operator=(PreOrderMappableContainer&&) noexcept = delete;
  // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator==(const PreOrderMappableContainer<Data> &) const noexcept = delete;
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator!=(const PreOrderMappableContainer<Data> &) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  // using typename MappableContainer<Data>::MapFun;
  using typename MappableContainer<Data>::MapFun;

  // type PreOrderMap(argument) specifiers;
  virtual void PreOrderMap(MapFun) = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  // type Map(argument) specifiers; // Override MappableContainer member
  void Map(MapFun) override;

};

/* ************************************************************************** */

template <typename Data>
class PostOrderMappableContainer : virtual public MappableContainer<Data> , virtual public PostOrderTraversableContainer<Data>{
  // Must extend MappableContainer<Data>,
  //             PostOrderTraversableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~PostOrderMappableContainer() specifiers
  virtual ~PostOrderMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  PostOrderMappableContainer& operator=(const PostOrderMappableContainer&) = delete;
  // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  PostOrderMappableContainer& operator=(PostOrderMappableContainer&&) noexcept = delete;
  // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator==(const PostOrderMappableContainer<Data> &) const noexcept = delete;
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator!=(const PostOrderMappableContainer<Data> &) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  // using typename MappableContainer<Data>::MapFun;
  using typename MappableContainer<Data>::MapFun;

  // type PostOrderMap(argument) specifiers;
  virtual void PostOrderMap(MapFun) = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)
  void Map(MapFun) override;
  // type Map(argument) specifiers; // Override MappableContainer member

};

/* ************************************************************************** */

template <typename Data>
class InOrderMappableContainer : virtual public MappableContainer<Data> , virtual public InOrderTraversableContainer<Data>{
  // Must extend MappableContainer<Data>,
  //             InOrderTraversableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~InOrderMappableContainer() specifiers
  virtual ~InOrderMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  InOrderMappableContainer& operator=(const InOrderMappableContainer&) = delete;
  // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  InOrderMappableContainer& operator=(InOrderMappableContainer&&) noexcept = delete;
  // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator==(const InOrderMappableContainer<Data> &) const noexcept = delete;
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator!=(const InOrderMappableContainer<Data> &) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  // using typename MappableContainer<Data>::MapFun;
  using typename MappableContainer<Data>::MapFun;

  // type InOrderMap(argument) specifiers;
  virtual void InOrderMap(MapFun) = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  // type Map(argument) specifiers; // Override MappableContainer member
  void Map(MapFun) override;

};

/* ************************************************************************** */

template <typename Data>
class BreadthMappableContainer : virtual public MappableContainer<Data> , virtual public BreadthTraversableContainer<Data>{
  // Must extend MappableContainer<Data>,
  //             BreadthTraversableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~BreadthMappableContainer() specifiers
  virtual ~BreadthMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  BreadthMappableContainer& operator=(const BreadthMappableContainer&) = delete;
  // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  BreadthMappableContainer& operator=(BreadthMappableContainer&&) noexcept = delete;
  // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator==(const BreadthMappableContainer<Data> &) const noexcept = delete;
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator!=(const BreadthMappableContainer<Data> &) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  // using typename MappableContainer<Data>::MapFun;
  using typename MappableContainer<Data>::MapFun;

  // type BreadthMap(argument) specifiers;
  virtual void BreadthMap(MapFun) = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)
  void Map(MapFun) override;
  // type Map(argument) specifiers; // Override MappableContainer member

};

/* ************************************************************************** */

}

#include "mappable.cpp"

#endif