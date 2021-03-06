// KBLedDlg.cpp : implementation file

#include "stdafx.h"
#include "AORUS.h"
#include "KBLedDlg.h"
#include "AORUSDlg.h"


#define LKEY_KBLED_LOCALL		0
#define LKEY_KBLED_LOCARROW		1
#define LKEY_KBLED_LOCWASD		2
#define LKEY_KBLED_LOCNUMPAD	3
#define LKEY_KBLED_LOCFNKEY		4
#define LKEY_KBLED_LOCUSERS		5

#define LKEY_KBLED_QTY			6

int CKBLedDlg::s_nWords = LKEY_KBLED_QTY;
LANG_WORD CKBLedDlg::s_Words[48] = 
{
	LANG_WORD(LKEY_KBLED_LOCALL,	_T("窒"),		_T("腢"),		_T("ALL")),
	LANG_WORD(LKEY_KBLED_LOCARROW,	_T("璋芛瑩"),	_T("源砃潬"),	_T("ARROW KEY")),
	LANG_WORD(LKEY_KBLED_LOCWASD,	_T("WASD"),		_T("WASD"),		_T("WASD")),
	LANG_WORD(LKEY_KBLED_LOCNUMPAD, _T("杅趼瑩"),	_T("趼潬"),	_T("NUMPAD")),
	LANG_WORD(LKEY_KBLED_LOCFNKEY,	_T("髡夔瑩"),	_T("髡夔潬"),	_T("FN KEY")),
	LANG_WORD(LKEY_KBLED_LOCUSERS,	_T("赻隅砱"),	_T("赻隅膽"),	_T("USER DEFINE")),
};

#define KEYs_107	107	// 107 Keys

CRect s_KeysAK700[KEYs_107] = {
	CRect(  7, 150,  25, 165),	//   lctrl    
	CRect( 35, 150,  53, 165),	//   lwin        
	CRect( 63, 150,  81, 165),	//   lalt
	CRect( 91, 150, 220, 165),	//   space  
	CRect(230, 150, 248, 165),	//   ralt 
	CRect(258, 150, 276, 165),	//   WinLock    
	CRect(286, 150, 304, 165),	//   fn        
	CRect(314, 150, 332, 165),	//   rctrl     
	CRect(346, 150, 360, 165),	//   left 
	CRect(368, 150, 382, 165),	//   down    
	CRect(390, 150, 404, 165),	//   right    
	CRect(418, 150, 454, 165),	//   num0  
	CRect(462, 150, 476, 165),	//   num.   
	CRect(484,  128, 498, 165),	//   num/enter

	CRect(  7,  128,  48, 143),	//   lshift    
	CRect( 57,  128,  71, 143),    //   z          
	CRect( 79,  128,  93, 143),    //   x         
	CRect( 101,  128,  115, 143),    //   c         
	CRect( 124,  128, 138, 143),	//   v          
	CRect(146,  128, 160, 143),	//   b         
	CRect(168,  128, 182, 143),	//   n        
	CRect(190,  128, 204, 143),	//   m       
	CRect(212,  128, 226, 143),	//   ,         
	CRect(234,  128, 248, 143),	//   .          
	CRect(256,  128, 270, 143),	//   /          
	CRect(278,  128, 332, 143),	//   rshift   
	CRect(368,  128, 382, 143),	//   up       
	CRect(418,  128, 432, 143),	//   num1  
	CRect(440,  128, 454, 143),	//   num2  
	CRect(462,  128, 476, 143),	//   num3  mark 

	CRect(  7,  106,  38,  121),    //   capslock
	CRect( 46,  106,  60,  121),	//   a         
	CRect( 68,  106,  82,  121),	//   s          
	CRect( 90,  106,  104,  121),	//   d         
	CRect( 112,  106,  126,  121),	//   f          
	CRect( 134,  106, 148,  121),	//   g         
	CRect(156,  106, 170,  121),	//   h         
	CRect(178,  106, 192,  121),    //   j          
	CRect(200,  106, 214,  121),    //   k         
	CRect(222,  106, 236,  121),    //   l          
	CRect(244,  106, 258,  121),    //   ;          
	CRect(268,  106, 282,  121),    //   '          
	CRect(290,  106, 332,  121),    //   enter   
	CRect(418,  106, 432,  121),	//   num4  
	CRect(440,  106, 454,  121),	//   num5  
	CRect(462,  106, 476,  121),	//   num6  
	CRect(484,  84, 498,  121),	//   num+  

	CRect(  7,  84,  32,  100),	//   tab      
	CRect( 42,  84,  56,  100),	//   q         
	CRect( 64,  84,  78,  100),    //   w         
	CRect( 86,  84,  100,  100),    //   e         
	CRect( 108,  84,  122,  100),    //   r          
	CRect( 130,  84, 144,  100),	//   t          
	CRect(152,  84, 166,  100),	//   y         
	CRect(174,  84, 188,  100),	//   u         
	CRect(196,  84, 210,  100),	//   i          
	CRect(218,  84, 232,  100),	//   o         
	CRect(240,  84, 254,  100),	//   p         
	CRect(262,  84, 276,  100),	//   [          
	CRect(284,  84, 298,  100),	//   ]          
	CRect(306,  84, 332,  100),	//   |          
	CRect(346,  84, 360,  100),	//   delete  
	CRect(368,  84, 382,  100),	//   end           
	CRect(390,  84, 404,  100),	//   pagedown
	CRect(418,  84, 432,  100),	//   num7  
	CRect(440,  84, 454,  100),	//   num8  
	CRect(462,  84, 476,  100),	//   num9 

	CRect(  7,  62,  22,  78),	//   ~         
	CRect( 30,  62,  44,  78),    //   1         
	CRect( 52,  62,  66,  78),    //   2         
	CRect( 74,  62,  88,  78),    //   3         
	CRect( 96,  62,  110,  78),    //   4         
	CRect( 118,  62,  132,  78),    //   5         
	CRect(140,  62, 154,  78),	//   6         
	CRect(162,  62, 176,  78),	//   7          
	CRect(184,  62, 198,  78),	//   8         
	CRect(206,  62, 220,  78),	//   9         
	CRect(228,  62, 242,  78),	//   0         
	CRect(250,  62, 264,  78),	//   -          
	CRect(272,  62, 286,  78),	//   =         
	CRect(294,  62, 332,  78),	//   backspace 
	CRect(346,  62, 360,  78),	//   insert   
	CRect(368,  62, 382,  78),	//   home  
	CRect(390,  62, 404,  78),	//   pageup     
	CRect(418,  62, 432,  78),	//   num          
	CRect(440,  62, 454,  78),	//   num/   
	CRect(462,  62, 476,  78),	//   num*   
	CRect(484,  62, 498,  78),	//   num-   

	CRect(  7,  38,  22,  52),	//   esc      
	CRect( 44,  38,  58,  52),	//   F1        
	CRect( 66,  38,  80,  52),	//   F2        
	CRect( 88,  38,  102,  52),    //   F3        
	CRect( 110,  38,  124,  52),    //   F4        
	CRect(140,  38, 154,  52),	//   F5        
	CRect(162,  38, 176,  52),	//   F6        
	CRect(184,  38, 198,  52),	//   F7        
	CRect(206,  38, 220,  52),	//   F8        
	CRect(251,  38, 265,  52),	//   F9        
	CRect(273,  38, 287,  52),	//   F10           
	CRect(295,  38, 309,  52),	//   F11           
	CRect(317,  38, 331,  52),	//   F12           
	CRect(346,  38, 360,  52),	//   PrintScreen     
	CRect(368,  38, 382,  52),	//   scrollLock  
	CRect(390,  38, 404,  52),	//   Pause  
	CRect(408,  33, 437,  60),	//   Logo    
	CRect(  0,   0,   0,   0),	//   /        
	CRect(  0,   0,   0,   0),	//   |        
};



// CKBLedDlg dialog

IMPLEMENT_DYNAMIC(CKBLedDlg, CUiDlg)

CKBLedDlg::CKBLedDlg(CWnd* pParent /*=NULL*/)
	: CUiDlg(CKBLedDlg::IDD, pParent)
{
	m_sCurFile = _T("");
	m_iAllType = 1;
	bSyncFlag = false;
}

CKBLedDlg::~CKBLedDlg()
{
}

void CKBLedDlg::DoDataExchange(CDataExchange* pDX)
{
	CUiDlg::DoDataExchange(pDX);
}

BOOL CKBLedDlg::OnInitDialog()
{
	CUiDlg::OnInitDialog();
	Ui();
	return true;
}

BEGIN_MESSAGE_MAP(CKBLedDlg, CUiDlg)
	ON_MESSAGE(WM_UI_BUTTON_CLICKED, OnUiButtonClicked)
	ON_MESSAGE(WM_UI_COMBOBOX_SELCHANGED, OnUiComboBoxSelChanged)
	ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()


// CKBLedDlg message handlers

void CKBLedDlg::Ui()
{
	UiMain();
}

void CKBLedDlg::UiMain()
{
	SetBkBitmap(IDB_LED_BGCOMMON, 0xff, CLR_TRPT); 

	UI_BTN btn[] = 
	{
	//	UI_BTN(this, BTN_KBLED_PROADD,  CRect(163,  23, 0, 0), &UIBTN_IMAGE(IDB_VGAPRO_ADDFILE, IDB_VGAPRO_ADDFILE, IDB_VGAPRO_ADDFILE, IDB_VGAPRO_ADDFILEOFF)),
		UI_BTN(this, BTN_KBLED_PROEDIT, CRect(183-10,  23, 0, 0), &UIBTN_IMAGE(IDB_VGAPRO_EDITON, IDB_VGAPRO_EDITON, IDB_VGAPRO_EDITON, IDB_VGAPRO_EDITOFF, IDB_VGAPRO_SAVEFILE, IDB_VGAPRO_SAVEFILE, IDB_VGAPRO_SAVEFILE, IDB_VGAPRO_SAVEFILEOFF, CLR_TRPT), NULL, BTN_CHECK),
	//	UI_BTN(this, BTN_KBLED_PRODEL,  CRect(203,  23, 0, 0), &UIBTN_IMAGE(IDB_VGAPRO_DELETEFILE, IDB_VGAPRO_DELETEFILE,	IDB_VGAPRO_DELETEFILE,	IDB_VGAPRO_DELETEFILEOFF)),
		UI_BTN(this, BTN_KBLED_DEFAULT, CRect(443, 269+20, 0, 0), &UIBTN_IMAGE(IDB_BTN_ON, IDB_BTN_ON, IDB_BTN_ON,   0,  0, 0, 0, 0, CLR_TRPT),&UIBTN_STRING(CLangX::Get(LANG_VGALED_DEFAULT),	CLR_WHITE, CLR_WHITE,CLR_WHITE,0,Font(11))),
		UI_BTN(this, BTN_KBLED_APPLY,   CRect(324, 269+20, 0, 0), &UIBTN_IMAGE(IDB_BTN_ON, IDB_BTN_ON, IDB_BTN_ON,   0,  0, 0, 0, 0, CLR_TRPT),&UIBTN_STRING(CLangX::Get(LANG_VGALED_APPLY),	CLR_WHITE, CLR_WHITE,CLR_WHITE,0,Font(11))),
		UI_BTN(this, BTN_KBLED_SYNCDEVICE, CRect(13, 328,  25, 340), &UIBTN_IMAGE(IDB_CHECKBOX_UNCHECK, IDB_CHECKBOX_UNCHECK, IDB_CHECKBOX_UNCHECK, IDB_CHECKBOX_UNCHECK, IDB_CHECKBOX_CHECKED, IDB_CHECKBOX_CHECKED, IDB_CHECKBOX_CHECKED, 0, CLR_TRPT), NULL, BTN_CHECK),
	};

	for (int i = BTN_KBLED_PROEDIT; i < BTN_KBLED_NUM; i++)
	{
		m_btn[i].CreateButton(btn[i]);
		m_btn[i].SetCursor(IDC_CUR_HAND);
	}

	m_stc[STC_KBLED_SYNCDEVICE].CreateStatic(UI_STATIC(this, STC_KBLED_SYNCDEVICE, CRect(31, 325, 300, 339), CLangX::Get(LANG_VGALED_SYNCLEDDEV), NULL, CLR_NONE));
	m_stc[STC_KBLED_SYNCDEVICE].ModifyCtrlStyle(ST_VCENTER,ST_LEFT);
	m_stc[STC_KBLED_SYNCDEVICE].SetFont(Font(11), CLR_GRAY);


	m_combobox[COMBOX_KBLED_PROFILE].Create(CRect(23, 25, 0, 0), this, COMBOX_KBLED_PROFILE);
	m_combobox[COMBOX_KBLED_PROFILE].SetComboBoxBitmap(IDB_VGALED_COMB_NORMAL, IDB_VGALED_COMB_NORMAL, IDB_VGALED_COMB_NORMAL, 0, CLR_WHITE);
	m_combobox[COMBOX_KBLED_PROFILE].SetFont(Font(11), CLR_WHITE);
	m_combobox[COMBOX_KBLED_PROFILE].SetCursor(IDC_CUR_HAND);
	m_combobox[COMBOX_KBLED_PROFILE].SetArrowWidth(20);
	m_combobox[COMBOX_KBLED_PROFILE].GetDropList()->SetFont(Font(11),CLR_WHITE);
	m_combobox[COMBOX_KBLED_PROFILE].GetDropList()->SetBkColor(RGB(0, 0, 0));
	m_combobox[COMBOX_KBLED_PROFILE].GetDropList()->SetHighlightBkColor(CLR_MAIN);
	m_combobox[COMBOX_KBLED_PROFILE].ModifyCtrlStyle(ST_RIGHT, ST_LEFT);

	for (int i = 0; i < 5; i++)
	{
		CString sValue;
		sValue.Format(_T("PROFILE %d"), i+1);
		m_combobox[COMBOX_KBLED_PROFILE].AddString(sValue, 0, CLR_MAIN);
	}
	m_combobox[COMBOX_KBLED_PROFILE].SetCurSel(0);


	m_edit.Create(WS_CHILD | WS_VISIBLE | WS_TABSTOP | ES_AUTOHSCROLL | ES_CENTER, CRect(23,  25, 153,  39), this, EDIT_KBLED_PROFILENAME);
	m_edit.SetFont(Font(9), CLR_WHITE);
	m_edit.SetBkColor(CLR_DARK);
	m_edit.ShowWindow(SW_HIDE);

	m_combobox[COMBOX_KBLED_SELKEYS].Create(CRect(23, 53, 0, 0), this, COMBOX_KBLED_SELKEYS);
	m_combobox[COMBOX_KBLED_SELKEYS].SetComboBoxBitmap(IDB_VGALED_COMB_NORMAL, IDB_VGALED_COMB_NORMAL, IDB_VGALED_COMB_NORMAL, 0, CLR_NONE);
	m_combobox[COMBOX_KBLED_SELKEYS].SetFont(Font(11), CLR_WHITE);
	m_combobox[COMBOX_KBLED_SELKEYS].SetCursor(IDC_CUR_HAND);
	m_combobox[COMBOX_KBLED_SELKEYS].SetArrowWidth(20);
	m_combobox[COMBOX_KBLED_SELKEYS].GetDropList()->SetFont(Font(11),CLR_WHITE);
	m_combobox[COMBOX_KBLED_SELKEYS].GetDropList()->SetBkColor(RGB(0, 0, 0));
	m_combobox[COMBOX_KBLED_SELKEYS].GetDropList()->SetHighlightBkColor(CLR_MAIN);
	m_combobox[COMBOX_KBLED_SELKEYS].ModifyCtrlStyle(ST_RIGHT, ST_LEFT);

	m_combobox[COMBOX_KBLED_SELKEYS].AddString(CLangX::Get(s_Words, s_nWords, LKEY_KBLED_LOCALL),	0, CLR_WHITE);
	m_combobox[COMBOX_KBLED_SELKEYS].AddString(CLangX::Get(s_Words, s_nWords, LKEY_KBLED_LOCARROW), 0, CLR_WHITE);
	m_combobox[COMBOX_KBLED_SELKEYS].AddString(CLangX::Get(s_Words, s_nWords, LKEY_KBLED_LOCWASD),	0, CLR_WHITE);
	m_combobox[COMBOX_KBLED_SELKEYS].AddString(CLangX::Get(s_Words, s_nWords, LKEY_KBLED_LOCNUMPAD),0, CLR_WHITE);
	m_combobox[COMBOX_KBLED_SELKEYS].AddString(CLangX::Get(s_Words, s_nWords, LKEY_KBLED_LOCFNKEY), 0, CLR_WHITE);
	m_combobox[COMBOX_KBLED_SELKEYS].AddString(CLangX::Get(s_Words, s_nWords, LKEY_KBLED_LOCUSERS), 0, CLR_WHITE);
	m_combobox[COMBOX_KBLED_SELKEYS].SetCurSel(0);

	m_LedStyleDlg.Create(IDD_VGA_MONITORING, GetDesktopWindow());

	m_nKeys = 104; // Default: 104 Keys
	m_KB.CreateKeyboard(UI_KEYBOARD(this, 1, CRect(70, 65, 0, 0), IDB_PAN_KB104_OFF, IDB_PAN_KB104_ON, CLR_MAIN, CLR_TRPT));//130 90
	for (int i = 0; i < KEYs_107; i++)
	{
		m_KB.AddItem(&UIKB_RECT(i, s_KeysAK700[i]));
		m_KB.SetItemStatus(i, true);
	}
	//m_KB.Enable(false);

	// Petter Lee 2017/6/18 need to be assign
	m_nProfileSel = 0;
	CXK700Cmd::ConnectXK700();
	SetProfile(m_nProfileSel);
}


bool CKBLedDlg::IsAllKeysSelected()
{
	int items[200];
	int nCount = 200;
	m_KB.GetAllSelectItem(items, nCount);
	return nCount >= 105; // Include LOGO Key
}


LRESULT CKBLedDlg::OnUiButtonClicked(WPARAM wParam, LPARAM lParam)
{
	
	LED_SETTING led = m_kbProfile[0][m_nProfileSel];

	switch(wParam)
	{
//	case BTN_KBLED_PROADD: break;
	case BTN_KBLED_PROEDIT: 
		{
			bool bCheck = m_btn[BTN_KBLED_PROEDIT].IsCheck();
			m_edit.ShowWindow(bCheck ? SW_SHOW : SW_HIDE);
			m_combobox[COMBOX_KBLED_PROFILE].ShowWindow(bCheck ? SW_HIDE : SW_SHOW);
		
		if (bCheck)
		{
			m_edit.SetWindowText(m_kbProfile[0][m_nProfileSel].sProfileName);
		}
		else
		{
			CString sName = _T("");
			m_edit.GetWindowText(sName);
			sName.Trim();
			if (_T("") == sName)
			{
				sName = m_kbProfile[0][m_nProfileSel].sProfileName;
				m_edit.SetWindowText(sName);
			}
			m_kbProfile[0][m_nProfileSel].sProfileName = sName;
			m_combobox[COMBOX_KBLED_PROFILE].ResetContent();
			for (int i = 0; i < LED_PROFILE_CONT; i++)
			{
				m_combobox[COMBOX_KBLED_PROFILE].AddString(m_kbProfile[0][i].sProfileName, 0, CLR_WHITE);
			}
			m_combobox[COMBOX_KBLED_PROFILE].SetCurSel(m_nProfileSel);


			CArray<LED_SETTING> profiles;
			for (int i = 0; i < LED_PROFILE_CONT; i++)
			{
				profiles.Add(m_kbProfile[0][i]);
			}
			Aorus()->GetCfg()->SetLedProfiles(DEVICE_AK700, profiles, 0, 0);

		}
		return 1;
		}
//	case BTN_KBLED_PRODEL: break;
	case BTN_KBLED_APPLY: 
		switch (m_LedStyleDlg.GetCurStyle())
		{
		case SEL_STYLE_CONSISTENCE:
		case SEL_STYLE_PULSING:
		case SEL_STYLE_REACTIVE:
		case SEL_STYLE_RIPPLE:
		case SEL_STYLE_CYCLING:
		case SEL_STYLE_WAVE:
			OnApply();
		}
		break;
	case BTN_KBLED_DEFAULT: 
		AfxBeginThread(DefaultThread, this); 
		return 1;

	case BTN_KBLED_SYNCDEVICE:
		
		if (m_btn[BTN_KBLED_SYNCDEVICE].IsCheck())
		{
			AfxMessageBox(_T("注意：啟用燈光同步控制功能，鍵盤的波浪、反應、漣漪效果將會被暫時禁用。"));

			bSyncFlag = true;
			//只有ALL模式支持循環控燈
			m_combobox[COMBOX_KBLED_SELKEYS].SetCurSel(0);
			SwitchKeyStatus(m_combobox[COMBOX_KBLED_SELKEYS].GetCurSel());
			m_combobox[COMBOX_KBLED_SELKEYS].Enable(false);
			m_LedStyleDlg.SyncLedControlMode();

 			SetSyncLed(true);
 			m_btn[BTN_KBLED_SYNCDEVICE].UpdateWindow();
			bool bSyncLed = IsSyncLed();	

			ApplyLedSetting(0, led, bSyncLed, true);
 			if (!bSyncLed) 
 			{
 				ShowLoadingWindow(AfxGetMainWnd(), SW_SHOW);
 				Aorus()->ReInitAllDevicesLedState(); 
 				ShowLoadingWindow(AfxGetMainWnd(), SW_HIDE);
 			}
			return 1;
		}

		else 
		{
			bSyncFlag = false;
			SetSyncLed(false);
			m_btn[BTN_KBLED_SYNCDEVICE].UpdateWindow();
			bool bSyncLed = IsSyncLed();	

			ApplyLedSetting(0, led, bSyncLed, true);
			if (!bSyncLed) 
			{
				ShowLoadingWindow(AfxGetMainWnd(), SW_SHOW);
				Aorus()->ReInitAllDevicesLedState(); 
				ShowLoadingWindow(AfxGetMainWnd(), SW_HIDE);
			}

			m_combobox[COMBOX_KBLED_SELKEYS].Enable(true);
 			m_LedStyleDlg.NormalLedMode();	
			m_LedStyleDlg.UpdateWindow();
			return 1;
		}

	default:break;
	}

	//Terry 2017/07/17
	if (bSyncFlag)
	{
		KB_LED_CFG cfg;
		led.dwStyle = m_LedStyleDlg.getCurSyncStyle();
		led.bOn = m_LedStyleDlg.bSwichStaues();//統一控燈鍵盤界面開關

		if (led.dwStyle == 2)
		{
			m_LedStyleDlg.ReadCfg(4, cfg);//統一控燈選擇CYCLING對應STYLE序號為4
			led.nSpeed = cfg.nSpeed;
			led.nRangeMax = cfg.nBrightness;
			led.dwStyle = 6;//CYCLING模式，KEYBOARD下拉框中2對應MOUSE下拉框中6
			led.bMutilColor = true;
		}
		else
		{
			m_LedStyleDlg.ReadCfg(led.dwStyle, cfg);
			led.nSpeed = cfg.nSpeed;
			led.nRangeMax = cfg.nBrightness;
			led.clrLed = m_LedStyleDlg.getCurSyncColor();
			led.bMutilColor = false;
		}
		SetSyncLed(true);
		bool bSyncLed = IsSyncLed();
		m_kbProfile[0][m_nProfileSel] = led;
		UpdateWindow();
		ApplyLedSetting(0, led, bSyncLed, false);
	}
	return 1;
}

LRESULT CKBLedDlg::OnUiComboBoxSelChanged(WPARAM wParam, LPARAM lParam)
{
	int nCurSel = (int)lParam; 
	switch(wParam)
	{
	case COMBOX_KBLED_PROFILE: 
		{
			m_nProfileSel = m_combobox[COMBOX_KBLED_PROFILE].GetCurSel();
			SetProfile(m_nProfileSel);
			//m_KbAssign.SetProfile(m_nProfileSel);
			CAORUSDlg* pParent = (CAORUSDlg*)AfxGetMainWnd();
			pParent->SwitchAK700KeyProfile(m_nProfileSel);

		}
		break;

	case COMBOX_KBLED_SELKEYS:
		AfxBeginThread(SwitchKeyThread, this);
		//OnApply(false);
		break;
	}

	return 1;
}

void CKBLedDlg::SwitchKeysType(int nKeys)  // 104/105/106/107...
{
	if (m_nKeys == nKeys) 
		return;

	m_nKeys = nKeys;
	CRect rcKeys[KEYs_107];
	UINT nOn = 0, nOff = 0;
	for (int i = 0; i < KEYs_107; i++)
	{
		rcKeys[i] = s_KeysAK700[i];
	}

	switch(m_nKeys)
	{
	case 104: {
		nOn = IDB_PAN_KB104_ON; nOff = IDB_PAN_KB104_OFF;
		rcKeys[105].SetRect(0, 0,  0, 0);
		rcKeys[106].SetRect(0, 0,  0, 0);
		} break;
	case 105: {
		} break;
	case 106: {
		} break;
	case 107: {
		} break;
	}

	UI_KEYBOARD ubk = UI_KEYBOARD(this, 1, CRect(348, 28, 902, 222), nOff, nOn, CLR_MAIN, CLR_TRPT);
	m_KB.ResetKeyboard(ubk);
	for (int i = KEYs_107 - 1; i >= 0; i--)
	{
		m_KB.DeleteItem(i);
	}

	for (int i= 0; i < KEYs_107; i++)
	{
		m_KB.AddItem(&UIKB_RECT(i, rcKeys[i]));
		m_KB.SetItemStatus(i, true);
	}
}

void CKBLedDlg::SetKeysSelected(int keysSelIndex[], int nKeys)
{
	m_KB.ResetAllItemStatus();
	for (int i = 0; i < nKeys; i++)
	{
		m_KB.SetItemStatus(keysSelIndex[i], true);
	}
}

//void CKBLedDlg::SwitchGameKeyStatus(int panelIndex)
//{
//	ShowLoadingWindow(GetParent()->GetParent(), SW_SHOW);
//	CmdLock();
//	switch (panelIndex)
//	{
//	case 0: // FPS
//		{
//			SetItemStatus(FPS_COUNT, s_nFPSIndex);
//			m_sCurFile = _T("FPS");
//		}
//		break;
//	case 1: // MMO
//		{
//			SetItemStatus(MMO_COUNT, s_nMMOIndex);
//			m_sCurFile = _T("MMO");
//		}
//		break;
//	case 2: // MOBA
//		{
//			SetItemStatus(MOBA_COUNT, s_nMOBAIndex);
//			m_sCurFile = _T("MOBA");
//		}
//		break;
//	case 3: // RTS
//		{
//			SetItemStatus(RTS_COUNT, s_nRTSIndex);
//			m_sCurFile = _T("RTS");
//		}
//		break;
//	case 4: // CS:GO
//		{
//			SetItemStatus(CS_GO_COUNT, s_nCSGOIndex);
//			m_sCurFile = _T("CS");
//		}
//		break;
//	case 5: // DATA 2
//		{
//			SetItemStatus(DOTA2_COUNT, s_nDOTA2Index);
//			m_sCurFile = _T("DATA2");
//		}
//		break;
//	case 6: // lol
//		{
//			SetItemStatus(LOL_COUNT, s_nLOLIndex);
//			m_sCurFile = _T("LOL");
//		}
//		break;
//	case 7: // STARCRAFT II
//		{
//			SetItemStatus(STARCRAFT2_COUNT, s_nSTARCRAFT2Index);
//			m_sCurFile = _T("STARCRAFT");	
//		}
//		break;
//	}
//
//	m_Keyboard.Enable(false);
//
//
//	HANDLE hHandle;
//	hHandle = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)(ReadMEMThreadProc), (LPVOID)this, 0, NULL);
//	if(NULL != hHandle)
//	{
//		CloseHandle(hHandle);
//	}
//	CmdUnLock();
//	ShowLoadingWindow(GetParent()->GetParent(), SW_HIDE);
//}
//
//void CKBLedDlg::SwitchKeyStatus(int panelIndex)
//{
//	ShowLoadingWindow(GetParent()->GetParent(), SW_SHOW);
//	CmdLock();
//	m_Keyboard.ResetAllItemStatus();
//	CString file = _T("");
//
//	switch (panelIndex)
//	{
//	case 0: // ALL
//		{
//			int nCount = m_Keyboard.GetItemCount();
//			for (int i = 0; i < nCount; i++)
//			{
//				m_Keyboard.SetItemStatus(i, true);
//			}
//			m_Keyboard.Enable(false);
//
//			
//			CXK700Cmd::ChgLedType(m_nProfileSel, m_iAllType);
//			m_sCurFile = _T("");
//			SwitchLedNav(m_iAllType - 1);
//		}
//		break;
//	case 1: // Arrow Key
//		{
//			SetItemStatus(ARROW_KEY_COUNT, s_nArrowKeyIndex);
//			m_Keyboard.Enable(false);
//			m_sCurFile = _T("ArrowKey");
//		}
//		break;
//	case 2: // wasd
//		{
//			SetItemStatus(WASD_COUNT, s_nWASDIndex);
//			m_Keyboard.Enable(false);
//			m_sCurFile = _T("WASD");
//
//		}
//		break;
//	case 3: // numpad
//		{
//			SetItemStatus(NUMPAD_COUNT, s_nNumpadsndex);
//			m_Keyboard.Enable(false);
//			m_sCurFile = _T("NUMPAD");
//
//
//		}
//		break;
//	case 4: // fn key
//		{
//			SetItemStatus(FN_KEY_COUNT, s_nFNIndex);
//			m_Keyboard.Enable(false);
//			m_sCurFile = _T("FNKEY");
//
//		}
//		break;
//	case 5: // user define
//		{
//			m_Keyboard.Enable(true);
//			m_sCurFile = _T("USERDEFINE");
//		}
//
//		break;
//	}
//
//	CKbLedCtrl::ReadMemeryToSet(m_nProfileSel,m_sCurFile);
//	CmdUnLock();
//	ShowLoadingWindow(GetParent()->GetParent(), SW_HIDE);
//}


void CKBLedDlg::SetApplyBtnEnable(bool bEnable)	// Peter Lee 2017/6/18
{
}

void CKBLedDlg::SetCancelBtnEnable(bool bEnable)	// Peter Lee 2017/6/18
{
}

void CKBLedDlg::OnApply()
{
	//Terry 2017/07/25
// 	HANDLE hHandle;
// 	hHandle = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)(ApplyThreadProc), (LPVOID)this, 0, NULL);
// 	if(NULL != hHandle)
// 	{
// 		CloseHandle(hHandle);
// 	}
	ShowLoadingWindow(GetParent(), SW_SHOW);

	EnableWindow(FALSE);

	KB_LED_CFG cfg;
	int nStyle = m_LedStyleDlg.GetCurStyle();
	bool bStatus[KEYCOUNT] = {0};
	m_LedStyleDlg.ReadCfg(nStyle, cfg);
	int nOff = cfg.bOn ? 128 : 0;
	m_KB.GetAllItemStatus(bStatus, KEYCOUNT);
	int nProfile = m_nProfileSel;
	Sleep(500);
	CArray<LED_SETTING> profiles;
	for (int i = 0; i < LED_PROFILE_CONT; i++)
	{
		Sleep(100);
		profiles.Add(m_kbProfile[0][i]);
	}

	Aorus()->GetCfg()->SetLedProfiles(DEVICE_AK700, profiles, nProfile,0);

	CmdLock();

	CString szPathLedMem = GetProfilePath(nProfile) + _T("USERDEFINE.bin");
	

	//当文件不为空并且文件不是自定义是，设置非选中按键为灭
	//当选为自定义模式，当本地没有自定义文件资料时，设置非选中按键为灭
	if(!m_sCurFile.IsEmpty() && m_sCurFile.Find(_T("USERDEFINE")) < 0 || (!PathFileExists(szPathLedMem) &&  m_combobox[COMBOX_KBLED_SELKEYS].GetCurSel() == 5))  
	{
		CKbLedCtrl::m_bIsSave = true; //合并LED多次设置

		if (nStyle != SEL_STYLE_RIPPLE)
		{
			if(m_combobox[COMBOX_KBLED_SELKEYS].GetCurSel() == 5)
				CKbLedCtrl::ResetClrList(nProfile);
			else
				CKbLedCtrl::EnableKeyType(true);  //设置键盘类型
		}

		for(int i = 0; i < KEYCOUNT; i++)
		{
			bStatus[i] = !bStatus[i];				
		}

		CKbLedCtrl::ToConsistent(
			bStatus, 
			cfg.clrCfg[0].clrList[0], 
			cfg.nBrightness, 
			cfg.nSpeed, 
			false, //led off 
			nProfile);


		for(int i = 0; i < KEYCOUNT; i++)
		{
			bStatus[i] = !bStatus[i];				
		}
	}

	switch(m_LedStyleDlg.GetCurStyle())
	{
	case SEL_STYLE_CONSISTENCE:
		{
			if(isAllKey()) 	
			{
				CXK700Cmd::ChgLedType(nProfile, LED_CONSISTENT);
				CXK700Cmd::ChgLedSetting(
					LED_CONSIST | nOff, 
					0, 
					GetRValue(cfg.clrCfg[0].clrList[0]), 
					GetGValue(cfg.clrCfg[0].clrList[0]), 
					GetBValue(cfg.clrCfg[0].clrList[0]),
					cfg.nBrightness,
					0);
				CKbLedCtrl::ResetClrList(nProfile);
			}
			else
			{

				CKbLedCtrl::ToConsistent(
					bStatus, 
					cfg.clrCfg[0].clrList[0], 
					cfg.nBrightness, 
					cfg.nSpeed, 
					cfg.bOn, 
					nProfile);
				CXK700Cmd::ChgLedType(nProfile, 7);

			}
			break;
		}
	case SEL_STYLE_PULSING:
		{
			if(isAllKey()) 	
			{
				CXK700Cmd::ChgLedType(nProfile, LED_PULSING);
				if(cfg.clrCfg[0].nCount >= 7) 	
				{
					CXK700Cmd::ChgLedSetting(
						LED_PULSING | nOff, 
						8, 
						GetRValue(cfg.clrCfg[0].clrList[0]), 
						GetGValue(cfg.clrCfg[0].clrList[0]), 
						GetBValue(cfg.clrCfg[0].clrList[0]),
						cfg.nBrightness,
						cfg.nSpeed);
					break;
				}
				else if (cfg.clrCfg[0].nCount > 1)
				{
					CXK700Cmd::ChgLedSetting(
						LED_PULSING | nOff, 
						2, 
						GetRValue(cfg.clrCfg[0].clrList[1]), 
						GetGValue(cfg.clrCfg[0].clrList[1]), 
						GetBValue(cfg.clrCfg[0].clrList[1]),
						cfg.nBrightness,
						cfg.nSpeed);
					Sleep(200);
					CXK700Cmd::ChgLedSetting(
						LED_PULSING | nOff, 
						1, 
						GetRValue(cfg.clrCfg[0].clrList[0]), 
						GetGValue(cfg.clrCfg[0].clrList[0]), 
						GetBValue(cfg.clrCfg[0].clrList[0]),
						cfg.nBrightness,
						cfg.nSpeed);
					Sleep(200);
					CXK700Cmd::ChgLedSetting(LED_PULSING | nOff, 4, 0, 0, 0, cfg.nBrightness, cfg.nSpeed);
				}
				else if (cfg.clrCfg[0].nCount > 0)
				{

					if(m_LedStyleDlg.IsBreathing1Selected())
					{
						CXK700Cmd::ChgLedSetting(
							LED_PULSING | nOff, 
							1, 
							GetRValue(cfg.clrCfg[0].clrList[0]), 
							GetGValue(cfg.clrCfg[0].clrList[0]), 
							GetBValue(cfg.clrCfg[0].clrList[0]),
							cfg.nBrightness,
							cfg.nSpeed);
					}
					else
					{
						CXK700Cmd::ChgLedSetting(
							LED_PULSING | nOff, 
							2, 
							GetRValue(cfg.clrCfg[0].clrList[0]), 
							GetGValue(cfg.clrCfg[0].clrList[0]), 
							GetBValue(cfg.clrCfg[0].clrList[0]),
							cfg.nBrightness,
							cfg.nSpeed);
					}					
				}

				CKbLedCtrl::ResetClrList(nProfile);
			}
			else
			{

				CKbLedCtrl::ToPulsing(
					bStatus, 
					cfg.clrCfg[0].clrList[0], 
					cfg.clrCfg[0].nCount > 1 ? cfg.clrCfg[0].clrList[1] : cfg.clrCfg[0].clrList[0], 
					cfg.nBrightness, 
					cfg.nSpeed, 
					cfg.clrCfg[0].nCount >= 7,
					cfg.bOn, 
					nProfile);
				CXK700Cmd::ChgLedType(nProfile, 7);
			}
			break;
		}
	case SEL_STYLE_REACTIVE:
		{
			if(isAllKey()) 	
			{
				CXK700Cmd::ChgLedType(nProfile, LED_REACTIVE);
				CXK700Cmd::ChgLedSetting(
					LED_REACTIVE | nOff, 
					0, 
					GetRValue(cfg.clrCfg[0].clrList[0]), 
					GetGValue(cfg.clrCfg[0].clrList[0]), 
					GetBValue(cfg.clrCfg[0].clrList[0]),
					0,
					cfg.nSpeed);
				CKbLedCtrl::ResetClrList(nProfile);
			}
			else
			{

				CKbLedCtrl::ToReactive(
					bStatus, 
					cfg.bOn ? cfg.clrCfg[0].clrList[0] : RGB(0, 0, 0),
					cfg.nSpeed, 
					nProfile);
				CXK700Cmd::ChgLedType(nProfile, 7);
			}
			break;
		}
	case SEL_STYLE_RIPPLE:
		{			
			if(isAllKey()) 	
			{
				CXK700Cmd::ChgLedType(nProfile, LED_RIPPLE);
				for(int i = 0; i < cfg.clrCfg[0].nCount; i++)
				{
					CXK700Cmd::ChgLedSetting(
						LED_RIPPLE,
						i + 1 ,
						GetRValue(cfg.clrCfg[0].clrList[i]), 
						GetGValue(cfg.clrCfg[0].clrList[i]), 
						GetBValue(cfg.clrCfg[0].clrList[i]),
						0,
						0);
					Sleep(200);
				}

				CXK700Cmd::ChgLedSetting(
					LED_RIPPLE | nOff, 
					0, 
					cfg.clrCfg[0].nCount, 
					cfg.nWidth, 
					cfg.nStartWay,
					cfg.nTimes,
					cfg.nSpeed);
				CKbLedCtrl::ResetClrList(nProfile);
			}
			else
			{

				CKbLedCtrl::ToRipple(
					bStatus, 
					cfg.nWidth,
					cfg.nStartWay,
					cfg.nTimes,
					cfg.clrCfg[0].clrList,
					cfg.clrCfg[0].nCount,
					cfg.nSpeed, 
					nProfile, cfg.bOn);
				CXK700Cmd::ChgLedType(nProfile, 7);

			}
			break;
		}
	case SEL_STYLE_CYCLING:
		{
			CXK700Cmd::ChgLedType(nProfile, LED_CYCLING);
			if(isAllKey()) 	
			{
				CXK700Cmd::ChgLedSetting(
					LED_CYCLING | nOff, 
					0, 0, 0, 0,
					cfg.nBrightness,
					cfg.nSpeed);
				CKbLedCtrl::ResetClrList(nProfile);
			}
			else
			{

				CKbLedCtrl::ToCycling(
					bStatus, 
					cfg.nBrightness,
					cfg.nSpeed, 
					cfg.bOn,
					nProfile);
				CXK700Cmd::ChgLedType(nProfile, 7);
			}
			break;
		}
	case SEL_STYLE_WAVE:
		{
			CXK700Cmd::ChgLedType(nProfile, LED_WAVE);
			if(isAllKey()) 	
			{
				CKbLedCtrl::Wave(nProfile, cfg.nAngle, 0, 10, cfg.nSpeed, cfg.clrCfg[0].clrList, cfg.clrCfg[0].nCount);
				CXK700Cmd::ChgLedSetting(LED_WAVE | nOff, 5, cfg.nTimes, cfg.nStartWay,  cfg.nSpeed, 0, 0);
				CKbLedCtrl::ResetClrList(nProfile);
			}
			else
			{
				if(cfg.nStartWay == 1 && cfg.nTimes == 0)
				{
					CKbLedCtrl::ToWave(
						bStatus, 
						270 - cfg.nAngle,
						cfg.clrCfg[0].clrList,
						cfg.clrCfg[0].nCount,
						cfg.bOn,  
						cfg.nBrightness, 
						cfg.nSpeed,
						nProfile);
				}
				else
				{
					CKbLedCtrl::ToWave(
						bStatus, 
						270 - cfg.nAngle,
						cfg.clrCfg[0].clrList,
						cfg.clrCfg[0].nCount,
						cfg.bOn, 
						cfg.nBrightness, 
						cfg.nSpeed, 
						cfg.nStartWay, 
						cfg.nTimes,
						nProfile);
				}

				CXK700Cmd::ChgLedType(nProfile, 7);
			}
			break;
		}
	}

	if(!isAllKey())
		CKbLedCtrl::EnableKeyType(false);
	CKbLedCtrl::SaveMemery(nProfile, m_sCurFile);

	CmdUnLock();
	ShowLoadingWindow(GetParent(), SW_HIDE);
//	Sleep(500);
//	CXK700Cmd::SetLEDStatus(true);  //LEDON 2017/07/25 Terry
	EnableWindow(TRUE);



 	return;
}

//Terry 2017/07/25
// DWORD CKBLedDlg::ApplyThreadProc(LPVOID lpParameter)
// {
// 
// 	CKBLedDlg* pMain = (CKBLedDlg*)lpParameter;
// 
// 	pMain->EnableWindow(FALSE);
// 
// 	KB_LED_CFG cfg;
// 	int nStyle = pMain->m_LedStyleDlg.GetCurStyle();
// 	bool bStatus[KEYCOUNT] = {0};
// 	pMain->m_LedStyleDlg.ReadCfg(nStyle, cfg);
// 	int nOff = cfg.bOn ? 128 : 0;
// 	pMain->m_KB.GetAllItemStatus(bStatus, KEYCOUNT);
// 	int nProfile = pMain->m_nProfileSel;
// 	//int nPageLst[] = {0, 1, 2, 4, 3, 5};
// 	/*int nPage = pMain->m_panel[PAN_KB_LED_NAV].GetCurItem();
// 	pMain->ReadCfg(nPage, cfg);
// 	int nOff = cfg.bOn ? 128 : 0;
// 	pMain->m_Keyboard.GetAllItemStatus(bStatus, KEYCOUNT);
// 
// 	int nProfile = pMain->m_nProfileSel;
// 
// 	if (s_VgaCtrl.GetBaseSetting().bSyncLed)
// 	{
// 		s_SyncLedConfig.nType = cfg.nType;
// 		if(5 == cfg.nType) s_SyncLedConfig.nType = 3;
// 		if(!cfg.bOn) s_SyncLedConfig.nType = 4;
// 		s_SyncLedConfig.clrArray[0] = cfg.clrCfg[0].clrList[0];
// 		s_SyncLedConfig.nSpeed = cfg.nSpeed;
// 		s_SyncLedConfig.nBright = cfg.nBrightness * 10;
// 		s_SyncLedConfig.nClrCount = 1;
// 		CSyncLed::Set(s_SyncLedConfig, true);
// 		pMain->EnableWindow(TRUE);
// 		return 0;
// 	}*/
// 
// 	//Terry 2017/07/13
// 	Sleep(500);
// 	CArray<LED_SETTING> profiles;
// 	for (int i = 0; i < LED_PROFILE_CONT; i++)
// 	{
// 		Sleep(100);
// 		profiles.Add(pMain->m_kbProfile[0][i]);
// 	}
// 
// 	Aorus()->GetCfg()->SetLedProfiles(DEVICE_AK700, profiles, nProfile,0);
// 
// 	//Terry 2017/07/25
// 	LED_SETTING led = pMain->m_kbProfile[0][nProfile];
// 	bool bSyncLed = pMain->IsSyncLed();
// 	if (bSyncLed)
// 	{
// 		pMain->m_kbProfile[0][nProfile] = led;
// 	}
// 	pMain->ApplyLedSetting(0, led, bSyncLed, true);
// 
// 	CXK700Cmd::SetLEDStatus(false); //LEDOFF
// 	ShowLoadingWindow(pMain->GetParent(), SW_SHOW);
// 	CmdLock();
// 
// 	CString szPathLedMem = pMain->GetProfilePath(nProfile) + _T("USERDEFINE.bin");
// 	
// 
// 	//当文件不为空并且文件不是自定义是，设置非选中按键为灭
// 	//当选为自定义模式，当本地没有自定义文件资料时，设置非选中按键为灭
// 	if(!pMain->m_sCurFile.IsEmpty() && pMain->m_sCurFile.Find(_T("USERDEFINE")) < 0 || (!PathFileExists(szPathLedMem) &&  pMain->m_combobox[COMBOX_KBLED_SELKEYS].GetCurSel() == 5))  
// 	{
// 		CKbLedCtrl::m_bIsSave = true; //合并LED多次设置
// 
// 		if (nStyle != SEL_STYLE_RIPPLE)
// 		{
// 			if(pMain->m_combobox[COMBOX_KBLED_SELKEYS].GetCurSel() == 5)
// 				CKbLedCtrl::ResetClrList(nProfile);
// 			else
// 				CKbLedCtrl::EnableKeyType(true);  //设置键盘类型
// 		}
// 
// 		for(int i = 0; i < KEYCOUNT; i++)
// 		{
// 			bStatus[i] = !bStatus[i];				
// 		}
// 
// 		CKbLedCtrl::ToConsistent(
// 			bStatus, 
// 			cfg.clrCfg[0].clrList[0], 
// 			cfg.nBrightness, 
// 			cfg.nSpeed, 
// 			false, //led off 
// 			nProfile);
// 
// 
// 		for(int i = 0; i < KEYCOUNT; i++)
// 		{
// 			bStatus[i] = !bStatus[i];				
// 		}
// 	}
// 
// 	switch(pMain->m_LedStyleDlg.GetCurStyle())
// 	{
// 	case SEL_STYLE_CONSISTENCE:
// 		{
// 			if(pMain->isAllKey()) 	
// 			{
// 				CXK700Cmd::ChgLedType(nProfile, LED_CONSISTENT);
// 				CXK700Cmd::ChgLedSetting(
// 					LED_CONSIST | nOff, 
// 					0, 
// 					GetRValue(cfg.clrCfg[0].clrList[0]), 
// 					GetGValue(cfg.clrCfg[0].clrList[0]), 
// 					GetBValue(cfg.clrCfg[0].clrList[0]),
// 					cfg.nBrightness,
// 					0);
// 				CKbLedCtrl::ResetClrList(nProfile);
// 			}
// 			else
// 			{
// 
// 				CKbLedCtrl::ToConsistent(
// 					bStatus, 
// 					cfg.clrCfg[0].clrList[0], 
// 					cfg.nBrightness, 
// 					cfg.nSpeed, 
// 					cfg.bOn, 
// 					nProfile);
// 				CXK700Cmd::ChgLedType(nProfile, 7);
// 
// 			}
// 			break;
// 		}
// 	/*case LED_LOL:
// 		{
// 			if(pMain->isAllKey()) 	
// 			{
// 				CXK700Cmd::ChgLedType(nProfile, LED_CMD_LOL);
// 				CXK700Cmd::ChgLedSetting(
// 					LED_CMD_LOL | nOff, 
// 					0, 
// 					GetRValue(cfg.clrCfg[0].clrList[0]), 
// 					GetGValue(cfg.clrCfg[0].clrList[0]), 
// 					GetBValue(cfg.clrCfg[0].clrList[0]),
// 					cfg.nBrightness,
// 					0);
// 				CKbLedCtrl::ResetClrList(nProfile);
// 			}
// 			break;
// 		}
// 	case LED_CS:
// 		{
// 			if(pMain->isAllKey()) 	
// 			{
// 				CXK700Cmd::ChgLedType(nProfile, LED_CMD_CS);
// 				CXK700Cmd::ChgLedSetting(
// 					LED_CMD_CS | nOff, 
// 					0, 
// 					GetRValue(cfg.clrCfg[0].clrList[0]), 
// 					GetGValue(cfg.clrCfg[0].clrList[0]), 
// 					GetBValue(cfg.clrCfg[0].clrList[0]),
// 					cfg.nBrightness,
// 					0);
// 				CKbLedCtrl::ResetClrList(nProfile);
// 			}
// 			break;
// 		}*/
// 	case SEL_STYLE_PULSING:
// 		{
// 			if(pMain->isAllKey()) 	
// 			{
// 				CXK700Cmd::ChgLedType(nProfile, LED_PULSING);
// 				if(cfg.clrCfg[0].nCount >= 7) 	
// 				{
// 					CXK700Cmd::ChgLedSetting(
// 						LED_PULSING | nOff, 
// 						8, 
// 						GetRValue(cfg.clrCfg[0].clrList[0]), 
// 						GetGValue(cfg.clrCfg[0].clrList[0]), 
// 						GetBValue(cfg.clrCfg[0].clrList[0]),
// 						cfg.nBrightness,
// 						cfg.nSpeed);
// 					break;
// 				}
// 				else if (cfg.clrCfg[0].nCount > 1)
// 				{
// 					CXK700Cmd::ChgLedSetting(
// 						LED_PULSING | nOff, 
// 						2, 
// 						GetRValue(cfg.clrCfg[0].clrList[1]), 
// 						GetGValue(cfg.clrCfg[0].clrList[1]), 
// 						GetBValue(cfg.clrCfg[0].clrList[1]),
// 						cfg.nBrightness,
// 						cfg.nSpeed);
// 					Sleep(200);
// 					CXK700Cmd::ChgLedSetting(
// 						LED_PULSING | nOff, 
// 						1, 
// 						GetRValue(cfg.clrCfg[0].clrList[0]), 
// 						GetGValue(cfg.clrCfg[0].clrList[0]), 
// 						GetBValue(cfg.clrCfg[0].clrList[0]),
// 						cfg.nBrightness,
// 						cfg.nSpeed);
// 					Sleep(200);
// 					CXK700Cmd::ChgLedSetting(LED_PULSING | nOff, 4, 0, 0, 0, cfg.nBrightness, cfg.nSpeed);
// 				}
// 				else if (cfg.clrCfg[0].nCount > 0)
// 				{
// 
// 					if(pMain->m_LedStyleDlg.IsBreathing1Selected())
// 					{
// 						CXK700Cmd::ChgLedSetting(
// 							LED_PULSING | nOff, 
// 							1, 
// 							GetRValue(cfg.clrCfg[0].clrList[0]), 
// 							GetGValue(cfg.clrCfg[0].clrList[0]), 
// 							GetBValue(cfg.clrCfg[0].clrList[0]),
// 							cfg.nBrightness,
// 							cfg.nSpeed);
// 					}
// 					else
// 					{
// 						CXK700Cmd::ChgLedSetting(
// 							LED_PULSING | nOff, 
// 							2, 
// 							GetRValue(cfg.clrCfg[0].clrList[0]), 
// 							GetGValue(cfg.clrCfg[0].clrList[0]), 
// 							GetBValue(cfg.clrCfg[0].clrList[0]),
// 							cfg.nBrightness,
// 							cfg.nSpeed);
// 					}					
// 				}
// 
// 				CKbLedCtrl::ResetClrList(nProfile);
// 			}
// 			else
// 			{
// 
// 				CKbLedCtrl::ToPulsing(
// 					bStatus, 
// 					cfg.clrCfg[0].clrList[0], 
// 					cfg.clrCfg[0].nCount > 1 ? cfg.clrCfg[0].clrList[1] : cfg.clrCfg[0].clrList[0], 
// 					cfg.nBrightness, 
// 					cfg.nSpeed, 
// 					cfg.clrCfg[0].nCount >= 7,
// 					cfg.bOn, 
// 					nProfile);
// 				CXK700Cmd::ChgLedType(nProfile, 7);
// 			}
// 			break;
// 		}
// 	case SEL_STYLE_REACTIVE:
// 		{
// 			if(pMain->isAllKey()) 	
// 			{
// 				CXK700Cmd::ChgLedType(nProfile, LED_REACTIVE);
// 				CXK700Cmd::ChgLedSetting(
// 					LED_REACTIVE | nOff, 
// 					0, 
// 					GetRValue(cfg.clrCfg[0].clrList[0]), 
// 					GetGValue(cfg.clrCfg[0].clrList[0]), 
// 					GetBValue(cfg.clrCfg[0].clrList[0]),
// 					0,
// 					cfg.nSpeed);
// 				CKbLedCtrl::ResetClrList(nProfile);
// 			}
// 			else
// 			{
// 
// 				CKbLedCtrl::ToReactive(
// 					bStatus, 
// 					cfg.bOn ? cfg.clrCfg[0].clrList[0] : RGB(0, 0, 0),
// 					cfg.nSpeed, 
// 					nProfile);
// 				CXK700Cmd::ChgLedType(nProfile, 7);
// 			}
// 			break;
// 		}
// 	case SEL_STYLE_RIPPLE:
// 		{			
// 			if(pMain->isAllKey()) 	
// 			{
// 				CXK700Cmd::ChgLedType(nProfile, LED_RIPPLE);
// 				for(int i = 0; i < cfg.clrCfg[0].nCount; i++)
// 				{
// 					CXK700Cmd::ChgLedSetting(
// 						LED_RIPPLE,
// 						i + 1 ,
// 						GetRValue(cfg.clrCfg[0].clrList[i]), 
// 						GetGValue(cfg.clrCfg[0].clrList[i]), 
// 						GetBValue(cfg.clrCfg[0].clrList[i]),
// 						0,
// 						0);
// 					Sleep(200);
// 				}
// 
// 				CXK700Cmd::ChgLedSetting(
// 					LED_RIPPLE | nOff, 
// 					0, 
// 					cfg.clrCfg[0].nCount, 
// 					cfg.nWidth, 
// 					cfg.nStartWay,
// 					cfg.nTimes,
// 					cfg.nSpeed);
// 				CKbLedCtrl::ResetClrList(nProfile);
// 			}
// 			else
// 			{
// 
// 				CKbLedCtrl::ToRipple(
// 					bStatus, 
// 					cfg.nWidth,
// 					cfg.nStartWay,
// 					cfg.nTimes,
// 					cfg.clrCfg[0].clrList,
// 					cfg.clrCfg[0].nCount,
// 					cfg.nSpeed, 
// 					nProfile, cfg.bOn);
// 				CXK700Cmd::ChgLedType(nProfile, 7);
// 
// 			}
// 			break;
// 		}
// 	case SEL_STYLE_CYCLING:
// 		{
// 			CXK700Cmd::ChgLedType(nProfile, LED_CYCLING);
// 			if(pMain->isAllKey()) 	
// 			{
// 				CXK700Cmd::ChgLedSetting(
// 					LED_CYCLING | nOff, 
// 					0, 0, 0, 0,
// 					cfg.nBrightness,
// 					cfg.nSpeed);
// 				CKbLedCtrl::ResetClrList(nProfile);
// 			}
// 			else
// 			{
// 
// 				CKbLedCtrl::ToCycling(
// 					bStatus, 
// 					cfg.nBrightness,
// 					cfg.nSpeed, 
// 					cfg.bOn,
// 					nProfile);
// 				CXK700Cmd::ChgLedType(nProfile, 7);
// 			}
// 			break;
// 		}
// 	case SEL_STYLE_WAVE:
// 		{
// 			CXK700Cmd::ChgLedType(nProfile, LED_WAVE);
// 			if(pMain->isAllKey()) 	
// 			{
// 				CKbLedCtrl::Wave(nProfile, cfg.nAngle, 0, 10, cfg.nSpeed, cfg.clrCfg[0].clrList, cfg.clrCfg[0].nCount);
// 				CXK700Cmd::ChgLedSetting(LED_WAVE | nOff, 5, cfg.nTimes, cfg.nStartWay,  cfg.nSpeed, 0, 0);
// 				CKbLedCtrl::ResetClrList(nProfile);
// 			}
// 			else
// 			{
// 				if(cfg.nStartWay == 1 && cfg.nTimes == 0)
// 				{
// 					CKbLedCtrl::ToWave(
// 						bStatus, 
// 						270 - cfg.nAngle,
// 						cfg.clrCfg[0].clrList,
// 						cfg.clrCfg[0].nCount,
// 						cfg.bOn,  
// 						cfg.nBrightness, 
// 						cfg.nSpeed,
// 						nProfile);
// 				}
// 				else
// 				{
// 					CKbLedCtrl::ToWave(
// 						bStatus, 
// 						270 - cfg.nAngle,
// 						cfg.clrCfg[0].clrList,
// 						cfg.clrCfg[0].nCount,
// 						cfg.bOn, 
// 						cfg.nBrightness, 
// 						cfg.nSpeed, 
// 						cfg.nStartWay, 
// 						cfg.nTimes,
// 						nProfile);
// 				}
// 
// 				CXK700Cmd::ChgLedType(nProfile, 7);
// 			}
// 			break;
// 		}
// 	}
// 
// 	if(!pMain->isAllKey())
// 		CKbLedCtrl::EnableKeyType(false);
// 	CKbLedCtrl::SaveMemery(nProfile,pMain->m_sCurFile);
// 
// 	CmdUnLock();
// 	ShowLoadingWindow(pMain->GetParent(), SW_HIDE);
// 	Sleep(500);
// 	CXK700Cmd::SetLEDStatus(true);  //LEDON
// 	//pMain->m_curCfg = cfg;
// 	pMain->EnableWindow(TRUE);
// 	//pMain->m_btn[BTN_KB_LED_APPLY].Enable(FALSE);
// 	//pMain->m_btn[BTN_KB_LED_RESET].Enable(FALSE);
// 
// 
//  	return 0;
// }

UINT CKBLedDlg::SwitchKeyThread(LPVOID lpParam)
{
	CKBLedDlg* pMain = (CKBLedDlg*)lpParam;
	pMain->EnableWindow(FALSE);
	pMain->SwitchKeyStatus(pMain->m_combobox[COMBOX_KBLED_SELKEYS].GetCurSel());
	pMain->EnableWindow(TRUE);
	return 0;

}

void CKBLedDlg::SwitchKeyStatus(int iIndex)
{
	ShowLoadingWindow(GetParent(), SW_SHOW);
	CmdLock();
	m_KB.ResetAllItemStatus();
	CString file = _T("");

	switch (iIndex)
	{
	case 0: // ALL
		{
			int nCount = m_KB.GetItemCount();
			for (int i = 0; i < nCount; i++)
			{
				m_KB.SetItemStatus(i, true);
			}
			m_KB.Enable(false);

			
			CXK700Cmd::ChgLedType(m_nProfileSel, m_iAllType);
			m_sCurFile = _T("");
			SwitchLedNav(m_iAllType - 1);
		}
		break;
	case 1: // Arrow Key
		{
			SetItemStatus(ARROW_KEY_COUNT, s_nArrowKeyIndex);
			m_KB.Enable(false);
			m_sCurFile = _T("ArrowKey");
		}
		break;
	case 2: // wasd
		{
			SetItemStatus(WASD_COUNT, s_nWASDIndex);
			m_KB.Enable(false);
			m_sCurFile = _T("WASD");
		}
		break;
	case 3: // numpad
		{
			SetItemStatus(NUMPAD_COUNT, s_nNumpadsndex);
			m_KB.Enable(false);
			m_sCurFile = _T("NUMPAD");
		}
		break;
	case 4: // fn key
		{
			SetItemStatus(FN_KEY_COUNT, s_nFNIndex);
			m_KB.Enable(false);
			m_sCurFile = _T("FNKEY");
		}
		break;
	case 5: // user define
		{
			m_KB.Enable(true);
			m_sCurFile = _T("USERDEFINE");
		}

		break;
	}

	CKbLedCtrl::ReadMemeryToSet(m_nProfileSel,m_sCurFile);
	CmdUnLock();
	ShowLoadingWindow(GetParent(), SW_HIDE);
}

// 設置鍵盤的key狀態，count是arr的長度，arr是存放key index的數組。
void CKBLedDlg::SetItemStatus(int count, int arr[])
{
	m_KB.ResetAllItemStatus();
	for (int i = 0; i < count; i++)
	{
		m_KB.SetItemStatus(arr[i], true);
	}
}

bool CKBLedDlg::isAllKey()
{
	int nItem[200];
	int nCount = 200;
	m_KB.GetAllSelectItem(nItem, nCount);
	return nCount >= 105; // 含Logo燈
}

/************************************************************************/
/* 键盘底部导航页卡切换                                          */
/************************************************************************/
void CKBLedDlg::SwitchLedNav(int nIndex)
{
	/*m_btn[BTN_KB_LED_APPLY].Enable(true);
	m_btn[BTN_KB_LED_RESET].Enable(true);

	//if(nIndex == 3 || nIndex == 5) return; // 暫時忽略Ripple和Wave模式
	if(s_VgaCtrl.GetBaseSetting().bSyncLed)
	{
		if (0 != nIndex && 1 != nIndex && 4 != nIndex)
		{
			return;
		}

		KB_LED_CFG cfg;
		int nPageLst[] = {0, 1, 2, 3, 4, 5, 6, 7};
		int nPage = nPageLst[nIndex];
		cfg.nType = nPage;
		ReadCfg(nPage, cfg);

		s_SyncLedConfig.nType = cfg.nType;
		if(5 == cfg.nType) s_SyncLedConfig.nType = 3;
		if(!cfg.bOn) s_SyncLedConfig.nType = 4;
		s_SyncLedConfig.clrArray[0] = cfg.clrCfg[0].clrList[0];
		s_SyncLedConfig.nSpeed = cfg.nSpeed;
		s_SyncLedConfig.nBright = cfg.nBrightness * 10;
		s_SyncLedConfig.nClrCount = 1;
		CSyncLed::Set(s_SyncLedConfig);

		m_stc[STC_KB_LED_CONSISTENT].ShowWindow(nIndex == 0 ? SW_SHOW : SW_HIDE);
		m_stc[STC_KB_LED_BREATHING ].ShowWindow(nIndex == 1 ? SW_SHOW : SW_HIDE);
		m_stc[STC_KB_LED_REACTIVE  ].ShowWindow(nIndex == 2 ? SW_SHOW : SW_HIDE);
		m_stc[STC_KB_LED_RIPPLE	   ].ShowWindow(nIndex == 3 ? SW_SHOW : SW_HIDE);
		m_stc[STC_KB_LED_CYCLING   ].ShowWindow(nIndex == 4 ? SW_SHOW : SW_HIDE);
		m_stc[STC_KB_LED_WAVE	   ].ShowWindow(nIndex == 5 ? SW_SHOW : SW_HIDE);
		m_stc[STC_KB_LED_LOL	   ].ShowWindow(nIndex == 6 ? SW_SHOW : SW_HIDE);
		m_stc[STC_KB_LED_CS		   ].ShowWindow(nIndex == 7 ? SW_SHOW : SW_HIDE);

		return;
	}

	m_stc[STC_KB_LED_CONSISTENT].ShowWindow(nIndex == 0 ? SW_SHOW : SW_HIDE);
	m_stc[STC_KB_LED_BREATHING ].ShowWindow(nIndex == 1 ? SW_SHOW : SW_HIDE);
	m_stc[STC_KB_LED_REACTIVE  ].ShowWindow(nIndex == 2 ? SW_SHOW : SW_HIDE);
	m_stc[STC_KB_LED_RIPPLE	   ].ShowWindow(nIndex == 3 ? SW_SHOW : SW_HIDE);
	m_stc[STC_KB_LED_CYCLING   ].ShowWindow(nIndex == 4 ? SW_SHOW : SW_HIDE);
	m_stc[STC_KB_LED_WAVE	   ].ShowWindow(nIndex == 5 ? SW_SHOW : SW_HIDE);
	m_stc[STC_KB_LED_LOL	   ].ShowWindow(nIndex == 6 ? SW_SHOW : SW_HIDE);
	m_stc[STC_KB_LED_CS		   ].ShowWindow(nIndex == 7 ? SW_SHOW : SW_HIDE);

	//int nItem[] = {0, 1, 2, 4, 3, 5};
	m_panel[PAN_KB_LED_NAV].SetCurItem(nIndex);


	if(m_panel[PAN_KB_LED_LIST].GetCurItem() == 0)
	{
		int nType[] = {LED_CONSIST, LED_PULSING, LED_REACTIVE, LED_RIPPLE, LED_CYCLING, LED_WAVE, LED_CMD_LOL, LED_CMD_CS};
		CXK700Cmd::ChgLedType(m_nProfileSel, nType[nIndex]);
		m_iAllType = nIndex + 1;
	}*/
}

CString CKBLedDlg::GetProfilePath(int nProfile)
{
	return CKbLedCtrl::GetCfgPath(nProfile);
}

void CKBLedDlg::SetProfile(int nProfile)
{
	m_nProfileSel = nProfile;


	CXK700Cmd::SwitchProfile(m_nProfileSel);
	Sleep(100);

	CKbLedCtrl::LoadProfileClrList(m_nProfileSel);

}

UINT CKBLedDlg::DefaultThread(LPVOID lpParam)
{
	CKBLedDlg* pMain = (CKBLedDlg*)lpParam;
	pMain->OnDefault();
	return 0;
}

void CKBLedDlg::OnDefault()
{
	/*if (s_VgaCtrl.GetBaseSetting().bSyncLed)
	{
		s_SyncLedConfig = SYNCLED_CONFIG();
		CSyncLed::Set(s_SyncLedConfig, true);
		SyncLedState();
	}
	else
	{*/
		CKbLedCtrl::Default(m_nProfileSel);
	//}
	//m_btn[BTN_KB_LED_APPLY].Enable(false);
	//m_btn[BTN_KB_LED_RESET].Enable(false);
}

void CKBLedDlg::InitState()
{
	//同步統一控燈CHECKBUTTON狀態 Terry 2017/07/19
	bool bSyncLed = IsSyncLed();
	m_btn[BTN_KBLED_SYNCDEVICE].SetCheck(bSyncLed ? true : false);
	InitProfile();	
}

void CKBLedDlg::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	if (bShow)
	{
		InitProfile();
		OnUiComboBoxSelChanged(COMBOX_KBLED_PROFILE, m_nProfileSel);
		m_combobox[COMBOX_KBLED_PROFILE].SetCurSel(m_nProfileSel);
	}
//LED界面選取同步控燈，切換至KEYBOARD同樣改變下拉框中LEDStyles Terry 2017/07/19
// 	if (m_btn[BTN_KBLED_SYNCDEVICE].IsCheck())
// 	{
// 		m_combobox[COMBOX_KBLED_SELKEYS].SetCurSel(0);
// 		SwitchKeyStatus(m_combobox[COMBOX_KBLED_SELKEYS].GetCurSel());
// 		m_combobox[COMBOX_KBLED_SELKEYS].Enable(false);
// 		m_LedStyleDlg.SyncLedControlMode();
// 		m_LedStyleDlg.UpdateWindow();
// 	}
// 	else 
// 	{
// 		m_combobox[COMBOX_KBLED_SELKEYS].Enable(true);
// 		m_LedStyleDlg.NormalLedMode();	
// 		m_LedStyleDlg.UpdateWindow();
// 	}
	if (m_btn[BTN_KBLED_SYNCDEVICE].IsCheck())
	{
		bSyncFlag = true;
		m_combobox[COMBOX_KBLED_SELKEYS].SetCurSel(0);
		SwitchKeyStatus(m_combobox[COMBOX_KBLED_SELKEYS].GetCurSel());
		m_combobox[COMBOX_KBLED_SELKEYS].Enable(false);
		m_LedStyleDlg.SyncLedControlMode();
	//	SetSyncLed(m_btn[BTN_KBLED_SYNCDEVICE].IsCheck());
		m_btn[BTN_KBLED_SYNCDEVICE].UpdateWindow();
		bool bSyncLed = IsSyncLed();	
	}

	else 
	{
		bSyncFlag = false;
	//	SetSyncLed(m_btn[BTN_KBLED_SYNCDEVICE].IsCheck());
		m_btn[BTN_KBLED_SYNCDEVICE].UpdateWindow();
		bool bSyncLed = IsSyncLed();	

		if (!bSyncLed) 
		{
			ShowLoadingWindow(AfxGetMainWnd(), SW_SHOW);
			Aorus()->ReInitAllDevicesLedState(); 
			ShowLoadingWindow(AfxGetMainWnd(), SW_HIDE);
		}
		m_combobox[COMBOX_KBLED_SELKEYS].Enable(true);
		m_LedStyleDlg.NormalLedMode();	
		m_LedStyleDlg.UpdateWindow();
	}

	CWnd::OnShowWindow(bShow, nStatus);
}

void CKBLedDlg::InitProfile()
{
	m_nDevice = DEVICE_AK700;
	int nDevices = 1; 
//	int m_nProSel;
	if (DEVICE_VGA == m_nDevice)
	{
		CVGA* pVGA = (CVGA*)Aorus()->GetDevice(DEVICE_VGA);
		nDevices = pVGA->Ctrl()->GetGpuCount();
	}

	LED_SETTING ledCur;
	for (int i = 0; i < nDevices; i++)
	{
		int nProSel = 0;
		CArray<LED_SETTING> profiles;
		Aorus()->GetCfg()->GetLedProfiles(m_nDevice, profiles, nProSel, i);
		if ((int)profiles.GetSize() <= 0)
		{
			m_nProSel = 0;
			LED_SETTING ledNew;
			ledNew.sProfileName = "Profile1";
			profiles.Add(ledNew);
		}
		for(int k = 0; k < (int)profiles.GetSize(); k++)
		{
			LED_SETTING ledP = profiles.GetAt(k);
			m_kbProfile[i][k] = ledP;
		}

		m_combobox[COMBOX_KBLED_PROFILE].ResetContent();
		for(int i = 0; i < LED_PROFILE_CONT; i++)
		{
			m_combobox[COMBOX_KBLED_PROFILE].AddString(m_kbProfile[0][i].sProfileName, 0, CLR_WHITE);
		}
		 m_combobox[COMBOX_KBLED_PROFILE].SetCurSel(m_nProfileSel);
	}
}

//Terry 2017/07/17
void CKBLedDlg::SetSyncLed(bool bSyncLed)
{
	VGA_PARAM_BASESETTING base;
	Aorus()->GetCfg()->GetBaseSetting(base);
	base.bSyncLed = bSyncLed;
	Aorus()->GetCfg()->SetBaseSetting(base);
}

bool CKBLedDlg::IsSyncLed()
{
	VGA_PARAM_BASESETTING base;
	Aorus()->GetCfg()->GetBaseSetting(base);
	return base.bSyncLed ? true : false;
}

void CKBLedDlg::SyncLedSetting(LED_SETTING& led, bool bSave)
{
	ShowLoadingWindow(AfxGetMainWnd(), SW_SHOW);			
	CVGA* pVGA = (CVGA*)Aorus()->GetDevice(DEVICE_VGA);
	int nGPUs = pVGA->Ctrl()->GetGpuCount();

	for (int i = 0; i < DEVICE_COUNT; i++)
	{
		CDevice* pDevice = Aorus()->GetDevice(s_DevIds[i]);
		if(!pDevice->IsConnected())
			continue;

		int nDevices = 1;
		if (pDevice->GetDeviceId() == DEVICE_VGA) nDevices = nGPUs;
		for (int m = 0; m < nDevices; m++)
		{
			int nProSel = 0;
			CArray<LED_SETTING> profiles;
			Aorus()->GetCfg()->GetLedProfiles(pDevice->GetDeviceId(), profiles, nProSel, m);
			// always save
			CArray<LED_SETTING> prosNew;
			for (int k = 0; k < (int)profiles.GetSize(); k++)
			{
				if (k == nProSel)
				{
					prosNew.Add(led); continue;
				}
				LED_SETTING ledTmp = profiles.GetAt(k);
				prosNew.Add(ledTmp);
			}

			Aorus()->GetCfg()->SetLedProfiles(pDevice->GetDeviceId(), prosNew, nProSel, m);
			// pDevice->SetLedSetting(m, nProSel, led, bSave); 
		}
	}

	Aorus()->ReInitAllDevicesLedState();   // refresh all devices' led dialog

	// Notify all devices to sync led.

	SYNCLED_CONFIG cfg;
	cfg.nType = -1;
	cfg.nBright = led.nRangeMax;
	cfg.nSpeed = led.nSpeed;
	for (int i = 0; i < 7; i++) 
	{
		cfg.clrArray[i] = s_clr[i];
	}

	switch(led.dwStyle)
	{
	case LED_STYLE_CONSISTENT:	
		cfg.nType = GVORDER_LED_CONSISTENT; 
		cfg.nClrCount = 1;
		cfg.clrArray[0] = led.clrLed;
		break;
	case LED_STYLE_BREATHING:	
		cfg.nType = led.bMutilColor ? GVORDER_LED_CYCLING : GVORDER_LED_BREATHING; 
		cfg.nClrCount = led.bMutilColor ? 7 : 1;
		if (!led.bMutilColor) cfg.clrArray[0] = led.clrLed;
		break;
	case LED_STYLE_FLASHING:	
		cfg.nType = GVORDER_LED_SINGLETWINKLE; 
		cfg.nClrCount = led.bMutilColor ? 7 : 1;
		if (!led.bMutilColor) cfg.clrArray[0] = led.clrLed;
		break;
	case LED_STYLE_DUALFLASHING:
		cfg.nType = GVORDER_LED_TWICETWINKLE; 
		cfg.nClrCount = led.bMutilColor ? 7 : 1;
		if (!led.bMutilColor) cfg.clrArray[0] = led.clrLed;
		break;
	case LED_STYLE_CIRCLING:	
		cfg.nType = GVORDER_LED_CYCLING; 
		cfg.nClrCount = 7;
		break;
	default: 
		cfg.nType = GVORDER_LED_CONSISTENT; 
		cfg.nClrCount = 1;
		cfg.clrArray[0] = led.clrLed;
		break;  // others: unsupported
	}

	for (int i = cfg.nClrCount; i < CLR_MAX_COUNT; i++)
	{
		cfg.clrArray[i] = RGB(0, 0, 0);
	}
	if (!led.bOn) { cfg.nType = GVORDER_LED_CONSISTENT; cfg.nBright = 0;}
	s_SyncLedConfig = cfg;
	s_SyncLedConfig.nBright = cfg.nBright*10;
	CSyncLed::Set(s_SyncLedConfig, true);

	ShowLoadingWindow(AfxGetMainWnd(), SW_HIDE);
	Aorus()->PostMessage(WM_SYN_MOBILESTATE, 0, 0);

}

void CKBLedDlg::ApplyLedSetting(int nCard, LED_SETTING& led, bool bSyncLed, bool bSave /*false: store in memory*/)
{
	if (bSyncLed)
	{
		return SyncLedSetting(led, true);
	}

	if (IsSyncLed())
	{
		return; // Control by GvLedService.exe now. DO NOTHING.
	}

	CDevice* pCurDevice = NULL;
	for(int i = 0; i < DEVICE_COUNT; i++)
	{
		CDevice* pDevice = Aorus()->GetDevice(s_DevIds[i]);
		if (pDevice->GetDeviceId() != m_nDevice)
			continue;
		pCurDevice = pDevice; break;
	}
	ASSERT(NULL != pCurDevice);
	return pCurDevice->SetLedSetting(nCard, m_nProfileSel, led, bSave);   

	Aorus()->PostMessage(WM_SYN_MOBILESTATE, 0, 0);
}

