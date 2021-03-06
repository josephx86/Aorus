#pragma once

#include "resource.h"
#include "inc/vga/Cfg.h"

// CVgaLedDlg dialog

class CKBLedWaveDlg : public CUiDlg
{ 
	typedef enum {
		STC_KBLEDS6_BRIGHTNESS,
		STC_KBLEDS6_SPEED,
		STC_KBLEDS6_COLORBG,
		STC_KBLEDS6_NUM
	};

	typedef enum {
		BTN_KBLEDS6_COLOR_1,
		BTN_KBLEDS6_COLOR_2,
		BTN_KBLEDS6_COLOR_3,
		BTN_KBLEDS6_COLOR_4,
		BTN_KBLEDS6_COLOR_5,
		BTN_KBLEDS6_COLOR_6,
		BTN_KBLEDS6_COLOR_7,
		BTN_KBLEDS6_COLOR_8,
		BTN_KBLEDS6_COLOR_9,
		BTN_KBLEDS6_NUM
	};

	typedef enum {
		EDIT_KBLEDS6_R,
		EDIT_KBLEDS6_G,
		EDIT_KBLEDS6_B,
		EDIT_KBLEDS6_NUM,
	};

	typedef enum {
		SLIDER_KBLEDS6_SPEED,
		SLIDER_KBLEDS6_BRGIHTNESS,
		SLIDER_KBLEDS6_RGB,
		SLIDER_KBLEDS6_NUM,
	};

	DECLARE_DYNAMIC(CKBLedWaveDlg)

public:
	CKBLedWaveDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CKBLedWaveDlg();


// Dialog Data
	enum { IDD = IDD_VGA_LED_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg LRESULT OnUiButtonClicked(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnUiSliderMoved(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnUiSliderMoving(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnUiEditChanged(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()

protected:
	void Ui();
	void UiMain();
	void OnOK() { } 
	void EditRGBChange();

	void OnColor(COLORREF clr);

private:
    CUiStatic m_stc[STC_KBLEDS6_NUM];
	CUiButton m_btn[BTN_KBLEDS6_NUM];
    CUiEdit	m_edit[EDIT_KBLEDS6_NUM];
	CUiSliderCtrl m_slider[SLIDER_KBLEDS6_NUM];

	static int s_nWords;
	static LANG_WORD s_Words[48];
};