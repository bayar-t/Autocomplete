/**
 *  CSE 100 PA2 C++ Autocomplete
 *  Authors: Jor-el Briones, Christine Alvarado
 */

/*
 * Authors: Jamie Shi (A12678538) and Sergelenbayar Tsogtbaatar (A12949154)
 * Date: January 26, 2017
 * Overview: Header for methods to implement BST for dictionary with ordered 
 * set
 * Assignment #2
 * File Name: DictionaryBST.h
 */

#ifndef DICTIONARY_BST_H
#define DICTIONARY_BST_H

#include <string>
#include <set>

/**
 *  The class for a dictionary ADT, implemented as a BST
 * When you implement this class, you MUST use a balanced binary
 * search tree in its implementation.  The C++ set implements 
 * a balanced BST, so we strongly suggest you use that to store 
 * the dictionary.
 */
class DictionaryBST
{
  public:
    /* Create a new Dictionary that uses a BST back end */
    DictionaryBST();

    /* Insert a word into the dictionary. Return true if word (the input
     * string) was successfuly inserted, else return false. Only valid words 
     * (those only containing chars a-z or space) can be inserted. */
    bool insert(std::string word);

    /* Return true if word is in the dictionary, and false otherwise */
    bool find(std::string word) const;

    /* Destructor */
    ~DictionaryBST();

  private:
    std::set<std::string> bst;

};

#endif // DICTIONARY_BST_H
