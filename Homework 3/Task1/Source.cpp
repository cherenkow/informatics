#include<iostream>
#include<clocale>
using namespace std;
void printMenu()
{
    cout << "�������� ��������" << endl;
    cout << "" << endl;
    cout << "0 - �����" << endl;
    cout << "1 - ������ � ����� � ���������� " << endl;
    cout << "2 - �������� � ��������� ����� �� � �� �" << endl;
    cout << "3 - ������� ������ " << endl;
    cout << "4 - ����� ������� �������� " << endl;
    cout << "5 - ���������� ������� � �������" << endl;
    cout << "6 - ����������� ��������" << endl;
    cout << "7 - ������� �������� � ������ " << endl;
    cout << "8 - �������� ��������� ������ ������ ���������" << endl;
    cout << "9 - ����� ���������������������" << endl;
    cout << endl;
}



void expandArray(int*& arr)
{
    int newCapacity = *(arr - 1) * 2;
    int* temp = new int[newCapacity + 2];
    temp += 2;
    for (int i = -2; i < *(arr - 1); i += 1)
    {
        temp[i] = arr[i];
    }
    *(temp - 1) *= 2;
    arr -= 2;
    delete[] arr;
    arr = temp;
}

void unify(int*& arr, int*& crr) {
    int newCapacity = *(arr - 2) + *(crr - 2);
    int* temp = new int[newCapacity + 2];
    temp += 2;
    if (*(arr - 2) < *(crr - 2)) {
        for (int i = 0; i < *(arr - 2); i += 1) {
            *(temp + i * 2) = *(arr + i);
            *(temp + i * 2 + 1) = *(crr + i);
        }
        int k = *(arr - 2);
        for (int i = *(arr - 2) * 2; i < newCapacity; ++i) {
            *(temp + i) = *(crr + k);
            k += 1;
        }
    }
    else {
        for (int i = 0; i < *(crr - 2); i += 1) {
            *(temp + i * 2) = *(arr + i);
            *(temp + i * 2 + 1) = *(crr + i);
        }
        int k = *(crr - 2);
        for (int i = *(crr - 2) * 2; i < newCapacity; ++i) {
            *(temp + i) = *(arr + k);
            k += 1;
        }
    }
    *(temp - 2) = newCapacity;
    *(temp - 1) = newCapacity;
    arr -= 2;
    delete[] arr;
    arr = temp;

}


void printArray(int* arr)
{
    cout << "{ ";
    for (int i = 0; i < *(arr - 2); ++i)
    {
        cout << arr[i] << " ";
    }
    cout << "}" << endl;
}

void addEl(int*& arr, int N, int A, int B)
{
    int k = *(arr - 2);
    int c = *(arr - 1);
    for (int i = k; i < k + N; ++i) {
        if (i == *(arr - 1)) {
            expandArray(arr);
        }
        *(arr + i) = rand() % (B - A + 1) + A;
        *(arr - 2) += 1;
    }
}

void newEl(int*& arr, int x) {
    if (*(arr - 2) == *(arr - 1)) {
        expandArray(arr);
    }
    *(arr + *(arr - 2)) = x;
    *(arr - 2) += 1;

}

void keyboard(int*& arr, int n) {
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        newEl(arr, x);
    }
}
int elementSearch(int* arr, int x) {
    for (int i = 0; i < *(arr - 2); ++i)
        if (*(arr + i) == x) {
            return i;
            break;
        }
}

void insert(int*& arr, int n, int x) {
    if (*(arr - 2) == *(arr - 1)) {
        expandArray(arr);
    }
    for (int i = *(arr - 2) - 1; i > n; --i) {
        *(arr + i) = *(arr + i - 1);
    }
    arr[n] = x;
}

void addArray(int*& arr, int*& brr) {
    if (*(arr - 2) + *(brr - 2) >= *(brr - 1)) {
        expandArray(arr);
    }
    for (int i = 0; i < *(brr - 1); ++i) {
        *(arr + *(arr - 2)) = *(brr + i);
        *(arr - 2) += 1;
    }
}

int deleteGroup(int*& arr, int si, int count) {
    if ((si + count <= *(arr - 2)) && si > -1 && count > 0) {
        int* temp = new int[*(arr - 1) + 2];
        temp += 2;
        int k = 0;
        for (int i = 0; i < si; i += 1)
        {
            temp[i] = arr[i];
            k++;
        }
        for (int i = si + count; i < *(arr - 2); i += 1)
        {
            temp[k] = arr[i];
            k++;
        }
        *(temp - 1) = *(arr - 1);
        *(temp - 2) = *(arr - 2) - count;
        arr -= 2;
        delete[] arr;
        arr = temp;
        return 0;
    }
    else {
        return 1;
    }

}

int seqSearch(int* arr, int* drr) {
    if (*(arr - 2) < *(drr - 2)) {
        return -1;
    }
    else {
        int k = 0;
        int t =-1;
        for (int i = 0; i <= *(arr - 2) - *(drr - 2); i++) {
            if (*(arr + i) == *(drr + k)) {
                t = i;
                break;
            }
        }
        if (t != -1) {
            for (int i = t; i < t + *(drr - 2); i++) {
                if (*(arr + i) == *(drr + k)) {
                    k += 1;
                }
            }
            if (k == *(drr - 2)) {
                return t;
            }
            else {
                return -1;
            }
        }
        else { return -1; }

    }
}
void switchCase(int choice, int*& a, int*& b, int* c) {
    cout << endl;
    switch (choice)
    {
    case 1: {
        cout << "��������: 1 ��� 2 ������ ?" << endl;
        int c1;
        cin >> c1;
        cout << "������� ����� ������?" << endl;
        int n;
        cin >> n;
        cout << "������� �����" << endl << endl;
        (c1 == 1 ? keyboard(a, n) :keyboard(b, n));
        (c1 == 1 ? printArray(a) : printArray(b));
        cout << endl << endl;
    }
        break;
    case 2:
        cout << "��������: 1 ��� 2 ������ ?" << endl;
        int c2;
        cin >> c2;
        cout << "������� n, a, b" << endl;
        int N;
        int A;
        int B;
        cin >> N;
        cin >> A;
        cin >> B;
        (c2 == 1 ? addEl(a, N, A, B): addEl(b, N, A, B) );
        (c2 == 1 ? printArray(a) : printArray(b));
        cout << endl << endl;
        break;

    case 3: 
        cout << "��������: 1 ��� 2 ������ ?" << endl;
        int c3;
        cin >> c3;
        (c3 == 1 ? printArray(a) : printArray(b));
        cout << endl << endl;
        break;
    case 4:
        cout << "��������: 1 ��� 2 ������ ?" << endl;
        int c4;
        cin >> c4;
        cout << "����� ������� �����?" << endl;
        int x;
        cin >> x;
        cout << "������ �������� ��������:" << (c4 == 1 ? elementSearch(a,x) : elementSearch(b,x));
        cout << endl << endl;
        break;
    case 5: {
        cout << "�������: � ������ ������� ��������� ������ ������?" << endl;
        int l;
        cin >> l;
        (l == 1 ? addArray(a, b) : addArray(b, a));
        (l == 1 ? printArray(a) : printArray(b));
        cout << endl << endl;
    }
          break;
    case 6: {
        cout << "�������: � ������ ������� �������� �����������?" << endl;
        int k;
        cin >> k;
        (k == 1 ? unify(a, b) : unify(b, a));
        (k == 1 ? printArray(a) : printArray(b));
        cout << endl << endl;
    }
          break;
    case 7:
        cout << "������� ������" << endl;
        int nn;
        cin >> nn;
        cout << "����� ������� �� ��� �����?" << endl;
        int xx;
        cin >> xx;
        insert(a, nn, xx);
        printArray(a);
        cout << endl << endl;
        break;
    case 8:
        cout << "�������: �� ������ ������� �������?";
        int c8;
        cin >> c8;
        cout << "������� ������ ������� ���������� ��������" << endl;
        int si;
        cin >> si;
        cout << "������� ��������� �������?" << endl;
        int count;
        cin >> count;
        deleteGroup(a, si, count);
        (c8 == 1 ? deleteGroup(a, si, count) : deleteGroup(b, si, count));
        (c8 == 1 ? printArray(a) : printArray(b));
        cout << endl << endl;
        break;
    case 9:
        cout << "�������: � ����� ������� ����?";
        int c9;
        cin >> c9;
        cout << "������� ��������� � ������� ������������������?" << endl;
        int m;
        cin >> m;
        cout << "������� �������� ������������������" << endl;
        keyboard(c, m);
       cout <<  (c9 == 1 ? seqSearch(a,c) : seqSearch(b, c));
        deleteGroup(c, 0, m);
        cout << endl << endl;
        break;
    }


}

int main()
{
    setlocale(LC_ALL, "Russian");

    int* a = new int[5 + 2];
    a += 2;
    *(a - 2) = 0;
    *(a - 1) = 5;
    int* b = new int[5 + 2];
    b += 2;
    *(b - 2) = 0;
    *(b - 1) = 5;
    int* c = new int[5 + 2];
    c += 2;
    *(c - 2) = 0;
    *(c - 1) = 5;
    int choice = -1;
    while (choice != 0)
    {
        printMenu();
        cin >> choice;
        switchCase(choice, a, b, c );
    }
   
    a -= 2;
    delete[] a;
    b -= 2;
    delete[] b;
    c -= 2;
    delete[] c;
    return 0;
}