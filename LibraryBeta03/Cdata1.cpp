// Cdata1.h : Cdata1 ���ʵ��



// Cdata1 ʵ��

// ���������� 2013��6��25��, 23:55

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

// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString Cdata1::GetDefaultConnect()
{
	return _T("DBQ=D:\\Documents\\Visual Studio 2010\\LibraryBeta03\\Debug\\LibraryACESS.mdb;DefaultDir=D:\\Documents\\Visual Studio 2010\\LibraryBeta03\\Debug;Driver={Microsoft Access Driver (*.mdb)};DriverId=25;FIL=MS Access;FILEDSN=D:\\Documents\\Visual Studio 2010\\LibraryBeta03\\Debug\\LibraryACESS.mdb.dsn;MaxBufferSize=2048;MaxScanRows=8;PageTimeout=5;SafeTransactions=0;Threads=3;UID=admin;UserCommitSync=Yes;");
}

CString Cdata1::GetDefaultSQL()
{
	return _T("[��1]");
}

void Cdata1::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[���]"), column1);
	RFX_Text(pFX, _T("[����]"), column2);
	RFX_Text(pFX, _T("[����]"), column3);
	RFX_Double(pFX, _T("[�۸�]"), column4);
	RFX_Long(pFX, _T("[���]"), column5);
	RFX_Long(pFX, _T("[���]"), column6);
	RFX_Text(pFX, _T("[������]"), column7);
	RFX_Date(pFX, _T("[��������]"), column8);
	RFX_Text(pFX, _T("[���]"), column9);

}
/////////////////////////////////////////////////////////////////////////////
// Cdata1 ���

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


