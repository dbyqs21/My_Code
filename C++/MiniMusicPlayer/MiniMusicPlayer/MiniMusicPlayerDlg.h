
// MiniMusicPlayerDlg.h : ͷ�ļ�
//

#pragma once
#include <mmsystem.h>
#include <digitalv.h>
#include "afxcmn.h"
#pragma comment(lib,"winmm.lib")

// CMiniMusicPlayerDlg �Ի���
class CMiniMusicPlayerDlg : public CDialogEx
{
private:
	MCIDEVICEID m_IDDevices;  //�������������Ӧ�ó�������
// ����
public:
	CMiniMusicPlayerDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MINIMUSICPLAYER_DIALOG };

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
	afx_msg void OnBnClickedButOpen();
	afx_msg void OnBnClickedButPlay();
	afx_msg void OnBnClickedButPause();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnCustomdrawSliderVolume(NMHDR *pNMHDR, LRESULT *pResult);
	UINT m_vol;
	CSliderCtrl m_slider;
	CString m_sMusicName;
	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg void OnBnClickedButClose();
	afx_msg void OnBnClickedButStop();
};
