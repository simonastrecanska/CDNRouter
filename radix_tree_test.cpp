#include <cassert>
#include <iostream>
#include "radix_tree.h"

/**
 * @brief Function to run tests for the RadixTree class.
 */

void runTests() {
    RadixTree tree;

    tree.insert("2001:49f0:d0b8::", 48, 174);
    tree.insert("2402:8100:2582::", 48, 215);
    tree.insert("240e:438:1e30::", 44, 103);
    tree.insert("2a02:26f7:ded0::", 48, 87);
    tree.insert("2404:0:2000::", 36, 58);
    tree.insert("2001:49f0::", 32, 200);
    tree.insert("2001:49f0:d0b8:1234::", 64, 300);

    std::pair<int, int> result = tree.find("2001:49f0:d0b8:8a00::");
    assert(result.first == 174 && result.second == 48);
    std::cout << "Test 1 passed\n";

    result = tree.find("2402:8100:2582:1234::");
    assert(result.first == 215 && result.second == 48);
    std::cout << "Test 2 passed\n";

    result = tree.find("240e:438:1e30:abcd::");
    assert(result.first == 103 && result.second == 44);
    std::cout << "Test 3 passed\n";

    result = tree.find("2a02:26f7:ded0:5678::");
    assert(result.first == 87 && result.second == 48);
    std::cout << "Test 4 passed\n";

    result = tree.find("2404:0:2000:abcd::");
    assert(result.first == 58 && result.second == 36);
    std::cout << "Test 5 passed\n";

    result = tree.find("2405:0000:2000::");
    assert(result.first == -1 && result.second == -1);
    std::cout << "Test 6 passed\n";

    // Additional test cases
    result = tree.find("2001:49f0:abcd::");
    assert(result.first == 200 && result.second == 32);
    std::cout << "Test 7 passed\n";

    result = tree.find("2001:49f0:d0b8:1234:5678::");
    assert(result.first == 300 && result.second == 64);
    std::cout << "Test 8 passed\n";

    result = tree.find("2001:49f0:d0b8:1234:abcd::");
    assert(result.first == 300 && result.second == 64);
    std::cout << "Test 9 passed\n";

    result = tree.find("2001:1234:5678::");
    assert(result.first == -1 && result.second == -1);
    std::cout << "Test 10 passed\n";

    result = tree.find("240e:438::");
    assert(result.first == -1 && result.second == -1);
    std::cout << "Test 11 passed\n";

    result = tree.find("2404::abcd");
    assert(result.first == -1 && result.second == -1);
    std::cout << "Test 12 passed\n";
}

int main() {
    try {
        runTests();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
