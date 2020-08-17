#include <ScoreLoader.hpp>
#include <fstream>
#include <iostream>

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
    if(ifs)
    {
        std::cerr << "failed to open file\n";
        return false;
    }

    Note note;
    while(ifs >> note.first >> note.second)
    {
        score.emplace_back(note);
    }

    ifs.close();
}

std::optional<Note> ScoreLoader::getNote()
{
    Note rtn = score.back();
    score.pop_back();
    return rtn;
}
