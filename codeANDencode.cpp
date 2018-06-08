// codeANDencode.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "RSA.h"
#include "codeANDencode.h"
#include "afxdialogex.h"
#include"solveRSA.h"
#include <io.h> //�Ƿ񴴽��ļ���
#include <direct.h> 

// codeANDencode �Ի���

IMPLEMENT_DYNAMIC(codeANDencode, CDialogEx)

codeANDencode::codeANDencode(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CODEANDENCODE, pParent)
{

}

codeANDencode::~codeANDencode()
{
}

void codeANDencode::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(codeANDencode, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &codeANDencode::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &codeANDencode::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &codeANDencode::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &codeANDencode::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON8, &codeANDencode::OnBnClickedButton8)
	ON_EN_CHANGE(IDC_EDIT23, &codeANDencode::OnEnChangeEdit23)
END_MESSAGE_MAP()


// codeANDencode ��Ϣ�������

//���ɹ�Կ����Կ
void codeANDencode::OnBnClickedButton1()
{
	CString p, q, e;//��ȡ����p,q�������e
	int ip, iq, ie;//����
	GetDlgItem(IDC_EDIT1)->GetWindowText(p);
	GetDlgItem(IDC_EDIT2)->GetWindowText(q);
	GetDlgItem(IDC_EDIT6)->GetWindowText(e);
	if (p != ""&&q != ""&&e != "") {
		ip = _ttoi(p);//CString תint
		iq = _ttoi(q);
		ie = _ttoi(e);
		//���� p������q����
		if (ip == iq) {
			MessageBox("��������p��ͬ������q");
			GetDlgItem(IDC_EDIT2)->SetFocus();
		}
		//p ��q�˼�����127����p,q��Ϊ1
		else if (ip*iq < 127 || ip == 1 || iq == 1) {
			MessageBox("������ϴ����������p��q");
			GetDlgItem(IDC_EDIT1)->SetFocus();
		}

		else {
			bool bp, bq;
			solveRSA  test;
			bp = test.is_prime(ip);
			bq = test.is_prime(iq);
			//p��q��Ϊ����
			if (bp == false) {
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
				int fn = (ip - 1)*(iq - 1);
				int d = test.rsa(ip, iq, ie);
				CString str;
				str.Format(_T("%d"), n);
				GetDlgItem(IDC_EDIT9)->SetWindowText(LPCTSTR(str));//
				GetDlgItem(IDC_EDIT10)->SetWindowText(LPCTSTR(str));

				str.Format(_T("%d"), d);
				GetDlgItem(IDC_EDIT11)->SetWindowText(LPCTSTR(str));

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
			GetDlgItem(IDC_EDIT6)->SetFocus();
		}

	}
}
//����
void codeANDencode::OnBnClickedButton8()
{
	CString e, n, mingwen,result;//
	GetDlgItem(IDC_EDIT8)->GetWindowText(e);
	GetDlgItem(IDC_EDIT14)->GetWindowText(n);
	GetDlgItem(IDC_EDIT23)->GetWindowText(mingwen);
	if (e != ""&&n != ""&&mingwen != "") {
		solveRSA test;
		int ie, in;
		ie = _ttoi(e);
		in = _ttoi(n);
		char* chmingwen = new char[1024];
		chmingwen = (char *)(LPCTSTR)mingwen;
		int imingwen,imiwen;
		int i = 0, len = strlen(chmingwen);
		while (i < 1024 && i < len) {
			imingwen = (int)chmingwen[i];
			imiwen=test.expmod(imingwen, ie, in);
			CString str;
			str.Format(_T("%d"), imiwen);
			if(i!=0)
				result = result + ',';
			result = result + str;
			i++;
		}
		GetDlgItem(IDC_EDIT17)->SetWindowText(result);
	}
	else {
		if (e == "") {
			MessageBox("�����빫Կ e");
			GetDlgItem(IDC_EDIT8)->SetFocus();
		}
		else if (n == "")
		{
			MessageBox("�����빫Կ n");
			GetDlgItem(IDC_EDIT14)->SetFocus();
		}
		else if (mingwen== "")
		{
			MessageBox("������ ���� ");
			GetDlgItem(IDC_EDIT23)->SetFocus();
		}
	}
}

//����
void codeANDencode::OnBnClickedButton2()
{
	CString miwen;
	GetDlgItem(IDC_EDIT17)->GetWindowText(miwen);
	FILE *fs;
	char* file = NULL;
	if (access("D:\\Work\\Encryption\\RSA", 0))
		system("md D:\\Work\\Encryption\\RSA");
	if ((fs = fopen("D:\\Work\\Encryption\\RSA\\miwen.txt", "w")) == NULL)
	{
		MessageBox("�޷��򿪴��ļ�\n");
		return;
	}
	fputs(miwen, fs);
	fclose(fs);
	UpdateData(FALSE);
}

//����
void codeANDencode::OnBnClickedButton3()
{
	TCHAR szBuffer[MAX_PATH] = { 0 };
	OPENFILENAME ofn = { 0 };
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = m_hWnd;
	ofn.lpstrFilter = _T("txt�ļ�(*.txt)\0");//Ҫѡ����ļ���׺   
	char buf[80];
	getcwd(buf, sizeof(buf));
	ofn.lpstrInitialDir = _T(buf);//Ĭ�ϵ��ļ�·��   
	ofn.lpstrFile = szBuffer;//szBuffer�Ǵ�ŵ�ѡ����ļ�·�� 
	ofn.nMaxFile = sizeof(szBuffer) / sizeof(*szBuffer);
	ofn.nFilterIndex = 0;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_EXPLORER;//��־����Ƕ�ѡҪ����OFN_ALLOWMULTISELECT  
	BOOL bSel;
	bSel = GetOpenFileName(&ofn);
	int i = 0, l = 0;
	int len = strlen(szBuffer);
	TCHAR filename[MAX_PATH];
	//·���任
	while (i < len) {
		filename[l++] = szBuffer[i];
		if (szBuffer[i++] == '\\')
			filename[l++] = '\\';
	}
	filename[l++] = '\0';

	FILE *fp;
	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("�޷��򿪴��ļ�\n");
		return;
	}
	char *miwen = new char[1024];
	i = 0;
	while (!feof(fp)) {
		miwen[i++] = fgetc(fp);
	}
	miwen[i - 1] = '\0';
	//MessageBox(miwen);
	fclose(fp);
	GetDlgItem(IDC_EDIT3)->SetWindowText((LPCTSTR)(LPCTSTR)miwen);
	UpdateData(FALSE);
}

//����
void codeANDencode::OnBnClickedButton4()
{
	/*if ((((CWnd* )GetDlgItem(IDC_EDIT8))->GetStyle() & WS_VISIBLE) ==1){
		GetDlgItem(IDC_EDIT8)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT14)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC19)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC20)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC21)->ShowWindow(TRUE);

}*/
	CString miwen, d, n;
	GetDlgItem(IDC_EDIT3)->GetWindowText(miwen);
	GetDlgItem(IDC_EDIT13)->GetWindowText(d);
	GetDlgItem(IDC_EDIT12)->GetWindowText(n);
	if (d != ""&&n != ""&&miwen != "") {
		int in = _ttoi(n);
		int id = _ttoi(d);
		solveRSA test;
		char* chmiwen = new char[1024];
		chmiwen = (char *)(LPCTSTR)miwen;
		int imiwen=0;
		int i = 0, len = strlen(chmiwen);
		long long  im;
		CString result;
		while (i < 1024 && i < len) {

			if (chmiwen[i] != ',') 
				imiwen = imiwen * 10 + (int)chmiwen[i] - 48;
			
			else {
				im = test.expmod(imiwen, id, in);
				imiwen = 0;
				result = result + (char)im;
			}
			if(i==1023||i==len-1)
			{
				im = test.expmod(imiwen, id, in);
				imiwen = 0;
				result = result + (char)im;
			}
			i++;
		}

		GetDlgItem(IDC_EDIT4)->SetWindowText(result);
		UpdateData(FALSE);
	}
	else {
		if (miwen == "")
		{
			MessageBox("�뵼�������ļ�");
			return;
		}
		else if (d == "") {
			MessageBox("������˽Կ d");
			GetDlgItem(IDC_EDIT13)->SetFocus();
		}
		else if (n == "")
		{
			MessageBox("������˽Կ n");
			GetDlgItem(IDC_EDIT12)->SetFocus();
		}
	}
}





void codeANDencode::OnEnChangeEdit23()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
