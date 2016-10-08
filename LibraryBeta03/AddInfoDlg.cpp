// AddInfoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "LibraryBeta03.h"
#include "AddInfoDlg.h"
#include "afxdialogex.h"
#include "Cdata1.h"
#include "LibraryBeta03Dlg.h"
int judgeok=0;

extern int pos;
// AddInfoDlg 对话框

IMPLEMENT_DYNAMIC(AddInfoDlg, CDialogEx)

AddInfoDlg::AddInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(AddInfoDlg::IDD, pParent)
{

}

AddInfoDlg::~AddInfoDlg()
{
}

void AddInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_numbox);
	DDX_Control(pDX, IDC_EDIT2, m_namebox);
	DDX_Control(pDX, IDC_EDIT3, m_authorbox);
	DDX_Control(pDX, IDC_EDIT4, m_pricebox);
	DDX_Control(pDX, IDC_EDIT5, m_storagebox);
	DDX_Control(pDX, IDC_EDIT6, m_lendedbox);
	DDX_Control(pDX, IDC_EDIT7, m_pressbox);
	DDX_Control(pDX, IDC_EDIT8, m_datebox);
	DDX_Control(pDX, IDC_COMBO1, m_leixingbox);
	DDX_Control(pDX, IDC_EDIT9, m_datetip);
}


BEGIN_MESSAGE_MAP(AddInfoDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &AddInfoDlg::OnBnClickedOk)
	ON_EN_KILLFOCUS(IDC_EDIT8, &AddInfoDlg::OnKillfocusEdit8)
	ON_EN_SETFOCUS(IDC_EDIT8, &AddInfoDlg::OnSetfocusEdit8)
END_MESSAGE_MAP()


// AddInfoDlg 消息处理程序


void AddInfoDlg::OnBnClickedOk()
{
	UpdateData(true);
	int selected=(-1);//以获取组合框选择的文本
	selected=m_leixingbox.GetCurSel();
	if(m_numbox.GetWindowTextLengthW()==0||m_namebox.GetWindowTextLengthW()==0||m_authorbox.GetWindowTextLengthW()==0\
		||m_pricebox.GetWindowTextLengthW()==0||m_storagebox.GetWindowTextLengthW()==0||m_lendedbox.GetWindowTextLengthW()==0\
		||m_pressbox.GetWindowTextLengthW()==0||m_datebox.GetWindowTextLengthW()==0||selected==(-1))
	{
		MessageBox(_T("任一信息不能为空！"));
		return;
	}
	
	CString c_num,c_name,c_author,c_price,c_storage,c_lended,c_publisher,c_pubdate;
	m_numbox.GetWindowTextW(c_num);
	m_namebox.GetWindowTextW(c_name);
	m_authorbox.GetWindowTextW(c_author);
	m_pricebox.GetWindowTextW(c_price);
	m_storagebox.GetWindowTextW(c_storage);
	m_lendedbox.GetWindowTextW(c_lended);
	m_pressbox.GetWindowTextW(c_publisher);
	m_datebox.GetWindowTextW(c_pubdate);
	CString typestr;
	if(selected!=LB_ERR)
	{
		m_leixingbox.GetLBText(selected,typestr);//typestr便为组合框中选中的文本
	}
	Cdata1 m_database;
	m_database.Open();
	m_database.AddNew();
	m_database.column1=c_num;
	m_database.column2=c_name;
	m_database.column3=c_author;
	m_database.column4=_wtof(c_price);//unicode下CString型转为double
	m_database.column5=_wtoi(c_storage);
	m_database.column6=_wtoi(c_lended);
	m_database.column7=c_publisher;
	//将CString转为CTime
	int first=c_pubdate.Find('-');
	int second=c_pubdate.Find('-',first+1);
	int year=_wtoi(c_pubdate.Left(4));
	int month=_wtoi(c_pubdate.Mid(first+1,second-first+1));
	int day=_wtoi(c_pubdate.Mid(second+1,c_pubdate.GetLength()-second-1));
	CTime temp(year,month,day,0,0,0);
	m_database.column8=temp;
	m_database.column9=typestr;
	m_database.Update();//完成添加//更新数据库
	m_database.MoveNext();
	
	m_database.Close();//断开数据库
	judgeok=1;

	CDialogEx::OnOK();

}


void AddInfoDlg::OnKillfocusEdit8()
{
	m_datetip.ShowWindow(false);
}


void AddInfoDlg::OnSetfocusEdit8()
{
	m_datetip.SetWindowTextW(_T("请以YYYY-MM-DD格式填写"));
	m_datetip.ShowWindow(true);
}
