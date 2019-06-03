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

NaiveBayesClassifier::NaiveBayesClassifier() = delete;

NaiveBayesClassifier::NaiveBayesClassifier(const NaiveBayesClassifier& orig) {
    this->vocabulary = orig.vocabulary;
    this->pSentenceCount = orig.pSentenceCount;
    this->tSentenceCount = orig.tSentenceCount;
    this->probDistribution = orig.probDistribution;
}

NaiveBayesClassifier::NaiveBayesClassifier(std::map<std::string, std::pair<int, int> > vocab, int pCount, int tCount) {
    this->vocabulary = vocab;
    this->pSentenceCount = pCount;
    this->tSentenceCount = tCount;
}

NaiveBayesClassifier::~NaiveBayesClassifier() {
}

void NaiveBayesClassifier::TrainClassifier() {
    for(auto word = this->vocabulary.begin(); word != this->vocabulary.end(); ++word) {
        std::vector<float> probs(4);
        float pEx = word->second.first;
        float nEx = word->second.second;
        float pNex = this->pSentenceCount - word->second.first;
        float nNex = (this->tSentenceCount - this->pSentenceCount) - word->second.second;
        
        probs[0] = (nNex + 1) / (this->tSentenceCount - this->pSentenceCount + 2);
        probs[1] = (nEx + 1) / (this->tSentenceCount - this->pSentenceCount + 2);
        probs[2] = (pNex + 1) / (this->pSentenceCount + 2);
        probs[3] = (pEx + 1) / (this->pSentenceCount + 2);
        std::pair<std::string, std::vector<float> > keyval;
        keyval.first = word->first;
        keyval.second = probs;
        this->probDistribution.insert(keyval);
    }
}

bool NaiveBayesClassifier::predictSentence(WordBag bag) {
    float posChance = std::log(float((float)this->pSentenceCount / (float)this->tSentenceCount));
    float negChance = std::log((float)((float)this->tSentenceCount - (float)this->pSentenceCount) / (float)this->tSentenceCount);
    for(auto word = this->vocabulary.begin(); word != this->vocabulary.end(); ++word) {
        if(bag.contains(word->first)) {
            posChance += std::log(this->probDistribution[word->first][3]);
            negChance += std::log(this->probDistribution[word->first][1]);
        }
        else {
            posChance += std::log(this->probDistribution[word->first][2]);
            negChance += std::log(this->probDistribution[word->first][0]);
        }
    }
    return posChance > negChance ? true : false;
}
