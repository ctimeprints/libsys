// printDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LibraryBeta03.h"
#include "printDlg.h"
#include "afxdialogex.h"
#include <afxwin.h>   
#include <afxdb.h>   
#include <odbcinst.h>   
#include "Cdata1.h"
extern int sumbooks;
extern double summoney;

// printDlg �Ի���

IMPLEMENT_DYNAMIC(printDlg, CDialogEx)

printDlg::printDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(printDlg::IDD, pParent)
{

}

printDlg::~printDlg()
{
}

void printDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(printDlg, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &printDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &printDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// printDlg ��Ϣ�������


void printDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void printDlg::OnBnClickedOk()
{
	CDatabase   database;   
    CString     sDriver=_T("MICROSOFT EXCEL DRIVER (*.XLS)");    
    CString     sExcelFile=_T("C:\\Users\\Public\\Desktop\\�鼮��Ϣ��.xls");   
    CString     sSQL;   

    //   
    sSQL.Format(_T("DRIVER={%s};DSN='''';FIRSTROWHASNAMES=1;READONLY=FALSE;CREATE_DB=\"%s\";DBQ=%s"),sDriver, sExcelFile, sExcelFile);   

    if (database.OpenEx(sSQL, CDatabase::noOdbcDialog)) 
	{   
        //������ṹ   
        sSQL="CREATE TABLE �鼮��Ϣ�� (��� TEXT,���� TEXT,���� TEXT,�۸� TEXT,��� TEXT,��� TEXT,������ TEXT,�������� TEXT,��� TEXT)";   
        database.ExecuteSQL(sSQL);   

        //������ֵ
		Cdata1 dbout;
		dbout.Open();
		dbout.MoveFirst();
		while(!dbout.IsEOF())
		{

			CString strtime;
			strtime.Format(_T("%s"),dbout.column8.Format("%Y-%m-%d"));//ʱ���ʽת��
			sSQL.Format(_T("INSERT INTO �鼮��Ϣ�� (���,����,����,�۸�,���,���,������,��������,���) VALUES ('%s','%s','%s','%.2f','%d','%d','%s','%s','%s')"),\
				(LPSTR)(LPCTSTR)dbout.column1,(LPSTR)(LPCTSTR)dbout.column2,(LPSTR)(LPCTSTR)dbout.column3,\
				dbout.column4,dbout.column5,dbout.column6,\
				(LPSTR)(LPCTSTR)dbout.column7,(LPSTR)(LPCTSTR)strtime,(LPSTR)(LPCTSTR)dbout.column9);   
			database.ExecuteSQL(sSQL);   
			dbout.MoveNext();
		}   
		dbout.Close();
		sSQL.Format(_T("INSERT INTO �鼮��Ϣ�� (����,�۸�) VALUES('������','%d')"),sumbooks);
		database.ExecuteSQL(sSQL);  
		sSQL.Format(_T("INSERT INTO �鼮��Ϣ�� (����,�۸�) VALUES('�ܽ��','%.2f')"),summoney);
		database.ExecuteSQL(sSQL); 
    }   
    else 
	{   
        AfxMessageBox(_T("error"));   
    }   

    // close the database   
    database.Close();   
    AfxMessageBox(_T("Excel�ļ������ɹ���\n�ѱ��浽���棬����Դ�ӡ��"));   
	CDialogEx::OnOK();
}
