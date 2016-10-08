// Cdata1.h : Cdata1 类的实现



// Cdata1 实现

// 代码生成在 2013年6月25日, 23:55

#include "stdafx.h"
#include "Cdata1.h"
#include "Cdata2.h"
IMPLEMENT_DYNAMIC(Cdata1, CRecordset)

Cdata1::Cdata1(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	column1 = L"";
	column2 = L"";
	column3 = L"";
	column4 = 0.0;
	column5 = 0;
	column6 = 0;
	column7 = L"";
	column8;
	column9 = L"";
	m_nFields = 10;
	m_nDefaultType = dynaset;
}

// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString Cdata1::GetDefaultConnect()
{
	return _T("DBQ=D:\\Documents\\Visual Studio 2010\\LibraryBeta03\\Debug\\LibraryACESS.mdb;DefaultDir=D:\\Documents\\Visual Studio 2010\\LibraryBeta03\\Debug;Driver={Microsoft Access Driver (*.mdb)};DriverId=25;FIL=MS Access;FILEDSN=D:\\Documents\\Visual Studio 2010\\LibraryBeta03\\Debug\\LibraryACESS.mdb.dsn;MaxBufferSize=2048;MaxScanRows=8;PageTimeout=5;SafeTransactions=0;Threads=3;UID=admin;UserCommitSync=Yes;");
}

CString Cdata1::GetDefaultSQL()
{
	return _T("[表1]");
}

void Cdata1::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[书号]"), column1);
	RFX_Text(pFX, _T("[书名]"), column2);
	RFX_Text(pFX, _T("[作者]"), column3);
	RFX_Double(pFX, _T("[价格]"), column4);
	RFX_Long(pFX, _T("[库存]"), column5);
	RFX_Long(pFX, _T("[借出]"), column6);
	RFX_Text(pFX, _T("[出版社]"), column7);
	RFX_Date(pFX, _T("[出版日期]"), column8);
	RFX_Text(pFX, _T("[类别]"), column9);

}
/////////////////////////////////////////////////////////////////////////////
// Cdata1 诊断

#ifdef _DEBUG
void Cdata1::AssertValid() const
{
	CRecordset::AssertValid();
}

void Cdata1::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


