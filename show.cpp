// show.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "RSA.h"
#include "show.h"
#include "afxdialogex.h"
#include"solveRSA.h"


// show �Ի���

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


// show ��Ϣ�������

//���㹫Կ��˽Կ
void show::OnBnClickedButton6()
{
	CString p, q, e;//��ȡ����p,q�������e
	int ip, iq, ie;//����
	GetDlgItem(IDC_EDIT1)->GetWindowText(p);
	GetDlgItem(IDC_EDIT2)->GetWindowText(q);
	GetDlgItem(IDC_EDIT3)->GetWindowText(e);
	if (p != ""&&q != ""&&e != "") {
		ip = _ttoi(p);//CString תint
		iq = _ttoi(q);
		ie = _ttoi(e);
		//���� p������q����
		if(ip==iq) {
			MessageBox("��������p��ͬ������q");
			GetDlgItem(IDC_EDIT2)->SetFocus();
		}
		//p ��q�˼�����127����p,q��Ϊ1
		else if(ip*iq<127||ip==1||iq==1) {
			MessageBox("������ϴ����������p��q");
			GetDlgItem(IDC_EDIT1)->SetFocus();
		}
		
		else {
			bool bp, bq;
			solveRSA  test;
			bp = test.is_prime(ip);
			bq = test.is_prime(iq);
			//p��q��Ϊ����
			if (bp==false) {
				MessageBox("����������p");
				GetDlgItem(IDC_EDIT1)->SetFocus();
			}
			else if (bq == false) {
				MessageBox("����������q");
				GetDlgItem(IDC_EDIT2)->SetFocus();
			}
			//p��q��Ϊ����
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
			MessageBox("����������p");
			GetDlgItem(IDC_EDIT1)->SetFocus();
		}
		else if (q == "")
		{
			MessageBox("����������q");
			GetDlgItem(IDC_EDIT2)->SetFocus();
		}
		else if (e == "")
		{
			MessageBox("�����������e");
			GetDlgItem(IDC_EDIT3)->SetFocus();
		}

	}
}

//��������
void show::OnBnClickedButton5()
{
	CString m, n, e;//��ȡ����m,��Կn�͹�Կe
	int im, in, ie;//����
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
			MessageBox("����������m");
			GetDlgItem(IDC_EDIT15)->SetFocus();
		}
		else if(n=="") {
			MessageBox("�����빫Կn");
			GetDlgItem(IDC_EDIT16)->SetFocus();
		}
		else if(e=="") {
			MessageBox("�����빫Կe");
			GetDlgItem(IDC_EDIT17)->SetFocus();
		}
	}
}

//��������
void show::OnBnClickedButton7()
{
	CString c, n, d;//��ȡ����c,��Կn����Կd
	int ic, in, id;//����
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
			MessageBox("����������c");
			GetDlgItem(IDC_EDIT22)->SetFocus();
		}
		else if (n == "") {
			MessageBox("��������Կn");
			GetDlgItem(IDC_EDIT23)->SetFocus();
		}
		else if (d == "") {
			MessageBox("��������Կd");
			GetDlgItem(IDC_EDIT24)->SetFocus();
		}
	}
}
