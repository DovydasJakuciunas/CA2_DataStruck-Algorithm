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
    bool operator <(Entity& b)const
    {
        return key < b.key;
    }
    bool operator>(Entity& b)const
    {
        return key > b.key;
    }
    bool operator==(Entity& b)const
    {
        return key == b.key;
    }

    void add(K key, V value);
    int count();

    //Stage 1
	void clear();
	bool containsKey(K key);
	V& get(K key);
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

template<class K, class V>
inline void Entity<K, V>::clear()
{
	tree.clear();
}

template<class K, class V>
inline bool Entity<K, V>::containsKey(K key)
{
    try {
        tree.get(Entity<K, V>(key, V()));   
        return true;
    }
    catch (logic_error&) {
        return false;
    }
}

template<class K, class V>
inline V& Entity<K, V>::get(K key)
{
    try {
        auto& entity = tree.get(Entity<K, V>(key, V()));
        return entity.value; 
    }
    catch (logic_error&) {
		return V();
    }
}

