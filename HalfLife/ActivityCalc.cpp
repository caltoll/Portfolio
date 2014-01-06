/*Gives an estimate for the current activity of a source based on initially
observed rates, half life of the isotope and time since measurement was taken.

Reads the half lives from a file and matches them to the isotope input from 
command line.
*/
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include <fstream>
#include <ctime>
#include <cstdlib>

/*Calculate the number of entries in the input file. Not used but could be useful in
future

int nEntries(FILE *fileName){//read the number of lines in the file, return to start
	int numLine=0;
	char line[10];
	
	while(fgets(line, 10, fileName)) numLine++;
	
	fseek(fileName ,0 ,SEEK_SET );
	return numLine;

}*/

float getHalfLives(FILE *dataFile, std::string inIsotope)
{

	char isotope[5];
	float lineHalfLife=0;
	float realHalfLife=0;
	bool success=0;
	
	while((fscanf(dataFile,"%s %f", isotope, &lineHalfLife))!=EOF){
	
		if(inIsotope == isotope){
			std::cout << "Half life of " << isotope << " is " << lineHalfLife << std::endl;
			realHalfLife = lineHalfLife;
			
		}
		
	}
	
	if(realHalfLife==0){
			std::cout<<"Could not find isotope provided in file.\nMake sure isotope name is formatted correctly (e.g Cs137). \n"
			<<"If formatting is correct check the file IsotopeList.txt and add the isotope"<<std::endl;
			std::exit(EXIT_FAILURE);
	}
	
	return realHalfLife;
	
	
	
}

//Converting the string to an integer
int stringToDouble(std::string inString)
{
	double outDouble;
	std::stringstream convert(inString);
	if (!(convert>>outDouble)){	
		std::cout<<"String to double conversion failed"<<std::endl;
		return 1;
	}
	return outDouble;
}
	//Calculate the activity of a sample given the number of years
	//Could used better date info as currently just use year
double getActivity(double startDate, double halfLife, int initialActivity)
{
	time_t now = time(0);
	tm *ltm = localtime(&now);
	double currentYear=ltm->tm_year;
	
	
	startDate = startDate - 1900;
	double time = currentYear - startDate;

	double x = pow(0.5, time/ halfLife);
	double finalActivity = initialActivity * x;
	return finalActivity;
}

int main(int argc, char* argv[])
{
	if (argc!=4){
		std::cerr << "Usage: " << argv[0] << " Isotope (e.g. Cs137) Activity Start_Year\n" << std::endl;
		return 0;
	}
	
	//parse date (year) and initial activity. 
	//String-int conversion http://www.cplusplus.com/forum/articles/9645/
	std::cout<<"************"<<std::endl;
	double year=stringToDouble(argv[3]);
	double initial=stringToDouble(argv[2]);
	
	// Half life and isotope arrays
	
	FILE *isotopeList= fopen("./IsotopeList.txt","r");
	
	if(isotopeList==NULL){
		std::cout<<"File failed to open \nMake sure IsotopeList.txt is present and in the same folder as this program\n\n";
		return 0;
	}
	
	double t12=0;

	
	t12=getHalfLives(isotopeList, argv[1]);

	//return final activity
	double final=getActivity(year, t12, initial);
	std::cout<<"Activty of source will be "<<final<<std::endl;

	return 0;
}