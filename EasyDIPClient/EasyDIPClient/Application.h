#include "EDClientpch.h"



#include "EasyDIPAPI/Loaders.h"



#ifndef __ED_CLIENT_APPLICATION__
#define __ED_CLIENT_APPLICATION__

class Application
{
	float test = 0;
	//template <typename TT> using ptr = std::shared_ptr<TT>;
	//ImGui::FileBrowser fileDialog;
	GLFWwindow *window;
	std::array< int, 2 > _wndPos{ 0, 0 };
	std::array< int, 2 > _wndSize{ 0, 0 };
	std::array< int, 2 > _vpSize{ 0, 0 };
	bool _updateViewport = true;
	GLFWmonitor* _monitor = nullptr;

	void Resize(int cx, int cy);

	unsigned int texId = 0;
	unsigned int texOGImg = 0;

	int windowWidth;
	int windowHeight;
	int widthConv = 1;
	int heightConv = 1;
	float color[7][7][4];
	int pivotX = 0, pivotY = 0;
	bool show_demo_window = true;
public:
	Application();
	~Application();

	static void CallbackResize(GLFWwindow* window, int cx, int cy);
	bool IsFullscreen(void);
	void SetFullScreen(bool fullscreen);
	
	void processInput();
	void MainLoop();
	void Render();
	void ImGui();
	void Init();

	float NCP = 0.03f;

	void SetCharacter();
	void SetMap();
	void Enable_Zbuffer();
	void SetCamaraPos();
	void SetEnd();
	void SetLight();
	void Win();
	void Get_Points();
	//bool Check_Collision(Mesh* one, Mesh* two);
	
	static void HelpMarker(const char* desc);

};

static void glfw_error_callback(int error, const char* description)
{
	fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}
#endif // !1

