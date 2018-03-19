
// bgMediaPlayerDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "..\bgMediaPlayerLib\bgMediaPlayerLib.h"


// CbgMediaPlayerDlg �Ի���
class CbgMediaPlayerDlg : public CDialog
{
// ����
public:
	CbgMediaPlayerDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_BGMEDIAPLAYER_DIALOG };

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
	CComboBox m_cHCount;
	CComboBox m_cVCount;
	CEdit m_cUrl;
	CButton m_cSoundSwitch;
	CEdit m_cVolumn;
	CSliderCtrl m_cVolumnSlider;
	CEdit m_cState;

public:
	afx_msg void OnBnClickedBtnInit();
	afx_msg void OnBnClickedBtnPlay();
	afx_msg void OnBnClickedBtnStop();
	afx_msg void OnBnClickedBtnPause();
	afx_msg void OnBnClickedBtnResume();
	afx_msg void OnBnClickedBtnCapturescreen();

private:
	bgMediaPlayer *player_;
};
