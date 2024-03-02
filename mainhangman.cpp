
#include <iostream>
#include <string.h>
using namespace std;
const string FIGURE[] = {
" ------------- \n"
" | \n"
" | \n"
" | \n"
" | \n"
" | \n"
" ----- \n",
" ------------- \n"
" |           | \n"
" | \n"
" | \n"
" | \n"
" | \n"
" ----- \n",
" ------------- \n"
" |           | \n"
" |           O \n"
" | \n"
" | \n"
" | \n",
" ------------- \n"
" |           | \n"
" |           O \n"
" |           | \n"
" | \n"
" | \n"
" ----- \n",
" ------------- \n"
" |           | \n"
" |           O \n"
" |          /| \n"
" | \n"
" | \n"
" ----- \n",
" ------------- \n"
" |           | \n"
" |           O \n"
" |          /|\\ \n"
" | \n"
" | \n"
" ----- \n",
" ------------- \n"
" |           | \n"
" |           O \n"
" |          /|\\   \n"
" |          /       \n"
" | \n"
" ----- \n",
" ------------- \n"
" |           | \n"
" |           O \n"
" |          /|\\ \n"
" |          / \\ \n"
" | \n"
" ----- \n",
};
string WORD_LIST[] = {
"angle", "ant", "apple", "arch", "arm", "army",
"baby", "bag", "ball", "band", "basin", "basket", "bath", "bed", "bee", "bell", "berry",
"bird", "blade", "board", "boat", "bone", "book", "boot", "bottle", "box", "boy",
"brain", "brake", "branch", "brick", "bridge", "brush", "bucket", "bulb", "button",
"cake", "camera", "card", "cart", "carriage", "cat", "chain", "cheese", "chest",
"chin", "church", "circle", "clock", "cloud", "coat", "collar", "comb", "cord",
"cow", "cup", "curtain", "cushion",
"dog", "door", "drain", "drawer", "dress", "drop", "ear", "egg", "engine", "eye",
"face", "farm", "feather", "finger", "fish", "flag", "floor", "fly",
"foot", "fork", "fowl", "frame", "garden", "girl", "glove", "goat", "gun",
"hair", "hammer", "hand", "hat", "head", "heart", "hook", "horn", "horse",
"hospital", "house", "island", "jewel", "kettle", "key", "knee", "knife", "knot",
"leaf", "leg", "library", "line", "lip", "lock",
"map", "match", "monkey", "moon", "mouth", "muscle",
"nail", "neck", "needle", "nerve", "net", "nose", "nut",
"office", "orange", "oven", "parcel", "pen", "pencil", "picture", "pig", "pin",
"pipe", "plane", "plate", "plow", "pocket", "pot", "potato", "prison", "pump",
"rail", "rat", "receipt", "ring", "rod", "roof", "root",
"sail", "school", "scissors", "screw", "seed", "sheep", "shelf", "ship", "shirt",
"shoe", "skin", "skirt", "snake", "sock", "spade", "sponge", "spoon", "spring",
"square", "stamp", "star", "station", "stem", "stick", "stocking", "stomach",
"store", "street", "sun", "table", "tail", "thread", "throat", "thumb", "ticket",
"toe", "tongue", "tooth", "town", "train", "tray", "tree", "trousers", "umbrella",
"wall", "watch", "wheel", "whip", "whistle", "window", "wire", "wing", "worm",
};
const int WORD_COUNT = sizeof(WORD_LIST) / sizeof(string);
string chooseWord()
{
	 int randomIndex = rand() % WORD_COUNT;
     return WORD_LIST[randomIndex];

}
bool contains(string word,char guess)
{
	for(int i=0;i<word.length();i++)
	{
		if(guess==word[i])return true;
	}
	return false;
}
string update(string guessedWord, string word, char guess)
{
            for (int i = word.length() - 1; i >= 0; i--)
			{
                    if (word[i] == guess)
					{
                        guessedWord[i] = guess;
                    }
            }
           return guessedWord;
}
void renderGame(string guessedWord, int badGuessCount)
{
    cout << FIGURE[badGuessCount] << endl;
    cout << guessedWord << endl;
    cout << "Number of wrong guesses: " << badGuessCount << endl;
}
int main()
{
    const int MAX_BAD_GUESSES = 7;
	char guess;
	string word=chooseWord();
	string guessedWord = string(word.length(), '-');
	int badGuessCount = 0;
	do
	{
		renderGame(guessedWord,badGuessCount);
	    cin>>guess;
		if (contains(word, guess))
		{
			guessedWord = update(guessedWord, word, guess);
		}
        else badGuessCount++;
	}while(badGuessCount<=MAX_BAD_GUESSES&&guessedWord!=word);
	if (badGuessCount < MAX_BAD_GUESSES) cout << "Congratulations! You win!";
    else cout << "You lost. The correct word is " << word;
	return 0;
}











