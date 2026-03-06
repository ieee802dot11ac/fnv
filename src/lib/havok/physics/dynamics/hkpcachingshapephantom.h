#pragma once

#include "hkdefs.h"
#include "lib/havok/common/base/types/hkbasetypes.h"

// class hkpCachingShapePhantom : public hkpShapePhantom {
// 	struct hkpCollisionDetail { /* Size=0x8 */
// //   hkpCollisionAgent* m_agent; // 0x0
// //   hkpCollidable* m_collidable; // 0x4

//   public: void iShouldNotHaveVtable() const;

//   HKMEMOPS_ARR
// };

//   /* 0x0000: fields for hkpShapePhantom */
//   /* 0x0150 */ protected: hkArray<hkpCachingShapePhantom::hkpCollisionDetail>
//   m_collisionDetails;

//   /* 0x015c */ public: hkBool m_orderDirty;
//   public: static const hkInternalClassMember Members[0];

//   public: hkpCachingShapePhantom(const hkpCachingShapePhantom&);
//   public: hkpCachingShapePhantom(hkFinishLoadedObjectFlag);
//   public: hkpCachingShapePhantom(const hkpShape*, const hkTransform&, uint32_t);

//   public: virtual ~hkpCachingShapePhantom();
//   public: virtual hkpPhantomType getType() const;
//   public: virtual void setPositionAndLinearCast(const hkVector4&, const
//   hkpLinearCastInput&, hkpCdPointCollector&, hkpCdPointCollector*);

//   public: virtual void setTransformAndLinearCast(const hkTransform&, const
//   hkpLinearCastInput&, hkpCdPointCollector&, hkpCdPointCollector*);

//   public: virtual hkpPhantom* clone() const;
//   public: virtual void getClosestPoints(hkpCdPointCollector&, const
//   hkpCollisionInput*);

//   public: virtual void ensureDeterministicOrder();
//   public: virtual void getPenetrations(hkpCdBodyPairCollector&, const
//   hkpCollisionInput*);

//   public: virtual void calcContentStatistics(hkStatisticsCollector*, const hkClass*)
//   const;

//   public: hkArray<hkpCachingShapePhantom::hkpCollisionDetail>& getCollisionDetails();

//   public: virtual void addOverlappingCollidable(hkpCollidable*);
//   public: virtual void removeOverlappingCollidable(hkpCollidable*);
//   public: virtual hkBool isOverlappingCollidableAdded(const hkpCollidable*);
//   public: virtual void updateShapeCollectionFilter();
//   public: virtual void deallocateInternalArrays();

//   public: static const hkClass& staticClass();
// };
