# Radix Tree for IPv6 Prefix Matching

## Overview

This project implements a Radix Tree to perform longest prefix matching of IPv6 addresses. The Radix Tree is used to route queries to the nearest CDN PoP based on the given IPv6 prefixes and their associated PoP IDs.

## File Structure

- `radix_tree.h`: Header file containing the `RadixTree` class definition.
- `radix_tree.cpp`: Implementation file for the `RadixTree` class.
- `radix_tree_test.cpp`: Unit tests for the `RadixTree` class.

### Compilation

1. Clone the repository:
```sh
git clone https://github.com/simonastrecanska/CDNRouter.git
```

2. Navigate to the project directory:
```sh
cd src
```

3. To compile the project, run the following command in your terminal:

```sh
g++ -o radix_tree_test radix_tree_test.cpp radix_tree.cpp
```

### Running the Tests

```sh
./radix_tree_test
```

## Detailed File Descriptions

### `radix_tree.h`

- Defines the `RadixTree` class and the `Node` struct.
- Declares methods for inserting prefixes, finding matches, deleting nodes, and converting IPv6 addresses to binary strings.

### `radix_tree.cpp`

- Implements the `RadixTree` class methods.
- Handles memory management and provides utility functions for converting IPv6 addresses.

### `radix_tree_test.cpp`

- Contains unit tests to verify the correctness of the `RadixTree` class.
- Uses assertions to ensure the tree behaves as expected.
