#include <iostream>
using namespace std;

int N;

// star( )가 실행 중일 때, ( )번 코드라인부터 감소하기 시작해야 한다.
void star(int k, bool increasing)
{
	if (k < 1)
		return;
	// 증가한다.
	if (increasing)
	{
		star(k - 1, increasing);
		for (int i = 0; i < k; i++)
		{
			cout << '*';
		}
		cout << '\n';

		if(k == N)
			star(k - 1, false);
	}
	else
	{
		for (int i = 0; i < k; i++)
		{
			cout << '*';
		}
		cout << '\n';
		star(k - 1, increasing);
	}
}

int main()
{
	cin >> N;

	star(N, true);
}


/*
int main()
{
int N;
cin >> N;		// N = 2

42~55

star(2);void star(2, true)
		{
			if(2<1)
			if(true)
			star(1);		void star(1, true)
							{
								if(1<1)
								if(true)
								star(0);     >> void star(0, true)
												{
													if(0<1)
													return;
												}
								for(int i = 0; i <1; i++){cout << '*';}
								cout << endl;
								if(1 == 2)
							}
			for(int i =0; i< 2; i++) {cout << '*';}
			cout << endl;

			if(2 == 2)
			star(1, false);		void star(1, false)
								{
									if(1<1)
									if(false) => else
										for(int i = 0; i < 1; i++) {cout << '*';}
										cout << endl;
										star(0, false);		void star(0, false)
																{
																		if(0<1)
																		return;
																}
								}
		}
}
*/