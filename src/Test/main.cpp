////////////////////////////////////////////////////////////
//
// GGE - Generic Game Engine
// Copyright (C) 2011-2012 Adri�n Guerra (adrigm@razonartificial.com)
//
////////////////////////////////////////////////////////////

#include <GGE/Core/App.hpp>

int main(int argc, char** argv)
{
	// Establecemos un c�digo de error
	GGE::Uint32 anExitCode = GGE::StatusNoError;

	// Creamos la aplicaci�n
	GGE::App *anApp = GGE::App::Instance();

	// Procesamos los argumentos
	//anApp->RegisterExecutableDir(argc, argv);

	// Ponemos en marcha la aplicaci�n
	anExitCode = anApp->Run();

	// Eliminamos la aplicaci�n
	GGE::App::Release();

	// Anulamos el puntero
	anApp = 0;

	// Retornamos el c�digo devuelto por la aplicaci�n
	return anExitCode;
}