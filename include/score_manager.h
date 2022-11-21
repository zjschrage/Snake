#include <vector>

class ScoreManager {
public:
    ScoreManager();
    void cacheScores();
    void writeScores();
    void addScore(int score);
private:
    std::vector<int> scores;
};