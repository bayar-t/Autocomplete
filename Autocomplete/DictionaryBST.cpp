/*
 * Authors: Jamie Shi (A12678538) and Sergelenbayar Tsogtbaatar (A12949154)
 * Date: January 26, 2017
 * Overview: Methods to implement BST for dictionary with ordered set
 * Assignment #2
 * File Name: DictionaryBST.cpp
 */

#include "util.h"
#include "DictionaryBST.h"

/* Create a new Dictionary that uses a BST back end */
DictionaryBST::DictionaryBST(){
}

/* Insert a word into the dictionary. Return true if word (the input string)
 * was successfuly inserted, else return false. Only valid words (those only
 * containing chars a-z or space) can be inserted. */
bool DictionaryBST::insert(std::string word)
{
  // Check to not insert invalid words
  for (unsigned int i = 0; i < word.length(); i++) {
    char aChar = word.at(i);

    bool check = false;
    if (aChar == ' ' || (int(aChar) >= int('a') && int(aChar) <= int('z'))) {
      check = true;
    }
    // Current char not a space or a letter from a-z
    if(check == false) {
      return false;
    }
  }

  std::pair<std::set<std::string>::iterator,bool> bstPair;
  bstPair = bst.insert(word);
  return bstPair.second;
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryBST::find(std::string word) const
{
  std::set<std::string>::iterator it;
  it = bst.find(word);

  if (it == bst.end()) {
    return false;
  }
  else {
    return true;
  }

}

/* Destructor */
DictionaryBST::~DictionaryBST(){}
