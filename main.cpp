#include "includers.h"

int main()
{
	//ввод зашифрованого сообщения
	cout << "Enter message to encrypt, press \"ENTER\" between sentences. (Ctrl-Z to stop): ";
	string messageToEncrypt, message;
	while (getline(cin, message))
		messageToEncrypt += message + '\n';

	cin.clear();
	
	//ввод ключа шифрования
	cout << "Enter key to encrypt ( -99999 - 99999): ";
	int keyEncrypt = 100000;
	cin >> keyEncrypt;
	//проверка на правильность ввода
	check(keyEncrypt);
	
	cin.clear();
	//ввод мощночти алфавита
	cout << "Enter power alphabet (0 - 255): ";
	unshint powerKey = -1;
	cin >> powerKey;
	//проверка на правильность ввода
	checkKey(powerKey, keyEncrypt);

	//шифрование сообщения
	Encrypt(messageToEncrypt, keyEncrypt);
	
	cin.clear();
	cin.ignore();
	//ввод файла сохранения зашифрованого сообщения
	cout << "Enter filename to save: ";
	string FileName;
	getline(cin, FileName);
	//проверка на ввода названия файла сохранения
	if (FileName == "")
		FileName = "New File";
	int inSize = FileName.size();
	ErazeSymbol(FileName);
	if (FileName.size() < inSize)
	{
		cout << "Warning, contains invalid characters, they are automatically deleted! ";
		cout << "Filename has next name: " << FileName << endl;
	}
			
	FileName += ".txt";

	cin.clear();
	
	//проверка на правильность ввода пути сохранения папки
	CheckPath(FileName, messageToEncrypt);
	
	cin.get();
	return 0;
}