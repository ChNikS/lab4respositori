/** @file  */
#include <iostream>
#include<conio.h>
using namespace std;

void directcheck(int node, int n, int *pTr)
{
	cout << node + 1 << " ";

	int *Tr_two = new int[n];
	for (int i = 0; i < n; i++) Tr_two[i] = 0;

	for (int j = 0; j < n; j++)
		if (pTr[j] == node + 1) Tr_two[j] = pTr[j];

	for (int k = 0; k < n; k++)
		if (Tr_two[k]) directcheck(k, n, pTr);

	delete[]Tr_two;
}

//! Revers function
void revers(int node, int n, int *pTr)
{
	int *Tr_three = new int[n];
	for (int i = 0; i < n; i++) Tr_three[i] = 0;

	for (int j = 0; j < n; j++)
		if (pTr[j] == node + 1) Tr_three[j] = pTr[j];

	for (int k = 0; k < n; k++)
		if (Tr_three[k]) revers(k, n, pTr);

	cout << node + 1 << " ";

	delete[]Tr_three;
}


void symmetric(int node, int n, int *pTr)
{
	int *Tr_four = new int[n];
	for (int i = 0; i < n; i++) Tr_four[i] = 0;

	for (int j = 0; j < n; j++)
		if (pTr[j] == node + 1) Tr_four[j] = pTr[j];

	for (int k = 0; k < n; k++)
		if (Tr_four[k]) symmetric(k, n, pTr);

	int q = 0;
	for (int z = 0; z < n; z++)
		if (pTr[z] == node + 1) q++;

	if (q == 0) cout << node + 1 << " ";
	if ((pTr[node - 1] != pTr[node]) && (pTr[node]))
		cout << pTr[node] << " ";

	delete[]Tr_four;
}

//! Glavnaja funkcija.
int main()
{
	
	int n;
	cout << "Vvedite kolichestvo uzlov dereva: "; cin >> n; 
	int *Tr = new int[n];
	cout << "Vvedite uzly: "; /// Enter uzel
	for (int i = 0; i < n; i++) cin >> Tr[i];

	cout << "correct: "; /// Functions call
	directcheck(0, n, Tr); /// -Direct check 
	cout << "\nrevers: ";
	revers(0, n, Tr); /// - Revers check
	cout << "\nSim: ";
	symmetric(0, n, Tr); /// - Simmetric check
	cout << endl;


	_getch();
}