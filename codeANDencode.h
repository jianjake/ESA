#pragma once


// codeANDencode 对话框

class codeANDencode : public CDialogEx
{
	DECLARE_DYNAMIC(codeANDencode)

public:
	codeANDencode(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~codeANDencode();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CODEANDENCODE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
