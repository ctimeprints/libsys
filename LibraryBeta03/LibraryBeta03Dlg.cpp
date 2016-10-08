
// LibraryBeta03Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "LibraryBeta03.h"
#include "LibraryBeta03Dlg.h"
#include "afxdialogex.h"
#include "Cdata1.h"
#include "Cdata2.h"
#include "AddInfoDlg.h"
#include "ModifyInfo.h"
#include "recover.h"
#include "printDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

int pageJ=0;
int pos=(-1);
CString m_num;
int sumbooks=0;
double summoney=0;
extern int judgeok;
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CLibraryBeta03Dlg 对话框




CLibraryBeta03Dlg::CLibraryBeta03Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLibraryBeta03Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLibraryBeta03Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listctrl);
	DDX_Control(pDX, IDC_BUTTON1, m_bt1);
	DDX_Control(pDX, IDC_BUTTON2, m_bt2);
	DDX_Control(pDX, IDC_BUTTON3, m_bt3);
	DDX_Control(pDX, IDC_BUTTON4, m_bt4);
	DDX_Control(pDX, IDC_BUTTON5, m_bt5);
	DDX_Control(pDX, IDC_BUTTON6, m_bt6);
	DDX_Control(pDX, IDC_BUTTON7, m_bt7);
	DDX_Control(pDX, IDC_BUTTON8, m_bt8);
	DDX_Control(pDX, IDC_EDIT1, m_searchbox);
	DDX_Control(pDX, IDC_COMBO1, m_datecombo);
	DDX_Control(pDX, IDC_COMBO2, m_typecombo);
	DDX_Control(pDX, IDC_RADIO1, m_checkradio);
	//  DDX_Control(pDX, IDC_EDIT2, m_alllendbox);
	DDX_Control(pDX, IDC_EDIT2, m_alllendedbox);
	DDX_Control(pDX, IDC_EDIT4, m_allstoragebox);
	DDX_Control(pDX, IDC_EDIT6, m_allbooks);
	DDX_Control(pDX, IDC_EDIT3, m_alllendedmoney);
	DDX_Control(pDX, IDC_EDIT5, m_allstoragemoney);
	DDX_Control(pDX, IDC_EDIT7, m_allmoney);
	DDX_Control(pDX, IDC_EDIT8, m_searchtip);
}

BEGIN_MESSAGE_MAP(CLibraryBeta03Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON3, &CLibraryBeta03Dlg::OnBnClickedButton3)
//	ON_NOTIFY(NM_THEMECHANGED, IDC_LIST1, &CLibraryBeta03Dlg::OnThemechangedList1)
ON_NOTIFY(NM_CLICK, IDC_LIST1, &CLibraryBeta03Dlg::OnClickList1)
ON_BN_CLICKED(IDC_BUTTON2, &CLibraryBeta03Dlg::OnBnClickedButton2)
ON_BN_CLICKED(IDC_BUTTON1, &CLibraryBeta03Dlg::OnBnClickedButton1)
ON_BN_CLICKED(IDC_BUTTON4, &CLibraryBeta03Dlg::OnBnClickedButton4)
ON_BN_CLICKED(IDC_BUTTON6, &CLibraryBeta03Dlg::OnBnClickedButton6)
ON_BN_CLICKED(IDC_BUTTON9, &CLibraryBeta03Dlg::OnBnClickedButton9)
ON_CBN_SELENDOK(IDC_COMBO1, &CLibraryBeta03Dlg::OnSelendokCombo1)
ON_CBN_SELENDOK(IDC_COMBO2, &CLibraryBeta03Dlg::OnSelendokCombo2)
ON_BN_CLICKED(IDC_RADIO1, &CLibraryBeta03Dlg::OnBnClickedRadio1)
ON_BN_CLICKED(IDC_RADIO2, &CLibraryBeta03Dlg::OnBnClickedRadio2)
ON_BN_CLICKED(IDC_BUTTON8, &CLibraryBeta03Dlg::OnBnClickedButton8)
ON_BN_CLICKED(IDC_BUTTON7, &CLibraryBeta03Dlg::OnBnClickedButton7)
ON_BN_CLICKED(IDC_BUTTON5, &CLibraryBeta03Dlg::OnBnClickedButton5)

ON_EN_KILLFOCUS(IDC_EDIT1, &CLibraryBeta03Dlg::OnKillfocusEdit1)
ON_EN_SETFOCUS(IDC_EDIT1, &CLibraryBeta03Dlg::OnSetfocusEdit1)
END_MESSAGE_MAP()


// CLibraryBeta03Dlg 消息处理程序

BOOL CLibraryBeta03Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:初始化内容，即弹出窗口即显示的内容
	HBITMAP hBmp1=::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP1));
	m_bt1.SetBitmap(hBmp1);
	HBITMAP hBmp2=::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP2));
	m_bt2.SetBitmap(hBmp2);
	HBITMAP hBmp3=::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP3));
	m_bt3.SetBitmap(hBmp3);
	HBITMAP hBmp4=::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP4));
	m_bt4.SetBitmap(hBmp4);
	HBITMAP hBmp5=::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP5));
	m_bt5.SetBitmap(hBmp5);
	CRect rect;
	m_listctrl.GetClientRect(&rect);
	m_listctrl.SetExtendedStyle(m_listctrl.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	m_listctrl.InsertColumn(0,_T("书号"),LVCFMT_CENTER,(rect.Width()/50)*6,0);
	m_listctrl.InsertColumn(1,_T("书名"),LVCFMT_CENTER,(rect.Width()/50)*10,1);
	m_listctrl.InsertColumn(2,_T("作者"),LVCFMT_CENTER,(rect.Width()/50)*5,2);
	m_listctrl.InsertColumn(3,_T("价格"),LVCFMT_CENTER,(rect.Width()/50)*5,3);
	m_listctrl.InsertColumn(4,_T("库存"),LVCFMT_CENTER,(rect.Width()/50)*3,4);
	m_listctrl.InsertColumn(5,_T("借出"),LVCFMT_CENTER,(rect.Width()/50)*3,5);
	m_listctrl.InsertColumn(6,_T("出版社"),LVCFMT_CENTER,(rect.Width()/50)*8,6);
	m_listctrl.InsertColumn(7,_T("出版日期"),LVCFMT_CENTER,(rect.Width()/50)*6,7);
	m_listctrl.InsertColumn(8,_T("类别"),LVCFMT_CENTER,(rect.Width()/50)*5,8);
	displaylist();
	m_datecombo.SetCurSel(2);
	m_typecombo.SetCurSel(5);
	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CLibraryBeta03Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CLibraryBeta03Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CLibraryBeta03Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLibraryBeta03Dlg::OnBnClickedButton3()//点击删除按钮
{
	Cdata1 m_database;
	m_database.Open();
	m_database.MoveFirst();
	pos=m_listctrl.GetSelectionMark();//获得选中列表项索引
	CString m_num=m_listctrl.GetItemText(pos,0);//获得list表中pos行，0列的数据
	Cdata2 gettrash;
	gettrash.Open();

	while(!m_database.IsEOF())
	{
		if(m_num!=m_database.column1)
		{
			m_database.MoveNext();
		}
		else
		{
			gettrash.AddNew();//实现把删除的数据保存到回收数据库
			gettrash.column1=m_database.column1;
			gettrash.column2=m_database.column2;
			gettrash.column3=m_database.column3;
			gettrash.column4=m_database.column4;
			gettrash.column5=m_database.column5;
			gettrash.column6=m_database.column6;
			gettrash.column7=m_database.column7;
			gettrash.column8=m_database.column8;
			gettrash.column9=m_database.column9;
			m_database.Delete();//删除数据库中的当前记录
			gettrash.Update();
			m_database.MoveNext();
			if(gettrashnum()>2)
			{
				gettrash.MoveFirst();
				gettrash.Delete();
				gettrash.MoveNext();
			}

		}
	}
	gettrash.Close();
	m_database.Close();
	MessageBox(_T("删除成功"));
	m_listctrl.DeleteItem(pos);//删除选中列表项的数据
	displaylist();
}

//将数据库中的数据显示到列表框中
void CLibraryBeta03Dlg::displaylist(void)
{
	m_listctrl.DeleteAllItems();

	Cdata1 m_database;
	m_database.Open();
	m_database.MoveFirst();
	absdisplay(m_database);
	m_database.Close();
	m_bt7.EnableWindow(false);
	m_bt8.EnableWindow(false);
	CheckRadioButton(IDC_RADIO1,IDC_RADIO2,IDC_RADIO1);
}


//void CLibraryBeta03Dlg::OnThemechangedList1(NMHDR *pNMHDR, LRESULT *pResult)
//{
//	// 该功能要求使用 Windows XP 或更高版本。
//	// 符号 _WIN32_WINNT 必须 >= 0x0501。
//	// TODO: 在此添加控件通知处理程序代码
//	*pResult = 0;
//}



void CLibraryBeta03Dlg::OnClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	pos=m_listctrl.GetSelectionMark();//获取选中行
	m_num=m_listctrl.GetItemText(pos,0);//获得pos行，0列的数据
	m_bt2.EnableWindow(true);
	m_bt3.EnableWindow(true);
	*pResult = 0;
}

//实现修改按钮
void CLibraryBeta03Dlg::OnBnClickedButton2()
{
	INT_PTR nRes;
	ModifyInfo modifyinfo;
	nRes=modifyinfo.DoModal();
	UpdateData(true);
	if(judgeok==1)
		displaylist();

}

//点击添加按钮
void CLibraryBeta03Dlg::OnBnClickedButton1()
{

	INT_PTR nRes;
	AddInfoDlg addinfodlg;
	nRes=addinfodlg.DoModal();
	UpdateData(true);
	if(judgeok==1)
		displaylist();

}

//点击恢复按钮
void CLibraryBeta03Dlg::OnBnClickedButton4()//点击恢复按钮
{
	// TODO: 在此添加控件通知处理程序代码
	INT_PTR nRes;
	recover recoverdlg;
	nRes=recoverdlg.DoModal();
	UpdateData(true);
	if(judgeok==1)
		displaylist();
}

//点击搜索按钮
void CLibraryBeta03Dlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	if(m_searchbox.GetWindowTextLengthW()==0)
	{
		MessageBox(_T("输入框为空！"));
		return;
	}

	CString str,searcheditbox;
	m_searchbox.GetWindowTextW(searcheditbox);
	str.Format(_T("书名='%s'"),searcheditbox);
	searchCSC(str);

}

//清空搜索记录功能
void CLibraryBeta03Dlg::OnBnClickedButton9()//点击清空搜索记录按钮
{
	displaylist();
	m_searchbox.SetWindowTextW(_T(""));
}

//获取回收数据库中的记录数
int CLibraryBeta03Dlg::gettrashnum(void)
{
	int i=0;
	Cdata2 trashdata;
	trashdata.Open();
	trashdata.MoveFirst();
	for(i=0;!trashdata.IsEOF();i++)
	{trashdata.MoveNext();}
	trashdata.Close();
	return i;
}

//点击时间分类combo按钮
void CLibraryBeta03Dlg::OnSelendokCombo1()
{
	CString timestr;
	switch(m_datecombo.GetCurSel())
	{
	case 0:timestr.Format(_T("出版日期<#2000-01-01#"));searchCSC(timestr);break;
	case 1:timestr.Format(_T("出版日期>=#2000-01-01#"));searchCSC(timestr);break;
	default:displaylist();break;

	}
}
//点击类别分类combo按钮
void CLibraryBeta03Dlg::OnSelendokCombo2()
{
	CString typestr;
	switch(m_typecombo.GetCurSel())
	{
	case 0:	
		typestr=_T("类别='文史类'");
		searchCSC(typestr);
		break;
	case 1:		
		typestr=_T("类别='理工类'");
		searchCSC(typestr);
		break;
	case 2:
		typestr=_T("类别='社哲类'");
		searchCSC(typestr);
		break;
	case 3:
		typestr=_T("类别='生活类'");
		searchCSC(typestr);
		break;
	case 4:
		typestr=_T("类别='军事类'");
		searchCSC(typestr);
		break;
	default:displaylist();break;
	}
}

//抽象文字搜索功能
void CLibraryBeta03Dlg::searchCSC(CString searchstr)
{
	Cdata1 absearch;
	absearch.Open();
	absearch.MoveFirst();
	int num=0;
	absearch.m_strFilter=searchstr;
	absearch.Requery();
	if(absearch.GetRecordCount()==0)
		MessageBox(_T("不存在您需要的书籍信息！"));
	else
		{
			m_listctrl.DeleteAllItems();
			int i=0;
			absearch.MoveFirst();
			absdisplay(absearch);
		}

	absearch.Close();
}

//点击“全部显示”单选点
void CLibraryBeta03Dlg::OnBnClickedRadio1()
{
	m_datecombo.SetCurSel(2);
	m_typecombo.SetCurSel(5);
	displaylist();
}

//点击“分页显示”单选点
void CLibraryBeta03Dlg::OnBnClickedRadio2()
{
	m_bt2.EnableWindow(false);
	m_bt3.EnableWindow(false);
	m_bt7.EnableWindow(true);
	m_bt8.EnableWindow(true);
	pageJ=0;
	Cdata1 pageDB;
	pageDB.Open();
	absdisplay(pageDB,pageJ);
	pageDB.Close();
	
}

//获取借出或库存数目
int CLibraryBeta03Dlg::getAmount(int col)//col为列数
{
	int i=0;
	int s=0;
	for(i=0;i<=m_listctrl.GetItemCount();i++)
	{
		s=s+_wtoi(m_listctrl.GetItemText(i,col));
	}
	return s;
}
//重载getAmount函数获取金额价值
double CLibraryBeta03Dlg::getAmount(int pricecol,int col)
{
	int i=0;
	double s=0;
	for(i=0;i<=m_listctrl.GetItemCount();i++)
	{
		s=s+(_wtoi(m_listctrl.GetItemText(i,col))*(_wtof(m_listctrl.GetItemText(i,pricecol))));
	}
	return s;
}
//抽象显示列表函数1，点击全部显示时
void CLibraryBeta03Dlg::absdisplay(Cdata1 &absDB)
{
	int i;
	CString str;
	for(i=0;!absDB.IsEOF();i++)
	{
		m_listctrl.InsertItem(i,_T(""));//添加一行

		m_listctrl.SetItemText(i,0,absDB.column1);
		m_listctrl.SetItemText(i,1,absDB.column2);
		m_listctrl.SetItemText(i,2,absDB.column3);

		str.Format(_T("%.2f"),absDB.column4);
		m_listctrl.SetItemText(i,3,str);

		str.Format(_T("%d"),absDB.column5);
		m_listctrl.SetItemText(i,4,str);

		str.Format(_T("%d"),absDB.column6);
		m_listctrl.SetItemText(i,5,str);

		m_listctrl.SetItemText(i,6,absDB.column7);

		CString strtime;
		strtime.Format(_T("%s"),absDB.column8.Format("%Y-%m-%d"));//时间格式转换
		m_listctrl.SetItemText(i,7,strtime);

		m_listctrl.SetItemText(i,8,absDB.column9);
		absDB.MoveNext();
	}
	m_bt2.EnableWindow(false);
	m_bt3.EnableWindow(false);
	statistics();
	sumbooks=getAmount(4)+getAmount(5);
	summoney=getAmount(3,4)+getAmount(3,5);


}
//抽象显示列表函数2，点击分页显示时
int CLibraryBeta03Dlg::absdisplay(Cdata1 &absDB,int count)
{
	m_listctrl.DeleteAllItems();
	int i;
	CString str;
	absDB.SetAbsolutePosition(17*count+1);
	for(i=0;!absDB.IsEOF()&&i<17;i++)
	{
		m_listctrl.InsertItem(i,_T(""));//添加一行

		m_listctrl.SetItemText(i,0,absDB.column1);
		m_listctrl.SetItemText(i,1,absDB.column2);
		m_listctrl.SetItemText(i,2,absDB.column3);

		str.Format(_T("%.2f"),absDB.column4);
		m_listctrl.SetItemText(i,3,str);

		str.Format(_T("%d"),absDB.column5);
		m_listctrl.SetItemText(i,4,str);

		str.Format(_T("%d"),absDB.column6);
		m_listctrl.SetItemText(i,5,str);

		m_listctrl.SetItemText(i,6,absDB.column7);

		CString strtime;
		strtime.Format(_T("%s"),absDB.column8.Format("%Y-%m-%d"));//时间格式转换
		m_listctrl.SetItemText(i,7,strtime);

		m_listctrl.SetItemText(i,8,absDB.column9);
		absDB.MoveNext();
	}

	m_bt2.EnableWindow(false);
	m_bt3.EnableWindow(false);
	statistics();
	if(absDB.IsEOF()) 
	{return 1;}
	else 
	{return 0;}
}

// 统计信息栏目
void CLibraryBeta03Dlg::statistics(void)
{
	CString amountstr;
	amountstr.Format(_T("%d"),getAmount(5));
	m_alllendedbox.SetWindowTextW(amountstr);
	amountstr.Format(_T("%d"),getAmount(4));
	m_allstoragebox.SetWindowTextW(amountstr);
	amountstr.Format(_T("%d"),getAmount(4)+getAmount(5));
	m_allbooks.SetWindowTextW(amountstr);
	amountstr.Format(_T("%.2f"),getAmount(3,5));
	m_alllendedmoney.SetWindowTextW(amountstr);
	amountstr.Format(_T("%.2f"),getAmount(3,4));
	m_allstoragemoney.SetWindowTextW(amountstr);
	amountstr.Format(_T("%.2f"),getAmount(3,4)+getAmount(3,5));
	m_allmoney.SetWindowTextW(amountstr);
}

//点击下一页
void CLibraryBeta03Dlg::OnBnClickedButton8()
{
	pageJ+=1;
	m_bt7.EnableWindow(true);
	Cdata1 pageDB;
	pageDB.Open();
	if(absdisplay(pageDB,pageJ))
		m_bt8.EnableWindow(false);
	pageDB.Close();
}

//点击上一页按钮
void CLibraryBeta03Dlg::OnBnClickedButton7()
{
	pageJ-=1;
	if(pageJ<0)
	{
		pageJ=0;
		m_bt7.EnableWindow(false);
		MessageBox(_T("这已是第一页！"));
	}
	else
	{
		Cdata1 pageDB;
		pageDB.Open();
		absdisplay(pageDB,pageJ);
		pageDB.Close();
	}
	m_bt8.EnableWindow(true);
}

//点击打印按钮
void CLibraryBeta03Dlg::OnBnClickedButton5()
{
	printDlg printdlg;
	printdlg.DoModal();
	
	
}



void CLibraryBeta03Dlg::OnKillfocusEdit1()
{
	m_searchtip.ShowWindow(false);
}


void CLibraryBeta03Dlg::OnSetfocusEdit1()
{
	m_searchtip.SetWindowTextW(_T("请输入书名检索"));
	m_searchtip.ShowWindow(true);
}
