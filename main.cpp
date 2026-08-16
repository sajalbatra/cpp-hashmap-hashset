#include <iostream>
#include <string>
#include "HashSet.h"

int main()
{
    std::cout << "--- Testing HashMap ---" << std::endl;

    HashMap<std::string, int> ageMap;

    ageMap.put("Alice", 24);
    ageMap.put("Bob", 30);
    ageMap.put("Charlie", 28);
    ageMap.put("Alice", 25);

    std::cout << "Alice's Age: "
              << ageMap.get("Alice")
              << " (Expected: 25)" << std::endl;

    std::cout << "Map Size: "
              << ageMap.size()
              << " (Expected: 3)" << std::endl;

    ageMap.remove("Bob");

    std::cout << "Contains Bob? "
              << (ageMap.contains("Bob") ? "Yes" : "No")
              << " (Expected: No)" << std::endl;

    std::cout << "\n--- Testing HashSet ---" << std::endl;

    HashSet<std::string> namesSet;

    namesSet.add("Delhi");
    namesSet.add("Mumbai");
    namesSet.add("Delhi");

    std::cout << "Set Size: "
              << namesSet.size()
              << " (Expected: 2)" << std::endl;

    std::cout << "Contains Mumbai? "
              << (namesSet.contains("Mumbai") ? "Yes" : "No")
              << " (Expected: Yes)" << std::endl;

    return 0;
}