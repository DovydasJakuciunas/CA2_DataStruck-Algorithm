#pragma once
#include <iostream>

#include "../CA2-SearchTree/BinaryTree.h"

using namespace std;

template <class K, class V>
struct Entity
{
private:
    K key;
    V value;

public:
    Entity();
    Entity(K key, V value);

    friend ostream& operator<<(ostream& out, Entity& b)
    {
        out << "Key: " << b.key << ". Value: " << b.value;
        return out;
    }
    bool operator <(Entity& b)
    {
        return key < b.key;
    }
    bool operator>(Entity& b)
    {
        return key > b.key;
    }
    bool operator==(Entity& b)
    {
        return key == b.key;
    }
};

template<class K, class V>
inline Entity<K, V>::Entity() 
{
    key = K();
    value = V();
}

template<class K, class V>
inline Entity<K, V>::Entity(K keyOther, V valueOther)
{
    key = keyOther;
    value = valueOther;
}
