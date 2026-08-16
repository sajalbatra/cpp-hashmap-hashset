# HashMap & HashSet in C++

A from-scratch implementation of HashMap and HashSet in C++ to understand how hash-based data structures work internally.

## Features

### HashMap
- Generic key-value pairs using C++ templates
- std::hash for hashing
- Separate chaining for collision handling
- Load factor based resizing
- Dynamic bucket expansion
- Rehashing
- Insert / update
- Get
- Remove
- Contains
- O(1) size tracking

### HashSet
- Built on top of HashMap using composition
- Add
- Remove
- Contains
- Size
- Duplicate handling

## How It Works

```
Key
 |
std::hash<K>
 |
Hash value
 |
Hash % bucketCount
 |
Bucket
 |
Separate chaining
```

## When the load factor exceeds 0.75:

Old buckets
     |
Double bucket count
     |
Recalculate hash indexes
     |
Move entries

## Project Structure
```
├── HashMap.h
├── HashSet.h
└── main.cpp
```
