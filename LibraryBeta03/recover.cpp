// recover.cpp : 实现文件
//

#include "stdafx.h"
#include "LibraryBeta03.h"
#include "recover.h"
#include "afxdialogex.h"
#include "Cdata1.h"
#include "Cdata2.h"

extern int judgeok;
int recoverpos=(-1);
// recover 对话框

IMPLEMENT_DYNAMIC(recover, CDialogEx)

recover::recover(CWnd* pParent /*=NULL*/)
	: CDialogEx(recover::IDD, pParent)
{

}

recover::~recover()
{
}

void recover::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, recoverlist);
}


BEGIN_MESSAGE_MAP(recover, CDialogEx)
	ON_BN_CLICKED(IDOK, &recover::OnBnClickedOk)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &recover::OnLvnItemchangedList1)
END_MESSAGE_MAP()


// recover 消息处理程序


BOOL recover::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	recoverlist.DeleteAllItems();
	CRect rect;
	recoverlist.GetClientRect(&rect);
	recoverlist.SetExtendedStyle(recoverlist.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	recoverlist.InsertColumn(0,_T("书号"),LVCFMT_CENTER,(rect.Width()/50)*6,0);
	recoverlist.InsertColumn(1,_T("书名"),LVCFMT_CENTER,(rect.Width()/50)*12,1);
	recoverlist.InsertColumn(2,_T("作者"),LVCFMT_CENTER,(rect.Width()/50)*7,2);
	recoverlist.InsertColumn(3,_T("价格"),LVCFMT_CENTER,(rect.Width()/50)*5,3);
	recoverlist.InsertColumn(4,_T("存"),LVCFMT_CENTER,(rect.Width()/50)*3,4);
	recoverlist.InsertColumn(5,_T("借"),LVCFMT_CENTER,(rect.Width()/50)*3,5);
	recoverlist.InsertColumn(6,_T("出版社"),LVCFMT_CENTER,(rect.Width()/50)*8,6);
	recoverlist.InsertColumn(7,_T("出版日期"),LVCFMT_CENTER,(rect.Width()/50)*6,7);
	recoverlist.InsertColumn(8,_T("类别"),LVCFMT_CENTER,(rect.Width()/50)*7,8);

	int i;
	CString str;
	Cdata2 m_database2;
	m_database2.Open();
	m_database2.Requery();
	m_database2.MoveFirst();
	for(i=0;!m_database2.IsEOF();i++)
	{
		recoverlist.InsertItem(i,_T(""));//添加一行

		recoverlist.SetItemText(i,0,m_database2.column1);
		recoverlist.SetItemText(i,1,m_database2.column2);
		recoverlist.SetItemText(i,2,m_database2.column3);

		str.Format(_T("%.2f"),m_database2.column4);
		recoverlist.SetItemText(i,3,str);

		str.Format(_T("%d"),m_database2.column5);
		recoverlist.SetItemText(i,4,str);

		str.Format(_T("%d"),m_database2.column6);
		recoverlist.SetItemText(i,5,str);

		recoverlist.SetItemText(i,6,m_database2.column7);

		CString strtime;
		strtime.Format(_T("%s"),m_database2.column8.Format("%Y-%m-%d"));//时间格式转换
		recoverlist.SetItemText(i,7,strtime);

		recoverlist.SetItemText(i,8,m_database2.column9);
		m_database2.MoveNext();
	}
	m_database2.Close();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void recover::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	if(recoverpos==(-1))
	{
			MessageBox(_T("您并未选中任何一条记录，请重新选中！"));
			return;
	}
	Cdata1 recoverdata;
	Cdata2 trashdata;
	recoverdata.Open();
	trashdata.Open();
	trashdata.SetAbsolutePosition(recoverpos+1);
	recoverdata.AddNew();
	recoverdata.column1=trashdata.column1;
	recoverdata.column2=trashdata.column2;
	recoverdata.column3=trashdata.column3;
	recoverdata.column4=trashdata.column4;
	recoverdata.column5=trashdata.column5;
	recoverdata.column6=trashdata.column6;
	recoverdata.column7=trashdata.column7;
	recoverdata.column8=trashdata.column8;
	recoverdata.column9=trashdata.column9;
	recoverdata.Update();

	trashdata.Delete();
	trashdata.MoveNext();
	trashdata.Close();
	recoverdata.Close();
	recoverlist.DeleteItem(recoverpos);
	judgeok=1;
	CDialogEx::OnOK();
}


void recover::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	recoverpos=recoverlist.GetSelectionMark();//获取选中行
	*pResult = 0;
}
