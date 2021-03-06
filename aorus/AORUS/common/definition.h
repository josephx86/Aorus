#pragma once

//////////////////////////////////////////////////////////////////////////
// device supported in AORUS

#define DEVICE_COUNT	9	// Qty of devices supported.

#define DEVICE_VGA		1	// video graphics card
#define DEVICE_SLI		2	// SLI device, which has led function
#define DEVICE_MB		3	// Motherboard, which has led funciton
#define DEVICE_ATC700	4	// CPU Cooler: ATC700
#define DEVICE_AC300	5	// Case: AC300
#define DEVICE_AH300	6	// Headset: AH300
#define DEVICE_AM300	7	// Mouse: AM300
#define DEVICE_AK700	8	// Keyboard: AK700
#define DEVICE_H5		9  // H5

#define DEVICE_LINE1	21	// separation line between 1st device icon and 2nd device icon 
#define DEVICE_LINE2	22	// separation line between 2nd device icon and 3rd device icon
#define DEVICE_LINE3	23	// separation line between 3rd device icon and 4th device icon

#define DEVICE_LARROW	31	// left arrow
#define DEVICE_RARROW	32	// right arrow

// Device IDs
static int s_DevIds[DEVICE_COUNT] = {
	DEVICE_VGA, 
	DEVICE_SLI,
	DEVICE_MB,
	DEVICE_ATC700,
	DEVICE_AC300,
	DEVICE_AH300,
	DEVICE_AM300,
	DEVICE_AK700,
	DEVICE_H5,
};

//////////////////////////////////////////////////////////////////////////
// LED light effect styles:

#define LED_STYLE_CONSISTENT	0   // monocolor 
#define LED_STYLE_BREATHING		1   // breahing 
#define LED_STYLE_FLASHING		2   // flashing 
#define LED_STYLE_DUALFLASHING	3   // dual flashing 
#define LED_STYLE_MONITORING	4   // monitor. such as: GPU temperature, usage... 
#define LED_STYLE_AUDIOFLASHING	5   // audio flashing 
#define LED_STYLE_CIRCLING		6   // mutil-color circling 
#define LED_STYLE_WAVE			7   // wave 

// LED monitor:

#define LED_MONITOR_GPU_TEMPERATURE	0  // for VGA
#define LED_MONITOR_GPU_USAGE		1
#define LED_MONITOR_GPU_FANSPEED	2
#define LED_MONITOR_CPU_USAGE		3  // for MB
#define LED_MONITOR_CPU_TEMPERATURE 4
#define LED_MONITOR_SYS_TEMPERATURE 5
#define LED_MONITOR_CPU_FANSPEED	6

//////////////////////////////////////////////////////////////////////////
// LED style struct:

typedef struct _LED_STYLE 
{
	int nId;	// See LED_STYLE_****
	CString sName;

	_LED_STYLE() {
		nId = 0; sName = _T("");
	};
	_LED_STYLE(int id, CString name) {
		nId = id; sName = name;
	};

} LED_STYLE, *PLED_STYLE;


//////////////////////////////////////////////////////////////////////////
/// 珨潬閉螿源宒
#define VGA_MODE_OC			0x00000001
#define VGA_MODE_GAME		0x00000002
#define VGA_MODE_ECO		0x00000003
#define VGA_MODE_USER		0x00000004
#define VGA_MODE_OCBOOST	0x00000005
#define VGA_MODE_ECOBOOST	0x00000006
///
//////////////////////////////////////////////////////////////////////////
/// 鞞縐眈燊Flag
#define VGA_PERF_GPUCLK			0x00000001			// GPU Clock
#define VGA_PERF_MEMCLK			0x00000002			// Memory Clock
#define VGA_PERF_GPUVOL			0x00000004			// GPU Voltage
#define VGA_PERF_OVERVOL		0x00000008			// Over Voltage
#define VGA_PERF_MEMVOL			0x00000010			// Memory Voltage
#define VGA_PERF_POWER			0x00000020			// Power Target
#define VGA_PERF_TEMPER			0x00000040			// Temperature Target
#define VGA_PERF_FANSPD			0x00000100			// Fan Percent
#define VGA_PERF_FANRPM			0x00000200			// Fan RPM
#define VGA_PERF_CPUSAGE		0x00000800			// CPU Usage
#define VGA_PERF_CPUCLK			0x00001000			// CPU Clock
#define VGA_PERF_MEMUSAGE		0x00002000			// Memory Usage
#define VGA_PERF_PAGEFILE		0x00004000			// Page file Usage
#define VGA_PERF_GPUSAGE		0x00008000			// GPU Usage
#define VGA_PERF_GCLKCUV		0x00010000			// GPU Clock Curve
#define VGA_PERF_MCLKCUV		0x00020000			// Memory Clock Curve
#define VGA_PERF_ALL			0xffffffff
///
//////////////////////////////////////////////////////////////////////////
/// 鞞縐Led?伎耀宒
#define LED_CLR_R					0x000001
#define LED_CLR_G					0x000002
#define LED_CLR_B					0x000004
#define LED_CLR_U					0x010000
///
//////////////////////////////////////////////////////////////////////////
/// 鞞縐嫖耀宒
#define LED_MODE_AUTO				0x000008
#define LED_MODE_ON					0x000010
#define LED_MODE_OFF				0x000020
///
//////////////////////////////////////////////////////////////////////////
/// 鞞縐嫖宒
#define LED_TYPE_NONE				0x001000
#define LED_TYPE_BREATHING			0x002000
#define LED_TYPE_FLASHING			0x004000
#define LED_TYPE_DUAL_FLASHING		0x008000
#define LED_TYPE_VARIABLE_FLASHING	0x010000
#define LED_TYPE_RANDOM				0x020000
#define LED_TYPE_AUDIO_FLASHING		0x040000
///
//////////////////////////////////////////////////////////////////////////
/// SLI?倰
#define SLI_TYPE_GA			0x01
#define SLI_TYPE_NV			0x02
//////////////////////////////////////////////////////////////////////////
/// 鞞縐Range
typedef struct _VGA_PARAM_RANGE 
{
	LONG nMax;
	LONG nMin;
	LONG nStep;

	_VGA_PARAM_RANGE() {
		nMax  = 0; nMin  = 0; nStep = 0;
	};

} VGA_PARAM_RANGE, *PVGA_PARAM_RANGE;
///
//////////////////////////////////////////////////////////////////////////
// Device's LED setting 
typedef struct _LED_SETTING
{
	CString sProfileName;	// profile name
	bool	bOn;			// On/Off light effect
	bool	bMutilColor;	// Monocolor or mutil-color when showing light effect.
	int		nType;			// SLI type
	int 	nRangeMin;		// Min brightness
	int 	nRangeMax;		// Max brightness
	int 	nSpeed;			// breathing/flashing/dual flashing speed
	int		nSelectCard;	// Deivce index, for VGA cards
	DWORD 	dwStyle;		// styles of light effect
	DWORD 	dwVariation;	// when select motoring style: Monitor items 
	COLORREF clrLed;		// color of LED

	_LED_SETTING();

} LED_SETTING, *PLED_SETTING;
///
//////////////////////////////////////////////////////////////////////////
/// 鞞縐Monitor偞隅
typedef struct _VGA_PARAM_MONISETTING
{
	bool	bGpuClk;		// GPU Clock
	bool	bMemClk;		// Memory Clock
	bool	bGpuVol;		// GPU Voltage
	bool	bMemVol;		// Memory Voltage
	bool	bPower;			// Power Target
	bool	bTemperature;	// Temperature Target
	bool	bFanSpd;		// Fan Speed
	bool	bFanRpm;		// Fan RPM
	bool	bGPUsage;		// GPU Usage
	bool	bCPUsage;		// CPU Usage
	bool	bCPUClock;		// CPU Clock
	bool	bMemUsage;		// Memory Usage
	bool	bPageUsage;		// Page file Usage
	bool	bLogRecord;		// 岆瘁Log
	int		nTimeInterval;	// ?庨嶲嶲路
	CString sLogFile;	    // ?庨恅璃繚

	_VGA_PARAM_MONISETTING();
	_VGA_PARAM_MONISETTING& operator = (const _VGA_PARAM_MONISETTING& setting);

} VGA_PARAM_MONISETTING, *PVGA_PARAM_MONISETTING;
///
//////////////////////////////////////////////////////////////////////////
/// ?闚價掛偞隅
typedef struct _VGA_PARAM_BASESETTING	// screen block parameter
{
	BOOL bAutoRun;			// 岆瘁赻?
	BOOL bMinimize;			// ?綴岆瘁郔苤趙
	BOOL bCloseMin;		    // 燊寯偌漃岆瘁郔苤趙
	BOOL bCheckUpdate;		// 岆瘁赻脤載陔
	BOOL bSyncMutil;		// 岆瘁?鞞縐偞离
	BOOL bSyncLed;			// 岆瘁嶱?肮祭諷
	CString sLastCheckUpdate; // 奻棒脤赻載陔

	_VGA_PARAM_BASESETTING();
	_VGA_PARAM_BASESETTING& operator = (const _VGA_PARAM_BASESETTING& setting);

} VGA_PARAM_BASESETTING, *PVGA_PARAM_BASESETTING;
///
//////////////////////////////////////////////////////////////////////////
/// 鞞縐餫圮偞隅
typedef struct _FAN_SETTING
{
	// Fan mode 
#define VGA_FANMODE_AUTO			0	// 赻耀宒
#define VGA_FANMODE_MANUAL			1	// 忒耀宒
#define VGA_FANMODE_DEFINE			2	// 赻隅膽鋪耀宒

#define VGA_FANCURVE_STEPS		   10	// 鋪郔湮諷秶

	int nFanMode;						// 餫圮耀宒
	int nCurveStep;						// 鋪諷秶
	int nFanPercent;					// 餫圮滖厒啃煦掀ㄗ忒耀宒ㄘ
	bool bFanStop;						// 岆瘁?蚚Fan Stop髡夔

	struct {

		int nFanSpeed;					// 餫圮滖厒啃煦掀
		int nTemperature;				// 僅

	} curve[VGA_FANCURVE_STEPS];

	_FAN_SETTING();
	_FAN_SETTING& operator = (const _FAN_SETTING& setting);

} FAN_SETTING, *PFAN_SETTING;
///
//////////////////////////////////////////////////////////////////////////
/// 鞞縐價掛陓洘
typedef struct _VGA_CARD_INFO
{
	// VGA card type.

#define VGA_CARD_UNKNOWN	0x0000		// 帤眭
#define VGA_CARD_AMD		0x0001		// AMD
#define VGA_CARD_NV			0x0002		// Nvidia

	int		nCardType;					// 鞞縐?倰
	CString sDevDesc;					// 郋鏡扴
	CString	sModelName;					// Modelname
	CString	sBiosVer;					// Bios 唳掛
	CString sDriverVer;					// Driver 唳掛
	CString sDriverDate;				// Driver 嶲
	CString sVid;						// 鞞縐VID
	CString sDid;						// 鞞縐DID
	CString sSsid;						// 鞞縐SSID
	CString sSvid;						// 鞞縐SVID
	CString	sMemSize;					// Memory Size

	_VGA_CARD_INFO();
	_VGA_CARD_INFO& operator = (const _VGA_CARD_INFO& info);

} VGA_CARD_INFO, *PVGA_CARD_INFO;
///
//////////////////////////////////////////////////////////////////////////
/// 鞞縐價掛偞隅
typedef struct _VGA_PERFORMANCE	// VGA performance.
{

#define  CLK_CURVE_BASE		1		// 嘐隅耀宒
#define  CLK_CURVE_LINDER	2		// 鋪俶耀宒
#define  CLK_CURVE_MANUAL	3		// 忒耀宒

	int	nGpuClk;
	int nMemClk;
	int nGpuVol;		// %
	int nMaxVol;		// uV
	int nMemVol;		// uV
	int nFanSpd;
	int nFanRPM;
	int nFanMode;
	int nPower;
	int nGPUsage;
	int nTemperature;
	int bTempPowerLink;
	int bVolLock;
	DWORD dwGpuClkCurve;		// GPU Clock偞离耀宒
	DWORD dwMemClkCurve;		// Memory Clock偞离耀宒

	GVDISP_CLOCK_VFSET GpuVf;
	GVDISP_CLOCK_VFSET MemVf;

	_VGA_PERFORMANCE();

} VGA_PERFORMANCE, *PVGA_PERFORMANCE;
///
//////////////////////////////////////////////////////////////////////////
/// MB?陓洘
typedef struct _VGA_MB_INFO	// VGA performance.
{
	int nCPUsage;				// CPU Usage
	float fCPUClk;				// CPU Clock
	int nMemUsage;				// Memory Usage
	double fPageUsage;			// Page file Usage

	_VGA_MB_INFO(){
		nCPUsage = 0;
		fCPUClk = 0;
		nMemUsage = 0;
		fPageUsage = 0;
	};

} VGA_MB_INFO, *PVGA_MB_INFO;
///
//////////////////////////////////////////////////////////////////////////
/// 鞞縐Base 陓洘
typedef struct _VGA_SPECIALPERFS	// VGA special performance. Only for Nvidia after N680.
{
	int nGpuBaseClk;			// Gpu Base Clock, GPU Clock = Base Clock + Offset
	int nGpuBoostClk;			// Gpu Boost Clock, GPU Boost Clock = Boost Clock + Offset
	int nMemBaseClk;
	int nGpuBaseVol;
	int nMaxBaseVol;

	_VGA_SPECIALPERFS();

} VGA_SPECIALPERFS, *PVGA_SPECIALPERFS;
///
//////////////////////////////////////////////////////////////////////////



#define VK_A			0x41
#define VK_B			0x42
#define VK_C			0x43
#define VK_D			0x44
#define VK_E			0x45
#define VK_F			0x46
#define VK_G			0x47
#define VK_H			0x48
#define VK_I			0x49
#define VK_J			0x4A
#define VK_K			0x4B
#define VK_L			0x4C
#define VK_M			0x4D
#define VK_N			0x4E
#define VK_O			0x4F
#define VK_P			0x50
#define VK_Q			0x51
#define VK_R			0x52
#define VK_S			0x53
#define VK_T			0x54
#define VK_U			0x55
#define VK_V			0x56
#define VK_W			0x57
#define VK_X			0x58
#define VK_Y			0x59
#define VK_Z			0x5A

#define VK_0			0x30
#define VK_1			0x31
#define VK_2			0x32
#define VK_3			0x33
#define VK_4			0x34
#define VK_5			0x35
#define VK_6			0x36
#define VK_7			0x37
#define VK_8			0x38
#define VK_9			0x39

#define SCAN_LEFT_CTRL		0x01
#define SCAN_LEFT_SHIFT		0x02
#define SCAN_LEFT_ALT		0x04
#define SCAN_LEFT_GUI		0x08
#define SCAN_RIGHT_CTRL		0x10
#define SCAN_RIGHT_SHIFT	0x20
#define SCAN_RIGHT_ALT		0x40
#define SCAN_RIGHT_GUI		0x80

#define VM_LEFT			1
#define VM_RIGHT		2
#define VM_MIDDLE		4
#define VM_BTN_4		16
#define VM_BTN_5		8
#define VM_LEFT_SCROLL	0xFF
#define VM_RIGHT_SCROLL	0x01
#define VM_UP_SCROLL	0x01
#define VM_DOWN_SCROLL	0xFF


//////////////////////////////////////////////////////////////////////////
/// 韜鍔摩Index繹撼
typedef enum _CMD_NAME
{
	CMD_SEL_PROFILE = 0, 
	CMD_GET_STATUS, 
	CMD_SEL_DPI, CMD_GET_CURDPI,
	CMD_APPLY_SET,
	CMD_SET_TILT,
	CMD_SET_REPORTRATE, CMD_GET_REPORTRATE,
	CMD_SET_PROFILE, CMD_GET_PROFILE,
	CMD_SET_DPI, CMD_GET_DPI,
	CMD_SET_LED, CMD_GET_LED,
	CMD_SET_BTN, CMD_GET_BTN,
	CMD_SET_MEM, CMD_GET_MEM,
	CMD_DEV_LOCK,
	CMD_SHW_LED,
	CMD_SET_COLOR, CMD_SET_BRIGHT, CMD_GET_COLOR, CMD_GET_BRIGHT, CMD_SAVE_BRIGHT,
	CMD_SYNC_LED, 
	CMD_QTY,

}CMD_NAME;



//////////////////////////////////////////////////////////////////////////
/// 韜鍔摩磁
static BYTE s_lstCmd1[][8] = {
	{ 0x00, 0xB0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // Select Profile
	{ 0x00, 0xB1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // Get Status
	{ 0x00, 0xB2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // Select DPI
	{ 0x00, 0xB3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // Get Current DPI
	{ 0x00, 0xB6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // Apply Setting
	{ 0x00, 0xBC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // Get Scroll Event
	{ 0x00, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // Set RepotRate Index
	{ 0x00, 0xC1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // Get RepotRate Index
	{ 0x00, 0xC2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // Set Profile
	{ 0x00, 0xC3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // Get Profile
	{ 0x00, 0xC4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // Set DPI
	{ 0x00, 0xC5, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // Get DPI
	{ 0x00, 0xC6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // Set LED Profile
	{ 0x00, 0xC7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // Get LED Profile
	{ 0x00, 0xD0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // Set Button Macros
	{ 0x00, 0xD1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // Get Button Macros
	{ 0x00, 0xD3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // Set Macros Memory
	{ 0x00, 0xD4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // Get Macros Memory
	{ 0x00, 0xAC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // Lock Device
	{ 0x00, 0xCC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // Lock Device
	{ 0x01, 0xC8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // Set Color List by Index
	{ 0x01, 0xC9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // Set Led Mode 
	{ 0x00, 0xCA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // Get Color List by Index
	{ 0x00, 0xCB, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // Get Led Mode 
	{ 0x01, 0xB6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // Save Led Mode to Flash
	{ 0x01, 0xCD, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // Save Led Mode to Flash
};

//////////////////////////////////////////////////////////////////////////
/// 韜鍔Byte Index隅砱ㄛ韜靡ㄩCMD_韜鍔坫迡_Byte砩砱坫迡
#define CMD_LENGTH				8
#define CMD_DATA_INDEX			2

#define CMD_COMMAND				1

#define CMD_STATUS_PROFILE		2
#define CMD_STATUS_BACKLIGHT	3
#define CMD_STATUS_ENABLE		4
#define CMD_STATUS_BREATH		5

#define CMD_DPI_INDEX			2
#define CMD_DPI_X				3
#define CMD_DPI_Y				4

#define CMD_LED_PROFILE			2
#define CMD_LED_R				3
#define CMD_LED_G				4
#define CMD_LED_B				5
#define CMD_LED_BREATH			6

#define CMD_BTN_INDEX			2
#define CMD_BTN_TYPE			3
#define CMD_BTN_OPT1			4
#define CMD_BTN_OPT2			5
#define CMD_BTN_OPT3			6

#define CMD_MEM_BYTES			2
#define CMD_MEM_ADDRH			3
#define CMD_MEM_ADDRM			4
#define CMD_MEM_ADDRL			5

#define CMD_REPORT_RATE			2

#define CMD_TILT_TYPE			2

#define CMD_LOCK_STU			2
#define CMD_LOCK_DPI			3
#define CMD_LOCK_PRO			4

#define CMD_SHW_STYLE			2
#define CMD_SHW_BRIGHT			3
#define CMD_SHW_R				4
#define CMD_SHW_G				5
#define CMD_SHW_B				6
#define CMD_SHW_SPEED			7

#define CMD_LEDRGB_R			2
#define CMD_LEDRGB_G			3
#define CMD_LEDRGB_B			4
#define CMD_LEDRGB_INDEX		5

#define CMD_LEDCFG_TYPE			2
#define CMD_LEDCFG_BRIGHT		3
#define CMD_LEDCFG_SPEED		4
#define CMD_LEDCFG_CLRCUT		5
#define CMD_LEDCFG_CYCLE		6
///
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
/// 杅擂Byte Index隅砱ㄛ歙脹衾CMD隅砱熬DATA Index宎
#define DATA_LENGTH				((CMD_LENGTH)-(CMD_DATA_INDEX))

#define DATA_STATUS_PROFILE		((CMD_STATUS_PROFILE)-(CMD_DATA_INDEX))
#define DATA_STATUS_BACKLIGHT	((CMD_STATUS_BACKLIGHT)-(CMD_DATA_INDEX))
#define DATA_STATUS_ENABLE		((CMD_STATUS_ENABLE)-(CMD_DATA_INDEX))
#define DATA_STATUS_BREATH		((CMD_STATUS_BREATH)-(CMD_DATA_INDEX))

#define DATA_DPI_INDEX			((CMD_DPI_INDEX)-(CMD_DATA_INDEX))
#define DATA_DPI_X				((CMD_DPI_X)-(CMD_DATA_INDEX))
#define DATA_DPI_Y				((CMD_DPI_Y)-(CMD_DATA_INDEX))

#define DATA_LED_PROFILE		((CMD_LED_PROFILE)-(CMD_DATA_INDEX))
#define DATA_LED_R				((CMD_LED_R)-(CMD_DATA_INDEX))
#define DATA_LED_G				((CMD_LED_G)-(CMD_DATA_INDEX))
#define DATA_LED_B				((CMD_LED_B)-(CMD_DATA_INDEX))
#define DATA_LED_BREATH			((CMD_LED_BREATH)-(CMD_DATA_INDEX))

#define DATA_BTN_INDEX			((CMD_BTN_INDEX)-(CMD_DATA_INDEX))
#define DATA_BTN_TYPE			((CMD_BTN_TYPE)-(CMD_DATA_INDEX))
#define DATA_BTN_OPT1			((CMD_BTN_OPT1)-(CMD_DATA_INDEX))
#define DATA_BTN_OPT2			((CMD_BTN_OPT2)-(CMD_DATA_INDEX))
#define DATA_BTN_OPT3			((CMD_BTN_OPT3)-(CMD_DATA_INDEX))

#define DATA_MEM_BYTES			((CMD_MEM_BYTES)-(CMD_DATA_INDEX))
#define DATA_MEM_ADDRH			((CMD_MEM_ADDRH)-(CMD_DATA_INDEX))
#define DATA_MEM_ADDRM			((CMD_MEM_ADDRM)-(CMD_DATA_INDEX))
#define DATA_MEM_ADDRL			((CMD_MEM_ADDRL)-(CMD_DATA_INDEX))

#define DATA_REPORT_RATE		((CMD_REPORT_RATE)-(CMD_DATA_INDEX))

#define DATA_TILT_TYPE			((CMD_TILT_TYPE)-(CMD_DATA_INDEX))

#define DATA_LOCK_STU			((CMD_LOCK_STU)-(CMD_DATA_INDEX))
#define DATA_LOCK_PRO			((CMD_LOCK_PRO)-(CMD_DATA_INDEX))
#define DATA_LOCK_DPI			((CMD_LOCK_DPI)-(CMD_DATA_INDEX))

#define DATA_SHW_STYLE			((CMD_SHW_STYLE)-(CMD_DATA_INDEX))
#define DATA_SHW_BRIGHT			((CMD_SHW_BRIGHT)-(CMD_DATA_INDEX))
#define DATA_SHW_R				((CMD_SHW_R)-(CMD_DATA_INDEX))
#define DATA_SHW_G				((CMD_SHW_G)-(CMD_DATA_INDEX))
#define DATA_SHW_B				((CMD_SHW_B)-(CMD_DATA_INDEX))
#define DATA_SHW_SPEED			((CMD_SHW_SPEED)-(CMD_DATA_INDEX))
			
#define DATA_LEDRGB_INDEX		((CMD_LEDRGB_INDEX)-(CMD_DATA_INDEX))
#define DATA_LEDRGB_R			((CMD_LEDRGB_R)-(CMD_DATA_INDEX))
#define DATA_LEDRGB_G			((CMD_LEDRGB_G)-(CMD_DATA_INDEX))
#define DATA_LEDRGB_B			((CMD_LEDRGB_B)-(CMD_DATA_INDEX))

#define DATA_LEDCFG_TYPE			((CMD_LEDCFG_TYPE)-(CMD_DATA_INDEX))
#define DATA_LEDCFG_BRIGHT		((CMD_LEDCFG_BRIGHT)-(CMD_DATA_INDEX))
#define DATA_LEDCFG_SPEED		((CMD_LEDCFG_SPEED)-(CMD_DATA_INDEX))
#define DATA_LEDCFG_CLRCUT		((CMD_LEDCFG_CLRCUT)-(CMD_DATA_INDEX))
#define DATA_LEDCFG_CYCLE		((CMD_LEDCFG_CYCLE)-(CMD_DATA_INDEX))

//////////////////////////////////////////////////////////////////////////
/// 操摩Memory韜鍔隅砱ㄛ迵楷冞善扢掘祥肮ㄛ剒冪徹ToData蛌遙
#define DATA_MACROS_TYPEDOWN	0
#define DATA_MACROS_DWVAL1		1
#define DATA_MACROS_DWVAL2		2
#define DATA_MACROS_DELAY		0
#define DATA_MACROS_TIMEL		1
#define DATA_MACROS_TIMEH		2
#define DATA_MACROS_TYPEUP		0
#define DATA_MACROS_UPVAL1		1
#define DATA_MACROS_UPVAL2		2

//////////////////////////////////////////////////////////////////////////
/// 操摩扽俶Memory Data Index 隅砱
#define DATA_MACROS_ATTR_ICON	 0
#define DATA_MACROS_ATTR_NAME	 1
#define DATA_MACROS_ATTR_TYPE	15

///
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
/// 操摩硌鍔蘇韜鍔
#define MACROS_KB_DOWN	0x22		// 瑩攫偌狟
#define MACROS_KB_UP	0x28		// 瑩攫粟
#define MACROS_MD_DOWN	0x32		// 嗣羸极瑩偌狟
#define MACROS_MD_UP	0x52		// 嗣羸极瑩粟
#define MACROS_MS_DOWN	0x11		// 扷梓偌狟
#define MACROS_MS_UP	0x1A		// 扷梓粟
#define MACROS_MS_X		0x12		// 扷梓X粣
#define MACROS_MS_Y		0x1B		// 扷梓Y粣
#define MACROS_SLR_UP	0x14		// 扷梓奻幗
#define MACROS_SLR_DOWN 0x1D		// 扷梓狟幗
#define MACROS_DELAY	0x43		// 偌瑩Delay奀潔
#define MACROS_DEFAULT	0xFF		// 蘇Byte硉

//////////////////////////////////////////////////////////////////////////
/// 操摩華硊迵喜渡隅砱
#define MACROS_KEYS_SIZE		0x0400 //0x0240
#define MACROS_NAME_SIZE		0x0010
#define MACROS_KEYS_COUNT		0x0032

#define MACROS_KEYS_ADDR		0x0000 //0580
#define MACROS_NAME_ADDR		0xD000//7600 c800

#define MACROS_NAME 0x0400
#define MACROS_NAME_LENGTH 0x320
//////////////////////////////////////////////////////////////////////////
/// Key Mapping 隅砱
#define MEM_MAX_SIZE			0x040
#define KEYMAP_PROFILE_SIZE		0x040
#define KEYMAP_TOTAL_SIZE		0x200
#define KEYMAP_TOTAL_ADDR		0x450

static DWORD s_MsProfileAddr[5] = {
	0x040, 0x100, 0x1c0, 0x280, 0x3d0,
};

static DWORD m_KbProfileAddr[5] = {
	0x000, 0x0C0, 0x180, 0x240, 0x300,
};

static DWORD m_ProfileAddr[5] = {
	0x000, 0x0C0, 0x180, 0x240, 0x300,
};

//////////////////////////////////////////////////////////////////////////
/// 羸极瑩keycode隅砱
static BYTE s_byMediaKey[][2] = {
	{ 0x23, 0x02 },  // browser
	{ 0xe9, 0x00 },  // volume up
	{ 0xea, 0x00 },  // volume down
	{ 0x92, 0x01 },  // Caculator
	{ 0xcd, 0x00 },  // Play
	{ 0xb7, 0x00 },  // Stop
	{ 0xb5, 0x00 },  // Next
	{ 0xb6, 0x00 },  // Prev
	{ 0x8a, 0x01 },  // EMail
	{ 0x94, 0x01 },  // My Computer
	{ 0x83, 0x01 },  // Media Player
	{ 0x02, 0x00 },  // Sleep
	{ 0xe2, 0x00 },  // Mute
};

//////////////////////////////////////////////////////////////////////////
/// 腑瘍撻淝隅砱宎Memory華硊
static DWORD s_MatrixAddr[] = {
	0x7A00, 0x7A80, 0x7B00, 0xB80, 0x7C00,
};

/// 腑瘍撻淝typedef
typedef struct _GVORDER_MATRIX
{
	GVORDER_MATRIX_GAME	Matrix;
	int		nLightNumber;
	int		nBrightLight;
	int		nProfile;

}GVORDER_MATRIX, *PGVORDER_MATRIX;

//////////////////////////////////////////////////////////////////////////
/// 蚔牁腑瘍撻淝隅砱ㄛ杅趼測桶猁謠腑腔撻淝Index﹝
/// 森揭氝樓綴ㄛ剒猁婓GvOrderLib腔GVORDER_MATRIX_GAME氝樓勤茼蚔牁
#define MATRIX_LENGTH 128
static BYTE s_KeyMatrix[8][MATRIX_LENGTH] = {
	// FPS
	{ 18, 19, 20, 21, 41, 43, 60, 61, 62 },	
	// MMO
	{ 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 41, 60, 61, 62, 71, 72 }, 
	// MOBA
	{ 18, 19, 20, 21, 22, 40, 41, 42, 43, 60, 61, 83 }, 
	// RTS
	{ 18, 19, 20, 21, 22, 60, 61, 77, 78, 96, 98 }, 
	// CSGO
	{ 18, 19, 20, 21, 22, 39, 41, 45, 46, 60, 61, 62, 64, 67, 77, 78, 83, 96 }, 
	// DOTA II
	{  2,  3,  4,  5,  6,  9, 18, 19, 20, 21, 22, 23, 40, 41, 42, 43, 45, 46, 60, 61, 71, 72, 79, 80, 81, 82, 83, 84 }, 
	// LOL
	{ 18, 19, 20, 21, 22, 23, 24, 40, 41, 42, 43, 60, 61, 62, 63 }, 
	// Starcraft II
	{  2,  3,  4,  5, 18, 19, 20, 21, 22, 60, 61, 71, 72, 77, 78, 83, 84, 96, 98 }
};
///
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
///
#define PROFILE_SIZE 0x40

#define PROFILE_STATUS 0x00
#define PROFILE_CURDPI 0x01
#define PROFILE_COLORR 0x02
#define PROFILE_COLORG 0x03
#define PROFILE_COLORB 0x04
#define PROFILE_DPIX1  0x05
#define PROFILE_DPIY1  0x06
#define PROFILE_DPIX2  0x07
#define PROFILE_DPIY2  0x08
#define PROFILE_DPIX3  0x09
#define PROFILE_DPIY3  0x0A
#define PROFILE_DPIX4  0x0B
#define PROFILE_DPIY4  0x0C
#define PROFILE_BLIGHT 0x0C
#define PROFILE_SPEED  0x0E
#define PROFILE_ICON   0x0F
#define PROFILE_BRIGHT 0x10
#define PROFILE_LEDMOD 0x11
#define PROFILE_NAME   0x12
#define PROFILE_RATE   0x21


#define ADDRL(_x_) (((_x_) >>  0) & 0xff)
#define ADDRM(_x_) (((_x_) >>  8) & 0xff)
#define ADDRH(_x_) (((_x_) >> 16) & 0xff)



///////////////////////////////////////////////////////////////////
// KB
///////////////////////////////////////////////////////////////////
#define KEYCOUNT 107

#define KB_CLR_COUNT 8
static COLORREF s_clrKbLed[KB_CLR_COUNT] = {
	RGB(255,   0,   0), 
	RGB(255,  96,   0), 
	RGB(255, 255,   0), 
	RGB(122, 255,   0), 
	RGB(  0, 255, 255), 
	RGB(  0,   0, 255), 
	RGB(137,   0, 139), 
	RGB(255,   0, 255), 
};

#define KEY_ROW 6
#define KEY_COL	21


// 森窒煦ID鷂s_XK700104Key燊?ㄛ0桶尨偌潬
/*static int s_KeyId[KEY_ROW][KEY_COL] = {
	{ 89, 106, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 0, 0, 0 },  //logo 105
	{ 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88 },
	{ 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 0 },
	{ 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 107, 43, 0, 0, 0, 44, 45, 46, 47 },  //107  |
	{ 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 0, 26, 43, 0, 27, 0, 28, 29, 30, 0 },
	{ 1, 2, 3, 0, 0, 4, 0, 0, 0, 5, 0, 6, 7, 8, 9, 10, 11, 12, 0, 13, 14 },
};*/


// �此部分ID與s_XK700104Key關聯，0表示無按鍵
static int s_KeyId[KEY_ROW][KEY_COL] = {
	{ 89, 106, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 0, 0, 0 },  //logo 105
	{ 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88 },
	{ 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 0 },
	{ 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 107, 43, 0, 0, 0, 44, 45, 46, 47 },  //107  |
	{ 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 0, 26, 43, 0, 27, 0, 28, 29, 30, 0 },
	{ 1, 2, 3, 0, 0, 4, 0, 0, 0, 5, 0, 6, 7, 8, 9, 10, 11, 12, 0, 13, 14 },
};

// 此部分位置與s_XK700104Key關聯，系實際FW存儲
static int s_nKeyFwIndex [] = {
	//0, 1, 2, 3, 9, 11, 12, 13, 14, 15, 16, 17, 19, 20, 21,										// LCtrl - Num Enter
	0, 1, 2, 5, 9, 11, 12, 13, 14, 15, 16, 17, 19, 20, 21,										// LCtrl - Num Enter; Peter Lee 2016/7/13
	22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 33, 36, 38, 39, 40,									// LShift - Num 3
	//42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 59, 60, 61, 62,							// CapsLock - Num +
	42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 55, 59, 60, 61, 62,							// CapsLock - Num +; Peter Lee 2016/7/13
	63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82,				// Tab ~ Num 9 
	84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104,	// ~ - Num -
	105, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121,122,106,54			// Esc - break （logo 122）
};

// 方向鍵
#define ARROW_KEY_COUNT 4
static int s_nArrowKeyIndex [] = {
	8,9,10,26, // 左下右上
};

// WASD
#define WASD_COUNT 4
static int s_nWASDIndex[] = {
	49,31,32,33, // wasd
};

// NUMPAD
#define NUMPAD_COUNT 17
static int s_nNumpadsndex[] = {
	11,12,13, // 0 . enter
	27, 28, 29, // 1 2 3
	43, 44, 45, 46,  // 4 5 6 +
	64, 65, 66, // 7 8 9
	84, 85, 86, 87, // numLk / * -
};

// fn key
#define FN_KEY_COUNT 22
static int s_nFNIndex[] = {
	6,
	89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, // f1 - f12
	83, 63, 82, 62,  // PgUp PgDown Home End
	81, 61, 101, 102, 103,  // Ins Del PrtScn ScrLk Pause
};

// FPS
#define FPS_COUNT 9
static int s_nFPSIndex[] = {
	49,31,32,33, // wasd
	51, // r
	68, 69, 70, 71, // 1234
};
// MMO
#define MMO_COUNT 17
static int s_nMMOIndex[] = {
	49,31,32,33, // wasd
	42,// enter
	68,69,70,71,72,73,74,75,76,77,78,79, // 1~0 - +
};

// MOBA
#define MOBA_COUNT 12
static int s_nMOBAIndex[] = {
	68,69,70,71,72,// 1~5
	48,49,50,51, // q~r
	31,32, 19// a s b
};

// RTS
#define RTS_COUNT 10
static int s_nRTSIndex[] = {
	68,69,70,71,72,// 1~5
	31,32,// a s
	0, 2, 14 // ctrl alt shit 
};

// CS:GO
#define CS_GO_COUNT 20
static int s_nCSGOIndex[] = {
	68,69,70,71,72,// 1~5
	49,31,32,33, // wasd
	48, 50, 51 ,// q e r
	53, 54, 35, 38, 19,// y u g k b
	0, 14, 47,// ctrl shift tab
};

// DOTA 2
#define DOTA2_COUNT 27
static int s_nDOTA2Index[] = {
	89, 90, 91, 92, 93, 96,// f1~f5, f8
	68,69,70,71,72, 73,// 1~6
	48,49,50,51, 53,// q w e r y
	31, 32, 35,// a s g
	15, 16, 17, 18, 19, 20,// z x c v b n
	42,// enter
};

// LOL
#define LOL_COUNT 16
static int s_nLOLIndex[] = {
	68,69,70,71,72, 73, 74,// 1~7
	48,49,50,51,// q w e r
	31, 32, 33, 34, 19// a s d f b
};

// STARCRAFT II
#define STARCRAFT2_COUNT 17
static int s_nSTARCRAFT2Index[] = {
	89, 90, 91, 92, // f1~f4
	68,69,70,71,72,// 1~5
	31,32,// a s
	19, 20,// b n
	0, 2, 14 ,// ctrl alt shit 
	42,// enter
};

// 鼠標按鍵Profile索引
static int key_index[]={ // 鍵的索引
	0, // left
	1, // right
	2, // mid
	4, // 4,前進
	3, // 5,後退

	//0xb, // Scroll left
	//0xa, // Scroll right
	//8, // Scroll Up
	//9, // Scroll Down

	7, // dpi +
	8, // dpi -
	//0xd, // Mode Switch
};