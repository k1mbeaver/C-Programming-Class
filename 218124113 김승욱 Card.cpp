//218124113 김승욱


#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

class CMyRand {
public:
	CMyRand() {
		srand((unsigned)time(NULL));
	}
	void init() {
		srand((unsigned)time(NULL));
	}

	unsigned randout(int e) {
		return (rand() % e + 1);
	}

	unsigned randout(int a, int b) {
		int e = b - a + 1;
		int c = rand() % e;
		c = c + a;
		return c;
	}
};

class CCard {
	string SuitName;
	string ExtraName;

public:
	int Rank = 0;
	void assign(int sn, int n) {
		if (sn == 0) SuitName = "Clover";
		if (sn == 1) SuitName = "Diamond";
		if (sn == 2) SuitName = "Heart";
		if (sn == 3) SuitName = "Spade";
		
		Rank = n;

		if (Rank == 1) ExtraName = "A";// Ace
		else if (Rank == 11) ExtraName = "J";// Jack
		else if (Rank == 12) ExtraName = "Q";// Queen
		else if (Rank == 13) ExtraName = "K";// King
		else ExtraName = "no";
	}

	string getSuitName() { return SuitName; }
	int getRank() { return Rank; }
	void prt() {
		if (Rank == 1)
		{
			cout << left << setw(10) << SuitName << setw(10) << ExtraName << endl;
		}
		else if (Rank >= 11 && Rank <= 13)
		{
			cout << left << setw(10) << SuitName << setw(10) << ExtraName << endl;
		}
		else
		{
			cout << left << setw(10) << SuitName << setw(10) << Rank << endl;
		}
	}

	void clear() {
		Rank = 0;
		SuitName = "";
		ExtraName = "";
	}
};

class CDeck {
	CCard card[52];
	CMyRand myRand;
public:
	CDeck() {
		int k = 0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 1; j <= 13; j++)
			{
				card[k].assign(i, j + 1);
				k++;
			}
		}
	}

	void shuffle() {
		int k;
		for (int i = 0; i < 52; ++i)
		{
			k = myRand.randout(0, 51);
			CCard temp = card[i];
			card[i] = card[k];
			card[k] = temp;
		}
	}

	CCard getCard(int n) { return card[n]; }

	void prtCard(int n) { card[n].prt(); }
};

class CPlayer {
public:
	string name;
	CCard card[3];
	CPlayer(string str = "noname") {
		name = str;
		clear();
	}
	void setName(string str) { name = str; }
	void addCard(CCard& cd, int n) { card[n] = cd; }
	void clear() {
		for (int i = 0; i < 3; i++)
		{
			card[i].clear();
		}
	}

	void show() {
		cout << name << endl;
		for (int i = 0; i < 3; i++)
		{
			card[i].prt();
		}
	}

	int sumcard() {
		int sum = 0;
		for (int i = 0; i < 3; i++)
		{
			sum = sum + card[i].Rank;
		}
		return sum;
	}
};

class CGame {
public:
	CPlayer player;
	int battle(int a, int b, int c) {
		int score[3];
		int max = 0;
		score[0] = a;
		score[1] = b;
		score[2] = c;

		max = score[0];

		for (int i = 1; i < 3; i++)
		{
			if (score[i] > max) max = score[i];
			else if (score[i] == max) return 0;
		}

		return max;
	}

	void winner(CPlayer a, CPlayer b, CPlayer c, int maxscore)
	{
		int n = 0;
		int apoint = a.sumcard();
		int bpoint = b.sumcard();
		int cpoint = c.sumcard();

		if (apoint == maxscore)
		{
			cout << "카드 게임의 승리자는 합계 " << maxscore << "점을 받은 " << a.name << "입니다" << endl;
		}

		else if (bpoint == maxscore)
		{
			cout << "카드 게임의 승리자는 합계 " << maxscore << "점을 받은 " << b.name << "입니다" << endl;
		}

		else if (cpoint == maxscore)
		{
			cout << "카드 게임의 승리자는 합계 " << maxscore << "점을 받은 " << c.name << "입니다" << endl;
		}
	}
};

int main()
{
	CCard card;
	CDeck deck;
	CGame game;
	CPlayer player1, player2, player3;
	int nSum1 = 0;
	int nSum2 = 0;
	int nSum3 = 0;

	while (1)
	{
		player1.setName("Smith");
		player2.setName("Nick");
		player3.setName("Kim");

		deck.shuffle();
		deck.shuffle();
		deck.shuffle();

		int n = 0;
		for (int i = 0; i < 3; i++)
		{
			card = deck.getCard(n);
			player1.addCard(card, i);
			n++;

			card = deck.getCard(n);
			player2.addCard(card, i);
			n++;

			card = deck.getCard(n);
			player3.addCard(card, i);
			n++;
		}

		cout << "Player1의 카드 내용" << endl;
		player1.show();

		cout << endl;

		cout << "Player2의 카드 내용" << endl;
		player2.show();

		cout << endl;

		cout << "Player3의 카드 내용" << endl;
		player3.show();

		cout << endl;

		nSum1 = player1.sumcard();
		cout << "Player1의 카드 합 : " << nSum1 << endl;

		nSum2 = player2.sumcard();
		cout << "Player2의 카드 합 : " << nSum2 << endl;

		nSum3 = player3.sumcard();
		cout << "Player3의 카드 합 : " << nSum3 << endl;

		n = game.battle(nSum1, nSum2, nSum3);
		// 동일한 점수가 나오는 경우
		if (n == 0)
		{
			cout << endl << "동일한 점수가 나왔습니다 게임을 다시 시작합니다" << endl << endl << endl;
			continue;
		}

		game.winner(player1, player2, player3, n);

		cout << endl; system("pause"); return 0;
	}

}