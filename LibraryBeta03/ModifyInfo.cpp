// ModifyInfo.cpp : 实现文件
//

#include "stdafx.h"
#include "LibraryBeta03.h"
#include "ModifyInfo.h"
#include "afxdialogex.h"
#include "Cdata1.h"

extern int pos;
extern int judgeok;
extern CString m_num;
// ModifyInfo 对话框

IMPLEMENT_DYNAMIC(ModifyInfo, CDialogEx)

ModifyInfo::ModifyInfo(CWnd* pParent /*=NULL*/)
	: CDialogEx(ModifyInfo::IDD, pParent)
{
}

ModifyInfo::~ModifyInfo()
{
}

void ModifyInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_modifynum);
	DDX_Control(pDX, IDC_EDIT2, m_modifyname);
	DDX_Control(pDX, IDC_EDIT3, m_modifyauthor);
	DDX_Control(pDX, IDC_EDIT4, m_modifyprice);
	DDX_Control(pDX, IDC_EDIT5, m_modifystorage);
	DDX_Control(pDX, IDC_EDIT6, m_modifylended);
	//  DDX_Control(pDX, IDC_EDIT7, m_modifydate);
	DDX_Control(pDX, IDC_EDIT7, m_modifypress);
	DDX_Control(pDX, IDC_EDIT8, m_modifydate);
	DDX_Control(pDX, IDC_COMBO1, m_modifytype);
	DDX_Control(pDX, IDC_EDIT9, m_mddatetip);
}


BEGIN_MESSAGE_MAP(ModifyInfo, CDialogEx)
	ON_BN_CLICKED(IDOK, &ModifyInfo::OnBnClickedOk)
	ON_EN_KILLFOCUS(IDC_EDIT8, &ModifyInfo::OnKillfocusEdit8)
	ON_EN_SETFOCUS(IDC_EDIT8, &ModifyInfo::OnSetfocusEdit8)
END_MESSAGE_MAP()


// ModifyInfo 消息处理程序


void ModifyInfo::OnBnClickedOk()
{
	UpdateData(true);
	int selected=(-1);//以获取组合框选择的文本
	selected=m_modifytype.GetCurSel();
	if(m_modifynum.GetWindowTextLengthW()==0||m_modifyname.GetWindowTextLengthW()==0||m_modifyauthor.GetWindowTextLengthW()==0\
		||m_modifyprice.GetWindowTextLengthW()==0||m_modifystorage.GetWindowTextLengthW()==0||m_modifylended.GetWindowTextLengthW()==0\
		||m_modifypress.GetWindowTextLengthW()==0||m_modifydate.GetWindowTextLengthW()==0||selected==(-1))
	{
		MessageBox(_T("任一信息不能为空！"));
		return;
	}

	CString c_num,c_name,c_author,c_price,c_storage,c_lended,c_publisher,c_pubdate;
	m_modifynum.GetWindowTextW(c_num);//从输入框获得数据并保存到CString型数据中
	m_modifyname.GetWindowTextW(c_name);
	m_modifyauthor.GetWindowTextW(c_author);
	m_modifyprice.GetWindowTextW(c_price);
	m_modifystorage.GetWindowTextW(c_storage);
	m_modifylended.GetWindowTextW(c_lended);
	m_modifypress.GetWindowTextW(c_publisher);
	m_modifydate.GetWindowTextW(c_pubdate);
	CString typestr;
	if(selected!=LB_ERR)
	{
		m_modifytype.GetLBText(selected,typestr);//typestr便为组合框中选中的文本
	}

	Cdata1 m_database;
	m_database.Open();
	m_database.MoveFirst();
	while(!m_database.IsEOF())//取得选中的对应的行
	{
		if(m_num!=m_database.column1)
		{
			m_database.MoveNext();
		}
		else
		{
			m_database.Edit();

			m_database.column1=c_num;
			m_database.column2=c_name;
			m_database.column3=c_author;
			m_database.column4=_wtof(c_price);//unicode下CString型转为double
			m_database.column5=_wtoi(c_storage);
			m_database.column6=_wtoi(c_lended);
			m_database.column7=c_publisher;
			//将CString转为CTime//获取出版日期
			int first=c_pubdate.Find('-');
			int second=c_pubdate.Find('-',first+1);
			int year=_wtoi(c_pubdate.Left(4));
			int month=_wtoi(c_pubdate.Mid(first+1,second-first+1));
			int day=_wtoi(c_pubdate.Mid(second+1,c_pubdate.GetLength()-second-1));
			CTime temp(year,month,day,0,0,0);
			m_database.column8=temp;
			m_database.column9=typestr;
			m_database.Update();
			m_database.MoveNext();
		}
	}
	UpdateData(false);
	m_database.Close();
	CDialogEx::OnOK();
	judgeok=1;
}





BOOL ModifyInfo::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	Cdata1 m_database;
	m_database.Open();
	m_database.MoveFirst();
	while(!m_database.IsEOF())//取得选中的对应的行
	{
		if(m_num!=m_database.column1)
		{
			m_database.MoveNext();
		}
		else
		{
			m_modifynum.SetWindowTextW(m_database.column1);
			m_modifyname.SetWindowTextW(m_database.column2);
			m_modifyauthor.SetWindowTextW(m_database.column3);
			CString str;
			str.Format(_T("%.2f"),m_database.column4);
			m_modifyprice.SetWindowTextW(str);
			str.Format(_T("%d"),m_database.column5);
			m_modifystorage.SetWindowTextW(str);
			str.Format(_T("%d"),m_database.column6);
			m_modifylended.SetWindowTextW(str);
			m_modifypress.SetWindowTextW(m_database.column7);

			CString strtime;
			strtime.Format(_T("%s"),m_database.column8.Format("%Y-%m-%d"));//时间格式转换
			m_modifydate.SetWindowTextW(strtime);
			int gettype=(-1);
			if(m_database.column9==_T("军事类"))
			gettype=4;
			if(m_database.column9==_T("生活类"))
				gettype=3;
			if(m_database.column9==_T("社哲类"))
				gettype=2;
			if(m_database.column9==_T("理工类"))
				gettype=1;
			if(m_database.column9==_T("文史类"))
				gettype=0;
			m_modifytype.SetCurSel(gettype);
			m_database.MoveNext();
		}

	}

	m_database.Close();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void ModifyInfo::OnKillfocusEdit8()
{
	m_mddatetip.ShowWindow(false);
}


void ModifyInfo::OnSetfocusEdit8()
{
	m_mddatetip.SetWindowTextW(_T("请以YYYY-MM-DD格式填写"));
	m_mddatetip.ShowWindow(true);
}
