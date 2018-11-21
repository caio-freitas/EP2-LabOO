#include "Projeto.h"
#include <fstream>

#define filename oi.txt

ifstream inputfile;
ofstream outputfile;

inputfile.open(filename);
outputfile.open(filename);

inputfile >> "oi";

inputfile.close();
outputfile.close();
