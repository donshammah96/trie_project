#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "trie.h"

void test_mixed_case_insertion() {
    printf("Testing mixed case insertion...\n");
    TrieNode* root = createNode();
    
    // Insert words with different cases
    insert(root, "Cat");
    insert(root, "cat");
    insert(root, "CAT");
    insert(root, "CaT");
    insert(root, "Apple");
    insert(root, "APPLE");
    insert(root, "apple");
    
    // Test that all variations are stored separately
    assert(search(root, "Cat") == true);
    assert(search(root, "cat") == true);
    assert(search(root, "CAT") == true);
    assert(search(root, "CaT") == true);
    assert(search(root, "Apple") == true);
    assert(search(root, "APPLE") == true);
    assert(search(root, "apple") == true);
    
    // Test that non-inserted variations return false
    assert(search(root, "cAt") == false);
    assert(search(root, "cAT") == false);
    assert(search(root, "ApPle") == false);
    
    freeTrie(root);
    printf("✓ Mixed case insertion test passed!\n");
}

void test_case_sensitive_search() {
    printf("Testing case sensitive search...\n");
    TrieNode* root = createNode();
    
    insert(root, "Hello");
    insert(root, "world");
    insert(root, "WORLD");
    insert(root, "Test");
    insert(root, "TEST");
    
    // Test exact matches
    assert(search(root, "Hello") == true);
    assert(search(root, "world") == true);
    assert(search(root, "WORLD") == true);
    assert(search(root, "Test") == true);
    assert(search(root, "TEST") == true);
    
    // Test case mismatches
    assert(search(root, "hello") == false);
    assert(search(root, "HELLO") == false);
    assert(search(root, "World") == false);
    assert(search(root, "test") == false);
    
    freeTrie(root);
    printf("✓ Case sensitive search test passed!\n");
}

void test_mixed_case_autocomplete() {
    printf("Testing mixed case autocomplete...\n");
    TrieNode* root = createNode();
    
    // Insert words with mixed cases
    insert(root, "car");
    insert(root, "Car");
    insert(root, "CAR");
    insert(root, "cart");
    insert(root, "Cart");
    insert(root, "CART");
    insert(root, "card");
    insert(root, "Card");
    
    printf("Autocomplete for 'car':\n");
    autocomplete(root, "car");
    
    printf("\nAutocomplete for 'Car':\n");
    autocomplete(root, "Car");
    
    printf("\nAutocomplete for 'CAR':\n");
    autocomplete(root, "CAR");
    
    freeTrie(root);
    printf("✓ Mixed case autocomplete test completed!\n");
}

void test_empty_and_invalid_input() {
    printf("Testing empty and invalid input...\n");
    TrieNode* root = createNode();
    
    // Test empty string
    insert(root, "");
    assert(search(root, "") == true);
    
    // Test single characters
    insert(root, "A");
    insert(root, "a");
    insert(root, "Z");
    insert(root, "z");
    
    assert(search(root, "A") == true);
    assert(search(root, "a") == true);
    assert(search(root, "Z") == true);
    assert(search(root, "z") == true);
    
    // These should be case sensitive
    assert(search(root, "A") != search(root, "a"));
    assert(search(root, "Z") != search(root, "z"));
    
    freeTrie(root);
    printf("✓ Empty and invalid input test passed!\n");
}

void run_all_tests() {
    printf("=== Running Trie Mixed Case Tests ===\n\n");
    
    test_mixed_case_insertion();
    printf("\n");
    
    test_case_sensitive_search();
    printf("\n");
    
    test_mixed_case_autocomplete();
    printf("\n");
    
    test_empty_and_invalid_input();
    printf("\n");
    
    printf("=== All tests completed! ===\n");
}

int main() {
    run_all_tests();
    return 0;
}
