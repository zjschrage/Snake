#include "score_manager.h"
#include <algorithm>

ScoreManager::ScoreManager() {
    cacheScores();
}

void ScoreManager::cacheScores() {
    FILE* fp = fopen("data/highscores.txt", "r");
    int tempScore = 0;
    for (int i = 0; i < 5; i++) {
        fscanf(fp, "%d\n", &tempScore);
        scores.push_back(tempScore);
    }
    fclose(fp);
}

void ScoreManager::writeScores() {
    FILE* fp = fopen("data/highscores.txt", "w");
    for (int i = 0; i < 5; i++) {
        fprintf(fp, "%d\n", scores[i]);
    }
    fclose(fp);
}

void ScoreManager::addScore(int score) {
    scores.push_back(score);
    std::sort(scores.begin(), scores.end(), [](int a, int b){return a > b;});
    writeScores();
}