
// autooDlg.h : header file
//

#pragma once
#define TIMER_1s 1
#define TIMER_60s 60

// CautooDlg dialog
class CautooDlg : public CDialogEx
{
	// Construction
public:
	CautooDlg(CWnd* pParent = NULL);	// standard constructor

										// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AUTOO_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


														// Implementation
private:
	int doanalzyoperate();
	int doact();
	CString m_currentdate;
	CString dogetclipboard();
	CString dogetdate();
	int m_setact;
	int m_starttime;
	int domouseclick(int v_x,int v_y, int v_sleepms);
  int domouseclicktest(int v_x, int v_y, int v_sleepms);

protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	CString m_log;

public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	CString m_position;
	CString m_operate;
	afx_msg void OnClickedAct();
	afx_msg void OnClickedLog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
  int m_workMode;
  int maxWin();
  
};
