#include <iostream>
#include "TestScores.h"

using namespace std;

void displayAverage(TestScores &);

int main()
{

  int NUM_SCORES = 5;
  double scores_arr[NUM_SCORES] = {97.5, 98.0, 78.5, 82.0, 63.5};

  // ********************************
  // *         PASSING TEST         *
  // ********************************
  // should display:
  //  Average: 71.2%
  TestScores scores1(scores_arr, NUM_SCORES);
  displayAverage(scores1);

  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

  // ********************************
  // *     FAILING TEST: Too Low    *
  // ********************************
  scores_arr[1] = -3.5;
  TestScores scores2(scores_arr, NUM_SCORES);
  displayAverage(scores2);

  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

  // ********************************
  // *     FAILING TEST: Too High   *
  // ********************************

  scores_arr[1] = 108.5;
  TestScores scores3(scores_arr, NUM_SCORES);
  displayAverage(scores3);
}

void displayAverage(TestScores &scores)
{
  scores.displayScores();

  try
  {
    cout << "Average: " << scores.getAverage() << "%" << endl;
  }
  catch (TestScores::NegativeScore e)
  {
    cout << "Error: Score too low " << e.getBadScore() << endl;
  }
  catch (TestScores::TooHighScore e)
  {
    cout << "Error: Score too high " << e.getBadScore() << endl;
  }
}
