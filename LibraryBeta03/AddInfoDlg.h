#pragma once
#include "afxwin.h"


// AddInfoDlg �Ի���

class AddInfoDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AddInfoDlg)

public:
	AddInfoDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~AddInfoDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_numbox;
	CEdit m_namebox;
	CEdit m_authorbox;
	CEdit m_pricebox;
	CEdit m_storagebox;
	CEdit m_lendedbox;
	CEdit m_pressbox;
	CEdit m_datebox;
	afx_msg void OnBnClickedOk();
	CComboBox m_leixingbox;
	CEdit m_datetip;
	afx_msg void OnKillfocusEdit8();
	afx_msg void OnSetfocusEdit8();
};
