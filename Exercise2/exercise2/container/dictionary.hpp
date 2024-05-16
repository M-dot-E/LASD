

#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

/* ************************************************************************** */

#include "mappable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class DictionaryContainer {
  // Must extend TestableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~DictionaryContainer() specifiers
  virtual ~DictionaryContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  DictionaryContainer& operator=(const DictionaryContainer&) = delete;
  // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  DictionaryContainer& operator=( DictionaryContainer&&) noexcept = delete;
  // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const DictionaryContainer&) const noexcept = delete;
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator!=(const DictionaryContainer&) const noexcept = delete;
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member functions

  // type Insert(argument) specifiers; // Copy of the value
  inline virtual bool Insert(const Data& value) = 0;
  // type Insert(argument) specifiers; // Move of the value
  inline virtual bool Insert(Data&& value) = 0;
  // type Remove(argument) specifiers;
  inline virtual bool Remove(const Data& value) = 0;


  // type InsertAll(argument) specifiers; // Copy of the value; From TraversableContainer; True if all are inserted
  inline virtual bool InsertAll(const TraversableContainer<Data>& container);

  // type InsertAll(argument) specifiers; // Move of the value; From MappableContainer; True if all are inserted
  inline virtual bool InsertAll(MappableContainer<Data>&& container);

  // type RemoveAll(argument) specifiers; // From TraversableContainer; True if all are removed
  inline virtual bool RemoveAll(const TraversableContainer<Data>& container);

  // type InsertSome(argument) specifiers; // Copy of the value; From TraversableContainer; True if some is inserted
  inline virtual bool InsertSome(const TraversableContainer<Data>& container);
  // type InsertSome(argument) specifiers; // Move of the value; From MappableContainer; True if some is inserted
  inline virtual bool InsertSome(MappableContainer<Data>&& container);
  // type RemoveSome(argument) specifiers; // From TraversableContainer; True if some is removed
  inline virtual bool RemoveSome(const TraversableContainer<Data>& container);


};

/* ************************************************************************** */

}

#include "dictionary.cpp"

#endif