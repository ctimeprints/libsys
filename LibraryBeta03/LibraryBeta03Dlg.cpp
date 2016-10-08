
// LibraryBeta03Dlg.cpp : ʵ���ļ�
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
// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CLibraryBeta03Dlg �Ի���




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


// CLibraryBeta03Dlg ��Ϣ�������

BOOL CLibraryBeta03Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:��ʼ�����ݣ����������ڼ���ʾ������
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

	m_listctrl.InsertColumn(0,_T("���"),LVCFMT_CENTER,(rect.Width()/50)*6,0);
	m_listctrl.InsertColumn(1,_T("����"),LVCFMT_CENTER,(rect.Width()/50)*10,1);
	m_listctrl.InsertColumn(2,_T("����"),LVCFMT_CENTER,(rect.Width()/50)*5,2);
	m_listctrl.InsertColumn(3,_T("�۸�"),LVCFMT_CENTER,(rect.Width()/50)*5,3);
	m_listctrl.InsertColumn(4,_T("���"),LVCFMT_CENTER,(rect.Width()/50)*3,4);
	m_listctrl.InsertColumn(5,_T("���"),LVCFMT_CENTER,(rect.Width()/50)*3,5);
	m_listctrl.InsertColumn(6,_T("������"),LVCFMT_CENTER,(rect.Width()/50)*8,6);
	m_listctrl.InsertColumn(7,_T("��������"),LVCFMT_CENTER,(rect.Width()/50)*6,7);
	m_listctrl.InsertColumn(8,_T("���"),LVCFMT_CENTER,(rect.Width()/50)*5,8);
	displaylist();
	m_datecombo.SetCurSel(2);
	m_typecombo.SetCurSel(5);
	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CLibraryBeta03Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CLibraryBeta03Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLibraryBeta03Dlg::OnBnClickedButton3()//���ɾ����ť
{
	Cdata1 m_database;
	m_database.Open();
	m_database.MoveFirst();
	pos=m_listctrl.GetSelectionMark();//���ѡ���б�������
	CString m_num=m_listctrl.GetItemText(pos,0);//���list����pos�У�0�е�����
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
			gettrash.AddNew();//ʵ�ְ�ɾ�������ݱ��浽�������ݿ�
			gettrash.column1=m_database.column1;
			gettrash.column2=m_database.column2;
			gettrash.column3=m_database.column3;
			gettrash.column4=m_database.column4;
			gettrash.column5=m_database.column5;
			gettrash.column6=m_database.column6;
			gettrash.column7=m_database.column7;
			gettrash.column8=m_database.column8;
			gettrash.column9=m_database.column9;
			m_database.Delete();//ɾ�����ݿ��еĵ�ǰ��¼
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
	MessageBox(_T("ɾ���ɹ�"));
	m_listctrl.DeleteItem(pos);//ɾ��ѡ���б��������
	displaylist();
}

//�����ݿ��е�������ʾ���б����
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
//	// �ù���Ҫ��ʹ�� Windows XP ����߰汾��
//	// ���� _WIN32_WINNT ���� >= 0x0501��
//	// TODO: �ڴ���ӿؼ�֪ͨ����������
//	*pResult = 0;
//}



void CLibraryBeta03Dlg::OnClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	pos=m_listctrl.GetSelectionMark();//��ȡѡ����
	m_num=m_listctrl.GetItemText(pos,0);//���pos�У�0�е�����
	m_bt2.EnableWindow(true);
	m_bt3.EnableWindow(true);
	*pResult = 0;
}

//ʵ���޸İ�ť
void CLibraryBeta03Dlg::OnBnClickedButton2()
{
	INT_PTR nRes;
	ModifyInfo modifyinfo;
	nRes=modifyinfo.DoModal();
	UpdateData(true);
	if(judgeok==1)
		displaylist();

}

//�����Ӱ�ť
void CLibraryBeta03Dlg::OnBnClickedButton1()
{

	INT_PTR nRes;
	AddInfoDlg addinfodlg;
	nRes=addinfodlg.DoModal();
	UpdateData(true);
	if(judgeok==1)
		displaylist();

}

//����ָ���ť
void CLibraryBeta03Dlg::OnBnClickedButton4()//����ָ���ť
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	INT_PTR nRes;
	recover recoverdlg;
	nRes=recoverdlg.DoModal();
	UpdateData(true);
	if(judgeok==1)
		displaylist();
}

//���������ť
void CLibraryBeta03Dlg::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	if(m_searchbox.GetWindowTextLengthW()==0)
	{
		MessageBox(_T("�����Ϊ�գ�"));
		return;
	}

	CString str,searcheditbox;
	m_searchbox.GetWindowTextW(searcheditbox);
	str.Format(_T("����='%s'"),searcheditbox);
	searchCSC(str);

}

//���������¼����
void CLibraryBeta03Dlg::OnBnClickedButton9()//������������¼��ť
{
	displaylist();
	m_searchbox.SetWindowTextW(_T(""));
}

//��ȡ�������ݿ��еļ�¼��
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

//���ʱ�����combo��ť
void CLibraryBeta03Dlg::OnSelendokCombo1()
{
	CString timestr;
	switch(m_datecombo.GetCurSel())
	{
	case 0:timestr.Format(_T("��������<#2000-01-01#"));searchCSC(timestr);break;
	case 1:timestr.Format(_T("��������>=#2000-01-01#"));searchCSC(timestr);break;
	default:displaylist();break;

	}
}
//���������combo��ť
void CLibraryBeta03Dlg::OnSelendokCombo2()
{
	CString typestr;
	switch(m_typecombo.GetCurSel())
	{
	case 0:	
		typestr=_T("���='��ʷ��'");
		searchCSC(typestr);
		break;
	case 1:		
		typestr=_T("���='����'");
		searchCSC(typestr);
		break;
	case 2:
		typestr=_T("���='������'");
		searchCSC(typestr);
		break;
	case 3:
		typestr=_T("���='������'");
		searchCSC(typestr);
		break;
	case 4:
		typestr=_T("���='������'");
		searchCSC(typestr);
		break;
	default:displaylist();break;
	}
}

//����������������
void CLibraryBeta03Dlg::searchCSC(CString searchstr)
{
	Cdata1 absearch;
	absearch.Open();
	absearch.MoveFirst();
	int num=0;
	absearch.m_strFilter=searchstr;
	absearch.Requery();
	if(absearch.GetRecordCount()==0)
		MessageBox(_T("����������Ҫ���鼮��Ϣ��"));
	else
		{
			m_listctrl.DeleteAllItems();
			int i=0;
			absearch.MoveFirst();
			absdisplay(absearch);
		}

	absearch.Close();
}

//�����ȫ����ʾ����ѡ��
void CLibraryBeta03Dlg::OnBnClickedRadio1()
{
	m_datecombo.SetCurSel(2);
	m_typecombo.SetCurSel(5);
	displaylist();
}

//�������ҳ��ʾ����ѡ��
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

//��ȡ���������Ŀ
int CLibraryBeta03Dlg::getAmount(int col)//colΪ����
{
	int i=0;
	int s=0;
	for(i=0;i<=m_listctrl.GetItemCount();i++)
	{
		s=s+_wtoi(m_listctrl.GetItemText(i,col));
	}
	return s;
}
//����getAmount������ȡ����ֵ
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
//������ʾ�б���1�����ȫ����ʾʱ
void CLibraryBeta03Dlg::absdisplay(Cdata1 &absDB)
{
	int i;
	CString str;
	for(i=0;!absDB.IsEOF();i++)
	{
		m_listctrl.InsertItem(i,_T(""));//���һ��

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
		strtime.Format(_T("%s"),absDB.column8.Format("%Y-%m-%d"));//ʱ���ʽת��
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
//������ʾ�б���2�������ҳ��ʾʱ
int CLibraryBeta03Dlg::absdisplay(Cdata1 &absDB,int count)
{
	m_listctrl.DeleteAllItems();
	int i;
	CString str;
	absDB.SetAbsolutePosition(17*count+1);
	for(i=0;!absDB.IsEOF()&&i<17;i++)
	{
		m_listctrl.InsertItem(i,_T(""));//���һ��

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
		strtime.Format(_T("%s"),absDB.column8.Format("%Y-%m-%d"));//ʱ���ʽת��
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

// ͳ����Ϣ��Ŀ
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

//�����һҳ
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

//�����һҳ��ť
void CLibraryBeta03Dlg::OnBnClickedButton7()
{
	pageJ-=1;
	if(pageJ<0)
	{
		pageJ=0;
		m_bt7.EnableWindow(false);
		MessageBox(_T("�����ǵ�һҳ��"));
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

//�����ӡ��ť
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
	m_searchtip.SetWindowTextW(_T("��������������"));
	m_searchtip.ShowWindow(true);
}
