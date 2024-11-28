#include "../CA2-SearchTree/Entity.h"
#include "../CA2-SearchTree/BinaryTree.h"

template <class K, class V>
class TreeMap
{
private:
	BinaryTree<Entity<K, V>> tree;

public:
	TreeMap() {};
	~TreeMap() {};

	void add(K key, V value);
	int count();


};

template<class K, class V>
inline void TreeMap<K, V>::add(K key, V value)
{
	{
		Entity<K, V> entity(key, value);
		tree.add(entity);
	}
}

template<class K, class V>
int TreeMap<K, V>::count()
{
	
	return tree.count();
	
}
