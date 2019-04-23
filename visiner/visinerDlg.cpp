
// visinerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "visiner.h"
#include "visinerDlg.h"
#include "afxdialogex.h"
#include "crypt.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CAboutDlg dialog used for App About
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CvisinerDlg dialog



CvisinerDlg::CvisinerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_VISINER_DIALOG, pParent)
	, stat(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CvisinerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, CIPHER);
	DDX_Control(pDX, IDC_EDIT2, outf);
	DDX_Control(pDX, IDC_EDIT3, inf);
	DDX_Control(pDX, IDC_COMBO2, language);
	DDX_CBString(pDX, IDC_COMBO2, stat);
}

BEGIN_MESSAGE_MAP(CvisinerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT3, &CvisinerDlg::OnEnChangeEdit3)
	ON_BN_CLICKED(IDOK, &CvisinerDlg::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT1, &CvisinerDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CvisinerDlg::OnEnChangeEdit2)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CvisinerDlg::OnCbnSelchangeCombo2)
	ON_CBN_EDITCHANGE(IDC_COMBO2, &CvisinerDlg::OnEditchangeCombo2)
END_MESSAGE_MAP()


// CvisinerDlg message handlers

BOOL CvisinerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	language.AddString(L"English");
	language.AddString(L"Russian");
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CvisinerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CvisinerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CvisinerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CvisinerDlg::OnEnChangeEdit3()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CvisinerDlg::OnBnClickedOk()
{

	CString key, output_file, input_file;
	// TODO: Add your control notification handler code here
	CIPHER.GetWindowTextW(key);
	outf.GetWindowTextW(output_file);
	inf.GetWindowTextW(input_file);
	//test(input_file, output_file);
	readfile(input_file);
	encrypt(key);
	writefile(output_file);
	CDialogEx::OnOK();
}


void CvisinerDlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CvisinerDlg::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}



void CvisinerDlg::OnCbnSelchangeCombo2()
{

	// TODO: Add your control notification handler code here
	language.GetLBText(language.GetCurSel(), stat);
	UpdateData(false);
}


void CvisinerDlg::OnEditchangeCombo2()
{
	// TODO: Add your control notification handler code here
}
