#include <vector>
#include <string>
#include <utility>

class ScoreLoader
{
public:
    using Note = std::pair<std::string, double>;

    ScoreLoader();
    ~ScoreLoader();
    bool load(const char *fileName);

    Note getNote();

private:
    std::vector<Note> score;
};