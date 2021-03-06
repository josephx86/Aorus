// VgaProfDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AORUS.h"
#include "VgaProfDlg.h"
#include "AorusDlg.h"


IMPLEMENT_DYNAMIC(CVgaProfDlg, CUiDlg)

CVgaProfDlg::CVgaProfDlg(CWnd* pParent /*=NULL*/)
	: CUiDlg(CVgaProfDlg::IDD, pParent)
{
    m_CurSelProfile=0;
}

CVgaProfDlg::~CVgaProfDlg()
{
}

void CVgaProfDlg::DoDataExchange(CDataExchange* pDX)
{
	CUiDlg::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CVgaProfDlg, CUiDlg)
	ON_MESSAGE(WM_UI_BUTTON_CLICKED, OnUiButtonClicked)
	ON_MESSAGE(WM_UI_SLIDER_MOVED, OnUiSliderMoved)
	ON_MESSAGE(WM_UI_SLIDER_MOVING, OnUiSliderMoving)
	ON_MESSAGE(WM_UI_LIST_CLK, OnUiListClick)
	ON_MESSAGE(WM_UI_LIST_EDITED,OnUiListEdited)
	ON_MESSAGE(WM_FANTOP_BTN_CHANGE,OnFanStopStateChange)
END_MESSAGE_MAP()


// CVgaProfDlg message handlers
BOOL CVgaProfDlg::OnInitDialog()
{
	CUiDlg::OnInitDialog();
	Ui();
	return true;
}

void CVgaProfDlg::Ui()
{
	UiMain();
}

void CVgaProfDlg::UiMain()
{
	SetBkBitmap(Aorus()->GetVGA()->Ctrl()->IsNvCard() ? IDB_VGA_PROF_NBG : IDB_VGA_PROF_BG, 0xff, CLR_TRPT); // 设置背景图;

	UI_BTN btn[] = 
	{

		UI_BTN(this, BTN_VGAPROF_GPUCLK_DEC,   CRect(159, 29,  0,0), &UIBTN_IMAGE(IDB_BTN_DEC_ON, IDB_BTN_DEC_ON, IDB_BTN_DEC_ON, 0, CLR_TRPT)),
		UI_BTN(this, BTN_VGAPROF_GPUCLK_INC,   CRect(432,  29, 0,  0), &UIBTN_IMAGE(IDB_BTN_INC_ON,	IDB_BTN_INC_ON,	IDB_BTN_INC_ON,	0, CLR_TRPT)),
		UI_BTN(this, BTN_VGAPROF_MEMCLK_DEC,   CRect(159, 76,  0, 0), &UIBTN_IMAGE(IDB_BTN_DEC_ON, IDB_BTN_DEC_ON, IDB_BTN_DEC_ON, 0, CLR_TRPT)),
		UI_BTN(this, BTN_VGAPROF_MEMCLK_INC,   CRect(432, 76,  0, 0), &UIBTN_IMAGE(IDB_BTN_INC_ON,	IDB_BTN_INC_ON,	IDB_BTN_INC_ON,	0, CLR_TRPT)),
		UI_BTN(this, BTN_VGAPROF_GPUVOL_DEC,   CRect(159, 124,  0, 0),  &UIBTN_IMAGE(IDB_BTN_DEC_ON, IDB_BTN_DEC_ON, IDB_BTN_DEC_ON, 0, CLR_TRPT)),
		UI_BTN(this, BTN_VGAPROF_GPUVOL_INC,   CRect(432, 124, 0, 0), &UIBTN_IMAGE(IDB_BTN_INC_ON,	IDB_BTN_INC_ON,	IDB_BTN_INC_ON,	0, CLR_TRPT)),
		UI_BTN(this, BTN_VGAPROF_FANSPD_DEC,   CRect(159, 172, 0, 0),  &UIBTN_IMAGE(IDB_BTN_DEC_ON, IDB_BTN_DEC_ON, IDB_BTN_DEC_ON, 0, CLR_TRPT)),
		UI_BTN(this, BTN_VGAPROF_FANSPD_INC,   CRect(432, 172, 0, 0), &UIBTN_IMAGE(IDB_BTN_INC_ON,	IDB_BTN_INC_ON,	IDB_BTN_INC_ON,	0, CLR_TRPT)),
		UI_BTN(this, BTN_VGAPROF_PWRTAR_DEC,   CRect(159, 219, 0, 0),  &UIBTN_IMAGE(IDB_BTN_DEC_ON, IDB_BTN_DEC_ON, IDB_BTN_DEC_ON, 0, CLR_TRPT)),
		UI_BTN(this, BTN_VGAPROF_PWRTAR_INC,   CRect(432, 219, 0,  0), &UIBTN_IMAGE(IDB_BTN_INC_ON,	IDB_BTN_INC_ON,	IDB_BTN_INC_ON,	0, CLR_TRPT)),
		UI_BTN(this, BTN_VGAPROF_TARTEM_DEC,   CRect(159, 263,  0,0), &UIBTN_IMAGE(IDB_BTN_DEC_ON, IDB_BTN_DEC_ON, IDB_BTN_DEC_ON, 0, CLR_TRPT)),
		UI_BTN(this, BTN_VGAPROF_TARTEM_INC,   CRect(431, 263,  0,0), &UIBTN_IMAGE(IDB_BTN_INC_ON,	IDB_BTN_INC_ON,	IDB_BTN_INC_ON,	0, CLR_TRPT)),
		UI_BTN(this, BTN_VGAPROF_ADDFILE,   CRect( 46, 104, 0,  0), &UIBTN_IMAGE(IDB_VGAPRO_ADDFILE, IDB_VGAPRO_ADDFILE, IDB_VGAPRO_ADDFILE,0, CLR_TRPT)),
		UI_BTN(this, BTN_VGAPROF_DELFILE,   CRect( 73, 104, 0,  0), &UIBTN_IMAGE(IDB_VGAPRO_DELETEFILE, IDB_VGAPRO_DELETEFILE, IDB_VGAPRO_DELETEFILE,0, CLR_TRPT)),
		UI_BTN(this, BTN_VGAPROF_SAVEFILE,  CRect(101, 104, 0,  0), &UIBTN_IMAGE(IDB_VGAPRO_SAVEFILE, IDB_VGAPRO_SAVEFILE, IDB_VGAPRO_SAVEFILE,0, CLR_TRPT)),
		UI_BTN(this, BTN_VGAPROF_GPULOCK,   CRect(139, 110,  0,0),&UIBTN_IMAGE(0, 0, 0, 0, IDB_VGAPRO_UNLOCK_ON, IDB_VGAPRO_UNLOCK_ON, IDB_VGAPRO_UNLOCK_ON, 0, CLR_TRPT), NULL, BTN_CHECK),		
		UI_BTN(this, BTN_VGAPROF_LINK,      CRect(141, 235,  0,0),&UIBTN_IMAGE(IDB_VGAPRO_UNLINK_ON, IDB_VGAPRO_UNLINK_ON, IDB_VGAPRO_UNLINK_ON, 0, IDB_VGAPRO_LINK_ON, IDB_VGAPRO_LINK_ON, IDB_VGAPRO_LINK_ON, 0, CLR_TRPT), NULL, BTN_CHECK),

		UI_BTN(this, BTN_VGAPROF_APPLY,     CRect(  8, 143, 0, 0), &UIBTN_IMAGE(IDB_BTN_ON, IDB_BTN_ON, IDB_BTN_ON,   0,  0, 0, 0, 0, CLR_TRPT),&UIBTN_STRING(CLangX::Get(LANG_VGAPRO_APPLY),	CLR_WHITE, CLR_WHITE,CLR_WHITE,0,Font(11))),
		UI_BTN(this, BTN_VGAPROF_RESET,     CRect(  8, 171, 0, 0), &UIBTN_IMAGE(IDB_BTN_ON, IDB_BTN_ON, IDB_BTN_ON,   0,  0, 0, 0, 0, CLR_TRPT),&UIBTN_STRING(CLangX::Get(LANG_VGAPRO_RESET),	CLR_WHITE, CLR_WHITE,CLR_WHITE,0,Font(11))),
		UI_BTN(this, BTN_VGAPROF_DEFAULT,   CRect(  8, 199, 0, 0), &UIBTN_IMAGE(IDB_BTN_ON, IDB_BTN_ON, IDB_BTN_ON,   0,  0, 0, 0, 0, CLR_TRPT),&UIBTN_STRING(CLangX::Get(LANG_VGAPRO_DEFAULT),	CLR_WHITE, CLR_WHITE,CLR_WHITE,0,Font(11))),
		UI_BTN(this, BTN_VGAPROF_GPUCUST,   CRect(349,  12,  0, 0),&UIBTN_IMAGE(IDB_MIDDLEBTN_OFF, IDB_MIDDLEBTN_OFF, IDB_MIDDLEBTN_OFF, IDB_MIDDLEBTN_OFF, IDB_MIDDLEBTN_ON, IDB_MIDDLEBTN_ON, IDB_MIDDLEBTN_ON, IDB_MIDDLEBTN_OFF, CLR_TRPT),&UIBTN_STRING(CLangX::Get(LANG_VGAPRO_GPUCUSTOM),	CLR_WHITE, CLR_WHITE,CLR_WHITE,0,Font(8)), BTN_CHECK),
		UI_BTN(this, BTN_VGAPROF_FANAUTO,   CRect(243, 154,  0, 0),&UIBTN_IMAGE(IDB_SMALLBTN_OFF, IDB_SMALLBTN_OFF, IDB_SMALLBTN_OFF, IDB_SMALLBTN_OFF, IDB_SMALLBTN_ON, IDB_SMALLBTN_ON, IDB_SMALLBTN_ON, IDB_SMALLBTN_OFF, CLR_TRPT),&UIBTN_STRING(CLangX::Get(LANG_VGAPRO_FANAUTO),	CLR_WHITE, CLR_WHITE,CLR_WHITE,0,Font(8)), BTN_RADIO),
	    UI_BTN(this, BTN_VGAPROF_FANMANUAL, CRect(296, 154,  0, 0),&UIBTN_IMAGE(IDB_SMALLBTN_OFF, IDB_SMALLBTN_OFF, IDB_SMALLBTN_OFF, IDB_SMALLBTN_OFF, IDB_SMALLBTN_ON, IDB_SMALLBTN_ON, IDB_SMALLBTN_ON, IDB_SMALLBTN_OFF, CLR_TRPT),&UIBTN_STRING(CLangX::Get(LANG_VGAPRO_FANMANUAL),	CLR_WHITE, CLR_WHITE,CLR_WHITE,0,Font(8)), BTN_RADIO),
	    UI_BTN(this, BTN_VGAPROF_FANCUST,   CRect(349, 154,  0, 0),&UIBTN_IMAGE(IDB_MIDDLEBTN_OFF, IDB_MIDDLEBTN_OFF, IDB_MIDDLEBTN_OFF, IDB_MIDDLEBTN_OFF, IDB_MIDDLEBTN_ON, IDB_MIDDLEBTN_ON, IDB_MIDDLEBTN_ON, IDB_MIDDLEBTN_OFF, CLR_TRPT),&UIBTN_STRING(CLangX::Get(LANG_VGAPRO_FANCUSTOM),	CLR_WHITE, CLR_WHITE,CLR_WHITE,0,Font(8)), BTN_RADIO)
	
	};
	for(int i=BTN_VGAPROF_GPUCLK_DEC; i <= BTN_VGAPROF_FANCUST; i++)
	{
		m_btn[i].CreateButton(btn[i - (int)BTN_VGAPROF_GPUCLK_DEC]);
		m_btn[i].SetCursor(IDC_CUR_HAND);
	}
	m_btn[BTN_VGAPROF_FANAUTO].SetCheck(true);

    UI_SLIDERCTRL sld[]=
	{
		UI_SLIDERCTRL(this, SLIDER_VGAPROF_GPUCLK,	CRect(170,  29,  0,  0), IDB_SLIDERBAR_ON, IDB_SLIDERBAR_ON, IDB_SLIDERBAR_OFF, IDB_PROFESSIONAL_SLIDER_BGOFF, IDB_VGAPRO_SLDBG_ON, IDB_PROFESSIONAL_SLIDER_BGOFF, CLR_TRPT),
		UI_SLIDERCTRL(this, SLIDER_VGAPROF_MEMCLK,	CRect(170,  76,  0,  0), IDB_SLIDERBAR_ON, IDB_SLIDERBAR_ON, IDB_SLIDERBAR_OFF, IDB_PROFESSIONAL_SLIDER_BGOFF, IDB_VGAPRO_SLDBG_ON, IDB_PROFESSIONAL_SLIDER_BGOFF, CLR_TRPT),
		UI_SLIDERCTRL(this, SLIDER_VGAPROF_GPUVOL,	CRect(170,  124,  0,  0), IDB_SLIDERBAR_ON, IDB_SLIDERBAR_ON, IDB_SLIDERBAR_OFF, IDB_PROFESSIONAL_SLIDER_BGOFF, IDB_VGAPRO_SLDBG_ON, IDB_PROFESSIONAL_SLIDER_BGOFF, CLR_TRPT),
		UI_SLIDERCTRL(this, SLIDER_VGAPROF_FANSPD,	CRect(170,  171,  0,  0), IDB_SLIDERBAR_ON, IDB_SLIDERBAR_ON, IDB_SLIDERBAR_OFF, IDB_PROFESSIONAL_SLIDER_BGOFF, IDB_VGAPRO_SLDBG_ON, IDB_PROFESSIONAL_SLIDER_BGOFF, CLR_TRPT),
		UI_SLIDERCTRL(this, SLIDER_VGAPROF_PWRTAR,	CRect(170,  218,  0,  0), IDB_SLIDERBAR_ON, IDB_SLIDERBAR_ON, IDB_SLIDERBAR_OFF, IDB_PROFESSIONAL_SLIDER_BGOFF, IDB_VGAPRO_SLDBG_ON, IDB_PROFESSIONAL_SLIDER_BGOFF, CLR_TRPT),
		UI_SLIDERCTRL(this, SLIDER_VGAPROF_TARTEM,	CRect(170,  263,  0,  0), IDB_SLIDERBAR_ON, IDB_SLIDERBAR_ON, IDB_SLIDERBAR_OFF, IDB_PROFESSIONAL_SLIDER_BGOFF, IDB_VGAPRO_SLDBG_ON, IDB_PROFESSIONAL_SLIDER_BGOFF, CLR_TRPT)

	};
	for(int i=SLIDER_VGAPROF_GPUCLK;i<=SLIDER_VGAPROF_TARTEM;i++)
	{
        m_slider[i].CreateSliderCtrl(sld[i]);
	}

	UI_STATIC stc[]=
	{
		UI_STATIC(this, STC_VGAPROF_GPUCLK_NAME,	CRect(157,  10, 328,  24), CLangX::Get(LANG_VGAPRO_GPUBOOSTCLK) + L"(MHz)", NULL, CLR_TRPT),
		UI_STATIC(this, STC_VGAPROF_MEMCLK_NAME,	CRect(157,  57, 328,  71), CLangX::Get(LANG_VGAPRO_MEMCLK) + L"(MHz)", NULL, CLR_TRPT),
		UI_STATIC(this, STC_VGAPROF_GPUVOL_NAME,	CRect(157, 105, 328, 119), CLangX::Get(LANG_VGAPRO_GPUVOL ) + L"(%)", NULL, CLR_TRPT),
		UI_STATIC(this, STC_VGAPROF_FANSPD_NAME,	CRect(157, 152, 245, 166), CLangX::Get(LANG_VGAPRO_FANSPD) + L"(%)", NULL, CLR_TRPT),
		UI_STATIC(this, STC_VGAPROF_PWRTAR_NAME,	CRect(157, 199, 328, 213), CLangX::Get(LANG_VGAPRO_PWRTAR) + L"(%)", NULL, CLR_TRPT),
		UI_STATIC(this, STC_VGAPROF_TARTEM_NAME,	CRect(157, 245, 328, 259), CLangX::Get(LANG_VGAPRO_TARTEMP) + L"(°C)", NULL, CLR_TRPT),


		UI_STATIC(this, STC_VGAPROF_GPUCLK_OFFSET,	CRect(450,  12, 490,  24), L"+20", NULL, CLR_TRPT),
		UI_STATIC(this, STC_VGAPROF_MEMCLK_OFFSET,	CRect(450,  59, 490,  71), L"+20", NULL, CLR_TRPT),
		UI_STATIC(this, STC_VGAPROF_GPUVOL_OFFSET,	CRect(450, 107, 490, 119), L"+20", NULL, CLR_TRPT),
		UI_STATIC(this, STC_VGAPROF_FANSPD_OFFSET,	CRect(450, 154, 490, 166), L"+20", NULL, CLR_TRPT),
		UI_STATIC(this, STC_VGAPROF_PWRTAR_OFFSET,	CRect(450, 201, 490, 213), L"+20", NULL, CLR_TRPT),
		UI_STATIC(this, STC_VGAPROF_TARTEM_OFFSET,	CRect(450, 247, 490, 259), L"+20", NULL, CLR_TRPT),

		UI_STATIC(this, STC_VGAPROF_GPUCLK_VALUE,	CRect(450,  27, 490,  41), L"1936", NULL, CLR_TRPT),
		UI_STATIC(this, STC_VGAPROF_MEMCLK_VALUE,	CRect(440,  74, 490,  88), L"1936", NULL, CLR_TRPT),
		UI_STATIC(this, STC_VGAPROF_GPUVOL_VALUE,	CRect(450, 122, 490, 136), L"1936", NULL, CLR_TRPT),
		UI_STATIC(this, STC_VGAPROF_FANSPD_VALUE,	CRect(450, 169, 490, 183), L"1936", NULL, CLR_TRPT),
		UI_STATIC(this, STC_VGAPROF_PWRTAR_VALUE,	CRect(450, 216, 490, 230), L"1936", NULL, CLR_TRPT),
		UI_STATIC(this, STC_VGAPROF_TARTEM_VALUE,	CRect(450, 261, 490, 275), L"1936", NULL, CLR_TRPT),
	};

	for (int i = STC_VGAPROF_GPUCLK_NAME;i <= STC_VGAPROF_TARTEM_NAME;i++)
	{
		m_stc[i].CreateStatic(stc[i]);
		m_stc[i].ModifyCtrlStyle(ST_VCENTER,ST_LEFT);
		m_stc[i].SetFont(Font(11), CLR_MAIN);
	}

	for (int i = STC_VGAPROF_GPUCLK_OFFSET;i <= STC_VGAPROF_TARTEM_OFFSET;i++)
	{
		m_stc[i].CreateStatic(stc[i]);
		m_stc[i].ModifyCtrlStyle(ST_VCENTER,ST_RIGHT);
		m_stc[i].SetFont(Font(9), CLR_WHITE);
	}
	for (int i = STC_VGAPROF_GPUCLK_VALUE;i <= STC_VGAPROF_TARTEM_VALUE;i++)
	{
		m_stc[i].CreateStatic(stc[i]);
		m_stc[i].ModifyCtrlStyle(ST_VCENTER,ST_RIGHT);
		m_stc[i].SetFont(Font(12, true), CLR_WHITE);
	}
	m_stc[STC_VGAPROF_FANSPD_OFFSET].ShowWindow(SW_HIDE);

	m_list[LST_VGAPROF_PROFILE].CreateList(LST_VGAPROF_PROFILE, CRect(9, 27, 118, 96), this, 0, 0,true);
	/*m_list[LST_VGAPROF_PROFILE].SetScrollSliCtrl(
		UI_SLIDERCTRL(&m_list[LST_VGAPROF_PROFILE], 1, CRect(101,  0, 0, 0), IDB_PROFILE_BARBG, IDB_PROFILE_BARBG, 0, IDB_PROFILE_BARBG, IDB_PROFILE_BARBG, 0, CLR_TRPT, WS_CHILD | WS_VISIBLE)
		, UI_BTN(&m_list[LST_VGAPROF_PROFILE], 2, CRect(101,   0, 110, 11), &UIBTN_IMAGE(IDB_PROFILE_LIST_BTNUP,   IDB_PROFILE_LIST_BTNUP,   IDB_PROFILE_LIST_BTNUP,   0))
		, UI_BTN(&m_list[LST_VGAPROF_PROFILE], 3, CRect(101, 59, 110, 70), &UIBTN_IMAGE(IDB_PROFILE_LIST_BTNDOWN, IDB_PROFILE_LIST_BTNDOWN, IDB_PROFILE_LIST_BTNDOWN, 0)));
	*/
	m_list[LST_VGAPROF_PROFILE].SetScrollSliCtrl(
		UI_SLIDERCTRL(&m_list[LST_VGAPROF_PROFILE], 1, CRect(101, 11, 0, 0), IDB_PROFILE_SLIDERBAR, IDB_PROFILE_SLIDERBAR, 0, IDB_PROFILE_SLIDERBG, IDB_PROFILE_SLIDERBG, 0, CLR_TRPT, WS_CHILD | WS_VISIBLE)
		, UI_BTN(&m_list[LST_VGAPROF_PROFILE], 2, CRect(101,   0, 0, 0), &UIBTN_IMAGE(IDB_PROFILE_LIST_BTNUP,   IDB_PROFILE_LIST_BTNUP,   IDB_PROFILE_LIST_BTNUP,   0))
		, UI_BTN(&m_list[LST_VGAPROF_PROFILE], 3, CRect(101, 59, 0, 0), &UIBTN_IMAGE(IDB_PROFILE_LIST_BTNDOWN, IDB_PROFILE_LIST_BTNDOWN, IDB_PROFILE_LIST_BTNDOWN, 0)));
	m_list[LST_VGAPROF_PROFILE].InsertColumn(0, _T("PROFILE ID"), LVCFMT_CENTER);
	m_list[LST_VGAPROF_PROFILE].InsertColumn(1, _T("PROFILE NAME"), LVCFMT_CENTER);
	m_list[LST_VGAPROF_PROFILE].SetColumnWidth(0,  0); // 設置列寬度
	m_list[LST_VGAPROF_PROFILE].SetColumnWidth(1, 110);
	m_list[LST_VGAPROF_PROFILE].SetFont(Font(11));
	//m_list[LST_VGAPROF_PROFILE].SetItemText(m_list.InsertImgItem(0, IDB_MARCO_DELAY), 1, _T("")); 
	m_list[LST_VGAPROF_PROFILE].RemoveImgItem(0);


	CRect rcCustomized,rcMainClient;
	::GetWindowRect(Aorus()->m_hWnd, rcMainClient);
	//m_CustomizedDlg.SetParent(this);
	m_CustomizedDlg.Create(IDD_VGA_CUSTOMIZED_DIALOG, GetDesktopWindow());
	m_CustomizedDlg.GetClientRect(&rcCustomized);
	rcCustomized.MoveToXY(CPoint(1057, 172));
	m_CustomizedDlg.MoveWindow(rcCustomized);
	m_CustomizedDlg.ShowWindow(SW_HIDE);
}


LRESULT CVgaProfDlg::OnUiButtonClicked(WPARAM wParam, LPARAM lParam)
{
	VGA_PARAM_RANGE	gpuClkR;
	VGA_PARAM_RANGE	memClkR;
	VGA_PARAM_RANGE	gpuVolR;
	VGA_PARAM_RANGE	FanSped;
	VGA_PARAM_RANGE	memVolR;
	VGA_PARAM_RANGE	powerR;
	VGA_PARAM_RANGE	tempR;
	Aorus()->GetVGA()->Ctrl()->GetPerfInfo(VGA_PERF_GPUCLK,	gpuClkR);
	Aorus()->GetVGA()->Ctrl()->GetPerfInfo(VGA_PERF_MEMCLK,	memClkR);
	Aorus()->GetVGA()->Ctrl()->GetPerfInfo(VGA_PERF_OVERVOL,	gpuVolR);
	Aorus()->GetVGA()->Ctrl()->GetPerfInfo(VGA_PERF_FANSPD,	FanSped);
	Aorus()->GetVGA()->Ctrl()->GetPerfInfo(VGA_PERF_MEMVOL,	memVolR);
	Aorus()->GetVGA()->Ctrl()->GetPerfInfo(VGA_PERF_POWER,	powerR);
	Aorus()->GetVGA()->Ctrl()->GetPerfInfo(VGA_PERF_TEMPER,	tempR);
	VGA_PERFORMANCE perf;
	switch(wParam)
	{
	case BTN_VGAPROF_GPUCLK_DEC:
	case BTN_VGAPROF_GPUCLK_INC:
		{
			if(!m_btn[BTN_VGAPROF_GPUCUST].IsCheck())
			{
				int value=m_slider[SLIDER_VGAPROF_GPUCLK].GetPos();
				if (Aorus()->GetVGA()->Ctrl()->IsBoost3())
					value = wParam == BTN_VGAPROF_GPUCLK_DEC? ((value<<1)-2):((value<<1)+2);
				else
					value = wParam == BTN_VGAPROF_GPUCLK_DEC? (value-1):(value+1);

				//perf.nGpuClk=wParam==BTN_VGAPROF_GPUCLK_DEC? (--value):(++value);
				perf.nGpuClk=value;
				perf.nGpuClk=perf.nGpuClk>gpuClkR.nMax? gpuClkR.nMax:perf.nGpuClk;
				perf.nGpuClk=perf.nGpuClk<gpuClkR.nMin? gpuClkR.nMin:perf.nGpuClk;
				UpdateProfile(VGA_PERF_GPUCLK,perf);
			}
		}break;
	case BTN_VGAPROF_MEMCLK_DEC:
	case BTN_VGAPROF_MEMCLK_INC:
		{
			int value=m_slider[SLIDER_VGAPROF_MEMCLK].GetPos();
			perf.nMemClk=wParam==BTN_VGAPROF_MEMCLK_DEC? (--value):(++value);
			perf.nMemClk=perf.nMemClk>memClkR.nMax? memClkR.nMax:perf.nMemClk;
			perf.nMemClk=perf.nMemClk<memClkR.nMin? memClkR.nMin:perf.nMemClk;
			UpdateProfile(VGA_PERF_MEMCLK,perf);
			
		}break;
	case BTN_VGAPROF_GPUVOL_DEC:
	case BTN_VGAPROF_GPUVOL_INC:
		{
			if(m_btn[BTN_VGAPROF_GPULOCK].IsCheck())
			{
				int value=m_slider[SLIDER_VGAPROF_GPUVOL].GetPos();
				perf.nGpuVol=wParam==BTN_VGAPROF_GPUVOL_DEC? (--value):(++value);
				perf.nGpuVol=perf.nGpuVol>gpuVolR.nMax? gpuVolR.nMax:perf.nGpuVol;
				perf.nGpuVol=perf.nGpuVol<gpuVolR.nMin? gpuVolR.nMin:perf.nGpuVol;
				UpdateProfile(VGA_PERF_GPUVOL,perf);	
			}
		}break;
	case BTN_VGAPROF_FANSPD_DEC:
	case BTN_VGAPROF_FANSPD_INC:
		{
			if(m_btn[BTN_VGAPROF_FANMANUAL].IsCheck())
			{
			    int value=m_slider[SLIDER_VGAPROF_FANSPD].GetPos();
				perf.nFanSpd=wParam==BTN_VGAPROF_FANSPD_DEC? (--value):(++value);
				perf.nFanSpd=perf.nFanSpd>FanSped.nMax? FanSped.nMax:perf.nFanSpd;
				perf.nFanSpd=perf.nFanSpd<FanSped.nMin? FanSped.nMin:perf.nFanSpd;
				UpdateProfile(VGA_PERF_FANSPD,perf);	    
			}
		}break;
	case BTN_VGAPROF_PWRTAR_DEC:
	case BTN_VGAPROF_PWRTAR_INC:
		{
			int value=m_slider[SLIDER_VGAPROF_PWRTAR].GetPos();
			perf.nPower=wParam==BTN_VGAPROF_PWRTAR_DEC? (--value):(++value);
			perf.nPower=perf.nPower>powerR.nMax? powerR.nMax:perf.nPower;
			perf.nPower=perf.nPower<powerR.nMin? powerR.nMin:perf.nPower;
			UpdateProfile(VGA_PERF_POWER,perf);

		}break;
	case BTN_VGAPROF_TARTEM_DEC:
	case BTN_VGAPROF_TARTEM_INC:
		{
			int value=m_slider[SLIDER_VGAPROF_TARTEM].GetPos();
			perf.nTemperature=wParam==BTN_VGAPROF_TARTEM_DEC? (--value):(++value);
			perf.nTemperature=perf.nTemperature>tempR.nMax? tempR.nMax:perf.nTemperature;
			perf.nTemperature=perf.nTemperature<tempR.nMin? tempR.nMin:perf.nTemperature;
			UpdateProfile(VGA_PERF_TEMPER,perf);
		}break;
	case BTN_VGAPROF_ADDFILE:AddFile();break;
	case BTN_VGAPROF_DELFILE:DeleteFile();break;
	case BTN_VGAPROF_SAVEFILE:SaveFile();break;
	case BTN_VGAPROF_GPULOCK:
		{
			if (m_btn[BTN_VGAPROF_GPULOCK].IsCheck())
			{
				m_btn[BTN_VGAPROF_GPUVOL_DEC].Enable(true);
				m_btn[BTN_VGAPROF_GPUVOL_INC].Enable(true);
				m_slider[SLIDER_VGAPROF_GPUVOL].Enable(true);
			}
			else
			{
				m_btn[BTN_VGAPROF_GPUVOL_DEC].Enable(false);
				m_btn[BTN_VGAPROF_GPUVOL_INC].Enable(false);
				m_slider[SLIDER_VGAPROF_GPUVOL].Enable(false);
			}
		}
		break;

	case BTN_VGAPROF_LINK:break;
	case BTN_VGAPROF_APPLY:OnApply();break;
	case BTN_VGAPROF_RESET:OnReset();break;
	case BTN_VGAPROF_DEFAULT:
		{
			OnUpdateUI(TRUE);
			m_btn[BTN_VGAPROF_GPULOCK].SetCheck(FALSE);
			OnApply();
			m_CustomizedDlg.OnDefault();
		}break;


	case BTN_VGAPROF_FANAUTO:
	case BTN_VGAPROF_FANMANUAL:
	case BTN_VGAPROF_FANCUST:
		{
			m_btn[BTN_VGAPROF_FANAUTO].SetCheck(wParam==BTN_VGAPROF_FANAUTO? true:false);
			m_btn[BTN_VGAPROF_FANMANUAL].SetCheck(wParam==BTN_VGAPROF_FANMANUAL? true:false);
			m_btn[BTN_VGAPROF_FANCUST].SetCheck(wParam==BTN_VGAPROF_FANCUST? true:false);
			m_slider[SLIDER_VGAPROF_FANSPD].Enable(wParam==BTN_VGAPROF_FANMANUAL? true:false);
			m_btn[BTN_VGAPROF_FANSPD_DEC].Enable(wParam==BTN_VGAPROF_FANMANUAL? true : false);
			m_btn[BTN_VGAPROF_FANSPD_INC].Enable(wParam==BTN_VGAPROF_FANMANUAL? true : false);
			if(m_CustomizedDlg.GetType() == CUST_TYPE_FAN) 
			{
				UIShowCustomized(m_btn[BTN_VGAPROF_FANCUST].IsCheck(), 1);
			}
			if(BTN_VGAPROF_FANCUST == wParam && m_btn[BTN_VGAPROF_FANCUST].IsCheck())
			{
				UIShowCustomized(true, 1);
			}
		}
		break;

	case BTN_VGAPROF_GPUCUST:
		{
			if (m_btn[BTN_VGAPROF_GPUCUST].IsCheck())
			{
				UIShowCustomized(true);
				m_slider[SLIDER_VGAPROF_GPUCLK].Enable(false);
				m_btn[BTN_VGAPROF_GPUCLK_DEC].Enable(false);
				m_btn[BTN_VGAPROF_GPUCLK_INC].Enable(false);
			}
			else
			{
				m_slider[SLIDER_VGAPROF_GPUCLK].Enable(true);
				m_btn[BTN_VGAPROF_GPUCLK_DEC].Enable(true);
				m_btn[BTN_VGAPROF_GPUCLK_INC].Enable(true);
			}

			if(m_CustomizedDlg.GetType() == CUST_TYPE_CLK)
			{
				UIShowCustomized(m_btn[BTN_VGAPROF_GPUCUST].IsCheck());
			}
		}
		break;
		
	}
	return 1;
}
LRESULT CVgaProfDlg::OnUiSliderMoved(WPARAM wParam, LPARAM lParam)
{
	return 1;
}
LRESULT CVgaProfDlg::OnUiSliderMoving(WPARAM wParam, LPARAM lParam)
{
	VGA_PERFORMANCE perf;
	switch(wParam)
	{
	case SLIDER_VGAPROF_GPUCLK:
		{
			perf.nGpuClk=lParam;
			UpdateProfile(VGA_PERF_GPUCLK,perf);
		}break;
	case SLIDER_VGAPROF_MEMCLK:
		{
			perf.nMemClk=lParam;
			UpdateProfile(VGA_PERF_MEMCLK,perf);
		}break;
	case SLIDER_VGAPROF_GPUVOL:
		{
			perf.nGpuVol=lParam;
			UpdateProfile(VGA_PERF_GPUVOL,perf);
		}break;
	case SLIDER_VGAPROF_FANSPD:
		{
			perf.nFanSpd=lParam;
			UpdateProfile(VGA_PERF_FANSPD,perf);
		}break;
	case SLIDER_VGAPROF_PWRTAR:
		{
			perf.nPower=lParam;
			UpdateProfile(VGA_PERF_POWER,perf);
		}break;
	case SLIDER_VGAPROF_TARTEM:
		{
			perf.nTemperature=lParam;
			UpdateProfile(VGA_PERF_TEMPER,perf);
		}break;
	}

	return 1;
}

void CVgaProfDlg::InitState()
{
	//Aorus()->GetCfg()->GetFanSocSetting(m_fanManual);
	
	//m_nProfileSel=Aorus()->GetCfg()->GetProfileSel();
	if (!Aorus()->GetVGA()->Ctrl()->IsNvCard())
	{
		m_stc[STC_VGAPROF_GPUCLK_NAME].SetCaption(CLangX::Get(LANG_VGAPRO_GPUAMDCLK));
		m_btn[BTN_VGAPROF_PWRTAR_DEC].ShowWindow(SW_HIDE);
		m_btn[BTN_VGAPROF_PWRTAR_INC].ShowWindow(SW_HIDE);
		m_btn[BTN_VGAPROF_TARTEM_DEC].ShowWindow(SW_HIDE);
		m_btn[BTN_VGAPROF_TARTEM_INC].ShowWindow(SW_HIDE);
		m_btn[BTN_VGAPROF_LINK].ShowWindow(SW_HIDE);
		m_btn[BTN_VGAPROF_GPUCUST].ShowWindow(SW_HIDE);
		m_slider[SLIDER_VGAPROF_PWRTAR].ShowWindow(SW_HIDE);
		m_slider[SLIDER_VGAPROF_TARTEM].ShowWindow(SW_HIDE);
		m_stc[STC_VGAPROF_PWRTAR_NAME].ShowWindow(SW_HIDE);
		m_stc[STC_VGAPROF_TARTEM_NAME].ShowWindow(SW_HIDE);
		m_stc[STC_VGAPROF_PWRTAR_OFFSET].ShowWindow(SW_HIDE);
		m_stc[STC_VGAPROF_TARTEM_OFFSET].ShowWindow(SW_HIDE);
		m_stc[STC_VGAPROF_PWRTAR_VALUE].ShowWindow(SW_HIDE);
		m_stc[STC_VGAPROF_TARTEM_VALUE].ShowWindow(SW_HIDE);
		m_btn[BTN_VGAPROF_GPUVOL_DEC].ShowWindow(SW_HIDE);
		m_btn[BTN_VGAPROF_GPUVOL_INC].ShowWindow(SW_HIDE);
		m_slider[SLIDER_VGAPROF_GPUVOL].ShowWindow(SW_HIDE);
		m_stc[STC_VGAPROF_GPUVOL_NAME].ShowWindow(SW_HIDE);
		m_stc[STC_VGAPROF_GPUVOL_OFFSET].ShowWindow(SW_HIDE);
		m_stc[STC_VGAPROF_GPUVOL_VALUE].ShowWindow(SW_HIDE);

		m_btn[BTN_VGAPROF_FANSPD_DEC].SetWindowPos(NULL, 159, 124, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
		m_btn[BTN_VGAPROF_FANSPD_INC].SetWindowPos(NULL, 432, 124, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
		m_btn[BTN_VGAPROF_FANAUTO].SetWindowPos(NULL, 243, 106, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
		m_btn[BTN_VGAPROF_FANMANUAL].SetWindowPos(NULL, 296, 106, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
		m_btn[BTN_VGAPROF_FANCUST].SetWindowPos(NULL, 349, 106, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
		m_slider[SLIDER_VGAPROF_FANSPD].SetWindowPos(NULL, 170, 124, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
		m_stc[STC_VGAPROF_FANSPD_NAME].SetWindowPos(NULL, 157, 105, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
		m_stc[STC_VGAPROF_FANSPD_OFFSET].SetWindowPos(NULL, 450, 107, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
		m_stc[STC_VGAPROF_FANSPD_VALUE].SetWindowPos(NULL, 450, 122, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	}
	


	Aorus()->GetVGA()->Ctrl()->GetPerformancesDefault(VGA_PERF_ALL, m_perfDefault);
	Aorus()->GetVGA()->Ctrl()->GetSpecialPerformaces(m_specialPerf);
	int ProfileCount=Aorus()->GetCfg()->GetProfileCount(Aorus()->GetVGASel());
	if(ProfileCount>0)
	{
		for (int i=0;i<ProfileCount;i++)
		{//init profile COMBOX
			CString csname;
			Aorus()->GetCfg()->GetProfileName(i,Aorus()->GetVGASel(),csname);
			m_list[LST_VGAPROF_PROFILE].SetItemText(m_list[LST_VGAPROF_PROFILE].InsertImgItem(i, 0), 1,csname);
			m_list[LST_VGAPROF_PROFILE].SetItemData(i,i);
		}
	}
	else
	{
		AddFile();
	}
	m_list[LST_VGAPROF_PROFILE].SetItemState(Aorus()->GetVGAProfileSel(),LVNI_FOCUSED | LVIS_SELECTED, LVNI_FOCUSED | LVIS_SELECTED); 
	//OnUpdateUI();
    if(m_list[LST_VGAPROF_PROFILE].GetItemCount()>Aorus()->GetVGAProfileSel())
	{
		//
	}
	//


	VGA_PARAM_RANGE	gpuClkR;
	VGA_PARAM_RANGE	memClkR;
	VGA_PARAM_RANGE	gpuVolR;
	VGA_PARAM_RANGE	FanSped;
	VGA_PARAM_RANGE	memVolR;
	VGA_PARAM_RANGE	powerR;
	VGA_PARAM_RANGE	tempR;
	Aorus()->GetVGA()->Ctrl()->GetPerfInfo(VGA_PERF_GPUCLK,	gpuClkR);
	Aorus()->GetVGA()->Ctrl()->GetPerfInfo(VGA_PERF_MEMCLK,	memClkR);
	Aorus()->GetVGA()->Ctrl()->GetPerfInfo(VGA_PERF_OVERVOL,	gpuVolR);
	Aorus()->GetVGA()->Ctrl()->GetPerfInfo(VGA_PERF_FANSPD,	FanSped);
	Aorus()->GetVGA()->Ctrl()->GetPerfInfo(VGA_PERF_MEMVOL,	memVolR);
	Aorus()->GetVGA()->Ctrl()->GetPerfInfo(VGA_PERF_POWER,	powerR);
	Aorus()->GetVGA()->Ctrl()->GetPerfInfo(VGA_PERF_TEMPER,	tempR);

	m_slider[SLIDER_VGAPROF_GPUCLK].SetRange(gpuClkR.nMin,gpuClkR.nMax);
	m_slider[SLIDER_VGAPROF_MEMCLK].SetRange(memClkR.nMin,memClkR.nMax);
	m_slider[SLIDER_VGAPROF_GPUVOL].SetRange(gpuVolR.nMin,gpuVolR.nMax);
	m_slider[SLIDER_VGAPROF_FANSPD].SetRange(FanSped.nMin,FanSped.nMax);
	m_slider[SLIDER_VGAPROF_PWRTAR].SetRange(powerR.nMin,powerR.nMax);
	m_slider[SLIDER_VGAPROF_TARTEM].SetRange(tempR.nMin,tempR.nMax);


	VGA_PERFORMANCE perf;
	//Aorus()->GetVGA()->Ctrl()->GetPerformances(VGA_PERF_GPUCLK|VGA_PERF_MEMCLK|VGA_PERF_GPUVOL|VGA_PERF_FANSPD|VGA_PERF_MEMVOL|VGA_PERF_POWER|VGA_PERF_TEMPER,Aorus()->GetVGASel(),perf);
	Aorus()->GetCfg()->GetPerformances(VGA_PERF_ALL,perf,Aorus()->GetVGAProfileSel(),Aorus()->GetVGASel());
	if (Aorus()->GetVGA()->Ctrl()->IsBoost3())
		m_slider[SLIDER_VGAPROF_GPUCLK].SetPos(perf.nGpuClk>>1);
	else
		m_slider[SLIDER_VGAPROF_GPUCLK].SetPos(perf.nGpuClk);
	m_slider[SLIDER_VGAPROF_MEMCLK].SetPos(perf.nMemClk);
	m_slider[SLIDER_VGAPROF_GPUVOL].SetPos(perf.nGpuVol);
	m_slider[SLIDER_VGAPROF_FANSPD].SetPos(perf.nFanSpd);
	m_slider[SLIDER_VGAPROF_PWRTAR].SetPos(perf.nPower);
	m_slider[SLIDER_VGAPROF_TARTEM].SetPos(perf.nTemperature);
	
    CString offset;
	if (Aorus()->GetVGA()->Ctrl()->IsBoost3())
		offset.Format(L"%d",perf.nGpuClk>>1);
	else
		offset.Format(L"%d",perf.nGpuClk);
	m_stc[STC_VGAPROF_GPUCLK_OFFSET].SetCaption(offset);
	offset.Format(L"%d",perf.nMemClk);
	m_stc[STC_VGAPROF_MEMCLK_OFFSET].SetCaption(offset);
	offset.Format(L"%d",perf.nGpuVol);
	m_stc[STC_VGAPROF_GPUVOL_OFFSET].SetCaption(offset);
	offset.Format(L"%d",perf.nFanSpd);
	m_stc[STC_VGAPROF_FANSPD_OFFSET].SetCaption(offset);
	offset.Format(L"%d",perf.nPower);
	m_stc[STC_VGAPROF_PWRTAR_OFFSET].SetCaption(offset);
	offset.Format(L"%d",perf.nTemperature);
	m_stc[STC_VGAPROF_TARTEM_OFFSET].SetCaption(offset);

	CString value;
	if (Aorus()->GetVGA()->Ctrl()->IsBoost3())
		value.Format(L"%d",(perf.nGpuClk>>1)+m_specialPerf.nGpuBoostClk);
	else
		value.Format(L"%d",perf.nGpuClk+m_specialPerf.nGpuBoostClk);
	m_stc[STC_VGAPROF_GPUCLK_VALUE].SetCaption(value);
	value.Format(L"%d",perf.nMemClk+m_specialPerf.nMemBaseClk);
	m_stc[STC_VGAPROF_MEMCLK_VALUE].SetCaption(value);
	value.Format(L"%d",perf.nGpuVol+m_specialPerf.nGpuBaseVol);
	m_stc[STC_VGAPROF_GPUVOL_VALUE].SetCaption(value);
	value.Format(L"%d",perf.nFanSpd);
	m_stc[STC_VGAPROF_FANSPD_VALUE].SetCaption(value);
	value.Format(L"%d",perf.nPower);
	m_stc[STC_VGAPROF_PWRTAR_VALUE].SetCaption(value);
	value.Format(L"%d",perf.nTemperature);
	m_stc[STC_VGAPROF_TARTEM_VALUE].SetCaption(value);

	// Peter Lee 2017/6/7, hide some UI with sink (no fan) models
	if (Aorus()->GetVGA()->Ctrl()->GetCardInfo()->sModelName == _T("GV-N1030SL-2GL") ||
		Aorus()->GetVGA()->Ctrl()->GetCardInfo()->sModelName == _T("GV-N108TAORUSX WB-11GD"))
	{
		m_btn[BTN_VGAPROF_FANAUTO].Enable(false);
		m_btn[BTN_VGAPROF_FANMANUAL].Enable(false);
		m_btn[BTN_VGAPROF_FANCUST].Enable(false);
	}

	OnUpdateUI();
	m_CustomizedDlg.InitState();
}
int CVgaProfDlg::SetLinkedPowerTemp(DWORD dwPerfs, int value)
{
	float back;
	VGA_PARAM_RANGE PowerRange, TempRange;
	VGA_PERFORMANCE perf;
	Aorus()->GetVGA()->Ctrl()->GetPerfInfo(VGA_PERF_POWER,  PowerRange);
	Aorus()->GetVGA()->Ctrl()->GetPerfInfo(VGA_PERF_TEMPER, TempRange);
	Aorus()->GetVGA()->Ctrl()->GetPerformancesDefault(VGA_PERF_POWER | VGA_PERF_TEMPER, perf);

	if (dwPerfs == VGA_PERF_POWER)
	{
		if (value > perf.nPower)
		{
			back =  (float)perf.nTemperature +
				(float)(value - perf.nPower) / (float)(PowerRange.nMax - perf.nPower) * (float)(TempRange.nMax - perf.nTemperature);
			back = (back > TempRange.nMax) ? TempRange.nMax : back;
		}
		else
		{
			back = perf.nTemperature -
				(float)(perf.nPower - value) / (float)(perf.nPower - PowerRange.nMin) * (float)(perf.nTemperature - TempRange.nMin);
			back = (back < TempRange.nMin) ? TempRange.nMin : back;
		}
	}
	else
	{
		if (value > perf.nTemperature)
		{
			back =  (float)perf.nPower +
				(float)(value - perf.nTemperature) / (float)(TempRange.nMax - perf.nTemperature) * (float)(PowerRange.nMax - perf.nPower);
			back = (back > PowerRange.nMax) ? PowerRange.nMax : back;
		}
		else
		{
			back = perf.nPower -
				(float)(perf.nTemperature - value) / (float)(perf.nTemperature - TempRange.nMin) * (float)(perf.nPower - PowerRange.nMin);
			back = (back < PowerRange.nMin) ? PowerRange.nMin : back;
		}

	}

	return (int)back;
}
void CVgaProfDlg::UpdateProfile(DWORD dwPerfs, const VGA_PERFORMANCE& perf)
{
	if(dwPerfs & VGA_PERF_GPUCLK)
	{
		if (Aorus()->GetVGA()->Ctrl()->IsBoost3())
			m_slider[SLIDER_VGAPROF_GPUCLK].SetPos(perf.nGpuClk>>1);
		else
			m_slider[SLIDER_VGAPROF_GPUCLK].SetPos(perf.nGpuClk);
		CString offsetstr;
		int iClk;
		if (Aorus()->GetVGA()->Ctrl()->IsBoost3())
			iClk = (perf.nGpuClk>>1) - m_perfDefault.nGpuClk;	// Peter Lee 2017/4/11
		else
			iClk = perf.nGpuClk - m_perfDefault.nGpuClk;	// Peter Lee 2017/4/11
		iClk>=0 ? offsetstr.Format(L"+%d", iClk) : offsetstr.Format(L"%d", iClk);
		
		m_stc[STC_VGAPROF_GPUCLK_OFFSET].SetCaption(offsetstr);
		CString str;
		if (Aorus()->GetVGA()->Ctrl()->IsBoost3())
			str.Format(L"%d",(perf.nGpuClk>>1)+m_specialPerf.nGpuBoostClk);		
		else
			str.Format(L"%d",perf.nGpuClk+m_specialPerf.nGpuBoostClk);		
		m_stc[STC_VGAPROF_GPUCLK_VALUE].SetCaption(str);
	}

	if(dwPerfs & VGA_PERF_MEMCLK)
	{
		m_slider[SLIDER_VGAPROF_MEMCLK].SetPos(perf.nMemClk);
		CString offsetstr;
		int iClk = perf.nMemClk - m_perfDefault.nMemClk;	// Peter Lee 2017/4/11
		iClk>=0? offsetstr.Format(L"+%d", iClk) : offsetstr.Format(L"%d",iClk);

		m_stc[STC_VGAPROF_MEMCLK_OFFSET].SetCaption(offsetstr);
		CString str;
		str.Format(L"%d",perf.nMemClk+m_specialPerf.nMemBaseClk);		
		m_stc[STC_VGAPROF_MEMCLK_VALUE].SetCaption(str);
	}

	if(dwPerfs & VGA_PERF_GPUVOL)
	{
		m_slider[SLIDER_VGAPROF_GPUVOL].SetPos(perf.nGpuVol);
		CString offsetstr;
		perf.nGpuVol>=0 ? offsetstr.Format(L"+%d",perf.nGpuVol) : offsetstr.Format(L"-%d",-perf.nGpuVol);
		m_stc[STC_VGAPROF_GPUVOL_OFFSET].SetCaption(offsetstr);
		CString str;
		str.Format(L"%d",perf.nGpuVol+m_specialPerf.nGpuBaseVol);
		m_stc[STC_VGAPROF_GPUVOL_VALUE].SetCaption(str);
	}

	if(dwPerfs & VGA_PERF_FANSPD)
	{
		m_slider[SLIDER_VGAPROF_FANSPD].SetPos(perf.nFanSpd);
		CString offsetstr;
		perf.nFanSpd>=0 ? offsetstr.Format(L"+%d",perf.nFanSpd) : offsetstr.Format(L"-%d",-perf.nFanSpd) ;
		m_stc[STC_VGAPROF_FANSPD_OFFSET].SetCaption(offsetstr);
		CString str;
		str.Format(L"%d",perf.nFanSpd);
		m_stc[STC_VGAPROF_FANSPD_VALUE].SetCaption(str);
	}

	if(dwPerfs & VGA_PERF_POWER)
	{
		m_slider[SLIDER_VGAPROF_PWRTAR].SetPos(perf.nPower);
		CString offsetstr;
		perf.nPower>=0 ? offsetstr.Format(L"+%d",perf.nPower) : offsetstr.Format(L"-%d",perf.nPower);
		m_stc[STC_VGAPROF_PWRTAR_OFFSET].SetCaption(offsetstr);
		CString str;
		str.Format(L"%d",perf.nPower);
		m_stc[STC_VGAPROF_PWRTAR_VALUE].SetCaption(str);
		if (m_btn[BTN_VGAPROF_LINK].IsCheck())
		{
			int temp=SetLinkedPowerTemp(VGA_PERF_POWER,perf.nPower);
			m_slider[SLIDER_VGAPROF_TARTEM].SetPos(temp);
			CString str,strvalue;
			strvalue.Format(_T("%d"),temp);
			temp >= 0? str.Format(L"+%d",temp) : str.Format(L"-%d",temp);
			m_stc[STC_VGAPROF_TARTEM_OFFSET].SetCaption(str);
			m_stc[STC_VGAPROF_TARTEM_VALUE].SetCaption(strvalue);
		}
	}

	if(dwPerfs & VGA_PERF_TEMPER)
	{
		m_slider[SLIDER_VGAPROF_TARTEM].SetPos(perf.nTemperature);
		CString offsetstr;
		perf.nTemperature >=0 ? offsetstr.Format(L"+%d",perf.nTemperature) : offsetstr.Format(L"-%d",-perf.nTemperature);
		m_stc[STC_VGAPROF_TARTEM_OFFSET].SetCaption(offsetstr);
		CString str;
		str.Format(L"%d",perf.nTemperature);
		m_stc[STC_VGAPROF_TARTEM_VALUE].SetCaption(str);

		if (m_btn[BTN_VGAPROF_LINK].IsCheck())
		{
			int nPower=SetLinkedPowerTemp(VGA_PERF_TEMPER,perf.nTemperature);
			CString str,strvalue;
			nPower>=0 ? str.Format(L"+%d",nPower) : str.Format(L"-%d",-nPower);
			strvalue.Format(_T("%d"),nPower);
			m_stc[STC_VGAPROF_PWRTAR_OFFSET].SetCaption(str);
			m_stc[STC_VGAPROF_PWRTAR_VALUE].SetCaption(strvalue);
			m_slider[SLIDER_VGAPROF_PWRTAR].SetPos(nPower);
		}
	}
}
void CVgaProfDlg::OnApply()
{
	// TODO: Add your control notification handler code here
	VGA_PERFORMANCE perf;
	int nIndex = m_list[LST_VGAPROF_PROFILE].GetCurSel();
	if(nIndex < 0) return; // 没有选择时
	Aorus()->SetVGAProfileSel(nIndex);
	Aorus()->GetCfg()->GetPerformances(VGA_PERF_ALL,perf,Aorus()->GetVGAProfileSel(),Aorus()->GetVGASel());

	//GPU CLK
	perf.dwGpuClkCurve=m_btn[BTN_VGAPROF_GPUCUST].IsCheck()? CLK_CURVE_MANUAL:CLK_CURVE_BASE;
	if(perf.dwGpuClkCurve==CLK_CURVE_BASE)
	{
		perf.nGpuClk=m_slider[SLIDER_VGAPROF_GPUCLK].GetPos();
		if (Aorus()->GetVGA()->Ctrl()->IsBoost3())
			perf.nGpuClk = perf.nGpuClk<<1;
	}
	else if (perf.dwGpuClkCurve==CLK_CURVE_MANUAL)
	{
		m_CustomizedDlg.GetGpuVFCurve(perf);
	}
	//MEM CLK
	perf.dwMemClkCurve=CLK_CURVE_BASE;
	perf.nMemClk=m_slider[SLIDER_VGAPROF_MEMCLK].GetPos();

	//GPU VOL
	perf.nGpuVol=m_slider[SLIDER_VGAPROF_GPUVOL].GetPos();

	//FAN SPEED
	FAN_SETTING fansetting;
	Aorus()->GetCfg()->GetFanSetting(fansetting,Aorus()->GetVGASel(),Aorus()->GetVGAProfileSel());
	if (m_btn[BTN_VGAPROF_FANAUTO].IsCheck())
	{
		fansetting.nFanMode=VGA_FANMODE_AUTO;
		perf.nFanMode=VGA_FANMODE_AUTO;
	}
	else if (m_btn[BTN_VGAPROF_FANMANUAL].IsCheck())
	{
		fansetting.nFanMode=VGA_FANMODE_MANUAL;
		fansetting.nFanPercent=m_slider[SLIDER_VGAPROF_FANSPD].GetPos();
		perf.nFanMode=VGA_FANMODE_MANUAL;
		perf.nFanSpd=fansetting.nFanPercent;
	}
	else if (m_btn[BTN_VGAPROF_FANCUST].IsCheck())
	{
		fansetting.nFanMode=VGA_FANMODE_DEFINE;
		m_CustomizedDlg.GetFanVFCurve(fansetting);
		perf.nFanMode=VGA_FANMODE_DEFINE;
	}
	//power target
	perf.nPower=m_slider[SLIDER_VGAPROF_PWRTAR].GetPos();

	//LINK
	perf.bTempPowerLink=m_btn[BTN_VGAPROF_LINK].IsCheck();

	//target temp
	perf.nTemperature=m_slider[SLIDER_VGAPROF_TARTEM].GetPos();
    ShowLoadingWindow(AfxGetMainWnd(), SW_SHOW);
	Aorus()->GetVGA()->Ctrl()->SetFanSetting(Aorus()->GetVGASel(),fansetting);
	Aorus()->GetCfg()->SetFanSetting(fansetting,Aorus()->GetVGASel(),Aorus()->GetVGAProfileSel());
	//if (Aorus()->GetVGA()->Ctrl()->IsNvCard())
		//perf.nGpuClk = perf.nGpuClk << 1;	// Peter Lee 
	Aorus()->GetVGA()->Ctrl()->SetPerformances(VGA_PERF_ALL,Aorus()->GetVGASel(),perf);
	//if (Aorus()->GetVGA()->Ctrl()->IsNvCard())
		//perf.nGpuClk = perf.nGpuClk >> 1;
	Aorus()->GetCfg()->SetPerformances(VGA_PERF_ALL,perf,Aorus()->GetVGAProfileSel(), Aorus()->GetVGASel());
	Aorus()->GetCfg()->SetVgaMode(VGA_MODE_USER, Aorus()->GetVGASel());
	ShowLoadingWindow(AfxGetMainWnd(), SW_HIDE);
}

void CVgaProfDlg::OnReset()
{
	//VGA_PERFORMANCE perf;
	//Aorus()->GetCfg()->SetPerformances(VGA_PERF_ALL,perf,Aorus()->GetVGAProfileSel(),Aorus()->GetVGASel());
	//m_CustomizedDlg.OnReset();
	OnUpdateUI();
}
void CVgaProfDlg::OnUpdateUI(BOOL bDefault)
{
	//((CListBox*)GetDlgItem(IDC_LIST_PROFILE))->SetCurSel(Aorus()->GetVGAProfileSel());
	VGA_PERFORMANCE perf;
	FAN_SETTING fansetting;

	int ProfileCount=Aorus()->GetCfg()->GetProfileCount(Aorus()->GetVGASel());
	m_list[LST_VGAPROF_PROFILE].RemoveAllItem();
	if(ProfileCount>0)
	{
		for (int i=0;i<ProfileCount;i++)
		{//init profile COMBOX
			CString csname;
			Aorus()->GetCfg()->GetProfileName(i,Aorus()->GetVGASel(),csname);
			m_list[LST_VGAPROF_PROFILE].SetItemText(m_list[LST_VGAPROF_PROFILE].InsertImgItem(i, 0), 1,csname);
			m_list[LST_VGAPROF_PROFILE].SetItemData(i,i);
		}
	}
	else
	{
		AddFile();
	}

	int nProfileSel = Aorus()->GetVGAProfileSel();
	if(nProfileSel < 0) return; // 没有选择时
	if (bDefault)
	{
		Aorus()->GetVGA()->Ctrl()->GetFanAutoSetting(fansetting);
		perf=m_perfDefault;
		Aorus()->GetCfg()->SetFanSetting(fansetting,Aorus()->GetVGASel(),Aorus()->GetVGAProfileSel());
		Aorus()->GetCfg()->SetPerformances(VGA_PERF_ALL,perf,Aorus()->GetVGAProfileSel(),Aorus()->GetVGASel());
	}
	else
	{
		Aorus()->GetCfg()->GetFanSetting(fansetting,Aorus()->GetVGASel(),nProfileSel);
		Aorus()->GetCfg()->GetPerformances(VGA_PERF_ALL,perf,nProfileSel,Aorus()->GetVGASel());
	}
	
  
	m_btn[BTN_VGAPROF_LINK].SetCheck(perf.bTempPowerLink? true:false);
	//gpu clk
	if (perf.dwGpuClkCurve==CLK_CURVE_MANUAL)
	{
		m_btn[BTN_VGAPROF_GPUCUST].SetCheck(true);
		m_slider[SLIDER_VGAPROF_GPUCLK].Enable(false);
		m_btn[BTN_VGAPROF_GPUCLK_DEC].Enable(false);
		m_btn[BTN_VGAPROF_GPUCLK_INC].Enable(false);
		UpdateProfile(VGA_PERF_GPUCLK,perf);
		//UIShowCustomized(TRUE);
	}
	else
	{
		m_btn[BTN_VGAPROF_GPUCUST].SetCheck(FALSE);
		UpdateProfile(VGA_PERF_GPUCLK,perf);
		m_slider[SLIDER_VGAPROF_GPUCLK].Enable(true);
		m_btn[BTN_VGAPROF_GPUCLK_DEC].Enable(true);
		m_btn[BTN_VGAPROF_GPUCLK_INC].Enable(true);
		if(m_CustomizedDlg.GetType() == CUST_TYPE_CLK) 
		{
			UIShowCustomized(m_btn[BTN_VGAPROF_GPUCUST].IsCheck(), 0);
		}
	}
    //gpu lock

	m_btn[BTN_VGAPROF_GPULOCK].SetCheck(perf.bVolLock ? false : true);
	
    if (m_btn[BTN_VGAPROF_GPULOCK].IsCheck())
    {
		m_btn[BTN_VGAPROF_GPUVOL_DEC].Enable(true);
		m_btn[BTN_VGAPROF_GPUVOL_INC].Enable(true);
		m_slider[SLIDER_VGAPROF_GPUVOL].Enable(true);
    }
	else
	{
		m_slider[SLIDER_VGAPROF_GPUVOL].Enable(false);
		m_btn[BTN_VGAPROF_GPUVOL_DEC].Enable(false);
		m_btn[BTN_VGAPROF_GPUVOL_INC].Enable(false);
	}

	//memclk
	//GPU vol
	// power target
	//target temp
	UpdateProfile(VGA_PERF_MEMCLK|VGA_PERF_GPUVOL|VGA_PERF_POWER|VGA_PERF_TEMPER,perf); 

	//fan spd
	if (fansetting.nFanMode==VGA_FANMODE_AUTO)
	{
		m_btn[BTN_VGAPROF_FANSPD_DEC].Enable(false);
		m_btn[BTN_VGAPROF_FANSPD_INC].Enable(false);
		m_btn[BTN_VGAPROF_FANAUTO].SetCheck(true);
		m_btn[BTN_VGAPROF_FANMANUAL].SetCheck(false);
		m_btn[BTN_VGAPROF_FANCUST].SetCheck(false);
		UpdateProfile(VGA_PERF_FANSPD,perf); 
		m_slider[SLIDER_VGAPROF_FANSPD].Enable(FALSE);
	}
	else if (fansetting.nFanMode==VGA_FANMODE_MANUAL)
	{
		m_btn[BTN_VGAPROF_FANSPD_DEC].Enable(true);
		m_btn[BTN_VGAPROF_FANSPD_INC].Enable(true);
		m_btn[BTN_VGAPROF_FANAUTO].SetCheck(false);
		m_btn[BTN_VGAPROF_FANMANUAL].SetCheck(true);
		m_btn[BTN_VGAPROF_FANCUST].SetCheck(false);
		UpdateProfile(VGA_PERF_FANSPD,perf); 
		m_slider[SLIDER_VGAPROF_FANSPD].Enable(true);
	}
	else if(fansetting.nFanMode==VGA_FANMODE_DEFINE)
	{
		m_btn[BTN_VGAPROF_FANSPD_DEC].Enable(false);
		m_btn[BTN_VGAPROF_FANSPD_INC].Enable(false);
		m_btn[BTN_VGAPROF_FANAUTO].SetCheck(false);
		m_btn[BTN_VGAPROF_FANMANUAL].SetCheck(false);
		m_btn[BTN_VGAPROF_FANCUST].SetCheck(true);
		UpdateProfile(VGA_PERF_FANSPD,perf); 
		m_slider[SLIDER_VGAPROF_FANSPD].Enable(false);
		//UIShowCustomized(TRUE,1);
	}
	/*if(m_CustomizedDlg.GetType() == CUST_TYPE_FAN) 
	{
		UIShowCustomized(m_btn[BTN_VGAPROF_FANCUST].IsCheck(), 1);
	}*/
	//link
	if(perf.bTempPowerLink)
	{
		m_btn[BTN_VGAPROF_LINK].SetCheck(true);
	}

	m_list[LST_VGAPROF_PROFILE].SetItemState(Aorus()->GetVGAProfileSel(), LVIS_SELECTED, LVIS_SELECTED);
	m_CustomizedDlg.OnReset();
}

void CVgaProfDlg::UIShowCustomized(bool flag,int CurveIndex)
{
	if(flag)
	{
		if (CurveIndex==0)
		{
			m_CustomizedDlg.ShowOcScannerBtn(false);
			m_CustomizedDlg.OnReset();
			m_CustomizedDlg.UpdateUI(0);
		}
		else
		{
			m_CustomizedDlg.ShowOcScannerBtn(false);
			m_CustomizedDlg.OnReset();
			m_CustomizedDlg.UpdateUI(1);
		}
		//m_CustomizedDlg.DisplayCurve(CurveIndex);
		CRect rcCustomized,rcMainClient;
		::GetWindowRect(m_hWnd,rcMainClient);
		m_CustomizedDlg.GetClientRect(&rcCustomized);
		rcCustomized.MoveToXY(CPoint(rcMainClient.right+130, rcMainClient.top-55));
		m_CustomizedDlg.MoveWindow(rcCustomized);
		m_CustomizedDlg.ShowWindow(SW_SHOW);
	}
	else
	{
		m_CustomizedDlg.ShowWindow(SW_HIDE);
	}
}
LRESULT CVgaProfDlg::OnUiListClick(WPARAM wParam, LPARAM lParam)
{
	if(lParam < 0 || Aorus()->GetVGAProfileSel() == lParam) return 1;
	SwitchProfile(lParam);
	return 1;
}
LRESULT CVgaProfDlg::OnUiListEdited(WPARAM wParam, LPARAM lParam)
{
	switch(wParam)
	{
	case LST_VGAPROF_PROFILE:
		{
			CString csname;
			csname=m_list[LST_VGAPROF_PROFILE].GetItemText(lParam,1);
			Aorus()->GetCfg()->SetProfileName(lParam,Aorus()->GetVGASel(),csname);
		}break;
	}
	return 1;
}
LRESULT CVgaProfDlg::OnFanStopStateChange(WPARAM wParam, LPARAM lParam)
{
	m_CustomizedDlg.PostMessage(WM_FANTOP_BTN_CHANGE, wParam ,lParam);
	return 1;
}
void CVgaProfDlg::AddFile()
{
	CString str;
	int index=m_list[LST_VGAPROF_PROFILE].GetItemCount();

	LCID  lcid;
	lcid = ::GetSystemDefaultLCID();
#ifdef _DEBUG
	lcid = -1;
#endif // _DEBUG
	if (lcid==2052)//||lcid==1028)
	{
		str.Format(L"资料文件 %d ",index+1);
	}
	else if (lcid==1028)
	{
		str.Format(L"資料檔 %d ",index+1);
	}
	else
	{
		str.Format(L"PROFILE %d ",index+1);
	}
	m_list[LST_VGAPROF_PROFILE].InsertImgItem(index, 0);
	m_list[LST_VGAPROF_PROFILE].SetItemText(index, 1,str);
	m_list[LST_VGAPROF_PROFILE].SetItemData(index,index);
	FAN_SETTING fansetting;
	Aorus()->GetVGA()->Ctrl()->GetFanAutoSetting(fansetting);
    Aorus()->GetCfg()->SetFanSetting(fansetting,Aorus()->GetVGASel(),index);
	Aorus()->GetCfg()->SetPerformances(VGA_PERF_ALL,m_perfDefault,index,Aorus()->GetVGASel());
	Aorus()->GetCfg()->SetProfileName(index,Aorus()->GetVGASel(),str);
	Aorus()->GetCfg()->SetProfileCount(index+1,Aorus()->GetVGASel());
	CString name;
	name=m_list[LST_VGAPROF_PROFILE].GetItemText(index,1);
}

void CVgaProfDlg::DeleteFile()
{
	int nIndex=m_list[LST_VGAPROF_PROFILE].GetCurSel();
	if (nIndex < 0)
	{
		return;
	}
	m_list[LST_VGAPROF_PROFILE].DeleteItem(nIndex);
	int nCount=m_list[LST_VGAPROF_PROFILE].GetItemCount();

	Aorus()->GetCfg()->SetProfileCount(nCount,Aorus()->GetVGASel());
	if (nIndex <= nCount)
	{
		for (int i=nIndex;i<nCount;i++)
		{
			
			int noldProfile=m_list[LST_VGAPROF_PROFILE].GetItemData(i);//原Profile index
			int nGpuCount=Aorus()->GetVGA()->Ctrl()->GetGpuCount();

			CString csName;
			csName=m_list[LST_VGAPROF_PROFILE].GetItemText(i,1);
			Aorus()->GetCfg()->SetProfileName(i,Aorus()->GetVGASel(),csName);
			for (int card=0;card<nGpuCount;card++)
			{
				VGA_PERFORMANCE perf;
				FAN_SETTING fansetting;
				Aorus()->GetCfg()->GetFanSetting(fansetting,card,noldProfile);
				Aorus()->GetCfg()->GetPerformances(VGA_PERF_ALL,perf,noldProfile,card);
				Aorus()->GetCfg()->SetFanSetting(fansetting,card,i);
				Aorus()->GetCfg()->SetPerformances(VGA_PERF_ALL,perf,i,card);
		    };
			m_list[LST_VGAPROF_PROFILE].SetItemData(i, i);//设置删除后，重新排列的Profile INDEX
		}
	}

	if (nCount > 0)
	{
		nIndex = nIndex % nCount;
		m_list[LST_VGAPROF_PROFILE].SetItemState(nIndex, LVIS_SELECTED, LVIS_SELECTED);
		SwitchProfile(nIndex);
	}
	else
	{
		FAN_SETTING fansetting;
		Aorus()->GetVGA()->Ctrl()->GetFanAutoSetting(fansetting);
		Aorus()->GetCfg()->SetFanSetting(fansetting, Aorus()->GetVGASel(), nIndex);
		Aorus()->GetCfg()->SetPerformances(VGA_PERF_ALL, m_perfDefault,nIndex,Aorus()->GetVGASel());
		Aorus()->GetVGA()->Ctrl()->SetPerformances(VGA_PERF_ALL,Aorus()->GetVGASel(),m_perfDefault);
		Aorus()->GetCfg()->SetVgaMode(VGA_MODE_GAME, Aorus()->GetVGASel());
		OnUpdateUI(TRUE);
	}

}
void CVgaProfDlg::SaveFile(bool bApply)
{
	VGA_PERFORMANCE perf;
	int nProfileSel=m_list[LST_VGAPROF_PROFILE].GetCurSel();
	if(nProfileSel < 0) return; // 没有选择时
	Aorus()->GetCfg()->GetPerformances(VGA_PERF_ALL,perf,nProfileSel,Aorus()->GetVGASel());

	//GPU CLK
	perf.dwGpuClkCurve=m_btn[BTN_VGAPROF_GPUCUST].IsCheck()? CLK_CURVE_MANUAL:CLK_CURVE_BASE;
	if(perf.dwGpuClkCurve==CLK_CURVE_BASE)
	{
		perf.nGpuClk=m_slider[SLIDER_VGAPROF_GPUCLK].GetPos();
	}
	else if (perf.dwGpuClkCurve==CLK_CURVE_MANUAL)
	{
		m_CustomizedDlg.GetGpuVFCurve(perf);
	}
	//MEM CLK
	perf.dwMemClkCurve=CLK_CURVE_BASE;
	perf.nMemClk=m_slider[SLIDER_VGAPROF_MEMCLK].GetPos();

	//GPU VOL
	perf.nGpuVol=m_slider[SLIDER_VGAPROF_GPUVOL].GetPos();

	//FAN SPEED
	FAN_SETTING fansetting;
	Aorus()->GetCfg()->GetFanSetting(fansetting,Aorus()->GetVGASel(),nProfileSel);
	if (m_btn[BTN_VGAPROF_FANAUTO].IsCheck())
	{
		fansetting.nFanMode=VGA_FANMODE_AUTO;
		perf.nFanMode=VGA_FANMODE_AUTO;
	}
	else if (m_btn[BTN_VGAPROF_FANMANUAL].IsCheck())
	{
		fansetting.nFanMode=VGA_FANMODE_MANUAL;
		fansetting.nFanPercent=m_slider[SLIDER_VGAPROF_FANSPD].GetPos();
		perf.nFanMode=VGA_FANMODE_MANUAL;
		perf.nFanSpd=fansetting.nFanPercent;
	}
	else if (m_btn[BTN_VGAPROF_FANCUST].IsCheck())
	{
		fansetting.nFanMode=VGA_FANMODE_DEFINE;
		m_CustomizedDlg.GetFanVFCurve(fansetting);
		perf.nFanMode=VGA_FANMODE_DEFINE;
	}
	//power target
	perf.nPower=m_slider[SLIDER_VGAPROF_PWRTAR].GetPos();

	//LINK
	perf.bTempPowerLink=m_btn[BTN_VGAPROF_LINK].IsCheck();

    //VolLock
	perf.bVolLock=!m_btn[BTN_VGAPROF_GPULOCK].IsCheck();

	//target temp
	perf.nTemperature=m_slider[SLIDER_VGAPROF_TARTEM].GetPos();

	
	Aorus()->GetCfg()->SetPerformances(VGA_PERF_ALL,perf,Aorus()->GetVGAProfileSel(),Aorus()->GetVGASel());
	if(bApply)
	{
		Aorus()->GetCfg()->SetFanSetting(fansetting,Aorus()->GetVGASel(),nProfileSel);
		Aorus()->GetVGA()->Ctrl()->SetPerformances(VGA_PERF_ALL,Aorus()->GetVGASel(),perf);
		Aorus()->GetVGA()->Ctrl()->SetFanSetting(Aorus()->GetVGASel(),fansetting);
	}
	else
	{

		Aorus()->GetCfg()->SetFanSetting(fansetting,Aorus()->GetVGASel(),nProfileSel,false);
	}
}

void CVgaProfDlg::SwitchProfile(int nProfile)
{
	ShowLoadingWindow(AfxGetMainWnd(), SW_SHOW);
	Aorus()->SetVGAProfileSel(nProfile);
	FAN_SETTING fansetting;
	VGA_PERFORMANCE perf;
	Aorus()->GetCfg()->GetFanSetting(fansetting, Aorus()->GetVGASel(), Aorus()->GetVGAProfileSel());
	Aorus()->GetVGA()->Ctrl()->SetFanSetting(Aorus()->GetVGASel(),fansetting);
	Aorus()->GetCfg()->SetCurFanSetting(fansetting,Aorus()->GetVGASel());
	Aorus()->GetCfg()->GetPerformances(VGA_PERF_ALL,perf,Aorus()->GetVGAProfileSel(), Aorus()->GetVGASel());
	Aorus()->GetVGA()->Ctrl()->SetPerformances(VGA_PERF_ALL,Aorus()->GetVGASel(),perf);
	Aorus()->GetCfg()->SetVgaMode(VGA_MODE_USER, Aorus()->GetVGASel());
	Aorus()->GetCfg()->SetProfileSel(Aorus()->GetVGASel(),Aorus()->GetVGAProfileSel());
	OnUpdateUI(false);
	m_CustomizedDlg.OnReset();
	ShowLoadingWindow(AfxGetMainWnd(), SW_HIDE);
}

BOOL CVgaProfDlg::PreTranslateMessage( MSG* pMsg )
{
	if(pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE)    
	{
		return TRUE;
	}

	return CUiDlg::PreTranslateMessage(pMsg);
}
