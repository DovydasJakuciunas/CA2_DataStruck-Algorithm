//#include "../CA2-SearchTree/BinaryTree.h" 
//
//template <typename K, typename V>
//class TreeMap {
//public:
//	BSTNode<K>* root;
//	BinaryTree<K, V> keyValueMap;
//	int numElements;
//
//	TreeMap() : root(nullptr), numElements(0) {}
//	~TreeMap() { clear(); }
//
//	void clear();
//	bool containsKey(K& key);
//	V get(K& key);
//	BinaryTree<K> keySet();
//    void put(K& key, V& value);
//    int size();
//	
//	
//
//
//};
//
//template<typename K, typename V>
//inline void TreeMap<K, V>::clear()
//{
//
//	if (root != nullptr)
//	{
//		delete root;
//		root = nullptr;
//		numElements = 0;
//	}
//	keyValueMap.clear();
//
//
//}
//
//template<typename K, typename V>
//inline bool TreeMap<K, V>::containsKey(K& key)
//{
//	return keyValueMap.find(key) != keyValueMap.end();
//}
//
//template <class K, class V>
//V TreeMap<K, V>::get(K& key)
//{
//	auto it = keyValueMap.find(key);
//	if (it != keyValueMap.end())
//	{
//		return it->second;
//	}
//	else
//	{
//		return V();
//	}
//}
//
//template<typename K, typename V>
//inline BinaryTree<K> TreeMap<K, V>::keySet()
//{
//	set<K> treeSet;
//	
//}
//
//
//
//template <class K, class V>
//void TreeMap<K, V>::put(K& key, V& value)
//{
//	if (root == nullptr)
//	{
//		root = new BSTNode<K>(key);
//		keyValueMap[key] = value;
//		numElements++;
//		
//	}
//	else
//	{
//		root->add(key);
//		keyValueMap[key] = value;
//		numElements++;
//	}
//	
//}
//
//
//
//template <class K, class V>
//int TreeMap<K, V>::size()
//{
//	return numElements;
//}
//
//
//
//
//
