
// MiniMusicPlayerDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MiniMusicPlayer.h"
#include "MiniMusicPlayerDlg.h"
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


// CMiniMusicPlayerDlg �Ի���



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


// CMiniMusicPlayerDlg ��Ϣ�������

BOOL CMiniMusicPlayerDlg::OnInitDialog()
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	ShowWindow(SW_MINIMIZE);

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	GetDlgItem(IDC_BUT_PLAY)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUT_PAUSE)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUT_STOP)->EnableWindow(FALSE);

	m_slider.SetRange(0, 1000);
	m_slider.SetPos(500);
	m_vol = 50;
	UpdateData(FALSE);


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMiniMusicPlayerDlg::OnPaint()
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
HCURSOR CMiniMusicPlayerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//���ļ�
void CMiniMusicPlayerDlg::OnBnClickedButOpen()
{
	//��ϵͳ���ļ�ѡ��Ի���
	CFileDialog fileDlg(TRUE,   //TRUE���ļ���FALSE���Ϊ
		NULL,    //Ĭ�ϵ���չ��  .txt .Mp3 .exe .dat
		NULL,    //Ĭ���ļ���
		OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST,    //�ļ�������ڣ��ļ�·���������
		L"MP3�ļ�(*.mp3)|*.mp3|WMA�ļ�(*.wma)|*.wma|WAV�ļ�(*.wav)|*.wav|�����ļ�(*.*)|*.*||"     // ����
		);
	fileDlg.DoModal();

	//��һ�׸���
	//MCIDEVICEID IDDevices;  //�������������Ӧ�ó�������
	mciSendCommand(m_IDDevices, MCI_CLOSE, 0, 0);  //��ֹ��δ��ļ������¶������ͬʱ����

	//��ȡ������·��
	CString sMusicPathName = fileDlg.GetPathName();
	m_sMusicName = fileDlg.GetFileName();
	//MessageBox(m_sMusicName);

	//MCI : media control interface
	//windows ����������ý���豸�ĸ߲�����ӿ�
	MCI_OPEN_PARMS mciOpenParms;   //���豸
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	MCI_PLAY_PARMS mciPlayParms;   //�����豸
	mciPlayParms.dwCallback = NULL; 
	mciPlayParms.dwFrom = 0;  //��0��ʼ����
	
	//���Ÿ���
	mciSendCommand(m_IDDevices, MCI_PLAY, MCI_FROM | MCI_NOTIFY, (DWORD)(PVOID)&mciPlayParms);

	//CPaintDC DC(this); // ���ڻ��Ƶ��豸������
	//////��ʾ��������
	//DC.SetTextColor(RGB(0, 255, 205));
	//DC.TextOutW(20, 50, CMiniMusicPlayerDlg::m_sMusicName);


	GetDlgItem(IDC_BUT_PLAY)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUT_PAUSE)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUT_STOP)->EnableWindow(TRUE);
}


void CMiniMusicPlayerDlg::OnBnClickedButPause()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString str;
	GetDlgItemText(IDC_BUT_PAUSE,str);
	if (str == L"��ͣ")
	{
		mciSendCommand(m_IDDevices, MCI_PAUSE, 0, 0);
		SetDlgItemText(IDC_BUT_PAUSE, L"����");
	}
	else
	{
		mciSendCommand(m_IDDevices, MCI_RESUME, 0, 0);
		SetDlgItemText(IDC_BUT_PAUSE, L"��ͣ");
	}

	
}


void CMiniMusicPlayerDlg::OnBnClickedButStop()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	mciSendCommand(m_IDDevices, MCI_STOP, 0, 0);
	mciSendCommand(m_IDDevices, MCI_CLOSE, 0, 0);

	GetDlgItem(IDC_BUT_PLAY)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUT_PAUSE)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUT_STOP)->EnableWindow(FALSE);
}

//�Ի���ı�����ɫ
BOOL CMiniMusicPlayerDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	//return CDialogEx::OnEraseBkgnd(pDC);
	CRect rect;
	GetClientRect(&rect);
	rect.bottom = 20;
	pDC->FillSolidRect(&rect, RGB(0, 100, 250));

	CRect rectClient;
	GetClientRect(&rectClient);
	rectClient.top = 20;
	pDC->FillSolidRect(&rectClient, RGB(0, 200, 250));

	//����
	pDC->SetBkColor(RGB(0, 100, 250));
	pDC->SetTextColor(RGB(255, 255, 255));

	CFont font;
	font.CreatePointFont(100, L"����");
	pDC->SelectObject(font);
	pDC->TextOutW(0, 0, L"MiniMusicPlayer");

	

	return TRUE;

}


void CMiniMusicPlayerDlg::OnCustomdrawSliderVolume(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
	// �϶�����
	UINT nHitTest = CDialogEx::OnNcHitTest(point);

	if (nHitTest == HTCLIENT)  //�ͻ���
	{
		nHitTest = HTCAPTION;  //������
	}

	return nHitTest;
}






void CMiniMusicPlayerDlg::OnBnClickedButClose()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	OnBnClickedButStop();
	CDialogEx::OnOK();
}


