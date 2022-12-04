#pragma once

namespace Brain {

	typedef enum class KeyCode : uint16_t
	{
		// from glfw3.h
		Space					= 32,
		Apostrophe				= 39,  /* ' */
		Comma					= 44,  /* , */
		Minus					= 45,  /* - */
		Period					= 46,  /* . */
		Slash					= 47,  /* / */

		D0						= 48, /* 0 */
		D1						= 49, /* 1 */
		D2						= 50, /* 2 */
		D3						= 51, /* 3 */
		D4						= 52, /* 4 */
		D5						= 53, /* 5 */
		D6						= 54, /* 6 */
		D7						= 55, /* 7 */
		D8						= 56, /* 8 */
		D9						= 57, /* 9 */

		Semicolon				= 59,  /* ; */
		Equal					= 61,  /* = */

		A						= 65,
		B						= 66,
		C						= 67,
		D						= 68,
		E						= 69,
		F						= 70,
		G						= 71,
		H						= 72,
		I						= 73,
		J						= 74,
		K						= 75,
		L						= 76,
		M						= 77,
		N						= 78,
		O						= 79,
		P						= 80,
		Q						= 81,
		R						= 82,
		S						= 83,
		T						= 84,
		U						= 85,
		V						= 86,
		W						= 87,
		X						= 88,
		Y						= 89,
		Z						= 90,

		LeftBracket				= 91,  /* [ */
		Backslash				= 92,  /* \ */
		RightBracket			= 93,  /* ] */
		GraveAccent				= 96,  /* ` */

		World1					= 161, /* non-US #1 */
		World2					= 162, /* non-US #2 */

		/* Function keys */
		Escape					= 256,
		Enter					= 257,
		Tab						= 258,
		Backspace				= 259,
		Insert					= 260,
		Delete					= 261,
		Right					= 262,
		Left					= 263,
		Down					= 264,
		Up						= 265,
		PageUp					= 266,
		PageDown				= 267,
		Home					= 268,
		End						= 269,
		CapsLock				= 280,
		ScrollLock				= 281,
		NumLock					= 282,
		PrintScreen				= 283,
		Pause					= 284,
		F1						= 290,
		F2						= 291,
		F3						= 292,
		F4						= 293,
		F5						= 294,
		F6						= 295,
		F7						= 296,
		F8						= 297,
		F9						= 298,
		F10						= 299,
		F11						= 300,
		F12						= 301,
		F13						= 302,
		F14						= 303,
		F15						= 304,
		F16						= 305,
		F17						= 306,
		F18						= 307,
		F19						= 308,
		F20						= 309,
		F21						= 310,
		F22						= 311,
		F23						= 312,
		F24						= 313,
		F25						= 314,

		/* Keypad */
		KP0						= 320,
		KP1						= 321,
		KP2						= 322,
		KP3						= 323,
		KP4						= 324,
		KP5						= 325,
		KP6						= 326,
		KP7						= 327,
		KP8						= 328,
		KP9						= 329,
		KPDecimal				= 330,
		KPDivide				= 331,
		KPMultiply				= 332,
		KPSubtract				= 333,
		KPAdd					= 334,
		KPEnter					= 335,
		KPEqual					= 336,

		LeftShift				= 340,
		LeftControl				= 341,
		LeftAlt					= 342,
		LeftSuper				= 343,
		RightShift				= 344,
		RightControl			= 345,
		RightAlt				= 346,
		RightSuper				= 347,
		Menu					= 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

// from glfw3.h
#define SB_KEY_SPACE              ::Brain::Key::Space		
#define SB_KEY_APOSTROPHE         ::Brain::Key::Apostrophe	/* ' */
#define SB_KEY_COMMA              ::Brain::Key::Comma			/* , */
#define SB_KEY_MINUS              ::Brain::Key::Minus			/* - */
#define SB_KEY_PERIOD             ::Brain::Key::Period		/* . */
#define SB_KEY_SLASH              ::Brain::Key::Slash			/* / */
#define SB_KEY_0                  ::Brain::Key::D0			
#define SB_KEY_1                  ::Brain::Key::D1			
#define SB_KEY_2                  ::Brain::Key::D2			
#define SB_KEY_3                  ::Brain::Key::D3			
#define SB_KEY_4                  ::Brain::Key::D4			
#define SB_KEY_5                  ::Brain::Key::D5			
#define SB_KEY_6                  ::Brain::Key::D6			
#define SB_KEY_7                  ::Brain::Key::D7			
#define SB_KEY_8                  ::Brain::Key::D8			
#define SB_KEY_9                  ::Brain::Key::D9			
#define SB_KEY_SEMICOLON          ::Brain::Key::Semicolon	  /* ; */
#define SB_KEY_EQUAL              ::Brain::Key::Equal		  /* = */
#define SB_KEY_A                  ::Brain::Key::A
#define SB_KEY_B                  ::Brain::Key::B
#define SB_KEY_C                  ::Brain::Key::C
#define SB_KEY_D                  ::Brain::Key::D
#define SB_KEY_E                  ::Brain::Key::E
#define SB_KEY_F                  ::Brain::Key::F
#define SB_KEY_G                  ::Brain::Key::G
#define SB_KEY_H                  ::Brain::Key::H
#define SB_KEY_I                  ::Brain::Key::I
#define SB_KEY_J                  ::Brain::Key::J
#define SB_KEY_K                  ::Brain::Key::K
#define SB_KEY_L                  ::Brain::Key::L
#define SB_KEY_M                  ::Brain::Key::M
#define SB_KEY_N                  ::Brain::Key::N
#define SB_KEY_O                  ::Brain::Key::O
#define SB_KEY_P                  ::Brain::Key::P
#define SB_KEY_Q                  ::Brain::Key::Q
#define SB_KEY_R                  ::Brain::Key::R
#define SB_KEY_S                  ::Brain::Key::S
#define SB_KEY_T                  ::Brain::Key::T
#define SB_KEY_U                  ::Brain::Key::U
#define SB_KEY_V                  ::Brain::Key::V
#define SB_KEY_W                  ::Brain::Key::W
#define SB_KEY_X                  ::Brain::Key::X
#define SB_KEY_Y                  ::Brain::Key::Y
#define SB_KEY_Z                  ::Brain::Key::Z
#define SB_KEY_LEFT_BRACKET       ::Brain::Key::LeftBracket	/* [ */
#define SB_KEY_BACKSLASH          ::Brain::Key::Backslash		/* \ */
#define SB_KEY_RIGHT_BRACKET      ::Brain::Key::RightBracket	/* ] */
#define SB_KEY_GRAVE_ACCENT       ::Brain::Key::GraveAccent	/* ` */
#define SB_KEY_WORLD_1            ::Brain::Key::World1		/* non-US #1 */
#define SB_KEY_WORLD_2            ::Brain::Key::World2		/* non-US #2 */
					
/* Function keys */	
#define SB_KEY_ESCAPE             ::Brain::Key::Escape		
#define SB_KEY_ENTER              ::Brain::Key::Enter		
#define SB_KEY_TAB                ::Brain::Key::Tab			
#define SB_KEY_BACKSPACE          ::Brain::Key::Backspace	
#define SB_KEY_INSERT             ::Brain::Key::Insert		
#define SB_KEY_DELETE             ::Brain::Key::Delete		
#define SB_KEY_RIGHT              ::Brain::Key::Right		
#define SB_KEY_LEFT               ::Brain::Key::Left		
#define SB_KEY_DOWN               ::Brain::Key::Down		
#define SB_KEY_UP                 ::Brain::Key::Up			
#define SB_KEY_PAGE_UP            ::Brain::Key::PageUp		
#define SB_KEY_PAGE_DOWN          ::Brain::Key::PageDown	
#define SB_KEY_HOME               ::Brain::Key::Home		
#define SB_KEY_END                ::Brain::Key::End			
#define SB_KEY_CAPS_LOCK          ::Brain::Key::CapsLock	
#define SB_KEY_SCROLL_LOCK        ::Brain::Key::ScrollLock	
#define SB_KEY_NUM_LOCK           ::Brain::Key::NumLock		
#define SB_KEY_PRINT_SCREEN       ::Brain::Key::PrintScreen	
#define SB_KEY_PAUSE              ::Brain::Key::Pause		
#define SB_KEY_F1                 ::Brain::Key::F1			
#define SB_KEY_F2                 ::Brain::Key::F2			
#define SB_KEY_F3                 ::Brain::Key::F3			
#define SB_KEY_F4                 ::Brain::Key::F4			
#define SB_KEY_F5                 ::Brain::Key::F5			
#define SB_KEY_F6                 ::Brain::Key::F6			
#define SB_KEY_F7                 ::Brain::Key::F7			
#define SB_KEY_F8                 ::Brain::Key::F8			
#define SB_KEY_F9                 ::Brain::Key::F9			
#define SB_KEY_F10                ::Brain::Key::F10			
#define SB_KEY_F11                ::Brain::Key::F11			
#define SB_KEY_F12                ::Brain::Key::F12			
#define SB_KEY_F13                ::Brain::Key::F13			
#define SB_KEY_F14                ::Brain::Key::F14			
#define SB_KEY_F15                ::Brain::Key::F15			
#define SB_KEY_F16                ::Brain::Key::F16			
#define SB_KEY_F17                ::Brain::Key::F17			
#define SB_KEY_F18                ::Brain::Key::F18			
#define SB_KEY_F19                ::Brain::Key::F19			
#define SB_KEY_F20                ::Brain::Key::F20			
#define SB_KEY_F21                ::Brain::Key::F21			
#define SB_KEY_F22                ::Brain::Key::F22			
#define SB_KEY_F23                ::Brain::Key::F23			
#define SB_KEY_F24                ::Brain::Key::F24			
#define SB_KEY_F25                ::Brain::Key::F25	

/* Keypad */
#define SB_KEY_KP_0               ::Brain::Key::KP0			
#define SB_KEY_KP_1               ::Brain::Key::KP1			
#define SB_KEY_KP_2               ::Brain::Key::KP2			
#define SB_KEY_KP_3               ::Brain::Key::KP3			
#define SB_KEY_KP_4               ::Brain::Key::KP4			
#define SB_KEY_KP_5               ::Brain::Key::KP5			
#define SB_KEY_KP_6               ::Brain::Key::KP6			
#define SB_KEY_KP_7               ::Brain::Key::KP7			
#define SB_KEY_KP_8               ::Brain::Key::KP8			
#define SB_KEY_KP_9               ::Brain::Key::KP9			
#define SB_KEY_KP_DECIMAL         ::Brain::Key::KPDecimal	
#define SB_KEY_KP_DIVIDE          ::Brain::Key::KPDivide	
#define SB_KEY_KP_MULTIPLY        ::Brain::Key::KPMultiply	
#define SB_KEY_KP_SUBTRACT        ::Brain::Key::KPSubtract	
#define SB_KEY_KP_ADD             ::Brain::Key::KPAdd		
#define SB_KEY_KP_ENTER           ::Brain::Key::KPEnter		
#define SB_KEY_KP_EQUAL           ::Brain::Key::KPEqual		
#define SB_KEY_LEFT_SHIFT         ::Brain::Key::LeftShift	
#define SB_KEY_LEFT_CONTROL       ::Brain::Key::LeftControl	
#define SB_KEY_LEFT_ALT           ::Brain::Key::LeftAlt		
#define SB_KEY_LEFT_SUPER         ::Brain::Key::LeftSuper	
#define SB_KEY_RIGHT_SHIFT        ::Brain::Key::RightShift	
#define SB_KEY_RIGHT_CONTROL      ::Brain::Key::RightControl
#define SB_KEY_RIGHT_ALT          ::Brain::Key::RightAlt	
#define SB_KEY_RIGHT_SUPER        ::Brain::Key::RightSuper	
#define SB_KEY_MENU               ::Brain::Key::Menu		