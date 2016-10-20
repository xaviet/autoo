
// autooDlg.cpp : implementation file
//

#include "stdafx.h"
#include "autoo.h"
#include "autooDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CautooDlg dialog



CautooDlg::CautooDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_AUTOO_DIALOG, pParent)
	, m_position(_T(""))
	, m_operate(_T(""))
	, m_setact(0)
	, m_starttime(210000)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CautooDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_position, m_position);
	DDX_Text(pDX, IDC_operate, m_operate);
}

BEGIN_MESSAGE_MAP(CautooDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_act, &CautooDlg::OnClickedAct)
	ON_BN_CLICKED(IDC_log, &CautooDlg::OnClickedLog)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CautooDlg message handlers

BOOL CautooDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	SetTimer(TIMER_1s, 1000, NULL);
	UpdateData(TRUE);
	this->m_operate.Format(_T("%d"), this->m_starttime);
	UpdateData(FALSE);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CautooDlg::OnPaint()
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
HCURSOR CautooDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CautooDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	UpdateData(TRUE);
	CPoint t_opt;
	GetCursorPos(&t_opt);
	CString t_cs;
	t_cs.Format(_T("%d, %d"), t_opt.x, t_opt.y);
	this->m_position = t_cs;
	UpdateData(FALSE);
	CDialogEx::OnMouseMove(nFlags, point);
}

void CautooDlg::OnClickedAct()
{
	// TODO: 在此添加控件通知处理程序代码
	CString t_cs;
	UpdateData(TRUE);
	doanalzyoperate();
	this->m_starttime = _ttoi(this->m_operate);
	this->m_operate.Format(_T("%s %s") , this->m_operate,_T("will run!"));
	UpdateData(FALSE);
	//MessageBox(this->m_operate);
	m_setact = (m_setact == 1 ? 0 : 1);
}

void CautooDlg::OnClickedLog()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(FALSE);
	//MessageBox(this->m_operate);
	UpdateData(TRUE);
}

int CautooDlg::doanalzyoperate()
{
	return(TRUE);
}

int CautooDlg::domouseclick(int v_x, int v_y, int v_sleepms=0)
{
	SetCursorPos(v_x, v_y);
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	Sleep(v_sleepms);
	return(TRUE);
}

int CautooDlg::doact()
{
	int t_i = 0;
	t_i = _ttoi((m_currentdate.Left(14)).Right(6));

	if (t_i >= this->m_starttime)
	{
		m_setact = 0;
		//MessageBox(t_cs);
		//Sleep(2000);

    /* 1440X900 */
    domouseclick(1400, 20, 8000);
    domouseclick(1310, 205, 2000);
    domouseclick(330, 250, 8000);
    domouseclick(1100, 440, 8000);
    domouseclick(1300, 20, 8000);
    domouseclick(35, 140, 2000);
    domouseclick(70, 225, 2000);
    domouseclick(260, 420, 2000);
    domouseclick(480, 450, 2000);
    domouseclick(200, 170, 2000);
    domouseclick(1245, 340, 2000);

    /* 1600X900
		domouseclick(1559, 10, 8000);
		domouseclick(1470, 220 , 2000);
		domouseclick(400, 240, 8000);
		domouseclick(1190, 440, 8000);
		domouseclick(1455, 10, 8000);
		domouseclick(25, 140, 2000);
		domouseclick(88, 233, 2000);
		domouseclick(302, 428, 2000);
		domouseclick(495, 462, 2000);
		//domouseclick(490, 435, 2000);
		domouseclick(203, 171, 2000);
		//SetCursorPos(1411, 338);
		domouseclick(1411, 338, 2000);
    */

	}
	return(TRUE);
}

CString CautooDlg::dogetclipboard()
{
	char* t_buffer = NULL;
	CString t_fromClipboard = _T("");
	HANDLE hData;
	if (OpenClipboard())
	{
		hData = GetClipboardData(CF_TEXT);
		t_buffer = (char*)GlobalLock(hData);
		t_fromClipboard.Empty();
		t_fromClipboard = CString(t_buffer);
		GlobalUnlock(hData);
		CloseClipboard();
		//MessageBox(fromClipboard);
	}
	return(t_fromClipboard);
}

void CautooDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch (nIDEvent)
	{
	case TIMER_1s:
		m_currentdate = dogetdate();
		if (m_setact)
		{
			doact();
		}
		break;
	default:
		break;
	}
	CDialogEx::OnTimer(nIDEvent);
}

CString CautooDlg::dogetdate()
{
	CString t_cs = _T("");
	SYSTEMTIME	t_sysTime;
	GetLocalTime(&t_sysTime);
	t_cs.Format(_T("%04ld%02ld%02ld%02ld%02ld%02ld%03ld"), t_sysTime.wYear, t_sysTime.wMonth, t_sysTime.wDay, t_sysTime.wHour, t_sysTime.wMinute, t_sysTime.wSecond, t_sysTime.wMilliseconds);
	return(t_cs);
}