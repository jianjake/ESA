#pragma once
#pragma once
//! RSA ��̬���ӿ�ʵ��   H�ļ�  
#ifndef RSA_H  
#define RSA_H  

#include <stdio.h>  
#include <string>  
#include <stdlib.h>     
#include <time.h>    
#include <math.h>  
#include <malloc.h>  
#include <iostream>  
#include <ppl.h>  

using namespace std;
using namespace Concurrency;
//! MAX���������������LENΪ�ṹ��slink��ռ���ڴ�ռ��С */  
#define MAX 100  
#define LEN sizeof(struct slink)  
//!   #�ܹ����ж�̬���ӿ�����RSA��  
/*!
@see class _declspec(dllexport) RSA
��RSA�㷨д�ɶ�̬���ӿ����ʽ������ã������й�Կ��˽Կ������
�Ϳ��Խ������ĵļ��ܺͽ���
*/
class _declspec(dllexport) solveRSA
{
public:

	//! # �¶�������ݽṹslink  

public:
	//! #RSA �Ĺ��캯��  
	/*!
	@see RSA()
	����Ӧ�ö�RSA���е�һЩ����������Ӧ�ĳ�ʼ��
	*/
	solveRSA();
	//! #RSA����������  
	/*!
	@see ~RSA()
	�ͷ��ڴ�
	*/
	~solveRSA();

public:
	//! #RSA�Ĵ������㺯����  
	/*
	�ж�һ�����Ƿ�Ϊ����
	*/
	
	bool is_prime(int p);
	/*
	���ñ�����ʵ��x^p mod m 
	*/
	long long expmod(int m, int n, int e);


	/*! @�������Կd�ĺ���(����Euclid�㷨)
	@see unsigned long  rsa(unsigned long p,unsigned long q,unsigned long e);
	*/
	unsigned long  rsa(unsigned long p, unsigned long q, unsigned long e);

};

#endif // RSA_H  