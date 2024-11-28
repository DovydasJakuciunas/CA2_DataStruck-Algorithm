#pragma once
#include <iostream>


using namespace std;

template <class K, class V>
struct Entity 
{
private:
    K key;
    V value;

public:
    Entity() {};
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

	
};


