// Cdata2.h : Cdata2 ���ʵ��



// Cdata2 ʵ��

// ���������� 2013��6��26��, 19:17

#include "stdafx.h"
#include "Cdata2.h"
#include "Cdata1.h"
IMPLEMENT_DYNAMIC(Cdata2, CRecordset)

Cdata2::Cdata2(CDatabase* pdb)
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
//#error ��ȫ���⣺�����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString Cdata2::GetDefaultConnect()
{
	return _T("DBQ=D:\\Documents\\Visual Studio 2010\\LibraryBeta03\\Debug\\LibraryTrashcan.mdb;DefaultDir=D:\\Documents\\Visual Studio 2010\\LibraryBeta03\\Debug;Driver={Microsoft Access Driver (*.mdb)};DriverId=25;FIL=MS Access;FILEDSN=D:\\Documents\\Visual Studio 2010\\LibraryBeta03\\Debug\\LibraryTrashcan.mdb.dsn;MaxBufferSize=2048;MaxScanRows=8;PageTimeout=5;SafeTransactions=0;Threads=3;UID=admin;UserCommitSync=Yes;");
}

CString Cdata2::GetDefaultSQL()
{
	return _T("[��1]");
}

void Cdata2::DoFieldExchange(CFieldExchange* pFX)
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
// Cdata2 ���

#ifdef _DEBUG
void Cdata2::AssertValid() const
{
	CRecordset::AssertValid();
}

void Cdata2::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


