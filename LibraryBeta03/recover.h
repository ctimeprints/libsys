#pragma once
#include "afxcmn.h"


// recover 对话框

class recover : public CDialogEx
{
	DECLARE_DYNAMIC(recover)

public:
	recover(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~recover();

// 对话框数据
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl recoverlist;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
};
