#include <iostream>
#include <cstdio>
#include <cstdarg>
#include <ctime>
#include <conio.h>
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

std::vector<std::string> explode(char delimiter, const std::string& str)
{
    std::size_t lastpos = 0;
    std::size_t pos = 0;
    std::vector<std::string> pieces;

    for (pos = str.find_first_of(delimiter); pos != std::string::npos; )
    {
        pieces.emplace_back(str.substr(lastpos, pos - lastpos));
        lastpos = pos + 1;
        pos = str.find_first_of(delimiter, pos + 1);
    }
    pieces.emplace_back(str.substr(lastpos));

    return pieces;
}

class Player
{
private:

public:
    std::string name;
    std::vector<int> current_hand;
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

    std::vector<unsigned char> ThrowDices(unsigned char _current_dices_in_play)
    {
        //Random based on time
        srand(unsigned(int(time(NULL))));

        std::vector<unsigned char> dices;
        for (int i = 0; i < _current_dices_in_play; i++)
        {
            dices.push_back(1 + rand() % 6);
        }

        return dices;
    }
};

class Yatzy
{
private:
    std::vector<Player*> players;
    std::map<unsigned char, std::string> combo_names;

    unsigned char turn;
    unsigned char throws;
    unsigned char current_dices_in_play;

public:
    bool winner_found;

    Yatzy(unsigned char _players, ...) : winner_found(false), turn(0), throws(0), current_dices_in_play(5)
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

    void Play()
    {
        if (throws != 3)
        {
            printf("\n%s's turn\n", this->players.at(turn)->name.c_str());
            printf("Press Enter to throw the dices\n");
        }

        char a = _getch();
        if (a == 13)
        {
            for (unsigned char i = 0; i < this->players.size(); i++)
            {
                std::vector<unsigned char> dices;
                if (turn == i)
                {
                    dices = this->players.at(i)->ThrowDices(current_dices_in_play);
                    throws++;

                    printf("%s thew the dices, rolls are: ", this->players.at(i)->name.c_str());
                    for (int i = 0; i < dices.size(); i++)
                    {
                        if (i == dices.size() - 1)
                            printf("%i\n", dices.at(i));
                        else
                            printf("%i, ", dices.at(i));
                    }

                    char choice;
                    do
                    {
                        printf("\nSave any dice? (Y/N) : ");
                        choice = _getch();
                    } while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');
                    
                    if (choice == 'y' || choice == 'Y')
                    {
                        std::vector<std::string> save_dice;
                        std::vector<int> actual_saved_dice;
                        std::string save_string = "";
                        
                        bool saved = false;
                        while (!saved)
                        {
                            printf("\nWhich dice? (comma separated): ");
                            std::cin >> save_string;
                            save_dice = explode(',', save_string);

                            if (save_dice.size() > dices.size())
                            {
                                printf("You tried to save more dices than the amount that was thrown\n");
                                continue;
                            }

                            if (save_dice.size() > 6 - this->players.at(i)->current_hand.size())
                            {
                                printf("The amount of dices saved, would surpass the maximum amounts of dices in the game\n");
                                saved = false;
                            }

                            for (int attempt_save = 0; attempt_save < save_dice.size(); attempt_save++)
                            {
                                for (int thrown_dices = 0; thrown_dices < dices.size(); thrown_dices++)
                                {
                                    if (dices.at(thrown_dices) == std::stoi(save_dice.at(attempt_save)))
                                    {
                                        actual_saved_dice.push_back(std::stoi(save_dice.at(attempt_save)));
                                        dices.erase(dices.begin()+thrown_dices);
                                        break;
                                    }
                                }
                            }

                            saved = true;
                        }

                        for (int saved_dice = 0; saved_dice < actual_saved_dice.size(); saved_dice++)
                            this->players.at(i)->current_hand.push_back(actual_saved_dice.at(saved_dice));

                        printf("%s's hand: ", this->players.at(i)->name.c_str());
                        for (unsigned char hand = 0; hand < this->players.at(i)->current_hand.size(); hand++)
                        {
                            if (hand == this->players.at(i)->current_hand.size() - 1)
                                printf("%i\n", this->players.at(i)->current_hand.at(i));
                            else
                                printf("%i, ", this->players.at(i)->current_hand.at(i));
                        }

                        current_dices_in_play -= actual_saved_dice.size();
                    }
                    else if (choice == 'n' || choice == 'N')
                    {
                        printf("\nNo dices saved\n");
                    }

                    
                    if (throws == 3)
                    {
                        printf("%s has thrown 3 times\n", this->players.at(i)->name.c_str());

                        //Save
                    }
                }
            }
        }
    }
};

int main()
{
    Yatzy game(3, "Matias", "Nicolai", "Casper");

    printf("Console Yatzy\n");
    game.PrintSheet();

    while (!game.winner_found)
    {
        game.Play();
    }
}