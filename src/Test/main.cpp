#include <GGE/Core.hpp>
#include "SceneMain.hpp"

int main(int argc, char* argv[])
{
	// Establecemos el c�digo de salida por defecto
	GGE::Int16 anExitCode = GGE::StatusNoError;

	// Creamos la aplicaci�n
	GGE::App *anApp = GGE::App::Instance();

	// Procesamos los argumentos
	anApp->ProcessArguments(argc, argv);

	// Establecemos la escena inicial
	anApp->SetFirstScene(new SceneMain("Main"));

	//Ejecutamos la aplicaci�n
	anExitCode = anApp->Run();

	// Eliminamos la aplicaci�n
	GGE::App::Release();
	anApp = 0;

	// Devolvemos el c�digo de salida
	return anExitCode;
}