
// bgMediaPlayerDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "..\bgMediaPlayerLib\bgMediaPlayerLib.h"


// CbgMediaPlayerDlg 对话框
class CbgMediaPlayerDlg : public CDialog
{
// 构造
public:
	CbgMediaPlayerDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_BGMEDIAPLAYER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
