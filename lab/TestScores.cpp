#include "TestScores.h"

#include <iostream>
using namespace std;

TestScores::TestScores(double *arrayOfScores, int count)
{
  scores = new double[count];
  numScores = count;

  // copy scores from passed array
  // breaks connection from source
  // -> cannot manipulate scores outside of class
  for (int i = 0; i < count; i++)
  {
    scores[i] = arrayOfScores[i];
  }
}

TestScores::~TestScores()
{
  delete[] scores;
}

double TestScores::getAverage()
{
  double total = 0.0;
  for (int i = 0; i < numScores; i++)
  {
    // temporary score
    double score = scores[i];

    // validate score
    if (score < 0.0)
      throw NegativeScore(score);
    else if (score > 100.0)
      throw TooHighScore(score);

    // valid score
    total += score;
  }

  return total / numScores;
}

void TestScores::displayScores()
{
  cout << "Scores: ";
  for (int i = 0; i < numScores; i++)
  {
    cout << scores[i] << " ";
  }
  cout << endl;
}
