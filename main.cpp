#include "includers.h"

int main()
{
	//Enter a message
	cout << "Enter message to encrypt, press \"ENTER\" between sentences. (Ctrl-Z to stop): ";
	string messageToEncrypt, message;
	while (getline(cin, message))
		messageToEncrypt += message + '\n';

	cin.clear();
	
	//Enter the encryption key
	cout << "Enter key to encrypt ( -99999 - 99999): ";
	int keyEncrypt = 100000;
	cin >> keyEncrypt;
	//Checking encryption key
	check(keyEncrypt);
	
	cin.clear();
	//Enter power alphabets
	cout << "Enter power alphabet (0 - 255): ";
	unshint powerKey = -1;
	cin >> powerKey;
	//Check the power of the alphabet
	checkKey(powerKey, keyEncrypt);

	//Encrypting messages
	Encrypt(messageToEncrypt, keyEncrypt);
	
	cin.clear();
	cin.ignore();
	//Enter filename
	cout << "Enter filename to save: ";
	string FileName;
	getline(cin, FileName);
	//Check for no input file name
	if (FileName == "")
		FileName = "New File";
	int inSize = FileName.size();
	//Removing invalid characters
	ErazeSymbol(FileName);
	if (FileName.size() < inSize)
	{
		cout << "Warning, contains invalid characters, they are automatically deleted! ";
		cout << "Filename has next name: " << FileName << endl;
	}
			
	FileName += ".txt";

	cin.clear();
	
	//Recording an encrypted message to a file
	CheckPath(FileName, messageToEncrypt);
	
	cin.get();
	return 0;
}
