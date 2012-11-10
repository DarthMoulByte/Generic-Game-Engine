#ifndef SCENEMANAGER_HPP
#define SCENEMANAGER_HPP

#include <map>
#include <SFML/Window.hpp>
#include <GGE/Core/Core_types.hpp>

namespace GGE
{

class SceneManager
{
	// Puntero a la instancia �nica
	static SceneManager* ms_instance;

public:
	static SceneManager* Instance();
	static void Release();

	/**
	 * A�ade una escena a la pila de escenas inactivas
	 *
	 * Solo a�ade una escena a la pila, no la inicializa
	 *
	 * @param theScene Puntero a la escena que vamos a a�adir
	 */
	void AddScene(Scene* theScene);


	/**
	 * Establece la escena indicada como activa
	 *
	 * Establece la escena como activa si se encuentra en la pila y llama a su
	 * Init() si no ha sido llamado. Cambia la escena al final del ciclo
	 *
	 * @param id_scene Cadena �nica que identifica a la escena
	 */
	void SetActiveScene(SceneID theSceneID);

	/**
	 * Elimina una escena de la pila, no puede ser la escena activa
	 *
	 * Se encarga de llamar a su m�todo Cleanup y de eliminarla de la memoria
	 *
	 * @param id_scene Cadena �nica que identifica a la escena
	 */
	void RemoveScene(SceneID theSceneID);

	/**
	 * Elimina todas las escenas inactivas
	 */
	void RemoveAllInactiveScene();

	/**
	 * Llama el m�todo Event() de la escena activa
	 *
	 * @param a_event representa a un evento del sistema
	 */
	void EventScene(sf::Event theEvent);

	/**
	 * Llama el m�todo Draw() de la escena activa
	 */
	void DrawScene();

	/**
	 * Llama al m�todo Update() de la escena activa
	 */
	void UpdateScene();

	/**
	 * Llama al m�todo Resume de la escena activa
	 */
	void ResumeScene();

	/**
	 * Llama al m�todo Pause de la escena activa
	 */
	void PauseScene();

	bool HandleChangeScene(); 

protected:
	// Puntero a la aplicaci�n
	GGE::App* mApp;

private:
	// Declaramos la clase App friend
	friend class App;
	/// Escena actualmente activa
	Scene* mActiveScene;
	/// Pr�xima escena activa
	SceneID mNextScene;
	// Lista de escenas inacticas
	std::map<SceneID, Scene*> mInactivesScenes;
	
	/**
	 * Cambia la escena activa inmediatamente. USAR SetActiveScene() para
	 * cambiar de escena
	 *
	 * @param id_scene ID de la escena a cambiar
	 */
	void ChangeScene(SceneID theSceneID);
	
	/**
	 * Elimina todas las escenas de la pila.
	 *
	 * Elimina todas las escenas incluso la escena activa, se encarga de llamar
	 * a los m�todos Cleanup() de las escenas y de eleminarlas de la memoria
	 */
	void RemoveAllScene();

	SceneManager();
	~SceneManager();

}; // Class SceneManager

} // Namespace GGE

#endif // SCENEMANAGER_HPP