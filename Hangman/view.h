#pragma once
#include <string>
class View
{
public:
	std::string getPicture(int index);
	int getPictureIndex();
	void setPictureIndex(int value);
	std::string getExecutionerPrompt();
	std::string getGuesserPrompt();
	void printEmptySlots(int size);
	void printCorrectLetters(std::string word, char c, std::string& correct_guesses, int& count_correct);
	void printPicture();
private:
	std::string platform = " |'''|\n     |\n     |\n     |\n   -----";
	std::string head = " |'''|\n O   |\n     |\n     |\n   -----";
	std::string body = " |'''|\n O   |\n |   |\n     |\n   -----";
	std::string left_arm = " |'''|\n O   |\n/|   |\n     |\n   -----";
	std::string right_arm = " |'''|\n O   |\n/|\\  |\n     |\n   -----";
	std::string left_leg = " |'''|\n O   |\n/|\\  |\n/    |\n   -----";
	std::string right_leg = " |'''|\n O   |\n/|\\  |\n/ \\  |\n   -----";
	std::string picture[7] = {platform, head, body, left_arm, right_arm, left_leg, right_leg};
	int picture_index = -1;
	std::string executioner_prompt = "Executioner please choose your desired word (Don't show the Guesser this word):";
	std::string guesser_prompt = "Guesser please enter a letter:";

};

