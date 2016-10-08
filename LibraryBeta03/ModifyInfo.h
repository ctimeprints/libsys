#pragma once


// ModifyInfo 对话框

class ModifyInfo : public CDialogEx
{
	DECLARE_DYNAMIC(ModifyInfo)

public:
	ModifyInfo(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ModifyInfo();

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_modifynum;
	CEdit m_modifyname;
	CEdit m_modifyauthor;
	CEdit m_modifyprice;
	CEdit m_modifystorage;
	CEdit m_modifylended;
	CEdit m_modifypress;
	CEdit m_modifydate;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	CComboBox m_modifytype;
	CEdit m_mddatetip;
	afx_msg void OnKillfocusEdit8();
	afx_msg void OnSetfocusEdit8();
};
