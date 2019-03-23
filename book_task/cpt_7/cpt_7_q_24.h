//
// Created by schwarzeni on 2019-03-17.
//

#ifndef BOOK_TASK_CPT_7_Q_24_H
#define BOOK_TASK_CPT_7_Q_24_H

#include <iostream>
#include <ctime>
#include <iomanip>

namespace cpt_7_q_24 {
    const int kSize = 8;
    const int kDirectSize = 8;
    const int kNotReach = 0;
    const int kCannotGo = -1;
    const int kReached = -2;

    int horizontal[kDirectSize] = {2, 1, -1, -2, -2, -1, 1, 2};
    int vertical[kDirectSize] = {-1, -2, -2, -1, 1, 2, 2, 1};

    void clearBoard(int maze[][kSize]) {
        for (int i = 0; i < kSize; i++) {
            for (int j = 0; j < kSize; j++) {
                maze[i][j] = kNotReach;
            }
        }
    }

    bool canGo(const int &direc_x, const int &direc_y, const int maze[][kSize]) {
        return direc_x >= 0
               && direc_x < kSize
               && direc_y >= 0
               && direc_y < kSize
               && maze[direc_x][direc_y] == kNotReach;
    }

    void printBoard(const int maze[][kSize]) {
        std::cout << " ";
        for (int row = 0; row < kSize; row++) {
            std::cout << "  " << row;
        }
        std::cout << std::endl;
        for (int row = 0; row < kSize; row++) {
            std::cout << row;

            for (int col = 0; col < kSize; col++)
                std::cout << std::setw(3) << maze[row][col];

            std::cout << '\n';
        } // end for
        std::cout << std::endl;
    }

    bool move(int curr_x, int curr_y, int maze[][kSize]) {

        static int move_count = 0;

        move_count++;
        int cache_move_count = move_count;

        if (move_count == kSize * kSize) {
            maze[curr_x][curr_y] = move_count;
            return true;
        };

        int tmp_target_x;
        int tmp_target_y;

        maze[curr_x][curr_y] = kReached;

        for (int i = 0; i < kDirectSize; i++) {
            tmp_target_x = curr_x + horizontal[i];
            tmp_target_y = curr_y + vertical[i];
            if (canGo(tmp_target_x, tmp_target_y, maze)) {
                if (!move(tmp_target_x, tmp_target_y, maze)) {
                    move_count--;
                    continue;
                } else {
                    maze[curr_x][curr_y] = cache_move_count;
                    return true;
                }
            }
        }
        maze[curr_x][curr_y] = kNotReach;
        return false;
    }

    void func() {
        int maze[kSize][kSize] = {0};
        printBoard(maze);

        std::srand(std::time(nullptr));
        int init_pos_x = rand() % kSize;
        int init_post_y = rand() % kSize;

        for (int i = 0; i < kSize; i++) {
            for (int j = 0; j < kSize; j++) {
                clearBoard(maze);
                std::time_t t_1 = time(0);
//        move(init_pos_x, init_post_y, maze);
                move(i, j, maze);

                std::time_t t_2 = time(0);
                std::cout << "(" << i  << ", " << j <<") 用时 " << t_2 - t_1 << "s" << std::endl;

                std::cout << std::endl;
                printBoard(maze);
            }
        }


    }
}

#endif //BOOK_TASK_CPT_7_Q_24_H
