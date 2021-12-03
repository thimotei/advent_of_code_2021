#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdio.h>

int main()
{
    // define types for the file and the current line
    std::ifstream file;
    std::string line;

    // open the data file
    file.open("../inputs/data.txt");

    // using 3D coordinate notation (x is horizontal position, z is depth)
    int x = 0;
    int z = 0;

    // using whitespace between the string and the numbers as the delimiter
    std::string delimiter = " ";

    // PART 1
    // loop to work out final position values
    while (getline(file, line))
    {
        
        int value;
        std::string direction = line.substr(0, line.find(delimiter));
        std::string magnitude = line.substr(line.find(delimiter) + 1, line.size());

        std::stringstream s;
        s << magnitude;
        s >> value;

        if (direction == "forward")
        {
            x += value;
        }
        else if (direction == "down")
        {
            z += value;
        }
        else
        {
            z -= value;
        }
    }

    // print the results of part 1 to the terminal
    std::cout << "The product of our horizontal position and depth is "
              << x*z << std::endl;
    
    // forcing the user to press return, acknowledging that the results
    // to part 1 have been seen!
    std::cout << "Press return to continue to part 2";
    std::cin.get();
   
    file.close();

    // PART 2
    // reinitialising the horizontal and depth positions for part 2
    x = 0;
    z = 0;
    int aim = 0;
    file.open("../inputs/data.txt");
    while (getline(file, line))
    {    
        int value;
        std::string direction = line.substr(0, line.find(delimiter));
        std::string magnitude = line.substr(line.find(delimiter) + 1, line.size());

        std::stringstream s;
        s << magnitude;
        s >> value;

        if (direction == "forward")
        {
            x += value;
            z += aim*value;
        }
        else if (direction == "down")
        {
            aim += value;
        }
        else
        {
            aim -= value;
        }
    }

    // print the results of part 2 to the terminal
    std::cout << "The product of our horizontal position and depth is "
              << x*z << std::endl;
    
    std::cout << "Press return to end the program";
    std::cin.get();
  
    file.close();
}
