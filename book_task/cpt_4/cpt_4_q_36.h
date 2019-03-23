//
// Created by schwarzeni on 2019-03-16.
//

#ifndef BOOK_TASK_CPT_4_Q_36_H
#define BOOK_TASK_CPT_4_Q_36_H

#include <iostream>
#include <iomanip>

namespace cpt_4_q_36 {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::setprecision;
    using std::fixed;

    void func() {
        // initialize variables; population must be a double because
        // int can hold only up to approximately 2 billion
        double population, growthRate;

        // read values from user
        cout << "Enter current population" << endl;
        cin >> population;
        cout << "Enter growth rate as a percentage" << endl;
        cin >> growthRate;

        // convert growth rate into growth factor to multiply with population
        double growthFactor = growthRate / 100 + 1.0;
        int year = 1; // initialize counter
        cout << "\nYear\tPopulation\tPopulation Change\n"; // output header
        cout << setprecision(0) << fixed; // set floating-point formatting

        // loop until year exceeds 75
        while (year <= 75) {
            double oldPopulation = population; // save old population
            population = population * growthFactor; // calculate new population
            double difference = population - oldPopulation; // population change

            // display information
            cout << year << "\t" << population << "\t" << difference << endl;
            ++year; // increment year
        } // end while
    }
}

#endif //BOOK_TASK_CPT_4_Q_36_H
