#ifndef __PYENGINE_2_0_PHYSICSMANAGER_H__
#define __PYENGINE_2_0_PHYSICSMANAGER_H__

// API Abstraction
#include "PrimeEngine/APIAbstraction/APIAbstractionDefines.h"

// Outer-Engine includes
#include <assert.h>

// Inter-Engine includes
#include "PrimeEngine/MemoryManagement/Handle.h"
#include "PrimeEngine/PrimitiveTypes/PrimitiveTypes.h"
#include "../Events/Component.h"
#include "../Utils/Array/Array.h"
#include "PrimeEngine/APIAbstraction/Effect/Effect.h"
#include "../Math/Vector3.h"


// Sibling/Children includes
//#include "SceneNode.h"

namespace PE{
namespace Components {

struct PhysicsManager : Component
		{
			PE_DECLARE_CLASS(PhysicsManager);

			static void Construct(PE::GameContext &context, PE::MemoryArena arena);

			// Constructor -------------------------------------------------------------
			// same
			PhysicsManager(PE::GameContext &context, PE::MemoryArena arena, Handle hMyself);
		//	{
			//	m_components.reset(512);
		//	}
			
				//
			void PrePhysics(Vector3 curPos, Vector3 targetPos, float speed);
			Vector3 UpdatePhysics();
			void CheckForChange(Vector3 *min, Vector3 *max);
			Vector3 m_curPos,m_targetPos;
			float m_speed;
		
			//void registerAsset(const Handle &h);
			static PhysicsManager *Instance() { return s_hInstance.getObject<PhysicsManager>(); }
			static PhysicsManager *TitleInstance() { return s_hTitleInstance.getObject<PhysicsManager>(); }
			static Handle InstanceHandle() { return s_hInstance; }
			static Handle TitleInstanceHandle() { return s_hTitleInstance; }
			static PhysicsManager *CurInstance() { return s_hCurInstance.getObject<PhysicsManager>(); }
			static Handle CurInstanceHandle() { return s_hCurInstance; }
			static void SetTitleAsCurrent(){ s_hCurInstance = s_hTitleInstance; }
			static void SetGameAsCurrent() { s_hCurInstance = s_hInstance; }
			static bool TitleIsCurrent() { return s_hCurInstance == s_hTitleInstance; }

			static void SetInstance(Handle h){ s_hInstance = h; }
		private:
			static Handle s_hInstance;
			static Handle s_hTitleInstance;
			static Handle s_hCurInstance;
		};

	}; // namespace Components
}; // namespace PE
#endif
