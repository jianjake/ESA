// codeANDencode.cpp : 实现文件
//

#include "stdafx.h"
#include "RSA.h"
#include "codeANDencode.h"
#include "afxdialogex.h"
#include"solveRSA.h"
#include <io.h> //是否创建文件夹
#include <direct.h> 

// codeANDencode 对话框

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


// codeANDencode 消息处理程序

//生成公钥和密钥
void codeANDencode::OnBnClickedButton1()
{
	CString p, q, e;//获取素数p,q和随机数e
	int ip, iq, ie;//数字
	GetDlgItem(IDC_EDIT1)->GetWindowText(p);
	GetDlgItem(IDC_EDIT2)->GetWindowText(q);
	GetDlgItem(IDC_EDIT6)->GetWindowText(e);
	if (p != ""&&q != ""&&e != "") {
		ip = _ttoi(p);//CString 转int
		iq = _ttoi(q);
		ie = _ttoi(e);
		//素数 p与素数q不等
		if (ip == iq) {
			MessageBox("请输入与p不同的素数q");
			GetDlgItem(IDC_EDIT2)->SetFocus();
		}
		//p 与q乘绩大于127，且p,q不为1
		else if (ip*iq < 127 || ip == 1 || iq == 1) {
			MessageBox("请输入较大的两个素数p和q");
			GetDlgItem(IDC_EDIT1)->SetFocus();
		}

		else {
			bool bp, bq;
			solveRSA  test;
			bp = test.is_prime(ip);
			bq = test.is_prime(iq);
			//p与q均为素数
			if (bp == false) {
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
			GetDlgItem(IDC_EDIT6)->SetFocus();
		}

	}
}
//加密
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
			MessageBox("请输入公钥 e");
			GetDlgItem(IDC_EDIT8)->SetFocus();
		}
		else if (n == "")
		{
			MessageBox("请输入公钥 n");
			GetDlgItem(IDC_EDIT14)->SetFocus();
		}
		else if (mingwen== "")
		{
			MessageBox("请输入 明文 ");
			GetDlgItem(IDC_EDIT23)->SetFocus();
		}
	}
}

//导出
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
		MessageBox("无法打开此文件\n");
		return;
	}
	fputs(miwen, fs);
	fclose(fs);
	UpdateData(FALSE);
}

//导入
void codeANDencode::OnBnClickedButton3()
{
	TCHAR szBuffer[MAX_PATH] = { 0 };
	OPENFILENAME ofn = { 0 };
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = m_hWnd;
	ofn.lpstrFilter = _T("txt文件(*.txt)\0");//要选择的文件后缀   
	char buf[80];
	getcwd(buf, sizeof(buf));
	ofn.lpstrInitialDir = _T(buf);//默认的文件路径   
	ofn.lpstrFile = szBuffer;//szBuffer是存放的选择的文件路径 
	ofn.nMaxFile = sizeof(szBuffer) / sizeof(*szBuffer);
	ofn.nFilterIndex = 0;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_EXPLORER;//标志如果是多选要加上OFN_ALLOWMULTISELECT  
	BOOL bSel;
	bSel = GetOpenFileName(&ofn);
	int i = 0, l = 0;
	int len = strlen(szBuffer);
	TCHAR filename[MAX_PATH];
	//路径变换
	while (i < len) {
		filename[l++] = szBuffer[i];
		if (szBuffer[i++] == '\\')
			filename[l++] = '\\';
	}
	filename[l++] = '\0';

	FILE *fp;
	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("无法打开此文件\n");
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

//解密
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
			MessageBox("请导入密文文件");
			return;
		}
		else if (d == "") {
			MessageBox("请输入私钥 d");
			GetDlgItem(IDC_EDIT13)->SetFocus();
		}
		else if (n == "")
		{
			MessageBox("请输入私钥 n");
			GetDlgItem(IDC_EDIT12)->SetFocus();
		}
	}
}





void codeANDencode::OnEnChangeEdit23()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
