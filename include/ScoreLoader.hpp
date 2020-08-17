#include <vector>
#include <string>
#include <utility>
#include <optional>

using Note = std::pair<int, double>;

class ScoreLoader
{
public:
    ScoreLoader();
    ~ScoreLoader();
    bool load(const char *fileName);

    std::optional<Note> getNote();

private:
    std::vector<Note> score;
};