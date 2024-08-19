#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool issamesuit(string card1, string card2){
    return card1[1] == card2[1];
}

int main(){

    unordered_map<string, int> rankValues = {
            {"2", 2}, {"3", 3}, {"4", 4}, {"5", 5}, {"6", 6},
            {"7", 7}, {"8", 8}, {"9", 9}, {"10", 10},
            {"J", 11}, {"Q", 12}, {"K", 13}, {"A", 14}
        };

    int card1 = 12;
    string suit1 = "Diamond";
    int card2 = 7;
    string suit2 = "Spade";
    string highestRankCard;
    int highestRank;
    for (const auto& pair : rankValues) {
        if (pair.second > card1) {
            highestRank = pair.second;
            highestRankCard = pair.first;
        }
    }

    cout << "Highest rank value: " << highestRank << " " << highestRankCard << " of " <<suit1<<endl;

    if(issamesuit(suit1,suit2)) cout<< "Same suit" << endl;

    else cout<< "Not same suit" << endl;

    return 0;
}