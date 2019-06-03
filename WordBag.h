/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   WordBag.h
 * Author: Brad
 *
 * Created on May 14, 2019, 9:48 PM
 */

#ifndef WORDBAG_H
#define WORDBAG_H

#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <sstream>
#include <cctype>
#include <algorithm>

class WordBag {
public:
    WordBag();
    WordBag(const WordBag& orig);
    WordBag(std::string startString);
    virtual ~WordBag();
    
    void printWords();
    void sortWordList();
    void removeChars();
    void wordsToLower();
    void removeDuplicates();
    int getSentiment();
    int getWordCount();
    bool contains(std::string Word);
    std::vector<std::string>& getWordList();
    
private:
    std::string originalString;
    std::vector<std::string> words;
    int sentiment;
};

#endif /* WORDBAG_H */

