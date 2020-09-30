#include<iostream>
#include<clocale>
using namespace std;
void printMenu()
{
    cout << "�������� ��������" << endl;
    cout << "" << endl;
    cout << "0 - �����" << endl;
    cout << "1 - �������� �������" << endl;
    cout << "2 - ������� ������" << endl;
    cout << "3 - ����� ����� ������������� ��������" << endl;
    cout << "4 - ����� ����������� �������" << endl;
    cout << "5 - ����� ��������� ������� " << endl;
    cout << "6 - ������� ������ � �������� ������e" << endl;
    cout << endl;
}


int maxEl(int*& arr, int& count)
{
    int t = arr[0];
    for (int i = 1; i < count; ++i) {
        if (t < arr[i]) {
            t = arr[i];
        }
    }
    for (int i = 0; i < count; ++i) {
        if (t ==arr[i]) {
            t = i;
            break;
        }
    }
    return t;

}

int minEl(int*& arr, int& count)
{
    int t = arr[0];
    for (int i = 1; i < count; ++i) {
        if (t > arr[i]) {
            t = arr[i];
        }
    }
    return t;

}

void expandArray(int*& arr, int& capacity)
{
    int newCapacity = capacity * 2;

    int* temp = new int[newCapacity];
    for (int i = 0; i < capacity; ++i)
    {
        temp[i] = arr[i];
    }

    capacity = newCapacity;
    delete[] arr;
    arr = temp;
}

void printArray(int* arr, int count)
{
    cout << "{ ";
    for (int i = 0; i < count; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << "}" << endl;
}

void printBackArray(int* arr, int count)
{
    cout << "{ ";
    for (int i = count - 1; i >= 0; --i)
    {
        cout << arr[i] << " ";
    }
    cout << "}" << endl << endl;
}
void sumArray(int* arr, int length)
{
    int result = 0;
    for (int i = 0; i < length; ++i)
    {
        result += arr[i];
    }
    cout << "����� ��������� �������: " << result << endl << endl;
}

void switchCase(int choice,int& count, int& cap, int*& a) {
    while (choice != 0)
    {
        printMenu();
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            cout << "������� ����� �������" << endl;

            if (count == cap) {
                expandArray(a, cap);
            }
            else {
                int x;
                cin >> x;
                a[count] = x;
                count++;
            }
            cout << endl;
            break;
        case 2:
            printArray(a, count);
            cout << endl;
            break;
        case 3:
            cout << "������ ���� ��������: " << maxEl(a, count) << endl << endl; ;
            break;
        case 4:
            cout << "����������� �������: " << minEl(a, count) << endl << endl;;
            break;
        case 5:
            sumArray(a, count);
            break;
        case 6:
            printBackArray(a, count);
        }

    }

}
int main()
{
    setlocale(LC_ALL, "Russian");

    int cap = 5;
    int count = 0;
    int* a = new int[cap];
    int choice = -1;
    switchCase(choice,count,cap,a);
    return 0;
}