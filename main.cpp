#include <iostream>
#include <cstring>
#include <clocale>
#include "windows.h"
using namespace std;

/*
David Gilmour : Poker2
Roger Waters : Banka
Syd Barrett : Kavga
Rick Wright : Ma�aza
Nick Mason : Mekan�n sahibi
*/

int kartlar[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

class Oyuncu {
	private:
		string isim;
		int para;
		int can;
	public:
		Oyuncu(string isim) {
			this->isim = isim;
			this->can = 100;
			this->para = 1000;
		}
		int para_ogren() {
			return this->para;
		}
		void para_gir(int yeni_para) {
			this->para = yeni_para;
		}
		int can_ogren() {
			return this->can;
		}
		void can_gir(int yeni_can) {
			this->can = yeni_can;
		}
		string isim_ogren() {
			return this->isim;
		}
		void isim_gir(string yeni_isim) {
			this->isim = yeni_isim;
		}
};

int main() {
	bool kazandim = false;
	setlocale(LC_ALL, "Turkish");
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	Oyuncu* malik = new Oyuncu("Nick Mason");
	Oyuncu* poker = new Oyuncu("David Gilmour");
	Oyuncu* banka = new Oyuncu("Roger Waters");
	Oyuncu* kavga = new Oyuncu("Syd Barrett");
	Oyuncu* pazar = new Oyuncu("Rick Wright");
	Oyuncu* sen = new Oyuncu("Sen        ");
	try {
		Sleep(1000);
		SetConsoleTextAttribute(h, 12);
		cout << malik->isim_ogren();
		SetConsoleTextAttribute(h, 7);
		cout << "\t: Kumarekop'a ho� geldin ye�en, benim ad�m " << malik->isim_ogren() << ", bu mekan�n sahibi benim" << endl;
		Sleep(2000);
		SetConsoleTextAttribute(h, 12);
		cout << malik->isim_ogren();
		SetConsoleTextAttribute(h, 7);
		cout << "\t: Buraya geldi�ine g�re kumar oynamay� seven bir yap�n var" << endl;
		Sleep(2000);
		SetConsoleTextAttribute(h, 12);
		cout << malik->isim_ogren();
		SetConsoleTextAttribute(h, 7);
		cout << "\t: Ben de gen�li�imde �ok severdim ama t�m param� bat�rd�m" << endl;
		Sleep(2000);
		SetConsoleTextAttribute(h, 12);
		cout << malik->isim_ogren();
		SetConsoleTextAttribute(h, 7);
		cout << "\t: Ve art�k ak�lland�m, kumar� b�rakt�m ama " << poker->isim_ogren() << " hala oynuyor" << endl;
		Sleep(2000);
		SetConsoleTextAttribute(h, 12);
		cout << malik->isim_ogren();
		SetConsoleTextAttribute(h, 7);
		cout << "\t: Ama senin inatla bu i�lere bula�ma gibi bir iste�in var anla��lan" << endl;
		Sleep(2000);
		SetConsoleTextAttribute(h, 12);
		cout << malik->isim_ogren();
		SetConsoleTextAttribute(h, 7);
		cout << "\t: ��eri girmek istiyorsan ad�n� ��renmem laz�m" << endl;
		Sleep(2000);
		SetConsoleTextAttribute(h, 9);
		cout << sen->isim_ogren();
		SetConsoleTextAttribute(h, 7);
		cout << "\t: ";
		string isim;
		cin.ignore(0);
		getline(cin, isim, '\n');
		Sleep(1000);
		if (isim == malik->isim_ogren()) {
			throw 467;
		}
		if (isim == poker->isim_ogren()) {
			throw 468;
		}
		if (isim == banka->isim_ogren()) {
			throw 469;
		}
		if (isim == kavga->isim_ogren()) {
			throw 470;
		}
		if (isim == pazar->isim_ogren()) {
			throw 471;
		}
		sen->isim_gir(isim);
		SetConsoleTextAttribute(h, 12);
		cout << malik->isim_ogren();
		SetConsoleTextAttribute(h, 7);
		cout << "\t: Tamamd�r " << isim << ", �imdi bana ya��n� s�yleyebilir misin" << endl;
		Sleep(2000);
		SetConsoleTextAttribute(h, 9);
		cout << sen->isim_ogren();
		SetConsoleTextAttribute(h, 7);
		cout << "\t: ";
		int yas;
		cin >> yas;
		Sleep(1000);
		if (yas < 18) {
			throw 472;
		}
		if (yas > 99) {
			throw 473;
		}
		SetConsoleTextAttribute(h, 12);
		cout << malik->isim_ogren();
		SetConsoleTextAttribute(h, 7);
		cout << "\t: Tamamd�r, o zaman seni mekan�m�za alal�m ��yle" << endl;
	}
	catch(int err) {
		if (err == 467) {
			SetConsoleTextAttribute(h, 12);
			cout << malik->isim_ogren();
			SetConsoleTextAttribute(h, 7);
			cout << "\t: Benim ada��m olan kimseler, bu mekana giremez" << endl;
			Sleep(2000);
			SetConsoleTextAttribute(h, 12);
			cout << malik->isim_ogren();
			SetConsoleTextAttribute(h, 7);
			cout << "\t: (Sana silah �eker...)" << endl;
			Sleep(2000);
			SetConsoleTextAttribute(h, 12);
			cout << malik->isim_ogren();
			SetConsoleTextAttribute(h, 7);
			cout << "\t: PAT! (�ld�n...)" << endl;
		}
		if (err > 467 && err < 472) {
			SetConsoleTextAttribute(h, 12);
			cout << malik->isim_ogren();
			SetConsoleTextAttribute(h, 7);
			cout << "\t: Benim arkada�lar�m�n ada�� olan kimseler, bu mekana giremez" << endl;
			Sleep(2000);
			SetConsoleTextAttribute(h, 12);
			cout << malik->isim_ogren();
			SetConsoleTextAttribute(h, 7);
			cout << "\t: (Sana silah �eker...)" << endl;
			Sleep(2000);
			SetConsoleTextAttribute(h, 12);
			cout << malik->isim_ogren();
			SetConsoleTextAttribute(h, 7);
			cout << "\t: PAT! (�ld�n...)" << endl;
		}
		if (err == 472) {
			SetConsoleTextAttribute(h, 12);
			cout << malik->isim_ogren();
			SetConsoleTextAttribute(h, 7);
			cout << "\t: 18 ya��ndan k���k olan kimseler, bu mekana giremez" << endl;
			Sleep(2000);
			SetConsoleTextAttribute(h, 12);
			cout << malik->isim_ogren();
			SetConsoleTextAttribute(h, 7);
			cout << "\t: (Sana silah �eker...)" << endl;
			Sleep(2000);
			SetConsoleTextAttribute(h, 12);
			cout << malik->isim_ogren();
			SetConsoleTextAttribute(h, 7);
			cout << "\t: PAT! (�ld�n...)" << endl;
		}
		if (err == 473) {
			SetConsoleTextAttribute(h, 12);
			cout << malik->isim_ogren();
			SetConsoleTextAttribute(h, 7);
			cout << "\t: 99 ya��ndan b�y�k olan kimseler, bu mekana giremez" << endl;
			Sleep(2000);
			SetConsoleTextAttribute(h, 12);
			cout << malik->isim_ogren();
			SetConsoleTextAttribute(h, 7);
			cout << "\t: (Sana silah �eker...)" << endl;
			Sleep(2000);
			SetConsoleTextAttribute(h, 12);
			cout << malik->isim_ogren();
			SetConsoleTextAttribute(h, 7);
			cout << "\t: PAT! (�ld�n)" << endl;
		}
	}
	return 0;
}
