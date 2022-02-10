//
// Created by Tudor on 7/7/2021.
//

#ifndef E3_912_CAMPEAN_TUDOR_ALEXANDRU_PLAYER_H
#define E3_912_CAMPEAN_TUDOR_ALEXANDRU_PLAYER_H

#include <iostream>

using namespace std;


class Player {

public:
    std::string name;

public:
    Player() = default;

    Player(const Player &p) = default;

    Player(string name)
    {
        this->name = name;
    }

    ~Player() = default;
    string getName()
    {
        return this->name;
    }
};

#endif //E3_912_CAMPEAN_TUDOR_ALEXANDRU_PLAYER_H
