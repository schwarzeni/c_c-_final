//
// Created by schwarzeni on 2019-03-13.
//

#ifndef PLAYGROUND_CPT18_Q_TASK_13_H
#define PLAYGROUND_CPT18_Q_TASK_13_H

#include <iostream>

namespace cpt18_q__task_13 {
    // function to print out each string in the array
    void output( const std::string * const ani, const int length )
    {
        // loop through the array with the given length
        for ( int j = 0; j < length; ++j )
            std::cout << ( j % 10 ? ' ': '\n' ) << ani[ j ];

        std::cout << std::endl;
    } // end function output

    int partition( std::string b[], int left, int right )
    {
        int pos = left;

        // while loop
        while ( true )
        {
            // move through the array from left to right
            while ( b[ pos ] <= b[ right ] && pos != right )
                right--;

            // if the right is reached, return that position
            if ( pos == right )
                return pos;

            // if the element from the left is greater, swap the positions
            if ( b[ pos ] > b[ right ] )
            {
                b[ pos ].swap( b[ right ] );
                pos = right;
            } // end if

            // compare from the beginning to the pos index
            while ( b[ left ] <= b[ pos ] && pos != left )
                left++;

            if ( pos == left )
                return pos;

            if ( b[ left ] > b[ pos ] )
            {
                b[ pos ].swap( b[ left ] );
                pos = left;
            } // end if
        } // end while
    } // end function partition

// function to sort the array
    void quickSort( std::string a[], int first, int last )
    {
        // call function partition
        int currentLocation;

        if ( first >= last )
            return;

        currentLocation = partition( a, first, last );

        // recursive calls to quickSort to continue the search
        quickSort( a, first, currentLocation - 1 );
        quickSort( a, currentLocation + 1, last );
    } // end function quickSort



    void func()
    {
        const int SIZE = 19;

        // an array of strings containing animal names
        std::string animals[] = { "Macaw", "Lion", "Tiger", "Bear", "Toucan",
                             "Zebra", "Puma", "Cat", "Yak", "Boar",  "Fox", "Ferret",
                             "Crocodile", "Alligator", "Elk", "Ox",  "Horse", "Eagle", "Hawk" };

        std::cout << "before:";
        output( animals, SIZE ); // call output to display string array
        quickSort( animals, 0, SIZE ); // sort them in order

        std::cout << "\nafter:";
        output( animals, SIZE ); // call output to display array of animal
    } // end main


}
#endif //PLAYGROUND_CPT18_Q_TASK_13_H
