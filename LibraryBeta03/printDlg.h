#pragma once


// printDlg �Ի���

class printDlg : public CDialogEx
{
	DECLARE_DYNAMIC(printDlg)

public:
	printDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~printDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
};
