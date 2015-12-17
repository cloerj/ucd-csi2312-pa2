//
// John-Marc Cloer
//

#include <iostream>
#include "Exceptions.h"

Clustering::Bounds()
{
    std::cout << "Your input would put the clusters out of bounds.\n";
    std::cout << "Please try again.\n";
}

Clustering::Clusterless()
{
    std::cout << "Unfortunately, I couldn't find any clusters.\n";
}

Clustering::Dimensionals(int input)
{
    switch(input)
    {
        case 1:
            std::cout << "The dimensions from the two clusters don't match.\n";
            break;
        case 2:
            std::cout << "The clusters are on top of one another.\n";
            break;
        default: std::cout << "There was some kind of error in the program.\n";
    }
}

Clustering::Empty()
{
    std::cout << "This cluster is completely empty.\n";
}

std::ostream &operator<<(std::ostream &oStream, std::string &strName)
{
    oStream << getName() << "Ex(" << strName << ")\n";
        return oStream;
}
