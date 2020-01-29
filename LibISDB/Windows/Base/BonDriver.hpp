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
 @file   BonDriver.hpp
 @brief  BonDriver
 @author DBCTRADO
*/


#ifndef LIBISDB_BON_DRIVER_H
#define LIBISDB_BON_DRIVER_H


/** IBonDriver インターフェース */
class IBonDriver
{
public:
#ifndef LIBISDB_WINDOWS
	typedef int BOOL;
	typedef uint8_t BYTE;
	typedef uint32_t DWORD;
#endif

	virtual const BOOL OpenTuner() = 0;
	virtual void CloseTuner() = 0;

	virtual const BOOL SetChannel(const BYTE bCh) = 0;
	virtual const float GetSignalLevel() = 0;

	virtual const DWORD WaitTsStream(const DWORD dwTimeOut = 0) = 0;
	virtual const DWORD GetReadyCount() = 0;

	virtual const BOOL GetTsStream(BYTE *pDst, DWORD *pdwSize, DWORD *pdwRemain) = 0;
	virtual const BOOL GetTsStream(BYTE **ppDst, DWORD *pdwSize, DWORD *pdwRemain) = 0;

	virtual void PurgeTsStream() = 0;

	virtual void Release() = 0;
};

/** IBonDriver2 インターフェース */
class IBonDriver2 : public IBonDriver
{
public:
#ifdef LIBISDB_WINDOWS
	typedef WCHAR CharType;
#else
	typedef char16_t CharType;
	typedef const CharType * LPCTSTR;
#endif

	virtual LPCTSTR GetTunerName() = 0;

	virtual const BOOL IsTunerOpening() = 0;

	virtual const LPCTSTR EnumTuningSpace(const DWORD dwSpace) = 0;
	virtual const LPCTSTR EnumChannelName(const DWORD dwSpace, const DWORD dwChannel) = 0;

	virtual const BOOL SetChannel(const DWORD dwSpace, const DWORD dwChannel) = 0;

	virtual const DWORD GetCurSpace() = 0;
	virtual const DWORD GetCurChannel() = 0;

// IBonDriver
	virtual void Release() = 0;
};

/** IBonDriver3 インターフェース */
class IBonDriver3 : public IBonDriver2
{
public:
	virtual const DWORD GetTotalDeviceNum() = 0;
	virtual const DWORD GetActiveDeviceNum() = 0;
	virtual const BOOL SetLnbPower(const BOOL bEnable) = 0;

// IBonDriver
	virtual void Release() = 0;
};


namespace LibISDB
{

	/** BonDriver クラス */
	class BonDriver
	{
	public:
		static constexpr uint32_t SPACE_INVALID   = 0xFFFFFFFF_u32;
		static constexpr uint32_t CHANNEL_INVALID = 0xFFFFFFFF_u32;

		BonDriver();
		~BonDriver();

		bool Load(const CStringView &FileName);
		void Unload();
		bool IsLoaded() const;
		bool CreateIBonDriver();
		void ReleaseIBonDriver();
		bool IsIBonDriverCreated() const;
		bool IsIBonDriver2() const;

		bool OpenTuner();
		void CloseTuner();
		bool IsTunerOpen() const;
		const IBonDriver2::CharType * GetTunerName() const;
		bool SetChannel(uint8_t Channel);
		bool SetChannel(uint32_t Space, uint32_t Channel);
		uint32_t GetCurSpace() const;
		uint32_t GetCurChannel() const;
		const IBonDriver2::CharType * EnumTuningSpace(uint32_t Space) const;
		const IBonDriver2::CharType * EnumChannelName(uint32_t Space, uint32_t Channel) const;
		float GetSignalLevel() const;
		uint32_t WaitTsStream(uint32_t Timeout = 0);
		uint32_t GetReadyCount() const;
		bool GetTsStream(uint8_t *pDst, uint32_t *pSize, uint32_t *pRemain);
		bool GetTsStream(uint8_t **ppDst, uint32_t *pSize, uint32_t *pRemain);
		void PurgeTsStream();

	private:
		/** C互換構造体->IBonDriver */
		class CBonStructAdapter : public IBonDriver
		{
		public:
			/** IBonDriver->C互換構造体 */
			struct STRUCT_IBONDRIVER
			{
				void *pCtx;
				const void *pEnd;
				BOOL (*pF00)(void *);
				void (*pF01)(void *);
				BOOL (*pF02)(void *, BYTE);
				float (*pF03)(void *);
				DWORD (*pF04)(void *, DWORD);
				DWORD (*pF05)(void *);
				BOOL (*pF06)(void *, BYTE *, DWORD *, DWORD *);
				BOOL (*pF07)(void *, BYTE **, DWORD *, DWORD *);
				void (*pF08)(void *);
				void (*pF09)(void *);
				STRUCT_IBONDRIVER &Initialize(IBonDriver *pBon, const void *pEnd_) {
					pCtx = pBon;
					pEnd = pEnd_ ? pEnd_ : this + 1;
					pF00 = F00;
					pF01 = F01;
					pF02 = F02;
					pF03 = F03;
					pF04 = F04;
					pF05 = F05;
					pF06 = F06;
					pF07 = F07;
					pF08 = F08;
					pF09 = F09;
					return *this;
				}
				static BOOL F00(void *p) { return static_cast<IBonDriver *>(p)->OpenTuner(); }
				static void F01(void *p) { static_cast<IBonDriver *>(p)->CloseTuner(); }
				static BOOL F02(void *p, BYTE a0) { return static_cast<IBonDriver *>(p)->SetChannel(a0); }
				static float F03(void *p) { return static_cast<IBonDriver *>(p)->GetSignalLevel(); }
				static DWORD F04(void *p, DWORD a0) { return static_cast<IBonDriver *>(p)->WaitTsStream(a0); }
				static DWORD F05(void *p) { return static_cast<IBonDriver *>(p)->GetReadyCount(); }
				static BOOL F06(void *p, BYTE *a0, DWORD *a1, DWORD *a2) { return static_cast<IBonDriver *>(p)->GetTsStream(a0, a1, a2); }
				static BOOL F07(void *p, BYTE **a0, DWORD *a1, DWORD *a2) { return static_cast<IBonDriver *>(p)->GetTsStream(a0, a1, a2); }
				static void F08(void *p) { static_cast<IBonDriver *>(p)->PurgeTsStream(); }
				static void F09(void *p) { static_cast<IBonDriver *>(p)->Release(); }
			};
			void Adapt(const STRUCT_IBONDRIVER &st_) { st = st_; }
			const BOOL OpenTuner() { return st.pF00(st.pCtx); }
			void CloseTuner() { st.pF01(st.pCtx); }
			const BOOL SetChannel(const BYTE bCh) { return st.pF02(st.pCtx, bCh); }
			const float GetSignalLevel() { return st.pF03(st.pCtx); }
			const DWORD WaitTsStream(const DWORD dwTimeOut = 0) { return st.pF04(st.pCtx, dwTimeOut); }
			const DWORD GetReadyCount() { return st.pF05(st.pCtx); }
			const BOOL GetTsStream(BYTE *pDst, DWORD *pdwSize, DWORD *pdwRemain) { return st.pF06(st.pCtx, pDst, pdwSize, pdwRemain); }
			const BOOL GetTsStream(BYTE **ppDst, DWORD *pdwSize, DWORD *pdwRemain) { return st.pF07(st.pCtx, ppDst, pdwSize, pdwRemain); }
			void PurgeTsStream() { st.pF08(st.pCtx); }
			void Release() { st.pF09(st.pCtx); }
		protected:
			STRUCT_IBONDRIVER st;
		};

		/** C互換構造体->IBonDriver2 */
		class CBonStruct2Adapter : public IBonDriver2
		{
		public:
			/** IBonDriver2->C互換構造体 */
			struct STRUCT_IBONDRIVER2
			{
				CBonStructAdapter::STRUCT_IBONDRIVER st;
				LPCTSTR (*pF10)(void *);
				BOOL (*pF11)(void *);
				LPCTSTR (*pF12)(void *, DWORD);
				LPCTSTR (*pF13)(void *, DWORD, DWORD);
				BOOL (*pF14)(void *, DWORD, DWORD);
				DWORD (*pF15)(void *);
				DWORD (*pF16)(void *);
				CBonStructAdapter::STRUCT_IBONDRIVER &Initialize(IBonDriver2 *pBon2, const void *pEnd) {
					pF10 = F10;
					pF11 = F11;
					pF12 = F12;
					pF13 = F13;
					pF14 = F14;
					pF15 = F15;
					pF16 = F16;
					return st.Initialize(pBon2, pEnd ? pEnd : this + 1);
				}
				static LPCTSTR F10(void *p) { return static_cast<IBonDriver2 *>(static_cast<IBonDriver *>(p))->GetTunerName(); }
				static BOOL F11(void *p) { return static_cast<IBonDriver2 *>(static_cast<IBonDriver *>(p))->IsTunerOpening(); }
				static LPCTSTR F12(void *p, DWORD a0) { return static_cast<IBonDriver2 *>(static_cast<IBonDriver *>(p))->EnumTuningSpace(a0); }
				static LPCTSTR F13(void *p, DWORD a0, DWORD a1) { return static_cast<IBonDriver2 *>(static_cast<IBonDriver *>(p))->EnumChannelName(a0, a1); }
				static BOOL F14(void *p, DWORD a0, DWORD a1) { return static_cast<IBonDriver2 *>(static_cast<IBonDriver *>(p))->SetChannel(a0, a1); }
				static DWORD F15(void *p) { return static_cast<IBonDriver2 *>(static_cast<IBonDriver *>(p))->GetCurSpace(); }
				static DWORD F16(void *p) { return static_cast<IBonDriver2 *>(static_cast<IBonDriver *>(p))->GetCurChannel(); }
			};
			bool Adapt(const CBonStructAdapter::STRUCT_IBONDRIVER &st) {
				if (static_cast<const char *>(st.pEnd) - reinterpret_cast<const char *>(&st) < static_cast<int>(sizeof(st2))) {
					return false;
				}
				st2 = reinterpret_cast<const STRUCT_IBONDRIVER2 &>(st);
				return true;
			}
			const BOOL OpenTuner() { return st2.st.pF00(st2.st.pCtx); }
			void CloseTuner() { st2.st.pF01(st2.st.pCtx); }
			const BOOL SetChannel(const BYTE bCh) { return st2.st.pF02(st2.st.pCtx, bCh); }
			const float GetSignalLevel() { return st2.st.pF03(st2.st.pCtx); }
			const DWORD WaitTsStream(const DWORD dwTimeOut = 0) { return st2.st.pF04(st2.st.pCtx, dwTimeOut); }
			const DWORD GetReadyCount() { return st2.st.pF05(st2.st.pCtx); }
			const BOOL GetTsStream(BYTE *pDst, DWORD *pdwSize, DWORD *pdwRemain) { return st2.st.pF06(st2.st.pCtx, pDst, pdwSize, pdwRemain); }
			const BOOL GetTsStream(BYTE **ppDst, DWORD *pdwSize, DWORD *pdwRemain) { return st2.st.pF07(st2.st.pCtx, ppDst, pdwSize, pdwRemain); }
			void PurgeTsStream() { st2.st.pF08(st2.st.pCtx); }
			void Release() { st2.st.pF09(st2.st.pCtx); }
			LPCTSTR GetTunerName() { return st2.pF10(st2.st.pCtx); }
			const BOOL IsTunerOpening() { return st2.pF11(st2.st.pCtx); }
			const LPCTSTR EnumTuningSpace(const DWORD dwSpace) { return st2.pF12(st2.st.pCtx, dwSpace); }
			const LPCTSTR EnumChannelName(const DWORD dwSpace, const DWORD dwChannel) { return st2.pF13(st2.st.pCtx, dwSpace, dwChannel); }
			const BOOL SetChannel(const DWORD dwSpace, const DWORD dwChannel) { return st2.pF14(st2.st.pCtx, dwSpace, dwChannel); }
			const DWORD GetCurSpace() { return st2.pF15(st2.st.pCtx); }
			const DWORD GetCurChannel() { return st2.pF16(st2.st.pCtx); }
		protected:
			STRUCT_IBONDRIVER2 st2;
		};

		HMODULE m_hLib;
		IBonDriver *m_pIBonDriver;
		IBonDriver2 *m_pIBonDriver2;
		CBonStructAdapter m_BonAdapter;
		CBonStruct2Adapter m_Bon2Adapter;
		bool m_IsOpen;
	};

}	// namespace LibISDB


#endif	// ifndef LIBISDB_BON_DRIVER_H
