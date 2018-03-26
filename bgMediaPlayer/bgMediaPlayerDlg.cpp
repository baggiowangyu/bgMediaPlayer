
// bgMediaPlayerDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "bgMediaPlayer.h"
#include "bgMediaPlayerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CbgMediaPlayerDlg 对话框




CbgMediaPlayerDlg::CbgMediaPlayerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CbgMediaPlayerDlg::IDD, pParent)
	, player_(NULL)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CbgMediaPlayerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_H_COUNT, m_cHCount);
	DDX_Control(pDX, IDC_COMBO_V_COUNT, m_cVCount);
	DDX_Control(pDX, IDC_EDIT_URL, m_cUrl);
	DDX_Control(pDX, IDC_CHECK_SOUND_SWITCH, m_cSoundSwitch);
	DDX_Control(pDX, IDC_EDIT_VOLUMN, m_cVolumn);
	DDX_Control(pDX, IDC_SLIDER_VOLUMN, m_cVolumnSlider);
	DDX_Control(pDX, IDC_EDIT_STATE, m_cState);
}

BEGIN_MESSAGE_MAP(CbgMediaPlayerDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTN_INIT, &CbgMediaPlayerDlg::OnBnClickedBtnInit)
	ON_BN_CLICKED(IDC_BTN_PLAY, &CbgMediaPlayerDlg::OnBnClickedBtnPlay)
	ON_BN_CLICKED(IDC_BTN_STOP, &CbgMediaPlayerDlg::OnBnClickedBtnStop)
	ON_BN_CLICKED(IDC_BTN_PAUSE, &CbgMediaPlayerDlg::OnBnClickedBtnPause)
	ON_BN_CLICKED(IDC_BTN_RESUME, &CbgMediaPlayerDlg::OnBnClickedBtnResume)
	ON_BN_CLICKED(IDC_BTN_CAPTURESCREEN, &CbgMediaPlayerDlg::OnBnClickedBtnCapturescreen)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CbgMediaPlayerDlg 消息处理程序

BOOL CbgMediaPlayerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_cHCount.AddString(_T("1"));
	m_cHCount.AddString(_T("2"));
	m_cHCount.AddString(_T("3"));
	m_cHCount.AddString(_T("4"));
	m_cHCount.AddString(_T("5"));
	m_cHCount.AddString(_T("6"));
	m_cHCount.AddString(_T("7"));
	m_cHCount.AddString(_T("8"));
	m_cHCount.AddString(_T("9"));
	m_cHCount.AddString(_T("10"));
	m_cHCount.SetCurSel(0);

	m_cVCount.AddString(_T("1"));
	m_cVCount.AddString(_T("2"));
	m_cVCount.AddString(_T("3"));
	m_cVCount.AddString(_T("4"));
	m_cVCount.AddString(_T("5"));
	m_cVCount.AddString(_T("6"));
	m_cVCount.AddString(_T("7"));
	m_cVCount.AddString(_T("8"));
	m_cVCount.AddString(_T("9"));
	m_cVCount.AddString(_T("10"));
	m_cVCount.SetCurSel(0);

	m_cVolumn.SetWindowText(_T("0"));

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CbgMediaPlayerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CbgMediaPlayerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CbgMediaPlayerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CbgMediaPlayerDlg::OnDestroy()
{
	CDialog::OnDestroy();
}



void CbgMediaPlayerDlg::OnBnClickedBtnInit()
{
	CString str_h_count;
	CString str_v_count;

	m_cHCount.GetWindowText(str_h_count);
	m_cVCount.GetWindowText(str_v_count);

	int h_count = _ttoi(str_h_count.GetBuffer(0));
	int v_count = _ttoi(str_v_count.GetBuffer(0));

	CWnd *screen_pointer = GetDlgItem(IDC_STATIC_SCREEN);

	if (player_ == NULL)
		player_ = new bgMediaPlayer(screen_pointer);

	int errCode = player_->Initialize(h_count, v_count);
}

void CbgMediaPlayerDlg::OnBnClickedBtnPlay()
{
	CString url;
	m_cUrl.GetWindowText(url);

	USES_CONVERSION;
	int errCode = player_->Play(T2A(url.GetBuffer(0)));
}

void CbgMediaPlayerDlg::OnBnClickedBtnStop()
{
	int errCode = player_->Stop();
}

void CbgMediaPlayerDlg::OnBnClickedBtnPause()
{
	int errCode = player_->Pause();
}

void CbgMediaPlayerDlg::OnBnClickedBtnResume()
{
	int errCode = player_->Resume();
}

void CbgMediaPlayerDlg::OnBnClickedBtnCapturescreen()
{
	//int errCode = player_->CaptureScreen();
}


