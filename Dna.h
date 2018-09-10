/**
Charlie Liu
2274468
liu305@mail.chapman.edu
CPSC350-2
Assignment1

This source file lists all the variables and methods used.
*/

#include <iostream>

using namespace std;

class Dna
{
private:
  float numA, numT, numC, numG;
  float numAA, numAC, numAT, numAG, numCA, numCC, numCT, numCG, numTA, numTC, numTT, numTG, numGA, numGC, numGT, numGG;
  float sum;
  float sumBigrams;
  double mean;
  double variance;
  double sd; //standard deviation

  int numLines;

  void countNucleotides(string line);
  void countBigrams(string line, int i);
  float calcSum();
  float calcSumBigrams();
  double calcMean();
  double calcVariance(string file);
  double calcSd();

public:
  Dna();
  ~Dna();

  void readFile(string file);
  void outputData(string fileName);
  int generateLength();

};
