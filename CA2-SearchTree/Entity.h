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

    //Stage 2
    void printLetters();
    void printWords(K key);
};


template<class K, class V>
void Entity<K, V>::put(K key, V value)    //Uses Binary Tree to put key and value into tree
{
    {
        Entity<K, V> entity(key, value);
        tree.add(entity);
    }
}
template<class K, class V>
int Entity<K, V>::size()    //Counts all the leafes in the tree
{

    return tree.count();

}
template<class K, class V>
void Entity<K, V>::clear()
{
	tree.clear();
}
template<class K, class V>
bool Entity<K, V>::containsKey(K key)
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
V& Entity<K, V>::get(K key) {
    static V nullValue = V();
    try {
        Entity<K, V> tempEntity(key, V());
        auto& entity = tree.get(tempEntity); //uses Binary Tree to get value of key
        return entity.value;
    }
    catch (logic_error&) {
        return nullValue;
    }
}
template <class K, class V>
BinaryTree<K> Entity<K, V>::keySet() {
    BinaryTree<K> keys;  //Starts to get             
    collectKeys(tree.root, keys);     
    return keys;                      
}
template <class K, class V>
void Entity<K, V>::collectKeys(BSTNode<Entity<K, V>>* node, BinaryTree<K>& keys) {      //Helper method for keyset
    if (node == nullptr) return; 

    collectKeys(node->getLeft(), keys);
    keys.add(node->getItem().key);
    collectKeys(node->getRight(), keys);
}
template<class K, class V>
bool Entity<K, V>::removeKey(K key)  //Remove key from tree
{
    return tree.remove(Entity<K, V>(key, V()));
}
template <class K, class V>
 V& Entity<K, V>::operator[](K key) {   //Overloading get operator , allow me to change variable for values
    try {
        Entity<K, V> tempEntity(key, V());
        auto& entity = tree.get(tempEntity);
        return entity.value;
    }
    catch (logic_error&) {
        this->put(key, V());
        Entity<K, V> tempEntity(key, V());
        return tree.get(tempEntity).value;
    }
}

// Stage 2 Methods 
template <class K, class V>
void Entity<K, V>::printLetters() {
    keySet().printInOrder();
}

template <class K, class V>
void Entity<K, V>::printWords(K key) {

        auto& wordsTree = this->get(key);
        cout << "Words for the letter '" << key << "': ";
        wordsTree.printInOrder();
        cout << endl;
    
}


