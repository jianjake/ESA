#pragma once
#pragma once
//! RSA 动态链接库实现   H文件  
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
//! MAX是数组的最大个数，LEN为结构体slink的占用内存空间大小 */  
#define MAX 100  
#define LEN sizeof(struct slink)  
//!   #能够进行动态链接库编译的RSA类  
/*!
@see class _declspec(dllexport) RSA
将RSA算法写成动态链接库的形式方便调用，其中有公钥，私钥和明文
就可以进行明文的加密和解密
*/
class _declspec(dllexport) solveRSA
{
public:

	//! # 新定义的数据结构slink  

public:
	//! #RSA 的构造函数  
	/*!
	@see RSA()
	其中应该对RSA类中的一些变量进行相应的初始化
	*/
	solveRSA();
	//! #RSA的析构函数  
	/*!
	@see ~RSA()
	释放内存
	*/
	~solveRSA();

public:
	//! #RSA的大数运算函数库  
	/*
	判断一个数是否为素数
	*/
	
	bool is_prime(int p);
	/*
	利用倍增法实现x^p mod m 
	*/
	long long expmod(int m, int n, int e);


	/*! @求解密密钥d的函数(根据Euclid算法)
	@see unsigned long  rsa(unsigned long p,unsigned long q,unsigned long e);
	*/
	unsigned long  rsa(unsigned long p, unsigned long q, unsigned long e);

};

#endif // RSA_H  