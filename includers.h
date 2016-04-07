#include <iostream>
#include <string>
#include <fstream>

using namespace std;

typedef unsigned short int unshint;

//Encrypting messages
void Encrypt(string& messageToEncrypt, const int& keyEncrypt)
{
	string copyMessage, encryptMessage;
	char cArray[2] = { '\0' };
	for (size_t i = 0; i < messageToEncrypt.length(); ++i)
	{
		copyMessage = messageToEncrypt[i];
		strcpy_s(cArray, copyMessage.c_str());
		if (keyEncrypt > -1)
			cArray[0] += keyEncrypt;
		else
			cArray[0] -= keyEncrypt;
		encryptMessage.push_back(cArray[0]);
	}
	messageToEncrypt = encryptMessage;
}

//Check the encryption key in the overflow, the valid values and input characters
void checkKey(unshint& powerKey, int& keyEncrypt)
{
	while (!(powerKey >= 0 && powerKey <= 255))
	{
			cout << "Exceeded the value of the power of the alphabet! Enter again: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> powerKey;
	}	
	keyEncrypt %= powerKey;
}

//Check the power of the alphabet on the overflow, the valid values and input characters
void check(int& keyEncrypt)
{
	while (!(keyEncrypt > -100000 && keyEncrypt < 100000))
	{
		cout << "Exceeded the value of the key to encrypt! Enter again: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> keyEncrypt;
	}
}

//Check to enter invalid characters in the file name and delete them
void ErazeSymbol(string& Input)
{
	string findSymbol("<>/\\|\"*?:");
	for (size_t i = 0; i < 10; ++i)
	{
		size_t searchSymbol = Input.find(findSymbol[i], 0);
		while (searchSymbol != string::npos)
		{
			size_t SearchPos = searchSymbol;
			Input.erase(searchSymbol, 1);
			searchSymbol = Input.find(findSymbol[i], SearchPos);
		}
	}
}

//Checking the admissibility of the way to save the file
void CheckPath(const string& FileName, const string& messageToEncrypt)
{
	char UserSelection = 'n';

	do {
		if (UserSelection == 'y')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		
		cout << "Enter path to save file(as C:/Users/Public/Documents: ";
		string FolderFilename;

		getline(cin, FolderFilename);
		//Check for input path
		if (FolderFilename == "")
			FolderFilename = "C:/Users/Public/Documents";
		FolderFilename += "/" + FileName;

		//file creation
		ofstream file(FolderFilename, ios_base::out);
		if (file.is_open())
		{
			file << messageToEncrypt << endl;
			file.close();
			cout << "Encrypt message is saving in " << FolderFilename << endl;
			UserSelection = 'n';
		}
		else
		{
			cout << "Warning, you enter the wrong path to the folder or a destination folder does not exist! Do you want to re-enter the path to the folder? ";
			cin >> UserSelection;
		}
	} while (UserSelection == 'y');
}
