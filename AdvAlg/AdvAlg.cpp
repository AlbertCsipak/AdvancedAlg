// AdvAlg.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ImageSegmentation.h"

int main()
{
    std::cout << "Hello World!\n";

    ImageSegmentation img = ImageSegmentation();
    img.loadImageFromFile("alma.png");

}