/*
  LibISDB
  Copyright(c) 2017-2020 DBCTRADO

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

/**
 @file   DirectShowUtilities.hpp
 @brief  DirectShow 用ユーティリティ
 @author DBCTRADO
*/


#ifndef LIBISDB_DIRECTSHOW_UTILITIES_H
#define LIBISDB_DIRECTSHOW_UTILITIES_H


#include <vector>
#define STRSAFE_NO_DEPRECATE
#include <dshow.h>
#include <d3d9.h>
#include <vmr9.h>
#include <wmcodecdsp.h>
#include "../../Utilities/COMUtilities.hpp"


#ifndef WAVE_FORMAT_AAC
#define WAVE_FORMAT_AAC 0x00FF
#endif

DEFINE_GUID(MEDIASUBTYPE_AAC,
	WAVE_FORMAT_AAC, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71);

DEFINE_GUID(MEDIASUBTYPE_H264_bis,
	0x8D2D71CB, 0x243F, 0x45E3, 0xB2, 0xD8, 0x5F, 0xD7, 0x96, 0x7E, 0xC0, 0x9B);

DEFINE_GUID(MEDIASUBTYPE_avc1,
	0x31637661, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71);

DEFINE_GUID(MEDIASUBTYPE_HEVC,
	0x43564548, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71);


namespace LibISDB::DirectShow
{

	/** DirectShow フィルタ検索クラス */
	class FilterFinder
	{
	public:
		struct FilterInfo {
			CLSID clsid;
			std::wstring FriendlyName;

			FilterInfo(CLSID id, LPCWSTR pszFriendlyName)
				: clsid(id)
				, FriendlyName(pszFriendlyName)
			{
			}
		};

		typedef std::vector<FilterInfo> FilterList;

		void Clear();
		int GetFilterCount() const;
		bool GetFilterInfo(int Index, CLSID *pClass, std::wstring *pFriendlyName = nullptr) const;
		bool GetFilterList(FilterList *pList) const;
		bool FindFilters(
			const GUID *pInTypes, int InTypeCount,
			const GUID *pOutTypes = nullptr, int OutTypeCount = 0,
			DWORD Merit = MERIT_DO_NOT_USE + 1);
		bool FindFilters(
			const GUID *pidInType, const GUID *pidInSubType,
			const GUID *pidOutType = nullptr, const GUID *pidOutubType = nullptr,
			DWORD Merit = MERIT_DO_NOT_USE + 1);
		bool SetPreferredFilter(const CLSID &idFilter);

	protected:
		FilterList m_FilterList;
	};

	/** DirectShow デバイス列挙クラス */
	class DeviceEnumerator
	{
	public:
		void Clear();
		int GetDeviceCount() const;
		bool EnumDevice(const CLSID &clsidDeviceClass);
		bool CreateFilter(const CLSID &clsidDeviceClass, LPCWSTR pszFriendlyName, IBaseFilter **ppFilter);
		LPCWSTR GetDeviceFriendlyName(int Index) const;

	protected:
		struct DeviceInfo {
			std::wstring FriendlyName;

			DeviceInfo(LPCWSTR pszFriendlyName)
				: FriendlyName(pszFriendlyName)
			{
			}
		};

		std::vector<DeviceInfo> m_DeviceList;
	};


	HRESULT AddToROT(IUnknown *pUnkGraph, DWORD *pRegister);
	void RemoveFromROT(DWORD Register);

	IPin * GetFilterPin(IBaseFilter *pFilter, PIN_DIRECTION dir, const AM_MEDIA_TYPE *pMediaType = nullptr);

	bool ShowPropertyPage(IBaseFilter *pFilter, HWND hwndOwner);
	bool HasPropertyPage(IBaseFilter *pFilter);

	HRESULT AppendFilterAndConnect(
		IGraphBuilder *pGraphBuilder,
		IBaseFilter *pFilter, LPCWSTR pszFilterName,
		COMPointer<IPin> *pOutputPin, bool Direct = false);
	HRESULT AppendFilterAndConnect(
		IGraphBuilder *pGraphBuilder,
		const CLSID &clsidFilter, LPCWSTR pszFilterName, COMPointer<IBaseFilter> *pAppendedFilter,
		COMPointer<IPin> *pOutputPin, bool Direct = false);

	RECT MapRect(const RECT &Rect, LONG XNum, LONG XDenom, LONG YNum, LONG YDenom);

}	// namespace LibISDB::DirectShow


#ifdef __MINGW32__
#include <evr.h>
#include <mfidl.h>

namespace LibISDB::DirectShow
{

// <mfidl.h> lack of definitions (Apr 2021 checked)
struct IMFRateSupport : public IUnknown
{
	STDMETHOD(GetSlowestRate)(MFRATE_DIRECTION eDirection, BOOL fThin, float *pflRate) = 0;
	STDMETHOD(GetFastestRate)(MFRATE_DIRECTION eDirection, BOOL fThin, float *pflRate) = 0;
	STDMETHOD(IsRateSupported)(BOOL fThin, float flRate, float *pflNearestSupportedRate) = 0;
};

// <evr9.h> lack of definitions (Feb 2020 checked)
struct MFVideoAlphaBitmapParams
{
	DWORD dwFlags;
	COLORREF clrSrcKey;
	RECT rcSrc;
	MFVideoNormalizedRect nrcDest;
	FLOAT fAlpha;
	DWORD dwFilterMode;
};

struct MFVideoAlphaBitmap
{
	BOOL GetBitmapFromDC;
	union {
		HDC hdc;
		IDirect3DSurface9 *pDDS;
	} bitmap;
	MFVideoAlphaBitmapParams params;
};

struct IMFVideoMixerBitmap : public IUnknown
{
	STDMETHOD(SetAlphaBitmap)(const MFVideoAlphaBitmap *pBmpParms) = 0;
	STDMETHOD(ClearAlphaBitmap)(void) = 0;
	STDMETHOD(UpdateAlphaBitmapParameters)(const MFVideoAlphaBitmapParams *pBmpParms) = 0;
	STDMETHOD(GetAlphaBitmapParameters)(MFVideoAlphaBitmapParams *pBmpParms) = 0;
};

struct IMFVideoProcessor : public IUnknown
{
	STDMETHOD(GetAvailableVideoProcessorModes)(UINT *lpdwNumProcessingModes, GUID **ppVideoProcessingModes) = 0;
	STDMETHOD(GetVideoProcessorCaps)(LPGUID lpVideoProcessorMode, void *lpVideoProcessorCaps) = 0;
	STDMETHOD(GetVideoProcessorMode)(LPGUID lpMode) = 0;
	STDMETHOD(SetVideoProcessorMode)(LPGUID lpMode) = 0;
	STDMETHOD(GetProcAmpRange)(void *pPropRange) = 0;
	STDMETHOD(GetProcAmpValues)(void *Values) = 0;
	STDMETHOD(SetProcAmpValues)(void *pValues) = 0;
	STDMETHOD(GetFilteringRange)(void *pPropRange) = 0;
	STDMETHOD(GetFilteringValue)(void *pValue) = 0;
	STDMETHOD(SetFilteringValue)(void *pValue) = 0;
	STDMETHOD(GetBackgroundColor)(COLORREF *lpClrBkg) = 0;
	STDMETHOD(SetBackgroundColor)(COLORREF ClrBkg) = 0;
};

constexpr GUID CLSID_EnhancedVideoRenderer = {
	0xFA10746C, 0x9B63, 0x4B6C, {0xBC, 0x49, 0xFC, 0x30, 0x0E, 0xA5, 0xF2, 0x56}
};

}	// namespace LibISDB::DirectShow

// <mfidl.h> lack of definitions (Feb 2020 checked)
#ifndef PRESENTATION_CURRENT_POSITION
#define PRESENTATION_CURRENT_POSITION 0x7FFFFFFFFFFFFFFF
#endif

__CRT_UUID_DECL(LibISDB::DirectShow::IMFRateSupport, 0x0A9CCDBC, 0xD797, 0x4563, 0x96,0x67, 0x94,0xEC,0x5D,0x79,0x29,0x2D);
__CRT_UUID_DECL(LibISDB::DirectShow::IMFVideoMixerBitmap, 0x814C7B20, 0x0FDB, 0x4EEC, 0xAF,0x8F, 0xF9,0x57,0xC8,0xF6,0x9E,0xDC);
__CRT_UUID_DECL(LibISDB::DirectShow::IMFVideoProcessor, 0x6AB0000C, 0xFECE, 0x4D1F, 0xA2,0xAC, 0xA9,0x57,0x35,0x30,0x65,0x6E);

#endif	// ifdef __MINGW32__


#endif	// ifndef LIBISDB_DIRECTSHOW_UTILITIES_H
