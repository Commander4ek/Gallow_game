#include <iostream>
#include <string>
#include <vector>
using namespace std;
class gallows
{
	vector<string> word = { "stranger","victory","peace","grape","student" };
	vector <char> wrong_letters;
	vector <char> used_letters;
	int turnnumber = 1;
	int win_count = 0;
	int lost_count = 0;
	int mistake = 7;
	int correctletters = 0;
public:
	gallows()
	{
	}
	~gallows()
	{

	}
	void win()
	{
		cout << "Congratulations, you won" << endl;
		win_count++;
		turnnumber = 1;
		mistake = 7;
		correctletters = 0;
		used_letters.clear();
		wrong_letters.clear();
	}
	void lost()
	{
		cout << "Game Over, Better Luck next time" << endl;
		lost_count++;
		turnnumber = 1;
		mistake = 7;
		correctletters = 0;
		used_letters.clear();
		wrong_letters.clear();
	}
	int Get_win_count()
	{
		return this->win_count;
	}
	int Get_lost_count()
	{
		return this->lost_count;
	}
	void Get_turn_number()
	{
		cout << "Turn# " << turnnumber << endl;
	}
	int Get_mistake()
	{
		return this->mistake;
	}
	void mistake_find()
	{
		mistake--;
	}
	int end_turn()
	{
		return ++turnnumber;
	}
	void end_round()
	{
		word.erase(word.begin());
	}
	string Get_word_to_play()
	{
		return *(word.begin());
	}
	void Right_Letter()
	{
		correctletters++;
	}
	int Get_right_letters()
	{
		return correctletters;
	}
	void Push_back_to_used_letters(char ch)
	{
		used_letters.push_back(ch);
	}
	bool Check_in_used_letters(char ch)
	{
		int  size = used_letters.size();
		if (size > 0)
		{
			for (int i = 0; i < size; ++i)
			{
				if (ch == used_letters[i])
				{
					return true;
				}
			}
			return false;
		}
		else
		{
			return false;
		}
	}
	void Push_back_to_wrong_letters(char ch)
	{
		wrong_letters.push_back(ch);
	}
	void Show_wrong_letters()
	{
		int size = wrong_letters.size();
		cout << "Wrong letters are:";
		if (size > 0)
		{
			for (int i = 0; i < size; ++i)
			{
				cout << wrong_letters[i] << " ";
			}
			cout << endl;
		}
	}
};


void game(gallows &gall)
{
	string word = gall.Get_word_to_play();
	int size = word.size();
	char *gamefield = new char[size + 1];
	bool exit = false;
	for (int i = 0; i < size; ++i)
	{
		*(gamefield + i) = '_';
		cout << *(gamefield + i) << " ";
	}
	gamefield[size] = '\0';
	cout << endl;
	cout << endl;
	while (exit != true)
	{
		cout << "WIN:" << gall.Get_win_count() << " LOST:" << gall.Get_lost_count() << endl << endl << endl;
		gall.Get_turn_number();
		cout << endl << endl;
		char CheckLetter;
		cout << "Enter your letter:";
		cin >> CheckLetter;
		cout << endl << endl;
		while (CheckLetter < 'a' || CheckLetter > 'z' || gall.Check_in_used_letters(CheckLetter))
		{
			cout << "Ops, try again:";
			cin >> CheckLetter;
		}
		int correctletterbefore = gall.Get_right_letters();
		int i = 0;
		for (char a : word)
		{
			if (a == CheckLetter)
			{
				*(gamefield + i) = CheckLetter;
				gall.Right_Letter();
			}
			i++;
		}
		cout << endl;
		for (int i = 0; i < size; ++i)
		{
			cout << *(gamefield + i) << " ";
		}
		int correctletterafter = gall.Get_right_letters();
		if (correctletterbefore == correctletterafter)
		{
			gall.mistake_find();
			gall.Push_back_to_wrong_letters(CheckLetter);
		}
		cout << endl;
		gall.Show_wrong_letters();
		gall.Push_back_to_used_letters(CheckLetter);
		cout << endl << endl << "You still can make " << gall.Get_mistake() << " mistakes" << endl << endl;
		if (gall.Get_mistake() == 0)
		{
			gall.lost();
			cout << "Are you going to try again? press - 1 to try again, press 0 - to exit application";
			int choice;
			cin >> choice;
			if (choice == 1)
			{
				delete[] gamefield;
				gall.end_round();
				word = gall.Get_word_to_play();
				size = word.size();
				gamefield = new char[size + 1];
				exit = false;
				for (int i = 0; i < size; ++i)
				{
					*(gamefield + i) = '_';
					cout << *(gamefield + i) << " ";
				}
				gamefield[size] = '\0';
				cout << endl;
				cout << endl;
			}
			else
			{
				exit = true;
				delete[] gamefield;
			}
		}
		if (gall.Get_right_letters() == size)
		{
			gall.win();
			cout << "Are you going to try again? press - 1 to try again, press 0 - to exit application";
			int choice;
			cin >> choice;
			if (choice == 1)
			{
				delete[] gamefield;
				gall.end_round();
				word = gall.Get_word_to_play();
				size = word.size();
				gamefield = new char[size + 1];
				exit = false;
				for (int i = 0; i < size; ++i)
				{
					*(gamefield + i) = '_';
					cout << *(gamefield + i) << " ";
				}
				gamefield[size] = '\0';
				cout << endl;
				cout << endl;
			}
			else
			{
				exit = true;
				delete[] gamefield;
			}
		}
		gall.end_turn();
	}
}
void menu(gallows &gall)
{
	cout << "Welcome to my Game" << endl;
	cout << "Press 1 to start, or press 0 to exit";
	int choose;
	cin >> choose;
	while (choose < 0 || choose > 1)
	{
		cout << "Ops, try again:";
		cin >> choose;
	}
	switch (choose)
	{
	case 1:
	{
		game(gall);
		break;
	}
	case 0:
	{
		break;
	}

	}
}

int main()
{
	gallows one;
	menu(one);
	return 0;
}