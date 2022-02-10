//
// Created by Tudor on 7/7/2021.
//

#ifndef E3_912_CAMPEAN_TUDOR_ALEXANDRU_REPOSITORY_H
#define E3_912_CAMPEAN_TUDOR_ALEXANDRU_REPOSITORY_H

#include <vector>
#include "Player.h"
#include <fstream>

class Repository
{
public:
    vector<Player> players;
    int map[100][100];
    int dimension;
    int nrBombs;
public:
    Repository()
    {
        this->read();
        for(int i =0;i<dimension;i++)
            for(int j =0;j<dimension;j++)
                map[i][j] = -1;
        for(int i = 0;i<nrBombs;i++)
        {
            int x = rand()%dimension;
            int y = rand()%dimension;
            map[x][y] = 0;

        }

    }
    void addPlayer(Player p)
    {
        this->players.push_back(p);
    }

    void read()
    {
        ifstream f("D:\\GitHub\\e3-912-Campean-Tudor-Alexandru\\input.txt");
        f>>this->dimension;
        f>>nrBombs;
        string name;
        while(f>>name)
        {
            Player p{name};
            this->addPlayer(p);
        }
    }


};

#endif //E3_912_CAMPEAN_TUDOR_ALEXANDRU_REPOSITORY_H
