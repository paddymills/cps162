#ifndef TESTSCORES_H
#define TESTSCORES_H

// base class for bad score exception
class InvalidScore
{
private:
  double value;

public:
  InvalidScore(double score)
  {
    value = score;
  }
  double getBadScore()
  {
    return value;
  }
};

class TestScores
{
private:
  double *scores; // pointer to array of test scores
  int numScores;  // array length
public:
  // exception classes
  class NegativeScore : public InvalidScore
  {
  public:
    NegativeScore(double badScore) : InvalidScore(badScore){};
  };
  class TooHighScore : public InvalidScore
  {
  public:
    TooHighScore(double badScore) : InvalidScore(badScore){};
  };

  // constructor, destructor and member methods
  TestScores(double *, int);
  ~TestScores();
  double getAverage();
  void displayScores();
};

#endif