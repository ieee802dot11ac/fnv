#pragma once

#include "nimain/NiObject.h"
#include "nimain/NiPixelFormat.h"
#include "nimain/NiRect.h"

class Ni2DBuffer : public NiObject {
  public:
	enum CopyFilterPreference {
		COPY_FILTER_NONE = 0x0000,
		COPY_FILTER_POINT = 0x0001,
		COPY_FILTER_LINEAR = 0x0002,
		COPY_FILTER_MAX = 0x0003,
	};
	enum MultiSamplePreference {
		MULTISAMPLE_NONE = 0x0000,
		MULTISAMPLE_2 = 0x0001,
		MULTISAMPLE_4 = 0x0002,
		MULTISAMPLE_8 = 0x0003,
	};
	class RendererData : public NiRefObject {
	  public:
		virtual ~RendererData();
		unsigned int GetWidth() const;
		unsigned int GetHeight() const;
		Ni2DBuffer::MultiSamplePreference GetMSAAPref() const;
		const NiPixelFormat* GetPixelFormat() const;
		// virtual NiXenon2DBufferData *IsNiXenon2DBufferData();
		RendererData(const Ni2DBuffer::RendererData&);

	  protected:
		RendererData(Ni2DBuffer*);
		RendererData();

		Ni2DBuffer* m_pkBuffer;						   // 0x08
		const NiPixelFormat* m_pkPixelFormat;		   // 0x0c
		Ni2DBuffer::MultiSamplePreference m_eMSAAPref; // 0x10
	};

	static const NiRTTI ms_RTTI;

	virtual const NiRTTI* GetRTTI() const;
	virtual void LoadBinary(NiStream&);
	virtual void LinkObject(NiStream&);
	virtual bool RegisterStreamables(NiStream&);
	virtual void SaveBinary(NiStream&);
	virtual bool IsEqual(NiObject*);
	virtual void GetViewerStrings(NiTPrimitiveArray<char*>*);
	virtual ~Ni2DBuffer();
	uint GetWidth() const;
	uint GetHeight() const;
	const NiPixelFormat* GetPixelFormat() const;
	Ni2DBuffer::MultiSamplePreference GetMSAAPref() const;
	virtual bool FastCopy(Ni2DBuffer*, const NiRect<uint>*, uint, uint) const;
	virtual bool Copy(Ni2DBuffer*, const NiRect<uint>*, const NiRect<uint>*,
					  Ni2DBuffer::CopyFilterPreference) const;
	void SetRendererData(Ni2DBuffer::RendererData*);
	Ni2DBuffer::RendererData* GetRendererData() const;
	void ResetDimensions(uint, uint);
	Ni2DBuffer(const Ni2DBuffer&);

	static NiObject* CreateObject();
	static Ni2DBuffer* Create(uint, uint);
	static Ni2DBuffer* Create(uint, uint, Ni2DBuffer::RendererData*);

  protected:
	Ni2DBuffer();
	virtual bool CreateRendererData(const NiPixelFormat&,
									Ni2DBuffer::MultiSamplePreference);

	uint m_uiWidth;										  // 0x08
	uint m_uiHeight;									  // 0x0c
	NiPointer<Ni2DBuffer::RendererData> m_spRendererData; // 0x10
};
