// KBLedCyclingDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AORUS.h"
#include "KBLedCyclingDlg.h"
#include "AORUSDlg.h"

#define LKEY_KBLEDS5_BRIGHTNESS	0
#define LKEY_KBLEDS5_SPEED		1
#define LKEY_KBLEDS5_QTY		2

int CKBLedCyclingDlg::s_nWords = LKEY_KBLEDS5_QTY;
LANG_WORD CKBLedCyclingDlg::s_Words[48] = 
{
	LANG_WORD(LKEY_KBLEDS5_BRIGHTNESS,	_T("亮度"), _T("亮度"), _T("BRIGHTNESS")),
	LANG_WORD(LKEY_KBLEDS5_SPEED,		_T("速度"), _T("速度"), _T("SPEED")),
};

IMPLEMENT_DYNAMIC(CKBLedCyclingDlg, CUiDlg)

CKBLedCyclingDlg::CKBLedCyclingDlg(CWnd* pParent /*=NULL*/)
	: CUiDlg(CKBLedCyclingDlg::IDD, pParent)
{
}

CKBLedCyclingDlg::~CKBLedCyclingDlg()
{
}

void CKBLedCyclingDlg::DoDataExchange(CDataExchange* pDX)
{
	CUiDlg::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CKBLedCyclingDlg, CUiDlg)
	ON_MESSAGE(WM_UI_BUTTON_CLICKED, OnUiButtonClicked)
	ON_MESSAGE(WM_UI_SLIDER_MOVED, OnUiSliderMoved)
	ON_MESSAGE(WM_UI_SLIDER_MOVING, OnUiSliderMoving)
	ON_MESSAGE(WM_UI_MULITSLIDER_MOVED, OnUiSliderMoved)
	ON_MESSAGE(WM_UI_MULITSLIDER_MOVING, OnUiSliderMoving)
	ON_MESSAGE(WM_UI_EDIT_CHANGE, OnUiEditChanged)
END_MESSAGE_MAP()


// CKBLedCyclingDlg message handlers
BOOL CKBLedCyclingDlg::OnInitDialog()
{
	CUiDlg::OnInitDialog();
	Ui();

	return true;
}

void CKBLedCyclingDlg::Ui()
{
	UiMain();
}

void CKBLedCyclingDlg::UiMain()
{
	SetBkBitmap(IDB_KBLED_BGBLACK, 0xff, CLR_NONE);

	UI_STATIC stc[] =
	{
		UI_STATIC(this, STC_KBLEDS5_BRIGHTNESS, CRect(10, 10, 90, 25), CLangX::Get(s_Words, s_nWords, LKEY_KBLEDS5_BRIGHTNESS), NULL, CLR_NONE),
		UI_STATIC(this, STC_KBLEDS5_SPEED,		CRect(10, 30, 90, 45), CLangX::Get(s_Words, s_nWords, LKEY_KBLEDS5_SPEED), NULL, CLR_NONE),
		UI_STATIC(this, STC_KBLEDS5_COLORBG,	CRect( 7, 80,  0,  0), _T(""), IDB_LED_BG_COLOR, CLR_TRPT),
	};
	for (int i = STC_KBLEDS5_BRIGHTNESS;i < STC_KBLEDS5_NUM; i++)
	{
		m_stc[i].CreateStatic(stc[i - (int)STC_KBLEDS5_BRIGHTNESS]);
		m_stc[i].ModifyCtrlStyle(ST_VCENTER, ST_RIGHT);
		m_stc[i].SetFont(Font(11), CLR_MAIN);
	}

	UI_BTN btn[] = 
	{
		UI_BTN(&m_stc[STC_KBLEDS5_COLORBG], BTN_KBLEDS5_COLOR_1,   CRect(  9, 3,  24, 18), &UIBTN_IMAGE(0,	0,	0,	0)),
		UI_BTN(&m_stc[STC_KBLEDS5_COLORBG], BTN_KBLEDS5_COLOR_2,   CRect( 34, 3,  49, 18), &UIBTN_IMAGE(0,	0,	0,	0)),
		UI_BTN(&m_stc[STC_KBLEDS5_COLORBG], BTN_KBLEDS5_COLOR_3,   CRect( 59, 3,  74, 18), &UIBTN_IMAGE(0,	0,	0,	0)),
		UI_BTN(&m_stc[STC_KBLEDS5_COLORBG], BTN_KBLEDS5_COLOR_4,   CRect( 83, 3,  98, 18), &UIBTN_IMAGE(0,	0,	0,	0)),
		UI_BTN(&m_stc[STC_KBLEDS5_COLORBG], BTN_KBLEDS5_COLOR_5,   CRect(108, 3, 123, 18), &UIBTN_IMAGE(0,	0,	0,	0)),
		UI_BTN(&m_stc[STC_KBLEDS5_COLORBG], BTN_KBLEDS5_COLOR_6,   CRect(133, 3, 148, 18), &UIBTN_IMAGE(0,	0,	0,	0)),
		UI_BTN(&m_stc[STC_KBLEDS5_COLORBG], BTN_KBLEDS5_COLOR_7,   CRect(158, 3, 174, 18), &UIBTN_IMAGE(0,	0,	0,	0)),
		UI_BTN(&m_stc[STC_KBLEDS5_COLORBG], BTN_KBLEDS5_COLOR_8,   CRect(182, 3, 197, 18), &UIBTN_IMAGE(0,	0,	0,	0)),
		UI_BTN(&m_stc[STC_KBLEDS5_COLORBG], BTN_KBLEDS5_COLOR_9,   CRect(207, 3, 222, 18), &UIBTN_IMAGE(0,	0,	0,	0)),
	};

	for(int i = BTN_KBLEDS5_COLOR_1; i < BTN_KBLEDS5_NUM; i++)
	{
		m_btn[i].CreateButton(btn[i - (int)BTN_KBLEDS5_COLOR_1]);
		m_btn[i].SetCursor(IDC_CUR_HAND);
	}

	m_edit[EDIT_KBLEDS5_R].Create(WS_CHILD | WS_VISIBLE | WS_TABSTOP | ES_AUTOHSCROLL | ES_CENTER, CRect(23, 67, 52, 79), &m_stc[STC_KBLEDS5_COLORBG], EDIT_KBLEDS5_R);
	m_edit[EDIT_KBLEDS5_R].SetFont(Font(9), CLR_WHITE);
	m_edit[EDIT_KBLEDS5_R].SetBkColor(CLR_DARK);
	m_edit[EDIT_KBLEDS5_R].SetAsIntNumberEdit(3);

	m_edit[EDIT_KBLEDS5_G].Create(WS_CHILD | WS_VISIBLE | WS_TABSTOP | ES_AUTOHSCROLL | ES_CENTER, CRect(75, 67, 104, 79), &m_stc[STC_KBLEDS5_COLORBG], EDIT_KBLEDS5_G);
	m_edit[EDIT_KBLEDS5_G].SetFont(Font(9), CLR_WHITE);
	m_edit[EDIT_KBLEDS5_G].SetBkColor(CLR_DARK);
	m_edit[EDIT_KBLEDS5_G].SetAsIntNumberEdit(3);

	m_edit[EDIT_KBLEDS5_B].Create(WS_CHILD | WS_VISIBLE | WS_TABSTOP | ES_AUTOHSCROLL | ES_CENTER, CRect(126, 67, 156, 79), &m_stc[STC_KBLEDS5_COLORBG], EDIT_KBLEDS5_B);
	m_edit[EDIT_KBLEDS5_B].SetFont(Font(9), CLR_WHITE);
	m_edit[EDIT_KBLEDS5_B].SetBkColor(CLR_DARK);
	m_edit[EDIT_KBLEDS5_B].SetAsIntNumberEdit(3);

	m_slider[SLIDER_KBLEDS5_SPEED].CreateSliderCtrl(UI_SLIDERCTRL(this, SLIDER_KBLEDS5_SPEED,	CRect(99,  10,  0,  0), IDB_SLIDERBAR_ON, IDB_SLIDERBAR_ON, IDB_SLIDERBAR_OFF, IDB_SLIDERBG_OFF, IDB_SLIDERBG_ON, IDB_SLIDERBG_OFF, CLR_TRPT));
	m_slider[SLIDER_KBLEDS5_BRGIHTNESS].CreateSliderCtrl(UI_SLIDERCTRL(this, SLIDER_KBLEDS5_BRGIHTNESS, CRect(99,  30,  0,  0), IDB_SLIDERBAR_ON, IDB_SLIDERBAR_ON, IDB_SLIDERBAR_OFF, IDB_SLIDERBG_OFF, IDB_SLIDERBG_ON, IDB_SLIDERBG_OFF, CLR_TRPT));
	m_slider[SLIDER_KBLEDS5_RGB].CreateSliderCtrl(UI_SLIDERCTRL(&m_stc[STC_KBLEDS5_COLORBG], SLIDER_KBLEDS5_RGB,	CRect(2, 32, 229, 49), IDB_SLIDER_RGBBAR, IDB_SLIDER_RGBBAR, 0, 0, 0, 0, CLR_TRPT));
	
	m_slider[SLIDER_KBLEDS5_RGB].SetRange(0, 359);
	m_slider[SLIDER_KBLEDS5_SPEED].SetRange(0, 10);
	m_slider[SLIDER_KBLEDS5_BRGIHTNESS].SetRange(0 ,100);
	OnColor(RGB(255, 0, 0));
}

LRESULT CKBLedCyclingDlg::OnUiButtonClicked(WPARAM wParam, LPARAM lParam)
{
	switch(wParam)
	{
	case BTN_KBLEDS5_COLOR_1: case BTN_KBLEDS5_COLOR_2: 
	case BTN_KBLEDS5_COLOR_3: case BTN_KBLEDS5_COLOR_4: 
	case BTN_KBLEDS5_COLOR_5: case BTN_KBLEDS5_COLOR_6:
	case BTN_KBLEDS5_COLOR_7: case BTN_KBLEDS5_COLOR_8: 
	case BTN_KBLEDS5_COLOR_9: {
			COLORREF color = s_clr[wParam - BTN_KBLEDS5_COLOR_1];
			OnColor(color);
		} break;
	 }

	return 1;
}

LRESULT CKBLedCyclingDlg::OnUiSliderMoved(WPARAM wParam, LPARAM lParam)
 {
	int nCurValue = (int)lParam;
	switch(wParam)
	{
	case SLIDER_KBLEDS5_RGB: { 
			COLORREF clr = HSBToRGB((float)nCurValue);
			OnColor(clr);
		} break;
	case SLIDER_KBLEDS5_BRGIHTNESS: break;
	case SLIDER_KBLEDS5_SPEED: break;
	}

	return 1;
 }

LRESULT CKBLedCyclingDlg::OnUiSliderMoving(WPARAM wParam, LPARAM lParam)
{
	int nCurValue = (int)lParam;
	switch (wParam)
	{	
		case SLIDER_KBLEDS5_RGB: OnColor(HSBToRGB((float)nCurValue)); break;
	}
	return 1;
}

LRESULT CKBLedCyclingDlg::OnUiEditChanged(WPARAM wParam, LPARAM lParam)
{
	switch(wParam)
	{
	case EDIT_KBLEDS5_R: case EDIT_KBLEDS5_G: case EDIT_KBLEDS5_B: {
			CString sR, sG, sB;
			m_edit[wParam].GetWindowText(sR);
			if(_ttoi(sR) < 0) sR.Format(_T("%03d"), 0);
			if(_ttoi(sR) > 255) sR.Format(_T("%03d"), 255);
			m_edit[wParam].SetWindowText(sR);
			m_edit[EDIT_KBLEDS5_R].GetWindowText(sR);
			m_edit[EDIT_KBLEDS5_G].GetWindowText(sG);
			m_edit[EDIT_KBLEDS5_B].GetWindowText(sB);
		} break;
	}
	return 1;
}

void CKBLedCyclingDlg::OnColor(COLORREF clr)
{
	 double r = GetRValue(clr);
	 double g = GetGValue(clr);
	 double b = GetBValue(clr);
	 m_edit[EDIT_KBLEDS5_R].SetWindowsValue(r);
	 m_edit[EDIT_KBLEDS5_G].SetWindowsValue(g);
	 m_edit[EDIT_KBLEDS5_B].SetWindowsValue(b);
	 m_slider[SLIDER_KBLEDS5_RGB].SetPos((int)RGBtoHSB(clr));

	if (r == 255 && g == 0 && b == 255) { b -= 1; clr = RGB(r, g, b); }
}

BOOL CKBLedCyclingDlg::PreTranslateMessage(MSG* pMsg)
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
	case EDIT_KBLEDS5_R: case EDIT_KBLEDS5_G: case EDIT_KBLEDS5_B: 
		EditRGBChange(); return TRUE;
	}

	return CUiDlg::PreTranslateMessage(pMsg);
}

void CKBLedCyclingDlg::EditRGBChange()
{
	CString sR, sG, sB;

	m_edit[EDIT_KBLEDS5_R].GetWindowText(sR);
	if(_ttoi(sR) < 0) sR.Format(_T("%03d"), 0);
	if(_ttoi(sR) > 255) sR.Format(_T("%03d"), 255);
	m_edit[EDIT_KBLEDS5_R].SetWindowText(sR);

	m_edit[EDIT_KBLEDS5_G].GetWindowText(sG);
	if(_ttoi(sG) < 0) sG.Format(_T("%03d"), 0);
	if(_ttoi(sG) > 255) sG.Format(_T("%03d"), 255);
	m_edit[EDIT_KBLEDS5_G].SetWindowText(sG);

	m_edit[EDIT_KBLEDS5_B].GetWindowText(sB);
	if(_ttoi(sB) < 0) sB.Format(_T("%03d"), 0);
	if(_ttoi(sB) > 255) sB.Format(_T("%03d"), 255);
	m_edit[EDIT_KBLEDS5_B].SetWindowText(sB);

	m_slider[SLIDER_KBLEDS5_RGB].SetPos((int)RGBtoHSB(RGB(_ttoi(sR), _ttoi(sG), _ttoi(sB))));
}