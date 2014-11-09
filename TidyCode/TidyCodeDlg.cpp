
// TidyCodeDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TidyCode.h"
#include "TidyCodeDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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


// CTidyCodeDlg �Ի���




CTidyCodeDlg::CTidyCodeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTidyCodeDlg::IDD, pParent)
	, m_EditContent(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTidyCodeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CONTENT, m_EditContent);
}

BEGIN_MESSAGE_MAP(CTidyCodeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_FILE_OPEN, &CTidyCodeDlg::OnFileOpen)
	ON_EN_CHANGE(IDC_EDIT1, &CTidyCodeDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT_CONTENT, &CTidyCodeDlg::OnEnChangeEditContent)
	ON_COMMAND(ID_FILE_EXIT, &CTidyCodeDlg::OnFileExit)
END_MESSAGE_MAP()


// CTidyCodeDlg ��Ϣ�������

BOOL CTidyCodeDlg::OnInitDialog()
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

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CTidyCodeDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTidyCodeDlg::OnPaint()
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
HCURSOR CTidyCodeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTidyCodeDlg::OnFileOpen()
{
	// TODO: �ڴ���������������
	CFileDialog fileDlg = CFileDialog(TRUE,
		NULL,
		NULL,
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		(LPCTSTR)TEXT("All Files(*.*)|*.*|C Source File(*.c)|*.c|C/C++ Header File(*.h)|*.h|C++ Source File(*.cpp)|*.cpp|Python Source File(*.py)|*.py||"),
		NULL);

	if (fileDlg.DoModal() == IDOK)
	{
		CString FilePathName = fileDlg.GetPathName();
		CString FileName = fileDlg.GetFileName();

		CFile pCFile;
		if (! pCFile.Open(FilePathName, CFile::modeRead))
		{
			MessageBox(TEXT("Open File Error"), TEXT("Error"), MB_OK);
			return ;
		}

		char * pBuf;
		DWORD dwFileLen;
		dwFileLen = pCFile.GetLength();
		pBuf = new char[dwFileLen + 1];
		pBuf[dwFileLen] = 0;

		pCFile.Read(pBuf, dwFileLen);
		pCFile.Close();

		GetDlgItem(IDC_EDIT_CONTENT)->SetWindowTextW(CString(pBuf));
		
	} else {
		
		return ;
	}
}


void CTidyCodeDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CTidyCodeDlg::OnEnChangeEditContent()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CTidyCodeDlg::OnFileExit()
{
	// �رմ��ڣ�����WM_CLOSE��Ϣ
	AfxGetMainWnd()->SendMessage(WM_CLOSE); 
}
