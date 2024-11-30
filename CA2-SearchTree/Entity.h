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
	bool removeKey(K key);
    V& operator[](K key);
};


template<class K, class V>
inline void Entity<K, V>::put(K key, V value)    //Uses Binary Tree to put key and value into tree
{
    {
        Entity<K, V> entity(key, value);
        tree.put(entity);
    }
}

template<class K, class V>
int Entity<K, V>::size()    //Counts all the leafes in the tree
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
        tree.get(Entity<K, V>(key, V()));   //Uses Binary Tree to get key
        return true;
    }
	catch (logic_error&) {      //Return null if key is not found
        return false;
    }
}

template <class K, class V>
inline V& Entity<K, V>::get(K key) {
    static V nullValue = V(); 
    try {
		auto& entity = tree.get(Entity<K, V>(key, V())); //uses Binary Tree to get value of key
        return entity.value;                             
    }
    catch (logic_error&) {
        return nullValue; 
    }
}

template <class K, class V>
inline BinaryTree<K> Entity<K, V>::keySet() {
    BinaryTree<K> keys;  //Starts to get             
    collectKeys(tree.root, keys);     
    return keys;                      
}

template <class K, class V>
void Entity<K, V>::collectKeys(BSTNode<Entity<K, V>>* node, BinaryTree<K>& keys) {      //Helper method for keyset
    if (node == nullptr) return; 

    collectKeys(node->getLeft(), keys);
    keys.put(node->getItem().key);
    collectKeys(node->getRight(), keys);
}

template<class K, class V>
inline bool Entity<K, V>::removeKey(K key)  //Remove key from tree
{
    return tree.remove(Entity<K, V>(key, V()));
}

template <class K, class V>
V& Entity<K, V>::operator[](K key) {   //Overloading get operator , allow me to change variable for values
    try {
        auto& entity = tree.get(Entity<K, V>(key, V()));
        return entity.value;
    }
    catch (logic_error&) {
        this->put(key, V());
        return tree.get(Entity<K, V>(key, V())).value;
    }
}

