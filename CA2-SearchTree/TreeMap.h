#include <map>  // For key-value mapping
#include <vector>    

#include "../CA2-SearchTree/BinaryTree.h" 

template <typename K, typename V>
class TreeMap {
public:
	BSTNode<K>* root;
	map<K, V> keyValueMap;
	int numElements;

	TreeMap() : root(nullptr), numElements(0) {}
	~TreeMap() { clear(); }

    void put(K& key, V& value);
	V get(K& key);
    int size();
	void clear();



};


template <class K, class V>
void TreeMap<K, V>::put(K& key, V& value)
{
	if (root == nullptr)
	{
		root = new BSTNode<K>(key);
		keyValueMap[key] = value;
		numElements++;
		
	}
	else
	{
		root->add(key);
		keyValueMap[key] = value;
		numElements++;
	}
	
}

template <class K,class V>
V TreeMap<K, V>::get(K& key)
{
	auto it = keyValueMap.find(key);
	if (it != keyValueMap.end())
	{
		return it->second;
	}
}

template <class K, class V>
int TreeMap<K, V>::size()
{
	return numElements;
}

template<typename K, typename V>
inline void TreeMap<K, V>::clear()
{

	if (root != nullptr)
	{
		delete root;
		root = nullptr;
		numElements=0;
	}
	keyValueMap.clear();
	
	
}

