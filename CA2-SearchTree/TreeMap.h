#include <map>  
#include <set>

#include "../CA2-SearchTree/BinaryTree.h" 

template <typename K, typename V>
class TreeMap {
public:
	BSTNode<K>* root;
	map<K, V> keyValueMap;
	int numElements;

	TreeMap() : root(nullptr), numElements(0) {}
	~TreeMap() { clear(); }

	void clear();
	bool containsKey(K& key);
	V& get(K& key);
	BinaryTree<K> keySet();
	void put(K& key, V& value);
	int size();
	bool removeKey(K key);

	
	V& operator[K key]
};


template <class K, class V>
void TreeMap<K, V>::put(K& key, V& value)
{
	if (root == nullptr)
	{
		root = new BSTNode<K>(key);
		keyValueMap[key] = value;	//Add key-value pair to map
		numElements++;
		
	}
	else
	{
		root->add(key);
		keyValueMap[key] = value;
		numElements++;
	}
	
}

template<typename K, typename V>
inline V& TreeMap<K, V>::get(K& key)
{
	auto it = keyValueMap.find(key);
	if (it != keyValueMap.end())
	{
		return it->second;
	}
	else
	{
		return V(); //Return empty for V(null)
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

template<typename K, typename V>
inline bool TreeMap<K, V>::containsKey(K& key)
{
	return keyValueMap.find(key) != keyValueMap.end();	//Checks if key is in the map
}

//template<typename K, typename V>
//inline BinaryTree<K> TreeMap<K, V>::keySet()
//{
//	set<K> keys;
//	for (auto it = keyValueMap.begin(); it != keyValueMap.end(); ++it)
//	{
//		keys.insert(it->first);
//	}
//
//	
//}

//Removes element by the key
template<typename K, typename V>
inline bool TreeMap<K, V>::removeKey(K key)
{
	if (containsKey(key))
	{
		keyValueMap.erase(key);
		numElements--;
		return true;
	}
	return false;
	
}

template<typename K, typename V>
inline V& TreeMap<K, V>::operator[](const K& key)
{
	return keyValueMap[key];
}
