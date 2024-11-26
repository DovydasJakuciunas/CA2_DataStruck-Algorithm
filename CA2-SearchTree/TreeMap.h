#include <map>  // For key-value mapping
#include <vector>    

#include "../CA2-SearchTree/BinaryTree.h" 

template <typename K, typename V>
class TreeMap {

    BSTNode<K>* root;              
    map<K, V> keyValueMap;    
    int numElements;

public:

    void put( K& key,  V& value);
    int size();

};


template <class K, class V>
void TreeMap<K, V>::put(K& key, V& value)
{
	if (root == nullptr)
	{
		root = new BSTNode<K>(key);
		keyValueMap[key] = value;
		
	}
	else
	{
		root->add(key);
	}
	numElements++;
}

template <class K, class V>
int TreeMap<K, V>::size()
{
	return numElements;
}
