// Editor.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <memory>

#include <UltraEngine.h>

class EditorApplication : public Ultra::Application {
public:
	EditorApplication() { }
	~EditorApplication() { }

	void run() override {
		std::cout << "Hello from the editor" << std::endl;
		std::cin.get();
	}
};

int main(void){

	Ultra::Application* app = new EditorApplication();
	
	app->run();

	return 0;
}