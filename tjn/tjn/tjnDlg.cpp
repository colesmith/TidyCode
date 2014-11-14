
// tjnDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "tjn.h"
#include "tjnDlg.h"
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


// CtjnDlg �Ի���




CtjnDlg::CtjnDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CtjnDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CtjnDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MULTI_LINE_EDIT, m_editMultiLine);
}

BEGIN_MESSAGE_MAP(CtjnDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_32772, &CtjnDlg::On32772)
END_MESSAGE_MAP()


// CtjnDlg ��Ϣ�������

BOOL CtjnDlg::OnInitDialog()
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
   
  
    // Add "About..." menu item to system menu.   
  
    // IDM_ABOUTBOX must be in the system command range.   
    ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);   
    ASSERT(IDM_ABOUTBOX < 0xF000);   
    
    // TODO: Add extra initialization here   
    //m_editMultiLine.SetWindowText(_T("Visual Studio 2010 : http://yunpan.cn/csWbDd4AwYJqJ  ��ȡ�� b1bb\r\nVisual Studio ʹ���Լ� MFC����: http://depts.washington.edu/cmmr/biga/chapter_tutorial/1.C++_MFC_D3DOGL/1.StepByStepGuide/index.html"));         
  

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CtjnDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CtjnDlg::OnPaint()
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
HCURSOR CtjnDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CtjnDlg::On32772()
{
	// TODO: �ڴ���������������
	 TCHAR szFilter[] = _T("�ı��ļ�(*.txt)|*.txt|�����ļ�(*.*)|*.*||");   
    // ������ļ��Ի���   
    CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, this);   
    CString strFilePath;
	CFileException fileException;
	if (IDOK == fileDlg.DoModal())   
    {   
        // ���������ļ��Ի����ϵġ��򿪡���ť����ѡ����ļ�·����ʾ���༭����   
        strFilePath = fileDlg.GetPathName();
		CStdioFile myFile;
		 if(myFile.Open(strFilePath,CFile::typeText|CFile::modeReadWrite),&fileException)

		{

			myFile.SeekToBegin();

			CString strLine;
			CString strText;

			while(myFile.ReadString(strLine))
			{
				strText += strLine;
				strText += "\r\n";
			}
			m_editMultiLine.SetWindowText(strText);

		}

		else

		{

			TRACE("Can't open file %s,error=%u\n",strFilePath,fileException.m_cause);
	
		}

		myFile.Close();
    }   
}
