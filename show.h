#pragma once


// show �Ի���

class show : public CDialogEx
{
	DECLARE_DYNAMIC(show)

public:
	show(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~show();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHOW };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton7();
};
