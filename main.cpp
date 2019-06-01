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
#include <fstream>
#include <vector>

using namespace std;

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
        bags.push_back(temp);
    }

    for (auto bag : bags) {
        bag.removeChars();
        bag.printWords();
    }

    return 0;
}

