#pragma once

namespace Brain {

	typedef enum class MouseCode : uint16_t
	{
		Button0			= 0,
		Button1			= 1,
		Button2			= 2,
		Button3			= 3,
		Button4			= 4,
		Button5			= 5,
		Button6			= 6,
		Button7			= 7,
		ButtonLast		= Button7,
		ButtonLeft		= Button0,
		ButtonRight		= Button1,
		ButtonMiddle	= Button2
	} Mouse;

	inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
	{
		os << static_cast<int32_t>(mouseCode);
		return os;
	}
}

// from glfw3.h
#define SB_MOUSE_BUTTON_0         ::Brain::Mouse::Button0		
#define SB_MOUSE_BUTTON_1         ::Brain::Mouse::Button1		
#define SB_MOUSE_BUTTON_2         ::Brain::Mouse::Button2		
#define SB_MOUSE_BUTTON_3         ::Brain::Mouse::Button3		
#define SB_MOUSE_BUTTON_4         ::Brain::Mouse::Button4		
#define SB_MOUSE_BUTTON_5         ::Brain::Mouse::Button5		
#define SB_MOUSE_BUTTON_6         ::Brain::Mouse::Button6		
#define SB_MOUSE_BUTTON_7         ::Brain::Mouse::Button7		
#define SB_MOUSE_BUTTON_LAST      ::Brain::Mouse::ButtonLast	
#define SB_MOUSE_BUTTON_LEFT      ::Brain::Mouse::ButtonLeft	
#define SB_MOUSE_BUTTON_RIGHT     ::Brain::Mouse::ButtonRight	
#define SB_MOUSE_BUTTON_MIDDLE    ::Brain::Mouse::ButtonMiddle