#include "includers.h"

int main()
{
	//���� ������������� ���������
	cout << "Enter message to encrypt, press \"ENTER\" between sentences. (Ctrl-Z to stop): ";
	string messageToEncrypt, message;
	while (getline(cin, message))
		messageToEncrypt += message + '\n';

	cin.clear();
	
	//���� ����� ����������
	cout << "Enter key to encrypt ( -99999 - 99999): ";
	int keyEncrypt = 100000;
	cin >> keyEncrypt;
	//�������� �� ������������ �����
	check(keyEncrypt);
	
	cin.clear();
	//���� �������� ��������
	cout << "Enter power alphabet (0 - 255): ";
	unshint powerKey = -1;
	cin >> powerKey;
	//�������� �� ������������ �����
	checkKey(powerKey, keyEncrypt);

	//���������� ���������
	Encrypt(messageToEncrypt, keyEncrypt);
	
	cin.clear();
	cin.ignore();
	//���� ����� ���������� ������������� ���������
	cout << "Enter filename to save: ";
	string FileName;
	getline(cin, FileName);
	//�������� �� ����� �������� ����� ����������
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
	
	//�������� �� ������������ ����� ���� ���������� �����
	CheckPath(FileName, messageToEncrypt);
	
	cin.get();
	return 0;
}