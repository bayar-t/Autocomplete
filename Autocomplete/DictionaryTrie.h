/**
 *  CSE 100 PA2 C++ Autocomplete
 *  Authors: Jor-el Briones, Christine Alvarado
 */

/*
 * Authors: Jamie Shi (A12678538) and Sergelenbayar Tsogtbaatar (A12949154)
 * Date: January 26, 2017
 * Overview: Header for methods to implement MWT for dictionary
 * Assignment #2
 * File Name: DictionaryTrie.h
 */

#ifndef DICTIONARY_TRIE_H
#define DICTIONARY_TRIE_H
#define NUM_VALID 27
#include <vector>
#include <string>
#include <stack>

// Code comes from Stepik Chapter 6.6 reading 
class MultiNode {
  public:
    bool word = false;
    std::string theWord = "";
    unsigned int theFrequency = 0;
    MultiNode* parent = NULL;
    MultiNode* children[27];
    MultiNode();
};

/**
 *  The class for a dictionary ADT, implemented as a trie
 *  You may implement this class as either a mulit-way trie
 *  or a ternary search trie, but you must use one or the other.
 *
 */
class DictionaryTrie
{
  public:

    /* Create a new Dictionary that uses a Trie back end */
    DictionaryTrie();

    /* Insert a word with its frequency into the dictionary.
     * Return true if the word was inserted, and false if it
     * was not (i.e. it was already in the dictionary or it was
     * invalid (empty string) */
    bool insert(std::string word, unsigned int freq);

    /* Return true if word is in the dictionary, and false otherwise */
    bool find(std::string word) const;

    /* Return up to num_completions of the most frequent completions
     * of the prefix, such that the completions are words in the dictionary.
     * These completions should be listed from most frequent to least.
     * If there are fewer than num_completions legal completions, this
     * function returns a vector with as many completions as possible.
     * If no completions exist, then the function returns a vector of size 0.
     * The prefix itself might be included in the returned words if the prefix
     * is a word (and is among the num_completions most frequent completions
     * of the prefix)
     */
    std::vector<std::string>
      predictCompletions(std::string prefix, unsigned int num_completions); 

    /* Destructor */
    ~DictionaryTrie();

  private:
    /* The the root node in the MWT*/
    MultiNode* root;

    /*
     * Given a char, convert it to a number that represents its index in the 
     * Node's children array. Return that number.
     * Example: input 'a' returns 0, input 'b' returns 1, input 'c' returns 2
     * More examples: input 'y' returns 24, input 'z' returns 25
     * Exception: input ' ' returns 26 (last index in the array)
     * Input chars that are not spaces or letters from a-z return -1
     */
    int charToNum(char character) const;

    /* Given a pointer to a node, do postorder traversal to delete all 
     * its children*/
    static void deleteAll(MultiNode* aNode);

};


#endif // DICTIONARY_TRIE_H
