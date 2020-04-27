/*
 * Authors: Jamie Shi (A12678538) and Sergelenbayar Tsogtbaatar (A12949154)
 * Date: February 8, 2017
 * Overview: Benchmarks the dictionary BST, dictionary HT, and dictionary trie
 * Assignment #2
 * File Name: benchdict.cpp
 */

#include <iostream>
#include <fstream>
#include <string>
#include "util.h"
#include "DictionaryTrie.h"
#include "DictionaryBST.h"
#include "DictionaryHashtable.h"
using namespace std;

int main(int argc, char** argv)
{
  if(argc < 4){
    cout << "Not enough arguments as input. Expected 4, got " << argc << endl;
    return 0;
  }

  int min_size = atoi(argv[1]);
  int step_size = atoi(argv[2]);
  int num_iterations = atoi(argv[3]);
  string dictBST = argv[4];
  int iterations = 2000;
  // Edge case: print warning message if fewer than min_size+i*step_size
  // words in the file
  std::vector<std::string> sizeVector;
  std::ifstream stream;
  stream.open(dictBST);
  if(!stream.is_open()){
    cout << "Invalid dictionary. " << endl;
  }

  unsigned int numWords = 0;
  std::string tempString;
  while(std::getline(stream, tempString)){
    numWords++;
  }
  cout << "num words: " << numWords << endl;
  stream.clear();
  stream.seekg(0, std::ios::beg);
  string s = argv[4];
  cout<< "Benchmarking DictionaryBST class" << endl;
  for(int i = 0; i < num_iterations; i++){
    DictionaryBST* dictionary = new DictionaryBST();
    std::vector<std::string> bstVector;
    // Reset istream
    stream.seekg(0, std::ios::beg);
    unsigned int theSize = min_size + i*step_size;
    if(numWords < theSize){
      cout << "Error. Low amount of words in dictionary" << endl;
    }
    Utils::load_dict(*dictionary, stream, theSize);
    Utils::load_vector(bstVector,stream, 100);
    Timer t;
    t.begin_timer();
    for(int numIterations = 0; numIterations<iterations; numIterations++){
      for(unsigned int k = 0; k < bstVector.size(); k++){
        if(dictionary->find(bstVector.at(k)) == true){ 
          cout << "Invalid, should not find anything" << endl;
        }
      }
    }
    long long time = t.end_timer();
    time = time/iterations;
    cout << (min_size + (i*step_size)) << "\t" << time << endl;

    delete(dictionary);
  }

}

