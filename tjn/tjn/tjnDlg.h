
// tjnDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CtjnDlg �Ի���
class CtjnDlg : public CDialogEx
{
// ����
public:
	CtjnDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_TJN_DIALOG };

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
private:
	CEdit m_editMultiLine;
public:
	afx_msg void On32772();
};
