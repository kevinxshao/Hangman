#include "view.h"
#include "iostream"

// This class is used to take care of displaying all the terminal art and prompts.
std::string View::getPicture(int index) {
	return picture[index];
}

int View::getPictureIndex() {
	return picture_index;
}

void View::setPictureIndex(int value) {
	picture_index = value;
}

std::string View::getExecutionerPrompt() {
	return executioner_prompt;
}

std::string View::getGuesserPrompt() {
	return guesser_prompt;
}

void View::printEmptySlots(int size) {
	for (int i = 0; i < size; i++) {
		std::cout << "_";;
		if (i != size - 1) {
			std::cout << " ";
		}
		else {
			std::cout << "\n";
		}
	}
	std::cout << "\n\n";
}

void View::printCorrectLetters(std::string word, char c, std::string& correct_guesses, int& count_correct) {
	std::cout << "\n\n";
	for (int i = 0; i < word.size(); i++) {
		if (word[i] == c) {
			correct_guesses[i*2] = c;
			count_correct++;
		}
	}
	std::cout << correct_guesses << std::endl;
}

void View::printPicture() {
	if (picture_index >= 0) {
		std::cout << picture[picture_index] << std::endl;
	}
}