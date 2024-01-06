#pragma once
class Score
{
private:
	int score = 0;
public:
	Score();
	void setScore(int n);
	void Reset();
	int getScore() const;
};

