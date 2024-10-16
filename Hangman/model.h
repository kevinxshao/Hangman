#pragma once
#include <string>
#include <set>
class Model
{
public:
	int correct_guesses = 0;
	bool isGameRunning();
	void setGameRunnning(bool value);
	std::string getExecutionerWord();
	void setExecutionerWord(std::string value);
	char getGuess();
	void setGuess(char c);
	std::set<char> getExistingLetters();
	void storeExistingLetters(std::string word);

private:
	bool game_running;
	std::string executioner_word;
	char guess;
	std::set<char> existing_letters;

};

