#pragma once

#include "resource.h"
#include "inc/vga/Cfg.h"

// CVgaLedDlg dialog

class CKBLedRippleDlg : public CUiDlg
{ 
	typedef enum {
		STC_KBLEDS4_BRIGHTNESS,
		STC_KBLEDS4_SPEED,
		STC_KBLEDS4_COLORBG,
		STC_KBLEDS4_NUM
	};

	typedef enum {
		BTN_KBLEDS4_COLOR_1,
		BTN_KBLEDS4_COLOR_2,
		BTN_KBLEDS4_COLOR_3,
		BTN_KBLEDS4_COLOR_4,
		BTN_KBLEDS4_COLOR_5,
		BTN_KBLEDS4_COLOR_6,
		BTN_KBLEDS4_COLOR_7,
		BTN_KBLEDS4_COLOR_8,
		BTN_KBLEDS4_COLOR_9,
		BTN_KBLEDS4_NUM
	};

	typedef enum {
		EDIT_KBLEDS4_R,
		EDIT_KBLEDS4_G,
		EDIT_KBLEDS4_B,
		EDIT_KBLEDS4_NUM,
	};

	typedef enum {
		SLIDER_KBLEDS4_SPEED,
		SLIDER_KBLEDS4_BRGIHTNESS,
		SLIDER_KBLEDS4_RGB,
		SLIDER_KBLEDS4_NUM,
	};

	DECLARE_DYNAMIC(CKBLedRippleDlg)

public:
	CKBLedRippleDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CKBLedRippleDlg();


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
    CUiStatic m_stc[STC_KBLEDS4_NUM];
	CUiButton m_btn[BTN_KBLEDS4_NUM];
    CUiEdit	m_edit[EDIT_KBLEDS4_NUM];
	CUiSliderCtrl m_slider[SLIDER_KBLEDS4_NUM];
	CUiMulitSliderCtrl m_Brightness;

	static int s_nWords;
	static LANG_WORD s_Words[48];
};