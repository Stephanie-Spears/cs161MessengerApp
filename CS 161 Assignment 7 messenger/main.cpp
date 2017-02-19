#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <istream>
#include <cstring>
#include <algorithm>


using namespace std;

int main()
{
	string TranslatedInput;
	string CallEngToSMS();
	string CallSMSToEng();
	int CallMenu();
	int Menu_Result;
	bool bRun_Code;
	
	bRun_Code = true;

		cout << "Welcome to the English/SMS translator service." << endl << endl;

		while (bRun_Code == true)
		{
			Menu_Result = CallMenu();

			while (Menu_Result != 3)
			{
				if (Menu_Result == 1)
				{
					TranslatedInput = CallEngToSMS();
					cout << "Translation: " << TranslatedInput << endl << endl;
					break;
				}
				else if (Menu_Result == 2)
				{
					TranslatedInput = CallSMSToEng();
					cout << "Translation: " << TranslatedInput << endl << endl;
					break;
				}
				else
				{
					cout << "Error--DEBUG MESSAGE 1" << endl;
				}
			}
			if (Menu_Result == 3)
			{
				cout << endl <<  "Ok. Bye" << endl << endl;
				bRun_Code = false;
			}
		}
		
			return (0);
}



int CallMenu()
{
	bool ValidInput;
	string sMenu_Result;
	stringstream ssMenu_Result;
	int Menu_Result;

ValidInput = false;

while (ValidInput == false)
{
	cout << "1) Translate English to SMS " << endl;
	cout << "2) Translate SMS to English " << endl;
	cout << "3) Quit " << endl;
	cout << "Enter Choice: ";
	getline(cin, sMenu_Result);

	if ((sMenu_Result != "1") && (sMenu_Result != "2") && (sMenu_Result != "3"))
	{
		cout << "'" << sMenu_Result << "'" << " is not a valid menu choice. Please try again." << endl << endl;
		cin.clear();
		sMenu_Result = "";
	}
	else
	{
		ssMenu_Result << sMenu_Result;
		ssMenu_Result >> Menu_Result;
		return Menu_Result;
	}
}

return (0);
}


string CallEngToSMS()
{
	string FindText;
	string ReplaceText;
	int i;

	bool ValidInput;
	string UserInput;
	string TranslatedInput;
	string sms_phrases[12] = { "brb", "btw", "bff", "fwiw", "gr8", "imho", "l8r", "omw", "np", "tmi", "ttyl", "wywh" };
	string eng_phrases[12] = { "be right back", "by the way", "best friends forever", "for what its worth", "great", "in my humble opinion", "later", "on my way", "no problem", "too much information", "talk to you later", "wish you were here" };


	ValidInput = false;
	while (ValidInput == false)
	{
		cout << "Enter an English sentence or phrase: ";
		getline(cin, UserInput);
		transform(UserInput.begin(), UserInput.end(), UserInput.begin(), tolower);
		UserInput.erase(remove_if(UserInput.begin(), UserInput.end(), (ispunct)), UserInput.end());

		TranslatedInput = UserInput;
		i = 0;
		while (i < 12)
		{
			FindText = eng_phrases[i];
			ReplaceText = sms_phrases[i];
			if (TranslatedInput.find(FindText) != string::npos)
			{
				TranslatedInput = TranslatedInput.replace(TranslatedInput.find(FindText), FindText.length(), ReplaceText);
			}
			++i;
		}
		if (TranslatedInput.length() == UserInput.length())
		{
			cout << "No translations found." << endl;

		}

		else
		{
			return TranslatedInput;
		}
	}
	return "OOPSIES"; 
}

string CallSMSToEng()
{
	string FindText;
	string ReplaceText;

	bool ValidInput;
	string UserInput;
	int i;
	string TranslatedInput;
	string sms_phrases[12] = { "brb", "btw", "bff", "fwiw", "gr8", "imho", "l8r", "omw", "np", "tmi", "ttyl", "wywh" };
	string eng_phrases[12] = { "be right back", "by the way", "best friends forever", "for what it's worth", "great", "in my humble opinion", "later", "on my way", "no problem", "too much information", "talk to you later", "wish you were here" };


	ValidInput = false;
	while (ValidInput == false)
	{
		cout << "Enter a sentence containing SMS: ";
		getline(cin, UserInput);
		transform(UserInput.begin(), UserInput.end(), UserInput.begin(), tolower);
		UserInput.erase(remove_if(UserInput.begin(), UserInput.end(), (ispunct)), UserInput.end());

		TranslatedInput = UserInput;
		i = 0;

		while (i < 12)
		{
			FindText = sms_phrases[i];
			ReplaceText = eng_phrases[i];
			if (TranslatedInput.find(FindText) != string::npos)
			{
				TranslatedInput = TranslatedInput.replace(TranslatedInput.find(FindText), FindText.length(), ReplaceText);
			}
			++i;
		}
		if (TranslatedInput.length() == UserInput.length())
		{
			cout << "No translations found." << endl;
		}
		else
		{
			return TranslatedInput;
		}
	}
	return "OOPS!" ;

}