#pragma once

#include "Entity.h"

namespace Brain {

	class ScriptableEntity
	{
	public:
		virtual ~ScriptableEntity(){}

		template<typename T>
		T& GetComponent()
		{
			return m_Entity.GetComponent<T>();
		}
	protected:
		virtual void OnCreate() {}
		virtual void OnDestroy() {}
		virtual void OnUpdate() {}
	private:
		Entity m_Entity;
		friend class Scene;


	};

}