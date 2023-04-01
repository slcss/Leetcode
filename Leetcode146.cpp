// Leetcode146.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class LRUCache {
public:
    LRUCache(int capacity) {
        size = capacity;
    }

    int get(int key) {
        if (mapData.find(key) == mapData.end()) return -1;

        listData.erase(mapData[key].first);
        listData.push_back(key);
        auto it = listData.end();
        mapData[key].first = --it;

        return mapData[key].second;
    }

    void put(int key, int value) {
        if (mapData.find(key) != mapData.end())
        {
            listData.erase(mapData[key].first);
            listData.push_back(key);
            auto it = listData.end();
            mapData[key].first = --it;

            mapData[key].second = value;
        }
        else
        {
            if (mapData.size() == size)
            {
                int keyDelete = listData.front();
                listData.pop_front();
                mapData.erase(keyDelete);
            }
            listData.push_back(key);
            auto it = listData.end();
            mapData[key].first = --it;
            mapData[key].second = value;
        }
    }

private:
    int size = 0;
    unordered_map<int, pair<list<int>::iterator, int>> mapData;
    list<int> listData;
};


int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
