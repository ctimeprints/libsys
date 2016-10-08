// printDlg.cpp : 实现文件
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

// printDlg 对话框

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


// printDlg 消息处理程序


void printDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void printDlg::OnBnClickedOk()
{
	CDatabase   database;   
    CString     sDriver=_T("MICROSOFT EXCEL DRIVER (*.XLS)");    
    CString     sExcelFile=_T("C:\\Users\\Public\\Desktop\\书籍信息表.xls");   
    CString     sSQL;   

    //   
    sSQL.Format(_T("DRIVER={%s};DSN='''';FIRSTROWHASNAMES=1;READONLY=FALSE;CREATE_DB=\"%s\";DBQ=%s"),sDriver, sExcelFile, sExcelFile);   

    if (database.OpenEx(sSQL, CDatabase::noOdbcDialog)) 
	{   
        //创建表结构   
        sSQL="CREATE TABLE 书籍信息表 (书号 TEXT,书名 TEXT,作者 TEXT,价格 TEXT,库存 TEXT,借出 TEXT,出版社 TEXT,出版日期 TEXT,类别 TEXT)";   
        database.ExecuteSQL(sSQL);   

        //插入数值
		Cdata1 dbout;
		dbout.Open();
		dbout.MoveFirst();
		while(!dbout.IsEOF())
		{

			CString strtime;
			strtime.Format(_T("%s"),dbout.column8.Format("%Y-%m-%d"));//时间格式转换
			sSQL.Format(_T("INSERT INTO 书籍信息表 (书号,书名,作者,价格,库存,借出,出版社,出版日期,类别) VALUES ('%s','%s','%s','%.2f','%d','%d','%s','%s','%s')"),\
				(LPSTR)(LPCTSTR)dbout.column1,(LPSTR)(LPCTSTR)dbout.column2,(LPSTR)(LPCTSTR)dbout.column3,\
				dbout.column4,dbout.column5,dbout.column6,\
				(LPSTR)(LPCTSTR)dbout.column7,(LPSTR)(LPCTSTR)strtime,(LPSTR)(LPCTSTR)dbout.column9);   
			database.ExecuteSQL(sSQL);   
			dbout.MoveNext();
		}   
		dbout.Close();
		sSQL.Format(_T("INSERT INTO 书籍信息表 (作者,价格) VALUES('总数量','%d')"),sumbooks);
		database.ExecuteSQL(sSQL);  
		sSQL.Format(_T("INSERT INTO 书籍信息表 (作者,价格) VALUES('总金额','%.2f')"),summoney);
		database.ExecuteSQL(sSQL); 
    }   
    else 
	{   
        AfxMessageBox(_T("error"));   
    }   

    // close the database   
    database.Close();   
    AfxMessageBox(_T("Excel文件导出成功！\n已保存到桌面，请打开以打印！"));   
	CDialogEx::OnOK();
}
