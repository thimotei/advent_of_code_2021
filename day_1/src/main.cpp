#include <fstream>
#include <iostream>
#include <vector>

int main() 
{
    // read in data
    std::ifstream file("../inputs/data.txt");

    // construct vector containing the data called "measurements"
    std::vector<int> measurement;
    while (file.eof() == false)
    {
        int next;
        file >> next;
        measurement.push_back(next);
    }
    file.close();

    // first part
    int increasing = 0;
    for (std::size_t i = 1; i < measurement.size(); ++i)
    {
        if (measurement[i] > measurement[i - 1])
        {
            ++increasing;
        }
    }

    //output the answer!
    std::cout << "Part 1 solution is: " << increasing << std::endl;

    // second part
    increasing = 0;
    std::vector<int> sliding_window;
    for (std::size_t i = 2; i < measurement.size(); ++i)
    {
        sliding_window.push_back(measurement[i] + measurement[i - 1] +
                                 measurement[i - 2]);
    }
    for (std::size_t i = 1; i < sliding_window.size(); ++i)
    {
        if (sliding_window[i] > sliding_window[i - 1])
        {
            ++increasing;
        }
    }

    // output the answer!
    std::cout << "Part 2 solution is: " << increasing << std::endl;

    std::cout << "Press Enter to end the program";

    // pauses the program until a key is pressed
    std::cin.get();

    return(0);
}
