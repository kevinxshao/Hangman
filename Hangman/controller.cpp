#include "controller.h"
#include "iostream"
#include "algorithm"

// This class is used to bridge together model logic and view logic together.

Controller::Controller(Model model, View view) : model(model), view(view){}

void Controller::run() {
	model.setGameRunnning(true);
	std::cout << view.getExecutionerPrompt() << std::endl;

	// Get the Executioner word. Force capitalization because in hangman the guesses are not case sensitive.
	std::string user_input;
	std::getline(std::cin, user_input);
	transform(user_input.begin(), user_input.end(), user_input.begin(), ::toupper); // Capitalize User Input
	model.setExecutionerWord(user_input);
	model.storeExistingLetters(model.getExecutionerWord());
	std::set<char> existing_letters = model.getExistingLetters();
	view.printEmptySlots(model.getExecutionerWord().size());
	std::string correct_guesses(model.getExecutionerWord().size()*2, ' ');
	int count_correct = 0;
	// Main Game Loop
	while (model.isGameRunning()) {
		// Print the current Hangman
		view.printPicture();
		// You lose if the hangman gets fully drawn.
		if (view.getPictureIndex() == 6) {
			std::cout << "You lose!";
			break;
		}
		// If you guessed the word correctly before hangman gets fully drawnn.
		if (count_correct == model.getExecutionerWord().size()) {
			std::cout << "You win!";
			break;
		}
		// Get Guesser's input
		char user_guess;
		std::cout << view.getGuesserPrompt() << std::endl;
		std::cin.get(user_guess);
		user_guess = std::toupper(user_guess);
		model.setGuess(user_guess);
		// Clear cin Buffer
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail(), '\n');
		std::cin.rdbuf()->in_avail();
		// Check if the guessed letter exist in the Exectioner's word. 
		if (!existing_letters.count(model.getGuess())) {
			view.setPictureIndex(view.getPictureIndex() + 1);
		}
		//Print your current correct guesses
		view.printCorrectLetters(model.getExecutionerWord(), model.getGuess(), correct_guesses, count_correct);
		view.printEmptySlots(model.getExecutionerWord().size());

	}
}

