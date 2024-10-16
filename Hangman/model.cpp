#include "model.h"
#include "iostream"

// This class is used to take care of game logic of hangman.

bool Model::isGameRunning() {
	return game_running;
}
void Model::setGameRunnning(bool value) {
	game_running = value;
}

std::string Model::getExecutionerWord() {
	return executioner_word;
}

void Model::setExecutionerWord(std::string value) {
	executioner_word = value;
}

char Model::getGuess() {
	return guess;
}
void Model::setGuess(char value) {
	guess = value;
}

std::set<char> Model::getExistingLetters() {
	return existing_letters;
}

void Model::storeExistingLetters(std::string word) {
	for (int i = 0; i < word.size(); i++) {
		existing_letters.insert(word[i]);
	}
}

