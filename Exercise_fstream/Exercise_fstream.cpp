/*a) Wygeneruj 100000 losowych liczb z przedzialu - 100000 100000
b) zapisz je do pliku
c) nastepnie wczytaj je z tego pliku do vectora
d) wypisz 100 pierwszych wczytanych liczb(std::advance)*/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>

int main()
{
    // a) 
    std::random_device r;
    std::default_random_engine defEngine(r());
    std::uniform_int_distribution<int> intDistr(-10000, 10000);
    for (int i = 0; i <= 10000; ++i)
    {
        int n = intDistr(defEngine);
    }

    //b) 
    std::string fileName{ "C:\\Users\\Patrycja\\Desktop\\repos\\Exercise_fstream.txt" };
    std::ofstream fileToWrite(fileName, std::ios::out | std::ios::trunc);

    if (fileToWrite.is_open())
    {
        std::cout << "File is open";

        for (int i = 0; i <= 10000; ++i)
        {
            if (fileToWrite.good())
            {
                fileToWrite << intDistr(defEngine) << ", ";
            }
        }

        fileToWrite.close();
    }
    else
    {
        std::cout << "Cannot open file";
        return -1;
    }

    //c) 

    std::vector<int> Numbers;
    std::ifstream fileToRead(fileName);
    std::string numbers;

    while (fileToRead.good() && !fileToRead.eof())
    {
        std::string numbers;
        
        std::getline(fileToRead, numbers);
        std::cout << numbers << std::endl;
    }

    for (int i = 0; i < numbers.size(); i++)
    {
        Numbers.push_back(fileToRead.eof());
    }

    fileToRead.close();

    //d) 

    auto numbers = numbers.begin();
	int i = 0;
	while (i != 100)
	{
		std::advance(numbers, i);
		std::cout << numbers << std::endl;
		i++;
	}
}