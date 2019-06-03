/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NaiveBayesClassifier.h
 * Author: brgoo
 *
 * Created on June 2, 2019, 2:26 PM
 */

#ifndef NAIVEBAYESCLASSIFIER_H
#define NAIVEBAYESCLASSIFIER_H

#include<map>
#include "WordBag.h"
#include <cmath>

class NaiveBayesClassifier {
public:
    
    NaiveBayesClassifier();
    NaiveBayesClassifier(const NaiveBayesClassifier& orig);
    NaiveBayesClassifier(std::map<std::string, std::pair<int, int> > vocabulary, int pCount, int tCount);
    virtual ~NaiveBayesClassifier();
    
    void TrainClassifier();
    bool predictSentence(std::vector<bool> data);
private:
    std::map<std::string, std::pair<int, int> > vocabulary;
    std::vector<std::vector<bool> > data;
    
    int pSentenceCount;
    int tSentenceCount;
    
    std::map<std::string, std::vector<float> > probDistribution;
};

#endif /* NAIVEBAYESCLASSIFIER_H */
//
//if(bag.getSentiment() == 1)
//            {
//                if(bag.contains(word->first))
//                {
//                    pEx++;
//                }
//                else
//                {
//                    pNex++;
//                }
//            }
//            else
//            {
//                if(bag.contains(word->first))
//                {
//                    nEx++;
//                }
//                else
//                {
//                    nNex++;
//                }
//            }