
#include "../GameObjectModel/GameObjectManager.h"
#include "PhysicsComponent.h"
#include "PhysicsManager.h"
#include "PrimeEngine/Scene/Mesh.h"

#include "../Lua/LuaEnvironment.h"
namespace PE {
	namespace Components{

		PE_IMPLEMENT_CLASS1(PhysicsComponent, Component);
		PhysicsComponent::PhysicsComponent(PE::GameContext &context, PE::MemoryArena arena,
			PE::Handle myHandle, Array<PrimitiveTypes::Float32> minValues, Array<PrimitiveTypes::Float32> maxValues, const char * assetName, Vector3 spawnPos)
			: Component(context, arena, myHandle)
		{

			//SceneNode *pSN = hSN.getObject<SceneNode>();
			//spawnPos = pSN->m_base.getPos();

			m_assetName = assetName;
			Vector3 p1, p2, p3, p4, p5, p6, p7, p8;
			Vector3 maxVal, min;

			maxVal.m_x = maxValues[0];
			maxVal.m_y = maxValues[1];
			maxVal.m_z = maxValues[2];

			min.m_x = minValues[0];
			min.m_y = minValues[1];
			min.m_z = minValues[2];

			maxVal = maxVal + spawnPos;
			min = min + spawnPos;
			m_min = min;
			m_max = maxVal;

			if (!StringOps::endswith(assetName, "SoldierTransform.mesha"))
			{
				Vector3 p1, p2, p3, p4, p5, p6, p7, p8;
				Vector3 maxVal;

				maxVal = m_max;
				p1.m_x = min.m_x; p1.m_y = min.m_y; p1.m_z = min.m_z;
				p8.m_x = maxVal.m_x; p8.m_y = maxVal.m_y; p8.m_z = maxVal.m_z;
				p2.m_x = maxVal.m_x; p2.m_y = min.m_y; p2.m_z = min.m_z;
				p3.m_x = maxVal.m_x; p3.m_y = min.m_y; p3.m_z = maxVal.m_z;
				p4.m_x = min.m_x; p4.m_y = min.m_y; p4.m_z = maxVal.m_z;
				p5.m_x = min.m_x; p5.m_y = maxVal.m_y; p5.m_z = min.m_z;
				p6.m_x = maxVal.m_x; p6.m_y = maxVal.m_y; p6.m_z = min.m_z;
				p7.m_x = min.m_x; p7.m_y = maxVal.m_y; p7.m_z = maxVal.m_z;

				bbpoints[0] = p1;
				bbpoints[1] = p2;
				bbpoints[2] = p3;
				bbpoints[3] = p4;
				bbpoints[4] = p5;
				bbpoints[5] = p6;
				bbpoints[6] = p7;
				bbpoints[7] = p8;
			}
			else
			{
				//dynamic object sphere


				sphereCenter = (m_max + m_min) * 0.5;
				sphereRadius = ((sphereCenter - m_min).length()) * 1.f;
			}
			//perform collisions
		}


		void PhysicsComponent::addDefaultComponents()
		{
			Component::addDefaultComponents();
			// Data components

			// event handlers

		}
		/*void PhysicsComponent::PrePhysics(Vector3 start, Vector3 end)
		{
		Vector3 startPos = start;
		Vector3 endPos = end;

		}*/
	}; // namespace Components
}; // namespace PE
