#pragma once

#define NDEBUG 1

class MyApp
{
public:
	void Run();

private:
	void InitWindow();
	void InitVulkan();
	void MainLoop();
	void CleanUp();

	void CreateInstance();

	bool CheckValidationLayerSupport();
	std::vector<const char*> GetRequiredExtensions();
	void SetupDebugMessenger();

	static VKAPI_ATTR VkBool32 VKAPI_CALL DebugCallBack(
		VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
		VkDebugUtilsMessageTypeFlagsEXT messageType,
		const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
		void* pUserData);

	VkResult CreateDebugUtilsMessengerEXT(VkInstance instance,
		const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
		const VkAllocationCallbacks* pAllocator,
		VkDebugUtilsMessengerEXT* pDebugMessenger);

	void DestroyDebugUtilsMessengerEXT(VkInstance instance,
		VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator);

	void PopulateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);

private:
	//glfw variables
	GLFWwindow* pWindow;
	uint32_t Width = 800;
	uint32_t Height = 600;

	//Vulkan variables
	VkInstance instance;
	VkDebugUtilsMessengerEXT debugMessenger;

	//validation layer variables
#ifndef NDEBUG
	const bool enableValidationLayers = false;
#else
	const bool enableValidationLayers = true;
#endif

	const std::vector<const char*> validationLayers = { "VK_LAYER_KHRONOS_validation" };

};

