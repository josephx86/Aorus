// KBLedRippleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AORUS.h"
#include "KBLedRippleDlg.h"
#include "AORUSDlg.h"

#define LKEY_KBLEDS4_BRIGHTNESS	0
#define LKEY_KBLEDS4_SPEED		1
#define LKEY_KBLEDS4_QTY		2

int CKBLedRippleDlg::s_nWords = LKEY_KBLEDS4_QTY;
LANG_WORD CKBLedRippleDlg::s_Words[48] = 
{
	LANG_WORD(LKEY_KBLEDS4_BRIGHTNESS,	_T("亮度"), _T("亮度"), _T("BRIGHTNESS")),
	LANG_WORD(LKEY_KBLEDS4_SPEED,		_T("速度"), _T("速度"), _T("SPEED")),
};

IMPLEMENT_DYNAMIC(CKBLedRippleDlg, CUiDlg)

CKBLedRippleDlg::CKBLedRippleDlg(CWnd* pParent /*=NULL*/)
	: CUiDlg(CKBLedRippleDlg::IDD, pParent)
{
}

CKBLedRippleDlg::~CKBLedRippleDlg()
{
}

void CKBLedRippleDlg::DoDataExchange(CDataExchange* pDX)
{
	CUiDlg::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CKBLedRippleDlg, CUiDlg)
	ON_MESSAGE(WM_UI_BUTTON_CLICKED, OnUiButtonClicked)
	ON_MESSAGE(WM_UI_SLIDER_MOVED, OnUiSliderMoved)
	ON_MESSAGE(WM_UI_SLIDER_MOVING, OnUiSliderMoving)
	ON_MESSAGE(WM_UI_MULITSLIDER_MOVED, OnUiSliderMoved)
	ON_MESSAGE(WM_UI_MULITSLIDER_MOVING, OnUiSliderMoving)
	ON_MESSAGE(WM_UI_EDIT_CHANGE, OnUiEditChanged)
END_MESSAGE_MAP()


// CKBLedRippleDlg message handlers
BOOL CKBLedRippleDlg::OnInitDialog()
{
	CUiDlg::OnInitDialog();
	Ui();

	return true;
}

void CKBLedRippleDlg::Ui()
{
	UiMain();
}

void CKBLedRippleDlg::UiMain()
{
	SetBkBitmap(IDB_KBLED_BGBLACK, 0xff, CLR_NONE);

	UI_STATIC stc[] =
	{
		UI_STATIC(this, STC_KBLEDS4_BRIGHTNESS, CRect(10, 10, 90, 25), CLangX::Get(s_Words, s_nWords, LKEY_KBLEDS4_BRIGHTNESS), NULL, CLR_NONE),
		UI_STATIC(this, STC_KBLEDS4_SPEED,		CRect(10, 30, 90, 45), CLangX::Get(s_Words, s_nWords, LKEY_KBLEDS4_SPEED), NULL, CLR_NONE),
		UI_STATIC(this, STC_KBLEDS4_COLORBG,	CRect( 7, 80,  0,  0), _T(""), IDB_LED_BG_COLOR, CLR_TRPT),
	};
	for (int i = STC_KBLEDS4_BRIGHTNESS;i < STC_KBLEDS4_NUM; i++)
	{
		m_stc[i].CreateStatic(stc[i - (int)STC_KBLEDS4_BRIGHTNESS]);
		m_stc[i].ModifyCtrlStyle(ST_VCENTER, ST_RIGHT);
		m_stc[i].SetFont(Font(11), CLR_MAIN);
	}

	UI_BTN btn[] = 
	{
		UI_BTN(&m_stc[STC_KBLEDS4_COLORBG], BTN_KBLEDS4_COLOR_1,   CRect(  9, 3,  24, 18), &UIBTN_IMAGE(0,	0,	0,	0)),
		UI_BTN(&m_stc[STC_KBLEDS4_COLORBG], BTN_KBLEDS4_COLOR_2,   CRect( 34, 3,  49, 18), &UIBTN_IMAGE(0,	0,	0,	0)),
		UI_BTN(&m_stc[STC_KBLEDS4_COLORBG], BTN_KBLEDS4_COLOR_3,   CRect( 59, 3,  74, 18), &UIBTN_IMAGE(0,	0,	0,	0)),
		UI_BTN(&m_stc[STC_KBLEDS4_COLORBG], BTN_KBLEDS4_COLOR_4,   CRect( 83, 3,  98, 18), &UIBTN_IMAGE(0,	0,	0,	0)),
		UI_BTN(&m_stc[STC_KBLEDS4_COLORBG], BTN_KBLEDS4_COLOR_5,   CRect(108, 3, 123, 18), &UIBTN_IMAGE(0,	0,	0,	0)),
		UI_BTN(&m_stc[STC_KBLEDS4_COLORBG], BTN_KBLEDS4_COLOR_6,   CRect(133, 3, 148, 18), &UIBTN_IMAGE(0,	0,	0,	0)),
		UI_BTN(&m_stc[STC_KBLEDS4_COLORBG], BTN_KBLEDS4_COLOR_7,   CRect(158, 3, 174, 18), &UIBTN_IMAGE(0,	0,	0,	0)),
		UI_BTN(&m_stc[STC_KBLEDS4_COLORBG], BTN_KBLEDS4_COLOR_8,   CRect(182, 3, 197, 18), &UIBTN_IMAGE(0,	0,	0,	0)),
		UI_BTN(&m_stc[STC_KBLEDS4_COLORBG], BTN_KBLEDS4_COLOR_9,   CRect(207, 3, 222, 18), &UIBTN_IMAGE(0,	0,	0,	0)),
	};

	for(int i = BTN_KBLEDS4_COLOR_1; i < BTN_KBLEDS4_NUM; i++)
	{
		m_btn[i].CreateButton(btn[i - (int)BTN_KBLEDS4_COLOR_1]);
		m_btn[i].SetCursor(IDC_CUR_HAND);
	}

	m_edit[EDIT_KBLEDS4_R].Create(WS_CHILD | WS_VISIBLE | WS_TABSTOP | ES_AUTOHSCROLL | ES_CENTER, CRect(23, 67, 52, 79), &m_stc[STC_KBLEDS4_COLORBG], EDIT_KBLEDS4_R);
	m_edit[EDIT_KBLEDS4_R].SetFont(Font(9), CLR_WHITE);
	m_edit[EDIT_KBLEDS4_R].SetBkColor(CLR_DARK);
	m_edit[EDIT_KBLEDS4_R].SetAsIntNumberEdit(3);

	m_edit[EDIT_KBLEDS4_G].Create(WS_CHILD | WS_VISIBLE | WS_TABSTOP | ES_AUTOHSCROLL | ES_CENTER, CRect(75, 67, 104, 79), &m_stc[STC_KBLEDS4_COLORBG], EDIT_KBLEDS4_G);
	m_edit[EDIT_KBLEDS4_G].SetFont(Font(9), CLR_WHITE);
	m_edit[EDIT_KBLEDS4_G].SetBkColor(CLR_DARK);
	m_edit[EDIT_KBLEDS4_G].SetAsIntNumberEdit(3);

	m_edit[EDIT_KBLEDS4_B].Create(WS_CHILD | WS_VISIBLE | WS_TABSTOP | ES_AUTOHSCROLL | ES_CENTER, CRect(126, 67, 156, 79), &m_stc[STC_KBLEDS4_COLORBG], EDIT_KBLEDS4_B);
	m_edit[EDIT_KBLEDS4_B].SetFont(Font(9), CLR_WHITE);
	m_edit[EDIT_KBLEDS4_B].SetBkColor(CLR_DARK);
	m_edit[EDIT_KBLEDS4_B].SetAsIntNumberEdit(3);

	m_slider[SLIDER_KBLEDS4_SPEED].CreateSliderCtrl(UI_SLIDERCTRL(this, SLIDER_KBLEDS4_SPEED,	CRect(99,  10,  0,  0), IDB_SLIDERBAR_ON, IDB_SLIDERBAR_ON, IDB_SLIDERBAR_OFF, IDB_SLIDERBG_OFF, IDB_SLIDERBG_ON, IDB_SLIDERBG_OFF, CLR_TRPT));
	m_slider[SLIDER_KBLEDS4_BRGIHTNESS].CreateSliderCtrl(UI_SLIDERCTRL(this, SLIDER_KBLEDS4_BRGIHTNESS, CRect(99,  30,  0,  0), IDB_SLIDERBAR_ON, IDB_SLIDERBAR_ON, IDB_SLIDERBAR_OFF, IDB_SLIDERBG_OFF, IDB_SLIDERBG_ON, IDB_SLIDERBG_OFF, CLR_TRPT));
	m_slider[SLIDER_KBLEDS4_RGB].CreateSliderCtrl(UI_SLIDERCTRL(&m_stc[STC_KBLEDS4_COLORBG], SLIDER_KBLEDS4_RGB,	CRect(2, 32, 229, 49), IDB_SLIDER_RGBBAR, IDB_SLIDER_RGBBAR, 0, 0, 0, 0, CLR_TRPT));
	
	m_slider[SLIDER_KBLEDS4_RGB].SetRange(0, 359);
	m_slider[SLIDER_KBLEDS4_SPEED].SetRange(0, 10);
	m_slider[SLIDER_KBLEDS4_BRGIHTNESS].SetRange(0 ,100);
	OnColor(RGB(255, 0, 0));
}

LRESULT CKBLedRippleDlg::OnUiButtonClicked(WPARAM wParam, LPARAM lParam)
{
	switch(wParam)
	{
	case BTN_KBLEDS4_COLOR_1: case BTN_KBLEDS4_COLOR_2: 
	case BTN_KBLEDS4_COLOR_3: case BTN_KBLEDS4_COLOR_4: 
	case BTN_KBLEDS4_COLOR_5: case BTN_KBLEDS4_COLOR_6:
	case BTN_KBLEDS4_COLOR_7: case BTN_KBLEDS4_COLOR_8: 
	case BTN_KBLEDS4_COLOR_9: {
			COLORREF color = s_clr[wParam - BTN_KBLEDS4_COLOR_1];
			OnColor(color);
		} break;
	 }

	return 1;
}

LRESULT CKBLedRippleDlg::OnUiSliderMoved(WPARAM wParam, LPARAM lParam)
 {
	int nCurValue = (int)lParam;
	switch(wParam)
	{
	case SLIDER_KBLEDS4_RGB: { 
			COLORREF clr = HSBToRGB((float)nCurValue);
			OnColor(clr);
		} break;
	case SLIDER_KBLEDS4_BRGIHTNESS: break;
	case SLIDER_KBLEDS4_SPEED: break;
	}

	return 1;
 }

LRESULT CKBLedRippleDlg::OnUiSliderMoving(WPARAM wParam, LPARAM lParam)
{
	int nCurValue = (int)lParam;
	switch (wParam)
	{	
		case SLIDER_KBLEDS4_RGB: OnColor(HSBToRGB((float)nCurValue)); break;
	}
	return 1;
}

LRESULT CKBLedRippleDlg::OnUiEditChanged(WPARAM wParam, LPARAM lParam)
{
	switch(wParam)
	{
	case EDIT_KBLEDS4_R: case EDIT_KBLEDS4_G: case EDIT_KBLEDS4_B: {
			CString sR, sG, sB;
			m_edit[wParam].GetWindowText(sR);
			if(_ttoi(sR) < 0) sR.Format(_T("%03d"), 0);
			if(_ttoi(sR) > 255) sR.Format(_T("%03d"), 255);
			m_edit[wParam].SetWindowText(sR);
			m_edit[EDIT_KBLEDS4_R].GetWindowText(sR);
			m_edit[EDIT_KBLEDS4_G].GetWindowText(sG);
			m_edit[EDIT_KBLEDS4_B].GetWindowText(sB);
		} break;
	}
	return 1;
}

void CKBLedRippleDlg::OnColor(COLORREF clr)
{
	 double r = GetRValue(clr);
	 double g = GetGValue(clr);
	 double b = GetBValue(clr);
	 m_edit[EDIT_KBLEDS4_R].SetWindowsValue(r);
	 m_edit[EDIT_KBLEDS4_G].SetWindowsValue(g);
	 m_edit[EDIT_KBLEDS4_B].SetWindowsValue(b);
	 m_slider[SLIDER_KBLEDS4_RGB].SetPos((int)RGBtoHSB(clr));

	if (r == 255 && g == 0 && b == 255) { b -= 1; clr = RGB(r, g, b); }
}

BOOL CKBLedRippleDlg::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN && 
		pMsg->wParam == VK_ESCAPE)   
	{
		return TRUE;  // Ignored ESC key
	}
	if (pMsg->message != WM_KEYDOWN || 
		pMsg->wParam != VK_RETURN)
	{
		return CUiDlg::PreTranslateMessage(pMsg);
	}

	// Allow user to change R/G/B value, and press ENTER key to change the color 
 
	DWORD dwID = GetFocus()->GetDlgCtrlID();
	switch(dwID)
	{
	case EDIT_KBLEDS4_R: case EDIT_KBLEDS4_G: case EDIT_KBLEDS4_B: 
		EditRGBChange(); return TRUE;
	}

	return CUiDlg::PreTranslateMessage(pMsg);
}

void CKBLedRippleDlg::EditRGBChange()
{
	CString sR, sG, sB;

	m_edit[EDIT_KBLEDS4_R].GetWindowText(sR);
	if(_ttoi(sR) < 0) sR.Format(_T("%03d"), 0);
	if(_ttoi(sR) > 255) sR.Format(_T("%03d"), 255);
	m_edit[EDIT_KBLEDS4_R].SetWindowText(sR);

	m_edit[EDIT_KBLEDS4_G].GetWindowText(sG);
	if(_ttoi(sG) < 0) sG.Format(_T("%03d"), 0);
	if(_ttoi(sG) > 255) sG.Format(_T("%03d"), 255);
	m_edit[EDIT_KBLEDS4_G].SetWindowText(sG);

	m_edit[EDIT_KBLEDS4_B].GetWindowText(sB);
	if(_ttoi(sB) < 0) sB.Format(_T("%03d"), 0);
	if(_ttoi(sB) > 255) sB.Format(_T("%03d"), 255);
	m_edit[EDIT_KBLEDS4_B].SetWindowText(sB);

	m_slider[SLIDER_KBLEDS4_RGB].SetPos((int)RGBtoHSB(RGB(_ttoi(sR), _ttoi(sG), _ttoi(sB))));
}