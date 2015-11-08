#define NOMINMAX

#include "PhysicsManager.h"
#include "PhysicsComponent.h"

//#include "Light.h"
//#include "DrawList.h"

#include "PrimeEngine/APIAbstraction/Effect/EffectManager.h"
#include "../Lua/LuaEnvironment.h"
#include "PrimeEngine/Render/ShaderActions/SetPerFrameConstantsShaderAction.h"
#include "list"

#include "PrimeEngine/Scene/SceneNode.h"

namespace PE {
namespace Components {

PE_IMPLEMENT_CLASS1(PhysicsManager, Component);

Handle PhysicsManager::s_hTitleInstance;
Handle PhysicsManager::s_hInstance;
Handle PhysicsManager::s_hCurInstance;

void PhysicsManager::Construct(PE::GameContext &context, PE::MemoryArena arena)
{
	Handle h("Physics_Manager", sizeof(PhysicsManager));
	PhysicsManager *pPhysicsManager = new(h) PhysicsManager(context, arena, h);
	pPhysicsManager->addDefaultComponents();
	SetInstance(h);
	
	s_hTitleInstance = Handle("Physics_Manager", sizeof(PhysicsManager));
	PhysicsManager *pTitlePhysicsManager = new(s_hTitleInstance) PhysicsManager(context, arena, h);
	pTitlePhysicsManager->addDefaultComponents();
	
	SetTitleAsCurrent();
}

PhysicsManager::PhysicsManager(PE::GameContext &context, PE::MemoryArena arena, Handle hMyself)
			: Component(context, arena, hMyself)
		{
		}

/*void PhysicsManager::addDefaultComponents()
{
	Component::addDefaultComponents();
}
*/



void PhysicsManager::PrePhysics(Vector3 curPos, Vector3 targetPos, float speed)
{
			m_curPos = curPos;
			m_targetPos = targetPos;
			m_speed = speed;
}



Vector3 getClosestPointInAABB(Vector3 sphereCenter, Vector3 m_curPos, Vector3 m_min, Vector3 m_max)
		{
			Vector3 xClosestPoint, Point;
			Point = sphereCenter + m_curPos;
			xClosestPoint.m_x = (Point.m_x < m_min.m_x) ? m_min.m_x : (Point.m_x > m_max.m_x) ? m_max.m_x : Point.m_x;
			xClosestPoint.m_y = (Point.m_y < m_min.m_y) ? m_min.m_y : (Point.m_y > m_max.m_y) ? m_max.m_y : Point.m_y;
			xClosestPoint.m_z = (Point.m_z < m_min.m_z) ? m_min.m_z : (Point.m_z > m_max.m_z) ? m_max.m_z : Point.m_z;
			return xClosestPoint;
			
		}



void PhysicsManager::CheckForChange(Vector3 *min, Vector3 *max)
{
	if(min->m_x > max->m_x) 
	{
		float temp = min->m_x;
		min->m_x = max->m_x;
		max->m_x = temp;
	}
	if(min->m_y > max->m_y) 
	{
		float temp = min->m_y;
		min->m_y = max->m_y;
		max->m_y = temp;
	}

	if(min->m_z > max->m_z) 
	{
		float temp = min->m_z;
		min->m_z = max->m_z;
		max->m_z = temp;
	}
}



Vector3 PhysicsManager::UpdatePhysics()
{
bool planeCollided = false;
			//Array<Handle, 1> m_components;
			PE::Handle *pHC = Instance()->m_components.getFirstPtr();

			for (PrimitiveTypes::UInt32 i = 0; i < Instance()->m_components.m_size; i++, pHC++) // fast array traversal (increasing ptr)
			{
				Component *pC = (*pHC).getObject<Component>();

				if (pC->isInstanceOf<PhysicsComponent>())
				{
					PhysicsComponent *pPC = (PhysicsComponent *)pC;
					
						if (StringOps::strcmp(pPC->m_assetName, "SoldierTransform.mesha") == 0)
					{
						PE::Handle *pHCS = Instance()->m_components.getFirstPtr();

						for (PrimitiveTypes::UInt32 s = 0; s < Instance()->m_components.m_size; s++, pHCS++) // fast array traversal (increasing ptr)
						{
							if (s != i)
							{
								Component *pCS = (*pHCS).getObject<Component>();
								Vector3 Normal, distanceVec; float r2 , dmin ;
								Vector3 closestPoint;
								if (pCS->isInstanceOf<PhysicsComponent>())
								{
									PhysicsComponent *pPCS = (PhysicsComponent *)pCS;
									// if (StringOps::strcmp(pPCS->m_assetName, "nazicar.x_carmesh_mesh.mesha") == 0)
									
									  if (StringOps::strcmp(pPCS->m_assetName, "cobbleplane.x_pplaneshape1_mesh.mesha") == 0)
									 {
												CheckForChange(&pPCS->m_min, &pPCS->m_max);
										  closestPoint = getClosestPointInAABB(pPC->sphereCenter, m_curPos, pPCS->m_min, pPCS->m_max);

										 Normal = ((pPC->sphereCenter + m_curPos) - closestPoint);
										 r2 = pPC->sphereRadius* pPC->sphereRadius;
										 distanceVec = (closestPoint - (pPC->sphereCenter + m_curPos));
										 dmin = distanceVec.lengthSqr();
										 Normal.normalize();
										 if (dmin <= r2)
										 {//nocollision
											 //fall soldier;
											 planeCollided = true;
										 }
									 }
									  else if(StringOps::strcmp(pPCS->m_assetName, "nazicar.x_carmesh_mesh.mesha") == 0)
									  {
										  CheckForChange(&pPCS->m_min, &pPCS->m_max);
										  closestPoint = getClosestPointInAABB(pPC->sphereCenter, m_curPos, pPCS->m_min, pPCS->m_max);

										  Normal = ((pPC->sphereCenter + m_curPos) - closestPoint);
										  r2 = pPC->sphereRadius* pPC->sphereRadius;
										  distanceVec = (closestPoint - (pPC->sphereCenter + m_curPos));
										  dmin = distanceVec.lengthSqr();
										  Normal.normalize();
										  if (dmin <= r2)
										  {//collision
											  return m_curPos + (Normal * m_speed);
										  }
									  }
									 
								}
							}
						}
						if (!planeCollided)
						{
							m_curPos.m_y += -10.f;
							return m_curPos;
							//return 
						}
						else
						{
							return m_curPos;
						}
					//else{
						return m_curPos;
					//}
					}
					//else{ return m_curPos; }
				}
			}
		};
	};
};