#include "radix_tree.h"

RadixTree::RadixTree() {
    root = new Node();
}

RadixTree::~RadixTree() {
    deleteTree(root);
}

/**
 * @brief Inserts an IPv6 prefix into the radix tree.
 * @param prefix The IPv6 prefix in string format.
 * @param prefixLength The length of the prefix in bits.
 * @param popId The PoP ID associated with the prefix.
 */
void RadixTree::insert(const std::string& prefix, int prefixLength, int popId) {
    std::string binaryPrefix = toBinaryString(prefix).substr(0, prefixLength);
    Node* current = root;
    for (std::string::size_type i = 0; i < binaryPrefix.size(); ++i) {
        char bit = binaryPrefix[i];
        if (current->children.find(bit) == current->children.end()) {
            current->children[bit] = new Node();
        }
        current = current->children[bit];
    }
    current->popId = popId;
}

/**
 * @brief Finds the longest matching prefix for a given IPv6 address.
 * @param ipv6 The IPv6 address in string format.
 * @return A pair containing the PoP ID and the scope prefix length of the longest matching prefix.
 */
std::pair<int, int> RadixTree::find(const std::string& ipv6) {
    std::string binaryAddress = toBinaryString(ipv6);
    Node* current = root;
    Node* bestMatch = nullptr;
    int bestMatchLength = 0;

    for (std::string::size_type i = 0; i < binaryAddress.size(); ++i) {
        char bit = binaryAddress[i];
        if (current->children.find(bit) == current->children.end()) {
            break;
        }
        current = current->children[bit];
        if (current->popId != -1) {
            bestMatch = current;
            bestMatchLength = i + 1;
        }
    }

    if (bestMatch) {
        return std::make_pair(bestMatch->popId, bestMatchLength);
    }
    return std::make_pair(-1, -1);
}

/**
 * @brief Recursively deletes all nodes in the tree.
 * @param node The current node being deleted.
 */
void RadixTree::deleteTree(Node* node) {
    for (auto & it : node->children) {
        deleteTree(it.second);
    }
    delete node;
}

/**
 * @brief Converts an IPv6 address from string to binary string representation.
 * @param ipv6 The IPv6 address in string format.
 * @return The binary string representation of the IPv6 address.
 */
std::string RadixTree::toBinaryString(const std::string& ipv6) {
    struct in6_addr addr;
    if (inet_pton(AF_INET6, ipv6.c_str(), &addr) != 1) {
        throw std::invalid_argument("Invalid IPv6 address");
    }
    std::bitset<128> bits;
    for (int i = 0; i < 16; ++i) {
        bits <<= 8;
        bits |= addr.s6_addr[i];
    }
    return bits.to_string();
}
