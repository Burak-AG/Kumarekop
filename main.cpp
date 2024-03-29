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
		string parola;
		int para;
		int can;
	public:
		Oyuncu(string isim, string parola) {
			this->isim = isim;
			this->parola = parola;
			this->can = 100;
			this->para = 1000;
		}
		int para_ogren() {
			return this->para;
		}
		void para_gir(int yeni_para) {
			this->para = yeni_para;
		}
		void para_ekle(int miktar) {
			this->para += miktar;
		}
		int can_ogren() {
			return this->can;
		}
		void can_gir(int yeni_can) {
			this->can = yeni_can;
		}
		void can_ekle(int miktar) {
			this->can += miktar;
		}
		string isim_ogren() {
			return this->isim;
		}
		void isim_gir(string yeni_isim) {
			this->isim = yeni_isim;
		}
		string parola_ogren() {
			return this->parola;
		}
		void parola_gir(string yeni_parola) {
			this->parola = yeni_parola;
		}
};

void isaretci_gorunumu(HANDLE h, bool durum) {
    CONSOLE_CURSOR_INFO bilgi;
    GetConsoleCursorInfo(h, &bilgi);
    bilgi.bVisible = durum;
    SetConsoleCursorInfo(h, &bilgi);
}

void sohbet(HANDLE h, Oyuncu* kisi, string mesaj, int renk, bool endline, bool efekt) {
	isaretci_gorunumu(h, false);
	if (efekt) { Sleep(300); }
	SetConsoleTextAttribute(h, renk);
	string isim;
	if (kisi->isim_ogren().length() < 8) {
		isim = kisi->isim_ogren() + "\t";
	}
	else if (kisi->isim_ogren().length() > 15) {
		isim = kisi->isim_ogren().substr(0, 15);
	}
	else {
		isim = kisi->isim_ogren();
	}
	if (efekt) {
		for (int i = 0; i < isim.length(); i++) {
			cout << isim[i];
			Sleep(30);
		}
	}
	else {
		cout << isim;
	}
	SetConsoleTextAttribute(h, 7);
	cout << "\t : ";
	if (efekt) {
		for (int i = 0; i < mesaj.length(); i++) {
			cout << mesaj[i];
			Sleep(30);
		}
	}
	else {
		cout << mesaj;
	}
	if (endline) {
		cout << endl;
	}
	if (efekt) { Sleep(300); }
	isaretci_gorunumu(h, true);
}

void mesaj(HANDLE h, string mesaj, int renk, bool efekt) {
	isaretci_gorunumu(h, false);
	if (efekt) { Sleep(300); }
	SetConsoleTextAttribute(h, renk);
	string rule1 = "---------------- : ";
	string rule2 = " : ----------------";
	if (efekt) {
		for (int i = 0; i < rule1.length(); i++) {
			cout << rule1[i];
			Sleep(30);
		}
	}
	else {
		cout << rule1;
	}
	SetConsoleTextAttribute(h, 6);
	if (efekt) {
		for (int i = 0; i < mesaj.length(); i++) {
			cout << mesaj[i];
			Sleep(30);
		}
	}
	else {
		cout << mesaj;
	}
	SetConsoleTextAttribute(h, renk);
	if (efekt) {
		for (int i = 0; i < rule2.length(); i++) {
			cout << rule2[i];
			Sleep(30);
		}
	}
	else {
		cout << rule2;
	}
	SetConsoleTextAttribute(h, 7);
	cout << endl;
	if (efekt) { Sleep(300); }
	isaretci_gorunumu(h, true);
}

int secim(HANDLE h, Oyuncu* kisi, string secenekler, int renk1, int renk2, bool efekt) {
	isaretci_gorunumu(h, false);
	if (efekt) { Sleep(300); }
	SetConsoleTextAttribute(h, renk1);
	string sec = "Se�enekler\t : ";
	if (efekt) {
		for (int i = 0; i < sec.length(); i++) {
			cout << sec[i];
			Sleep(30);
		}
	}
	else {
		cout << sec;
	}
	if (efekt) {
		for (int i = 0; i < secenekler.length(); i++) {
			cout << secenekler[i];
			Sleep(30);
		}
	}
	else {
		cout << secenekler;
	}
	cout << endl;
	SetConsoleTextAttribute(h, renk2);
	string isim;
	if (kisi->isim_ogren().length() < 8) {
		isim = kisi->isim_ogren() + "\t";
	}
	else if (kisi->isim_ogren().length() > 15) {
		isim = kisi->isim_ogren().substr(0, 15);
	}
	else {
		isim = kisi->isim_ogren();
	}
	if (efekt) {
		for (int i = 0; i < isim.length(); i++) {
			cout << isim[i];
			Sleep(30);
		}
	}
	else {
		cout << isim;
	}
	SetConsoleTextAttribute(h, 7);
	cout << "\t : ";
	if (efekt) { Sleep(300); }
	isaretci_gorunumu(h, true);
	int secenek;
	cin >> secenek;
	return secenek;
}

int main() {
	bool kazandim = false;
	setlocale(LC_ALL, "Turkish");
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	Oyuncu* malik = new Oyuncu("Nick Mason", "123456");
	Oyuncu* poker = new Oyuncu("David Gilmour", "123456");
	Oyuncu* banka = new Oyuncu("Roger Waters", "123456");
	Oyuncu* kavga = new Oyuncu("Syd Barrett", "123456");
	Oyuncu* pazar = new Oyuncu("Rick Wright", "123456");
	Oyuncu* sahis = new Oyuncu("Sen", "");
	try {
		sohbet(h, malik, "Kumarekop'a ho� geldin ye�en, benim ad�m " + malik->isim_ogren() + ", bu mekan�n sahibi benim", 12, 1, 1);
		sohbet(h, malik, "Buraya geldi�ine g�re kumar oynamay� seven bir yap�n var", 12, 1, 1);
		sohbet(h, malik, "Ben de gen�li�imde �ok severdim ama t�m param� bat�rd�m", 12, 1, 1);
		sohbet(h, malik, "Ve art�k ak�lland�m, kumar� b�rakt�m ama " + poker->isim_ogren() + " hala oynuyor", 12, 1, 1);
		sohbet(h, malik, "Ama senin inatla bu i�lere bula�ma gibi bir iste�in var anla��lan", 12, 1, 1);
		sohbet(h, malik, "��eri girmek istiyorsan ad�n� ��renmem laz�m", 12, 1, 1);
		sohbet(h, sahis, "", 9, 0, 1);
		string isim;
		cin.ignore(0);
		getline(cin, isim, '\n');
		Sleep(300);
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
		sahis->isim_gir(isim);
		sohbet(h, malik, "Tamamd�r " + isim + ", �imdi bana ya��n� s�yleyebilir misin", 12, 1, 1);
		sohbet(h, sahis, "", 9, 0, 1);
		int yas;
		cin >> yas;
		Sleep(300);
		if (yas < 18) {
			throw 472;
		}
		if (yas > 99) {
			throw 473;
		}
		sohbet(h, malik, "Tamamd�r, son olarak bir parolaya ihtiyac�n var", 12, 1, 1);
		sohbet(h, malik, "En az 6 karakter i�ermesine dikkat et ve akl�nda tut", 12, 1, 1);
		sohbet(h, sahis, "", 9, 0, 1);
		string parola;
		cin >> parola;
		Sleep(300);
		if (parola.length() < 6) {
			throw 474;
		}
		if (parola == "123456" || parola == "654321") {
			throw 475;
		}
		sahis->isim_gir(isim);
		sohbet(h, malik, "Tamamd�r, o zaman seni mekan�m�za alal�m ��yle", 12, 1, 1);
		mesaj(h, "Nick Mason abimizin mekan�na girdiniz (" + sahis->isim_ogren() + ")", 8, 1);
		sohbet(h, malik, "Bekle, seni buradaki elemanlarla tan��t�ray�m", 12, 1, 1);
		sohbet(h, malik, "Bu, mekan�m�z�n kumarbaz� David Gilmour, onunla birlikte kumar oynayabilirsin", 12, 1, 1);
		sohbet(h, malik, "Bu, mekan�m�z�n bankas� Roger Waters, ondan faizle para alabilir veya faizle ona para verebilirsin", 12, 1, 1);
		sohbet(h, malik, "Bu, mekan�m�z�n kavgac�s� Syd Barrett, onunla paras�na d�v��lere girebilirsin", 12, 1, 1);
		sohbet(h, malik, "Ve bu da, mekan�m�z�n pazarc�s� Rick Wright, ondan e�yalar� alabilirsin veya geri iade edebilirsin", 12, 1, 1);
		sohbet(h, malik, "Ben de dedi�im gibi bu mekan�n sahibi ve ayn� zamanda tefecisiyim, dara d��t���nde gelebilirsin", 12, 1, 1);
		sohbet(h, malik, "O zaman sana iyi e�lenceler, hadi ben ka�t�m", 12, 1, 1);
		mesaj(h, "Oyundaki amac�n�z en k�sa s�rede milyoner olmakt�r (" + sahis->isim_ogren() + ")", 8, 1);
		while (sahis->para_ogren() < 1000000 && sahis->can_ogren() > 0) {
			int s1 = secim(h, sahis, "(1:Envantere bak, 2:David'e git, 3:Roger'a git, 4:Syd'e git, 5:Nick'e git, 6:Rick'e git)", 8, 9, 1);
			switch (s1) {
				case 1:
					cout << "ENVANTER G�STER�LECEK" << endl;
					break;
				case 2:
					sohbet(h, poker, "Selam, biraz kumar oynamak ister misin, ne oynayal�m?", 12, 1, 1);
					break;
				case 3:
					sohbet(h, banka, "Merhaba, bu para babas�ndan ne istersin?", 12, 1, 1);
					break;
				case 4:
					sohbet(h, kavga, "�ok s�k�ld�m, biraz d�v��mek ister misin?", 12, 1, 1);
					break;
				case 5:
					sohbet(h, malik, "Yine ne oldu, problemin nedir, ne istiyorsun?", 12, 1, 1);
					break;
				case 6:
					sohbet(h, pazar, "Selam, benden ne sat�n almak istersin?", 12, 1, 1);
					break;
				default 7:
					cout << "�YLE B�R �EY YOK" << endl;
			}
		}
	}
	catch(int err) {
		if (err == 467) {
			sohbet(h, malik, "Benim ada��m olan kimseler, bu mekana giremez", 12, 1, 1);
			sohbet(h, malik, "(Sana silah �eker...)", 12, 1, 1);
			mesaj(h, "PAT! (�ld�n...) (" + sahis->isim_ogren() + ")", 8, 0);
		}
		if (err > 467 && err < 472) {
			sohbet(h, malik, "Benim arkada�lar�m�n ada�� olan kimseler, bu mekana giremez", 12, 1, 1);
			sohbet(h, malik, "(Sana silah �eker...)", 12, 1, 1);
			mesaj(h, "PAT! (�ld�n...) (" + sahis->isim_ogren() + ")", 8, 0);
		}
		if (err == 472) {
			sohbet(h, malik, "18 ya��ndan k���k olan kimseler, bu mekana giremez", 12, 1, 1);
			sohbet(h, malik, "(Sana silah �eker...)", 12, 1, 1);
			mesaj(h, "PAT! (�ld�n...) (" + sahis->isim_ogren() + ")", 8, 0);
		}
		if (err == 473) {
			sohbet(h, malik, "99 ya��ndan b�y�k olan kimseler, bu mekana giremez", 12, 1, 1);
			sohbet(h, malik, "(Sana silah �eker...)", 12, 1, 1);
			mesaj(h, "PAT! (�ld�n...) (" + sahis->isim_ogren() + ")", 8, 0);
		}
		if (err == 474) {
			sohbet(h, malik, "Dedi�imi anlayamayan kimseler, bu mekana giremez", 12, 1, 1);
			sohbet(h, malik, "(Sana silah �eker...)", 12, 1, 1);
			mesaj(h, "PAT! (�ld�n...) (" + sahis->isim_ogren() + ")", 8, 0);
		}
		if (err == 475) {
			sohbet(h, malik, "Bu kadar ahmak olan kimseler, bu mekana giremez", 12, 1, 1);
			sohbet(h, malik, "(Sana silah �eker...)", 12, 1, 1);
			mesaj(h, "PAT! (�ld�n...) (" + sahis->isim_ogren() + ")", 8, 8);
		}
	}
	delete malik;
	delete poker;
	delete banka;
	delete kavga;
	delete pazar;
	delete sahis;
	return 0;
}
