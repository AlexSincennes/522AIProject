// API Abstraction
#include "PrimeEngine/APIAbstraction/APIAbstractionDefines.h"

#include "MeshManager.h"
// Outer-Engine includes

// Inter-Engine includes
#include "PrimeEngine/FileSystem/FileReader.h"
#include "PrimeEngine/APIAbstraction/GPUMaterial/GPUMaterialSet.h"
#include "PrimeEngine/PrimitiveTypes/PrimitiveTypes.h"
#include "PrimeEngine/APIAbstraction/Texture/Texture.h"
#include "PrimeEngine/APIAbstraction/Effect/EffectManager.h"
#include "PrimeEngine/APIAbstraction/GPUBuffers/VertexBufferGPUManager.h"
#include "PrimeEngine/../../GlobalConfig/GlobalConfig.h"

#include "PrimeEngine/Geometry/SkeletonCPU/SkeletonCPU.h"

#include "PrimeEngine/Scene/RootSceneNode.h"

#include "Light.h"

// Sibling/Children includes

#include "MeshInstance.h"
#include "Skeleton.h"
#include "SceneNode.h"
#include "DrawList.h"
#include "SH_DRAW.h"
#include "PrimeEngine/Lua/LuaEnvironment.h"

namespace PE {
namespace Components{

PE_IMPLEMENT_CLASS1(MeshManager, Component);
MeshManager::MeshManager(PE::GameContext &context, PE::MemoryArena arena, Handle hMyself)
	: Component(context, arena, hMyself)
	, m_assets(context, arena, 256)
{
}

PE::Handle MeshManager::getAsset(const char *asset, const char *package, int &threadOwnershipMask)
{
	char key[StrTPair<Handle>::StrSize];
	sprintf(key, "%s/%s", package, asset);
	
	int index = m_assets.findIndex(key);
	if (index != -1)
	{
		return m_assets.m_pairs[index].m_value;
	}
	Handle h;

	if (StringOps::endswith(asset, "skela"))
	{
		PE::Handle hSkeleton("Skeleton", sizeof(Skeleton));
		Skeleton *pSkeleton = new(hSkeleton) Skeleton(*m_pContext, m_arena, hSkeleton);
		pSkeleton->addDefaultComponents();

		pSkeleton->initFromFiles(asset, package, threadOwnershipMask);
		h = hSkeleton;
	}
	else if (StringOps::endswith(asset, "mesha"))
	{
		MeshCPU mcpu(*m_pContext, m_arena);
		mcpu.ReadMesh(asset, package, "");
		
		PE::Handle hMesh("Mesh", sizeof(Mesh));
		Mesh *pMesh = new(hMesh) Mesh(*m_pContext, m_arena, hMesh);
		pMesh->addDefaultComponents();

		pMesh->loadFromMeshCPU_needsRC(mcpu, threadOwnershipMask);

#if PE_API_IS_D3D11
		// todo: work out how lods will work
		//scpu.buildLod();
#endif
        // generate collision volume here. or you could generate it in MeshCPU::ReadMesh()
        pMesh->m_performBoundingVolumeCulling = true; // will now perform tests for this mesh

		pMesh->maxValues = pMesh->m_hPositionBufferCPU.getObject<PositionBufferCPU>()->m_maxValues;
		pMesh->minValues = pMesh->m_hPositionBufferCPU.getObject<PositionBufferCPU>()->m_minValues;
		Vector3 p1, p2, p3, p4, p5, p6, p7, p8;
		Vector3 maxVal, min;

		maxVal.m_x = pMesh->maxValues[0];
		maxVal.m_y = pMesh->maxValues[1];
		maxVal.m_z = pMesh->maxValues[2];

		min.m_x = pMesh->minValues[0];
		min.m_y = pMesh->minValues[1];
		min.m_z = pMesh->minValues[2];

		p1.m_x = min.m_x; p1.m_y = min.m_y; p1.m_z = min.m_z;
		p8.m_x = maxVal.m_x; p8.m_y = maxVal.m_y; p8.m_z = maxVal.m_z;
		p2.m_x = maxVal.m_x; p2.m_y = min.m_y; p2.m_z = min.m_z;
		p3.m_x = maxVal.m_x; p3.m_y = min.m_y; p3.m_z = maxVal.m_z;
		p4.m_x = min.m_x; p4.m_y = min.m_y; p4.m_z = maxVal.m_z;
		p5.m_x = min.m_x; p5.m_y = maxVal.m_y; p5.m_z = min.m_z;
		p6.m_x = maxVal.m_x; p6.m_y = maxVal.m_y; p6.m_z = min.m_z;
		p7.m_x = min.m_x; p7.m_y = maxVal.m_y; p7.m_z = maxVal.m_z;

		pMesh->bbpoints[0] = p1;
		pMesh->bbpoints[1] = p2;
		pMesh->bbpoints[2] = p3;
		pMesh->bbpoints[3] = p4;
		pMesh->bbpoints[4] = p5;
		pMesh->bbpoints[5] = p6;
		pMesh->bbpoints[6] = p7;
		pMesh->bbpoints[7] = p8;



		h = hMesh;
	}


	PEASSERT(h.isValid(), "Something must need to be loaded here");

	RootSceneNode::Instance()->addComponent(h);
	m_assets.add(key, h);
	return h;
}

void MeshManager::registerAsset(const PE::Handle &h)
{
	static int uniqueId = 0;
	++uniqueId;
	char key[StrTPair<Handle>::StrSize];
	sprintf(key, "__generated_%d", uniqueId);
	
	int index = m_assets.findIndex(key);
	PEASSERT(index == -1, "Generated meshes have to be unique");
	
	RootSceneNode::Instance()->addComponent(h);
	m_assets.add(key, h);
}

}; // namespace Components
}; // namespace PE
