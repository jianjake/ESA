#include"stdafx.h"
#include "solveRSA.h"

solveRSA::solveRSA()
{

}

solveRSA::~solveRSA()
{

}


/*/�������Կd�ĺ���(����Euclid�㷨)96403770511368768000*/
unsigned long  solveRSA::rsa(unsigned long p, unsigned long q, unsigned long e)  /*/�������Կd�ĺ���(����Euclid�㷨)*/
{
	unsigned long g, k, r, n1, n2, t;
	unsigned long b1 = 0, b2 = 1;
	g = (p - 1)*(q - 1);
	n1 = g;
	n2 = e;
	while (1)
	{
		k = n1 / n2;
		r = n1 - k*n2;
		if (r != 0)
		{
			n1 = n2;
			n2 = r;
			t = b2;
			b2 = b1 - k*b2;
			b1 = t;
		}
		else
		{
			break;
		}
	}
	return (g + b2) % g;
}
/*/�ж�һ�����Ƿ�Ϊ����*/
bool solveRSA::is_prime(int p) {
	int end = sqrt(p);
	for (int i = 2; i <=end; i++)
		if (p%i == 0)
			return false;
	return true;
}
/*/�������ñ�����ʵ��x^p mod m */
long long solveRSA::expmod(int x, int p, int m) {
	//x^p mod m 
	const int N = 110;
	int a[N];
	long long s;
		//scanf("%d%d%d", &x, &p, &m);
		//��pת�ɶ����ƴ���a����
		int k = 0;
		while (p>0) {
			++k;
			a[k] = p % 2;
			p = p / 2;
		}

		//for (int i = k; i>0; --i) printf("%d", a[i]);
		//printf("\n");

		//��ʼ����������t�ʹ�s
		long long t = x;
		if (a[1] == 0) s = 1;
		else s = x;

		//����
		for (int i = 2; i <= k; ++i) {
			t = t*t%m;
			if (a[i] == 1) s = s*t%m;
		}
		//printf("%I64d", s);
		return s;
	}