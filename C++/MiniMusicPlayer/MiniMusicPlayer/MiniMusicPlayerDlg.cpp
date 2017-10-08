
// MiniMusicPlayerDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MiniMusicPlayer.h"
#include "MiniMusicPlayerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
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

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMiniMusicPlayerDlg 对话框



CMiniMusicPlayerDlg::CMiniMusicPlayerDlg(CWnd* pParent /*=NULL*/)
: CDialogEx(CMiniMusicPlayerDlg::IDD, pParent)
, m_vol(500)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMiniMusicPlayerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_VOLUME, m_vol);
	DDX_Control(pDX, IDC_SLIDER_VOLUME, m_slider);
}

BEGIN_MESSAGE_MAP(CMiniMusicPlayerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUT_OPEN, &CMiniMusicPlayerDlg::OnBnClickedButOpen)
	ON_BN_CLICKED(IDC_BUT_PLAY, &CMiniMusicPlayerDlg::OnBnClickedButPlay)
	ON_BN_CLICKED(IDC_BUT_PAUSE, &CMiniMusicPlayerDlg::OnBnClickedButPause)
	ON_WM_ERASEBKGND()
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_VOLUME, &CMiniMusicPlayerDlg::OnCustomdrawSliderVolume)
	ON_WM_NCHITTEST()
	ON_WM_CLOSE()
	
	ON_BN_CLICKED(IDC_BUT_CLOSE, &CMiniMusicPlayerDlg::OnBnClickedButClose)
	ON_BN_CLICKED(IDC_BUT_STOP, &CMiniMusicPlayerDlg::OnBnClickedButStop)
END_MESSAGE_MAP()


// CMiniMusicPlayerDlg 消息处理程序

BOOL CMiniMusicPlayerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	ShowWindow(SW_MINIMIZE);

	// TODO:  在此添加额外的初始化代码
	GetDlgItem(IDC_BUT_PLAY)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUT_PAUSE)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUT_STOP)->EnableWindow(FALSE);

	m_slider.SetRange(0, 1000);
	m_slider.SetPos(500);
	m_vol = 50;
	UpdateData(FALSE);


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMiniMusicPlayerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMiniMusicPlayerDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMiniMusicPlayerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//打开文件
void CMiniMusicPlayerDlg::OnBnClickedButOpen()
{
	//打开系统的文件选择对话框
	CFileDialog fileDlg(TRUE,   //TRUE打开文件，FALSE另存为
		NULL,    //默认的扩展名  .txt .Mp3 .exe .dat
		NULL,    //默认文件名
		OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST,    //文件必须存在，文件路径必须存在
		L"MP3文件(*.mp3)|*.mp3|WMA文件(*.wma)|*.wma|WAV文件(*.wav)|*.wav|所有文件(*.*)|*.*||"     // 过滤
		);
	fileDlg.DoModal();

	//打开一首歌曲
	//MCIDEVICEID IDDevices;  //用来保存歌曲在应用程序里面
	mciSendCommand(m_IDDevices, MCI_CLOSE, 0, 0);  //防止多次打开文件，导致多个歌曲同时播放

	//获取歌曲的路径
	CString sMusicPathName = fileDlg.GetPathName();
	m_sMusicName = fileDlg.GetFileName();
	//MessageBox(m_sMusicName);

	//MCI : media control interface
	//windows 中用来控制媒体设备的高层命令接口
	MCI_OPEN_PARMS mciOpenParms;   //打开设备
	mciOpenParms.lpstrElementName = sMusicPathName;
	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_WAIT, (DWORD)(PVOID)&mciOpenParms);

	m_IDDevices = mciOpenParms.wDeviceID;
	
	GetDlgItem(IDC_BUT_PLAY)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUT_PAUSE)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUT_STOP)->EnableWindow(FALSE);

	OnBnClickedButPlay();

}


void CMiniMusicPlayerDlg::OnBnClickedButPlay()
{
	// TODO:  在此添加控件通知处理程序代码
	MCI_PLAY_PARMS mciPlayParms;   //播放设备
	mciPlayParms.dwCallback = NULL; 
	mciPlayParms.dwFrom = 0;  //从0开始播放
	
	//播放歌曲
	mciSendCommand(m_IDDevices, MCI_PLAY, MCI_FROM | MCI_NOTIFY, (DWORD)(PVOID)&mciPlayParms);

	//CPaintDC DC(this); // 用于绘制的设备上下文
	//////显示歌曲名称
	//DC.SetTextColor(RGB(0, 255, 205));
	//DC.TextOutW(20, 50, CMiniMusicPlayerDlg::m_sMusicName);


	GetDlgItem(IDC_BUT_PLAY)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUT_PAUSE)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUT_STOP)->EnableWindow(TRUE);
}


void CMiniMusicPlayerDlg::OnBnClickedButPause()
{
	// TODO:  在此添加控件通知处理程序代码
	CString str;
	GetDlgItemText(IDC_BUT_PAUSE,str);
	if (str == L"暂停")
	{
		mciSendCommand(m_IDDevices, MCI_PAUSE, 0, 0);
		SetDlgItemText(IDC_BUT_PAUSE, L"继续");
	}
	else
	{
		mciSendCommand(m_IDDevices, MCI_RESUME, 0, 0);
		SetDlgItemText(IDC_BUT_PAUSE, L"暂停");
	}

	
}


void CMiniMusicPlayerDlg::OnBnClickedButStop()
{
	// TODO:  在此添加控件通知处理程序代码
	mciSendCommand(m_IDDevices, MCI_STOP, 0, 0);
	mciSendCommand(m_IDDevices, MCI_CLOSE, 0, 0);

	GetDlgItem(IDC_BUT_PLAY)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUT_PAUSE)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUT_STOP)->EnableWindow(FALSE);
}

//对话框的背景颜色
BOOL CMiniMusicPlayerDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	//return CDialogEx::OnEraseBkgnd(pDC);
	CRect rect;
	GetClientRect(&rect);
	rect.bottom = 20;
	pDC->FillSolidRect(&rect, RGB(0, 100, 250));

	CRect rectClient;
	GetClientRect(&rectClient);
	rectClient.top = 20;
	pDC->FillSolidRect(&rectClient, RGB(0, 200, 250));

	//字体
	pDC->SetBkColor(RGB(0, 100, 250));
	pDC->SetTextColor(RGB(255, 255, 255));

	CFont font;
	font.CreatePointFont(100, L"宋体");
	pDC->SelectObject(font);
	pDC->TextOutW(0, 0, L"MiniMusicPlayer");

	

	return TRUE;

}


void CMiniMusicPlayerDlg::OnCustomdrawSliderVolume(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码
	MCI_DGV_SETVIDEO_PARMS mciSetVolume;
	mciSetVolume.dwCallback = NULL;
	mciSetVolume.dwItem = MCI_DGV_SETAUDIO_VOLUME;
	mciSetVolume.dwValue = m_slider.GetPos();

	m_vol = m_slider.GetPos();
	UpdateData(FALSE);

	mciSendCommand(m_IDDevices, MCI_SETAUDIO, MCI_DGV_SETAUDIO_VALUE | MCI_DGV_SETAUDIO_ITEM, (DWORD)(PVOID)&mciSetVolume);
	*pResult = 0;
}


LRESULT CMiniMusicPlayerDlg::OnNcHitTest(CPoint point)
{
	// 拖动窗口
	UINT nHitTest = CDialogEx::OnNcHitTest(point);

	if (nHitTest == HTCLIENT)  //客户端
	{
		nHitTest = HTCAPTION;  //标题栏
	}

	return nHitTest;
}






void CMiniMusicPlayerDlg::OnBnClickedButClose()
{
	// TODO:  在此添加控件通知处理程序代码
	OnBnClickedButStop();
	CDialogEx::OnOK();
}


