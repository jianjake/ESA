#pragma once


// show 对话框

class show : public CDialogEx
{
	DECLARE_DYNAMIC(show)

public:
	show(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~show();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHOW };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton7();
};
