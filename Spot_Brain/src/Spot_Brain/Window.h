#pragma once

#include "sbpch.h"

#include "Spot_Brain/Core.h"
#include "Spot_Brain/Events/Event.h"

namespace Brainspace {
	
	// Window properties
	struct WindowProps 
	{
		//Declare some variables
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		// Constructor for the class
		WindowProps(const std::string& title = "Spot Brain Core",
							unsigned int width = 1280,
							unsigned int height = 720)
						: Title(title), Width(width), Height(height)
		{
		}
	};

	class BRAIN_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};

}