#include "sbpch.h"
#include "Entity.h"

namespace Brain {

	Entity::Entity(entt::entity handle, Scene* scene)
		: m_EntityHandle(handle), m_Scene(scene)
	{

	}

}