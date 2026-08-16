// Implement the hashmap and hashset implementation in cpp
#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include <functional>

const double LOAD_FACTOR = 0.75;

template <typename K, typename V>
class HashMap
{
private:
    int bucketCount = 4;
    int elementsCount = 0;
    std::vector<std::vector<std::pair<K, V>>> buckets;

    size_t hashFunction(const K &key)
    {
        return std::hash<K>{}(key) % bucketCount;
    }

    // like redis store everything in string
    void rehash()
    {
        // rehash the bucket.
        // bucketCount *=2; 8,16,32,64.....
        bucketCount *= 2;
        std::vector<std::vector<std::pair<K, V>>> newBuckets(bucketCount);
        for (const auto &bucket : buckets)
        {
            for (const auto &val : bucket)
            {
                int index = hashFunction(val.first);
                newBuckets[index].push_back({val.first, val.second});
            }
        }
        buckets = std::move(newBuckets);
    }

public:
    HashMap()
    {
        buckets.resize(bucketCount);
    }
    void put(K key, V value)
    {
        int index = hashFunction(key);
        // Check if key already exists
        for (auto &val : buckets[index])
        {
            if (val.first == key)
            {
                val.second = value;
                return;
            }
        }
        if ((double)(elementsCount + 1) / bucketCount > LOAD_FACTOR)
        {
            rehash();
            // bucketCount changed, so calculate index again
            index = hashFunction(key);
        }
        buckets[index].push_back({key, value});
        elementsCount++;
    }
    V get(K key)
    {
        int index = hashFunction(key);
        for (auto &entry : buckets[index])
        {
            if (entry.first == key)
            {
                return entry.second;
            }
        }
        return V();
    }
    void remove(K key)
    {
        int index = hashFunction(key);
        for (auto it = buckets[index].begin(); it != buckets[index].end(); ++it)
        {
            if (it->first == key)
            {
                buckets[index].erase(it);
                elementsCount--;
                return;
            }
        }
    }
    bool contains(K key)
    {
        int index = hashFunction(key);
        for (auto &entry : buckets[index])
        {
            if (entry.first == key)
            {
                return true;
            }
        }
        return false;
    }
    int size()
    {
        return elementsCount;
    }
};