/**
 * Clase abstracta que representa a una escena cualquierda de un juego todas
 * las escenas deben de heredar de ésta.
 *
 * @file scene.h
 * @author Adrián Guerra Marrero
 * @date 20110422 - Initial Release
 */

#ifndef SCENE_HPP
#define SCENE_HPP

#include <algorithm>
#include <list>
#include <SFML/Graphics.hpp>
#include <GGE/Core/Core_types.hpp>

namespace GGE
{
class Scene
{
public:
	/**
	 * Scene Destructor
	 */
	virtual ~Scene();

	/**
	 * Devuelve el identificador único de la escena
	 *
	 * @return GGE::SceneID el ID de la escena
	 */
	const SceneID GetID() const;
	
	/**
	 * Devuelve true si el Init() ya ha sido llamado
	 */
	const bool IsInitComplete() const;
	
	/**
	 * Devuelve true si la escena está pausada
	 */
	const bool IsPaused() const;
	
	/**
	 * Método llamado cuando se activa la escena
	 */
	virtual void Init();

	/**
	 * Método llamado para reiniciar la escena
	 */
	virtual void ReInit();

	/**
	 * Método llamano al pausar la escena
	 */
	virtual void Pause();
	
	/**
	 * Método llamado al salir del pause de la escena
	 */
	virtual void Resume();

	/**
	 * Comprueba si el método Cleanup(); debe ser llamado
	 */
	void HandleCleanup(void);
	
	/**
	 * Método que es llamado al eliminar la escena, se ecarga de la limpieza
	 */
	virtual void Cleanup();

	/**
	 * Método que recibe los eventos del sistema, llamado por cada evento que se
	 * produce en un ciclo de la aplicación
	 */
	virtual void Events(sf::Event TheEvent) = 0;
	
	/**
	 * Método que actualiza la escena, llamado al menos una vez por ciclo
	 */
	virtual void Update(void) = 0;

	/**
	 * Método encargado de dibujar en la escena, llamado en relación a los FPS
	 */
	void Draw(void);

	void AddObject(GGE::ObjectScene* theObject);
	void QuitObject(GGE::ObjectScene* theObject);
	void DeleteObject(GGE::ObjectScene* theObject);

	void AddObjects(const std::vector<GGE::ObjectScene*> &theList);
	void QuitObjects(const std::vector<GGE::ObjectScene*> &theList);
	void DeleteObjects(const std::vector<GGE::ObjectScene*> &theList);


	void SetBackgroundColor(const sf::Color &theColor);

protected:
	/// Puntero a la aplicación padre
	App* mApp;

	/**
	 * Constructor de la escena
	 * 
	 * @param m_id Cadena de texto que establece un identificador único
	 */
	Scene(SceneID theID);

private:
	/// Representa el id único de la escena
	const SceneID mID;
	/// Comprueba si cleanup debe ser llamado
	bool mCleanup;
	/// Comprueba si la escena está inicializada
	bool mInit;
	/// Comprueba si la escena está pausada
	bool mPaused;
	/// Lista de Actores a dibujar
	std::list<GGE::ObjectScene*> mObjects;
	/// Color de fondo de la escena
	sf::Color mColorBack;

	/**
	 * Our copy constructor is private because we do not allow copies of
	 * our Singleton class
	 */
	Scene(const Scene&);  // Intentionally undefined

	/**
	 * Our assignment operator is private because we do not allow copies
	 * of our Singleton class
	 */
	Scene& operator=(const Scene&); // Intentionally undefined


}; // class Scene
} // Namespace GGE

#endif // SCENE_HPP
