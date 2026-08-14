#pragma once

#include "nimain/NiAccumulator.h"
#include "nimain/NiDynamicEffectState.h"
#include "nimain/NiObject.h"
#include "nimain/NiPoint3.h"
#include "nimain/NiPropertyState.h"
#include "nimain/NiShader.h"
#include "nisystem/NiCriticalSection.h"

class NiRenderer : public NiObject {
  public:
	enum ClearFlags {
		CLEAR_BACKBUFFER = 0x0001,
		CLEAR_STENCIL = 0x0002,
		CLEAR_ZBUFFER = 0x0004,
		CLEAR_NONE = 0x0000,
		CLEAR_ALL = 0x0007,
	};
	enum EFrameState {
		FRAMESTATE_OUTSIDE_FRAME = 0x0000,
		FRAMESTATE_INSIDE_FRAME = 0x0001,
		FRAMESTATE_INSIDE_OFFSCREEN_FRAME = 0x0002,
		FRAMESTATE_WAITING_FOR_DISPLAY = 0x0003,
	};

	static const NiRTTI ms_RTTI;
	static NiPoint3 PosAdjust;
	static bool bPosAdjust;
	static int iMaxAnisotropy;

	virtual const NiRTTI* GetRTTI() const;
	virtual void GetViewerStrings(NiTPrimitiveArray<char*>*);
	bool WaitRenderFinished(unsigned int);
	NiRenderer(const NiRenderer&);
	NiRenderer();
	virtual ~NiRenderer();
	unsigned int LockCount() const;
	unsigned int GetFrameID() const;
	EFrameState GetFrameState() const;
	bool GetInsideFrameState() const;
	bool IsRenderTargetGroupActive() const;
	bool EndUsingRenderTargetGroup();
	void SetSorter(NiAccumulator*);
	NiAccumulator* GetSorter() const;
	bool GetBatchRendering() const;
	// bool
	// PrecacheGeometry(NiGeometry *, unsigned int, unsigned int,
	// NiD3DShaderDeclaration
	// *);
	NiShader* GetErrorShader() const;
	void SetErrorShader(NiShader*);
	NiPropertyState* GetPropertyState() const;
	void SetPropertyState(NiPropertyState*);
	NiDynamicEffectState* GetEffectState() const;
	void SetEffectState(NiDynamicEffectState*);
	void LockSourceDataCriticalSection();
	void UnlockSourceDataCriticalSection();
	virtual void DoMinimalFlip();

	static NiPoint3& QPosAdjust();
	static void SetPosAdjust(const NiPoint3&);
	static const char* GetLastErrorString();
	static void ClearLastErrorString();
	static void SetLastErrorString(const char*);
	static void Message(const char*, ...);
	static void Warning(const char*, ...);
	static void Error(const char*, ...);
	static void _SDMShutdown();
	static NiRenderer* QRenderer();
	static bool PackParticleStripUtil_GetVerts(const NiPoint3**,
											   const NiPoint3*, const NiPoint3*,
											   float, NiPoint3*, NiPoint3*,
											   NiPoint3&);
	static bool PackParticleStripUtil_GetVerts(const NiPoint3*, const NiPoint3*,
											   const NiPoint3*, float,
											   NiPoint3*, NiPoint3*, NiPoint3&);

  protected:
	static char ms_acErrorString[256];
	static NiRenderer* ms_pkRenderer;

	void Do_BeginBatch(NiPropertyState*, NiDynamicEffectState*);
	void Do_EndBatch();
	void Do_BatchRenderShape(NiTriShape*);
	void Do_BatchRenderStrips(NiTriStrips*);
	void LockPrecacheCriticalSection();
	void UnlockPrecacheCriticalSection();
	bool Check_FrameState(const char*, EFrameState) const;
	bool Check_RenderTargetGroupActive(const char*, bool) const;
	bool Check_BatchRendering(const char*, bool) const;

	NiPointer<NiAccumulator> m_spAccum;				// 0x008
	NiPropertyState* m_pkCurrProp;					// 0x00c
	NiDynamicEffectState* m_pkCurrEffects;			// 0x010
	NiPointer<NiShader> m_spErrorShader;			// 0x014
	NiCriticalSection m_kRendererLock;				// 0x080
	NiCriticalSection m_kPrecacheCriticalSection;	// 0x100
	NiCriticalSection m_kSourceDataCriticalSection; // 0x180
	EFrameState m_eFrameState;						// 0x200
	unsigned int m_uiFrameID;						// 0x204
	bool m_bRenderTargetGroupActive;				// 0x208
	bool m_bBatchRendering;							// 0x209
};
