/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NaiveBayesClassifier.cpp
 * Author: brgoo
 * 
 * Created on June 2, 2019, 2:26 PM
 */

#include "NaiveBayesClassifier.h"

NaiveBayesClassifier::NaiveBayesClassifier() {
    this->vocabulary = std::map<std::string, std::pair<int, int> >();
}

NaiveBayesClassifier::NaiveBayesClassifier(const NaiveBayesClassifier& orig) {
    this->vocabulary = orig.vocabulary;
}

NaiveBayesClassifier::NaiveBayesClassifier(std::map<std::string, std::pair<int, int> > vocab) {
    this->vocabulary = vocab;
}

NaiveBayesClassifier::~NaiveBayesClassifier() {
}

