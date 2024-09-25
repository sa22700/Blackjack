#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;
// Luodaan luokka
class BlackJack
{
	//Luodaan kortit taulukko
private:
	int kortit[52];
public:
	//Luodaan konstruktori
	BlackJack()
	{
		//loopataan for loopilla 52 kertaa ja asetetaan kortit taulukkoon arvot 0-51
		for (int i = 0; i < 52; i++)
		{
			kortit[i] = i;
		}
	}
	//luodaan funktio
	void sekoita()
	{
		//arvotaan kortit aika perusteisesti
		srand(time(NULL));
		//loopataan for loopilla 52 kertaa ja arvotaan kortit taulukkoon arvot 0-51
		for (int i = 0; i < 52; i++)
		{
			int randomi = rand() % 52 + 1;
			//vaihdetaan kortit taulukon arvot kesken‰‰n
			int temporar = kortit[i];
			kortit[i] = kortit[randomi];
			kortit[randomi] = temporar;
		}
	}
	//luodaan funktio
	void pelaa()
	{
		//luodaan muuttujat, jotka alkavat arvosta 0
		int pelaajanSumma = 0;
		int jakajanSumma = 0;
		int korttiarvo = 0;
		//loopataan while loopilla niin kauan kun pelaajan summa on alle 21
		while (pelaajanSumma < 21)
		{
			cout << "Pelaajan summa: " << pelaajanSumma << endl;
			cout << "Jakajan summa: " << jakajanSumma << endl;
			cout << "Haluatko nostaa kortin? (k/e)" << endl;
			char vastaus;
			cin >> vastaus;
			//annetaan pelaajalle mahdollisuus nostaa kortti tai lopettaa
			if (vastaus == 'k')
			{
				//kortti saa arvon kortit taulukosta
				int kortti = kortit[korttiarvo];
				//korttiarvo kasvaa yhdell‰
				korttiarvo++;
				//arvotaan kortti ja asetetaan arvo
				int arvo = kortti % 13 + 1;
				//arvon ollessa yli 10, asetetaan arvo 10
				if (arvo > 10)
				{
					arvo = 10;
				}
				//jos arvo on 1, annetaan pelaajalle mahdollisuus valita 1 tai 14 v‰lill‰
				else if (arvo == 1)
				{
					cout << "Haluatko asettaa 1 arvoksi 1 vai 14? " << endl;
					int vastaus;
					cin >> vastaus;
					//hieman ristiriitaa aiheuttaa se ett‰ teht‰v‰nannossa pyydet‰‰n asettamaan 10, 11, 12, 13 = 10, 
					//mutta jos pelaaja valitsee 1 kohdalla 14, niin onko se 10 vai 14? itse p‰‰tin ett‰ 10
					if (vastaus == 14)
					{
						arvo = 10;
					}
					else if (vastaus == 1)
					{
						arvo = 1;
					}
					else
					{
						cout << "Virheellinen syˆte!" << endl;
						continue;
					}
				}
				//summataan arvot pelaajan summaan
				pelaajanSumma += arvo;
			}
			//pelaaja p‰‰tt‰‰ lopettaa pelin
			else if (vastaus == 'e')
			{
				break;
			}
			else
			{
				cout << "Virheellinen syˆte!" << endl;
				continue;
			}
		}
		//loopataan while loopilla niin kauan kun jakajan summa on alle 17
		while (jakajanSumma <= 17)
		{
			//kortti saa arvon kortit taulukosta
			int kortti = kortit[korttiarvo];
			//korttiarvo kasvaa yhdell‰
			korttiarvo++;
			//arvotaan kortti ja arvo voi olla 1-13 v‰lill‰
			int arvo = kortti % 13 + 1;
			//jos arvo on yli 10, asetetaan arvo 10
			if (arvo > 10)
			{
				arvo = 10;
			}
			//summataan arvot jakajan summaan
			jakajanSumma += arvo;
		}
		cout << "Pelaajan summa: " << pelaajanSumma << endl;
		cout << "Jakajan summa: " << jakajanSumma << endl;
		//tulostetaan voittaja, tietyin ehdoin
		//jos pelaajan summa on yli 21, jakaja voittaa
		if (pelaajanSumma > 21)
		{
			cout << "Jakaja voittaa!" << endl;
		}
		//jos jakajan summa on yli 21, pelaaja voittaa
		else if (jakajanSumma > 21)
		{
			cout << "Pelaaja voittaa!" << endl;
		}
		//jos pelaajan summa on enemm‰n kuin jakajan summa, pelaaja voittaa
		else if (pelaajanSumma > jakajanSumma)
		{
			cout << "Pelaaja voittaa!" << endl;
		}
		//jos jakajan summa on enemm‰n kuin pelaajan summa, jakaja voittaa
		else if (jakajanSumma > pelaajanSumma)
		{
			cout << "Jakaja voittaa!" << endl;
		}
		//jos pelaajan summa on yht‰ suuri kuin jakajan summa, jakaja voittaa
		else if (pelaajanSumma == jakajanSumma)
		{
			cout << "Jakaja voittaa!" << endl;
		}
	}
};
//p‰‰ohjelma
int main()
{
	//arvotaan aika perusteisesti
	srand(time(NULL));
	//loopataan while loopilla niin kauan kun arvo on tosi, eli pelaaja p‰‰tt‰‰ keskeytt‰‰ pelin
	while (true)
	{
		//luodaan blackjack olio
		BlackJack blackjack;
		//kutsutaan funktioita
		blackjack.sekoita();
		//kutsutaan funktioita
		blackjack.pelaa();
		cout << "Haluatko pelata uudestaan? (k/e)" << endl;
		char vastaus;
		cin >> vastaus;
		//annetaan pelaajalle mahdollisuus pelata uudestaan tai lopettaa
		if (vastaus == 'e')
		{
			break;
		}
		//annetaan pelaajalle mahdollisuus pelata uudestaan
		else if (vastaus == 'k')
		{
			continue;
		}
		else
		{
			cout << "Virheellinen syˆte!" << endl;
			continue;
		}
		return 0;
	}
}