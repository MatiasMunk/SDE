#include <cstdio>
#include <cstdarg>
#include <string>
#include <vector>
#include <map>

enum Combos
{
    ONES,
    TWOS,
    THREES,
    FOURS,
    FIVES,
    SIXES,
    SUM_FIRST,

    BONUS,
    ONE_PAIR,
    TWO_PAIRS,
    THREE_OF_A_KIND,
    FOUR_OF_A_KIND,
    LITTLE_STRAIGHT,
    BIG_STRAIGHT,
    HOUSE,
    CHANCE,
    YATZY,
    SUM_FINAL,
    END_COMBO
};

class Player
{
private:

public:
    std::string name;
    std::map<unsigned char, int> points;

    Player(std::string _name) : name(_name)
    {
        for (unsigned char combo = 0; combo < END_COMBO; combo++)
        {
            this->points.insert(std::make_pair(combo, 0));
        }
    }

    int GetPoints(unsigned char _which)
    {
        std::map<unsigned char, int>::iterator it = this->points.begin();
        for (unsigned char i = 0; i < END_COMBO; i++)
        {
            if (it->first == _which)
                return it->second;
        }

        return 0;
    }
};

class Sheet
{
private:
    std::vector<Player*> players;
    std::map<unsigned char, std::string> combo_names;

public:
    Sheet(unsigned char _players, ...)
    {
        va_list ptr;
        va_start(ptr, _players);

        for (int i = 0; i < _players; i++)
        {
            this->players.push_back(new Player(va_arg(ptr, char*)));

        }

        va_end(ptr);

        this->combo_names[ONES] = "1'ere";
        this->combo_names[TWOS] = "2'ere";
        this->combo_names[THREES] = "3'ere";
        this->combo_names[FOURS] = "4'ere";
        this->combo_names[FIVES] = "5'ere";
        this->combo_names[SIXES] = "6'ere";
        this->combo_names[SUM_FIRST] = "SUM";
        this->combo_names[BONUS] = "Bonus";
        this->combo_names[ONE_PAIR] = "1 par";
        this->combo_names[TWO_PAIRS] = "2 par";
        this->combo_names[THREE_OF_A_KIND] = "3 ens";
        this->combo_names[FOUR_OF_A_KIND] = "4 ens";
        this->combo_names[LITTLE_STRAIGHT] = "L Str";
        this->combo_names[BIG_STRAIGHT] = "S Str";
        this->combo_names[HOUSE] = "Hus";
        this->combo_names[CHANCE] = "Chance";
        this->combo_names[YATZY] = "Yatzy";
        this->combo_names[SUM_FINAL] = "Sum";
    }

    void PrintSheet()
    {
        printf("Sheet\n");

        printf("Player\t");
        for (int i = 0; i < this->players.size(); i++)
        {
            if (i == this->players.size() - 1)
                printf("\t%s\n", this->players.at(i)->name.c_str());
            else
                printf("\t%s\t", this->players.at(i)->name.c_str());
        }

        std::map<unsigned char, std::string>::iterator it = this->combo_names.begin();
        for (unsigned char i = 0; i < END_COMBO; i++)
        {
            if (it->first == i)
            {
                printf("%s\t", it->second.c_str());
                for (int player = 0; player < this->players.size(); player++)
                {
                    if (player == this->players.size() - 1)
                        printf("\t%i\n", this->players.at(player)->GetPoints(i));
                    else
                        printf("\t%i\t", this->players.at(player)->GetPoints(i));
                }
            }

            ++it;
        }
    }
};

int main()
{
    Sheet* sheet = new Sheet(3, "Matias", "Nicolai", "Casper");

    printf("Console Yatzy\n");
    sheet->PrintSheet();
}