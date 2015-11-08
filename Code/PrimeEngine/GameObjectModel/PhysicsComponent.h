#ifndef __PYENGINE_2_0_PHYSICS_COMPONENT__
#define __PYENGINE_2_0_PHYSICS_COMPONENT__

// API Abstraction
#include "PrimeEngine/APIAbstraction/APIAbstractionDefines.h"

// Outer-Engine includes
#include <assert.h>
#include "../Math/Vector3.h"

// Inter-Engine includes
//#include "../Scene/CameraSceneNode.h"

// Sibling/Children includes

namespace PE {
	namespace Components {

		struct PhysicsComponent : public Component
		{
			PE_DECLARE_CLASS(PhysicsComponent);


			// Constructor -------------------------------------------------------------
			// when created in a scene node
			PhysicsComponent(PE::GameContext &context, PE::MemoryArena arena, PE::Handle myHandle
				, Array<PrimitiveTypes::Float32> minValues, Array<PrimitiveTypes::Float32> maxValues, const char * assetName, Vector3 spawnPos);

			virtual void addDefaultComponents();



			//	void PrePhysics(Vector3 start, Vector3 end);
			Vector3 m_min;
			Vector3 m_max;
			Vector3 bbpoints[8];
			float sphereRadius;
			Vector3 sphereCenter;
			float boundingVolume[6];
			const char * m_assetName;
		};
	}; // namespace Components
}; // namespace PE

#endif
