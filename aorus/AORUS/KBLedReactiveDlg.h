#pragma once

#include "resource.h"
#include "inc/vga/Cfg.h"

// CVgaLedDlg dialog

class CKBLedReactiveDlg : public CUiDlg
{ 
	typedef enum {
		STC_KBLEDS3_BRIGHTNESS,
		STC_KBLEDS3_SPEED,
		STC_KBLEDS3_DURATION,
		STC_KBLEDS3_COLORBG,
		STC_KBLEDS3_NUM
	};

	typedef enum {
		BTN_KBLEDS3_COLOR_1,
		BTN_KBLEDS3_COLOR_2,
		BTN_KBLEDS3_COLOR_3,
		BTN_KBLEDS3_COLOR_4,
		BTN_KBLEDS3_COLOR_5,
		BTN_KBLEDS3_COLOR_6,
		BTN_KBLEDS3_COLOR_7,
		BTN_KBLEDS3_COLOR_8,
		BTN_KBLEDS3_COLOR_9,
		BTN_KBLEDS3_NUM
	};

	typedef enum {
		EDIT_KBLEDS3_R,
		EDIT_KBLEDS3_G,
		EDIT_KBLEDS3_B,
		EDIT_KBLEDS3_NUM,
	};

	typedef enum {
		SLIDER_KBLEDS3_SPEED,
		SLIDER_KBLEDS3_BRGIHTNESS,
		SLIDER_KBLEDS3_DURATION,
		SLIDER_KBLEDS3_RGB,
		SLIDER_KBLEDS3_NUM,
	};

	DECLARE_DYNAMIC(CKBLedReactiveDlg)

public:
	CKBLedReactiveDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CKBLedReactiveDlg();


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
    CUiStatic m_stc[STC_KBLEDS3_NUM];
	CUiButton m_btn[BTN_KBLEDS3_NUM];
    CUiEdit	m_edit[EDIT_KBLEDS3_NUM];
	CUiSliderCtrl m_slider[SLIDER_KBLEDS3_NUM];

	static int s_nWords;
	static LANG_WORD s_Words[48];
};