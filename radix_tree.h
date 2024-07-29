#ifndef RADIX_TREE_H
#define RADIX_TREE_H

#include <iostream>
#include <unordered_map>
#include <string>
#include <bitset>
#include <vector>
#include <arpa/inet.h>

class RadixTree {
public:
    RadixTree();
    ~RadixTree();
    void insert(const std::string& prefix, int prefixLength, int popId);
    std::pair<int, int> find(const std::string& ipv6);

private:
    struct Node {
        std::unordered_map<char, Node*> children;
        int popId;
        Node() : popId(-1) {}
    };

    Node* root;
    void deleteTree(Node* node);
    static std::string toBinaryString(const std::string& ipv6);
};

#endif // RADIX_TREE_H
