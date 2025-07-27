#include <stdio.h>
#include "trie.h"

int main() {
    TrieNode* root = createNode();

    // Insert sample words with mixed cases
    const char* words[] = {"cat", "car", "cart", "cake", "cell", "dog", "don", "dot", 
                          "Cat", "Car", "DOG", "CAKE"};
    for (int i = 0; i < 12; i++) {
        insert(root, words[i]);
    }

    // Autocomplete demo
    printf("==== Autocomplete Demo =====\n");
    autocomplete(root, "ca");

    // Spell checker demo
    printf("\n==== Spell Checker Demo =====\n");
    spellCheck(root, "kat");

    // Word prediction demo
    printf("\n==== Word Prediction Demo =====\n");
    predictNextWord(root, "ca");

    // Free trie
    freeTrie(root);
    return 0;
}
