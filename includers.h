#include <iostream>
#include <string>
#include <fstream>

using namespace std;

typedef unsigned short int unshint;

//шифрование сообщения
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

//проверка мощности алфавита
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

//проверка ключа шифрования
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

//проверка на недопустимые символы
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

//проверка на правильность ввода пути папки
void CheckPath(const string& FileName, const string& messageToEncrypt)
{
	char UserSelection = 'n';

	do {
		if (UserSelection == 'y')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		//ввод пути сохранения файла
		cout << "Enter path to save file(as C:/Users/Public/Documents: ";
		string FolderFilename;

		getline(cin, FolderFilename);
		//проверка на ввод названия пути папки сохранения
		if (FolderFilename == "")
			FolderFilename = "C:/Users/Public/Documents";
		FolderFilename += "/" + FileName;

		//запись шифрованого сообщения в файл
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