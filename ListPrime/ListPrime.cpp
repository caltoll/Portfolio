//ListPrime.cpp
//Dumb implementation of whether a number is prime

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
typedef unsigned long int ulong;


bool checkPrime(ulong num);
ulong stringToInt(std::string inStream);

int main(int argc, char* argv[])
{
	if (argc!=3)
	{
		std::cout	<<"Usage: checkPrime <max number> <method>\n"
					<<"Method can be 'b' for brute-force factorisation or 'f' for Fermat method"
					<< std::endl;
		return 0;
	}

	ulong num = stringToInt(argv[1]);
	char method = argv[2][0];
	if ((method != 'b')&&(method != 'f')) 
		{
			std::cout << "Method not recognised: must be 'b' or 'f'";
			return 0;
		}

	std::vector<ulong> primeList;

	bool prime;
	std::cout << "[          ]\r[";
	int percent=10;
	for (ulong i=2; i<num; i++)
	{
		if ((( i * 100 ) / num ) ==percent) //PROGRESS BAR
		{
			std::cout << "=";
			percent = percent + 10;
		}
		prime = checkPrime(i);
		
		if (prime)
			primeList.push_back(i);
		
	}

	std::cout << "=\n" << sizeof(ulong) * primeList.capacity();

//Print all at once to a file

	std::ofstream out("PrimeList.txt");
	

	for (int i=0; i<primeList.size(); i++ )
		out << primeList[i] << "\n";
	

	return 1;
}




ulong stringToInt(std::string inStream)
{
	ulong outInt;
	std::stringstream convert(inStream);
	if (!(convert >> outInt))
	{
		std::cerr << "String to int conversion failed" << std::endl;
		return 0;
	}

	return outInt;
}


bool checkPrime(ulong num)
{	
	if (num == 1 || num%2==0)
		return false;
	else
	{
		
		for(int i = num/2; i>1; i--)
		{
			int remain = num%i;
			if(remain==0)
			{
				return false;
			}
	
			
		}
	}
	return true;
}