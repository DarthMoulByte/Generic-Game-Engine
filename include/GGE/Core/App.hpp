#ifndef APP_HPP
#define APP_HPP

#include <string>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <GGE/Config.hpp>
#include <GGE/Core/Core_types.hpp>

namespace GGE
{
class App
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
	/// T�tulo de la ventana
	std::string mTitle;
	/// Ventana de la aplicaci�n
	sf::RenderWindow mWindow;
	/// Modo de video (Width, Height, Bpp)
	sf::VideoMode mVideoMode;
	/// Opciones de la ventana
	sf::ContextSettings mContextSettings;
	/// Estilo de la ventana
	unsigned long mWindowStyle;
	/// Log de la aplicaci�n
	std::ofstream mLog;
	/// Puntero al SceneManager
	GGE::SceneManager* mSceneManager;
	/// Puntero al AssetManager
	GGE::AssetManager* mAssetManager;
	/// C�mara por defecto
	GGE::Camera* mCamera;

	static App* Instance();
	static void Release();

	/**
	 * Procesa los par�metros pasados por l�nea de comandos
	 *
	 * @param argc N�mero de par�metros
	 * @param argv[] Lista de par�metros
	 */
	virtual void ProcessArguments(int argc, char* argv[]);

	/**
	 * Pone en funcionamiento la aplicaci�n. Se encarga de llamar a los m�todos
	 * Preinit, Init, loop y CleanUp
	 *
	 * @return Devuelve el c�digo de salida de la aplicaci�n
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
	float GetUpdateTime(void) const;

	/**
	 * Detiene la aplicacion con el c�digo de salida indicado
	 *
	 * @param the_exit_code C�digo de salida de la aplicaci�n
	 */
	void Quit(int the_exit_code);

	/**
	 * Devuelve la ruta del ejecutable
	 * 
	 * @return devuelve la ruta completa del ejecutable
	 */
	std::string GetExecutableDir(void) const;

	void SetFirstScene(GGE::Scene* theScene);

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
	/// C�digo de salida de la aplicaci�n
	GGE::Int16 mExitCode;
	/// Verdadero si la aplicaci�n se est� ejecutando
	bool mRunning;
	/// Archivo de log de la aplicaci�n
	std::string mLogFile;
	/// Reloj que obtiene el tiempo pasado en cada loop
	sf::Clock mUpdateClock;
	/// Almacena el tiempo pasado en cada bucle
	sf::Time mUpdateTime;
	/// Almacena la ruta del ejecutable
	std::string mExecutableDir;
	/// Puntero a la escena inicial
	GGE::Scene* mScene;

	App(const std::string TheTitle = "GGE Application");
	virtual ~App();

}; // Class App

} // namespace GGE
#endif // APP_HPP