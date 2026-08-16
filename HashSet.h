#pragma once
#include "HashMap.h" // Import your custom map using quotes

template <typename K>
class HashSet
{
private:
    HashMap<K, bool> mpp;

public:
    void add(const K &value)
    {
        mpp.put(value, true);
    }
    bool contains(const K &value)
    {
        return mpp.contains(value);
    }
    void remove(const K &value)
    {
        mpp.remove(value);
    }
    int size()
    {
        return mpp.size();
    }
};