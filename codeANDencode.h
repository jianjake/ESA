#pragma once


// codeANDencode �Ի���

class codeANDencode : public CDialogEx
{
	DECLARE_DYNAMIC(codeANDencode)

public:
	codeANDencode(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~codeANDencode();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CODEANDENCODE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnEnChangeEdit8();
	afx_msg void OnEnChangeEdit23();
};
