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

class NaiveBayesClassifier {
public:
    
    NaiveBayesClassifier();
    NaiveBayesClassifier(const NaiveBayesClassifier& orig);
    NaiveBayesClassifier(std::map<std::string, std::pair<int, int> > vocabulary);
    virtual ~NaiveBayesClassifier();
    
private:
    std::map<std::string, std::pair<int, int> > vocabulary;
};

#endif /* NAIVEBAYESCLASSIFIER_H */

