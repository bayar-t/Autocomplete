/*
 * Authors: Jamie Shi (A12678538) and Sergelenbayar Tsogtbaatar (A12949154)
 * Date: January 26, 2017
 * Overview: Contains methods to implement MWT for dictionary
 * Assignment #2
 * File Name: DictionaryTrie.cpp
 */

#include "util.h"
#include "DictionaryTrie.h"

/* Create a new Dictionary that uses a Trie back end */
DictionaryTrie::DictionaryTrie(){
  root = NULL;
}

MultiNode::MultiNode(){
  for(int i = 0; i < NUM_VALID; i++) {
    children[i] = NULL;
  }
}
/*
 * Given a char, convert it to a number that represents its index in the Node's
 * children array. Return that number.
 * Example: input 'a' returns 0, input 'b' returns 1, input 'c' returns 2
 * More examples: input 'y' returns 24, input 'z' returns 25
 * Exception: input ' ' returns 26 (last index in the array)
 * Input chars that are not spaces or letters from a-z return -1
 */
int DictionaryTrie::charToNum(char character) const {
  if (character == ' ') {
    return NUM_VALID-1;
  }
  // Input char not a space or a letter from a-z
  else if (int(character) < int('a') || int(character) > int('z')) {
    return -1;
  }
  else {
    return int(character) - int('a');
  }
}

/* Insert a word with its frequency into the dictionary.
 * Return true if the word was inserted, and false if it
 * was not (i.e. it was already in the dictionary or it was
 * invalid (empty string) */
bool DictionaryTrie::insert(std::string word, unsigned int freq)
{
  // Edge case: can't insert empty word
  if (word == "") {
    return false;
  }

  // Edge case: inserting a word into an empty trie
  if (root == NULL) {
    root = new MultiNode();
  }

  MultiNode* curr = root;

  // Iterate through all letters in word, and traverse the MWT
  for (unsigned int i = 0; i < word.length(); i++) {
    int charIndex = charToNum(word.at(i));
    if (charIndex == -1) {
      return false; // Can't insert invalid word
    }
    if (curr->children[charIndex] == NULL) {
      curr->children[charIndex] = new MultiNode();
      std::string currWord = curr->theWord;
      //std::string currLetter = std::string(word.at(i));

      char currLetter = word.at(i);
      currWord += currLetter;

      std::string nextWord = currWord; //currWord.append(currLetter);
      curr->children[charIndex]->theWord = nextWord;
    }
    curr = curr->children[charIndex];
  }
  MultiNode* test = root;
  for(unsigned int i = 0; i < word.length(); i++){
    int charIndex = charToNum(word.at(i));
    if(test->children[charIndex] != NULL){
    /////////////////////  std::cout << "the curr word is: " << test->theWord << std::endl;
      test = test->children[charIndex];
    }
  }
 ////////////////////// std::cout << "the word is: " << test->theWord << std::endl;
  // Don't insert duplicate word
  if (curr->word == true) {
    /* Uncomment cout calls below to test frequency manually */
    //std::cout << "\nfreq to add: " << freq << "\ncurrent freq: ";
    //std::cout << curr->theFrequency << std::endl;

    // Update frquency to larger frequency if necessary
    if (freq > curr->theFrequency) {
      curr->theFrequency = freq;
    }
    //std::cout << "freq after: " << curr->theFrequency << std::endl;

    return false;
  }
  else {
    /* Uncomment cout calls below to test frequency manually */
    //std::cout << "\nfreq to add: " << freq << "\ncurrent freq: ";
    //std::cout << curr->theFrequency << std::endl;

    // Update the frequency to larger frequency if necessary
    if (freq > curr->theFrequency) {
      curr->theFrequency = freq;
    }
    //std::cout<< "freq after: " << curr->theFrequency << std::endl;

    curr->word = true;
  }

  return true;
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryTrie::find(std::string word) const 
{
  if (word == "") {
    return false;
  }

  MultiNode* curr = root;

  // Iterate through all letters in word, and traverse the MWT
  for (unsigned int i = 0; i < word.length(); i++) {

    int charIndex = charToNum(word.at(i));

    if (charIndex == -1) return false; // No invalid words should be in MWT
    if (curr->children[charIndex] == NULL) {
      return false;
    }
    curr = curr->children[charIndex];
  }
  // Word should be marked as in the MWT
  if (!curr->word) {
    return false;
  }
  else {
    return true;
  }

}

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
std::vector<std::string> DictionaryTrie::predictCompletions(std::string prefix, 
unsigned int num_completions)
{
  std::vector<std::string> words;

  // If prefix is empty, return empty vector
  if (prefix == "") {
    std::cout << "Invalid Input. Please retry with correct input" << std::endl;
    return words;
  }
  if(num_completions < 0){
    std::cout << "Invalid Input. Please retry with correct input" << std::endl;
    return words;
  }


  MultiNode* curr = root;

  // Find the node with the child that stores the last char in the prefix
  for (unsigned int i = 0; i < prefix.length(); i++) {
    int charIndex = charToNum(prefix.at(i));

    // Invalid input (prefix has characters that aren't spaces or letters a-z)
    if (charIndex == -1) {
      std::cout << "Invalid Input. Please retry with correct input"; 
      std::cout << std::endl;
      return words;
    }

    // Prefix is not in the dictionary trie
    if (curr->children[charIndex] == NULL) {
      std::cout << "Prefix is not in the dictionary trie"; 
      std::cout << std::endl;
      return words;
    }

    curr = curr->children[charIndex];
  }

  std::set<std::pair<int, std::string>> pWords;
  std::pair<int, std::string> pWord;
  std::stack<MultiNode*> theStack;
  theStack.push(curr);

  while (!theStack.empty()) {
    MultiNode* temp = theStack.top();
    theStack.pop();

    // If word is true, add word along with its frequency into the set
    if (temp->word) {
      pWords.insert(make_pair(temp->theFrequency, temp->theWord));
    }

    // For each of curr node's children, n, push n onto the stack
    for (int i=0; i<27; i++) {
      if (temp->children[i] != NULL) {
        theStack.push(temp->children[i]);
      }
    }

  } // End while loop

  // Now pWords stores all the possible words along with their frequencies
  for (std::set<std::pair<int, std::string>>::reverse_iterator rit = pWords.rbegin(); 
      rit != pWords.rend(); rit++) {
    if (num_completions-- == 0) {
      return words;
    }
    // Push the word into the words vector
    words.push_back(rit->second);
  }

  return words;
}

/*
  // If prefix is a word, then push it and its frequency to pWords vector
  if(curr->word == true){
    pWords.push_back(make_pair(prefix, curr->theFrequency));
  }

  while(theStack.empty() == false){
    std::string suffix;
    MultiNode* temp = theStack.top();
    theStack.pop();

    for (int i = 0; i < 27; i++) {
      if (temp->children[i] != NULL) {
        theStack.push(temp->children[i]);
        if (currNode->word == true) {
          pWords.push_back(make_pair(temp->children[i]->theWord, temp->children[i]->theFrequency);
        }


       if(temp->children[i]->word == true){
        for(int k = 0; k < theStack.size(); i++){
          MultiNode* currNode = theStack.top();
          theStack.pop();
          if(currNode->word == true){
            pWords.push_back(make_pair(temp->children[i]->theWord,
              temp->children[i]->theFrequency);
          }
        }

        //check if word exists already in possible words
          
       }
       temp = temp->children[i];
      }
    }

  }
  return words;*/

/* Given a pointer to a node, delete all of that node's children*/
void DictionaryTrie::deleteAll(MultiNode* aNode) {
  for (int i=0; i<NUM_VALID; i++) {
    if (aNode->children[i]) {
      deleteAll(aNode->children[i]);
      delete(aNode->children[i]);
    }
  }

}

/* Destructor */
DictionaryTrie::~DictionaryTrie(){
  if (root) {
    deleteAll(root);
    delete(root);
  }
}
