
// TidyCodeDlg.h : ͷ�ļ�
//

#pragma once


// CTidyCodeDlg �Ի���
class CTidyCodeDlg : public CDialogEx
{
// ����
public:
	CTidyCodeDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_TIDYCODE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEditContent();
	afx_msg void OnFileExit();
	CString m_EditContent;
};
