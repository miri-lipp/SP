
// visinerDlg.h : header file
//

#pragma once


// CvisinerDlg dialog
class CvisinerDlg : public CDialogEx
{
// Construction
public:
	CvisinerDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_VISINER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnBnClickedOk();
	CEdit CIPHER;
	afx_msg void OnEnChangeEdit1();
	CEdit outf;
	CEdit inf;
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnCbnSelchangeCombo2();
	CComboBox language;
	afx_msg void OnEditchangeCombo2();
	CString stat;
};
