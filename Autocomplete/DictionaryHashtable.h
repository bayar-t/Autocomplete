/**
 *  CSE 100 PA2 C++ Autocomplete
 *  Authors: Jor-el Briones, Christine Alvarado
 */

/*
 * Authors: Jamie Shi (A12678538) and Sergelenbayar Tsogtbaatar (A12949154)
 * Date: January 26, 2017
 * Overview: Headers for methods to implement hash table for dictionary with 
 * unordered set
 * Assignment #2
 * File Name: DictionaryHashtable.h
 */

#ifndef DICTIONARY_HASHTABLE_H
#define DICTIONARY_HASHTABLE_H

#include <string>
#include <unordered_set>

/**
 *  The class for a dictionary ADT, implemented as a Hashtable
 * When you implement this class, you MUST use a Hashtable
 * in its implementation.  The C++ unordered_set implements 
 * a Hashtable, so we strongly suggest you use that to store 
 * the dictionary.
 */
class DictionaryHashtable
{
  public:
    /* Create a new Dictionary that uses a Hashset back end */
    DictionaryHashtable();

    /* Insert a word into the dictionary. Return true if word (the input 
     * string) was successfuly inserted, else return false. Only valid words 
     * (those only containing chars a-z or space) can be inserted. */
    bool insert(std::string word);

    /* Return true if word is in the dictionary, and false otherwise */
    bool find(std::string word) const;

    /* Destructor */
    ~DictionaryHashtable();

  private:
    std::unordered_set<std::string> hash;
};

#endif // DICTIONARY_HASHTABLE_H
