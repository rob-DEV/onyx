#ifndef _ONYX_PLATFORM_VULKAN_GRAPHICS_CONTEXT_H_
#define _ONYX_PLATFORM_VULKAN_GRAPHICS_CONTEXT_H_

#include <Onyx/graphics/GraphicsContext.h>
#include "VulkanInstance.h"

struct GLFWwindow;

namespace Onyx {

	class VulkanGraphicsContext : public GraphicsContext {

	public:
		
		VulkanGraphicsContext(GLFWwindow* window);
		void init();
		void swapBuffers();

	private:
		VulkanInstance* m_VulkanInstance;
		GLFWwindow* m_WindowHandle;

	};


}


#endif // _ONYX_GRAPHICS_CONTEXT_H_
