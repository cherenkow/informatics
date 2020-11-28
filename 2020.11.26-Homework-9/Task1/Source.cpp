#include<iostream>
#include<clocale>
#include<string>
using namespace std;

void resolveError(int er) {
	switch (er) {
	case 1: {
		int var = rand() % (1 + 2 + 1) - 2;
		if (var >= 0) {
			cout << "��� ����� ����� ����������� �������" << endl;
		}
		else {
			cout << "������ �� ������ ��������� �������� ��, �� ����� ��� �����  ����� �����" << endl;
		}
	}
		  break;
	case 2: {
		int var = rand() % (1 + 2 + 1) - 2;
		if (var >= 0) {
			cout << "�� ����������� ������� ������� �������, ����� ����" << endl;
		}
		else {
			cout << "� ���� ���������� ������ �����, ������ ������� ���" << endl;
		}
	}
		  break;
	case 3: {
		int var = rand() % (1 + 2 + 1) - 2;
		if (var >= 0) {
			cout << "�������, �� ������ ������ ������" << endl;
		}
		else {
			cout << "������ �����, ����� ���-�� ������" << endl;
		}
	}
		  break;
	case 4: {
		int var = rand() % (1 + 2 + 1) - 2;
		if (var >= 0) {
			cout << "��������� ����:" << endl;
		}
		else {
			cout << "����������, ������� ����� ��� ���" << endl;
		}
	}
		  break;
	case 5: {
		int var = rand() % (1 + 2 + 1) - 2;
		if (var >= 0) {
			cout << "������� ��� ������ ���������� �����" << endl;
		}
		else {
			cout << "�� ��������, ���������� ������ ����� ���� double" << endl;
		}
	}
		  break;
	}
}

bool isDigit(char symbol) {
	if (symbol >= '0' && symbol <= '9') {
		return true;
	}
	return false;
}

int readInt(string& str) {
	bool check = false;
	long long result1 = 0;
	while (check != true) {

		int tab = 0; // ���� �� ������� 
		int symb = 0; // ���� �� �����
		int length = 0; //

		getline(cin, str);

		for (int i = 0; str[i] != '\0'; ++i) {
			length += 1;
			(str[i] == ' ' ? tab += 1 : tab += 0);
			(isDigit(str[i]) == false && str[i] != ' ' ? symb += 1 : symb += 0);
		}


		if (tab > 0 && symb > 0) {
			resolveError(1);
			resolveError(2);
			resolveError(4);
			continue;
		}
		if (tab > 0) {
			resolveError(1);
			resolveError(4);
			continue;
		}
		else if (symb > 0) {
			resolveError(2);
			resolveError(4);
			continue;
		}
		else if (length == 0) {
			resolveError(3);
			resolveError(4);
			continue;
		}
		for (int i = 0; str[i] != '\0'; ++i) {
			result1 = result1 * 10 + str[i] - '0';
		}
		check = true;
	}
	return result1;
}

double readDouble(string& str) {
	bool check = false;
	double result2 = 1.0;
	while (check != true) {

		int tab = 0; // ���� �� ������� 
		int symb = 0; // ���� �� �����
		int lastDigit = -1; //��������� �� ��������� ������ � ������
		int length = 0; //
		int dot = 0;
		int dotIndex = -1;
		int digitCount = 0;
		getline(cin, str);

		for (int i = 0; str[i] != '\0'; ++i) {
			length += 1;
			(str[i] == ' ' ? tab += 1 : tab += 0);
			(str[i] == '.' ? dot += 1 : dot += 0);
			(isDigit(str[i]) == true ? digitCount += 1 : digitCount += 0);
			//��������� ������� ����� ������� � ����� 
			(isDigit(str[i]) == false && str[i] != ' ' && str[i] != '.' ? symb += 1 : symb += 0);
			(isDigit(str[i]) == true && i >= 1 && str[i - 1] == '.' ? lastDigit = i - 2 : lastDigit += 0);
		}
		if (dot == 1 && digitCount >= 2) {
			for (int i = 0; str[i] != '\0'; ++i) {
				if (str[i] == '.') {
					dotIndex = i;
					break;
			}
			}
		}
		if (dot == 1 && tab == 0 && symb == 0 && length != 0 && digitCount >= 2 && dotIndex >= 1) {
			cout << endl;
			double result1 = 0;
			double rusult2 = (double)1/2;
			cout << "result1 = " << result1 << endl;
			cout << "result2 = " << result2 << endl;
			for (int i = 0; i < dotIndex; ++i) {
				result1 = result1 * 10 + str[i] - '0';
			}
			int kol = 0;
			for (int i = dotIndex + 1; str[i] != '\0'; ++i) {
				result1 = result1 * 10 + str[i] - '0';
				kol += 1;
			}
			int d = 1;
			while (kol > 1) {
				d *= 10;
				kol--;
			}
			cout << "d = " << d << endl;
			cout << "dotIndex = " << dotIndex << endl;
			cout << "result1 = " << result1 << endl;
			result1 = (result1 * 1.0) /d;

			cout << "���� ������� ����� " << result1 << endl;

		}
		else {
			if (tab > 0 && symb > 0 && dot > 1) {
				resolveError(1);
				resolveError(2);
				resolveError(4);
				continue;
			}
			if (tab > 0 && dot > 1) {
				resolveError(1);
				resolveError(4);
				continue;
			}
			else if (symb > 0 && dot > 1) {
				resolveError(1);
				resolveError(2);
				resolveError(4);
				continue;
			}
			else if (tab > 0 && symb > 0 && (dot == 1 || dot == 0)) {
				resolveError(1);
				resolveError(4);
				continue;
			}
			else if (tab > 0 && (dot == 1 || dot == 0)) {
				resolveError(1);
				resolveError(4);
				continue;
			}
			else if (symb > 0 && (dot == 1 || dot == 0)) {
				resolveError(2);
				resolveError(4);
				continue;
			}
			else if (dot == 0) {
				resolveError(5);
				resolveError(4);
				continue;
			}
			else if (length == 0) {
				resolveError(3);
				resolveError(4);
				continue;
			}
			else {
				cout << "�� ������� ��� ����� ���� ����� �������, ������� ������� ��� ���" << endl;
			}
		}
	}
	return result2;
}



int main() {
	setlocale(LC_ALL, "Russian");
	string str;
	cout << "������� ������ �����" << endl;
	long long chislo1 = readInt(str);
	cout << "���� ������� ����� " << chislo1 << endl;
	cout << "������� ����� ������ ������ �����" << endl;
	double chislo2 = readDouble(str);
	cout << "���� ������� ����� " << chislo2 << endl;


	return 0;
}