#pragma once

#include "resource.h"
#include "inc/vga/Cfg.h"

// CVgaLedDlg dialog

class CKBLedPulsingDlg : public CUiDlg
{ 
	typedef enum {
		STC_KBLEDS2_BRIGHTNESS,
		STC_KBLEDS2_SPEED,
		STC_KBLEDS2_COLORBG,
		STC_KBLEDS2_NUM
	};

	typedef enum {
		BTN_KBLEDS2_COLOR_1,
		BTN_KBLEDS2_COLOR_2,
		BTN_KBLEDS2_COLOR_3,
		BTN_KBLEDS2_COLOR_4,
		BTN_KBLEDS2_COLOR_5,
		BTN_KBLEDS2_COLOR_6,
		BTN_KBLEDS2_COLOR_7,
		BTN_KBLEDS2_COLOR_8,
		BTN_KBLEDS2_COLOR_9,
		BTN_KBLEDS2_NUM
	};

	typedef enum {
		EDIT_KBLEDS2_R,
		EDIT_KBLEDS2_G,
		EDIT_KBLEDS2_B,
		EDIT_KBLEDS2_NUM,
	};

	typedef enum {
		SLIDER_KBLEDS2_SPEED,
		SLIDER_KBLEDS2_BRGIHTNESS,
		SLIDER_KBLEDS2_RGB,
		SLIDER_KBLEDS2_NUM,
	};

	DECLARE_DYNAMIC(CKBLedPulsingDlg)

public:
	CKBLedPulsingDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CKBLedPulsingDlg();


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
    CUiStatic m_stc[STC_KBLEDS2_NUM];
	CUiButton m_btn[BTN_KBLEDS2_NUM];
    CUiEdit	m_edit[EDIT_KBLEDS2_NUM];
	CUiSliderCtrl m_slider[SLIDER_KBLEDS2_NUM];
	CUiPanelCtrl m_panelColor;

	static int s_nWords;
	static LANG_WORD s_Words[48];
};