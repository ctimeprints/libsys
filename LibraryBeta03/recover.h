#pragma once
#include "afxcmn.h"


// recover �Ի���

class recover : public CDialogEx
{
	DECLARE_DYNAMIC(recover)

public:
	recover(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~recover();

// �Ի�������
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl recoverlist;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
};
