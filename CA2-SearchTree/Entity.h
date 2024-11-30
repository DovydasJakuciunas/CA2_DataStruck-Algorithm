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

    void put(K key, V value);
    int size();

    //Stage 1
	void clear();
	bool containsKey(K key);
	V& get(K key);
    BinaryTree<K> keySet();
    void collectKeys(BSTNode<Entity<K, V>>* node, BinaryTree<K>& keys);

};


template<class K, class V>
inline void Entity<K, V>::put(K key, V value)
{
    {
        Entity<K, V> entity(key, value);
        tree.put(entity);
    }
}

template<class K, class V>
int Entity<K, V>::size()
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

template <class K, class V>
inline V& Entity<K, V>::get(K key) {
    static V nullValue = V(); 
    try {
        auto& entity = tree.get(Entity<K, V>(key, V()));
        return entity.value;                             
    }
    catch (logic_error&) {
        return nullValue; 
    }
}

template <class K, class V>
inline BinaryTree<K> Entity<K, V>::keySet() {
    BinaryTree<K> keys;              
    collectKeys(tree.root, keys);     
    return keys;                      
}

template <class K, class V>
void Entity<K, V>::collectKeys(BSTNode<Entity<K, V>>* node, BinaryTree<K>& keys) {
    if (node == nullptr) return; 

    collectKeys(node->getLeft(), keys);
    keys.put(node->getItem().key);
    collectKeys(node->getRight(), keys);
}



