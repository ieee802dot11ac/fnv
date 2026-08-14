#pragma once

#include "nimain/NiCamera.h"
#include "nimain/NiColor.h"
#include "nimain/NiPoint3.h"
#include "nimain/NiQuaternion.h"
#include "nimain/nistream.h"

class NiParticlesData : public NiGeometryData {
  public:
	static const NiRTTI ms_RTTI;
	static const u8 MAX_SUBTEXTURE_COUNT;

	virtual const NiRTTI* GetRTTI() const;
	virtual void LoadBinary(NiStream&);
	virtual void LinkObject(NiStream&);
	virtual bool RegisterStreamables(NiStream&);
	virtual void SaveBinary(NiStream&);
	virtual bool IsEqual(NiObject*);
	virtual void GetViewerStrings(NiTPrimitiveArray<char*>*);
	NiParticlesData(const NiParticlesData&);
	NiParticlesData();
	NiParticlesData(u16, NiPoint3*, NiPoint3*, NiColorA*, NiQuaternion*, float*,
					NiPoint3*);
	virtual ~NiParticlesData();
	const float* GetRadii() const;
	float* GetRadii();
	const float* GetSizes() const;
	float* GetSizes();
	const u8* GetTextureIndices() const;
	u8* GetTextureIndices();
	const NiColorA* GetSubTextureOffsets() const;
	NiColorA* GetSubTextureOffsets();
	const u8 GetSubTextureOffsetCount() const;
	u8 GetSubTextureOffsetCount();
	const NiQuaternion* GetRotations() const;
	NiQuaternion* GetRotations();
	const float* GetRotationAngles() const;
	float* GetRotationAngles();
	const NiPoint3* GetRotationAxes() const;
	NiPoint3* GetRotationAxes();
	virtual void SetActiveVertexCount(u16);
	virtual u16 GetActiveVertexCount() const;
	void ReplaceRadii(float*);
	void ReplaceSizes(float*);
	void ReplaceRotations(NiQuaternion*);
	void ReplaceRotationAngles(float*);
	void ReplaceRotationAxes(NiPoint3*);
	void ReplaceTextureIndices(u8*);
	void ReplaceSubTextureOffsets(NiColorA*, u8);
	virtual void RemoveParticle(u16);
	void SetRadiiData(float*);
	void SetSizesData(float*);
	void SetRotationsData(NiQuaternion*);
	void SetRotationAnglesData(float*);
	void SetRotationAxesData(NiPoint3*);
	void SetTextureIndices(u8*);
	void SetSubTextureOffsets(NiColorA*, u8);
	virtual void CalculateNormals();
	u16* GetRenderOrder();
	void SortParticles(const NiCamera*);

	static NiObject* CreateObject();
	static NiObject* CreateOldRotatingParticlesObject();

  protected:
	void QuickSortParticles(int, int);

  public:
	bool m_bIsOldRotatingParticlesObject; // 0x40
  protected:
	u16* m_ausRenderOrder;			 // 0x44
	float* m_afDepths;				 // 0x48
	float* m_pfRadii;				 // 0x4c
	u16 m_usActive;					 // 0x50
	float* m_pfSizes;				 // 0x54
	NiQuaternion* m_pkRotations;	 // 0x58
	float* m_pfRotationAngles;		 // 0x5c
	NiPoint3* m_pkRotationAxes;		 // 0x60
	u8* m_pucTextureIndices;		 // 0x64
	NiColorA* m_pkSubTextureOffsets; // 0x68
	u8 m_ucSubTextureOffsetCount;	 // 0x6c
};
