#include <iostream>
using namespace std;
void printBits(short s)
{
	int bitlength = sizeof(s) * 8;
	int k = 0;
	for (int i = 0; i < bitlength; ++i)
	{
		k++;
		unsigned short bit = s;
		bit = bit << i;
		bit = bit >> (bitlength - 1);
		cout << bit;
		if (k % 8 == 0) {
			cout << " ";
		}
	}
}
void printBits(int s)
{
	int bitlength = sizeof(s) * 8;
	int k = 0;
	for (int i = 0; i < bitlength; ++i)
	{
		k++;
		unsigned int bit = s;
		bit = bit << i;
		bit = bit >> (bitlength - 1);
		cout << bit;
		if (k % 8 == 0) {
			cout << " ";
		}
	}
}
void printBits( long s)
{
	int bitlength = sizeof(s) * 8;
	int k = 0;
	for (int i = 0; i < bitlength; ++i)
	{
		k++;
		unsigned long bit = s;
		bit = bit << i;
		bit = bit >> (bitlength - 1);
		cout << bit;
		if (k % 8 == 0) {
			cout << " ";
		}
	}
}
void printBits(long long  s)
{
	int bitlength = sizeof(s) * 8;
	int k = 0;
	for (int i = 0; i < bitlength; ++i)
	{
		k++;
		unsigned long long bit = s;
		bit = bit << i;
		bit = bit >> (bitlength - 1);
		cout << bit;
		if (k % 8 == 0) {
			cout << " ";
		}
	}
}
int binaryInt(int s) {
	int k = 0;
	while (s >= 2) {
		k++;
		s = s / 2;
	}
	return k;
}
void binaryprInt(int s,int bits,int t = 0, int n = 23) {
	int k = 0;
	int* arr = new int[n] { 0 };
	while (s >= 2) {
		k++;
		arr[k - 1] = s % 2;
		s = s / 2;
	}
	arr[k] = s % 2;
	(t == 0 ? k += 0 : k -= 1);
	for (int i = k; i >= 0; --i) {
		if (bits % 8 == 0) {
			cout << " ";
		}
		cout << arr[i];
		bits += 1;
	}
}
void binaryR(float f,int bits, int k, int n = 23) {
	float ff = f - (int)f;
	for (int i = k + 1; i <= n; ++i) {
		if (ff > 0) {
			ff *= 2;
			if (bits % 8 == 0) {
				cout << " ";
			}
			cout << (int)(ff);
			ff = ff - (int)ff;
			bits += 1;
			continue;
		}
		if (bits % 8 == 0) {
			cout << " ";
		}
		cout << "0";
		bits += 1;

	}
}
void printBits(double f) {
	if (f > 0) {
		cout << "0";
	}
	else {
		cout << "1";
		f *= (-1);
	}
	int k = binaryInt(int(f));
	binaryprInt(k + 1023,1,0,52);
	binaryprInt(int(f),12, 1, 52);
	binaryR(f,12+k, k, 52);
}

void printBits(float f) {
	if (f > 0) {
		cout << "0";
	}
	else {
		cout << "1";
		f *= (-1);
	}
	int k = binaryInt(int(f));
	binaryprInt(k + 127,1);
	binaryprInt(int(f),9, 1);
	binaryR(f,9+k, k);
}

void printBits(long double f) {
	printBits((double)f);
}

int main() {
	short a = 0;
	cin >> a;
	printBits(a);
	cout << endl;

	int b = 0;
	cin >> b;
	printBits(b);
	cout << endl;

	long c = 0;
	cin >> c;
	printBits(c);
	cout << endl;

	long long d = 0;
	cin >> d;
	printBits(c);
	cout << endl;

	float f = 0;
	cin >> f;
	printBits(f);
	cout << endl;

	double g = 0;
	cin >> g;
	printBits(g);
	cout << endl;

	long double h = 0;
	cin >> h;
	printBits(h);

	
	return 0;
}