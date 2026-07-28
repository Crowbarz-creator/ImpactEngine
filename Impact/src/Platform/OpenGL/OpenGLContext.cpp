#include "imppch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/GL.h>

namespace Impact {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		IMP_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		IMP_CORE_ASSERT(status, "Failed to initialize Glad!");

		IMP_CORE_INFO("OpenGL Info:");
		IMP_CORE_INFO("  Vendor: {0}", (const char*)glGetString(GL_VENDOR));
		IMP_CORE_INFO("  Renderer: {0}", (const char*)glGetString(GL_RENDERER));
		IMP_CORE_INFO("  Version: {0}", (const char*)glGetString(GL_VERSION));

	#ifdef IMP_ENABLE_ASSERTS
		int versionMajor;
		int versionMinor;
		glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
		glGetIntegerv(GL_MINOR_VERSION, &versionMinor);

		IMP_CORE_ASSERT(versionMajor > 4 || (versionMajor == 4 && versionMinor >= 5), "Impact Engine requires at least OpenGL version 4.5!");
	#endif
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

}