#pragma once

#include "d3d9i/d3d9.h"
#include "d3d9i/d3d9caps.h"
#include "d3d9i/d3d9types.h"
#include "nimain/NiRenderer.h"

class NiXenonRenderer : public NiRenderer {
  public:
	static const NiRTTI ms_RTTI;
	static bool m_bObliqueViewFrustum;
	static float m_fWaterHeight;
	static bool bInstantResourceRelease;
	static bool bInstantDeviceRelease;
	static bool bInstantVertexDeclRelease;
	static bool bInstantTextureRelease;

	virtual const NiRTTI* GetRTTI() const;
	bool BeginFrame();
	bool EndFrame();
	bool DisplayFrame();
	bool BeginOffScreenFrame();
	bool EndOffScreenFrame();
	void ClearBuffer(const NiRect<float>*, uint);
	void SetCameraData(const NiCamera*);
	void SetCameraData(const NiPoint3&, const NiPoint3&, const NiPoint3&,
					   const NiPoint3&, const NiFrustum&, const NiRect<float>&);
	void SetScreenSpaceCameraData(const NiRect<float>*);
	bool BeginUsingRenderTargetGroup(NiRenderTargetGroup*, uint);
	bool BeginUsingDefaultRenderTargetGroup(uint);
	bool EndUsingRenderTargetGroup();
	void RenderShape(NiTriShape*);
	void RenderTristrips(NiTriStrips*);
	void OnlyRenderShape(NiTriShape*);
	void OnlyRenderTristrips(NiTriStrips*);
	void RenderPoints(NiParticles*);
	void RenderParticleStrips(NiParticles*);
	void RenderLines(NiLines*);
	void RenderScreenTexture(NiScreenTexture*);
	virtual void SetDefaultProgramCache(NiFragmentMaterial*, bool, bool, bool,
										bool, const char*);
	void SetDefaultProgramCache(NiFragmentMaterial*);
	void PurgeAllRendererData(NiAVObject*);
	bool MapWindowPointToBufferPoint(uint, uint, float&, float&,
									 const NiRenderTargetGroup*);
	virtual const NiPixelFormat*
	FindClosestDepthStencilFormat(const NiPixelFormat*, uint, uint) const;
	const NiPixelFormat*
	FindClosestDepthStencilFormat(const NiPixelFormat*) const;
	uint GetBackbufferWidth();
	uint GetBackbufferHeight();
	uint GetOffscreenRenderTargetWidth();
	uint GetOffscreenRenderTargetHeight();
	void LockRenderer();
	void UnlockRenderer();
	void SetOutsideFrame();
	void LockPrecacheCriticalSection();
	void UnlockPrecacheCriticalSection();
	virtual void DoMinimalFlip();
	void WaitForRenderingToFinish();
	void SetClippingPlanes(int, int, float*);
	void StartRenderEvent();
	void EndRenderEvent();
	bool WaitRenderFinished(uint);
	virtual ~NiXenonRenderer();
	bool Recreate();
	NiXenonRenderer::RecreateStatus Recreate(uint, uint);
	NiXenonRenderer::RecreateStatus
		Recreate(uint, uint, uint, D3DFORMAT, D3DFORMAT, D3DFORMAT,
				 NiXenonRenderer::PresentationInterval, uint);
	uint GetResetCounter() const;
	void UseQuickDecals(bool);
	void PerformPrecache();
	NiXenonShaderDeclaration* CreateShaderDeclaration(uint, uint);
	NiPointer<NiTexture> CreateNiTextureFromD3DTexture(D3DBaseTexture*);
	virtual const NiPixelFormat*
	FindClosestPixelFormat(NiTexture::FormatPrefs&) const;
	virtual const NiPixelFormat*
		FindClosestPixelFormat(NiXenonRenderer::TexFormat,
							   NiXenonRenderer::TexUsage);
	void PurgeVertexShader(NiD3DVertexShader*);
	void PurgePixelShader(NiD3DPixelShader*);
	void RegisterD3DShader(NiD3DShaderInterface*);
	void ReleaseD3DShader(NiD3DShaderInterface*);
	void PurgeD3DShader(NiD3DShaderInterface*);
	void PurgeAllD3DShaders();
	D3DDevice* GetD3DDevice() const;
	D3DPRESENT_PARAMETERS* GetPresentParams() const;
	const D3DCAPS9* GetDeviceCaps() const;
	const D3DRING_BUFFER_PARAMETERS& GetRingBufferParameters() const;
	bool SetRingBufferParameters(D3DRING_BUFFER_PARAMETERS&);
	NiXenonRenderState* GetRenderState() const;
	NiXenonVertexBufferManager* GetVBManager() const;
	NiXenonTextureManager* GetTextureManager() const;
	uint GetMaxStreams() const;
	uint GetPixelShaderVersion() const;
	uint GetVertexShaderVersion() const;
	bool GetMipmapCubeMaps() const;
	bool IsDynamicTexturesCapable() const;
	bool GetMRTPostPixelShaderBlendingCapability() const;
	bool GetFormatPostPixelShaderBlendingCapability(_D3DFORMAT) const;
	bool GetSWVertexCapable() const;
	bool GetSWVertexSwitchable() const;
	void ClearDefaultPipelineShaders();
	void LoadDefaultPipelineShaderCache(const char*);
	void SetDefaultPipelineShaderCacheSaveFile(const char*);
	virtual const char* GetDriverInfo() const;
	virtual uint GetFlags() const;
	virtual void SetDepthClear(const float);
	virtual float GetDepthClear() const;
	virtual void SetBackgroundColor(const NiColorA&);
	virtual void SetBackgroundColor(const NiColor&);
	virtual void GetBackgroundColor(NiColorA&) const;
	virtual void SetStencilClear(uint);
	virtual uint GetStencilClear() const;
	virtual bool ValidateRenderTargetGroup(NiRenderTargetGroup*);
	virtual bool IsDepthBufferCompatible(Ni2DBuffer*, NiDepthStencilBuffer*);
	virtual NiRenderTargetGroup* GetDefaultRenderTargetGroup() const;
	virtual const NiRenderTargetGroup* GetCurrentRenderTargetGroup() const;
	virtual NiDepthStencilBuffer* GetDefaultDepthStencilBuffer() const;
	virtual Ni2DBuffer* GetDefaultBackBuffer() const;
	void UpdateFloatingPointDepthBuffer(Ni2DBuffer*);
	bool IsFloatingPointDepthUsed();
	void SetTilingSplitAspectRatio(float);
	float GetTilingSplitAspectRatio();
	virtual uint GetMaxBuffersPerRenderTargetGroup() const;
	virtual bool GetIndependentBufferBitDepths() const;
	virtual bool PrecacheTexture(NiTexture*, bool, bool);
	virtual bool SetMipmapSkipLevel(uint);
	virtual uint GetMipmapSkipLevel() const;
	virtual bool PrecacheGeometry(NiGeometry*, uint, uint,
								  NiD3DShaderDeclaration*);
	virtual void PurgeGeometryData(NiGeometryData*);
	virtual void PurgeMaterial(NiMaterialProperty*);
	virtual void PurgeEffect(NiDynamicEffect*);
	virtual void PurgeScreenTextureRendererData(NiScreenTexture*);
	virtual void PurgeSkinPartitionRendererData(NiSkinPartition*);
	virtual void PurgeSkinInstance(NiSkinInstance*);
	virtual bool PurgeTexture(NiTexture*);
	virtual bool PurgeAllTextures(bool);
	virtual NiPixelData* TakeScreenShot(const NiRect<uint>*,
										const NiRenderTargetGroup*);
	virtual bool FastCopy(const Ni2DBuffer*, Ni2DBuffer*, const NiRect<uint>*,
						  uint, uint);
	virtual bool Copy(const Ni2DBuffer*, Ni2DBuffer*, const NiRect<uint>*,
					  const NiRect<uint>*, Ni2DBuffer::CopyFilterPreference);
	void DiscardCopySurface();
	bool RestoreDepthStencilBuffer(NiResolvableDepthStencilBuffer*, float);
	virtual bool GetLeftRightSwap() const;
	virtual bool SetLeftRightSwap(bool);
	virtual float GetMaxFogValue() const;
	virtual void SetMaxFogValue(float);
	virtual u8* AllocateVertexBufferMemory(uint);
	virtual void ProtectVertexBufferMemory(void*, uint);
	virtual void UnprotectVertexBufferMemory(void*, uint);
	virtual void FreeVertexBufferMemory(void*);
	float GetDepthRange() const;
	void SetModelTransform(const NiTransform&, bool);
	void SetSkinnedModelTransforms(const NiSkinInstance*,
								   const NiSkinPartition::Partition*,
								   const NiTransform&);
	void CalculateBoneMatrices(const NiSkinInstance*, const NiTransform&, bool,
							   uint, bool);
	void DrawPrimitive(NiGeometry*, NiGeometryData*, NiSkinInstance*,
					   const NiTransform&, const NiBound&,
					   NiGeometryBufferData*);
	void DrawSkinnedPrimitive(NiGeometry*, NiGeometryData*,
							  const NiSkinInstance*, const NiTransform&,
							  const NiBound&);
	void FreeGeometricData(NiGeometryData*, NiSkinInstance*,
						   NiSkinPartition::Partition*);
	virtual bool CreateSourceTextureRendererData(NiSourceTexture*);
	virtual bool
	CreateRenderedTextureRendererData(NiRenderedTexture*,
									  Ni2DBuffer::MultiSamplePreference);
	virtual bool CreateSourceCubeMapRendererData(NiSourceCubeMap*);
	virtual bool CreateRenderedCubeMapRendererData(NiRenderedCubeMap*);
	virtual bool CreateDynamicTextureRendererData(NiDynamicTexture*);
	virtual void CreatePaletteRendererData(NiPalette*);
	virtual bool
	CreateDepthStencilRendererData(NiDepthStencilBuffer*, const NiPixelFormat*,
								   Ni2DBuffer::MultiSamplePreference);
	void AddRenderedCubeMapData(NiRenderedCubeMap*);
	void RemoveRenderedCubeMapData(NiRenderedCubeMap*);
	void AddRenderedTextureData(NiRenderedTexture*);
	void RemoveRenderedTextureData(NiRenderedTexture*);
	virtual void RemoveDynamicTextureData(NiDynamicTexture*);
	virtual void* LockDynamicTexture(const NiTexture::RendererData*, int&);
	virtual bool UnLockDynamicTexture(const NiTexture::RendererData*);
	virtual NiShader* GetFragmentShader(NiMaterialDescriptor*);
	NiPixelFormat** GetTextureFormatArray(NiXenonRenderer::TexUsage);
	const NiPixelFormat*
		GetDefaultTextureFormat(NiXenonRenderer::TexUsage) const;
	const NiPixelData* GetDefaultTextureData(NiXenonRenderer::TexUsage) const;
	NiXenonRenderer::TexFormat GetReplacementDataFormat() const;
	NiTexture* GetClipperTexture() const;
	bool AddTask(NiXenonRendererTask*, NiTaskManager::TaskPriority);
	const D3DMATRIX& GetD3DMat() const;
	const D3DMATRIX& GetD3DView() const;
	const D3DMATRIX& GetD3DProj() const;
	const D3DMATRIX& GetInvView() const;
	const D3DXMATRIX* GetD3DViewProj() const;
	const D3DXMATRIX* GetD3DWorld() const;
	void ReleaseThreadOwnership();
	void AcquireThreadOwnership();
	uint QOwningThread();
	void WaitForRendererTaskCompletion();
	void SetMinPixelShaderVersion(uint, uint);
	void SetPixelShaderVersionRequest(uint, uint);
	void SetMinVertexShaderVersion(uint, uint);
	void SetVertexShaderVersionRequest(uint, uint);
	void SetSystemUserVersion(uint, uint);
	void SetMinUserVersion(uint, uint);
	void SetUserVersionRequest(uint, uint);
	uint GetMinPixelShaderVersion() const;
	uint GetPixelShaderVersionRequest() const;
	uint GetMinVertexShaderVersion() const;
	uint GetVertexShaderVersionRequest() const;
	uint GetMinUserVersion() const;
	uint GetUserVersionRequest() const;
	const NiD3DShaderLibraryVersion* GetShaderLibraryVersion() const;
	bool PackGeometryBuffer(NiGeometryBufferData*, NiGeometryData*,
							NiSkinInstance*, NiD3DShaderDeclaration*, bool);
	bool PackSkinnedGeometryBuffer(NiGeometryBufferData*, NiGeometryData*,
								   const NiSkinInstance*,
								   NiSkinPartition::Partition*,
								   NiD3DShaderDeclaration*, bool);
	D3DVertexDeclaration* CreateVertexDecl(_D3DVERTEXELEMENT9*);
	bool IsCopySurfaceValid(Ni2DBuffer*);
	NiVBChip* CreateVBChipForAGD(BSPackedAdditionalGeometryData*,
								 const NiSkinInstance*,
								 NiSkinPartition::Partition*);
	D3DVertexDeclaration* GetD3DDeclarationFromIndex(uint);
	NiD3DShaderDeclaration* GetShaderDeclarationFromIndex(uint);
	virtual bool GetWidescreen();
	virtual void Do_DrawPartition(NiGeometryData::RendererData*,
								  NiSkinPartition::Partition*, NiGeometryData*);
	NiXenonRenderer(const NiXenonRenderer&);
	bool IsHardwareSkinned(NiGeometry*, const NiD3DShaderInterface*);
	NiXenonRenderTargetGroupData*
	GetRenderTargetGroupData(NiRenderTargetGroup*) const;
	static void RemoveEffect(NiDynamicEffect*);
	static void RemoveGeometryData(NiGeometryData*);
	static void RemoveMaterial(NiMaterialProperty*);
	static void RemoveScreenTextureRendererData(NiScreenTexture*);
	static void RemoveSkinPartitionRendererData(NiSkinPartition*);
	static void RemoveSkinInstance(NiSkinInstance*);
	static void Callback(uint);
	static NiXenonRenderer* Create(uint, uint, uint, _D3DFORMAT, _D3DFORMAT,
								   _D3DFORMAT,
								   NiXenonRenderer::PresentationInterval, uint);
	static void AddDisplayFormat(_D3DFORMAT);
	static void RemoveDisplayFormat(_D3DFORMAT);
	static Direct3D* GetDirect3D();
	static void PrepareForStreaming(NiObjectNET*);
	static void RestoreAfterStreaming();
	static const char* GetD3DFormatString(_D3DFORMAT);
	static _D3DMULTISAMPLE_TYPE GetMultiSampleType(uint);
	static uint GetPresentInterval(NiXenonRenderer::PresentationInterval);
	static NiXenonRenderer* GetRenderer();
	static uint CreateVertexFlags(bool, bool, bool, uint);
	static bool GetHasColorsFromFlags(uint);
	static bool GetHasNormalsFromFlags(uint);
	static bool GetHasBinormalsTangentsFromFlags(uint);
	static uint GetNumUVsFromFlags(uint);
	static void ReleaseResource(D3DResource*);
	static void ReleaseVBResource(D3DVertexBuffer*);
	static void ReleaseIBResource(D3DIndexBuffer*);
	static void ReleaseDevice(D3DDevice*);
	static void ReleaseVertexDecl(D3DVertexDeclaration*);
	static void ReleaseTexture(D3DBaseTexture*, uint);
	static uint DoUpgrade(NiXenonTextureData*, D3DBaseTexture*);
	static void UpgradeTexture(NiTexture*, D3DBaseTexture*);
	static void DoDegrade(NiXenonTextureData*);
	static void DegradeTexture(NiTexture*);
	static void _SDMShutdown();
	static NiXenonRenderer::AddressSettings
		GetD3DClampMode(NiTexturingProperty::ClampMode);
	static NiXenonRenderer::FilterSettings
		GetD3DFilterMode(NiTexturingProperty::FilterMode);
	static uint GetProjectedTextureFlags();

  protected:
	static Direct3D* ms_pkD3D9;
	static NiTPointerList<uint> ms_kDisplayFormats;
	static NiXenonRenderer::AddressSettings ms_akD3DAddressMapping[4];
	static NiXenonRenderer::FilterSettings ms_akD3DFilterMapping[8];
	static uint ms_uiProjectedTextureFlags;
	static NiPointer<NiXenonShaderDeclaration> ms_aspDeclarations[256];

	void* PackStripParticleVertex(NiXenonRenderer::SourceNormalVertex*,
								  const NiPoint3&, const NiPoint3&, uint, u16,
								  u16, float);
	void* PackStripParticleVertex(NiXenonRenderer::SourceNormalVertex*,
								  const NiPoint3&, int, uint, u16, u16, float);
	NiXenonRenderer();
	void InitToDefault();
	bool LostDeviceRestore();
	bool InitializePresentParams(uint, uint, uint, uint, _D3DFORMAT, _D3DFORMAT,
								 _D3DFORMAT,
								 NiXenonRenderer::PresentationInterval,
								 _D3DPRESENT_PARAMETERS_&) const;
	bool InitializeTextureDefaults();
	bool InitializeDeviceCaps(const _D3DPRESENT_PARAMETERS_&);
	virtual void Do_LockRenderer();
	virtual void Do_UnlockRenderer();
	virtual bool Do_BeginFrame();
	virtual bool Do_EndFrame();
	virtual bool Do_DisplayFrame();
	virtual void Do_ClearBuffer(const NiRect<float>*, uint);
	virtual void Do_SetCameraData(const NiPoint3&, const NiPoint3&,
								  const NiPoint3&, const NiPoint3&,
								  const NiFrustum&, const NiRect<float>&);
	virtual void Do_SetScreenSpaceCameraData(const NiRect<float>*);
	virtual bool Do_BeginUsingRenderTargetGroup(NiRenderTargetGroup*, uint);
	virtual bool Do_EndUsingRenderTargetGroup();
	virtual void Do_BeginBatch(NiPropertyState*, NiDynamicEffectState*);
	virtual void Do_EndBatch();
	virtual void Do_BatchRenderShape(NiTriShape*);
	virtual void Do_BatchRenderStrips(NiTriStrips*);
	virtual void Do_RenderShape(NiTriShape*);
	virtual void Do_RenderTristrips(NiTriStrips*);
	virtual void Do_OnlyRenderShape(NiTriShape*);
	virtual void Do_OnlyRenderTristrips(NiTriStrips*);
	virtual void Do_RenderPoints(NiParticles*);
	void PackPoints(NiXenonRenderer::VBParticles*, NiPoint3*, NiColorA*, float*,
					float*, float*, u8*, u16);
	void PackPointIndices(u16*, uint, u16*);
	virtual void Do_RenderParticleStrips(NiParticles*);
	uint PackParticleStrips(NiXenonRenderer::SourceNormalVertex*, u16*,
							NiParticlesData*);
	virtual void Do_RenderLines(NiLines*);
	virtual void Do_RenderScreenTexture(NiScreenTexture*);
	void PackScreenTextureGeomBuffer(NiScreenTexture*);
	void PackScreenTextureBuffers(NiScreenTexture*, u16);
	void ClearStreams();
	void ClearTextures();
	void ClearShaders();
	bool PrePackGeometryBuffer(NiGeometry*, NiGeometryData*, u16, u16,
							   const u16*, const u16*, u16,
							   NiD3DShaderDeclaration*);
	bool PrePackSkinnedGeometryBuffer(NiGeometry*, NiGeometryData*,
									  NiSkinInstance*, NiD3DShaderDeclaration*,
									  uint, uint);
	bool ReservePrepackedBufferSpace(NiGeometryBufferData*, NiGeometryData*,
									 NiSkinPartition::Partition*,
									 NiD3DShaderDeclaration*);
	void EmptyBatch();
	void RenderBatch();
	void AddToBatch(NiGeometry*);
	bool GenerateDefaultTextureData();
	void CreatePixelFormatArray(NiPixelFormat**, uint, _D3DRESOURCETYPE);
	void CreatePrepackedShaderDeclarations();
	D3DVertexShader* GetVS_Copy();
	D3DPixelShader* GetPS_Copy();
	D3DVertexDeclaration* GetDecl_Pos();
	D3DVertexDeclaration* GetDecl_PosNorm();
	D3DVertexDeclaration* GetDecl_PosNormUV0();
	D3DVertexDeclaration* GetDecl_PosNormColor();
	D3DVertexDeclaration* GetDecl_PosColor();
	D3DVertexDeclaration* GetDecl_PosUV0();
	D3DVertexDeclaration* GetDecl_PosColorUV0();
	D3DVertexDeclaration* GetDecl_PosNormColorUV0();
	D3DVertexDeclaration* GetDecl_SourceNormalVertex();
	D3DVertexDeclaration* GetDecl_ParticlesSubTexture();
	D3DVertexDeclaration* GetDecl_FromFVF(uint);
	D3DVertexDeclaration* GetDecl_Particles();

#pragma region Members
  public:
	volatile uint iRenderFence; // 0x280
	uint iOwningThread;			// 0x284
	bool m_bWidescreen;			// 0x288
  protected:
	D3DDevice* m_pkD3DDevice9;					   // 0x28c
	D3DCAPS9 m_kD3DCaps9;						   // 0x290
	D3DRING_BUFFER_PARAMETERS m_kRingBufferParams; // 0x3c0
	uint m_uiBehaviorFlags;						   // 0x3d8
	bool m_bCopyTouchedEDRAM;					   // 0x3dc
	uint m_uiBackground;						   // 0x3e0
	float m_fZClear;							   // 0x3e4
	uint m_uiStencilClear;						   // 0x3e8
	bool m_bFloatingPointDepthUsed;				   // 0x3ec
	bool m_bResolvableDSRecreate;				   // 0x3ed
	uint m_uiResolveClearMode;					   // 0x3f0
	uint m_uiResolveClearColor;					   // 0x3f4
	uint m_uiResolveClearStencil;				   // 0x3f8
	float m_fResolveClearZ;						   // 0x3fc
	uint m_uiRendFlags;							   // 0x400
	char m_acBehavior[32];						   // 0x404
	NiTPointerMap<NiVBBlock*, NiXenonRenderer::PrePackObject*>
		m_kPrePackObjects;										 // 0x424
	NiXenonRenderer::BatchedObject* m_pkBatchHead;				 // 0x434
	NiXenonRenderer::BatchedObject* m_pkBatchTail;				 // 0x438
	NiPropertyState* m_pkBatchedPropertyState;					 // 0x43c
	NiDynamicEffectState* m_pkBatchedEffectState;				 // 0x440
	NiPointer<NiD3DShaderInterface> m_spBatchedShader;			 // 0x444
	NiPoint3 m_kCamRight;										 // 0x448
	NiPoint3 m_kCamUp;											 // 0x454
	NiPoint3 m_kModelCamRight;									 // 0x460
	NiPoint3 m_kModelCamUp;										 // 0x46c
	NiBound m_kWorldBound;										 // 0x478
	const NiBound m_kDefaultBound;								 // 0x488
	float m_fNearDepth;											 // 0x498
	float m_fDepthRange;										 // 0x49c
	D3DMATRIX m_kD3DIdentity;									 // 0x4a0
	D3DVIEWPORT9 m_kD3DPort;									 // 0x4e0
	uint m_uiHWBones;											 // 0x4f8
	uint m_uiMaxStreams;										 // 0x4fc
	uint m_uiMaxPixelShaderVersion;								 // 0x500
	uint m_uiMaxVertexShaderVersion;							 // 0x504
	bool m_bMipmapCubeMaps;										 // 0x508
	bool m_bDynamicTexturesCapable;								 // 0x509
	uint m_uiResetCounter;										 // 0x50c
	NiPixelFormat* m_aapkTextureFormats[5][22];					 // 0x510
	NiPixelFormat* m_apkDefaultTextureFormat[5];				 // 0x6c8
	NiPointer<NiPixelData> m_aspDefaultTextureData[5];			 // 0x6dc
	NiXenonRenderer::TexFormat m_eReplacementDataFormat;		 // 0x6f0
	NiPointer<NiRenderTargetGroup> m_spDefaultRenderTargetGroup; // 0x6f4
	NiRenderTargetGroup* m_pkCurrRenderTargetGroup;				 // 0x6f8
	uint m_uiMaxNumRenderTargets;								 // 0x6fc
	bool m_bIndependentBitDepths;								 // 0x700
	bool m_bMRTPostPixelShaderBlending;							 // 0x701
	float m_fTilingSplitAspectRatio;							 // 0x704
	NiPropertyState* m_spScreenTexturePropertyState;			 // 0x708
  public:
	NiD3DGeometryGroupManager* m_pkGeometryGroupManager; // 0x70c
	NiUnsharedGeometryGroup* m_pkDefaultGroup;			 // 0x710
	NiDynamicGeometryGroup* m_pkDynamicGroup;			 // 0x714
  protected:
	NiXenonRenderState* m_pkRenderState;	   // 0x718
	NiXenonVertexBufferManager* m_pkVBManager; // 0x71c
	NiXenonIndexBufferManager* m_pkIBManager;  // 0x720
	NiXenonTextureManager* m_pkTextureManager; // 0x724
	NiTPointerMap<NiRenderedTexture*, NiXenonRenderedTextureData*>
		m_kRenderedTextures; // 0x728
	NiTPointerMap<NiRenderedCubeMap*, NiXenonRenderedCubeMapData*>
		m_kRenderedCubeMaps; // 0x738
	NiTPointerMap<NiDynamicTexture*, NiXenonDynamicTextureData*>
		m_kDynamicTextures;										  // 0x748
	NiTPointerList<NiD3DShaderInterface*> m_kD3DShaders;		  // 0x758
	NiD3DShaderLibraryVersion m_kShaderLibraryVersion;			  // 0x764
	NiPointer<NiXenon2DBufferData> m_spBufferToUseAtDisplayFrame; // 0x78c
	D3DXMATRIX m_kD3DMat;										  // 0x790
	D3DXMATRIX m_kD3DView;										  // 0x7d0
	D3DXMATRIX m_kD3DProj;										  // 0x810
	D3DXMATRIX m_kD3DViewProj;									  // 0x850
	D3DXMATRIX m_kInvView;										  // 0x890
	NiPoint2* m_pkScreenTextureVerts;							  // 0x8d0
	NiColorA* m_pkScreenTextureColors;							  // 0x8d4
	NiPoint2* m_pkScreenTextureTexCoords;						  // 0x8d8
	u16* m_pusScreenTextureIndices;								  // 0x8dc
	u16 m_usNumScreenTextureVerts;								  // 0x8e0
	uint m_uiNumScreenTextureIndices;							  // 0x8e4
	NiPointer<NiMaterial> m_spLegacyDefaultShaderMaterial;		  // 0x8e8
	NiVertexDeclCache* m_pkDeclCache;							  // 0x8ec
	D3DSurface* m_pkCopySurface;								  // 0x8f0
	D3DVertexDeclaration* m_hDecl_Pos;							  // 0x8f4
	D3DVertexDeclaration* m_hDecl_PosNorm;						  // 0x8f8
	D3DVertexDeclaration* m_hDecl_PosNormUV0;					  // 0x8fc
	D3DVertexDeclaration* m_hDecl_PosNormColor;					  // 0x900
	D3DVertexDeclaration* m_hDecl_PosColor;						  // 0x904
	D3DVertexDeclaration* m_hDecl_PosUV0;						  // 0x908
	D3DVertexDeclaration* m_hDecl_PosColorUV0;					  // 0x90c
	D3DVertexDeclaration* m_hDecl_PosNormColorUV0;				  // 0x910
	D3DVertexDeclaration* m_hDecl_SourceNormalVertex;			  // 0x914
	D3DVertexDeclaration* m_hDecl_VBParticlesSubTex;			  // 0x918
	D3DVertexDeclaration* m_hDecl_Particles;					  // 0x91c
	D3DVertexShader* m_pkVS_Copy;								  // 0x920
	D3DPixelShader* m_pkPS_Copy;								  // 0x924

	static int CreateDirect3D9();
};
