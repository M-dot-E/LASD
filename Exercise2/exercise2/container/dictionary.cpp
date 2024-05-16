

namespace lasd {

/* ************************************************************************** */
template<typename Data>
inline bool DictionaryContainer<Data>::InsertAll(const TraversableContainer<Data> & cont){
    bool all = true;
    cont.Traverse([this, &all](const Data& dat){
        all &= Insert(dat);
    }
    );
    return all;
}

template<typename Data>
inline bool DictionaryContainer<Data>::InsertAll(MappableContainer<Data> && cont){
    bool all = true;
    cont.Map([this, &all](const Data& dat){
        all &= Insert(std::move(dat));
    }
    );
    return all;
}

template<typename Data>
inline bool DictionaryContainer<Data>::RemoveAll(const TraversableContainer<Data> & cont){
    bool all = true;
    cont.Traverse(
        [this , &all](const Data & dat){
            all &= Remove(dat);
        }
    );
    return all;
}

template<typename Data>
inline bool DictionaryContainer<Data>::RemoveSome(const TraversableContainer<Data> & cont){
    bool some = true;
    cont.Traverse(
        [this , &some](const Data & dat){
            some |= Remove(dat);
        }
    );
    return some;
}

template<typename Data>
inline bool DictionaryContainer<Data>::InsertSome(const TraversableContainer<Data> & cont){
    bool some = true;
    cont.Traverse(
        [this , &some](const Data & dat){
            some |= Insert(dat);
        }
    );
    return some;
}

template<typename Data>
inline bool DictionaryContainer<Data>::InsertSome(MappableContainer<Data> && cont){
    bool some = true;
    cont.Traverse(
        [this , &some](const Data & dat){
            some |= Insert(std::move(dat));
        }
    );
    return some;
}
// ...

/* ************************************************************************** */

}