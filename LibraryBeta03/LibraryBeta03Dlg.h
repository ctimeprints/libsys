
// LibraryBeta03Dlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "ModifyInfo.h"
#include "Cdata1.h"
#include "afxwin.h"


// CLibraryBeta03Dlg 对话框
class CLibraryBeta03Dlg : public CDialogEx
{
// 构造
public:
	CLibraryBeta03Dlg(CWnd* pParent = NULL);	// 标准构造函数
// 对话框数据
	enum { IDD = IDD_LIBRARYBETA03_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg void OnBnClickedButton3();
	CListCtrl m_listctrl;
	void displaylist(void);

	afx_msg void OnClickList1(NMHDR *pNMHDR, LRESULT *pResult);
	CButton m_bt1;
	CButton m_bt2;
	CButton m_bt3;
	CButton m_bt4;
	CButton m_bt5;
	CButton m_bt6;
	CButton m_bt7;
	CButton m_bt8;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton4();
	CEdit m_searchbox;
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton9();
	int gettrashnum(void);
	CComboBox m_datecombo;
	CComboBox m_typecombo;
	afx_msg void OnSelendokCombo1();
	afx_msg void OnSelendokCombo2();
	void searchCSC(CString searchstr);
	CButton m_checkradio;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	int getAmount(int col);
	double getAmount(int pricecol,int col);

	CEdit m_alllendedbox;
	CEdit m_allstoragebox;
	CEdit m_allbooks;
	void absdisplay(Cdata1 &absDB);
	int absdisplay(Cdata1 &absDB,int count);
	CEdit m_alllendedmoney;
	CEdit m_allstoragemoney;
	CEdit m_allmoney;
	// 统计信息栏目
	void statistics(void);
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton5();

	CEdit m_searchtip;
	afx_msg void OnKillfocusEdit1();
	afx_msg void OnSetfocusEdit1();
};
