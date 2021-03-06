#pragma once

#include "resource.h"
#include "inc/vga/Cfg.h"

// CVgaLedDlg dialog



class CLedDlg : public CUiDlg
{ 
	#pragma region controls ID define

	typedef enum _LED_STC_ID
	{
		STC_LED_LEDCAPTION,
		STC_LED_LEDEFFECTS,
		STC_LED_STYLE,
		STC_LED_SPEED,
		STC_LED_VARIATION,
		STC_LED_BRIGHTNESS,
		STC_LED_SYNCDEVICE,
		STC_LED_AORUSLOGO,

		STC_LED_STYLE_COMBINE,
		STC_LED_SPEED_COMBINE,
		STC_LED_VARIATION_COMBINE,
		STC_LED_HIDE_LEDCOLR,
		STC_LED_NUM
	};

	typedef enum _LED_BTN_ID
	{
        BTN_LED_EFFECTS,
		BTN_LED_COLOR_1,
		BTN_LED_COLOR_2,
		BTN_LED_COLOR_3,
		BTN_LED_COLOR_4,
		BTN_LED_COLOR_5,
		BTN_LED_COLOR_6,
		BTN_LED_COLOR_7,
		BTN_LED_COLOR_8,
		BTN_LED_COLOR_9,
		BTN_LED_COLOR_R,  // random color
		BTN_LED_SYNCDEVICE,
		BTN_LED_DEFAULT,
		BTN_LED_APPLY,
		BTN_LED_ADDPROFILE,
		BTN_LED_EDITPROFILE,
		BTN_LED_DELPROFILE,
		BTN_LED_NUM
	};

	typedef enum _LED_EDIT_ID
	{
		EDIT_LED_R,
		EDIT_LED_G,
		EDIT_LED_B,
		EDIT_LED_CODE,
		EDIT_LED_PROFILE,
		EDIT_LED_NUM,
	};

	typedef enum _LED_SLIDER_ID
	{
		SLIDER_LED_SPEED,
		SLIDER_LED_BRGIHTNESS,
		SLIDER_LED_MulitBRGIHTNESS,
		SLIDER_LED_RGB,
		SLIDER_LED_NUM,
	};
	typedef enum _VGALED_COMBOX_ID
	{
		COMBOX_LED_STYLE,
		COMBOX_LED_VARIATION,
		COMBOX_LED_PROFILE,
		COMBOX_LED_NUM,
	};

	#pragma endregion

	DECLARE_DYNAMIC(CLedDlg)

public:


	CLedDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CLedDlg();

	void InitProfile();
	void InitState();
	void InitializeUI();
	void Initialize(int nDevice, bool bHasProfile=false);
	LED_SETTING GetLedCfg(int nCard, int nProfile) { return m_ledProfiles[nCard][nProfile]; }
	void ChangeCurProfile(int iProfile) {m_nProSel = iProfile;}
	
	int GetProfileNum() {return m_nProfiles;}
// Dialog Data
	enum { IDD = IDD_VGA_LED_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg LRESULT OnUiButtonClicked(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnUiSliderMoved(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnUiSliderMoving(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnUiComboBoxSelChanged(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnUiEditChanged(WPARAM wParam, LPARAM lParam);

	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);

	DECLARE_MESSAGE_MAP()

protected:
	void Ui();
	void UiMain();
	void OnOK() { } 
	void EditRGBChange();

	void SyncAorusLedBtnClr(COLORREF clr);	// Sync color to LED icon on AORUS's main UI.

	int GetCardSel();

	void OnColor(COLORREF clr);
	void UpdateUI(LED_SETTING led);
	void EnableControls(DWORD dwMask,bool bShowVariation, bool bShowMultiBritness=true);

	bool IsSyncLed();
	void SetSyncLed(bool bSyncLed);
	void TranToSyncStyle(LED_SETTING &led);
	bool IsSyncLedSupported();

	void OnApply();
	void OnDefault();
	void SyncLedSetting(LED_SETTING& led, bool bSave); // sync led setting between different devices.
	void ApplyLedSetting(int nCard, LED_SETTING& led, bool bLedSync, bool bSave /*true: save, false: only store in memory temperialy*/);
	void SetLogoLedTimer(int nTimerId, int nTimerClk);

private:
    CUiStatic  m_stc[STC_LED_NUM];
	CUiButton m_btn[BTN_LED_NUM];
    CUiEdit	m_edit[EDIT_LED_NUM];
	CUiSliderCtrl	m_slider[SLIDER_LED_NUM];
	CUiMulitSliderCtrl m_Brightness;
	CUiComboBox m_combobox[COMBOX_LED_NUM];

	int m_nDevice;
	CArray<LED_STYLE> m_Styles;			// styles supported.
	CArray<LED_STYLE> m_Monitors;		// Monitor items, if has.
	int m_nShiftTop;
	bool m_bHasProfile;

	int m_nProSel;
	int m_nProfiles; // How many profiles here now.
	LED_SETTING m_ledProfiles[GVDISP_CARD_MAXNUM][LED_PROFILE_CONT];

	// variables used in OnTimer() to control led effects.

	int  m_nCircleClr;
	int  m_nBreathBright;
	bool m_bBreathDown;
	bool m_bFlashOff;
	int  m_nDualFlashCnt;
	int  m_nBreathClrBright;
	bool m_bBreathClrDown;
	int  m_nBreathClrIdx;
	int  m_nFlashClrClr; 
	bool m_bFlashClrOff;
	int m_nDualFlashClrCnt;
	int m_nDualFlashClrClr;
};