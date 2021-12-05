#include <iostream> //std::cout
#include <fstream>  // std::ifstream
#include <string>
#include <sstream>
#include <vector>
#include <array>

#include <string_parser.h>

typedef std::vector<int> ints_t;

// int max_value = 0;
int count_2s = 0;

std::vector<ints_t> parse_day5()
{
    // std::ifstream input ("../inputs/day_5_test.txt");
    std::ifstream input ("../inputs/day_5.txt");

    std::vector<ints_t> sets_of_4_ints;
    std::string line;
    while (std::getline(input, line))
    {
        strings_t two_pairs = substrings_to_strings(line, " -> ");
        ints_t x1y1x2y2 = substrings_to_ints(two_pairs.at(0) + "," + two_pairs.at(1), ",");
        sets_of_4_ints.push_back(x1y1x2y2);
    }

    //Succesfully recreates the input strings. No bug here.
    // for (auto set : sets_of_4_ints)
        // std::cout << set[0] << "," << set[1] << " -> " << set[2] << "," << set[3] << "\n";

    return sets_of_4_ints;
}

int main ()
{
    std::vector<ints_t> sets_of_4_ints = parse_day5();

    static constexpr int max_dimension = 1000;
    std::array<std::array<uint8_t, max_dimension>, max_dimension> cells = {0};
    // std::array<std::array<uint8_t, max_dimension>, max_dimension> cells2 = {0};

    for (auto set : sets_of_4_ints)
    {
        //Only horizontal & vertical
        if (set[0] == set[2])
        {
            //add to cells
            int min = std::min(set[1], set[3]);
            int max = std::max(set[1], set[3]);
            for ( int ii = min; ii <= max; ++ii)
            {
                cells[ii][set[0]]++;
                int cell_value = cells[ii][set[0]];
                // check_and_count_max(cell_value);
                if (cell_value == 2)
                    count_2s++;
            }
        }
        else if (set[1] == set[3])
        {
            //add to cells
            int min = std::min(set[0], set[2]);
            int max = std::max(set[0], set[2]);
            for ( int ii = min; ii <= max; ++ii)
            {
                cells[set[1]][ii]++;
                int cell_value = cells[set[1]][ii];
                // check_and_count_max(cell_value);
                if (cell_value == 2)
                    count_2s++;
            }
        }
    }


    //the "turn it on its head and burn all your resources" method. - Same wrong result
    // for (size_t ii = 0; ii < max_dimension; ++ii)
    // {
    //     for (size_t jj = 0; jj < max_dimension; ++jj)
    //     {
    //         for (auto set : sets_of_4_ints)
    //         {
    //             if (set[0] == set[2] || set[1] == set[3])
    //             {
    //                 size_t min_x = std::min(set[0], set[2]);
    //                 size_t max_x = std::max(set[0], set[2]);
    //                 size_t min_y = std::min(set[1], set[3]);
    //                 size_t max_y = std::max(set[1], set[3]);
    //                 if ( ii <= max_y && ii >= min_y && jj <= max_x && jj >= min_x)
    //                 {
    //                     check_and_count_max(++cells[ii][jj]);
    //                 }
    //             }
    //         }
    //     }
    // }

    std::cout << "\n\n" << /*"max_value: " << max_value << ", " <<*/ count_2s << " times" << "\n\n";

    // // Plot
    // std::ofstream out("out.txt");
    // for (auto rows : cells)
    // {
    //     for (auto cell : rows)
    //     {
    //         if (cell == 0)
    //         {
    //             std::cout << ".";
    //             out << "0,";
    //         }
    //         else
    //         {
    //             std::cout << static_cast<int>(cell);// << " ";
    //             out << static_cast<int>(cell) << ",";
    //         }
    //     }
    //     std::cout << "\n";
    //     out << "\n";
    // }

    return 0;
}