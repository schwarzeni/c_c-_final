//
// Created by schwarzeni on 2019-03-10.
//

#ifndef PLAYGROUND_MAZEDATA_H
#define PLAYGROUND_MAZEDATA_H

#include <assert.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include "Pointe.h"

namespace cpt8_maze {
    class MazeData {
    public:
        explicit MazeData(const std::string &filepath) {
            std::ifstream infile(filepath);
            std::string firstLine;
            std::getline(infile, firstLine);
            std::istringstream iss(firstLine);
            // 读取第一行数据
            iss >> this->R >> this->C;
            // 初始化迷宫数组
            this->maze = new char *[this->R];
            this->solveMaze = new char *[this->R];
            this->isVisited = new bool *[this->R];
            for (int i = 0; i < this->R; i++) {
                this->maze[i] = new char[this->C];
                this->solveMaze[i] = new char[this->C];
                this->isVisited[i] = new bool[this->C];
            }

            // 读取迷宫数据
            char tmp;
            int i = 0, j = 0;
            infile.get(tmp);
            while (!infile.eof()) {
                if (tmp == '\n') {
                    i++;
                    j = 0;
                } else {
                    this->maze[i][j] = tmp;
                    j++;
                }
                infile.get(tmp);
            }

            infile.close();
        }

        int getRow() {
            return this->R;
        }

        int getColumn() {
            return this->C;
        }

        int getMaze(int x, int y) {
            assert(this->inArea(x, y) && this->maze != nullptr);
            return this->maze[x][y];
        }

        bool inArea(int x, int y) {
            return x >= 0 && x < this->R && y >= 0 && y < this->C;
        }

        void printMaze() {
            for (int i = 0; i < this->R; i++) {
                for (int j = 0; j < this->C; j++) {
                    std::cout << this->maze[i][j];
                }
                std::cout << std::endl;
            }
        }

        void showResult() {
            for (int i = 0; i < this->R; i++) {
                for (int j = 0; j < this->C; j++) {
                    std::cout << this->solveMaze[i][j];
                }
                std::cout << std::endl;
            }
        }

        void DFS(int x, int y) {
            std::cout << "深度优先" << std::endl;
            this->initTask();
            this->_DFS(x, y);
            this->showResult();
        }


        void BFS(int x, int y) {
            std::cout << "广度优先" << std::endl;
            this->initTask();
            this->_BFS(x, y);
            this->showResult();
        }

        bool canGo(int x, int y) {
            return this->inArea(x, y) && this->solveMaze[x][y] == ' ';
        }

        void printPath(const cpt8_maze::Point *pt) {
            while (pt != nullptr) {
                this->solveMaze[pt->getX()][pt->getY()] = this->pathChar;
                pt = pt->getPoint();
            }
        }


    private:
        // 行
        int R;
        // 列
        int C;
        // 迷宫数组
        char **maze;
        // 解决结果
        char **solveMaze;
        // isVisited
        bool **isVisited;

        char pathChar = 'o';
        char commonPathChar = ' ';
        char barrierChar = '*';

        // 复制数组用于解题
        void initTask() {
            // WARN 数组判空
            for (int i = 0; i < this->R; i++)
                for (int j = 0; j < this->C; j++) {
                    this->solveMaze[i][j] = this->maze[i][j];
                    this->isVisited[i][j] = false;
                }
        }


        bool _DFS(int x, int y) {
            if (x == 100 && y == 99) {
                return true;
            } else if (this->canGo(x, y)) {
                this->solveMaze[x][y] = this->pathChar;
                if (this->_DFS(x + 1, y)) {
                    return true;
                }
                if (this->_DFS(x - 1, y)) {
                    return true;
                }
                if (this->_DFS(x, y - 1)) {
                    return true;
                }
                if (this->_DFS(x, y + 1)) {
                    return true;
                }
                // 回溯法
                this->solveMaze[x][y] = ' ';
            }
            return false;
        }


        bool _BFS(int x, int y) {
            std::vector<cpt8_maze::Point *> queue;
            cpt8_maze::Point initPt(x, y);
            queue.push_back(&initPt);

            while (!queue.empty()) {
                Point *const &currentPt = queue.at(0);
                queue.erase(queue.cbegin());
                int currX = currentPt->getX();
                int currY = currentPt->getY();

                if (currX == 100 && currY == 99) {
                    this->printPath(currentPt);
                    queue.clear();
                    return true;
                }

                if (this->canGo(currX, currY) && !this->isVisited[currX][currY]) {
                    this->isVisited[currX][currY] = true;
                    queue.push_back(new cpt8_maze::Point(currX + 1, currY, currentPt));
                    queue.push_back(new cpt8_maze::Point(currX - 1, currY, currentPt));
                    queue.push_back(new cpt8_maze::Point(currX, currY + 1, currentPt));
                    queue.push_back(new cpt8_maze::Point(currX, currY - 1, currentPt));
                } else {
                }
            }

            return false;
        }
    };
}

#endif //PLAYGROUND_MAZEDATA_H
