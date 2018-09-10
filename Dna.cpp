/**
Charlie Liu
2274468
liu305@mail.chapman.edu
CPSC350-2
Assignment1

Source file calculates all the data needed from the input file and outputs it to the output file.
*/

#include "Dna.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <stdlib.h>

#define _USE_MATH_DEFINES

using namespace std;

Dna::Dna()
{
  numA = 0;
  numT = 0;
  numC = 0;
  numG = 0;
  numAA = 0;
  numAC = 0;
  numAT = 0;
  numAG = 0;
  numCA = 0;
  numCC = 0;
  numCT = 0;
  numCG = 0;
  numTA = 0;
  numTC = 0;
  numTT = 0;
  numTG = 0;
  numGA = 0;
  numGC = 0;
  numGT = 0;
  numGG = 0;

  sumBigrams = 0;
  mean = 0;
  variance = 0;
  sd = 0;

  numLines = 0;
}

Dna::~Dna()
{

}

void Dna::readFile(string file)
{
  ifstream myFile(file.c_str());
  string line;

  cout << "Attempting to read file: " << file << ' ' << myFile.good() << '\n';

  if (myFile.is_open())
  {


    while (getline (myFile,line))
    {
      cout << line << '\n';
      ++numLines;
      countNucleotides(line);
    }

    cout << "Number of lines: " << numLines << '\n';

    calcVariance(file);
    calcSd();


  }

  else cout << "Unable to open file\n";
}

void Dna::countNucleotides(string line)
{
  for (int i = 0; i < line.length(); ++i)
  {
    if (toupper(line[i]) == 'A')
    {
      ++numA;
    }
    else if (toupper(line[i]) == 'T')
    {
      ++numT;
    }
    else if (toupper(line[i]) == 'C')
    {
      ++numC;
    }
    else if (toupper(line[i]) == 'G')
    {
      ++numG;
    }
    countBigrams(line, i);
  }
}

void Dna::countBigrams(string line, int i)
{
  if (i < line.length() - 1)
  {
    switch (toupper(line[i]))
    {
      case 'A':
      {
        switch (toupper(line[i + 1]))
        {
          case 'A': ++numAA;
          break;
          case 'C': ++numAC;
          break;
          case 'T': ++numAT;
          break;
          case 'G': ++numAG;
          break;
        }
      } break;
      case 'C':
      {
        switch (toupper(line[i + 1]))
        {
          case 'A': ++numCA;
          break;
          case 'C': ++numCC;
          break;
          case 'T': ++numCT;
          break;
          case 'G': ++numCG;
          break;
        }
      } break;
      case 'T':
      {
        switch (toupper(line[i + 1]))
        {
          case 'A': ++numTA;
          break;
          case 'C': ++numTC;
          break;
          case 'T': ++numTT;
          break;
          case 'G': ++numTG;
          break;
        }
      } break;
      case 'G':
      {
        switch (toupper(line[i + 1]))
        {
          case 'A': ++numGA;
          break;
          case 'C': ++numGC;
          break;
          case 'T': ++numGT;
          break;
          case 'G': ++numGG;
          break;
        }
      } break;
    }
  }
}

float Dna::calcSum()
{
  sum = numA + numT + numC + numG;
  cout << "Sum: " << sum << '\n';
  return sum;
}

float Dna::calcSumBigrams()
{
  sumBigrams = numAA + numAC + numAT + numAG + numCA + numCC + numCT + numCG + numTA + numTC + numTT + numTG + numGA + numGC + numGT + numGG;
}

double Dna::calcMean()
{
  mean = calcSum() / numLines;
  cout << "Mean: " << mean << '\n';
  return mean;
}

double Dna::calcVariance(string file)
{
  ifstream myFile(file.c_str());
  string line;

  double temp = 0;
  calcMean();
  while (getline (myFile,line))
  {
    temp += (line.length() - 1 - mean) * (line.length() - 1 - mean);
  }
  variance = temp / (numLines - 1);
  cout << "variance: " << variance << '\n';
  return variance;
}

double Dna::calcSd()
{
  sd = sqrt(variance);
  return sd;
}

void Dna::outputData(string fileName)
{

  ofstream myFile(fileName.c_str());
  if (myFile.is_open())
  {
    myFile << "Charlie Liu  2274468 CPSC350-02" << endl;

    myFile << "Sum: " << sum << endl;
    myFile << "Mean: " << mean << endl;
    myFile << "Variance: " << variance << endl;
    myFile << "Standard Deviation: " << sd << endl;
    myFile << "Probability of A = " << numA / sum << '\n';
    myFile << "Probability of C = " << numC / sum << '\n';
    myFile << "Probability of T = " << numT / sum << '\n';
    myFile << "Probability of G = " << numG / sum << '\n';
    myFile << "Probability of AA = " << numAA / calcSumBigrams() << '\n';
    myFile << "Probability of AC = " << numAC / sumBigrams << '\n';
    myFile << "Probability of AT = " << numAT / sumBigrams << '\n';
    myFile << "Probability of AG = " << numAG / sumBigrams << '\n';
    myFile << "Probability of CA = " << numCA / sumBigrams << '\n';
    myFile << "Probability of CC = " << numCC / sumBigrams << '\n';
    myFile << "Probability of CT = " << numCT / sumBigrams << '\n';
    myFile << "Probability of CG = " << numCG / sumBigrams << '\n';
    myFile << "Probability of TA = " << numTA / sumBigrams << '\n';
    myFile << "Probability of TC = " << numTC / sumBigrams << '\n';
    myFile << "Probability of TT = " << numTT / sumBigrams << '\n';
    myFile << "Probability of TG = " << numTG / sumBigrams << '\n';
    myFile << "Probability of GA = " << numGA / sumBigrams << '\n';
    myFile << "Probability of GC = " << numGC / sumBigrams << '\n';
    myFile << "Probability of GT = " << numGT / sumBigrams << '\n';
    myFile << "Probability of GG = " << numGG / sumBigrams << '\n';

    for (int i = 0; i < 1000; ++i)
    {
      for (int j = 0; j < generateLength(); ++j)
      {
        if (rand() % (int)sum < numA)
        {
          myFile << "A";
        }
        else if (rand() % (int)sum < numA + numC)
        {
          myFile << "C";
        }
        else if (rand() % (int)sum < numA + numC + numT)
        {
          myFile << "T";
        }
        else if (rand() % (int)sum < numA + numC + numT + numG)
        {
          myFile << "G";
        }
      }
      myFile << endl;
    }

    myFile.close();
  }


}

int Dna::generateLength()
{
  double c = sqrt((-2) * log((double)rand() / RAND_MAX)) * cos(2 * M_PI * ((double)rand() / RAND_MAX));
  double d = sd * c + mean;
  return d + .5;
}
