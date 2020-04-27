/*
 * Authors: Jamie Shi (A12678538) and Sergelenbayar Tsogtbaatar (A12949154)
 * Date: January 26, 2017
 * Overview: Methods to implement hash table for dictionary with unordered set
 * Assignment #2
 * File Name: DictionaryHashtable.cpp
 */

#include "util.h"
#include "DictionaryHashtable.h"

/* Create a new Dictionary that uses a Hashset back end */
DictionaryHashtable::DictionaryHashtable(){}

/* Insert a word into the dictionary. Return true if word (the input 
 * string) was successfuly inserted, else return false. Only valid words 
 * (those only containing chars a-z or space) can be inserted. */
bool DictionaryHashtable::insert(std::string word)
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

  auto hashPair = hash.insert(word);
  return hashPair.second; 
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryHashtable::find(std::string word) const
{
  std::unordered_set<std::string>::const_iterator it;
  it = hash.find(word);

  if (it == hash.end()) {
    return false;
  }
  else {
    return true;
  }
}

/* Destructor */
DictionaryHashtable::~DictionaryHashtable(){}
