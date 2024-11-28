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
	BinaryTree<Entity<K, V>> tree;

public:
    Entity() {};
    ~Entity() {};
    Entity(const K& k, const V& v) : key(k), value(v) {}

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

    void add(K key, V value);
    int count();
};


template<class K, class V>
inline void Entity<K, V>::add(K key, V value)
{
    {
        Entity<K, V> entity(key, value);
        tree.add(entity);
    }
}

template<class K, class V>
int Entity<K, V>::count()
{

    return tree.count();

}
