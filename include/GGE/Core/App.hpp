////////////////////////////////////////////////////////////
//
// GGE - Generic Game Engine
// Copyright (C) 2011-2012 Adri�n Guerra (adrigm@razonartificial.com)
//
////////////////////////////////////////////////////////////

#ifndef GGE_APP_HPP
#define GGE_APP_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <string>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <GGE/Config.hpp>
#include <GGE/Core/Export.hpp>
#include <GGE/Core/Core_types.hpp>

namespace GGE
{

class GGE_CORE_API App
{
	static App* ms_instance;

public:
	// Constantes
	///////////////////////////////////////////////////////////////////////////
	static const unsigned int DEFAULT_VIDEO_WIDTH = 640;
	static const unsigned int DEFAULT_VIDEO_HEIGHT = 480;
	static const unsigned int DEFAULT_VIDEO_BPP = 32;

	// Variables
	///////////////////////////////////////////////////////////////////////////
	/// Ventana de la aplicaci�n
	sf::RenderWindow window;
	/// Modo de video (Width, Height, Bpp)
	sf::VideoMode videoMode;
	/// Opciones de la ventana
	sf::ContextSettings contextSettings;
	/// Estilo de la ventana
	unsigned long windowStyle;
	/// Log de la aplicaci�n
	std::ofstream log;

	/**
	 * Devuelve un puntero a la instancia �nica de la clase si existe,
	 * si no, la crea y duevuelve el puntero.
	 * 
	 * @return Puntero a la instancia �nica de App
	 */
	static App* Instance();

	static void Release();

	/**
	 * Procesa los par�metros pasados por l�nea de comandos
	 *
	 * @param argc N�mero de par�metros
	 * @param argv[] Lista de par�metros
	 */
	void ProcessArguments(int argc, char** argv);

	/**
	 * Establece la ruta del ejecutable de la aplicaci�n
	 * 
	 * @param argc N�mero de par�metros
	 * @param argv[] Lista de par�metros
	 */
	void RegisterExecutableDir(int argc, char** argv);

	/**
	 * Devuelve la ruta del ejecutable de la aplicaci�n
	 *
	 * @return string con la ruta de la aplicaci�n
	 */
	std::string GetExecutableDir() const;

	/**
	 * Pone en funcionamiento la aplicaci�n. Se encarga de llamar a los m�todos
	 * Preinit, Init, loop y CleanUp
	 *
	 * @return C�digo de salida de la aplicaci�n
	 */
	int Run(void);

	/**
	 * Devuelve verdadero si la aplicaci�n se est� ejecutando
	 *
	 * @return true si la apicaci�n se est� ejecutando
	 */
	bool IsRunning(void) const;

	/**
	 * Obtiene el tiempo pasado en cada ciclo del programa.
	 *
	 * @return	The update time.
	 */
	GGE::Int64 GetUpdateTime(void) const;

	/**
	 * Detiene la aplicacion con el c�digo de salida indicado
	 *
	 * @param the_exit_code C�digo de salida de la aplicaci�n
	 */
	void Quit(int the_exit_code);

	std::string GetTitle() const;
	void SetTitle(const std::string theTitle);

protected:
	/**
	 * M�todo llamado antes del Init() se encarga de establecer configuraciones
	 * de la aplicaci�n
	 */
	void PreInit(void);

	/**
	 * Se encarga de inicializar la aplicaci�n
	 */
	virtual void Init(void);

	/**
	 * Lleva el bucle de la aplicaci�n se encarga de mantenerla en ejecuci�n
	 */
	virtual void Loop(void);

	/**
	 * Se encarga de la limpieza andes de salir de la aplicacion
	 */
	virtual void Cleanup(void);

private:
	/// T�tulo de la ventana
	std::string m_title;
	/// C�digo de salida de la aplicaci�n
	GGE::Int16 m_exitCode;
	/// Verdadero si la aplicaci�n se est� ejecutando
	bool m_running;
	/// Ruta del ejecutable
	std::string m_executableDir;
	/// Reloj que obtiene el tiempo pasado en cada loop
	sf::Clock m_updateClock;
	/// Almacena el tiempo pasado en cada bucle
	sf::Time m_updateTime;

	App();
	virtual ~App();

	/**
	 * App copy constructor is private because we do not allow copies of
	 * our Singleton class
	*/
	App(const App&);               // Intentionally undefined

	/**
	 * Our assignment operator is private because we do not allow copies
	 * of our Singleton class
	 */
	App& operator=(const App&);    // Intentionally undefined
}; // class App

} // namespace GGE

#endif // GGE_APP_HPP