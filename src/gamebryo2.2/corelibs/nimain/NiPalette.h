#pragma once

#include "nimain/NiObject.h"
#include "nisystem/NiCriticalSection.h"

class NiPalette : public NiObject {
  public:
	class PaletteEntry {
	  public:
		u8 m_ucRed;	  // 0x0
		u8 m_ucGreen; // 0x1
		u8 m_ucBlue;  // 0x2
		u8 m_ucAlpha; // 0x3
	};

	class RendererData {
	  public:
		RendererData(NiPalette*);
		virtual ~RendererData();

	  protected:
		NiPalette* m_pkPalette; // 0x4
	};

	static const NiRTTI ms_RTTI;

	virtual const NiRTTI* GetRTTI() const;
	virtual void LoadBinary(NiStream&);
	virtual void LinkObject(NiStream&);
	virtual bool RegisterStreamables(NiStream&);
	virtual void SaveBinary(NiStream&);
	virtual bool IsEqual(NiObject*);
	virtual void GetViewerStrings(NiTPrimitiveArray<char*>*);
	NiPalette(const NiPalette&);
	NiPalette(bool, unsigned int, const NiPalette::PaletteEntry*);
	NiPalette(bool, unsigned int);
	NiPalette();
	virtual ~NiPalette();
	bool GetHasAlpha() const;
	unsigned int GetNumEntries() const;
	const NiPalette::PaletteEntry* GetEntries() const;
	NiPalette::PaletteEntry* GetEntries();
	NiPalette& operator=(const NiPalette&);
	void MarkAsChanged();
	unsigned int GetRevisionID() const;
	void SetRendererData(NiPalette::RendererData*);
	NiPalette::RendererData* GetRendererData() const;
	NiPalette* GetListNext();
	NiPalette* GetListPrev();

	static NiObject* CreateObject();
	static NiPalette* GetListHead();
	static NiPalette* GetListTail();

  protected:
	static NiPalette* ms_pkHead;
	static NiPalette* ms_pkTail;
	static NiCriticalSection ms_kPaletteListCriticalSection;

	bool m_bAlpha;							   // 0x08
	unsigned int m_uiEntries;				   // 0x0c
	unsigned int m_uiRevID;					   // 0x10
	NiPalette::PaletteEntry* m_pkPalette;	   // 0x14
	NiPalette::RendererData* m_pkRendererData; // 0x18
	NiPalette* m_pkPrev;					   // 0x1c
	NiPalette* m_pkNext;					   // 0x20

	void AddPaletteToList();
	void RemovePaletteFromList();
	void CreateRendererData();
};
