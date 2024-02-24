#include <iostream>
#include <cstring>
#include <clocale>
#include "windows.h"
using namespace std;

/*
David Gilmour : Poker2
Roger Waters : Banka
Syd Barrett : Kavga
Rick Wright : Maðaza
Nick Mason : Mekanýn sahibi
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
		cout << "\t: Kumarekop'a hoþ geldin yeðen, benim adým " << malik->isim_ogren() << ", bu mekanýn sahibi benim" << endl;
		Sleep(2000);
		SetConsoleTextAttribute(h, 12);
		cout << malik->isim_ogren();
		SetConsoleTextAttribute(h, 7);
		cout << "\t: Buraya geldiðine göre kumar oynamayý seven bir yapýn var" << endl;
		Sleep(2000);
		SetConsoleTextAttribute(h, 12);
		cout << malik->isim_ogren();
		SetConsoleTextAttribute(h, 7);
		cout << "\t: Ben de gençliðimde çok severdim ama tüm paramý batýrdým" << endl;
		Sleep(2000);
		SetConsoleTextAttribute(h, 12);
		cout << malik->isim_ogren();
		SetConsoleTextAttribute(h, 7);
		cout << "\t: Ve artýk akýllandým, kumarý býraktým ama " << poker->isim_ogren() << " hala oynuyor" << endl;
		Sleep(2000);
		SetConsoleTextAttribute(h, 12);
		cout << malik->isim_ogren();
		SetConsoleTextAttribute(h, 7);
		cout << "\t: Ama senin inatla bu iþlere bulaþma gibi bir isteðin var anlaþýlan" << endl;
		Sleep(2000);
		SetConsoleTextAttribute(h, 12);
		cout << malik->isim_ogren();
		SetConsoleTextAttribute(h, 7);
		cout << "\t: Ýçeri girmek istiyorsan adýný öðrenmem lazým" << endl;
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
		cout << "\t: Tamamdýr " << isim << ", þimdi bana yaþýný söyleyebilir misin" << endl;
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
		cout << "\t: Tamamdýr, o zaman seni mekanýmýza alalým þöyle" << endl;
	}
	catch(int err) {
		if (err == 467) {
			SetConsoleTextAttribute(h, 12);
			cout << malik->isim_ogren();
			SetConsoleTextAttribute(h, 7);
			cout << "\t: Benim adaþým olan kimseler, bu mekana giremez" << endl;
			Sleep(2000);
			SetConsoleTextAttribute(h, 12);
			cout << malik->isim_ogren();
			SetConsoleTextAttribute(h, 7);
			cout << "\t: (Sana silah çeker...)" << endl;
			Sleep(2000);
			SetConsoleTextAttribute(h, 12);
			cout << malik->isim_ogren();
			SetConsoleTextAttribute(h, 7);
			cout << "\t: PAT! (Öldün...)" << endl;
		}
		if (err > 467 && err < 472) {
			SetConsoleTextAttribute(h, 12);
			cout << malik->isim_ogren();
			SetConsoleTextAttribute(h, 7);
			cout << "\t: Benim arkadaþlarýmýn adaþý olan kimseler, bu mekana giremez" << endl;
			Sleep(2000);
			SetConsoleTextAttribute(h, 12);
			cout << malik->isim_ogren();
			SetConsoleTextAttribute(h, 7);
			cout << "\t: (Sana silah çeker...)" << endl;
			Sleep(2000);
			SetConsoleTextAttribute(h, 12);
			cout << malik->isim_ogren();
			SetConsoleTextAttribute(h, 7);
			cout << "\t: PAT! (Öldün...)" << endl;
		}
		if (err == 472) {
			SetConsoleTextAttribute(h, 12);
			cout << malik->isim_ogren();
			SetConsoleTextAttribute(h, 7);
			cout << "\t: 18 yaþýndan küçük olan kimseler, bu mekana giremez" << endl;
			Sleep(2000);
			SetConsoleTextAttribute(h, 12);
			cout << malik->isim_ogren();
			SetConsoleTextAttribute(h, 7);
			cout << "\t: (Sana silah çeker...)" << endl;
			Sleep(2000);
			SetConsoleTextAttribute(h, 12);
			cout << malik->isim_ogren();
			SetConsoleTextAttribute(h, 7);
			cout << "\t: PAT! (Öldün...)" << endl;
		}
		if (err == 473) {
			SetConsoleTextAttribute(h, 12);
			cout << malik->isim_ogren();
			SetConsoleTextAttribute(h, 7);
			cout << "\t: 99 yaþýndan büyük olan kimseler, bu mekana giremez" << endl;
			Sleep(2000);
			SetConsoleTextAttribute(h, 12);
			cout << malik->isim_ogren();
			SetConsoleTextAttribute(h, 7);
			cout << "\t: (Sana silah çeker...)" << endl;
			Sleep(2000);
			SetConsoleTextAttribute(h, 12);
			cout << malik->isim_ogren();
			SetConsoleTextAttribute(h, 7);
			cout << "\t: PAT! (Öldün)" << endl;
		}
	}
	return 0;
}
