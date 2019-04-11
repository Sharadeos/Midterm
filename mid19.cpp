//
//
//
//Author: Gordon Griesel
//Editor: Luis Manahan
//Date: April 7, 2019
//Edited: April 11, 2019
//Purpose: Framework for a coding exam
//
//See instructions on assignment web page to produce a unit-test
//for the vec_length function.
//
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <fstream>      // std::ifstream
#include <vector>
#include <sstream>
using namespace std;
//type defines
typedef double Flt;
typedef Flt Vec[3];

//prototype
Flt vec_length(Vec v);

//Array of vector values
const Flt arr[] = {
   1.0,   0.0,
   1.0,   1.0,
  -1.2,   2.5,
  99.9,  99.9,
   2.2,  -1.2,
   0.0,   0.0
};


int main(int argc, char *argv[])
{
#ifdef TEST
if (argc >= 2) {	
	int n = 0;
	double thresh = stod(argv[1]);
	std::ifstream theFile ("data.csv");
	std::string line;
	std::vector<std::vector<std::string> > values;
	while(std::getline(theFile, line, '\n')) {
		std::string line_value;
		std::vector<std::string> line_values;
		std::stringstream ss(line);
		while(std::getline(ss, line_value, ',')) {
			line_values.push_back(line_value);
			//cout << line_value << endl;
		}
		values.emplace_back(line_values);
	}
	printf("                                    \n");
	printf("3350 software engineering           \n\n");
	printf("Unit test of veclength() function:\n");
	printf("tolerance: %.2f\n\n", thresh);
	printf("     x         y         length     actual\n");
	printf("     --------  --------  ---------- ----------\n");
	for (int i = 0; i < int(values.size()); i++) {
		for (int j = 0; j < int(values[i].size()); j++) {
        //cout << values[i][j] << ",";
		}
		Vec v = { stod(values[i][0]), stod(values[i][1]) };
		Flt ret = vec_length(v);
	
	
		if (abs(ret - stod(values[i][4]) ) > thresh) {
			printf("%3i  %8.5lf  %8.5lf  %10.5lf %10.5lf <-- error\n", i+1, v[0], v[1], stod(values[i][4]), ret);
			n++;
		}
		else {
			printf("%3i  %8.5lf  %8.5lf  %10.5lf %10.5lf\n", i+1, v[0], v[1], stod(values[i][4]), ret);
		}
	}
	cout << "\nUnit test complete." << endl;
	cout << "errors found: " << n << endl;
}
#endif
#ifdef TEST2

	if (argc >= 2) {
	return 0;
	}
    //Program to calculate vector normalization and length.
	//
    printf("                                    \n");
    printf("3350 software engineering           \n");
    printf("                                    \n");
    printf("Calculation of vector lengths:      \n");
    printf("                                    \n");
    printf("     x         y         length     \n");
    printf("     --------  --------  ---------- \n");
    //read until sentinel found.
    int i=0;
    Vec v = { arr[i*2+0], arr[i*2+1] };
    do {
        Flt ret = vec_length(v);
        printf("%3i  %8.5lf  %8.5lf  %10.5lf\n", i+1, v[0], v[1], ret);
        ++i;
        v[0] = arr[i*2+0];
        v[1] = arr[i*2+1];
    } while (!(v[0]==0.0 && v[1]==0.0));
    //
    printf("\nProgram complete.\n\n");
	
	
	
#endif

   return 0;

}

Flt vec_length(Vec v)
{
    //Normalize a vector.
    //Return the original length of the vector.
    //
    //input: the 2 components of a vector
    //output: the pre-normalized vector length is returned
    //        the vector argument is scaled to a length of 1.0
    //
    //A degenerate vector causes an error condition.
    //It will return a length of 0.0
    //and an arbitrary vector with length 1.0.
    //
    //calculate the vector dot product with itself...
    Flt dot = v[0]*v[0] + v[1]*v[1];
    //check for degenerate vector...
    if (dot == 0.0) {
        //set an arbitrary vector of length 1.0
        //printf("ERROR vector magnitude is zero.\n");
        v[0] = 1.0;
        v[1] = 0.0;
        return 0.0;
    }
    //vector has a magnitude so continue.
    Flt len = sqrt(dot);
    Flt oolen = 1.0 / len;
    v[0] *= oolen;
    v[1] *= oolen;
    return len;
}
