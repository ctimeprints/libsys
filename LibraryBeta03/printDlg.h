#pragma once


// printDlg 对话框

class printDlg : public CDialogEx
{
	DECLARE_DYNAMIC(printDlg)

public:
	printDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~printDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
};
