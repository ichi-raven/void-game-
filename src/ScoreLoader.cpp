#include <ScoreLoader.hpp>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>

#include <Siv3D.hpp>

ScoreLoader::ScoreLoader()
{
    return;
}


ScoreLoader::~ScoreLoader()
{
    score.clear();
    return;
}

bool ScoreLoader::load(const char* fileName)
{
    if(!fileName)
    {
        std::cerr << "invalid filename address\n";
        return false;
    }

    std::ifstream ifs(fileName);
    if(!ifs)
    {
        std::cerr << "failed to open file\n";
        return false;
    }

    Note note;
    std::string str;
    while (std::getline(ifs, str))
    {
        std::istringstream iss(str);
        if(!iss)
            continue;
        iss >> note.first >> note.second;
        score.emplace_back(note);
    }

    std::reverse(score.begin(), score.end());
    ifs.close();

    // std::ofstream ofs("test.txt");

    // for(auto& n : score)
    // {
    //     ofs << n.first << " " << n.second << "\n";
    // }

    // ofs.close();

    return true;
}

const std::vector<Note>& ScoreLoader::getNotes() const 
{
    return score;
}
