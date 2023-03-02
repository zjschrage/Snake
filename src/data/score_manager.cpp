#include "score_manager.h"
#include "constants.h"
#include "directory.h"
#include <algorithm>
#include <iostream>

ScoreManager::ScoreManager() {
    cacheScores();
}

void ScoreManager::cacheScores() {
    //std::cout << "SCORE MANAGER DIRECTORY:" << (Directory::get() + PATH_TO_HIGHSCORES).c_str() << std::endl;
    FILE* fp = fopen((Directory::get() + PATH_TO_HIGHSCORES).c_str(), "r");
    int tempScore = 0;
    for (int i = 0; i < 5; i++) {
        fscanf(fp, "%d\n", &tempScore);
        scores.push_back(tempScore);
    }
    fclose(fp);
}

void ScoreManager::writeScores() {
    FILE* fp = fopen((Directory::get() + PATH_TO_HIGHSCORES).c_str(), "w");
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