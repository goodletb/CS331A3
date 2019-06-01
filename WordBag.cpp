/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   WordBag.cpp
 * Author: Brad
 *
 * Created on May 14, 2019, 9:48 PM
 */

#include "WordBag.h"

WordBag::WordBag() {
}

WordBag::WordBag(const WordBag& orig) {
    this->originalString = orig.originalString;
    this->sentiment = orig.sentiment;
    this->words.reserve(orig.words.size());
    for (auto word : orig.words) {
        this->words.push_back(word);
    }
}

WordBag::WordBag(std::string startString) {
    this->originalString = startString;
    std::stringstream stream(startString);
    std::string word;
    while (stream >> word) {
        if (isdigit(word[0])) {
            this->sentiment = atoi(word.c_str());
        } else {
            this->words.push_back(word);
        }
    }
    this->sortWordList();
}

WordBag::~WordBag() {
}

void WordBag::printWords() {
    for (auto word : this->words) {
        std::cout << word << std::endl;
    }
}

void WordBag::sortWordList() {
    std::sort(this->words.begin(), this->words.end(), [](std::string x, std::string y) {
        return strcmp(x.c_str(), y.c_str()) <= 0 ? true : false;
    });
}

void WordBag::removeChars() {
    std::string charsToRemove = "\'\"!.,?";
    for (int i = 0; i < this->words.size(); i++) {
        for (char c : charsToRemove) {
            words[i].erase(std::remove(words[i].begin(), words[i].end(), c), words[i].end());
        }
    }
}

int WordBag::getSentiment() {
    return this->sentiment;
}
