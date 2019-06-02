/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: Brad
 *
 * Created on May 14, 2019, 7:33 PM
 */

#include <cstdlib>
#include <iostream>
#include "WordBag.h"
#include "NaiveBayesClassifier.h"
#include <fstream>
#include <vector>
#include <map>

/*
 *
 */
int main(int argc, char** argv) {
    std::ifstream f;
    f.open("input.txt");
    std::string line;
    std::vector<WordBag> bags;
    while (!f.eof()) {
        std::getline(f, line);
        WordBag temp(line);
        temp.removeChars();
        temp.wordsToLower();
        bags.push_back(temp);
    }
    
    std::map<std::string, std::pair<int, int> > vocabulary;
    
    for(auto bag : bags){
        for(auto word : bag.getWordList())
        {
            if(vocabulary.count(word) == 0){
                std::pair<std::string, std::pair<int, int>> p;
                p.first = word;
                p.second = std::pair<int, int>();
                vocabulary.insert(p);
            }
            if(bag.getSentiment() == 1)
                vocabulary.at(word).first += 1;
            else
                vocabulary.at(word).second += 1;
        }
    }
    std::cout << "wordcount = " << vocabulary.size() << "\n";
    std::vector<std::string> vocab;
    for(auto word : vocabulary) {
        vocab.push_back(word.first);
    }
    
    std::vector<std::vector<bool>> output(bags.size());
    for(int i = 0; i < output.size(); i++)
    {
        output[i].resize(vocab.size() + 1);
        for(int j = 0; j < vocab.size(); j++) {
            if(bags[i].contains(vocab[j])) output[i][j] = true;
            else output[i][j] = false;
        }
        output[i].push_back((bool)bags[i].getSentiment());
    }
    
    std::ofstream outfile("outfile.txt");
    std::stringstream s;
    for(auto word : vocab) {
        s << word << ",";
    }
    std::string out = s.str();
    out = out.substr(0, out.length()-1);
    outfile << out << "\n\n";
    
    for(int i = 0; i < output.size(); i++) {
        for(int j = 0; j < output[i].size(); j++) {
            outfile << output[i][j]<<",";
        }
        outfile << bags[i].getSentiment() << "\n\n";
    }
    
    NaiveBayesClassifier classifier(vocabulary);
    
    
    std::cout << " WORKING\n";
    return 0;
}

