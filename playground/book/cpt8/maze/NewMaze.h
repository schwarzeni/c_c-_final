#include <random>

//
// Created by schwarzeni on 2019-03-10.
//

#ifndef PLAYGROUND_NEWMAZE_H
#define PLAYGROUND_NEWMAZE_H

#include <assert.h>
#include <iostream>
#include <fstream>

namespace cpt8_maze {


    class NewMaze {
    public:
        NewMaze(int R, int C) : R(R), C(R) {
            assert(R % 2 != 0 && C % 2 != 0);

            this->startX = 0;
            this->startY = 1;
            this->endX = R - 1;
            this->endY = C - 2;

            // 初始化
            this->maze = new char *[this->R];
            this->isVisited = new bool *[this->R];

            this->init();

        }

        void printMaze() {
            for (int i = 0; i < this->R; i++) {
                for (int j = 0; j < this->C; j++) {
                    std::cout << this->maze[i][j];
                }
                std::cout << std::endl;
            }
        }

        // 深度优先生产法
        void DFS() {
            this->init();
            this->DFS_(this->startX + 1, this->startY);
            this->save();
        }

        // 点是否可以前往
        bool canGo(int x, int y) {
            return this->isValid(x, y) && !this->isVisited[x][y];
        }

        // 点是否合法
        bool isValid(int x, int y) {
            return x >= 0 && x < this->R && y >= 0 && y < this->C;
        }

        void init() {
            // WARN: 对相关参数进行判断
            for (int i = 0; i < this->R; i++) {
                this->maze[i] = new char[this->C];
                this->isVisited[i] = new bool[this->C];
                for (int j = 0; j < this->C; j++) {
                    if (i % 2 != 0 && j % 2 != 0) {
                        this->maze[i][j] = this->pathIcon;
                    } else {
                        this->maze[i][j] = this->barrierIcon;
                    }
                    this->isVisited[i][j] = false;
                }
            }

            // 设置入口和出口
            this->maze[1][0] = this->directionIcon;
            this->maze[this->R - 2][this->C - 1] = this->directionIcon;
        }

        void save() {
            std::ofstream outfile(this->filename, std::ios_base::ate);
            for (int i = 0; i < this->R; i++) {
                for (int j = 0; j < this->C; j++) {
                    outfile << this->maze[i][j];
                }
                outfile << '\n';
            }
            outfile.close();
        }


    private:
        // 行
        int R;
        // 列
        int C;
        // path
        char pathIcon = ' ';
        // wall
        char barrierIcon = '*';
        char directionIcon = ' ';
        // 迷宫
        char **maze;
        // direction
        int direction[4][2] = {{-1, 0},
                               {1,  0},
                               {0,  -1},
                               {0,  1}};

        std::string filename = "maze.txt";

        // 是否已经访问过
        bool **isVisited;

        int startX;
        int startY;
        int endX;
        int endY;

        bool DFS_(int x, int y) {
            if (this->canGo(x, y)) {
                this->isVisited[x][y] = true;
                int idxs[] = {0, 1, 2, 3};
                std::shuffle(std::begin(idxs), std::end(idxs), std::mt19937(std::random_device()()));
                for (int i : idxs) {
                    int nextX = x + this->direction[i][0] * 2;
                    int nextY = y + this->direction[i][1] * 2;
                    if (DFS_(nextX, nextY)) {
                        this->maze[x + this->direction[i][0]][y + this->direction[i][1]] = this->pathIcon;
                    }
                }
                return true;
            } else {
                return false;
            }
        }
    };
}

#endif //PLAYGROUND_NEWMAZE_H
