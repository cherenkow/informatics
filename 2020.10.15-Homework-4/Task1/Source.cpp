#include<iostream>
#include<clocale>
#include"ArrayList.h";

void printMenu()
{
	printf("�������� ��������:\n");
	printf("\n");
	printf("0 - �����\n");
	printf("1 - �������� ������� � �����\n");
	printf("2 - �������� ����� ������� � ������������ �����\n");
	printf("3 - �������� ������ ���������\n");
	printf("4 - �������� ������ ��������� � ������������ �����\n");
	printf("5 - ������� ��� �������� ������\n");
	printf("6 - ��������� ������� �������� � ������\n");
	printf("7 - �������� ������� �� �������\n");
	printf("8 - ����� ����� �������\n");
	printf("9 - ��������� ������ �� ������� ���������\n");
	printf("10 - ������� ������ �� ����� \n");
	printf("11 - ������� �������\n");
	printf("12 - �������� �������� �������\n");
	printf("\n");
}



void switchCase(int choice, ArrayList& a) {
	printf("\n");
	switch (choice)
	{
	case 1:
		printf("������� ����� �������:\n");
		int el1;
		std::cin >> el1;
		a.add(el1);
		a.print();

		break;
	case 2:
		printf("������� ����� �������:\n");
		int el2;
		std::cin >> el2;
		printf("������� ������:\n");
		int ix;
		std::cin >> ix;
		a.add(ix, el2);
		a.print();
		break;
	case 3: {
		printf("������� ��������� � ����������� ������? \n");
		int k;
		std::cin >> k;
		ArrayList list(k);
		printf("������� �������� ������: \n");
		for (int i = 0; i < k; ++i) {
			int el3;
			std::cin >> el3;
			list.add(el3);
		}
		a.addAll(list);
		a.print();
	}
		  break;
	case 4:
	{
		printf("������� ��������� � ����������� ������? \n");
		int kk;
		std::cin >> kk;
		ArrayList list1(kk);
		printf("������� �������� ������: \n");
		for (int i = 0; i < kk; ++i) {
			int el4;
			std::cin >> el4;
			list1.add(el4);
		}
		printf("������� ������:");
		int ii;
		std::cin >> ii;
		a.addAll(ii, list1);
		a.print();
	}
	break;
	case 5:
		printf("�������� �������\n");
		a.clear();
		a.print();
		break;
	case 6:
		printf("������� ������� �������: \n");
		int el5;
		std::cin >> el5;
		printf("%d\n", a.contains(el5));
		break;
	case 7:
		printf("������� ������:\n");
		int index;
		std::cin >> index;
		if (a.get(index) != false) {
			printf("������� � �������� %d � ������: %d\n", index, a.get(index));
		}
		else {
			printf("������; ���������� ��� ���\n");
		}
		break;
	case 8:
		printf("������� ������� �������: \n");
		int el6;
		std::cin >> el6;
		if (a.indexOf(el6) > -1) {
			printf("������� %d � ������ ����� ������: %d\n", el6, a.indexOf(el6));
		}
		else {
			printf("������; ���������� ��� ���\n");
		}
		break;
	case 9:
		if (a.isEmpty() == true) {
			printf("list is NOT EMPTY\n");
		}
		else {
			printf("list is EMPTY\n");
		}
		break;
	case 10:
		a.print();
		break;
	case 11:
		printf("������� ������ ���������� �������:\n");
		int d;
		std::cin >> d;
		if (a.remove(d) == true) {
			a.print();
		}
		else {
			printf("���-�� ����� �� ���\n");
		}
		break;
	case 12:
		printf("������� ������� ��������:\n");
		int in1;
		std::cin >> in1;
		int in2;
		std::cin >> in2;
		if (a.swap(in1, in2) == true) {
			a.print();
		}
		else {
			printf("���-�� ����� �� ���\n");
		}
		break;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	ArrayList a;

	int choice = -1;
	while (choice != 0)
	{
		printMenu();
		std::cin >> choice;
		switchCase(choice, a);
	}

	return 0;
}