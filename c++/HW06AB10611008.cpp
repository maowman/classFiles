//=================================================================
//	PROGRAMMER  : 梁安哲
//	DATE	    : 2021-12-12
//	FILENAME	: HW06AB10611008.cpp
//	DESCRIPTION : This is a bridge simulator
//=================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int answer1, answer2, answer3, answer4;

class Card // class of card
{
public:
    Card(int inputNumber, int inputColor) // constructor of the card
    {
        number = inputNumber;
        color = inputColor;
    }
    int getPoint() // get the high-card point of the card
    {
        int point = 0;
        if (number == 1)
        {
            point = 4;
        }
        else if (number == 11)
        {
            point = 1;
        }
        else if (number == 12)
        {
            point = 2;
        }
        else if (number == 13)
        {
            point = 3;
        }
        return point;
    }

    friend std::ostream &operator<<(std::ostream &os, Card &card) // how to output the card
    {
        os << card.getName();
        return os;
    }

private:
    int number;
    int color; // 0 = spades , 1 = hearts , 2 = diamonds , 3 = clubs
    std::string getName()
    {
        std::string cardName = std::to_string(number);
        if (number == 1 || number == 11 || number == 12 || number == 13)
        {
            if (number == 1)
            {
                cardName = "Ace";
            }
            else if (number == 11)
            {
                cardName = "Knight";
            }
            else if (number == 12)
            {
                cardName = "Queen";
            }
            else if (number == 13)
            {
                cardName = "King";
            }
        }
        std::string cardColorName;
        if (color == 0)
        {
            cardColorName = "Spades";
        }
        else if (color == 1)
        {
            cardColorName = "Hearts";
        }
        else if (color == 2)
        {
            cardColorName = "Diamonds";
        }
        else if (color == 3)
        {
            cardColorName = "Clubs";
        }
        else
        {
            cardColorName = "Error";
        }
        std::string fullname = cardColorName + " " + cardName;
        return fullname;
    }
};

class Player

{
public:
    Player(std::string inputName) // constructor of the player
    {
        name = inputName;
    }
    void addCard(Card card) // give a card to the player
    {
        cards.push_back(card);
    }
    int getTotalPoint() // get the total high-card point of a player
    {
        int total = 0;
        for (int i = 0; i < (int)cards.size(); i++)
            total += cards[i].getPoint();
        return total;
    }
    friend std::ostream &operator<<(std::ostream &os, Player &player) // how to output a player
    {
        os << "Player " << player.name << " :" << std::endl;
        os << "Has " << player.cards.size() << " card(s) and " << player.getTotalPoint() << " point(s)" << std::endl;
        for (int i = 0; i < (int)player.cards.size(); i++)
        {
            os << player.cards[i] << std::endl;
        }
        return os;
    }

private:
    std::string name;
    std::vector<Card> cards;
};

class Game
{
public:
    Game()
    {
        players.push_back(Player("Alpha"));
        players.push_back(Player("Beta"));
        players.push_back(Player("Gamma"));
        players.push_back(Player("Delta")); // add four player
        for (int i = 0; i < 4; i++)
        {
            for (int k = 1; k <= 13; k++)
            {
                cards.push_back(Card(k, i)); // generate a set of pocker card
            }
        }
        std::random_shuffle(cards.begin(), cards.end()); // shuffle the deck
    }
    void nextRound()
    {
        for (int i = 0; i < (int)players.size(); i++)
        {
            players[i].addCard(cards[cards.size() - 1]); // give the last card to a player
            cards.pop_back();                            // delte the last card in the deck
        }
        round += 1;
    }
    void showStatus() // show the game status using std::cout
    {
        std::cout << "At round " << round << std::endl;
        for (int i = 0; i < (int)players.size(); i++)
        {
            std::cout << players[i] << std::endl;
        }
    }
    void saveStatus(std::ofstream &file) // save the game status
    {
        file << "At round " << round << std::endl;
        for (int i = 0; i < (int)players.size(); i++)
        {
            file << players[i] << std::endl;
        }
    }
    void autolab()
    {
        answer1 = players[0].getTotalPoint();
        answer2 = players[1].getTotalPoint();
        answer3 = players[2].getTotalPoint();
        answer4 = players[3].getTotalPoint(); // store the high-card point of each players
    }

private:
    int round = 0;
    std::vector<Player> players;
    std::vector<Card> cards;
};

int main()
{
    int roundNumber = 3;                   // the number of round
    std::string fileName = "CardGame.txt"; // define the saving location
    std::ofstream file(fileName.c_str());
    for (int i = 0; i < roundNumber; i++)
    {
        Game game;                   // set up a new game
        for (int k = 0; k < 13; k++) // a game will have 13 rounds
        {
            game.nextRound();      // iterate the next round
            game.showStatus();     // show the game status
            game.saveStatus(file); // save the game status
        }
        game.autolab();
    }
    file.close();
    // for Autolab submission check
    return 0;
}
