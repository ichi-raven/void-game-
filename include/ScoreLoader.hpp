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

    const std::vector<Note>&  getNotes() const;

private:
    std::vector<Note> score;
};