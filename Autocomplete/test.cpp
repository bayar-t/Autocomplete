/*
 * Authors: Jamie Shi (A12678538) and Sergelenbayar Tsogtbaatar (A12949154)
 * Date: January 26, 2017
 * Overview: Test methods for DictionaryBST, DictionaryHashtable, and 
 * DictionaryTrie
 * Assignment #2
 * File Name: test.cpp
 */

#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<set>
#include<cstdlib>
#include "util.h"
#include "DictionaryTrie.h"
#include "DictionaryBST.h"
#include "DictionaryHashtable.h"
#define LETTERS 26
using namespace std;

/* This tests the methods for the implemented BST, hash table and trie */
int main(int argc, char** argv)
{

  //Initialize words
  vector<std::string> words;
  vector<std::string> words1;
  vector<std::string> words15;

  vector<string>::iterator wit;
  vector<string>::iterator wen;

  vector<string>::iterator wit15;
  vector<string>::iterator wen15;

  //initialize nonwords
  vector<string> nope;
  vector<string>::iterator nit;
  vector<string>::iterator nen;

  //Initialize data structures
  DictionaryBST d_bst;
  DictionaryHashtable d_ht;
  DictionaryTrie dt;

  DictionaryBST d_bst15;
  DictionaryHashtable d_ht15;
  DictionaryTrie dt15;

  int t_bst, t_ht, tt;
  int t_bst15, t_ht15, tt15;

  words.push_back("harry");

  words15.push_back("sriram");
  words15.push_back("cse");
  words15.push_back("crucio");
  words15.push_back("autocomplete");
  words15.push_back("cse a");
  words15.push_back(" hello");
  words15.push_back("     ");
  words15.push_back("space ");
  words15.push_back("star  ");
  words15.push_back("  zebra");
  words15.push_back("computer screen ");
  words15.push_back("mouse");
  words15.push_back("superb");
  words15.push_back("abcdefghijklmnopqrstuvwxyz");
  words15.push_back("aabbccddeeffghijkklmnopqrstuvwxyzz ");

  nope.push_back("Abc");
  nope.push_back("CSE100");
  nope.push_back("asdfjLK");
  nope.push_back("California");
  nope.push_back("asdfF");
  nope.push_back("hsdfui*");
  nope.push_back("starR");
  nope.push_back("cse12a");
  nope.push_back("siodaffFdhf");
  nope.push_back("gvfura8et&*Fsdf");

/*  nit = nope.begin();
  nen = nope.end();

  cout << "Inserting into Dictionaries with single word..." << endl;

  wit = words.begin();
  wen = words.end();
  for(; wit != wen; ++wit)
  {
    cout << "Inserting: \"" << *wit << "\"... ";
    t_bst = d_bst.insert(*wit);
    t_ht = d_ht.insert(*wit);
    tt = dt.insert(*wit, 2);
    if(!t_bst)
    {
      cout << "failed for DictionaryBST... \n";
      return -1;
    }
    if(!t_ht)
    {
      cout << "failed for DictionaryHashset... \n";
      return -1;
    }
    if(!tt)
    {
      cout << "failed for DictionaryTrie... \n";
      return -1;
    }
    if(t_bst && t_ht && tt)
    {
      cout << "PASSED! :D \n";
    }
    cout << endl;
  }

  cout << endl << "Re-inserting elements that were just inserted into ";
  cout << "Dictionaries..." << endl;

  wit = words.begin();
  wen = words.end();
  for(; wit != wen; ++wit)
  {
    cout << "Inserting: \"" << *wit << "\"... ";
    t_bst = d_bst.insert(*wit);
    t_ht = d_ht.insert(*wit);
    tt = dt.insert(*wit, 180);
    if(t_bst)
    {
      cout << "failed for DictionaryBST... \n";
      return -1;
    }
    if(t_ht)
    {
      cout << "failed for DictionaryHashset... \n";
      return -1;
    }
    if(tt)
    {
      cout << "failed for DictionaryTrie... \n";
      return -1;
    }
    if(!t_bst && !t_ht && !tt)
    {
      cout << "PASSED! :D \n";
    }
    cout << endl;
  }

  cout << endl;


  cout << "Inserting into Dictionaries with fifteen words..." << endl;

  wit15 = words15.begin();
  wen15 = words15.end();
  for(; wit15 != wen15; ++wit15)
  {
    cout << "Inserting: \"" << *wit15 << "\"... ";
    t_bst15 = d_bst15.insert(*wit15);
    t_ht15 = d_ht15.insert(*wit15);
    tt15 = dt15.insert(*wit15, 50);
    if(!t_bst15)
    {
      cout << "failed for DictionaryBST... \n";
      return -1;
    }
    if(!t_ht15)
    {
      cout << "failed for DictionaryHashset... \n";
      return -1;
    }
    if(!tt15)
    {
      cout << "failed for DictionaryTrie... \n";

  cout << endl << "Re-inserting elements that were just inserted into ";
  cout << "Dictionaries..." << endl;

  wit15 = words15.begin();
  wen15 = words15.end();
  for(; wit15 != wen15; ++wit15)
  {
    cout << "Inserting: \"" << *wit15 << "\"... ";
    t_bst15 = d_bst15.insert(*wit15);
    t_ht15 = d_ht15.insert(*wit15);
    tt15 = dt15.insert(*wit15, 40);
    if(t_bst15)
    {
      cout << "failed for DictionaryBST... \n";
      return -1;
    }
    if(t_ht15)
    {
      cout << "failed for DictionaryHashset... \n";
      return -1;
    }
    if(tt15)
    {
      cout << "failed for DictionaryTrie... \n";
      return -1;
    }
    if(!t_bst15 && !t_ht15 && !tt15)
    {
      cout << "PASSED! :D \n";
    }
    cout << endl;
  }

  cout << endl;

  //Tests for invalid word insertion
  cout << "Inserting invalid words into Dictionaries..." << endl;
  for(; nit != nen; ++nit){
    t_bst = d_bst.insert(*nit);
    t_ht = d_ht.insert(*nit);
    tt = dt.insert(*nit, 0);
    if(t_bst == 1){
      cout<< "Failed, inserted invalid word: " << *nit << " to BST" << endl;
      return -1;
    }
    if(t_ht == 1){
      cout<< "Failed, inserted invalid word: " << *nit << " to HT" << endl;
      return -1;
    }
    if(tt == 1){
      cout << "Failed, inserted invalid word: " << *nit << " to MWT" << endl;
      return -1;
    }
  }

  cout << "Passed special character insertion cases\n\n";

  cout << "Finding elements in Dictionaries..." << endl; 

  // Iterators
  wit15 = words15.begin();
  wen15 = words15.end();
  wit = words.begin();
  wen = words.end();

  for(;wit15 != wen15; ++wit15){
    bool check = dt15.find(*wit15);
    bool check1 = d_ht15.find(*wit15);
    bool check2 = d_bst15.find(*wit15);
    if(check == false){
      cout<< "Word: "<< *wit15<< " was not found in 15 word Trie" << endl;
      return -1;
    }
    if(check1 == false){
      cout << "Word: " << *wit15<< " was not found in 15 word HT" << endl;
      return -1;
    }
    if(check2 == false){
      cout << "Word: " << *wit15<< " was not found in 15 word BST" << endl;
      return -1;
    }
  }
  for(; wit != wen; ++wit){
    bool check = dt.find(*wit);
    bool check1 = d_ht.find(*wit);
    bool check2 = d_bst.find(*wit);
    if(check == false){
      cout<< "Word: " << *wit << " was not found in one word Trie" << endl;
      return -1;
    }
    if(check1 == false){
      cout << "Word: " << *wit<< " was not found in one word HT" << endl;
      return -1;
    }
    if(check2 == false){
      cout << "Word: " << *wit<< " was not found in one word BST" << endl;
      return -1;
    }

  }

  cout << "Passed find function test\n" << endl;
*/



/*

  // Uncomment to test using dictionaries
 
      return -1;
    }
    if(t_bst15 && t_ht15 && tt15)
    {
      cout << "PASSED! :D \n";
    }
    cout << endl;
  }

  cout << endl << "Re-inserting elements that were just inserted into ";
  cout << "Dictionaries..." << endl;

  wit15 = words15.begin();
  wen15 = words15.end();
  for(; wit15 != wen15; ++wit15)
  {
    cout << "Inserting: \"" << *wit15 << "\"... ";
    t_bst15 = d_bst15.insert(*wit15);
    t_ht15 = d_ht15.insert(*wit15);
    tt15 = dt15.insert(*wit15, 40);
    if(t_bst15)
    {
      cout << "failed for DictionaryBST... \n";
      return -1;
    }
    if(t_ht15)
    {
      cout << "failed for DictionaryHashset... \n";
      return -1;
    }
    if(tt15)
    {
      cout << "failed for DictionaryTrie... \n";
      return -1;
    }
    if(!t_bst15 && !t_ht15 && !tt15)
    {
      cout << "PASSED! :D \n";
    }
    cout << endl;
  }

  cout << endl;

  //Tests for invalid word insertion
  cout << "Inserting invalid words into Dictionaries..." << endl;
  for(; nit != nen; ++nit){
    t_bst = d_bst.insert(*nit);
    t_ht = d_ht.insert(*nit);
    tt = dt.insert(*nit, 0);
    if(t_bst == 1){
      cout<< "Failed, inserted invalid word: " << *nit << " to BST" << endl;
      return -1;
    }
    if(t_ht == 1){
      cout<< "Failed, inserted invalid word: " << *nit << " to HT" << endl;
      return -1;
    }
    if(tt == 1){
      cout << "Failed, inserted invalid word: " << *nit << " to MWT" << endl;
      return -1;
    }
  }

  cout << "Passed special character insertion cases\n\n";

  cout << "Finding elements in Dictionaries..." << endl; 

  // Iterators
  wit15 = words15.begin();
  wen15 = words15.end();
  wit = words.begin();
  wen = words.end();

  for(;wit15 != wen15; ++wit15){
    bool check = dt15.find(*wit15);
    bool check1 = d_ht15.find(*wit15);
    bool check2 = d_bst15.find(*wit15);
    if(check == false){
      cout<< "Word: "<< *wit15<< " was not found in 15 word Trie" << endl;
      return -1;
    }
    if(check1 == false){
      cout << "Word: " << *wit15<< " was not found in 15 word HT" << endl;
      return -1;
    }
    if(check2 == false){
      cout << "Word: " << *wit15<< " was not found in 15 word BST" << endl;
      return -1;
    }
  }
  for(; wit != wen; ++wit){
    bool check = dt.find(*wit);
    bool check1 = d_ht.find(*wit);
    bool check2 = d_bst.find(*wit);
    if(check == false){
      cout<< "Word: " << *wit << " was not found in one word Trie" << endl;
      return -1;
    }
    if(check1 == false){
      cout << "Word: " << *wit<< " was not found in one word HT" << endl;
      return -1;
    }
    if(check2 == false){
      cout << "Word: " << *wit<< " was not found in one word BST" << endl;
      return -1;
    }

  }

  cout << "Passed find function test\n" << endl;
*/





  // Uncomment to test using dictionaries
  /*
     std::ifstream aBstStream;
     std::ifstream bBstStream;
     std::ifstream aTrieStream;
     std::ifstream bTrieStream;
    return false; // No invalid words should be in MWT
     std::ifstream aHashStream;
     std::ifstream bHashStream;

  // Change absolute paths below to test loading dictionaries using util.cpp

  aBstStream.open("/home/linux/ieng6/cs100w/public/pa2/dictionary/freq_dict.txt");
  bBstStream.open("/home/linux/ieng6/cs100w/public/pa2/dictionary/freq_dict.txt");
  aTrieStream.open("/home/linux/ieng6/cs100w/public/pa2/dictionary/freq_dict.txt");
  bTrieStream.open("/home/linux/ieng6/cs100w/public/pa2/dictionary/freq_dict.txt");
  aHashStream.open("/home/linux/ieng6/cs100w/public/pa2/dictionary/freq_dict.txt");
  bHashStream.open("/home/linux/ieng6/cs100w/public/pa2/dictionary/freq_dict.txt");

  DictionaryTrie trieTester;
  DictionaryHashtable hashTester;
  DictionaryBST bstTester;

  vector<std::string> bstWords;
  vector<std::string> trieWords;
  vector<std::string> hashWords;

  Utils::load_vector(hashWords, aHashStream);
  Utils::load_dict(hashTester, bHashStream);

  Utils::load_vector(bstWords, aBstStream);
  Utils::load_dict(bstTester, bBstStream);

  Utils::load_vector(trieWords, aTrieStream);
  Utils::load_dict(trieTester, bTrieStream);

  vector<std::string>::iterator hashStart = hashWords.begin();
  vector<std::string>::iterator hashEnd = hashWords.end();

  vector<std::string>::iterator itStart = bstWords.begin();
  vector<std::string>::iterator itEnd = bstWords.end();

  vector<std::string>::iterator trieStart = trieWords.begin();
  vector<std::string>::iterator trieEnd = trieWords.end();

  cout << "Testing BST's insert and find methods using an entire dictionary\n";
  for(; itStart != itEnd; ++itStart){
  if(bstTester.find(*itStart) == false) {
  cout << "word: " << *itStart << " was not found in BST" << endl;
  }
  }
  cout << "Passed comprehensive tests for BST's insert and find methods\n";


  cout << "Testing hash table's insert and find methods using an entire "; 
  cout << "dictionary\n";
  for(; hashStart != hashEnd; ++hashStart){
  if(hashTester.find(*hashStart) == false){
  cout << "word: " << *hashStart << " was not found in hash" << endl;
  }
  }
  cout << "Passed comprehensive tests for hash table's insert and find ";
  cout << "methods";

  cout << "Testing tries's insert and find methods using an entire "; 
  cout << "dictionary\n";
  for(; trieStart != trieEnd; ++trieStart){
  if(trieTester.find(*trieStart) == false){
  cout << "word: " << *trieStart << " was not found in trie" << endl;
  }
  }
  cout << "Passed comprehensive tests for trie's insert and find methods\n";
  */
 
  DictionaryTrie testAutocomplete;
  std::vector<std::string> autocompleteVec;
  std::vector<std::string> topFive;
  
  testAutocomplete.insert("abc", 0);
  testAutocomplete.insert("jack", 5);
  testAutocomplete.insert("abcd", 12);
  testAutocomplete.insert("abc", 10);
  testAutocomplete.insert("xyz", 5);
  testAutocomplete.insert("ab c", 90);
  testAutocomplete.insert("ag re c", 933);
  testAutocomplete.insert("axy", 10);
  testAutocomplete.insert("abcde", 3);
  testAutocomplete.insert("abcdef", 0);

  topFive.push_back("ab c");   // Frequency 90
  topFive.push_back("abcd");   // Frequency 12
  topFive.push_back("abc");    // Frequency 10
  topFive.push_back("abcde");  // Frequency 3
  topFive.push_back("abcdef"); // Frequency 0

  autocompleteVec = testAutocomplete.predictCompletions("ab", 5);
  if (autocompleteVec.size() != 5) {
    cout << "numCompletions is wrong; expected 5 elems, got " <<
    autocompleteVec.size() << "\n";
  }

  for(unsigned int i=0; i<autocompleteVec.size(); i++){
    if (topFive.at(i) != autocompleteVec.at(i)){
      cout << "Invalid autoComplete, words: " << autocompleteVec.at(i) << ", "
      << topFive.at(i) << " are not the same" << endl;
    }
  }

  cout << "Passed all tests\n";

  return 0;
}
