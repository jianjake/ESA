// show.cpp : 实现文件
//

#include "stdafx.h"
#include "RSA.h"
#include "show.h"
#include "afxdialogex.h"
#include"solveRSA.h"


// show 对话框

IMPLEMENT_DYNAMIC(show, CDialogEx)

show::show(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SHOW, pParent)
{

}

show::~show()
{
}

void show::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(show, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON6, &show::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON5, &show::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON7, &show::OnBnClickedButton7)
END_MESSAGE_MAP()


// show 消息处理程序

//计算公钥与私钥
void show::OnBnClickedButton6()
{
	CString p, q, e;//获取素数p,q和随机数e
	int ip, iq, ie;//数字
	GetDlgItem(IDC_EDIT1)->GetWindowText(p);
	GetDlgItem(IDC_EDIT2)->GetWindowText(q);
	GetDlgItem(IDC_EDIT3)->GetWindowText(e);
	if (p != ""&&q != ""&&e != "") {
		ip = _ttoi(p);//CString 转int
		iq = _ttoi(q);
		ie = _ttoi(e);
		//素数 p与素数q不等
		if(ip==iq) {
			MessageBox("请输入与p不同的素数q");
			GetDlgItem(IDC_EDIT2)->SetFocus();
		}
		//p 与q乘绩大于127，且p,q不为1
		else if(ip*iq<127||ip==1||iq==1) {
			MessageBox("请输入较大的两个素数p和q");
			GetDlgItem(IDC_EDIT1)->SetFocus();
		}
		
		else {
			bool bp, bq;
			solveRSA  test;
			bp = test.is_prime(ip);
			bq = test.is_prime(iq);
			//p与q均为素数
			if (bp==false) {
				MessageBox("请输入素数p");
				GetDlgItem(IDC_EDIT1)->SetFocus();
			}
			else if (bq == false) {
				MessageBox("请输入素数q");
				GetDlgItem(IDC_EDIT2)->SetFocus();
			}
			//p与q均为素数
			else {
				int n = ip*iq;
				int fn = (ip - 1)*(iq-1);
				int d = test.rsa(ip, iq, ie);
				CString str;
				str.Format(_T("%d"), ip);
				GetDlgItem(IDC_EDIT4)->SetWindowText(LPCTSTR(str));//
				str.Format(_T("%d"), iq);
				GetDlgItem(IDC_EDIT5)->SetWindowText(LPCTSTR(str));//
				str.Format(_T("%d"), n);
				GetDlgItem(IDC_EDIT6)->SetWindowText(LPCTSTR(str));//
				GetDlgItem(IDC_EDIT12)->SetWindowText(LPCTSTR(str));
				GetDlgItem(IDC_EDIT14)->SetWindowText(LPCTSTR(str));
				str.Format(_T("%d"), ip-1);
				GetDlgItem(IDC_EDIT8)->SetWindowText(LPCTSTR(str));
				str.Format(_T("%d"), iq - 1);
				GetDlgItem(IDC_EDIT11)->SetWindowText(LPCTSTR(str));
				str.Format(_T("%d"), fn);
				GetDlgItem(IDC_EDIT9)->SetWindowText(LPCTSTR(str));
				str.Format(_T("%d"), d);
				GetDlgItem(IDC_EDIT13)->SetWindowText(LPCTSTR(str));
				GetDlgItem(IDC_EDIT10)->SetWindowText(LPCTSTR(str));
				str.Format(_T("%d"), ie);
				GetDlgItem(IDC_EDIT7)->SetWindowText(LPCTSTR(str));				
				UpdateData(FALSE);
			}
		}

	}
	else {
		if (p == "") {
			MessageBox("请输入素数p");
			GetDlgItem(IDC_EDIT1)->SetFocus();
		}
		else if (q == "")
		{
			MessageBox("请输入素数q");
			GetDlgItem(IDC_EDIT2)->SetFocus();
		}
		else if (e == "")
		{
			MessageBox("请输入随机数e");
			GetDlgItem(IDC_EDIT3)->SetFocus();
		}

	}
}

//计算密文
void show::OnBnClickedButton5()
{
	CString m, n, e;//获取明文m,公钥n和公钥e
	int im, in, ie;//数字
	GetDlgItem(IDC_EDIT15)->GetWindowText(m);
	GetDlgItem(IDC_EDIT16)->GetWindowText(n);
	GetDlgItem(IDC_EDIT17)->GetWindowText(e);
	if (m != ""&&n != ""&&e != "") {
		GetDlgItem(IDC_EDIT18)->SetWindowText(m);
		GetDlgItem(IDC_EDIT19)->SetWindowText(e);
		GetDlgItem(IDC_EDIT20)->SetWindowText(n);
		im = _ttoi(m);
		in = _ttoi(n);
		ie = _ttoi(e);
		long long  ic;
		solveRSA test;
		ic = test.expmod(im, ie, in);
		CString str;
		str.Format(_T("%I64d"), ic);
		GetDlgItem(IDC_EDIT21)->SetWindowText(str);
		UpdateData(FALSE);
	}
	else {
		if (m == "") {
			MessageBox("请输入明文m");
			GetDlgItem(IDC_EDIT15)->SetFocus();
		}
		else if(n=="") {
			MessageBox("请输入公钥n");
			GetDlgItem(IDC_EDIT16)->SetFocus();
		}
		else if(e=="") {
			MessageBox("请输入公钥e");
			GetDlgItem(IDC_EDIT17)->SetFocus();
		}
	}
}

//计算明文
void show::OnBnClickedButton7()
{
	CString c, n, d;//获取密文c,密钥n和密钥d
	int ic, in, id;//数字
	GetDlgItem(IDC_EDIT22)->GetWindowText(c);
	GetDlgItem(IDC_EDIT23)->GetWindowText(n);
	GetDlgItem(IDC_EDIT24)->GetWindowText(d);
	if (c != ""&&n != ""&&d != "") {
		GetDlgItem(IDC_EDIT25)->SetWindowText(c);
		GetDlgItem(IDC_EDIT26)->SetWindowText(d);
		GetDlgItem(IDC_EDIT27)->SetWindowText(n);
		ic = _ttoi(c);
		in = _ttoi(n);
		id = _ttoi(d);
		long long  im;
		solveRSA test;
		im = test.expmod(ic, id, in);
		CString str;
		str.Format(_T("%I64d"), im);
		GetDlgItem(IDC_EDIT28)->SetWindowText(str);
		UpdateData(FALSE);
	}
	else {
		if (c == "") {
			MessageBox("请输入密文c");
			GetDlgItem(IDC_EDIT22)->SetFocus();
		}
		else if (n == "") {
			MessageBox("请输入密钥n");
			GetDlgItem(IDC_EDIT23)->SetFocus();
		}
		else if (d == "") {
			MessageBox("请输入密钥d");
			GetDlgItem(IDC_EDIT24)->SetFocus();
		}
	}
}
